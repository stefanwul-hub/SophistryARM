/* 0001a176 FUN_0001a176 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble FUN_0001a176(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  longdouble lVar4;
  
  if (0 < *(int *)(param_1 + 0xcfb0)) {
    fVar2 = 0.0;
    iVar3 = 0;
    do {
      if (iVar3 != param_2) {
        piVar1 = *(int **)(*(int *)(param_1 + 0xcea4) + iVar3 * 4);
        lVar4 = (longdouble)(**(code **)(*piVar1 + 0x78))(piVar1,iVar3 < param_2,param_3);
        fVar2 = (float)lVar4;
      }
    } while ((ABS(fVar2) <= 0.001) && (iVar3 = iVar3 + 1, iVar3 < *(int *)(param_1 + 0xcfb0)));
    return (longdouble)fVar2;
  }
  return (longdouble)0.0;
}

