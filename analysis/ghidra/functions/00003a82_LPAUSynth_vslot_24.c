/* 00003a82 LPAUSynth_vslot_24 */

undefined4 LPAUSynth_vslot_24(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0xd) != '\0') {
    return 0xffffd59f;
  }
  uVar1 = AUBase_vslot_24();
  return uVar1;
}

