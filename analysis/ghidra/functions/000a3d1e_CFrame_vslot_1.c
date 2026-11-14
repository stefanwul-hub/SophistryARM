/* 000a3d1e CFrame_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CFrame_vslot_1(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined1 local_1d [13];
  
  *param_1 = (int)&PTR_CFrame_vslot_0_000f4148;
  if (param_1[0x1a] != 0) {
    local_1d[0] = 0;
    CModulFramePl_vslot_45(param_1,param_1[0x1a],local_1d);
  }
  CFrame_vslot_78(param_1,0);
  if (*(char *)((int)param_1 + 0x72) != '\0') {
    FUN_0009ea98();
    *(undefined1 *)((int)param_1 + 0x72) = 0;
  }
  piVar3 = (int *)param_1[0x25];
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  if ((char)param_1[0x26] != '\0') {
    cVar1 = (**(code **)(*param_1 + 0x150))(param_1);
    if ((cVar1 != '\0') && (param_1[0x19] != 0)) {
      piVar3 = (int *)(**(code **)(*(int *)param_1[0x18] + 8))((int *)param_1[0x18]);
      (**(code **)(*piVar3 + 0x244))(piVar3,param_1[0x27]);
      param_1[0x19] = 0;
    }
  }
  if ((void *)param_1[0x27] != (void *)0x0) {
    _free((void *)param_1[0x27]);
  }
  if (param_1[0x1f] != 0) {
    _DisposeControl(param_1[0x1f]);
  }
  if (param_1[0x1e] != 0) {
    iVar2 = _UnregisterToolboxObjectClass(param_1[0x1e]);
    if (iVar2 != 0) {
      _fprintf((FILE *)(PTR_001037f8 + 0xb0),"UnregisterToolboxObjectClass failed : %d\n",iVar2);
      FUN_000a3c6a(param_1);
      operator_delete(param_1);
      return;
    }
  }
  FUN_000a3c6a(param_1);
  operator_delete(param_1);
  return;
}

