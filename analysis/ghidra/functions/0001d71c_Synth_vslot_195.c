/* 0001d71c Synth_vslot_195 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_195(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char local_52d;
  char local_528 [320];
  undefined1 local_3e8 [320];
  undefined1 local_2a8 [320];
  char local_168 [320];
  int local_28;
  undefined4 local_24;
  int *local_20 [4];
  
  if (param_1[0xedb] != 0) {
    return;
  }
  local_2a8[0] = 0;
  local_528[0] = '\0';
  local_3e8[0] = 0;
  (**(code **)(*param_1 + 0x50))(param_1,param_2,local_3e8);
  FUN_0001cb52(param_1,param_2,local_20,&local_28,&local_24);
  if (param_1[0x22af] != 0) {
    iVar2 = 0;
    if (-1 < param_2) {
      iVar2 = param_2;
    }
    iVar1 = param_1[0x2692] + -1;
    if (iVar2 <= param_1[0x2692] + -1) {
      iVar1 = iVar2;
    }
    local_52d = *(char *)(iVar1 * 0x20 + 8 + param_1[0x22af]);
  }
  if (local_20[0] == (int *)0x0) {
    return;
  }
  if (local_28 < 0) {
    return;
  }
  if (local_52d == '\0') {
    return;
  }
  iVar2 = FUN_0002e1c0(param_1 + 0xe28);
  param_1[0xedf] = iVar2;
  param_1[0xede] = param_2;
  (**(code **)(*local_20[0] + 0x50))(local_20[0],local_24,local_28,local_528,0x17);
  if (param_2 != param_1[0xee0]) {
    (**(code **)(*local_20[0] + 0x4c))(local_20[0],local_24,local_28,local_2a8);
    if (param_1[0xedd] == 2) {
      _sprintf(local_168,"%s %s",local_528,local_2a8);
      goto LAB_0001d88b;
    }
    if (param_1[0xedd] == 3) {
      _sprintf(local_168,"%s %s %s",local_3e8,local_528,local_2a8);
      goto LAB_0001d88b;
    }
  }
  _strcpy(local_168,local_528);
LAB_0001d88b:
  Envelope_c_vslot_17(param_1 + 0x169,local_24,0x10,local_168);
  (**(code **)(*param_1 + 0x34c))(param_1,param_1[0xeda],0 < param_1[0xecc]);
  return;
}

