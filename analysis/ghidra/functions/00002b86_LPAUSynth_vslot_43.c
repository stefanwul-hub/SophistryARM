/* 00002b86 LPAUSynth_vslot_43 */

undefined4 LPAUSynth_vslot_43(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  
  cVar1 = FUN_000a66e8(param_1,param_4);
  if ((cVar1 != '\0') && (*(int *)(param_4 + 0x1c) == 2)) {
    return 1;
  }
  return 0;
}

