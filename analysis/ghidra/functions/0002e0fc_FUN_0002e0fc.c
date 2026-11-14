/* 0002e0fc FUN_0002e0fc */

undefined4 FUN_0002e0fc(int param_1,uint param_2,undefined4 *param_3)

{
  if ((-1 < (int)param_2) && (param_2 < *(uint *)(param_1 + 8) >> 2)) {
    if (*(int *)(param_1 + 4) != 0) {
      *param_3 = *(undefined4 *)(*(int *)(param_1 + 4) + param_2 * 4);
      return 1;
    }
    *param_3 = 0;
    return 0;
  }
  return 0;
}

