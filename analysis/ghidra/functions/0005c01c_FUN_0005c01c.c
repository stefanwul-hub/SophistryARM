/* 0005c01c FUN_0005c01c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0005c01c(int param_1,int param_2,int param_3)

{
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,0,"Freq 1");
    FUN_00054f62(param_1,param_2,param_3 + 399,0x46,10);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 399) * 0x68,0x9d,0x10,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,1,"Gain 1");
    FUN_00054f62(param_1,param_2,param_3 + 0x192,0x46,0x17);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x192) * 0x68,0x9d,0x1d,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,2,"Q 1");
    FUN_00054f62(param_1,param_2,param_3 + 0x195,0x46,0x24);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x195) * 0x68,0x9d,0x2a,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,4,"Freq 2");
    FUN_00054f62(param_1,param_2,param_3 + 0x198,0x46,0x3e);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x198) * 0x68,0x9d,0x44,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,5,"Gain 2");
    FUN_00054f62(param_1,param_2,param_3 + 0x19b,0x46,0x4b);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x19b) * 0x68,0x9d,0x51,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  if (param_2 != 0) {
    FUN_0005984e(param_1,param_2,6,"Q 2");
    FUN_00054f62(param_1,param_2,param_3 + 0x19e,0x46,0x58);
    FUN_0000b2b0(param_1 + 0x54 + (param_3 + 0x19e) * 0x68,0x9d,0x5e,0x28,0xb,
                 *(undefined4 *)(param_1 + 0x34));
  }
  return;
}

