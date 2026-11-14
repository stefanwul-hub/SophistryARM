/* 0008be50 FUN_0008be50 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble FUN_0008be50(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  
  fVar1 = 0.0;
  if (*(int *)(param_1 + 0x124) == 0) goto LAB_0008beba;
  if (param_2 < 0) {
    param_2 = 0;
LAB_0008be83:
    if (0.0 <= param_3) goto LAB_0008be8c;
LAB_0008bedd:
    if (NAN(param_3)) goto LAB_0008be8c;
    fVar2 = 0.0;
  }
  else {
    if (0x7f < param_2) {
      param_2 = 0x26330;
      goto LAB_0008be83;
    }
    param_2 = param_2 * 0x4d0;
    if (param_3 < 0.0) goto LAB_0008bedd;
LAB_0008be8c:
    fVar2 = 1.0;
    if (param_3 <= 1.0) {
      fVar2 = param_3;
    }
  }
  param_2 = *(int *)(param_1 + 0x124) + param_2;
  fVar1 = *(float *)(param_2 + 0x404);
  fVar1 = (*(float *)(param_2 + 0x474) - fVar1) * fVar2 + fVar1;
LAB_0008beba:
  return (longdouble)fVar1;
}

