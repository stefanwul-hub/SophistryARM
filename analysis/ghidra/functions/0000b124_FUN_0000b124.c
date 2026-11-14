/* 0000b124 FUN_0000b124 */

void FUN_0000b124(int param_1,int param_2)

{
  int *piVar1;
  longdouble lVar2;
  undefined1 local_14c [320];
  
  if (*(int *)(param_1 + 0xc) != 0xb) {
    FUN_0001ce0e(*(undefined4 *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 8),param_1 + 0x10);
    (**(code **)(**(int **)(param_1 + 0x4c) + 0x50))
              (*(int **)(param_1 + 0x4c),*(undefined4 *)(param_1 + 8),local_14c);
    piVar1 = *(int **)(param_1 + 0x40);
    if (piVar1 != (int *)0x0) {
      if (param_2 == 0) {
        (**(code **)(*piVar1 + 0x130))(piVar1,local_14c);
        lVar2 = (longdouble)
                (**(code **)(**(int **)(param_1 + 0x4c) + 0x2b4))
                          (*(int **)(param_1 + 0x4c),*(undefined4 *)(param_1 + 8));
        FUN_0000afe2(param_1,(float)lVar2);
        return;
      }
      (**(code **)(*piVar1 + 0x130))(piVar1,param_2);
    }
    lVar2 = (longdouble)
            (**(code **)(**(int **)(param_1 + 0x4c) + 0x2b4))
                      (*(int **)(param_1 + 0x4c),*(undefined4 *)(param_1 + 8));
    FUN_0000afe2(param_1,(float)lVar2);
  }
  return;
}

