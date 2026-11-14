/* 0004b81e FUN_0004b81e */

void FUN_0004b81e(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_14;
  undefined4 local_10;
  
  param_1 = param_1 + 0x32aa04;
  iVar1 = Envelope_c_vslot_12(param_1,param_2,0x6c);
  iVar2 = Envelope_c_vslot_12(param_1,param_2,0x6e);
  local_14 = Envelope_c_vslot_12(param_1,param_2,0x70);
  local_10 = Envelope_c_vslot_12(param_1,param_2,0x72);
  if (param_3 != 0) {
    iVar3 = -1;
    while (((iVar1 == iVar2 || (iVar1 == local_14)) || (iVar1 == local_10))) {
      iVar3 = iVar3 + 1;
      iVar1 = iVar3;
    }
  }
  if (param_3 != 1) {
    iVar3 = -1;
    while (((iVar1 == iVar2 || (iVar2 == local_14)) || (iVar2 == local_10))) {
      iVar3 = iVar3 + 1;
      iVar2 = iVar3;
    }
  }
  if (param_3 != 2) {
    iVar3 = -1;
    while (((iVar1 == local_14 || (iVar2 == local_14)) || (local_14 == local_10))) {
      iVar3 = iVar3 + 1;
      local_14 = iVar3;
    }
  }
  if (param_3 != 3) {
    iVar3 = -1;
    while (((iVar1 == local_10 || (iVar2 == local_10)) || (local_14 == local_10))) {
      iVar3 = iVar3 + 1;
      local_10 = iVar3;
    }
  }
  Envelope_c_vslot_9(param_1,param_2,0x6c,iVar1);
  Envelope_c_vslot_9(param_1,param_2,0x6e,iVar2);
  Envelope_c_vslot_9(param_1,param_2,0x70,local_14);
  Envelope_c_vslot_9(param_1,param_2,0x72,local_10);
  return;
}

