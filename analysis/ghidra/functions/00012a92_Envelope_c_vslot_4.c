/* 00012a92 Envelope_c_vslot_4 */

void Envelope_c_vslot_4(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[0x48];
  if ((iVar1 != 0) && (0 < *(int *)(iVar1 + 8))) {
    iVar2 = 0;
    do {
      FUN_00011b02(iVar1,iVar2);
      (**(code **)(*param_1 + 0x78))(param_1,iVar2,0xffffffff);
      iVar2 = iVar2 + 1;
      iVar1 = param_1[0x48];
    } while (iVar2 < *(int *)(iVar1 + 8));
    return;
  }
  return;
}

