/* 0008bcda FUN_0008bcda */

void FUN_0008bcda(int param_1,int param_2,int param_3)

{
  if (((*(int *)(param_1 + 0x124) != 0) && (-1 < param_2)) && (param_2 < 0x80)) {
    param_2 = param_2 * 0x4d0;
    FUN_000109c8(*(int *)(param_1 + 0x124) + 0x310 + param_2,*(undefined4 *)(param_3 + 4));
    FUN_000109c8(param_2 + *(int *)(param_1 + 0x124) + 0x380,*(undefined4 *)(param_3 + 8));
    FUN_000108b4(param_2 + *(int *)(param_1 + 0x124) + 0x3f0,*(undefined4 *)(param_3 + 0xc));
    FUN_000108b4(param_2 + *(int *)(param_1 + 0x124) + 0x460,*(undefined4 *)(param_3 + 0x10));
    FUN_000109c8(param_2 + *(int *)(param_1 + 0x124) + 0x690,*(undefined4 *)(param_3 + 0x14));
    FUN_000109c8(param_2 + *(int *)(param_1 + 0x124) + 0x700,0x7f - *(int *)(param_3 + 0x18));
    FUN_000109c8(param_2 + *(int *)(param_1 + 0x124) + 0x4d0,*(undefined4 *)(param_3 + 0x1c));
    FUN_000109c8(param_2 + *(int *)(param_1 + 0x124) + 0x540,*(undefined4 *)(param_3 + 0x20));
    FUN_000109c8(param_2 + *(int *)(param_1 + 0x124) + 0x5b0,*(undefined4 *)(param_3 + 0x24));
    FUN_000109c8();
    return;
  }
  return;
}

