/* 0009c750 FUN_0009c750 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0009c750(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 char *param_5,undefined4 param_6,undefined4 param_7)

{
  undefined2 uVar1;
  
  FUN_0009c4e8(param_1,param_2,param_6,param_7);
  *param_1 = &PTR_CTextEdit_vslot_0_000f3be8;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2c] = 0;
  param_1[0x6d] = 0;
  param_1[0x6e] = 0;
  param_1[0xf] = param_3;
  param_1[0x10] = param_4;
  if (param_5 == (char *)0x0) {
    *(undefined1 *)(param_1 + 0x2d) = 0;
  }
  else {
    _strcpy((char *)(param_1 + 0x2d),param_5);
  }
  uVar1 = _CurResFile();
  *(undefined2 *)((int)param_1 + 0xaa) = uVar1;
  param_1[0x2b] = 0;
  *(undefined1 *)((int)param_1 + 0x33) = 1;
  return;
}

