/* 00001bd4 FUN_00001bd4 */

void FUN_00001bd4(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (0 < *(int *)(param_1 + 0xa4)) {
    iVar3 = 0;
    iVar1 = 0;
    do {
      iVar2 = iVar1 + *(int *)(param_1 + 0x90);
      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 0xc);
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0x18;
    } while (iVar3 < *(int *)(param_1 + 0xa4));
  }
  return;
}

