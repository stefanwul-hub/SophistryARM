/* 0001cb52 FUN_0001cb52 */

void FUN_0001cb52(int param_1,int param_2,int *param_3,int *param_4,int *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_18;
  int *local_14;
  undefined4 local_10;
  
  if (*(char *)(param_1 + 0xcfc4) != '\0') {
    *param_5 = -1;
    *param_3 = 0;
    *param_4 = -1;
    if (((*(int *)(param_1 + 0x8abc) != 0) && (-1 < param_2)) &&
       (param_2 < *(int *)(param_1 + 0x9a48))) {
      iVar3 = param_2 * 0x20;
      piVar1 = (int *)(*(int *)(param_1 + 0x8abc) + iVar3);
      if (param_2 == *piVar1) {
        *param_3 = piVar1[5];
        *param_4 = *(int *)(iVar3 + 0x18 + *(int *)(param_1 + 0x8abc));
        iVar2 = *(int *)(iVar3 + 0xc + *(int *)(param_1 + 0x8abc));
        *param_5 = iVar2;
        if (iVar2 == -1) {
          *param_5 = *(int *)(param_1 + 0xcfe0);
        }
        if (*param_5 < 0) {
          *param_5 = 0;
        }
        iVar2 = *(int *)(param_1 + 0xcfb0) + -1;
        if (iVar2 < *param_5) {
          *param_5 = iVar2;
        }
        iVar3 = *(int *)(iVar3 + 0x10 + *(int *)(param_1 + 0x8abc));
        if ((iVar3 != 0) && (iVar3 < 9)) {
          local_18 = -1;
          FUN_0001cb52(param_1,*(undefined4 *)(param_1 + 0x50d0 + iVar3 * 4),&local_14,&local_18,
                       &local_10);
          if ((local_18 == -1) || (local_14 == (int *)0x0)) {
            iVar2 = 0;
          }
          else {
            iVar2 = (**(code **)(*local_14 + 0x30))(local_14,local_10,local_18);
          }
          *param_4 = *param_4 + iVar2 * *(int *)(param_1 + 0x50f4 + iVar3 * 4);
        }
      }
    }
  }
  return;
}

