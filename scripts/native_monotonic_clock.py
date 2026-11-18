#!/usr/bin/env python3
"""Native tick/timebase contract for the original-instruction test host.

Only monotonic time is changed. Wall-clock, random and preference fixtures
remain controlled by the existing reference host.
"""
import ctypes
import sys
import time


class NativeMonotonicClock:
    def __init__(self):
        self.numerator, self.denominator = 1, 1
        self._read = time.monotonic_ns
        if sys.platform == "darwin":
            class Timebase(ctypes.Structure):
                _fields_ = [("numer", ctypes.c_uint32), ("denom", ctypes.c_uint32)]
            system = ctypes.CDLL("/usr/lib/libSystem.B.dylib")
            info = system.mach_timebase_info
            info.argtypes = [ctypes.POINTER(Timebase)]
            info.restype = ctypes.c_int
            value = Timebase()
            if info(ctypes.byref(value)) or not value.numer or not value.denom:
                raise RuntimeError("Cannot read native reference clock timebase")
            self.numerator, self.denominator = value.numer, value.denom
            self._read = system.mach_absolute_time
            self._read.argtypes = []
            self._read.restype = ctypes.c_uint64
            self._system = system

    def ticks(self):
        return int(self._read())
