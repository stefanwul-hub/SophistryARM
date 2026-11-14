/* 00085e0a InBuffer2_c_vslot_17 */

void InBuffer2_c_vslot_17(int param_1)

{
  bool bVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  
  if ((*(char *)(param_1 + 0x28) != '\0') &&
     (iVar4 = *(int *)(param_1 + 0x2c) + -1, 0 < *(int *)(param_1 + 0x2c))) {
    iVar2 = iVar4 * 4;
    do {
      pfVar3 = (float *)(iVar2 + *(int *)(param_1 + 0x34));
      *pfVar3 = *pfVar3 + *(float *)(*(int *)(param_1 + 0x38) + iVar2);
      pfVar3 = (float *)(iVar2 + *(int *)(param_1 + 0x3c));
      *pfVar3 = *pfVar3 + *(float *)(*(int *)(param_1 + 0x40) + iVar2);
      pfVar3 = (float *)(iVar2 + *(int *)(param_1 + 0x4c));
      *pfVar3 = *pfVar3 + *(float *)(*(int *)(param_1 + 0x38) + iVar2);
      pfVar3 = (float *)(iVar2 + *(int *)(param_1 + 0x50));
      *pfVar3 = *pfVar3 + *(float *)(iVar2 + *(int *)(param_1 + 0x40));
      iVar2 = iVar2 + -4;
      bVar1 = 0 < iVar4;
      iVar4 = iVar4 + -1;
    } while (bVar1);
  }
  if ((*(char *)(param_1 + 0x27) == '\0') && (*(char *)(param_1 + 0x28) == '\0')) {
    *(undefined1 *)(param_1 + 0x27) = 1;
  }
  *(undefined4 *)(param_1 + 0x20) = 4;
  return;
}

