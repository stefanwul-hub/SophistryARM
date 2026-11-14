/* 0001655a Synth_vslot_153 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_153(int *param_1)

{
  int iVar1;
  int *piVar2;
  int local_160;
  char local_15c [332];
  
  iVar1 = Envelope_c_vslot_12(param_1 + 0xf3,0,0xb);
  param_1[0x33ed] = iVar1;
  iVar1 = Envelope_c_vslot_12(param_1 + 0xf3,0,0xc);
  param_1[0x33ee] = iVar1;
  (**(code **)(*param_1 + 0x3e0))(param_1,param_1[0xeeb],param_1[0x33ed],iVar1);
  if (0 < param_1[0x33ec]) {
    local_160 = 0;
    iVar1 = (int)param_1 + 0x9bd5;
    piVar2 = param_1;
    do {
      _sprintf(local_15c,"%sLoadPresetPath%ld",param_1 + 0x13e4,local_160);
      if (*(char *)((int)piVar2 + 0x9bd5) != '\0') {
        FUN_0002e63a(param_1 + 0xe28,local_15c,iVar1);
      }
      local_160 = local_160 + 1;
      iVar1 = iVar1 + 0x140;
      piVar2 = piVar2 + 0x50;
    } while (local_160 < param_1[0x33ec]);
  }
  return;
}

