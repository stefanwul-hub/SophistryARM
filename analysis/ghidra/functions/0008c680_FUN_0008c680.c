/* 0008c680 FUN_0008c680 */

undefined4
FUN_0008c680(int param_1,int param_2,int param_3,int param_4,int *param_5,undefined4 *param_6,
            undefined4 *param_7,int *param_8,undefined4 param_9)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x124) == 0) {
    return 0;
  }
  *param_8 = 0;
  if (param_3 == 0x62) {
    *(undefined1 *)(param_1 + 0x330) = 1;
    *(uint *)(param_1 + 0x334) = (*(uint *)(param_1 + 0x334) & 0xff80) + param_4;
    *param_8 = 0;
    param_4 = *(int *)(param_1 + 0x334);
    goto LAB_0008c6d2;
  }
  if (param_3 < 99) {
    if (param_3 == 0x60) {
      *param_8 = 2;
      if (*(char *)(param_1 + 0x330) == '\0') {
        *(int *)(param_1 + 0x334) = param_4;
        goto LAB_0008c6d2;
      }
    }
    else {
      if (param_3 != 0x61) goto LAB_0008c6bd;
      *param_8 = 3;
      if (*(char *)(param_1 + 0x330) == '\0') {
        *(int *)(param_1 + 0x334) = param_4;
        goto LAB_0008c6d2;
      }
    }
    param_4 = *(int *)(param_1 + 0x334);
  }
  else {
    if (param_3 == 99) {
      *(undefined1 *)(param_1 + 0x330) = 1;
      *(uint *)(param_1 + 0x334) = (*(uint *)(param_1 + 0x334) & 0x7f) + param_4 * 0x80;
      *param_8 = 0;
      param_4 = *(int *)(param_1 + 0x334);
      goto LAB_0008c6d2;
    }
LAB_0008c6bd:
    *(int *)(param_1 + 0x334) = param_3;
    *param_8 = 1;
    param_4 = *(int *)(param_1 + 0x334);
  }
LAB_0008c6d2:
  if (*param_8 != 0) {
    iVar2 = *param_5 + 1;
    *param_5 = iVar2;
    if (iVar2 < 0x80) {
      iVar3 = iVar2 * 0x4d0;
      do {
        iVar1 = iVar3 + *(int *)(param_1 + 0x124);
        if (((0 < *(int *)(iVar1 + 0x628)) && (param_4 == *(int *)(iVar1 + 0x318))) &&
           (param_2 == *(int *)(iVar1 + 0x548))) {
          if (0x7f < iVar2) {
            return 0;
          }
          *param_6 = *(undefined4 *)(*(int *)(param_1 + 0x124) + 0x4d8 + iVar3);
          *param_7 = *(undefined4 *)(*param_5 * 0x4d0 + *(int *)(param_1 + 0x124) + 0x388);
          FUN_0008beea(param_1,param_6,param_7,param_8,param_9);
          return 1;
        }
        iVar2 = iVar2 + 1;
        *param_5 = iVar2;
        iVar3 = iVar3 + 0x4d0;
      } while (iVar2 != 0x80);
    }
  }
  return 0;
}

