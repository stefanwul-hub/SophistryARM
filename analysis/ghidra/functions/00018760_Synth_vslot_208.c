/* 00018760 Synth_vslot_208 */

undefined4 Synth_vslot_208(int *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  cVar1 = (**(code **)(*param_1 + 0x3e4))(param_1,*(undefined4 *)(param_3 + 0x10),param_2);
  if (cVar1 != '\0') {
    param_1 = param_1 + 0x169;
    iVar2 = Envelope_c_vslot_12(param_1,param_2,0x13);
    iVar3 = Envelope_c_vslot_12(param_1,param_2,0x14);
    iVar4 = Envelope_c_vslot_12(param_1,param_2,0x15);
    iVar5 = Envelope_c_vslot_12(param_1,param_2,0x16);
    if ((((iVar2 <= *(int *)(param_3 + 8)) && (*(int *)(param_3 + 8) <= iVar3)) &&
        (iVar4 <= *(int *)(param_3 + 0xc))) && (*(int *)(param_3 + 0xc) <= iVar5)) {
      return 1;
    }
  }
  return 0;
}

