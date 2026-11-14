/* 0001b1b4 Synth_vslot_20 */

void Synth_vslot_20(int *param_1,int param_2,char *param_3)

{
  if (param_3 != (char *)0x0) {
    if ((char)param_1[0x33f1] == '\0') {
      (**(code **)(*param_1 + 0xc))(param_1);
    }
    if ((char)param_1[0x33f1] == '\0') {
      builtin_strncpy(param_3,"uninitialized",0xe);
      return;
    }
    if (param_1[0x22af] != 0) {
      _OSAtomicAdd32Barrier(1,param_1 + 0xecc);
      param_2 = param_2 % param_1[0xecf];
      if (param_2 < param_1[0x2691]) {
        _strcpy(param_3,*(char **)(param_2 * 0x20 + 4 + param_1[0x22af]));
      }
      else if (param_2 < param_1[0x2692]) {
        builtin_strncpy(param_3,"hidden",7);
      }
      else {
        builtin_strncpy(param_3,"reserved",9);
      }
      _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0xecc);
    }
  }
  return;
}

