/* 0002b954 FUN_0002b954 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0002b954(undefined4 *param_1,int param_2)

{
  void *pvVar1;
  
  *param_1 = &PTR_CmdBuffer_c_vslot_0_000e7678;
  param_1[1] = param_2;
  param_1[4] = 0;
  param_1[3] = 0;
  pvVar1 = _malloc(param_2 * 0x18 + 0x18);
  param_1[2] = pvVar1;
  return;
}

