/* 00085cca InBuffer2_c_vslot_13 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 InBuffer2_c_vslot_13(int param_1,undefined4 *param_2,char param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if ((*(char *)(param_1 + 0x24) != '\0') && (0 < *(int *)(param_1 + 0x14))) {
    if ((*(char *)(param_1 + 0x28) == '\0') && (*(char *)(param_1 + 0x27) == '\0')) {
      *param_2 = *(undefined4 *)(param_1 + 0x34);
      return 1;
    }
    if (param_3 != '\0') {
      iVar3 = *(int *)(param_1 + 0x2c) + -1;
      if (0 < *(int *)(param_1 + 0x2c)) {
        iVar2 = iVar3 * 4;
        do {
          *(float *)(iVar2 + *(int *)(param_1 + 0x38)) =
               (*(float *)(iVar2 + *(int *)(param_1 + 0x34)) +
               *(float *)(iVar2 + *(int *)(param_1 + 0x3c))) * 0.5;
          iVar2 = iVar2 + -4;
          bVar1 = 0 < iVar3;
          iVar3 = iVar3 + -1;
        } while (bVar1);
      }
      *param_2 = *(undefined4 *)(param_1 + 0x38);
      return 1;
    }
  }
  return 0;
}

