/* 000b6fd6 Reverb2_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Reverb2_c_vslot_0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  *param_1 = &PTR_Reverb2_c_vslot_0_000f4bc8;
  if ((void *)param_1[0x1d2] != (void *)0x0) {
    _free((void *)param_1[0x1d2]);
  }
  param_1[0x1d2] = 0;
  if ((param_1 != (undefined4 *)0xfffff94c) && (param_1 + 0x1ad != param_1 + 0x1d1)) {
    puVar1 = param_1 + 0x1cc;
    iVar2 = 6;
    do {
      if ((void *)*puVar1 != (void *)0x0) {
        _free((void *)*puVar1);
      }
      *puVar1 = 0;
      puVar1 = puVar1 + -6;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if ((param_1 != (undefined4 *)0xfffff9dc) && (param_1 + 0x189 != param_1 + 0x1ad)) {
    puVar1 = param_1 + 0x1a8;
    iVar2 = 6;
    do {
      if ((void *)*puVar1 != (void *)0x0) {
        _free((void *)*puVar1);
      }
      *puVar1 = 0;
      puVar1 = puVar1 + -6;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if ((param_1 != (undefined4 *)0xfffffbfc) && (param_1 + 0x101 != param_1 + 0x189)) {
    puVar1 = param_1 + 0x179;
    iVar2 = 8;
    do {
      if ((void *)*puVar1 != (void *)0x0) {
        _free((void *)*puVar1);
      }
      *puVar1 = 0;
      puVar1 = puVar1 + -0x11;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if ((param_1 != (undefined4 *)0xfffffe1c) && (param_1 + 0x79 != param_1 + 0x101)) {
    param_1 = param_1 + 0xf1;
    iVar2 = 8;
    do {
      if ((void *)*param_1 != (void *)0x0) {
        _free((void *)*param_1);
      }
      *param_1 = 0;
      param_1 = param_1 + -0x11;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_00031edc();
  return;
}

