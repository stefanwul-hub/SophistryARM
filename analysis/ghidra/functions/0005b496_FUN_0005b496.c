/* 0005b496 FUN_0005b496 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0005b496(int param_1,int param_2,int param_3)

{
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,0,"Roomsize");
    FUN_00054f62(param_1,param_2,param_3 + 0x13e,0x46,10);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x13e) * 0x68,0x9d,0x10,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,1,"Predelay");
    FUN_00054f62(param_1,param_2,param_3 + 0x144,0x46,0x17);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x144) * 0x68,0x9d,0x1d,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x27890),
               param_3 + 0x147,0xb1,0x17,1,1);
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,2,"Damp");
    FUN_00054f62(param_1,param_2,param_3 + 0x141,0x46,0x24);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x141) * 0x68,0x9d,0x2a,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,3,"Modulation");
    FUN_00054f62(param_1,param_2,param_3 + 0x14a,0x46,0x31);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x14a) * 0x68,0x9d,0x37,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  FUN_00026b74(param_1,param_2,param_3 + 0x14d,0xaf,0x31,*(undefined4 *)(param_1 + 0x278c0),0);
  return;
}

