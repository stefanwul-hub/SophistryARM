/* 000ac3ea FUN_000ac3ea */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble FUN_000ac3ea(int param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint local_20 [4];
  
  local_20[0] = param_2;
  if (*(char *)(param_1 + 0x20) == '\0') {
    iVar1 = FUN_000c6836(param_1 + 8,local_20);
    if (param_1 + 0xc != iVar1) {
      return (longdouble)*(float *)(iVar1 + 0x20);
    }
  }
  else if (param_2 < (uint)((*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24) >> 3) * -0x55555555
                           )) {
    return (longdouble)*(float *)(*(int *)(param_1 + 0x24) + param_2 * 0x18 + 0xc);
  }
  puVar2 = (undefined4 *)___cxa_allocate_exception(4);
  *puVar2 = 0xffffd582;
                    /* WARNING: Subroutine does not return */
  ___cxa_throw(puVar2,PTR_001037fc,0);
}

