/* 000062ca CSubMenuPl_vslot_45 */

longdouble CSubMenuPl_vslot_45(int *param_1)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  
  iVar1 = param_1[0x4e];
  if (0 < iVar1) {
    iVar2 = (**(code **)(*param_1 + 0x138))(param_1,0,1);
    lVar3 = (longdouble)FUN_000152c0((float)(iVar2 + param_1[0x39]),(float)iVar1);
    return lVar3;
  }
  return (longdouble)0;
}

