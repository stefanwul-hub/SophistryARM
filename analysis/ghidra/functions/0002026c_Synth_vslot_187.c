/* 0002026c Synth_vslot_187 */

void Synth_vslot_187(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char *pcVar1;
  undefined4 uVar2;
  char local_14c [319];
  undefined1 local_d;
  
  pcVar1 = (char *)param_1[0x26a0];
  if (pcVar1 == (char *)0x0) {
    pcVar1 = (char *)FUN_00009ba6(param_1 + 0x30f6,param_1);
    param_1[0x26a0] = (int)pcVar1;
    if (pcVar1 == (char *)0x0) {
      return;
    }
  }
  _strncpy(local_14c,pcVar1,0x13f);
  local_d = 0;
  FUN_0000a024(param_1 + 0x30f6,local_14c,param_2);
  if (param_1[0xe3c] != 0) {
    (**(code **)(*param_1 + 0x2f0))(param_1,local_14c,param_3);
    *(undefined1 *)((int)param_1 + 0xcfc9) = 1;
    return;
  }
  uVar2 = Envelope_c_vslot_12(param_1 + 0x169,param_1[0x33f8],1);
  (**(code **)(*param_1 + 0x2f4))(param_1,local_14c,param_3);
  *(undefined1 *)((int)param_1 + 0xcfc9) = 1;
  (**(code **)(*param_1 + 0x29c))(param_1,uVar2);
  return;
}

