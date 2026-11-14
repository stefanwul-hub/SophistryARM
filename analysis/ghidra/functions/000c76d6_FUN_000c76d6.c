/* 000c76d6 FUN_000c76d6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000c76d6(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  size_t sVar9;
  
  puVar8 = (undefined4 *)param_1[1];
  if (puVar8 != (undefined4 *)param_1[2]) {
    if (puVar8 == (undefined4 *)0x0) {
      iVar5 = 0;
    }
    else {
      *puVar8 = puVar8[-1];
      iVar5 = param_1[1];
    }
    param_1[1] = iVar5 + 4;
    uVar1 = *param_3;
    uVar6 = (iVar5 + -4) - (int)param_2 & 0xfffffffc;
    _memmove((void *)(iVar5 - uVar6),param_2,uVar6);
    *param_2 = uVar1;
    return;
  }
  uVar6 = (int)puVar8 - *param_1 >> 2;
  if (uVar6 == 0x3fffffff) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("vector::_M_insert_aux");
  }
  if (uVar6 == 0) {
    uVar7 = 1;
  }
  else {
    uVar7 = uVar6 * 2;
    if (uVar7 < uVar6) {
      uVar7 = 0x3fffffff;
    }
    else if (0x3fffffff < uVar7) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_alloc();
    }
  }
  pvVar3 = operator_new(uVar7 * 4);
  sVar9 = (int)param_2 - *param_1;
  _memmove(pvVar3,(void *)*param_1,sVar9);
  puVar8 = (undefined4 *)((int)pvVar3 + sVar9);
  if (puVar8 != (undefined4 *)0x0) {
    *puVar8 = *param_3;
  }
  iVar5 = param_1[1];
  _memmove(puVar8 + 1,param_2,iVar5 - (int)param_2);
  pvVar2 = (void *)*param_1;
  for (pvVar4 = pvVar2; pvVar4 != (void *)param_1[1]; pvVar4 = (void *)((int)pvVar4 + 4)) {
  }
  if (pvVar2 != (void *)0x0) {
    operator_delete(pvVar2);
  }
  *param_1 = (int)pvVar3;
  param_1[1] = (iVar5 - (int)param_2) + (int)(puVar8 + 1);
  param_1[2] = (int)((int)pvVar3 + uVar7 * 4);
  return;
}

