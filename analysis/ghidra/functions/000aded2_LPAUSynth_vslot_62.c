/* 000aded2 LPAUSynth_vslot_62 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int LPAUSynth_vslot_62(int *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,
                      undefined4 param_5,int param_6)

{
  int iVar1;
  float fVar2;
  uint local_10 [2];
  
  if (param_6 == 0) {
    iVar1 = -0x32;
  }
  else if (*(char *)((int)param_1 + 0xd) == '\0') {
    iVar1 = -0x2a73;
  }
  else if (*(float *)(param_6 + 8) == 0.0) {
    fVar2 = *(float *)(param_6 + 4);
    if (fVar2 <= 0.0) {
      fVar2 = 0.0;
    }
    local_10[0] = (int)(fVar2 - (float)(-(uint)(2.1474836e+09 <= fVar2) & 0x4f000000)) +
                  (uint)(2.1474836e+09 <= fVar2) * -0x80000000 | -(uint)(4.2949673e+09 <= fVar2);
    iVar1 = (**(code **)(*param_1 + 0xe8))(param_1,param_3,local_10[0],param_5);
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0xe4))(param_1,param_2,param_3,local_10,param_5,param_6);
    if ((iVar1 == 0) && (param_4 != (uint *)0x0)) {
      *param_4 = local_10[0];
    }
  }
  return iVar1;
}

