/* 000a6c2c LPAUSynth_vslot_4 */

void LPAUSynth_vslot_4(int *param_1)

{
  if (*(char *)((int)param_1 + 0xd) != '\0') {
    (**(code **)(*param_1 + 0x18))(param_1);
  }
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  return;
}

