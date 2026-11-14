/* 00025e74 FUN_00025e74 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00025e74(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  undefined4 local_20;
  
  if ((*(char *)(param_1 + 0x51) != '\0') && (-1 < *(int *)(param_1 + 0x25dd8))) {
    lVar4 = (longdouble)
            (**(code **)(**(int **)(param_1 + 0x4c) + 0x2b4))
                      (*(int **)(param_1 + 0x4c),*(int *)(param_1 + 0x25dd8));
    if (0 < *(int *)(param_1 + 0x25854)) {
      local_20 = 0;
      iVar2 = param_1;
      iVar3 = param_1;
      do {
        piVar1 = *(int **)(iVar3 + 0x88);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x100))(piVar1,(float)lVar4 < 0.5);
        }
        piVar1 = *(int **)(iVar2 + 0x20854);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x100))(piVar1,(float)lVar4 < 0.5);
        }
        local_20 = local_20 + 1;
        iVar3 = iVar3 + 0x68;
        iVar2 = iVar2 + 0xc;
      } while (local_20 < *(int *)(param_1 + 0x25854));
    }
  }
  return;
}

