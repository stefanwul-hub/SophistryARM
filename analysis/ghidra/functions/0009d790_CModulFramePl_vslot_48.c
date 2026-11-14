/* 0009d790 CModulFramePl_vslot_48 */

int CModulFramePl_vslot_48(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  if (iVar2 != 0) {
    iVar1 = 0;
    do {
      iVar2 = *(int *)(iVar2 + 4);
      iVar1 = iVar1 + 1;
    } while (iVar2 != 0);
    return iVar1;
  }
  return 0;
}

