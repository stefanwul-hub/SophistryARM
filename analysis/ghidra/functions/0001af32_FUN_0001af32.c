/* 0001af32 FUN_0001af32 */

void FUN_0001af32(int *param_1)

{
  if (param_1 != (int *)0x0) {
    _OSAtomicAdd32Barrier(1,param_1 + 0xecc);
    (**(code **)(*param_1 + 0x27c))(param_1);
    _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0xecc);
  }
  return;
}

