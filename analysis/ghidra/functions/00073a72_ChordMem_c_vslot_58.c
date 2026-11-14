/* 00073a72 ChordMem_c_vslot_58 */

undefined4 ChordMem_c_vslot_58(int param_1,char *param_2,int param_3,int param_4)

{
  char cVar1;
  int iVar2;
  
  if (*(int *)(param_3 + 8) < 0) {
    *(undefined4 *)(param_3 + 8) = 0;
  }
  if (0x7f < *(int *)(param_3 + 8)) {
    *(undefined4 *)(param_3 + 8) = 0x7f;
  }
  if (*param_2 != '\0') {
    *(undefined4 *)(param_1 + 0x1e0) = 0;
    *param_2 = '\0';
  }
  iVar2 = *(int *)(param_1 + 0x1e0);
  while( true ) {
    if (0x7f < iVar2) {
      return 0;
    }
    cVar1 = FUN_0002d78e(param_1 + 0x1e4 + *(int *)(param_3 + 8) * 0x14,iVar2);
    if (cVar1 != '\0') break;
    iVar2 = *(int *)(param_1 + 0x1e0) + 1;
    *(int *)(param_1 + 0x1e0) = iVar2;
  }
  if (0x7f < *(int *)(param_1 + 0x1e0)) {
    return 0;
  }
  *(int *)(param_4 + 8) = *(int *)(param_1 + 0x1e0);
  *(undefined4 *)(param_4 + 0xc) = 0;
  *(undefined4 *)(param_4 + 0x10) = *(undefined4 *)(param_1 + 0xbe4 + *(int *)(param_3 + 8) * 4);
  *(int *)(param_1 + 0x1e0) = *(int *)(param_1 + 0x1e0) + 1;
  return 1;
}

