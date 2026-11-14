/* 0001a208 Synth_vslot_54 */

undefined1 Synth_vslot_54(int param_1,int param_2)

{
  undefined1 uVar1;
  
  if (*(int *)(param_1 + 0x9a44) <= param_2 % *(int *)(param_1 + 0x3b3c)) {
    return 0;
  }
  uVar1 = FUN_000965a2(param_1,param_2);
  return uVar1;
}

