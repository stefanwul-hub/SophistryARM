/* 0000dd62 Instrument_c_vslot_47 */

void Instrument_c_vslot_47(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_24;
  int local_20;
  
  *(undefined4 *)(param_1 + 0xeb8) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  uVar1 = *(undefined4 *)(param_1 + 0x148);
  *(undefined4 *)(param_1 + 300) = uVar1;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x144) = 0;
  *(undefined4 *)(FUN_00001ace + param_1 + 6) = 0;
  *(undefined4 *)(param_1 + 0x1ad8) = 0;
  *(undefined4 *)(param_1 + 0x1adc) = 0;
  *(undefined4 *)(param_1 + 0x1ae0) = 0;
  *(undefined4 *)(param_1 + 0x1ae4) = 0;
  *(undefined4 *)(param_1 + 0x1ae8) = uVar1;
  iVar3 = 0x10;
  iVar2 = param_1;
  iVar4 = param_1;
  do {
    *(undefined1 *)(iVar2 + 0x1c9) = 0;
    *(undefined4 *)(iVar4 + 0x1dc) = 0xffffffff;
    *(undefined1 *)(iVar2 + 0x1b4) = 0;
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  local_20 = param_1;
  local_24 = 0;
  iVar4 = param_1 + 0x10d4;
  iVar2 = param_1;
  do {
    *(undefined4 *)(local_20 + 0xed4) = 0xffffffff;
    (**(code **)(*(int *)(iVar2 + 0x10d4) + 0x10))(iVar4);
    local_24 = local_24 + 1;
    iVar4 = iVar4 + 0x14;
    local_20 = local_20 + 4;
    iVar2 = iVar2 + 0x14;
  } while (local_24 != 0x80);
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  return;
}

