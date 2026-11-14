/* 0001a0d8 FUN_0001a0d8 */

undefined4 FUN_0001a0d8(int *param_1,int param_2)

{
  if ((param_1[1] != 0) && (param_2 < *param_1)) {
    return *(undefined4 *)(param_1[1] + param_2 * 4);
  }
  return 0;
}

