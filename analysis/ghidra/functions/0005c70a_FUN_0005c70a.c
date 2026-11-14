/* 0005c70a FUN_0005c70a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0005c70a(int param_1,int param_2,int param_3)

{
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,0,"Smooth");
    FUN_00054f62(param_1,param_2,param_3 + 0x1a1,0x46,10);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x1a1) * 0x68,0x9d,0x10,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  FUN_0005984e(param_1,param_2,1,"L");
  FUN_00059e1e(param_1,param_2,param_3 + 0x1a4,0x10,0x19,0x17,*(undefined4 *)(param_1 + 0x27850));
  FUN_0005984e(param_1,param_2,2,"R");
  FUN_00059e1e(param_1,param_2,param_3 + 0x1a7,0x10,0x19,0x24,*(undefined4 *)(param_1 + 0x27850));
  FUN_0005984e(param_1,param_2,3,"Link L+R");
  FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x27894),
               param_3 + 0x1ad,0x4a,0x31,1,1);
  FUN_0005984e(param_1,param_2,4,"Sync");
  FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x27894),
               param_3 + 0x1aa,0x4a,0x3e,1,1);
  return;
}

