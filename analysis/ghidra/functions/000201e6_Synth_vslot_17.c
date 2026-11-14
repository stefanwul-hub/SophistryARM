/* 000201e6 Synth_vslot_17 */

void Synth_vslot_17(int *param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if ((char)param_1[0x33f1] != '\0') {
    pcVar1 = *(code **)(*param_1 + 0xe0);
    if (param_1[0xe3c] == 0) {
      uVar2 = Envelope_c_vslot_12(param_1 + 0x169,param_1[0x33f8],1);
    }
    else {
      uVar2 = Envelope_c_vslot_12(param_1 + 0xf3,0,0x1a);
    }
    (*pcVar1)(param_1,0,uVar2,param_2);
  }
  return;
}

