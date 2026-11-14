/* 000322d4 FUN_000322d4 */

void FUN_000322d4(undefined4 param_1,float *param_2,int param_3)

{
  int iVar1;
  float fVar2;
  
  if ((param_2 != (float *)0x0) && (fVar2 = *param_2, 1 < param_3)) {
    iVar1 = 1;
    do {
      param_2 = param_2 + 1;
      fVar2 = fVar2 + *param_2;
      *param_2 = fVar2;
      iVar1 = iVar1 + 1;
    } while (param_3 != iVar1);
  }
  return;
}

