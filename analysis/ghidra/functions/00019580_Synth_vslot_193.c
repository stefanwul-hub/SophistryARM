/* 00019580 Synth_vslot_193 */

void Synth_vslot_193(int *param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
                    char *param_5,undefined4 param_6)

{
  char cVar1;
  undefined1 local_14c [324];
  
  if (*param_5 != '\0') {
    cVar1 = FUN_0000abd0(param_1 + 0x30f6,param_4,param_5,local_14c,param_6);
    if (cVar1 != '\0') {
      (**(code **)(*param_1 + 0x36c))(param_1,param_3,local_14c);
      return;
    }
  }
  return;
}

