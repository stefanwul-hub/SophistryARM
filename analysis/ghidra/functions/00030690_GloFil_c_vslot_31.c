/* 00030690 GloFil_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void GloFil_c_vslot_31(int param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  
  if (*(char *)(param_1 + 0x15c) != '\0') {
    fVar3 = 1.0 - *(float *)(*(int *)(param_1 + 0x124) + 0x1cc);
    fVar3 = 1.0 - fVar3 * fVar3;
    *(float *)(param_1 + 0x9f8) = fVar3;
    if ((1e-06 <= fVar3) || (NAN(fVar3))) {
      fVar3 = (float)(~-(uint)(fVar3 <= 0.999999) & (uint)0.999999 |
                     (uint)fVar3 & -(uint)(fVar3 <= 0.999999));
    }
    else {
      fVar3 = 1e-06;
    }
    *(float *)(param_1 + 0x9f8) = fVar3;
    iVar2 = *(int *)(param_1 + 0x124);
    *(undefined4 *)(param_1 + 0x9fc) = *(undefined4 *)(iVar2 + 0x23c);
    *(undefined4 *)(param_1 + 0xa00) = *(undefined4 *)(iVar2 + 0x38c);
    *(double *)(param_1 + 0x9a8) =
         (double)*(float *)(iVar2 + 0x2ac) * (2.0 - (double)*(float *)(iVar2 + 0x2ac));
    fVar3 = *(float *)(iVar2 + 0x408);
    fVar1 = *(float *)(iVar2 + 0xec);
    *(float *)(param_1 + 0x9f0) = fVar3 * fVar1;
    *(float *)(param_1 + 0x9f4) = fVar3 * (1.0 - fVar1);
  }
  return;
}

