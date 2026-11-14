/* 00006572 CMenuSimple_vslot_45 */

longdouble CMenuSimple_vslot_45(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  
  iVar1 = param_1[0x3e];
  iVar2 = param_1[0x3d];
  if (iVar1 <= iVar2) {
    return (longdouble)0;
  }
  iVar3 = (**(code **)(*param_1 + 0x138))(param_1,0,1);
  lVar4 = (longdouble)FUN_000152c0((float)iVar3,(float)(iVar1 - iVar2));
  return lVar4;
}

