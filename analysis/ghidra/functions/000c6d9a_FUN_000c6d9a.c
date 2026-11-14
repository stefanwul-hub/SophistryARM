/* 000c6d9a FUN_000c6d9a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000c6d9a(undefined4 *param_1,uint param_2)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  void *pvVar5;
  
  if (0x3fffffff < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("vector::reserve");
  }
  pvVar1 = (void *)*param_1;
  if (param_2 <= (uint)(param_1[2] - (int)pvVar1 >> 2)) {
    return;
  }
  iVar2 = param_1[1];
  if (param_2 < 0x40000000) {
    pvVar4 = operator_new(param_2 * 4);
    _memmove(pvVar4,pvVar1,iVar2 - (int)pvVar1);
    pvVar3 = (void *)*param_1;
    for (pvVar5 = pvVar3; (void *)param_1[1] != pvVar5; pvVar5 = (void *)((int)pvVar5 + 4)) {
    }
    if (pvVar3 != (void *)0x0) {
      operator_delete(pvVar3);
    }
    *param_1 = pvVar4;
    param_1[1] = (void *)((int)pvVar4 + (iVar2 - (int)pvVar1 >> 2) * 4);
    param_1[2] = (void *)(param_2 * 4 + (int)pvVar4);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_alloc();
}

