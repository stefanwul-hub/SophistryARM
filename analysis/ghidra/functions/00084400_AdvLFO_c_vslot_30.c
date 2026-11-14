/* 00084400 AdvLFO_c_vslot_30 */

void AdvLFO_c_vslot_30(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  Envelope_c_vslot_30(param_1,param_2,param_3);
  if ((param_3 == -1) || (param_3 == 4)) {
    iVar3 = FUN_00012888(param_1,param_2);
    if (iVar3 == 0) {
      return;
    }
    if (*(char *)(iVar3 + 0x1dc) == '\0') {
      FUN_000109c8(iVar3 + 0x230,*(undefined4 *)(iVar3 + 0x254));
      FUN_000109c8(iVar3 + 0x1c0,1);
    }
  }
  piVar1 = param_1 + 0x7f;
  (**(code **)(*param_1 + 0x60))(param_1,param_2,param_3,2,piVar1,2);
  (**(code **)(*param_1 + 0x60))(param_1,param_2,param_3,3,piVar1,3);
  (**(code **)(*param_1 + 0x60))(param_1,param_2,param_3,4,piVar1,4);
  (**(code **)(*param_1 + 0x60))(param_1,param_2,param_3,5,piVar1,5);
  piVar2 = param_1 + 0x268;
  (**(code **)(*param_1 + 0x60))(param_1,param_2,param_3,6,piVar2,1);
  (**(code **)(*param_1 + 0x60))(param_1,param_2,param_3,7,piVar2,2);
  (**(code **)(*param_1 + 0x60))(param_1,param_2,param_3,8,piVar2,3);
  (**(code **)(*param_1 + 0x60))(param_1,param_2,param_3,10,piVar1,10);
  return;
}

