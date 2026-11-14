/* 00006480 CMenuSimple_vslot_96 */

void CMenuSimple_vslot_96(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[0x3a] != 0) {
    FUN_0001ce0e(param_1[0x3a],param_1[0x10],param_1 + 0x3c);
    if (((param_1[0x40] != 0) && (0 < param_1[0x41])) && (param_1[0x41] < 0x140)) {
      (**(code **)(*param_1 + 0x14c))(param_1);
      iVar1 = FUN_0001d28c(param_1[0x3a],param_1[0x10]);
      iVar3 = param_1[0x3d];
      iVar2 = (param_1[0x3e] - iVar3) + 1;
      if (0 < iVar2) {
        iVar3 = 0;
        do {
          (**(code **)(*param_1 + 0x17c))(param_1,param_1,iVar3,iVar3);
          iVar3 = iVar3 + 1;
        } while (iVar2 != iVar3);
        iVar3 = param_1[0x3d];
      }
      (**(code **)(*param_1 + 0x13c))(param_1,iVar1 - iVar3,1);
      (**(code **)(*param_1 + 0x15c))(param_1,iVar1 - param_1[0x3d]);
      return;
    }
  }
  return;
}

