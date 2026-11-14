/* 000aef2c FUN_000aef2c */

undefined4
FUN_000aef2c(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_5 + 4);
  *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)(param_5 + 0xc);
  *(undefined4 *)(param_3 + 8) = *(undefined4 *)(param_5 + 8);
  return 0;
}

