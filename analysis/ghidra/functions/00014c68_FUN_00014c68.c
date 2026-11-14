/* 00014c68 FUN_00014c68 */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

longdouble FUN_00014c68(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  
  iVar2 = *(int *)(param_1 + 0x1d4);
  if (iVar2 != 0) {
    iVar3 = (int)param_2;
    if (iVar3 < 0) {
      iVar3 = 0;
      fVar4 = 0.0;
    }
    else if (iVar3 < 0x80) {
      fVar4 = (float)iVar3;
    }
    else {
      iVar3 = 0x7f;
      fVar4 = 127.0;
    }
    fVar1 = *(float *)(iVar2 + iVar3 * 4);
    return (longdouble)((param_2 - fVar4) * (*(float *)(iVar2 + 4 + iVar3 * 4) - fVar1) + fVar1);
  }
  return (longdouble)0.0;
}

