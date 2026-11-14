/* 0005a5c6 FUN_0005a5c6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0005a5c6(int param_1,int param_2,int param_3)

{
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,0,"Time");
    FUN_00054f62(param_1,param_2,param_3 + 0xe1,0x46,10);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0xe1) * 0x68,0x9d,0x10,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x27890),
               param_3 + 0xf0,0xb1,10,1,1);
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,1,"Feedback");
    FUN_00054f62(param_1,param_2,param_3 + 0xe4,0x46,0x17);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0xe4) * 0x68,0x9d,0x1d,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,2,"Filter");
    FUN_00054f62(param_1,param_2,param_3 + 0xe7,0x46,0x24);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0xe7) * 0x68,0x9d,0x2a,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,3,"Mod Rate");
    FUN_00054f62(param_1,param_2,param_3 + 0xea,0x46,0x31);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0xea) * 0x68,0x9d,0x37,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x27890),
               param_3 + 0xf3,0xb1,0x31,1,1);
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,4,"Mod Depth");
    FUN_00054f62(param_1,param_2,param_3 + 0xed,0x46,0x3e);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0xed) * 0x68,0x9d,0x44,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  return;
}

