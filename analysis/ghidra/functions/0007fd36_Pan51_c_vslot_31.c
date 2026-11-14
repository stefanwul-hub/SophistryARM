/* 0007fd36 Pan51_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Pan51_c_vslot_31(int param_1)

{
  int iVar1;
  longdouble lVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  float fVar7;
  
  iVar1 = *(int *)(param_1 + 0x124);
  if (iVar1 == 0) {
    return;
  }
  fVar5 = *(float *)(iVar1 + 0x248);
  dVar6 = (double)*(float *)(iVar1 + 0x7c) * 0.5 + 0.5;
  lVar2 = (longdouble)_pow(1.0 - dVar6,0,0x3fe00000);
  fVar3 = fVar5 * (float)((double)lVar2 * 1.4);
  lVar2 = (longdouble)_pow(dVar6,0,0x3fe00000);
  fVar4 = fVar5 * (float)((double)lVar2 * 1.4);
  dVar6 = (double)*(float *)(iVar1 + 0xec) * 0.5 + 0.5;
  lVar2 = (longdouble)_pow(1.0 - dVar6,0,0x3fe00000);
  fVar7 = (float)((double)lVar2 * 1.4) * fVar5;
  lVar2 = (longdouble)_pow(dVar6,0,0x3fe00000);
  fVar5 = (float)((double)lVar2 * 1.4) * fVar5;
  *(float *)(param_1 + 0x1e4) = fVar3 * fVar7;
  *(float *)(param_1 + 0x1e8) = fVar7 * fVar4;
  *(float *)(param_1 + 0x1ec) = fVar3 * fVar5;
  *(float *)(param_1 + 0x1f0) = fVar5 * fVar4;
  if (*(float *)(param_1 + 0x1e4) <= 1e-05 && *(float *)(param_1 + 0x1e4) != 1e-05) {
    *(undefined4 *)(param_1 + 0x1e4) = 0;
    if (*(float *)(param_1 + 0x1e8) <= 1e-05 && *(float *)(param_1 + 0x1e8) != 1e-05)
    goto LAB_0007ff7c;
LAB_0007ff11:
    if (1e-05 < *(float *)(param_1 + 0x1ec) || *(float *)(param_1 + 0x1ec) == 1e-05)
    goto LAB_0007ff1a;
LAB_0007ff67:
    *(undefined4 *)(param_1 + 0x1ec) = 0;
    if (1e-05 < *(float *)(param_1 + 0x1f0) || *(float *)(param_1 + 0x1f0) == 1e-05)
    goto LAB_0007ff23;
  }
  else {
    if (1e-05 < *(float *)(param_1 + 0x1e8) || *(float *)(param_1 + 0x1e8) == 1e-05)
    goto LAB_0007ff11;
LAB_0007ff7c:
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    if (*(float *)(param_1 + 0x1ec) <= 1e-05 && *(float *)(param_1 + 0x1ec) != 1e-05)
    goto LAB_0007ff67;
LAB_0007ff1a:
    if (1e-05 < *(float *)(param_1 + 0x1f0) || *(float *)(param_1 + 0x1f0) == 1e-05)
    goto LAB_0007ff23;
  }
  *(undefined4 *)(param_1 + 0x1f0) = 0;
LAB_0007ff23:
  *(undefined4 *)(param_1 + 500) = *(undefined4 *)(iVar1 + 0x168);
  *(undefined4 *)(param_1 + 0x1f8) = *(undefined4 *)(iVar1 + 0x1d8);
  *(float *)(param_1 + 0x20c) = *(float *)(param_1 + 0x144) * 440.0;
  return;
}

