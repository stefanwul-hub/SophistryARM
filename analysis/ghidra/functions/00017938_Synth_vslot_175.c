/* 00017938 Synth_vslot_175 */

void Synth_vslot_175(int *param_1)

{
  if (*(char *)((int)param_1 + 0xcfc9) == '\0') {
    return;
  }
  (**(code **)(*param_1 + 0x1a8))(param_1);
  return;
}

