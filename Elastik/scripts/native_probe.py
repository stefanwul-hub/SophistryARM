"""Run a probe per fixture or in one process; never retry a failed fixture."""
import subprocess


class NativeProbe:
    def __init__(self, command, persistent=False):
        self.command = command
        self.process = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                                        stderr=subprocess.PIPE) if persistent else None

    def run(self, fixture, result_bytes):
        if self.process is None:
            return subprocess.run(self.command, input=fixture, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        try:
            self.process.stdin.write(fixture)
            self.process.stdin.flush()
        except BrokenPipeError:
            pass
        result = self.process.stdout.read(result_bytes)
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
