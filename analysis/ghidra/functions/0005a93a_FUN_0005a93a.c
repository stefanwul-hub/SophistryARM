/* 0005a93a FUN_0005a93a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0005a93a(int param_1,int param_2,int param_3)

{
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,0,"Time");
    FUN_00054f62(param_1,param_2,param_3 + 0xf6,0x46,10);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0xf6) * 0x68,0x9d,0x10,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,1,"Rate");
    FUN_00054f62(param_1,param_2,param_3 + 0xfc,0x46,0x17);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0xfc) * 0x68,0x9d,0x1d,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,2,"Time Spr");
    FUN_00054f62(param_1,param_2,param_3 + 0xf9,0x46,0x24);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0xf9) * 0x68,0x9d,0x2a,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,3,"Rate Spr");
    FUN_00054f62(param_1,param_2,param_3 + 0xff,0x46,0x31);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0xff) * 0x68,0x9d,0x37,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,4,"Dry");
    FUN_00054f62(param_1,param_2,param_3 + 0x108,0x46,0x3e);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x108) * 0x68,0x9d,0x44,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,5,"Stereo");
    FUN_00054f62(param_1,param_2,param_3 + 0x10b,0x46,0x4b);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x10b) * 0x68,0x9d,0x51,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  return;
}

