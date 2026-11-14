/* 0000de7e FUN_0000de7e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0000de7e(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_30;
  int local_2c;
  undefined4 *local_24;
  undefined4 *local_20;
  
  FUN_0001436c(param_1);
  *param_1 = &PTR_Instrument_c_vslot_0_000e67c8;
  FUN_0002de30(param_1 + 0x387);
  FUN_0002de30(param_1 + 0x394);
  FUN_0002de30(param_1 + 0x3a1);
  puVar1 = param_1 + 0x435;
  iVar3 = 0x7f;
  puVar2 = PTR_DAT_00103814 + 8;
  do {
    *puVar1 = puVar2;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0xffffffff;
    *(undefined1 *)(puVar1 + 1) = 1;
    puVar1 = puVar1 + 5;
    iVar3 = iVar3 + -1;
  } while (iVar3 != -1);
  param_1[0x6b] = 0;
  *(undefined1 *)(param_1 + 0x3b4) = 0;
  *(undefined1 *)(param_1 + 0x56) = 0;
  param_1[0x57] = 0;
  *(undefined1 *)(param_1 + 0x6d7) = 1;
  *(undefined1 *)(param_1 + 0x3b0) = 1;
  *(undefined1 *)((int)param_1 + 0xec1) = 1;
  *(undefined1 *)((int)param_1 + 0xec2) = 1;
  *(undefined1 *)((int)param_1 + 0xec3) = 1;
  param_1[0x3b1] = 0;
  *(undefined1 *)(param_1 + 0x54) = 1;
  *(undefined1 *)((int)param_1 + 0x151) = 0;
  *(undefined1 *)(param_1 + 0x6d5) = 1;
  param_1[0x6d6] = 0xffffffff;
  param_1[0x6d8] = 0;
  if (param_2 < 1) {
    param_2 = 1;
  }
  else if (6 < param_2) {
    param_2 = 6;
  }
  param_1[0x6c] = param_2;
  param_1[0x52] = 0x3f800000;
  param_1[0x53] = 0;
  param_1[0x55] = 0;
  param_1[0x69] = 0xffffffff;
  param_1[0x3ae] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0x3f800000;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x6b5] = 0;
  param_1[0x6b6] = 0;
  param_1[0x6b7] = 0;
  param_1[0x6b8] = 0;
  param_1[0x6b9] = 0;
  param_1[0x6ba] = 0x3f800000;
  iVar3 = 0x10;
  puVar1 = param_1;
  puVar4 = param_1;
  do {
    *(undefined1 *)((int)puVar1 + 0x1c9) = 0;
    puVar4[0x77] = 0xffffffff;
    *(undefined1 *)(puVar1 + 0x6d) = 0;
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  local_20 = param_1;
  local_30 = 0;
  puVar4 = param_1 + 0x435;
  puVar1 = param_1;
  do {
    local_20[0x3b5] = 0xffffffff;
    (**(code **)(puVar1[0x435] + 0x10))(puVar4);
    local_30 = local_30 + 1;
    puVar4 = puVar4 + 5;
    local_20 = local_20 + 1;
    puVar1 = puVar1 + 5;
  } while (local_30 != 0x80);
  param_1[0x6a] = 0;
  param_1[0x3af] = 0xbf800000;
  iVar3 = 4;
  puVar1 = param_1;
  puVar4 = param_1;
  do {
    puVar1[0x58] = 0;
    puVar1[0x59] = 0;
    puVar1[0x60] = 0;
    puVar1[0x61] = 0;
    *(undefined1 *)(puVar4 + 0x68) = 0;
    puVar1 = puVar1 + 2;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  local_24 = param_1;
  local_2c = 0;
  puVar4 = param_1 + 0x435;
  puVar1 = param_1;
  do {
    local_24[0x3b5] = 0xffffffff;
    (**(code **)(puVar1[0x435] + 0x10))(puVar4);
    local_2c = local_2c + 1;
    puVar4 = puVar4 + 5;
    local_24 = local_24 + 1;
    puVar1 = puVar1 + 5;
  } while (local_2c != 0x80);
  param_1[0x6d4] = 0;
  return;
}

