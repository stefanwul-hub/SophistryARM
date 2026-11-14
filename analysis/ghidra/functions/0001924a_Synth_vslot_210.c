/* 0001924a Synth_vslot_210 */

void Synth_vslot_210(int *param_1,int param_2,int param_3,int param_4,undefined1 param_5)

{
  int iVar1;
  int iVar2;
  
  if (0 < param_1[0x2692]) {
    iVar2 = 0;
    do {
      iVar1 = iVar2 * 0x20 + param_1[0x22af];
      if (((*(int *)(iVar1 + 0x18) == param_3) && (*(int *)(iVar1 + 0x14) == param_2)) &&
         ((*(int *)(iVar1 + 0xc) == param_4 ||
          ((*(int *)(iVar1 + 0xc) == -1 && (param_4 == param_1[0x33f8])))))) {
        (**(code **)(*param_1 + 0x34c))(param_1,iVar2,param_5);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[0x2692]);
  }
  return;
}

