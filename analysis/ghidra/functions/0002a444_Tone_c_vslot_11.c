/* 0002a444 Tone_c_vslot_11 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Tone_c_vslot_11(int *param_1,int param_2,int param_3,undefined1 param_4,undefined1 param_5)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  float fVar4;
  float fVar5;
  undefined *local_2c;
  undefined1 local_28;
  int local_24;
  int local_20;
  
  if (param_1[1] == 0) {
    return;
  }
  param_1[0x50] = param_2;
  iVar1 = FUN_00017d68(param_1[1],param_2);
  param_1[0x51] = iVar1;
  *(undefined1 *)(param_1 + 0x53) = *(undefined1 *)(param_3 + 4);
  param_1[0x54] = *(int *)(param_3 + 8);
  param_1[0x55] = *(int *)(param_3 + 0xc);
  param_1[0x56] = *(int *)(param_3 + 0x10);
  iVar1 = FUN_00012888(param_1[0x30e],param_2);
  param_1[0x58] = iVar1;
  param_1[0x57] = 0;
  fVar5 = (float)*(int *)(param_3 + 8) * 0.007874016;
  fVar5 = (fVar5 + fVar5) - 1.0;
  param_1[0x48] = (int)fVar5;
  fVar5 = fVar5 * ABS(fVar5) + fVar5 * ABS(fVar5);
  param_1[0x47] = (int)fVar5;
  if ((-1.0 <= fVar5) || (NAN(fVar5))) {
    fVar5 = (float)(~-(uint)(fVar5 <= 1.0) & (uint)1.0 | (uint)fVar5 & -(uint)(fVar5 <= 1.0));
  }
  else {
    fVar5 = -1.0;
  }
  param_1[0x47] = (int)fVar5;
  fVar5 = (float)*(int *)(param_3 + 0xc) * 0.007874016;
  lVar2 = (longdouble)_expf((float)(*(int *)(param_3 + 0xc) + -0x7f) * 0.05);
  lVar3 = (longdouble)Envelope_c_vslot_8(param_1[1] + 0x3cc,0,8);
  fVar4 = (1.0 - (float)lVar3) * fVar5 + (float)lVar3 * (float)lVar2;
  param_1[0x49] = (int)((fVar4 + fVar4) - 1.0);
  param_1[0x4a] = (int)((fVar5 + fVar5) - 1.0);
  (**(code **)(*param_1 + 0x3c))(param_1,*(undefined4 *)(param_1[0x51] + 0x118));
  (**(code **)(*param_1 + 0x38))(param_1,0);
  param_1[0x4e] = param_1[0x4d];
  param_1[0x30d] = *(int *)(param_1[0x51] + 0xebc);
  local_20 = *(int *)(param_3 + 0xc);
  local_24 = *(int *)(param_3 + 8);
  if (local_24 < 0) {
    local_24 = 0;
  }
  else if (0x7f < local_24) {
    local_24 = 0x7f;
  }
  if (local_20 < 0) {
    local_20 = 0;
  }
  else if (0x7f < local_20) {
    local_20 = 0x7f;
  }
  local_2c = PTR_DAT_00103808 + 8;
  local_28 = 0;
  Instrument_c_vslot_7(param_1,param_2,&local_2c,param_4,param_5);
  local_2c = PTR_DAT_00103808 + 8;
  param_1[0x59] = 0;
  iVar1 = Envelope_c_vslot_12(param_1[1] + 0x5a4,param_2,0xc);
  param_1[0x5b] = (int)((float)iVar1 * 0.02083333);
  iVar1 = Envelope_c_vslot_12(param_1[1] + 0x5a4,param_2,0x19);
  fVar5 = (float)iVar1 * 0.02083333;
  param_1[0x5c] = (int)fVar5;
  if ((-1e-07 <= fVar5) || (NAN(fVar5))) {
    fVar5 = (float)param_1[0x5b];
  }
  else {
    fVar5 = (float)param_1[0x5b];
    param_1[0x5c] = (int)fVar5;
  }
  lVar2 = (longdouble)FUN_00014cf2(param_1[1] + 0x36c0);
  param_1[0x5b] = (int)(fVar5 * (float)lVar2);
  fVar5 = (float)param_1[0x5c];
  lVar2 = (longdouble)FUN_00014cf2(param_1[1] + 0x36c0);
  param_1[0x5c] = (int)(fVar5 * (float)lVar2);
  return;
}

