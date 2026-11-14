/* 000a1ec8 COffscreenContext_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void COffscreenContext_vslot_1(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  *param_1 = &PTR_COffscreenContext_vslot_0_000f4048;
  piVar1 = (int *)param_1[0x1a];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (param_1[0x18] != 0) {
    _CGContextRestoreGState(param_1[0x18]);
    _CGContextRelease(param_1[0x18]);
  }
  param_1[0x18] = 0;
  if ((void *)param_1[0x20] == (void *)0x0) {
    iVar2 = param_1[0x1b];
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x1c) != 0)) {
      uVar3 = _GetGWorldPixMap(*(undefined4 *)(iVar2 + 0x1c));
      _UnlockPixels(uVar3);
      FUN_000a1e2c(param_1);
      operator_delete(param_1);
      return;
    }
  }
  else {
    _free((void *)param_1[0x20]);
  }
  FUN_000a1e2c(param_1);
  operator_delete(param_1);
  return;
}

