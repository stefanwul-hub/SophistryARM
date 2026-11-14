/* 000c5dd0 FUN_000c5dd0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000c5dd0(int *param_1,uint param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (0x15555555 < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("vector::reserve");
  }
  puVar7 = (undefined4 *)*param_1;
  if (param_2 <= (uint)((param_1[2] - (int)puVar7 >> 2) * -0x55555555)) {
    return;
  }
  puVar1 = (undefined4 *)param_1[1];
  iVar5 = (int)puVar1 - (int)puVar7;
  if (param_2 < 0x15555556) {
    puVar3 = (undefined4 *)operator_new(param_2 * 0xc);
    puVar6 = puVar3;
    for (; puVar1 != puVar7; puVar7 = puVar7 + 3) {
      if (puVar6 != (undefined4 *)0x0) {
        *puVar6 = *puVar7;
        puVar6[1] = puVar7[1];
        puVar6[2] = puVar7[2];
      }
      puVar6 = puVar6 + 3;
    }
    pvVar2 = (void *)*param_1;
    for (pvVar4 = pvVar2; (void *)param_1[1] != pvVar4; pvVar4 = (void *)((int)pvVar4 + 0xc)) {
    }
    if (pvVar2 != (void *)0x0) {
      operator_delete(pvVar2);
    }
    *param_1 = (int)puVar3;
    param_1[1] = (int)(puVar3 + (iVar5 >> 2));
    param_1[2] = (int)(puVar3 + param_2 * 3);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_alloc();
}

