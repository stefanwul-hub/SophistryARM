/* 0005c946 FUN_0005c946 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0005c946(int param_1,int param_2,int param_3)

{
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,0,"Bits");
    FUN_00054f62(param_1,param_2,param_3 + 0x1b0,0x46,10);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x1b0) * 0x68,0x9d,0x10,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,1,"Cutoff");
    FUN_00054f62(param_1,param_2,param_3 + 0x1bc,0x46,0x17);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x1bc) * 0x68,0x9d,0x1d,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x27894),
               param_3 + 0x1b9,0xb5,0x17,1,1);
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,2,"Resonance");
    FUN_00054f62(param_1,param_2,param_3 + 0x1bf,0x46,0x24);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x1bf) * 0x68,0x9d,0x2a,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,3,"Divider");
    FUN_00054f62(param_1,param_2,param_3 + 0x1b3,0x46,0x31);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x1b3) * 0x68,0x9d,0x37,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x27894),
               param_3 + 0x1b6,0xb5,0x31,1,1);
  FUN_0005984e(param_1,param_2,4,"Fil Post Div");
  FUN_00026b74(param_1,param_2,param_3 + 0x1c2,0x46,0x3d,*(undefined4 *)(param_1 + 0x278bc),1);
  FUN_0005984e(param_1,param_2,5,"Smoother");
  FUN_00026b74(param_1,param_2,param_3 + 0x1c5,0x46,0x4a,*(undefined4 *)(param_1 + 0x278bc),1);
  return;
}

