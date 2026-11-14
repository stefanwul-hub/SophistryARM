/* 0001b09e Synth_vslot_56 */

undefined4 Synth_vslot_56(int *param_1,undefined4 param_2,int param_3,char *param_4)

{
  int iVar1;
  char *pcVar2;
  
  if (((param_4 == (char *)0x0) || (param_3 < 0)) || (param_1[0x2694] <= param_3)) {
    return 0;
  }
  if (*(char *)((int)param_1 + 0xcfc9) == '\0') {
    _OSAtomicAdd32Barrier(1,param_1 + 0xecc);
    *(undefined1 *)((int)param_1 + 0xcfda) = 0;
    (**(code **)(*param_1 + 0x2e8))(param_1);
    *(undefined1 *)((int)param_1 + 0xcfda) = 1;
    _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0xecc);
    iVar1 = param_1[0xe3c];
  }
  else {
    iVar1 = param_1[0xe3c];
  }
  if (iVar1 == 0) {
    pcVar2 = (char *)FUN_0002cbbe(param_1[0x33f8] * 0x574 + param_1[0xe3e],param_3);
  }
  else {
    pcVar2 = (char *)FUN_0002cbbe(iVar1,param_3);
  }
  if (pcVar2 != (char *)0x0) {
    _strcpy(param_4,pcVar2);
    return 1;
  }
  builtin_strncpy(param_4,"unknown",8);
  return 1;
}

