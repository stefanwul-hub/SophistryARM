/* 000178f8 Synth_vslot_95 */

undefined4 Synth_vslot_95(int param_1,char *param_2)

{
  if (param_2 != (char *)0x0) {
    _strcpy(param_2,*(char **)(param_1 + 0x3bac));
    return 1;
  }
  return 0;
}

