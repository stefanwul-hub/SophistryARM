/* 00008370 CPlusMinusDisplay_vslot_29 */

void CPlusMinusDisplay_vslot_29(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_2 - *(int *)(param_1 + 8);
  iVar1 = param_2[1] - *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) + iVar2;
  *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + iVar2;
  *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + iVar1;
  *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + iVar1;
  *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + iVar2;
  *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + iVar2;
  *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + iVar1;
  *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + iVar1;
  *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + iVar2;
  *(int *)(param_1 + 0xe8) = *(int *)(param_1 + 0xe8) + iVar2;
  *(int *)(param_1 + 0xe4) = *(int *)(param_1 + 0xe4) + iVar1;
  *(int *)(param_1 + 0xec) = *(int *)(param_1 + 0xec) + iVar1;
  CControlPl_vslot_29();
  return;
}

