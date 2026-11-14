/* 0002df68 MemC_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void MemC_c_vslot_0(undefined4 *param_1)

{
  *param_1 = &PTR_MemC_c_vslot_0_000e7b68;
  if (((void *)param_1[1] != (void *)0x0) && (*(char *)(param_1 + 3) != '\0')) {
    _free((void *)param_1[1]);
    param_1[1] = 0;
    param_1[2] = 0;
    return;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

