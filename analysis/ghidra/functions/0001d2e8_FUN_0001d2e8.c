/* 0001d2e8 FUN_0001d2e8 */

longdouble FUN_0001d2e8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  int local_28;
  int *local_24;
  int local_20 [4];
  
  iVar1 = *(int *)(param_1 + 0x3b3c);
  iVar2 = param_2 % iVar1;
  local_24 = (int *)0x0;
  local_28 = -1;
  FUN_0001cb52(param_1,iVar2,&local_24,&local_28,local_20);
  if ((local_28 != -1) && (local_24 != (int *)0x0)) {
    iVar1 = param_2 / iVar1;
    if (*(int *)(iVar2 * 0x20 + 0xc + *(int *)(param_1 + 0x8abc)) != -1) {
      iVar1 = local_20[0];
    }
    local_20[0] = iVar1;
    lVar3 = (longdouble)(**(code **)(*local_24 + 0x2c))(local_24,iVar1,local_28);
    return lVar3;
  }
  return (longdouble)0;
}

