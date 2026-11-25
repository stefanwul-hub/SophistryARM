"""Capture original CMenuWithSub and CStepSeqPl drawing, without OS widgets."""
from pathlib import Path
import hashlib, json, struct, sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tests'))
from probe_engine_initialization import Host, Original, LegacyImage
from unicorn.x86_const import UC_X86_REG_EAX

image = LegacyImage((ROOT / 'reference/CronoX3.i386').read_bytes())
b = Original(bytes(image.mapped()), 0x4000000)
h = Host(b, image)
for entry in image.stubs:
    b.hook(entry['address'], h.callback)
ctl, vt, subvt, stub = 0x300000, 0x6f0000, 0x6f0800, 0x6f1000
put = h.put
word = h.word
args = lambda n: struct.unpack('<' + 'I' * n, b.read(b.esp() + 4, 4 * n))
rect = lambda p: list(struct.unpack('<4i', b.read(p, 16)))
def ret(value=0):
    b.uc.reg_write(UC_X86_REG_EAX, value & 0xffffffff)
    b.ret()

labels = json.loads((ROOT / 'tests/fixtures/cronox-modulation-destinations.json').read_text())
raw_labels = b''.join(s.encode('ascii') + b'\0' for s in labels)
assert all(len(s) == 16 for s in labels) and len(labels) == 58
assert all(s.encode('ascii') in bytes(image.mapped()) for s in labels[1:])
b.write(0x350000, raw_labels)
b.write(ctl, bytes(0x1000)); put(ctl, vt)
for offset, value in [(0xdc, 0x640800), (0x48, 670), (0xe4, 0), (0xe8, 57), (0xec, 17), (0xf0, 0x350000)]:
    put(ctl + offset, value)
root_items, leaf_items = [], {}
def menu_record(pc):
    a = args(6)
    if pc == 0x9d08:
        put(a[0], subvt); leaf_items[a[0]] = []
    elif pc == stub + 4:  # addEntry of a category
        root_items.append({'label': h.string(a[2]).decode('ascii'), 'menu': a[1]})
    elif pc == stub + 8:  # original CMenuSimple::addItemShift reaches addEntry
        item = {'label': h.string(a[1]).decode('ascii'), 'index': a[2]}
        if a[0] == ctl: root_items.append(item)
        else: leaf_items[a[0]].append(item)
    ret()
for p in [vt, subvt]:
    for offset in range(0, 0x200, 4): put(p + offset, stub)
    put(p + 0x184, stub + 8)
for offset, pc in [(0x180, stub + 4), (0x1c8, 0x943a), (0x1cc, 0x8a2c), (0x1d8, 0x91b8), (0x1dc, 0x913c), (0x1e0, 0x91f2), (0x1e4, 0x96b6), (0x1e8, 0x8a62)]:
    put(vt + offset, pc)
for pc in [stub, stub + 4, stub + 8, 0x9d08, 0x1ade8]: b.hook(pc, menu_record)
b.run(0x8f70, [ctl])
menu = []
for entry in root_items:
    if 'menu' in entry:
        menu.append({'label': entry['label'], 'children': leaf_items[entry['menu']]})
    else: menu.append(entry)
assert len(menu) == 17 and sum(len(e.get('children', [e])) for e in menu) == 58

# CStepSeqPl constants from createArpEdits 0x77786 and constructor 0xa5fc0.
# Drawing calls, strings, colours and source/destination rectangles remain original.
b.write(ctl, bytes(0x1000)); put(ctl, vt)
for offset, value in [(0x10, 224), (0x14, 104), (0xe4, 4), (0xe8, 8), (0xec, 56), (0xf0, 13), (0xf4, 31), (0xf8, 16), (0x100, 8), (0x104, 12), (0x398, 0x640000), (0xd4, 0xffd2d2d2), (0xd8, 0xff696969)]:
    put(ctl + offset, value)
for offset, value in [(0x79, 1), (0x108, 0), (0x109, 1), (0x10a, 0), (0x10b, 1), (0x10c, 1)]: b.write(ctl + offset, bytes([value]))
put(0x640000, subvt); put(subvt + 0x14, stub + 12)
font_color, frame = 0, []
def draw_record(pc):
    global font_color
    a = args(6)
    if pc == 0xb8080: font_color = a[1]
    elif pc == 0xc1c22:
        frame.append(['text', h.string(a[1]).decode('ascii'), *rect(a[2]), font_color])
    elif pc == stub + 12:
        frame.append(['bitmap', *rect(a[2]), *struct.unpack('<2i', b.read(a[3], 8))])
    ret()
for pc in [0xbbae8, 0xb8080, 0xc1c22, stub + 12]: b.hook(pc, draw_record)
cases = []
for length in [1, 8, 16, 32, 128]:
    for current in list(range(33)) + [126, 127, 128]:
        seq = bytearray([current + 1, length + 1])
        for step in range(128): seq.extend([61, [1, 129, 2, 128, 81, 101][step % 6]])
        b.write(ctl + 0x10d, bytes(seq) + b'\0'); frame = []
        b.run(0xa62f2, [ctl, 0x640200])
        assert len(frame) == 64
        cases.append({'length': length, 'current': current, 'operations': frame})
data = {'menu': menu, 'arpeggiator': cases}
def fnv_parts(parts):
    value=14695981039346656037
    for part in parts:
        for byte in part:
            value=((value^byte)*1099511628211)&0xffffffffffffffff
    return format(value,'016x')
def u32(value):return struct.pack('<I',value&0xffffffff)
parts=[]
for entry in menu:
    parts.extend([entry['label'].encode()+b'\0',u32(len(entry.get('children',[])))])
    for child in entry.get('children',[entry]):parts.extend([child['label'].encode()+b'\0',u32(child['index'])])
menu_hash=fnv_parts(parts)
parts=[]
for case in cases:
    parts.extend([u32(case['length']),u32(case['current'])])
    for op in case['operations']:
        parts.append(u32(op[0]=='text'))
        values=op[1:]
        if op[0]=='text':parts.append(values[0].encode()+b'\0');values=values[1:]
        parts.extend(map(u32,values))
draw_hash=fnv_parts(parts)
out = ROOT / 'work/crx011'; out.mkdir(parents=True, exist_ok=True)
(out / 'original-modulation.json').write_text(json.dumps(data, separators=(',', ':')) + '\n')
report = {'checkpoint': 'CRX011', 'original_i386_sha256': hashlib.sha256((ROOT / 'reference/CronoX3.i386').read_bytes()).hexdigest(), 'menu_routine': '0x8f70 CMenuWithSub::fill', 'original_categories': 16, 'original_destinations': 58, 'category_names': [e['label'].strip() for e in menu if 'children' in e], 'menu_sha256': hashlib.sha256(json.dumps(menu, separators=(',', ':')).encode()).hexdigest(), 'arpeggiator_routine': '0xa62f2 CStepSeqPl::draw', 'arpeggiator_cases': len(cases), 'arpeggiator_operations': sum(len(c['operations']) for c in cases), 'indicator_bitmap': 306, 'bitmap_dimensions': [8, 24], 'cell_size': [56, 13], 'indicator_rect': [16, 0, 8, 12], 'value_rect': [24, 0, 31, 13], 'displayed_bytes': 'velocity/off/tie at 3 + 2*step; original flag108=false, flag109=true', 'macos_ui_executed': False}
report.update(menu_fnv64=menu_hash,arpeggiator_fnv64=draw_hash)
(out / 'modulation-recovery.json').write_text(json.dumps(report, indent=2) + '\n')
print(json.dumps(report))
