/* 00006740 CMenuWithSub_vslot_94 */

void CMenuWithSub_vslot_94
               (int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  longdouble lVar2;
  
  CMenuSimple_vslot_94(param_1,param_2,param_3,param_4,param_5);
  *(int *)(param_1 + 0x194 + param_3 * 4) = param_2;
  if (param_2 != param_1) {
    return;
  }
  iVar1 = *(int *)(param_2 + 0xda8);
  lVar2 = (longdouble)
          FUN_000152c0((float)param_3,(float)(*(int *)(param_2 + 0xf8) - *(int *)(param_2 + 0xf4)));
  *(float *)(param_2 + 0x594 + iVar1 * 4) = (float)lVar2;
  iVar1 = *(int *)(param_2 + 0xda8);
  *(int *)(param_2 + 0x994 + param_3 * 4) = iVar1;
  *(int *)(param_2 + 0xda8) = iVar1 + 1;
  return;
}

