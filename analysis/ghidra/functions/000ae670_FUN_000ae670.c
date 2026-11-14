/* 000ae670 FUN_000ae670 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000ae670(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)operator_new(0x10);
  *puVar1 = PTR_DAT_001038d8 + 8;
  puVar1[1] = 1;
  *puVar1 = PTR_DAT_001038d4 + 8;
  puVar2 = (undefined4 *)_malloc(0xc);
  puVar1[2] = puVar2;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar1[3] = 0xc;
  *param_1 = puVar1;
  return;
}

