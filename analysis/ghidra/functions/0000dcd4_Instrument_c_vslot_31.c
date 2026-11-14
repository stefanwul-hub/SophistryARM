/* 0000dcd4 Instrument_c_vslot_31 */

void Instrument_c_vslot_31(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_18;
  int local_14;
  
  if (param_2 < 1) {
    param_2 = 1;
  }
  if (*(int *)(param_1 + 0x1c4) < param_2) {
    param_2 = *(int *)(param_1 + 0x1c4);
  }
  local_14 = param_1;
  local_18 = 0;
  iVar1 = param_1 + 0x10d4;
  iVar2 = param_1;
  do {
    *(undefined4 *)(local_14 + 0xed4) = 0xffffffff;
    (**(code **)(*(int *)(iVar2 + 0x10d4) + 0x10))(iVar1);
    local_18 = local_18 + 1;
    iVar1 = iVar1 + 0x14;
    local_14 = local_14 + 4;
    iVar2 = iVar2 + 0x14;
  } while (local_18 != 0x80);
  *(int *)(param_1 + 0xecc) = param_2;
  *(bool *)(param_1 + 0xed0) = param_2 == 1;
  return;
}

