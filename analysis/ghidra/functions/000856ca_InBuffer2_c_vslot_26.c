/* 000856ca InBuffer2_c_vslot_26 */

void InBuffer2_c_vslot_26(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(bool *)(param_1 + 0x24) = 0 < *(int *)(param_1 + 0x14) && 0 < *(int *)(param_1 + 0x1c);
  if (0 < *(int *)(param_1 + 0x18)) {
    iVar2 = 0;
    iVar1 = param_1;
    do {
      while (((*(char *)(param_1 + 0x25) == '\0' || (iVar2 == 1)) || (iVar2 == 3))) {
        *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) & *(int *)(iVar1 + 0x34) != 0;
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 4;
        if (*(int *)(param_1 + 0x18) <= iVar2) goto LAB_00085724;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < *(int *)(param_1 + 0x18));
  }
LAB_00085724:
  *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) & *(int *)(param_1 + 0xc) != 0;
  return;
}

