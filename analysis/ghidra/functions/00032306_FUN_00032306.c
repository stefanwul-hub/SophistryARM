/* 00032306 FUN_00032306 */

void FUN_00032306(undefined4 param_1,float *param_2,int param_3)

{
  float fVar1;
  int iVar2;
  float fVar3;
  
  if ((param_2 != (float *)0x0) && (1 < param_3)) {
    iVar2 = 1;
    fVar3 = *param_2;
    do {
      param_2 = param_2 + 1;
      fVar1 = *param_2;
      *param_2 = fVar1 - fVar3;
      iVar2 = iVar2 + 1;
      fVar3 = fVar1;
    } while (param_3 != iVar2);
  }
  return;
}

