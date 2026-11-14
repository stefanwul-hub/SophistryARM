/* 000b631a Reverb2R_c_vslot_39 */

void Reverb2R_c_vslot_39(int param_1,int param_2)

{
  char cVar1;
  
  if ((*(char *)(param_2 + 0x1b4 + param_1) != '\0') && (param_2 == *(int *)(param_1 + 0x128))) {
    cVar1 = FUN_000b60a8(param_1);
    if (cVar1 != '\0') {
      FUN_000b6206();
      return;
    }
  }
  return;
}

