/* 0000db3a Instrument_c_vslot_19 */

void Instrument_c_vslot_19(int param_1,char param_2)

{
  char cVar1;
  
  if ((*(char *)(param_1 + 0x1b5c) != '\0') && (param_2 == '\0')) {
    cVar1 = FUN_0002ddaa(param_1 + 0xe1c);
    *(undefined4 *)(param_1 + 0xeb8) = 0;
    if (cVar1 != '\0') {
      FUN_0002ddc8(param_1 + 0xe1c);
    }
    if (*(int *)(param_1 + 4) == 0) {
      return;
    }
    FUN_000241f2(*(int *)(param_1 + 4),*(undefined4 *)(param_1 + 0x1a4));
  }
  *(char *)(param_1 + 0x1b5c) = param_2;
  return;
}

