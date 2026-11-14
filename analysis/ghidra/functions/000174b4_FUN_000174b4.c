/* 000174b4 FUN_000174b4 */

void FUN_000174b4(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                 int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(LPAUSynth_vslot_10 + param_1);
  if (0 < iVar1) {
    iVar3 = 0;
    iVar2 = param_1;
    do {
      if ((((param_3 == *(int *)(CMenuBase_vslot_1 + iVar2)) &&
           (param_4 == *(int *)(iVar2 + 0x62a0))) && (param_6 == *(int *)(iVar2 + 0x62a8))) &&
         (param_7 == *(int *)(iVar2 + 0x62ac))) {
        return;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar1 != iVar3);
  }
  if (0xdf < iVar1) {
    return;
  }
  *(undefined4 *)(param_1 + 0x6298 + iVar1 * 0x18) = param_2;
  *(int *)(CMenuBase_vslot_1 + *(int *)(LPAUSynth_vslot_10 + param_1) * 0x18 + param_1) = param_3;
  *(int *)(param_1 + 0x62a0 + *(int *)(LPAUSynth_vslot_10 + param_1) * 0x18) = param_4;
  *(undefined4 *)(param_1 + 0x62a4 + *(int *)(LPAUSynth_vslot_10 + param_1) * 0x18) = param_5;
  *(int *)(param_1 + 0x62a8 + *(int *)(LPAUSynth_vslot_10 + param_1) * 0x18) = param_6;
  *(int *)(param_1 + 0x62ac + *(int *)(LPAUSynth_vslot_10 + param_1) * 0x18) = param_7;
  *(int *)(LPAUSynth_vslot_10 + param_1) = *(int *)(LPAUSynth_vslot_10 + param_1) + 1;
  return;
}

