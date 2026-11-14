/* 000c6a12 FUN_000c6a12 */

_Rb_tree_node_base * FUN_000c6a12(int param_1,int param_2,_Rb_tree_node_base *param_3,uint *param_4)

{
  bool bVar1;
  _Rb_tree_node_base *p_Var2;
  
  p_Var2 = (_Rb_tree_node_base *)operator_new(0x2c);
  if (p_Var2 != (_Rb_tree_node_base *)0xfffffff0) {
    *(uint *)(p_Var2 + 0x10) = *param_4;
    *(uint *)(p_Var2 + 0x14) = param_4[1];
    *(uint *)(p_Var2 + 0x18) = param_4[2];
    *(uint *)(p_Var2 + 0x1c) = param_4[3];
    *(uint *)(p_Var2 + 0x20) = param_4[4];
    *(uint *)(p_Var2 + 0x24) = param_4[5];
    *(uint *)(p_Var2 + 0x28) = param_4[6];
  }
  if (((param_2 == 0) && (param_3 != (_Rb_tree_node_base *)(param_1 + 4))) &&
     (*(uint *)(param_3 + 0x10) <= *param_4)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  std::_Rb_tree_insert_and_rebalance(bVar1,p_Var2,param_3,(_Rb_tree_node_base *)(param_1 + 4));
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  return p_Var2;
}

