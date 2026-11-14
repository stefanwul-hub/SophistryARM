/* 0004db30 Kaja_c_vslot_69 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 Kaja_c_vslot_69(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  DAT_000fcbc0 = 0xffffffff;
  DAT_000fcbc4 = 0;
  DAT_000fc4a0 = 1;
  DAT_000fc4a4 = 2;
  DAT_000fc4f8 = 1;
  DAT_000fc568 = 2;
  DAT_000fc828 = 0xf;
  DAT_000fc82c = 6;
  DAT_000fc880 = 1;
  DAT_000fc8f0 = 2;
  DAT_000fc960 = 3;
  DAT_000fc9d0 = 4;
  DAT_000fca40 = 5;
  DAT_000fcab0 = 6;
  *param_2 = &DAT_000fcbc0;
  if (*(int *)(param_1 + 0xcfbc) == 2) {
    *param_3 = &DAT_000fc4a0;
    return 1;
  }
  if (*(int *)(param_1 + 0xcfbc) != 6) {
    return 0;
  }
  *param_3 = &DAT_000fc828;
  return 1;
}

