/* 000a317e CFrame_vslot_70 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 CFrame_vslot_70(int *param_1,int param_2,int param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined1 local_3c [8];
  float local_34;
  float local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  
  cVar1 = (**(code **)(*param_1 + 0x150))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  iVar3 = param_1[2];
  if ((param_1[4] - iVar3 == param_2) && (param_3 == param_1[5] - param_1[3])) {
    return 0;
  }
  piVar2 = (int *)param_1[0x18];
  if (piVar2 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*piVar2 + 8))(piVar2);
    if (((piVar2 != (int *)0x0) &&
        (iVar3 = (**(code **)(*piVar2 + 0x15c))(piVar2,"sizeWindow"), iVar3 != 0)) &&
       (cVar1 = (**(code **)(*piVar2 + 0x1ac))(piVar2,param_2,param_3), cVar1 != '\0')) {
      param_1[4] = param_2 + param_1[2];
      param_1[5] = param_3 + param_1[3];
      _HIViewGetFrame(param_1[0x1f],local_3c);
      local_34 = (float)param_2;
      local_30 = (float)param_3;
      _HIViewSetFrame(param_1[0x1f],local_3c);
      return 1;
    }
    iVar3 = param_1[2];
  }
  param_1[4] = param_2 + iVar3;
  param_1[5] = param_3 + param_1[3];
  if (param_1[0x1f] != 0) {
    *(undefined1 *)(param_1 + 0x22) = 1;
    _HIViewGetFrame(param_1[0x1f],local_3c);
    local_34 = (float)param_2;
    local_30 = (float)param_3;
    _HIViewSetFrame(param_1[0x1f],local_3c);
    *(undefined1 *)(param_1 + 0x22) = 0;
    _HIViewSetNeedsDisplay(param_1[0x1f],1);
  }
  local_20 = param_1[5] - param_1[3];
  local_24 = param_1[4] - param_1[2];
  local_2c = 0;
  local_28 = 0;
  CModulFramePl_vslot_29(param_1,&local_2c);
  return 1;
}

