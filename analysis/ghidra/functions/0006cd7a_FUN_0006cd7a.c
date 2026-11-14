/* 0006cd7a FUN_0006cd7a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0006cd7a(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  longdouble lVar3;
  double dVar4;
  
  FUN_00031e98(param_1);
  *param_1 = &PTR_Delay2_c_vslot_0_000f0fa8;
  FUN_000b885e(param_1 + 0x294);
  FUN_000b885e(param_1 + 0x29d);
  param_1[0x282] = 0;
  param_1[0x283] = 0;
  param_1[0x284] = 0;
  param_1[0x285] = 0;
  param_1[0x286] = 0;
  param_1[0x287] = 0;
  param_1[0x288] = 0;
  param_1[0x291] = 0;
  param_1[0x292] = 0;
  param_1[0x293] = 0;
  param_1[0x289] = 0;
  *(undefined1 *)(param_1 + 0x290) = 1;
  *(undefined1 *)((int)param_1 + 0xa41) = 0;
  param_1[0x28a] = 0;
  param_1[0x28b] = 0;
  param_1[0x28c] = 0;
  param_1[0x28d] = 0;
  param_1[0x28e] = 0;
  param_1[0x28f] = 0;
  dVar4 = (double)DAT_000fd060;
  iVar2 = 0;
  puVar1 = param_1;
  do {
    lVar3 = (longdouble)_sin((double)iVar2 * dVar4 * 6.283185307179586);
    puVar1[0x82] = (float)lVar3;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar2 != 0x200);
  *(undefined8 *)(param_1 + 0x78) = 0;
  *(undefined8 *)(param_1 + 0x7a) = 0;
  *(undefined8 *)(param_1 + 0x7c) = 0;
  *(undefined8 *)(param_1 + 0x7e) = 0;
  *(undefined1 *)(param_1 + 0x80) = 1;
  return;
}

