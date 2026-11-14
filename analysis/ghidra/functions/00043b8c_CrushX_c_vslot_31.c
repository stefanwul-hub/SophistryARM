/* 00043b8c CrushX_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CrushX_c_vslot_31(int param_1,int param_2)

{
  int iVar1;
  undefined1 uVar2;
  longdouble lVar3;
  float fVar4;
  double dVar5;
  uint uVar6;
  
  iVar1 = *(int *)(param_1 + 0x124);
  if (iVar1 != 0) {
    if ((param_2 == -1) || (param_2 == 2)) {
      lVar3 = (longdouble)_pow(2.0,(double)*(float *)(iVar1 + 0xec));
      fVar4 = (float)((int)((double)lVar3 + 0.5) + -1) * 0.5;
      *(float *)(param_1 + 0x1e4) = fVar4;
      *(float *)(param_1 + 0x1e8) = 0.999 / fVar4;
    }
    fVar4 = *(float *)(iVar1 + 0x31c) * 2.2675737e-05 * *(float *)(param_1 + 0x204);
    *(float *)(param_1 + 0x210) = fVar4;
    dVar5 = (double)fVar4;
    *(double *)(param_1 + 0x218) = dVar5 * (2.0 - dVar5);
    *(float *)(param_1 + 0x214) = *(float *)(iVar1 + 0x38c) * 0.01;
    if (((*(float *)(iVar1 + 0x31c) <= 19999.0 && *(float *)(iVar1 + 0x31c) != 19999.0) ||
        (0.1 < *(float *)(iVar1 + 0x38c))) || (*(int *)(iVar1 + 0x2a8) != 1)) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
    *(undefined1 *)(param_1 + 0x1e1) = uVar2;
    *(undefined1 *)(param_1 + 0x1ec) = *(undefined1 *)(iVar1 + 0x16c);
    iVar1 = *(int *)(iVar1 + 0x1c8);
    *(int *)(param_1 + 0x24c) = iVar1;
    fVar4 = 1.0 / (float)iVar1;
    *(float *)(param_1 + 0x250) = fVar4;
    if ((0.0 <= fVar4) || (NAN(fVar4))) {
      uVar6 = ~-(uint)(fVar4 <= 1.0) & (uint)1.0 | (uint)fVar4 & -(uint)(fVar4 <= 1.0);
    }
    else {
      uVar6 = 0;
    }
    *(uint *)(param_1 + 0x250) = uVar6;
    *(float *)(param_1 + 0x254) = 1.0 - *(float *)(param_1 + 0x250);
    *(bool *)(param_1 + 0x238) = 1 < *(int *)(param_1 + 0x24c);
    iVar1 = *(int *)(param_1 + 0x124);
    *(undefined4 *)(param_1 + 0x23c) = *(undefined4 *)(iVar1 + 0x238);
    *(undefined4 *)(param_1 + 0x208) = *(undefined4 *)(iVar1 + 0x2a8);
    *(undefined1 *)(param_1 + 0x20c) = *(undefined1 *)(iVar1 + 0x40c);
    *(undefined1 *)(param_1 + 0x20d) = *(undefined1 *)(iVar1 + 0x47c);
    *(undefined4 *)(param_1 + 0x200) = *(undefined4 *)(iVar1 + 0x4dc);
  }
  return;
}

