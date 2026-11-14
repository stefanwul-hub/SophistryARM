/* 0000b41c FUN_0000b41c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0000b41c(int param_1,float param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  float local_20;
  undefined4 local_10;
  
  iVar1 = *(int *)(param_1 + 0x4c);
  if (iVar1 == 0) {
    return;
  }
  iVar2 = *(int *)(param_1 + 0xc);
  if (((((iVar2 == 0xd) || (iVar2 == 4)) || (iVar2 == 9)) || ((iVar2 == 10 || (iVar2 == 3)))) &&
     (iVar3 = *(int *)(param_1 + 0x34), iVar3 != 0)) {
    if (*(char *)(iVar3 + 0x6d) == '\0') {
      if (*(char *)(iVar3 + 0x6c) == '\0') goto LAB_0000b468;
      _OSAtomicAdd32Barrier(1,iVar1 + 0x3b30);
      uVar5 = 0xffffffff;
    }
    else {
      _OSAtomicAdd32Barrier(1,iVar1 + 0x3b30);
      uVar5 = 1;
    }
    FUN_0001dd36(*(undefined4 *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 8),uVar5);
LAB_0000b562:
    _OSAtomicAdd32Barrier(0xffffffff,*(int *)(param_1 + 0x4c) + 0x3b30);
    return;
  }
LAB_0000b468:
  if ((0.0 <= param_2) || (NAN(param_2))) {
    local_20 = 1.0;
    if (param_2 <= 1.0) {
      local_20 = param_2;
    }
  }
  else {
    local_20 = 0.0;
  }
  if (2 < iVar2) {
    if (iVar2 < 0xb) {
      _OSAtomicAdd32Barrier(1,iVar1 + 0x3b30);
      (**(code **)(**(int **)(param_1 + 0x4c) + 0x34))
                (*(int **)(param_1 + 0x4c),*(undefined4 *)(param_1 + 8),local_20);
      _OSAtomicAdd32Barrier(0xffffffff,*(int *)(param_1 + 0x4c) + 0x3b30);
    }
    else if (iVar2 == 0xd) {
      piVar4 = *(int **)(param_1 + 0x34);
      if ((piVar4 == (int *)0x0) || (*(char *)((int)piVar4 + 0x6e) == '\0')) {
        _OSAtomicAdd32Barrier(1,iVar1 + 0x3b30);
        (**(code **)(**(int **)(param_1 + 0x4c) + 0x34))
                  (*(int **)(param_1 + 0x4c),*(undefined4 *)(param_1 + 8),local_20);
      }
      else {
        (**(code **)(*piVar4 + 300))(piVar4,&local_10);
        _OSAtomicAdd32Barrier(1,*(int *)(param_1 + 0x4c) + 0x3b30);
        (**(code **)(**(int **)(param_1 + 0x4c) + 0x36c))
                  (*(int **)(param_1 + 0x4c),*(undefined4 *)(param_1 + 8),local_10);
      }
      goto LAB_0000b562;
    }
  }
  return;
}

