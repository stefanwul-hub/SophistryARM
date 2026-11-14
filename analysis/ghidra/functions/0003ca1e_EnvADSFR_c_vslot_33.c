/* 0003ca1e EnvADSFR_c_vslot_33 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void EnvADSFR_c_vslot_33(int *param_1,undefined4 param_2,int param_3,char param_4,byte param_5)

{
  float fVar1;
  bool bVar2;
  float fVar3;
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  bVar2 = (*(byte *)((int)param_1 + 0x15d) & param_5) != 0;
  local_2c = PTR_DAT_00103808 + 8;
  local_28 = *(undefined1 *)(param_3 + 4);
  local_24 = *(undefined4 *)(param_3 + 8);
  local_20 = *(undefined4 *)(param_3 + 0xc);
  Envelope_c_vslot_33(param_1,param_2,&local_2c,param_4,bVar2);
  local_2c = PTR_DAT_00103808 + 8;
  if ((param_1[0x49] != 0) && ((char)param_1[0x7e] != '\0')) {
    param_1[0x7a] = 0x3f800000;
    param_1[0x7b] = 0x3f800000;
    (**(code **)(*param_1 + 0xac))(param_1,param_1 + 0x7a,*(float *)(param_1[0x49] + 0x2ac) * -0.01)
    ;
    (**(code **)(*param_1 + 0xb0))(param_1,param_1 + 0x7b,*(float *)(param_1[0x49] + 0x31c) * 0.01);
    fVar1 = (float)param_1[0x7b];
    if ((1e-07 <= fVar1) || (NAN(fVar1))) {
      fVar3 = 1e+06;
      if (fVar1 <= 1e+06) {
        fVar3 = fVar1;
      }
    }
    else {
      fVar3 = 1e-07;
    }
    param_1[0x7b] = (int)fVar3;
    if (param_4 == '\0') {
      *(undefined4 *)param_1[0x75] = 0;
    }
    if (!bVar2) {
      *(undefined1 *)(param_1 + 0x78) = 0;
      FUN_0003c484(param_1,0);
      return;
    }
  }
  return;
}

