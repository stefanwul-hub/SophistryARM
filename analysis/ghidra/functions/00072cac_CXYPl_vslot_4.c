/* 00072cac CXYPl_vslot_4 */

void CXYPl_vslot_4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  undefined4 local_14;
  undefined4 local_10;
  
  if (param_2 != 0) {
    CControlPl_vslot_4(param_1,param_2);
    if (*(int *)(param_1 + 0xb0) != 0) {
      local_10 = *(undefined4 *)(param_1 + 0xc);
      local_14 = *(undefined4 *)(param_1 + 8);
      (**(code **)(**(int **)(param_1 + 0xb0) + 0x10))
                (*(int **)(param_1 + 0xb0),param_2,param_1 + 8,&local_14);
      FUN_0009c9f4(param_2,1);
      FUN_0009c9de(param_2,0);
      iVar2 = *(int *)(param_1 + 8);
      lVar3 = (longdouble)FUN_00001ace(param_1,0);
      iVar2 = iVar2 + (int)((float)lVar3 * *(float *)(param_1 + 0xb8));
      iVar1 = *(int *)(param_1 + 0x14);
      lVar3 = (longdouble)FUN_00001ace(param_1,1);
      iVar1 = (iVar1 - (int)((float)lVar3 * *(float *)(param_1 + 0xb4))) + -1;
      FUN_000729d2(param_1,param_2,iVar2,iVar1,1);
      FUN_000729d2(param_1,param_2,iVar2,iVar1,0);
    }
  }
  return;
}

