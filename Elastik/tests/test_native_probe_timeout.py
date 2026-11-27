#!/usr/bin/env python3
"""A truncated persistent-probe response must fail instead of hanging."""
from pathlib import Path
import sys

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'scripts'))
from native_probe import NativeProbe


def main():
    echo = 'import sys\nwhile True:\n b=sys.stdin.buffer.read(4)\n if not b:break\n sys.stdout.buffer.write(b);sys.stdout.buffer.flush()\n'
    probe = NativeProbe([sys.executable, '-c', echo], persistent=True, timeout_seconds=2)
    assert probe.run(b'abcd', 4).stdout == b'abcd'
    assert probe.run(b'efgh', 4).stdout == b'efgh'
    probe.close()
    short = 'import sys;sys.stdin.buffer.read(4);sys.stdout.buffer.write(b"ok");sys.stdout.buffer.flush();sys.stdin.buffer.read()'
    probe = NativeProbe([sys.executable, '-c', short], persistent=True, timeout_seconds=0.2)
    result = probe.run(b'data', 4)
    assert result.returncode != 0 and result.stdout == b'ok' and b'timed out' in result.stderr
    assert probe.process.poll() is not None
    probe.process.stdin.close(); probe.process.stdout.close(); probe.process.stderr.close()
    probe = NativeProbe([sys.executable, '-c', 'import sys;sys.stdin.buffer.read(4);sys.exit(7)'], persistent=True, timeout_seconds=2)
    result = probe.run(b'data', 4)
    assert result.returncode == 7 and result.stdout == b''
    probe.process.stdin.close(); probe.process.stdout.close(); probe.process.stderr.close()
    print('PASS: persistent responses, truncation timeout and nonzero exit; no retries')


if __name__ == '__main__': main()
