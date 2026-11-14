/* 00094808 FUN_00094808 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00094808(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_000021e2(param_1,param_2,param_3,param_4);
  *param_1 = &PTR_CKeyboardBase_vslot_0_000f34c8;
  param_1[300] = param_5;
  if (param_5 != 0) {
    iVar2 = 0;
    puVar1 = param_1;
    do {
      puVar1[0x2c] = 0;
      puVar1[0xac] = 0xffffffff;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 != 0x80);
    param_1[0x12e] = param_6;
    param_1[0x12d] = param_7;
  }
  return;
}

