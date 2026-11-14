/* 0000cbee Instrument_c_vslot_11 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Instrument_c_vslot_11(int param_1,int param_2)

{
  int iVar1;
  double dVar2;
  
  iVar1 = 4;
  do {
    dVar2 = (double)param_2 * *(double *)(param_1 + 0x180) + *(double *)(param_1 + 0x160);
    *(double *)(param_1 + 0x160) = dVar2;
    if (1.0 < dVar2) {
      do {
        dVar2 = dVar2 - 1.0;
      } while (1.0 < dVar2);
      *(double *)(param_1 + 0x160) = dVar2;
    }
    param_1 = param_1 + 8;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

