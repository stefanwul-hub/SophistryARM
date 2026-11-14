/* 0001421a FUN_0001421a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble FUN_0001421a(undefined4 param_1,int param_2,double param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  double dVar5;
  undefined8 local_24;
  undefined4 local_14;
  
  if (0.0 <= param_3) {
    if (param_3 <= 0.0) {
      dVar5 = 0.499999999999;
    }
    else {
      dVar5 = -0.499999999999;
    }
    local_14 = SUB84(dVar5 + param_3 + 6755399441055744.0,0);
    param_3 = param_3 - (double)local_14;
    if (local_14 < 1) {
      iVar3 = param_2 + local_14 * 4;
      fVar4 = 0.0;
      local_24 = 0.0;
    }
    else {
      iVar3 = param_2 + local_14 * 4;
      fVar4 = *(float *)(iVar3 + -4);
      local_24 = (double)fVar4;
    }
    fVar1 = *(float *)(param_2 + local_14 * 4);
    fVar2 = *(float *)(iVar3 + 4);
    dVar5 = (double)fVar1;
    return (longdouble)
           (float)(dVar5 + ((double)(fVar2 - fVar4) * 0.5 +
                           ((double)fVar2 + (double)fVar2 + local_24 +
                            (dVar5 * 5.0 + (double)*(float *)(iVar3 + 8)) * -0.5 +
                           (((double)(fVar1 - fVar2) * 3.0 - local_24) +
                           (double)*(float *)(iVar3 + 8)) * 0.5 * param_3) * param_3) * param_3);
  }
  return (longdouble)0.0;
}

