/* 00008130 COnOffButtonPl_vslot_7 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void COnOffButtonPl_vslot_7(int param_1,undefined4 param_2)

{
  uint uVar1;
  longdouble lVar2;
  float fVar3;
  float fVar4;
  
  FUN_00001bd4(param_1);
  *(undefined1 *)(param_1 + 0x6c) = 0;
  *(undefined1 *)(param_1 + 0x6d) = 0;
  if (1 < *(int *)(param_1 + 0xb4)) {
    uVar1 = FUN_0009cba2(param_2);
    fVar3 = 1.0 / (float)(*(int *)(param_1 + 0xb4) + -1);
    FUN_00001ca6(param_1,*(undefined4 *)(param_1 + 0x40));
    if ((uVar1 & 1) == 0) {
      lVar2 = (longdouble)FUN_000019e8(param_1);
      fVar4 = (float)lVar2 - fVar3;
      if (fVar4 < 0.01 - fVar3) {
        fVar4 = 1.0;
      }
    }
    else {
      lVar2 = (longdouble)FUN_000019e8(param_1);
      fVar4 = (float)lVar2 + fVar3;
      if (fVar3 + 0.99 < fVar4) {
        fVar4 = 0.0;
      }
    }
    FUN_00001b2e(param_1,param_2,0,fVar4);
    FUN_00001c10();
    return;
  }
  return;
}

