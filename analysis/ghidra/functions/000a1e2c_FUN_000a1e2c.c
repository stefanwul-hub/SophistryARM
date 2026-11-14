/* 000a1e2c FUN_000a1e2c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000a1e2c(undefined4 *param_1)

{
  undefined4 uVar1;
  
  *param_1 = &PTR_CDrawContext_vslot_0_000f4008;
  if (param_1[0x18] != 0) {
    _CGContextRestoreGState(param_1[0x18]);
    _CGContextRestoreGState(param_1[0x18]);
    _CGContextSynchronize(param_1[0x18]);
    if ((param_1[6] == 0) && (param_1[7] != 0)) {
      uVar1 = _GetWindowPort(param_1[7]);
      _QDEndCGContext(uVar1,param_1 + 0x18);
    }
    if (param_1[8] != 0) {
      *(undefined4 *)(param_1[8] + 0x94) = 0;
    }
  }
  *param_1 = PTR_DAT_00103888 + 8;
  return;
}

