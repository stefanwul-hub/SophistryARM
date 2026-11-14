/* 0001cc86 Synth_vslot_13 */

void Synth_vslot_13(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *local_18;
  int local_14;
  int local_10;
  
  if ((((-1 < param_2) && (param_2 < param_1[0x2692])) && (param_1[0x22af] != 0)) &&
     ((char)param_1[0xec4] == '\0')) {
    iVar1 = *(int *)(param_1[0x22af] + 0xc + param_2 * 0x20);
    if (iVar1 == -1) {
      iVar1 = param_1[0x33f8];
    }
    if ((((char)param_1[0x256] != '\0') && (param_2 != param_1[0xed2])) &&
       (param_2 != param_1[0xed3])) {
      FUN_0008d4a0(param_1 + 0x1e1,iVar1,param_2);
    }
    local_14 = -1;
    FUN_0001cb52(param_1,param_2,&local_18,&local_14,&local_10);
    if (((param_1 + 0x169 == local_18) && ((local_14 == 5 || (local_14 == 4)))) ||
       (param_1[0x2691] < param_2)) {
      (**(code **)(*param_1 + 0x2b0))(param_1,param_2 + param_1[0xecf] * local_10,param_3);
    }
    else {
      FUN_00095256(param_1,param_2 + param_1[0xecf] * local_10,param_3);
    }
    if ((((param_1 + 0xf3 != local_18) && (local_18 != param_1 + 0x2d)) &&
        (iVar1 = *(int *)(param_2 * 0x20 + 0xc + param_1[0x22af]), -1 < iVar1)) &&
       (iVar1 != param_1[0x33f8])) {
      (**(code **)(*param_1 + 0x318))(param_1,iVar1);
    }
    (**(code **)(*param_1 + 0x308))(param_1,param_2);
  }
  return;
}

