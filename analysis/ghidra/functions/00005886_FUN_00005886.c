/* 00005886 FUN_00005886 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00005886(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,float param_7,float param_8)

{
  longdouble lVar1;
  float fVar2;
  
  FUN_000021e2(param_1,param_2,param_3,param_4);
  *param_1 = &PTR_CKnobPl_vslot_0_000e4fa8;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = *param_2;
  param_1[0x33] = param_2[1];
  param_1[0x2e] = param_5;
  param_1[0x2f] = param_6;
  param_1[0x2c] = 0x42f00000;
  param_1[0x34] = param_7;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  *(bool *)((int)param_1 + 0xb5) = 359.99 <= param_7;
  lVar1 = (longdouble)FUN_00015302(0,0x40768000,(double)param_7 * 6.283185307179586);
  param_1[0x35] = (float)lVar1;
  fVar2 = (param_8 / 360.0) * 6.2831855 + 2.618;
  param_1[0x36] = fVar2;
  if (fVar2 < 0.0) {
    do {
      fVar2 = fVar2 + 6.2831855;
    } while (fVar2 < 0.0);
    param_1[0x36] = fVar2;
  }
  fVar2 = (float)param_1[0x36];
  if (6.2831855 < fVar2) {
    do {
      fVar2 = fVar2 - 6.2831855;
    } while (6.2831855 < fVar2);
    param_1[0x36] = fVar2;
  }
  CControlPl_vslot_77(param_1,2);
  return;
}

