/* 000c5ef2 FUN_000c5ef2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000c5ef2(int *param_1,uint param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  void *pvVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (0x7ffffff < param_2) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("vector::reserve");
  }
  puVar7 = (undefined4 *)*param_1;
  if (param_2 <= (uint)(param_1[2] - (int)puVar7 >> 5)) {
    return;
  }
  puVar1 = (undefined4 *)param_1[1];
  iVar3 = (int)puVar1 - (int)puVar7;
  if (param_2 < 0x8000000) {
    puVar4 = (undefined4 *)operator_new(param_2 * 0x20);
    puVar6 = puVar4;
    for (; puVar1 != puVar7; puVar7 = puVar7 + 8) {
      if (puVar6 != (undefined4 *)0x0) {
        *puVar6 = *puVar7;
        puVar6[1] = puVar7[1];
        puVar6[2] = puVar7[2];
        puVar6[3] = puVar7[3];
        puVar6[4] = puVar7[4];
        puVar6[5] = puVar7[5];
        puVar6[6] = puVar7[6];
        puVar6[7] = puVar7[7];
      }
      puVar6 = puVar6 + 8;
    }
    pvVar2 = (void *)*param_1;
    for (pvVar5 = pvVar2; (void *)param_1[1] != pvVar5; pvVar5 = (void *)((int)pvVar5 + 0x20)) {
    }
    if (pvVar2 != (void *)0x0) {
      operator_delete(pvVar2);
    }
    *param_1 = (int)puVar4;
    param_1[1] = (int)(puVar4 + (iVar3 >> 5) * 8);
    param_1[2] = (int)(puVar4 + param_2 * 8);
    return;
  }
                    /* WARNING: Subroutine does not return */
  std::__throw_bad_alloc();
}

