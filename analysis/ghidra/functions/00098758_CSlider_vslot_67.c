/* 00098758 CSlider_vslot_67 */

void CSlider_vslot_67(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 0x74) = *param_2;
  *(undefined4 *)(param_1 + 0x78) = uVar1;
  if ((*(byte *)(param_1 + 0x84) & 1) != 0) {
    iVar2 = *(int *)(param_1 + 0x74) + *(int *)(param_1 + 0x9c);
    *(int *)(param_1 + 0x94) = iVar2;
    *(int *)(param_1 + 0x98) = iVar2 + *(int *)(param_1 + 0x90) + *(int *)(param_1 + 0x88);
    return;
  }
  iVar2 = *(int *)(param_1 + 0x78) + *(int *)(param_1 + 0x9c);
  *(int *)(param_1 + 0x94) = iVar2;
  *(int *)(param_1 + 0x98) = iVar2 + *(int *)(param_1 + 0x90) + *(int *)(param_1 + 0x8c);
  return;
}

