/* 00025f38 SynthEditor_c_vslot_35 */

void SynthEditor_c_vslot_35(int *param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  int *piVar4;
  
  if (*(char *)((int)param_1 + 0x51) != '\0') {
    piVar4 = param_1;
    do {
      piVar1 = (int *)piVar4[0x9771];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x140))(piVar1);
        pcVar2 = *(code **)(*param_1 + 0x80);
        uVar3 = (**(code **)(*(int *)piVar4[0x9771] + 0xdc))((int *)piVar4[0x9771]);
        (*pcVar2)(param_1,uVar3,0);
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != param_1 + 3);
  }
  return;
}

