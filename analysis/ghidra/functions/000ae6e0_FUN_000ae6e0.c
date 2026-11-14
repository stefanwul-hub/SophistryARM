/* 000ae6e0 FUN_000ae6e0 */

undefined4 FUN_000ae6e0(double *param_1,double *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_1c;
  
  if ((*param_1 == 0.0) || (*param_2 == 0.0)) {
    iVar1 = *(int *)(param_1 + 1);
  }
  else {
    if (*param_1 != *param_2) {
      return 0;
    }
    if (NAN(*param_1) || NAN(*param_2)) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 1);
  }
  if (((iVar1 == 0) || (*(int *)(param_2 + 1) == 0)) || (iVar1 == *(int *)(param_2 + 1))) {
    uVar5 = *(uint *)((int)param_1 + 0xc);
    local_1c = *(uint *)((int)param_2 + 0xc);
    if (((iVar1 != 0) && (*(int *)(param_2 + 1) != 0)) && ((uVar5 != 0 && (local_1c != 0)))) {
      if (iVar1 == 0x6c70636d) {
        uVar3 = uVar5 & 0x7fffffff;
        uVar4 = uVar3 & local_1c & 0x7fffffff;
        uVar2 = local_1c & 0x7fffffff;
        if ((uVar4 & 8) != 0) {
          uVar3 = uVar5 & 0x7fffffef;
          uVar4 = local_1c & 0x7fffffef & uVar3;
          uVar2 = local_1c & 0x7fffffef;
        }
        local_1c = uVar2;
        if ((uVar4 & 1) != 0) {
          uVar3 = uVar3 & 0xfffffffb;
          local_1c = local_1c & 0xfffffffb;
        }
        uVar5 = uVar3;
        if ((*(uint *)(param_1 + 4) < 9) && ((uVar3 & 8) != 0)) {
          uVar5 = uVar3 & 0xfffffffd;
        }
        uVar2 = local_1c;
        if ((*(uint *)(param_2 + 4) < 9) && (uVar2 = local_1c & 0xfffffffd, (local_1c & 8) == 0)) {
          uVar2 = local_1c;
        }
        local_1c = uVar2;
        if ((*(uint *)((int)param_1 + 0x1c) < 2) && (*(uint *)((int)param_2 + 0x1c) < 2)) {
          uVar5 = uVar5 & 0xffffffdf;
          local_1c = local_1c & 0xffffffdf;
        }
      }
      if (uVar5 != local_1c) {
        return 0;
      }
    }
    if (((((((*(int *)(param_1 + 2) == 0) || (*(int *)(param_2 + 2) == 0)) ||
           (*(int *)(param_1 + 2) == *(int *)(param_2 + 2))) &&
          (((*(int *)((int)param_1 + 0x14) == 0 || (*(int *)((int)param_2 + 0x14) == 0)) ||
           (*(int *)((int)param_1 + 0x14) == *(int *)((int)param_2 + 0x14))))) &&
         (((*(int *)(param_1 + 3) == 0 || (*(int *)(param_2 + 3) == 0)) ||
          (*(int *)(param_1 + 3) == *(int *)(param_2 + 3))))) &&
        (((*(int *)((int)param_1 + 0x1c) == 0 || (*(int *)((int)param_2 + 0x1c) == 0)) ||
         (*(int *)((int)param_1 + 0x1c) == *(int *)((int)param_2 + 0x1c))))) &&
       (((*(int *)(param_1 + 4) == 0 || (*(int *)(param_2 + 4) == 0)) ||
        (*(int *)(param_1 + 4) == *(int *)(param_2 + 4))))) {
      return 1;
    }
  }
  return 0;
}

