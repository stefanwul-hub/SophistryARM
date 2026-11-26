#!/usr/bin/env python3
"""Inspect the original GNArchiver class/object directory, not object bodies.

Layout follows original functions 0x1b71e2, 0x1b73d8, 0x1640f2, 0x164748.
Accepts raw state bytes or an AU plist containing a binary 'data' field.
Does not instantiate objects, restore projects or print sample paths/values.
"""
import argparse
import hashlib
import json
import plistlib
import struct
from pathlib import Path


class HeaderReader:
    def __init__(self, data):
        self.data, self.offset = data, 0

    def take(self, size):
        if size < 0 or size > len(self.data) - self.offset:
            raise ValueError('Truncated or invalid original state directory')
        result = self.data[self.offset:self.offset + size]
        self.offset += size
        return result

    def integer(self):
        if self.take(1) != b'i':
            raise ValueError('Expected original typed-stream integer tag')
        return struct.unpack('>i', self.take(4))[0]

    def count(self):
        value = self.integer()
        if not 0 <= value <= 1000000:
            raise ValueError('Invalid or excessive directory count')
        return value

    def string(self):
        if self.take(1) != b'*':
            raise ValueError('Expected original typed-stream string tag')
        return self.take(self.count()).decode('ascii')


def inspect_header(data):
    reader = HeaderReader(data)
    version = reader.integer()
    if version != 1:
        raise ValueError('Unsupported GNArchiver binary version')
    classes = []
    for _ in range(reader.count()):
        number, class_version, name = reader.integer(), reader.integer(), reader.string()
        classes.append({'number': number, 'version': class_version, 'name': name})
    numbers = {c['number'] for c in classes}
    if len(numbers) != len(classes):
        raise ValueError('Duplicate original class numbers')
    object_count = reader.count()
    object_classes = [reader.integer() for _ in range(object_count)]
    unknown = sorted(set(object_classes) - numbers)
    return {'format': 'GNArchiver binary with GNTypedStream tags', 'version': version,
            'classes': classes, 'object_count': object_count,
            'unknown_object_class_numbers': unknown, 'body_offset': reader.offset,
            'body_bytes': len(data) - reader.offset,
            'data_sha256': hashlib.sha256(data).hexdigest(),
            'object_bodies_decoded': False, 'old_project_restored': False}


def inspect_file(path):
    if path.stat().st_size > 32 * 1024 * 1024:
        raise ValueError('Input exceeds this inspector limit (32 MiB)')
    data = path.read_bytes()
    if data.startswith(b'<?xml') or data.startswith(b'bplist'):
        outer = plistlib.loads(data)
        if not isinstance(outer, dict) or not isinstance(outer.get('data'), bytes):
            raise ValueError('Expected an AU dictionary with binary data')
        data = outer['data']
    return inspect_header(data)


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('state', type=Path)
    p.add_argument('--output', type=Path)
    a = p.parse_args()
    text = json.dumps(inspect_file(a.state), indent=2) + '\n'
    if a.output:
        a.output.write_text(text)
    else:
        print(text, end='')
