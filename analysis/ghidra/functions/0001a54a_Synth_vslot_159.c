/* 0001a54a Synth_vslot_159 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_159(int *param_1)

{
  char cVar1;
  uint uVar2;
  undefined1 local_4c [4];
  undefined1 local_48;
  undefined1 local_47;
  undefined2 local_46;
  undefined2 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined *local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  cVar1 = FUN_0002ddde(param_1 + 0x267c);
  if (cVar1 == '\0') {
    return;
  }
  uVar2 = FUN_0002e1c0(param_1 + 0xe28);
  if (((uint)(param_1[0xedf] + param_1[0xedc]) < uVar2) && (param_1[0xede] != param_1[0xee0])) {
    (**(code **)(*param_1 + 0x308))(param_1,param_1[0xee0]);
  }
  FUN_0002b8e2(local_4c);
  while( true ) {
    cVar1 = FUN_0002ba86(param_1 + 0xe2e,local_4c);
    if (cVar1 == '\0') break;
    local_34 = PTR_DAT_00103820 + 8;
    local_30 = local_48;
    local_2f = local_47;
    local_2e = local_46;
    local_2c = local_44;
    local_28 = local_40;
    local_24 = local_3c;
    local_20 = local_38;
    (**(code **)(*param_1 + 0x3d0))(param_1,&local_34);
    HoldData_c_vslot_0(&local_34);
  }
  param_1[0x349c] = uVar2;
  FUN_0002de1a(param_1 + 0x267c);
  HoldData_c_vslot_0(local_4c);
  return;
}

