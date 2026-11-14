/* 000414e8 Chorus1_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Chorus1_c_vslot_31(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  
  iVar1 = *(int *)(param_1 + 0x124);
  if ((iVar1 != 0) && (*(char *)(param_1 + 0x15c) != '\0')) {
    if ((param_2 == -1) || ((param_2 == 5 || (param_2 == 4)))) {
      fVar3 = *(float *)(iVar1 + 0x23c);
      fVar2 = *(float *)(iVar1 + 0x1cc) * 100.0;
      Envelope_c_vslot_9(param_1 + 0x1e0,*(undefined4 *)(param_1 + 0x128),3,(int)fVar2);
      Envelope_c_vslot_9(param_1 + 0x1e0,*(undefined4 *)(param_1 + 0x128),5,0xfffffff3);
      Envelope_c_vslot_9(param_1 + 0x984,*(undefined4 *)(param_1 + 0x128),3,
                         (int)((1.0 - fVar3) * fVar2));
      Envelope_c_vslot_9(param_1 + 0x984,*(undefined4 *)(param_1 + 0x128),5,0xfffffff3);
      Envelope_c_vslot_9(param_1 + 0x1128,*(undefined4 *)(param_1 + 0x128),3,
                         (int)(fVar2 * (fVar3 + 1.0)));
      Envelope_c_vslot_9(param_1 + 0x1128,*(undefined4 *)(param_1 + 0x128),5,0xfffffff3);
      iVar1 = *(int *)(param_1 + 0x124);
    }
    if (param_2 == 7) {
      *(undefined8 *)(param_1 + 0x20c4) = *(undefined8 *)(param_1 + 0x20ac);
      *(undefined8 *)(param_1 + 0x20bc) = *(undefined8 *)(param_1 + 0x20ac);
    }
    fVar2 = *(float *)(param_1 + 0x140) * 0.001 * *(float *)(iVar1 + 0xec);
    *(float *)(param_1 + 0x2094) = fVar2;
    fVar3 = 1.0;
    *(float *)(param_1 + 0x2098) = (*(float *)(iVar1 + 0x15c) * 1.23 + 1.0) * fVar2;
    *(float *)(param_1 + 0x209c) = fVar2 * (*(float *)(iVar1 + 0x15c) * -1.44 + 1.0);
    if (*(char *)(iVar1 + 0x39c) != '\0') {
      fVar3 = -1.0;
    }
    fVar2 = *(float *)(iVar1 + 0x46c);
    fVar3 = fVar3 * *(float *)(iVar1 + 0x2ac);
    *(float *)(param_1 + 0x20a0) = (fVar2 * 0.5 + 0.5) * fVar3;
    *(float *)(param_1 + 0x20a4) = (fVar2 * -0.5 + 0.5) * fVar3;
    *(undefined4 *)(param_1 + 0x20a8) = *(undefined4 *)(iVar1 + 0x3fc);
    fVar3 = ABS(fVar3) * -0.43 + 1.0 + ABS(fVar3) * fVar2 * -0.19;
    *(float *)(param_1 + 0x20a0) = fVar3 * *(float *)(param_1 + 0x20a0);
    *(float *)(param_1 + 0x20a4) = fVar3 * *(float *)(param_1 + 0x20a4);
    *(float *)(param_1 + 0x20a8) = fVar3 * *(float *)(param_1 + 0x20a8);
  }
  return;
}

