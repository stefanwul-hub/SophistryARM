/* 0000bc5c FUN_0000bc5c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0000bc5c(int param_1,float param_2)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = (int)((double)param_2 * 1.4);
  *(int *)(param_1 + 0x1c) = iVar1;
  *(double *)(param_1 + 0xc) = 1.0 / (double)iVar1;
  lVar2 = (longdouble)_pow(0x47ae147b,0x3f847ae1,1.0 / ((double)param_2 * 1.6));
  *(double *)(param_1 + 0x14) = (double)lVar2;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

