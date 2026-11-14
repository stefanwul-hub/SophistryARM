/* 0009e178 CFrame_vslot_61 */

undefined1 CFrame_vslot_61(int *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  
  if ((char)param_1[0x26] != '\0') {
    cVar1 = (**(code **)(*param_1 + 0x150))(param_1);
    if (cVar1 == '\0') {
      if (param_1[0x27] == 0) {
        iVar4 = param_1[0x19];
      }
      else {
        if (param_2 != (undefined4 *)0x0) {
          *(short *)(param_1[0x27] + 0x80) = (short)*param_2;
          *(short *)(param_1[0x27] + 0x82) = (short)param_2[1];
        }
        piVar3 = (int *)(**(code **)(*(int *)param_1[0x18] + 8))((int *)param_1[0x18]);
        iVar4 = (**(code **)(*piVar3 + 0x240))(piVar3,param_1[0x27]);
        param_1[0x19] = iVar4;
      }
      if (iVar4 != 0) {
        cVar1 = FUN_0009dff8(param_1,iVar4);
        if (cVar1 != '\0') {
          (**(code **)(*param_1 + 0x14c))(param_1,1);
        }
      }
      uVar2 = (**(code **)(*param_1 + 0x150))(param_1);
      return uVar2;
    }
  }
  return 0;
}

