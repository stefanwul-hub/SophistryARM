/* 0000fe38 Envelope_c_vslot_37 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Envelope_c_vslot_37(int param_1)

{
  float *pfVar1;
  longdouble lVar2;
  
  if (*(char *)(param_1 + 0x1f8) != '\0') {
    *(undefined4 *)(param_1 + 0x1f0) = 99;
    *(undefined4 *)(param_1 + 500) = 0;
    **(int **)(param_1 + 0x1dc) = (int)(*(float *)(param_1 + 0x140) * 0.005 + 0.5);
    pfVar1 = *(float **)(param_1 + 0x1d8);
    lVar2 = (longdouble)
            FUN_000152c0(**(uint **)(param_1 + 0x1d4) ^ 0x80000000,
                         (float)**(int **)(param_1 + 0x1dc));
    *pfVar1 = (float)lVar2;
  }
  return;
}

