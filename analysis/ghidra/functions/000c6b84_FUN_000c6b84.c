/* 000c6b84 FUN_000c6b84 */

void FUN_000c6b84(int param_1,_Rb_tree_node_base *param_2,uint *param_3)

{
  int iVar1;
  
  if (((_Rb_tree_node_base *)(param_1 + 4) == param_2) ||
     (param_2 == *(_Rb_tree_node_base **)(param_1 + 0x10))) {
    if ((*(int *)(param_1 + 0x14) != 0) && (*(uint *)(*(int *)(param_1 + 0x10) + 0x10) < *param_3))
    {
      FUN_000c6a12(param_1,0,*(int *)(param_1 + 0x10),param_3);
      return;
    }
  }
  else {
    iVar1 = std::_Rb_tree_increment(param_2);
    if ((*(uint *)(param_2 + 0x10) < *param_3) && (*param_3 < *(uint *)(iVar1 + 0x10))) {
      if (*(int *)(param_2 + 0xc) == 0) {
        FUN_000c6a12(param_1,0,param_2,param_3);
        return;
      }
      FUN_000c6a12(param_1,iVar1,iVar1,param_3);
      return;
    }
  }
  FUN_000c6aae(param_1,param_3);
  return;
}

