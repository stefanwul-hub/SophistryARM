/* 0001c3ea Synth_vslot_190 */

void Synth_vslot_190(int *param_1,undefined4 param_2)

{
  char *pcVar1;
  char local_28c [319];
  undefined1 local_14d;
  char local_14c [320];
  
  pcVar1 = (char *)param_1[0x26a0];
  if (pcVar1 == (char *)0x0) {
    pcVar1 = (char *)FUN_00009ba6(param_1 + 0x30f6,param_1);
    param_1[0x26a0] = (int)pcVar1;
    if (pcVar1 == (char *)0x0) {
      return;
    }
  }
  _strncpy(local_28c,pcVar1,0x13f);
  local_14d = 0;
  FUN_0000a024(param_1 + 0x30f6,local_28c,param_2);
  FUN_0000a364(param_1 + 0x30f6,local_28c,local_14c);
  if ((local_14c[0] != '\0') &&
     ((**(code **)(*param_1 + 0x2e4))(param_1,local_14c), *(char *)((int)param_1 + 0x9bd5) == '\0'))
  {
    _strcpy((char *)((int)param_1 + 0x9bd5),local_14c);
  }
  *(undefined1 *)((int)param_1 + 0xcfc9) = 1;
  return;
}

