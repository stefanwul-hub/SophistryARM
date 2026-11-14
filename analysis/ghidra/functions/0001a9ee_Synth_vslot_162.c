/* 0001a9ee Synth_vslot_162 */

void Synth_vslot_162(int param_1,undefined1 param_2,int param_3,char param_4)

{
  int iVar1;
  int local_34;
  undefined1 local_2d;
  undefined1 local_24 [4];
  char local_20;
  undefined1 local_1f;
  char local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  
  iVar1 = *(int *)(param_3 + 8);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (0x7f < iVar1) {
    iVar1 = 0x7f;
  }
  *(int *)(param_3 + 8) = iVar1;
  iVar1 = *(int *)(param_3 + 0xc);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (0x7f < iVar1) {
    iVar1 = 0x7f;
  }
  *(int *)(param_3 + 0xc) = iVar1;
  iVar1 = *(int *)(param_3 + 0x10);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else if (0xf < iVar1) {
    iVar1 = 0xf;
  }
  *(int *)(param_3 + 0x10) = iVar1;
  local_34 = *(int *)(param_3 + 0xc);
  iVar1 = Envelope_c_vslot_12(param_1 + 0xb4,0,4);
  if (iVar1 == 0) {
    if (local_34 == 0) {
      local_2d = 0;
    }
    else {
      local_34 = 0x7f;
      local_2d = 0x7f;
    }
  }
  else {
    local_2d = (undefined1)local_34;
  }
  iVar1 = 0;
  if (*(int *)(param_3 + 0x10) != 0x10) {
    iVar1 = *(int *)(param_3 + 0x10);
  }
  FUN_0002b8e2(local_24);
  local_20 = (-(param_4 == '\0') & 7U) + 0x51;
  local_1f = param_2;
  local_10 = (-(local_34 == 0) & 0xf0U) + 0x90 + (char)iVar1;
  local_f = (undefined1)*(undefined4 *)(param_3 + 8);
  local_e = local_2d;
  local_d = 0;
  FUN_0002ba10(param_1 + 0x38a4,local_24);
  HoldData_c_vslot_0(local_24);
  return;
}

