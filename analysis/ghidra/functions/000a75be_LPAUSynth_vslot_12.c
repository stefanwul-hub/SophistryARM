/* 000a75be LPAUSynth_vslot_12 */

undefined4 LPAUSynth_vslot_12(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = param_2;
  local_14 = param_3;
  local_10 = param_4;
  puVar1 = *(undefined4 **)(param_1 + 0xc0);
  if (*(undefined4 **)(param_1 + 0xbc) == puVar1) {
    FUN_000c5dd0(param_1 + 0xbc,0x20);
    puVar1 = *(undefined4 **)(param_1 + 0xc0);
  }
  if (puVar1 == *(undefined4 **)(param_1 + 0xc4)) {
    FUN_000c5bba(param_1 + 0xbc,puVar1,&local_18);
  }
  else {
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = local_18;
      puVar1[1] = local_14;
      puVar1[2] = local_10;
      puVar1 = *(undefined4 **)(param_1 + 0xc0);
    }
    *(undefined4 **)(param_1 + 0xc0) = puVar1 + 3;
  }
  return 0;
}

