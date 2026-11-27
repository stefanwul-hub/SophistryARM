"""Run a probe per fixture or in one process; never retry a failed fixture."""
import subprocess
import os
import selectors
import time


class NativeProbe:
    def __init__(self, command, persistent=False, timeout_seconds=15):
        self.command = command
        self.timeout_seconds = timeout_seconds
        self.process = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                                        stderr=subprocess.PIPE) if persistent else None

    def run(self, fixture, result_bytes):
        if self.process is None:
            try:
                return subprocess.run(self.command, input=fixture, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                                      timeout=self.timeout_seconds)
            except subprocess.TimeoutExpired as error:
                return subprocess.CompletedProcess(self.command, -9, error.stdout or b'',
                                                   (error.stderr or b'') + b'\nProbe result timed out.\n')
        try:
            self.process.stdin.write(fixture)
            self.process.stdin.flush()
        except BrokenPipeError:
            pass
        # A shorter response must fail promptly: a persistent probe may be
        # waiting for its next fixture while read(expected_size) waits forever.
        pieces = []; received = 0
        deadline = time.monotonic() + self.timeout_seconds
        with selectors.DefaultSelector() as selector:
            selector.register(self.process.stdout, selectors.EVENT_READ)
            while received < result_bytes:
                left = deadline - time.monotonic()
                if left <= 0 or not selector.select(left):
                    self.process.kill(); self.process.wait(timeout=5)
                    return subprocess.CompletedProcess(self.command, self.process.returncode, b''.join(pieces),
                                                       self.process.stderr.read() + b'\nProbe result timed out.\n')
                chunk = os.read(self.process.stdout.fileno(), min(65536, result_bytes - received))
                if not chunk: break
                pieces.append(chunk); received += len(chunk)
        result = b''.join(pieces)
        if len(result) != result_bytes:
            code = self.process.wait(timeout=5)
            return subprocess.CompletedProcess(self.command, code, result, self.process.stderr.read())
        return subprocess.CompletedProcess(self.command, 0, result, b'')

    def close(self):
        if self.process is not None:
            self.process.stdin.close()
            code = self.process.wait(timeout=5)
            error = self.process.stderr.read()
            self.process.stdout.close()
            self.process.stderr.close()
            if code:
                raise RuntimeError(f'Probe exited {code}: {error!r}')
