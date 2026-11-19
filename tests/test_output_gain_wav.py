import math
import struct
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "scripts"))
from compare_output_gain import compare_wave_bytes, scaled_wave


def wave(values, channels=2):
    data = struct.pack('<' + str(len(values)) + 'f', *values)
    return (b'RIFF' + struct.pack('<I', 36+len(data)) + b'WAVEfmt ' +
            struct.pack('<IHHIIHH',16,3,channels,44100,44100*channels*4,channels*4,32) +
            b'data' + struct.pack('<I',len(data)) + data)


class OutputGainReferenceTests(unittest.TestCase):
    def test_exact_plus_six_db_all_channels_no_clipping(self):
        for channels in [1,2,6]:
            source = wave([.5,-.5,1,-1,0,-0.0]*channels, channels)
            gain = struct.unpack('<f',struct.pack('<f',math.pow(10,6/20)))[0]
            expected = wave([x*gain for x in [.5,-.5,1,-1,0,-0.0]*channels],channels)
            self.assertTrue(compare_wave_bytes(source,expected)['passed'])
            self.assertGreater(struct.unpack_from('<f',expected,52)[0],1)

    def test_unchanged_audio_is_not_a_valid_compensated_output(self):
        source = wave([.25,-.25])
        self.assertFalse(compare_wave_bytes(source,source)['passed'])

    def test_double_compensation_is_rejected(self):
        source = wave([.25,-.25])
        once, _ = scaled_wave(source)
        twice, _ = scaled_wave(once)
        self.assertFalse(compare_wave_bytes(source,twice)['passed'])

    def test_nonfinite_audio_is_rejected(self):
        with self.assertRaises(ValueError):
            scaled_wave(wave([float('nan'),0]))

    def test_truncated_audio_is_rejected(self):
        with self.assertRaises(ValueError):
            scaled_wave(wave([.25,-.25])[:-1])

    def test_double_compensation_fails(self):
        source = wave([.25,-.25])
        once,_ = scaled_wave(source)
        twice,_ = scaled_wave(once)
        self.assertFalse(compare_wave_bytes(source,twice)['passed'])

    def test_nonfinite_source_rejected(self):
        with self.assertRaisesRegex(ValueError,'Nonfinite'):
            scaled_wave(wave([float('nan'),0]))

    def test_truncated_and_integer_pcm_rejected(self):
        source=wave([.5,-.5])
        with self.assertRaises(ValueError):scaled_wave(source[:-1])
        integer=bytearray(source);struct.pack_into('<H',integer,20,1)
        with self.assertRaises(ValueError):scaled_wave(integer)


if __name__=='__main__':unittest.main()
