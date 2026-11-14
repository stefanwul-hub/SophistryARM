/* 00019602 Synth_vslot_189 */

void Synth_vslot_189(int *param_1,undefined4 param_2)

{
  char *pcVar1;
  int local_154;
  int local_150;
  undefined1 local_14c [320];
  
  (**(code **)(*param_1 + 0x29c))(param_1,0);
  FUN_00009996(param_1 + 0x30f6,param_2,local_14c);
  if (0 < param_1[0x33ec]) {
    local_154 = 0;
    local_150 = 0;
    do {
      FUN_0002d328(local_150 + param_1[0xe3d],local_14c,1);
      FUN_0002d328(local_150 + param_1[0xe3e],param_2,0);
      if (0 < *(int *)(local_150 + param_1[0xe3e] + 0x528)) {
        pcVar1 = (char *)FUN_0002ca94(local_150 + param_1[0xe3e],0);
        if (pcVar1 != (char *)0x0) {
          (**(code **)(*param_1 + 0x2dc))(param_1,local_154,pcVar1);
          if (*(char *)((int)param_1 + 0x9bd5) == '\0') {
            _strcpy((char *)((int)param_1 + 0x9bd5),pcVar1);
          }
        }
      }
      local_154 = local_154 + 1;
      local_150 = local_150 + 0x574;
    } while (local_154 < param_1[0x33ec]);
  }
  return;
}

