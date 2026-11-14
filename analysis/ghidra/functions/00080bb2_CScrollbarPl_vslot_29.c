/* 00080bb2 CScrollbarPl_vslot_29 */

void CScrollbarPl_vslot_29(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_2 - *(int *)(param_1 + 8);
  iVar1 = param_2[1] - *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) + iVar2;
  *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + iVar2;
  *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + iVar1;
  *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + iVar1;
  CControlPl_vslot_29();
  return;
}

