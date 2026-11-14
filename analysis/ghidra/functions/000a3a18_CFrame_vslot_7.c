/* 000a3a18 CFrame_vslot_7 */

void CFrame_vslot_7(int *param_1,int param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int local_10;
  
  local_10 = param_2;
  if (param_2 == 0) {
    local_10 = param_1[0x25];
  }
  if (param_1[0x1b] != 0) {
    (**(code **)(*param_1 + 0x13c))(param_1,0);
  }
  if ((param_4 == 0xffffffff) && (local_10 != 0)) {
    uVar3 = _GetCurrentButtonState();
    param_4 = uVar3 & 1;
    if ((uVar3 & 2) != 0) {
      param_4 = uVar3 & 1 | 4;
    }
    if ((uVar3 & 4) != 0) {
      param_4 = param_4 | 2;
    }
    uVar3 = _GetCurrentKeyModifiers();
    if ((uVar3 & 0x100) != 0) {
      param_4 = param_4 | 0x10;
    }
    if ((uVar3 & 0x200) != 0) {
      param_4 = param_4 | 8;
    }
    if ((uVar3 & 0x800) != 0) {
      param_4 = param_4 | 0x20;
    }
    if ((uVar3 & 0x1000) != 0) {
      param_4 = param_4 | 0x40;
    }
    if (((param_4 & 0x40) != 0) && ((param_4 & 1) != 0)) {
      param_4 = param_4 & 0xffffffbe | 4;
    }
  }
  piVar1 = (int *)param_1[0x1a];
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0x68))(piVar1,param_3,param_4);
    if (cVar2 == '\0') {
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x000a3aa2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)param_1[0x1a] + 0x1c))();
    return;
  }
  CModulFramePl_vslot_7();
  return;
}

