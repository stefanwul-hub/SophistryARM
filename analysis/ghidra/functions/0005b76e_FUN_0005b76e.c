/* 0005b76e FUN_0005b76e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0005b76e(int param_1,int param_2,int param_3)

{
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,0,"Time Left");
    FUN_00054f62(param_1,param_2,param_3 + 0x153,0x46,10);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x153) * 0x68,0x9d,0x10,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x27890),
               param_3 + 0x162,0xb1,10,1,1);
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,1,"Time Right");
    FUN_00054f62(param_1,param_2,param_3 + 0x156,0x46,0x17);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x156) * 0x68,0x9d,0x1d,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x27890),
               param_3 + 0x165,0xb1,0x17,1,1);
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,2,"Feedback");
    FUN_00054f62(param_1,param_2,param_3 + 0x159,0x46,0x24);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x159) * 0x68,0x9d,0x2a,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,3,"Highpass");
    FUN_00054f62(param_1,param_2,param_3 + 0x15f,0x46,0x31);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x15f) * 0x68,0x9d,0x37,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,4,"Lowpass");
    FUN_00054f62(param_1,param_2,param_3 + 0x15c,0x46,0x3e);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x15c) * 0x68,0x9d,0x44,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  FUN_0005984e(param_1,param_2,5,"Link L+R");
  FUN_00026b74(param_1,param_2,param_3 + 0x168,0x46,0x4a,*(undefined4 *)(param_1 + 0x278bc),1);
  return;
}

