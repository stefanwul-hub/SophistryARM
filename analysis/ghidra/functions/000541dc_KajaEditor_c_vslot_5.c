/* 000541dc KajaEditor_c_vslot_5 */

void KajaEditor_c_vslot_5(int param_1)

{
  if (*(char *)(param_1 + 0x51) == '\0') {
    return;
  }
  *(undefined1 *)(param_1 + 0x51) = 0;
  FUN_00028c80(param_1,0x58);
  SynthEditor_c_vslot_23();
  return;
}

