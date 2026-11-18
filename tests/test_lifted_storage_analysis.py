#!/usr/bin/env python3
"""Exercise the path and byte-alias proof required for scratch localization."""
import sys,unittest
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'scripts'))
from optimize_lifted_cpp import definitely_initialized,regions

def v(space,offset,size=4):return {'space':space,'offset':hex(offset),'size':size}
def copy(out,source):return {'op':'COPY','output':out,'inputs':[source]}
def branch(delta,conditional=False):
    return {'op':'CBRANCH' if conditional else 'BRANCH','output':None,
            'inputs':[v('const',delta & 0xffffffffffffffff,8)]+([v('register',0)] if conditional else [])}
U=v('unique',0x100);R=v('register',0);C=v('const',1)

class DefiniteScratchTests(unittest.TestCase):
    def check(self,ops,expected):self.assertEqual(definitely_initialized({'pcode':ops}),expected)
    def test_definition_skipped_on_one_branch(self):
        self.check([branch(2,True),copy(U,C),copy(R,U)],False)
    def test_both_branches_define_the_bytes(self):
        self.check([branch(3,True),copy(U,C),branch(2),copy(U,C),copy(R,U)],True)
    def test_back_edge_does_not_define_first_iteration(self):
        self.check([copy(R,U),copy(U,C),branch(-2,True)],False)
    def test_initialized_loop(self):
        self.check([copy(U,C),copy(R,U),branch(-1,True)],True)
    def test_unreachable_read_is_ignored(self):
        self.check([branch(2),copy(R,U),copy(R,C)],True)
    def test_partial_alias_is_not_a_complete_definition(self):
        self.check([copy(v('unique',0x100,2),C),copy(R,U)],False)
    def test_two_partial_writes_cover_the_read(self):
        self.check([copy(v('unique',0x100,2),C),copy(v('unique',0x102,2),C),copy(R,U)],True)
    def test_overlapping_views_share_storage(self):
        ins={'pcode':[copy(U,C),copy(v('unique',0x102,2),v('unique',0x100,2))]}
        self.assertEqual(regions(ins),[[0x100,0x104]])

if __name__=='__main__':unittest.main()
