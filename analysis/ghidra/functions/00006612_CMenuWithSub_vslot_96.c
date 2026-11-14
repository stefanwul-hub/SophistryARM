/* 00006612 CMenuWithSub_vslot_96 */

void CMenuWithSub_vslot_96(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_10;
  
  if ((((param_1[0x3a] != 0) &&
       (FUN_0001ce0e(param_1[0x3a],param_1[0x10],param_1 + 0x3c), param_1[0x40] != 0)) &&
      (0 < param_1[0x41])) && (param_1[0x41] < 0x140)) {
    (**(code **)(*param_1 + 0x14c))(param_1);
    iVar2 = FUN_0001d28c(param_1[0x3a],param_1[0x10]);
    iVar3 = param_1[0x3d];
    iVar1 = (param_1[0x3e] - iVar3) + 1;
    local_10 = 0;
    if (0 < iVar1) {
      do {
        (**(code **)(*param_1 + 0x19c))(param_1,&local_10,iVar1);
      } while (local_10 < iVar1);
      iVar3 = param_1[0x3d];
    }
    (**(code **)(*param_1 + 0x13c))(param_1,iVar2 - iVar3,1);
    (**(code **)(*param_1 + 0x15c))(param_1,iVar2 - param_1[0x3d]);
    return;
  }
  return;
}

