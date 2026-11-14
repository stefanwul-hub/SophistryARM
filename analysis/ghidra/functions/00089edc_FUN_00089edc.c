/* 00089edc FUN_00089edc */

undefined4 FUN_00089edc(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((-1 < param_2) && (param_2 < 0x10)) {
    iVar1 = FUN_0002e1c0(param_1 + 0x104);
    if (*param_3 == 99) {
      *(int *)(param_1 + 4 + param_2 * 4) = *param_4;
      *(int *)(param_1 + 0x84 + param_2 * 4) = iVar1;
    }
    if (*param_3 == 0x62) {
      *(int *)(param_1 + 0x44 + param_2 * 4) = *param_4;
      *(int *)(param_1 + 0x84 + param_2 * 4) = iVar1;
      iVar2 = iVar1;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x84 + param_2 * 4);
    }
    if ((iVar2 == -1) || (iVar1 < iVar2 + 1000)) {
      if ((*param_3 == 6) &&
         ((iVar1 = *(int *)(param_1 + 4 + param_2 * 4), -1 < iVar1 &&
          (iVar2 = *(int *)(param_1 + 0x44 + param_2 * 4), -1 < iVar2)))) {
        *param_3 = iVar2 + iVar1 * 0x80;
        *(int *)(param_1 + 0xc4 + param_2 * 4) = *param_4;
        *(undefined4 *)(param_1 + 0x84 + param_2 * 4) = 0xffffffff;
        if (*param_3 < 0) {
          *param_3 = 0;
        }
        if (0x3fff < *param_3) {
          *param_3 = 0x3fff;
        }
        if (*param_4 < 0) {
          *param_4 = 0;
        }
        if (0x7f < *param_4) {
          *param_4 = 0x7f;
        }
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
      if (((*param_3 == 0x26) && (iVar1 = *(int *)(param_1 + 4 + param_2 * 4), -1 < iVar1)) &&
         (iVar2 = *(int *)(param_1 + 0x44 + param_2 * 4), -1 < iVar2)) {
        *param_3 = iVar2 + iVar1 * 0x80;
        *param_4 = *param_4 + *(int *)(param_1 + 0xc4 + param_2 * 4) * 0x80;
        *(undefined4 *)(param_1 + 0x84 + param_2 * 4) = 0xffffffff;
        if (*param_3 < 0) {
          *param_3 = 0;
        }
        if (0x3fff < *param_3) {
          *param_3 = 0x3fff;
        }
        if (*param_4 < 0) {
          *param_4 = 0;
        }
        if (0x3fff < *param_4) {
          *param_4 = 0x3fff;
        }
        return 1;
      }
      return uVar3;
    }
  }
  return 0;
}

