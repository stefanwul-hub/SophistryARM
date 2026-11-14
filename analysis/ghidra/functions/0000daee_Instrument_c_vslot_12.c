/* 0000daee Instrument_c_vslot_12 */

undefined4 Instrument_c_vslot_12(int param_1,undefined4 param_2,int *param_3)

{
  char cVar1;
  
  if (*(int *)(param_1 + 4) != 0) {
    cVar1 = FUN_0001ab48(*(int *)(param_1 + 4),param_2,param_3);
    if (cVar1 != '\0') {
      *param_3 = *param_3 + *(int *)(param_1 + 0x1b60);
      return 1;
    }
  }
  return 0;
}

