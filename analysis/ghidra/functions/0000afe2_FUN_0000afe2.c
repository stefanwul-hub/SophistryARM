/* 0000afe2 FUN_0000afe2 */

void FUN_0000afe2(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 local_15c;
  undefined2 local_158;
  
  if (*(int *)(param_1 + 0x4c) != 0) {
    if ((*(int *)(param_1 + 8) == -1) || (*(int *)(param_1 + 0xc) == 0xb)) {
      local_15c = 0x202d202d;
      local_158 = 0x2d;
      param_2 = 0;
      if (0xd < *(uint *)(param_1 + 0xc)) {
        return;
      }
    }
    else {
      _OSAtomicAdd32Barrier(1,*(int *)(param_1 + 0x4c) + 0x3b30);
      FUN_0001d532(*(undefined4 *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 8),&local_15c,0x13f);
      _OSAtomicAdd32Barrier(0xffffffff,*(int *)(param_1 + 0x4c) + 0x3b30);
      if (0xd < *(uint *)(param_1 + 0xc)) {
        return;
      }
    }
    if ((1 << ((byte)*(undefined4 *)(param_1 + 0xc) & 0x1f) & 0x36f8U) != 0) {
      piVar1 = *(int **)(param_1 + 0x3c);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x130))(piVar1,&local_15c);
        (**(code **)(**(int **)(param_1 + 0x3c) + 0x54))(*(int **)(param_1 + 0x3c),1);
      }
      piVar1 = *(int **)(param_1 + 0x34);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0xb0))(piVar1,param_2);
        (**(code **)(**(int **)(param_1 + 0x34) + 0x130))(*(int **)(param_1 + 0x34),&local_15c);
        (**(code **)(**(int **)(param_1 + 0x34) + 0x54))(*(int **)(param_1 + 0x34),1);
      }
    }
  }
  return;
}

