/* 0008b5e4 FUN_0008b5e4 */

undefined1 FUN_0008b5e4(int param_1)

{
  char cVar1;
  undefined4 local_14;
  void *local_10 [2];
  
  if (*(int *)(param_1 + 0x318) != 0) {
    local_10[0] = (void *)0x0;
    cVar1 = FUN_0002e8c2(param_1 + 0x168,param_1 + 0x1d5,local_10,&local_14);
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(param_1 + 0x120) + 0x10))
                (*(int **)(param_1 + 0x120),local_10[0],local_14,0);
      *(undefined1 *)(param_1 + 0x315) = 1;
    }
    if (local_10[0] != (void *)0x0) {
      _free(local_10[0]);
    }
    local_10[0] = (void *)0x0;
    FUN_00012222(*(undefined4 *)(param_1 + 0x120),0,1,0);
    FUN_00012222(*(undefined4 *)(param_1 + 0x120),0,2,0);
    return *(undefined1 *)(param_1 + 0x315);
  }
  return 0;
}

