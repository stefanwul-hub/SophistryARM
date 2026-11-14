/* 000144fa Instrument_c_vslot_2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Instrument_c_vslot_2(int param_1,float param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  
  if (0.0 < param_2) {
    *(float *)(param_1 + 0xc) = param_2;
    lVar4 = (longdouble)FUN_000152c0(0x3f800000,param_2);
    *(float *)(param_1 + 0x10) = (float)lVar4;
    if (0 < *(int *)(param_1 + 0x114)) {
      iVar3 = 0;
      iVar2 = param_1;
      do {
        piVar1 = *(int **)(iVar2 + 0x14);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0xa0))(piVar1,param_2);
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar3 < *(int *)(param_1 + 0x114));
      return;
    }
  }
  return;
}

