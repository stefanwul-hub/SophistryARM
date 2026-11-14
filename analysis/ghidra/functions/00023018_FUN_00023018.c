/* 00023018 FUN_00023018 */

void FUN_00023018(int param_1,byte *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  short sVar4;
  byte bVar5;
  undefined1 local_2c [4];
  undefined1 local_28;
  undefined1 local_27;
  short local_26;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_14;
  uint local_10;
  
  bVar5 = *param_2 & 0xf;
  local_10 = (uint)param_2[1];
  local_14 = (uint)param_2[2];
  cVar3 = FUN_00089edc(param_1 + 0xcea8,bVar5,&local_10,&local_14);
  if (cVar3 == '\0') {
    if (*(char *)(param_1 + 0x958) != '\0') {
      FUN_0008d3a2(param_1 + 0x784,bVar5,local_10,local_14);
    }
    FUN_00021f2e(param_1,bVar5,local_10,param_2[2]);
    return;
  }
  if ((local_10 == 0x400) && (0x3f < (int)local_14)) {
    if (*(int *)(param_1 + 0x38f0) == 0) {
      sVar4 = Envelope_c_vslot_12(param_1 + 0x5a4,*(undefined4 *)(param_1 + 0xcfe0),1);
    }
    else {
      sVar4 = Envelope_c_vslot_12(param_1 + 0x3cc,0,0x1a);
    }
    uVar1 = *(undefined4 *)(param_1 + 0xcfe0);
    FUN_0002b8e2(local_2c);
    local_28 = 0x4d;
    local_27 = (undefined1)uVar1;
    local_26 = sVar4 + -1;
    local_20 = 0;
    local_1c = 0;
    FUN_0002ba10(param_1 + 0x38b8,local_2c);
    HoldData_c_vslot_0(local_2c);
  }
  if ((local_10 == 0x401) && (0x3f < (int)local_14)) {
    if (*(int *)(param_1 + 0x38f0) == 0) {
      sVar4 = Envelope_c_vslot_12(param_1 + 0x5a4,*(undefined4 *)(param_1 + 0xcfe0),1);
    }
    else {
      sVar4 = Envelope_c_vslot_12(param_1 + 0x3cc,0,0x1a);
    }
    uVar1 = *(undefined4 *)(param_1 + 0xcfe0);
    FUN_0002b8e2(local_2c);
    local_28 = 0x4d;
    local_27 = (undefined1)uVar1;
    local_26 = sVar4 + 1;
    local_20 = 0;
    local_1c = 0;
    FUN_0002ba10(param_1 + 0x38b8,local_2c);
    HoldData_c_vslot_0(local_2c);
  }
  if ((local_10 == 0x402) && (0x3f < (int)local_14)) {
    uVar1 = *(undefined4 *)(param_1 + 0xb0);
    uVar2 = *(undefined4 *)(param_1 + 0xcfe0);
    FUN_0002b8e2(local_2c);
    local_28 = 0x4e;
    local_27 = (undefined1)uVar2;
    local_20 = 0;
    local_1c = 0;
    local_26 = (short)uVar1 + -1;
    FUN_0002ba10(param_1 + 0x38b8,local_2c);
    HoldData_c_vslot_0(local_2c);
  }
  if ((local_10 == 0x403) && (0x3f < (int)local_14)) {
    uVar1 = *(undefined4 *)(param_1 + 0xb0);
    uVar2 = *(undefined4 *)(param_1 + 0xcfe0);
    FUN_0002b8e2(local_2c);
    local_28 = 0x4e;
    local_27 = (undefined1)uVar2;
    local_20 = 0;
    local_1c = 0;
    local_26 = (short)uVar1 + 1;
    FUN_0002ba10(param_1 + 0x38b8,local_2c);
    HoldData_c_vslot_0(local_2c);
    return;
  }
  return;
}

