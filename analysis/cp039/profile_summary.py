#!/usr/bin/env python3
"""Aggregate only the main thread of macOS sample; never export raw stacks."""
import argparse
import collections
import json
import re
from pathlib import Path


def summarize(text):
    body = text.split("Call graph:\n", 1)[1].split("Total number in stack", 1)[0]
    nodes, stack = [], []
    for line in body.splitlines():
        match = re.match(r"^([ +!|:]*)(\d+) (.+)$", line)
        if not match:
            continue
        depth, count, label = len(match[1]), int(match[2]), match[3]
        function = label.split("  (in ", 1)[0]
        node = {"depth": depth, "samples": count, "function": function, "children": []}
        while stack and stack[-1]["depth"] >= depth:
            stack.pop()
        if stack:
            stack[-1]["children"].append(node)
        else:
            nodes.append(node)
        stack.append(node)
    roots = [node for node in nodes if "com.apple.main-thread" in node["function"]]
    if len(roots) != 1:
        raise ValueError("Expected one main-thread sample root")
    root = roots[0]
    exclusive, inclusive = collections.Counter(), collections.Counter()
    binding = collections.Counter()
    def visit(node, in_service=False, in_editor=False):
        children = sum(c["samples"] for c in node["children"])
        if children > node["samples"]:
            raise ValueError("Sample-tree child counts exceed their parent")
        name = node["function"]
        if name.startswith("Thread_"):
            name = "main_thread_root"
        in_service = in_service or name.startswith("sophistry::LegacyEngine::Impl::service(")
        in_editor = in_editor or name.startswith("sophistry::LegacyEngine::Impl::editorPlatformService(")
        own = node["samples"] - children
        exclusive[name] += own
        if in_service:
            binding["all"] += own
            if "operator==" in name or "strlen" in name or "memcmp" in name:
                binding["name_comparisons"] += own
        if in_editor:
            binding["editor_router"] += own
        inclusive[name] += node["samples"]
        for child in node["children"]:
            visit(child, in_service, in_editor)
    visit(root)
    if sum(exclusive.values()) != root["samples"]:
        raise ValueError("Exclusive samples do not conserve the main-thread total")
    units = [{"compiled_unit": name.split("(", 1)[0], "exclusive_samples": count,
              "main_thread_percent": 100 * count / root["samples"]}
             for name, count in exclusive.most_common()
             if re.fullmatch(r"sl_unit_\d{4}", name.split("(", 1)[0])]
    def category(predicate):
        count = sum(v for k, v in exclusive.items() if predicate(k))
        return {"exclusive_samples": count, "main_thread_percent": 100 * count / root["samples"]}
    return {"scope": "Exclusive samples on the main rendering thread; idle worker threads excluded. Unit time includes actual DSP and translation support, not solely overhead.",
            "main_thread_samples": root["samples"], "exclusive_samples_conserved": True,
            "compiled_units": units,
            "instruction_bookkeeping": category(lambda k: k.startswith("sl_tick(")),
            "compiled_unit_dispatch": category(lambda k: k.startswith("sl_execute(")),
            "string_comparisons": category(lambda k: "operator==" in k or "strlen" in k or "memcmp" in k),
            "host_import_binding": {k: {"exclusive_samples": v, "main_thread_percent": 100 * v / root["samples"]}
                                    for k, v in binding.items()},
            "original_audio_process_inclusive_samples": sum(v for k, v in inclusive.items() if k.startswith("sophistry::LegacyEngine::process(")),
            "au_render_inclusive_samples": sum(v for k, v in inclusive.items() if k.startswith("AudioUnitRender")),
            "raw_thread_ids_native_addresses_and_paths_exported": False}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("input", type=Path)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    result = summarize(args.input.read_text())
    args.output.write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps({"main_thread_samples": result["main_thread_samples"],
                      "units": len(result["compiled_units"]),
                      "top_units": result["compiled_units"][:5]}, indent=2))
