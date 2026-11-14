/* 0003a25a FUN_0003a25a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0003a25a(undefined4 *param_1)

{
  void *pvVar1;
  
  FUN_00031fec(param_1);
  *param_1 = &PTR_WaveRAM_c_vslot_0_000e8688;
  FUN_000aeb88(param_1 + 0x79);
  FUN_0000a5d4(param_1 + 0x116);
  param_1[0x77] = 0;
  pvVar1 = operator_new(0x20);
  FUN_000126be(pvVar1,0x544d3032,1,0x13);
  param_1[0x48] = pvVar1;
  if ((pvVar1 != (void *)0x0) && (*(int *)((int)pvVar1 + 4) != 0)) {
    *(undefined1 *)((int)param_1 + 0x1e1) = 0;
    *(undefined1 *)(param_1 + 0x78) = 1;
    *(undefined1 *)(param_1 + 0x1bb) = 0;
  }
  return;
}

