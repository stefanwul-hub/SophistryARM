/* 000a38fc CModulFramePl_vslot_7 */

void CModulFramePl_vslot_7(int param_1,int param_2,int *param_3,uint param_4)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int local_14;
  int local_10;
  
  local_14 = *param_3 - *(int *)(param_1 + 8);
  local_10 = param_3[1] - *(int *)(param_1 + 0xc);
  if ((param_4 == 0xffffffff) && (param_2 != 0)) {
    uVar3 = _GetCurrentButtonState();
    uVar5 = uVar3 & 1 | 4;
    if ((uVar3 & 2) == 0) {
      uVar5 = uVar3 & 1;
    }
    uVar4 = uVar5 | 2;
    if ((uVar3 & 4) == 0) {
      uVar4 = uVar5;
    }
    uVar3 = _GetCurrentKeyModifiers();
    uVar5 = uVar4 | 0x10;
    if ((uVar3 & 0x100) == 0) {
      uVar5 = uVar4;
    }
    uVar4 = uVar5 | 8;
    if ((uVar3 & 0x200) == 0) {
      uVar4 = uVar5;
    }
    uVar5 = uVar4 | 0x20;
    if ((uVar3 & 0x800) == 0) {
      uVar5 = uVar4;
    }
    param_4 = uVar5 | 0x40;
    if ((uVar3 & 0x1000) == 0) {
      param_4 = uVar5;
    }
    if (((param_4 & 0x40) != 0) && ((param_4 & 1) != 0)) {
      param_4 = param_4 & 0xffffffbe | 4;
    }
  }
  piVar6 = *(int **)(param_1 + 0x40);
  if (piVar6 != (int *)0x0) {
    do {
      piVar1 = (int *)*piVar6;
      if (((piVar1 != (int *)0x0) && (cVar2 = (**(code **)(*piVar1 + 0x5c))(piVar1), cVar2 != '\0'))
         && (cVar2 = (**(code **)(*piVar1 + 0x68))(piVar1,&local_14,param_4), cVar2 != '\0')) {
        (**(code **)(*piVar1 + 0x1c))(piVar1,param_2,&local_14,param_4);
        return;
      }
      piVar6 = (int *)piVar6[2];
    } while (piVar6 != (int *)0x0);
  }
  return;
}

