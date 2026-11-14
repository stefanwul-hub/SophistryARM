/* 00019420 Synth_vslot_184 */

undefined4 Synth_vslot_184(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  *(undefined1 *)((int)param_1 + 0xcfdb) = 1;
  *(undefined1 *)((int)param_1 + 0xcfda) = 0;
  piVar1 = param_1 + 0xf3;
  uVar2 = Envelope_c_vslot_12(piVar1,0,3);
  uVar3 = Envelope_c_vslot_12(piVar1,0,0x1a);
  uVar4 = Envelope_c_vslot_12(piVar1,0,0x1b);
  (**(code **)(*param_1 + 0x278))(param_1);
  Envelope_c_vslot_9(piVar1,0,0x1a,uVar3);
  Envelope_c_vslot_9(piVar1,0,0x1b,uVar4);
  uVar3 = (**(code **)(*param_1 + 0x2dc))(param_1,0,param_2);
  Envelope_c_vslot_9(piVar1,0,3,uVar2);
  (**(code **)(*param_1 + 0x364))(param_1,0,piVar1,3);
  *(undefined1 *)((int)param_1 + 0xcfdb) = 0;
  *(undefined1 *)((int)param_1 + 0xcfda) = 1;
  (**(code **)(*param_1 + 0x318))(param_1,0);
  return uVar3;
}

