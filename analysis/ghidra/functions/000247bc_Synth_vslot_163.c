/* 000247bc Synth_vslot_163 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_163(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined *local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  piVar5 = param_1 + 0x169;
  uVar1 = Envelope_c_vslot_12(piVar5,param_2,0x13);
  uVar2 = Envelope_c_vslot_12(piVar5,param_2,0x14);
  uVar3 = Envelope_c_vslot_12(piVar5,param_2,0x15);
  uVar4 = Envelope_c_vslot_12(piVar5,param_2,0x16);
  local_2c = *(undefined1 *)(param_3 + 4);
  local_28 = *(undefined4 *)(param_3 + 8);
  local_24 = *(undefined4 *)(param_3 + 0xc);
  local_30 = PTR_DAT_00103814 + 8;
  local_20 = *(undefined4 *)(param_3 + 0x10);
  (**(code **)(*param_1 + 0x290))(param_1,param_2,&local_30,uVar1,uVar2,uVar3,uVar4);
  return;
}

