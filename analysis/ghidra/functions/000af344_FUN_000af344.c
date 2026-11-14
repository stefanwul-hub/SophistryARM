/* 000af344 FUN_000af344 */

void FUN_000af344(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  
  if (((-1 < param_2) && (param_2 <= param_3)) && (param_3 < *(int *)(param_1 + 0x22c))) {
    iVar2 = param_2 << 2;
    iVar3 = 0;
    iVar1 = param_2;
    do {
      *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x21c)) =
           *(undefined4 *)(iVar2 + *(int *)(param_1 + 0x21c));
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 4;
      iVar2 = iVar2 + 4;
    } while (iVar1 <= param_3);
    lVar4 = (longdouble)
            FUN_00015302((double)*(int *)(param_1 + 0x228),(double)*(int *)(param_1 + 0x22c));
    iVar1 = (param_3 - param_2) + 1;
    *(int *)(param_1 + 0x22c) = iVar1;
    *(int *)(param_1 + 0x228) = (int)lVar4 * iVar1;
    *(undefined4 *)(param_1 + 0x26c) = 0;
    *(int *)(param_1 + 0x270) = param_3 - param_2;
  }
  return;
}

