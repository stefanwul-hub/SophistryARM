/* 00091d52 FUN_00091d52 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00091d52(int param_1,float param_2,float param_3,float param_4,float param_5)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  double dVar4;
  double dVar5;
  
  lVar1 = (longdouble)_pow(0,0x40240000,(double)param_3 * 0.025);
  *(double *)(param_1 + 700) = (double)lVar1;
  if (1.0 < (double)(param_2 * param_5)) {
    dVar4 = 6.283185307179586;
  }
  else {
    dVar4 = (double)(param_2 * param_5) * 6.283185307179586;
  }
  *(double *)(param_1 + 0x2c4) = dVar4;
  lVar2 = (longdouble)_sin(dVar4);
  *(double *)(param_1 + 0x2d4) = (double)lVar2;
  lVar3 = (longdouble)_cos(dVar4);
  *(double *)(param_1 + 0x2cc) = (double)lVar3;
  dVar5 = (double)lVar2 / ((double)param_4 + (double)param_4);
  *(double *)(param_1 + 0x2dc) = dVar5;
  dVar5 = dVar5 * *(double *)(param_1 + 700);
  *(double *)(param_1 + 0x29c) = dVar5 + 1.0;
  dVar4 = *(double *)(param_1 + 0x2cc) * -2.0;
  *(double *)(param_1 + 0x2a4) = dVar4;
  *(double *)(param_1 + 0x28c) = dVar4;
  *(double *)(param_1 + 0x2ac) = 1.0 - dVar5;
  dVar5 = (1.0 / (double)lVar1) * *(double *)(param_1 + 0x2dc);
  dVar4 = dVar5 + 1.0;
  *(double *)(param_1 + 0x284) = dVar4;
  *(double *)(param_1 + 0x2b4) = 1.0 / dVar4;
  *(double *)(param_1 + 0x294) = 1.0 - dVar5;
  return;
}

