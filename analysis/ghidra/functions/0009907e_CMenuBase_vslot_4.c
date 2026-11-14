/* 0009907e CMenuBase_vslot_4 */

void CMenuBase_vslot_4(int param_1,undefined4 param_2)

{
  if ((-1 < *(int *)(param_1 + 0xbc)) && (*(int *)(param_1 + 0xb4) != 0)) {
    FUN_00098ac0(param_1,param_2,
                 *(int *)(*(int *)(param_1 + 0xa4) + *(int *)(param_1 + 0xbc) * 4) +
                 *(int *)(param_1 + 0xd8),0);
    return;
  }
  FUN_00098ac0(param_1,param_2,0,0);
  return;
}

