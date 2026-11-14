/* 0008c078 FUN_0008c078 */

bool FUN_0008c078(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6)

{
  if ((param_2 < 0x80) && (*(int *)(param_1 + 0x124) != 0)) {
    param_2 = param_2 * 0x4d0;
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x124) + 0x548 + param_2);
    *param_4 = *(undefined4 *)(param_2 + 0x318 + *(int *)(param_1 + 0x124));
    *param_5 = *(undefined4 *)(param_2 + 0x4d8 + *(int *)(param_1 + 0x124));
    *param_6 = *(undefined4 *)(param_2 + 0x388 + *(int *)(param_1 + 0x124));
    return *(int *)(param_2 + 0x628 + *(int *)(param_1 + 0x124)) != 0;
  }
  return false;
}

