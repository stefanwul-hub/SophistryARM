/* 0005bb40 FUN_0005bb40 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0005bb40(int param_1,int param_2,int param_3)

{
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,0,"Time Cen");
    FUN_00054f62(param_1,param_2,param_3 + 0x16b,0x46,10);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x16b) * 0x68,0x9d,0x10,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x27890),
               param_3 + 0x16e,0xb1,10,1,1);
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,1,"Time Left");
    FUN_00054f62(param_1,param_2,param_3 + 0x174,0x46,0x17);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x174) * 0x68,0x9d,0x1d,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x27890),
               param_3 + 0x177,0xb1,0x17,1,1);
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,2,"Time Right");
    FUN_00054f62(param_1,param_2,param_3 + 0x17a,0x46,0x24);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x17a) * 0x68,0x9d,0x2a,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x27890),
               param_3 + 0x17d,0xb1,0x24,1,1);
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,3,"Feedback");
    FUN_00054f62(param_1,param_2,param_3 + 0x180,0x46,0x31);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x180) * 0x68,0x9d,0x37,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,4,"Bal Cen/LR");
    FUN_00054f62(param_1,param_2,param_3 + 0x171,0x46,0x3e);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x171) * 0x68,0x9d,0x44,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,5,"Pan Left");
    FUN_00054f62(param_1,param_2,param_3 + 0x183,0x46,0x4b);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x183) * 0x68,0x9d,0x51,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,6,"Pan Right");
    FUN_00054f62(param_1,param_2,param_3 + 0x186,0x46,0x58);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x186) * 0x68,0x9d,0x5e,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  return;
}

