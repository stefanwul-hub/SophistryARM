/* 00036822 FUN_00036822 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00036822(int param_1,float param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  
  iVar1 = *(int *)(param_1 + 0x23c);
  if (iVar1 != 0) {
    iVar2 = param_1 + 0x260;
    iVar3 = param_1;
    do {
      *(double *)(param_1 + 0x268) = (double)*(int *)(iVar1 + 0x26c) + (double)param_2 * 10000.0;
      dVar4 = 0.0;
      if (0.0 <= *(double *)(iVar2 + 8)) {
        dVar4 = *(double *)(iVar2 + 8);
      }
      *(double *)(iVar2 + 8) = dVar4;
      *(double *)(param_1 + 0x2a8) = *(double *)(param_1 + 0x268) - *(double *)(param_1 + 0x2e8);
      iVar2 = iVar2 + 8;
      iVar1 = *(int *)(iVar3 + 0x240);
      param_1 = param_1 + 8;
      iVar3 = iVar3 + 4;
    } while (iVar1 != 0);
  }
  return;
}

