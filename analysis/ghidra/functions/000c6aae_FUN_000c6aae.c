/* 000c6aae FUN_000c6aae */

ulonglong FUN_000c6aae(int param_1,uint *param_2)

{
  _Rb_tree_node_base *p_Var1;
  undefined4 uVar2;
  _Rb_tree_node_base *p_Var3;
  
  p_Var3 = (_Rb_tree_node_base *)(param_1 + 4);
  if (*(_Rb_tree_node_base **)(param_1 + 8) == (_Rb_tree_node_base *)0x0) {
LAB_000c6b19:
    if (p_Var3 == *(_Rb_tree_node_base **)(param_1 + 0xc)) {
      uVar2 = FUN_000c6a12(param_1,0,p_Var3,param_2);
      goto LAB_000c6b4f;
    }
    p_Var1 = (_Rb_tree_node_base *)std::_Rb_tree_decrement(p_Var3);
    if (*param_2 <= *(uint *)(p_Var1 + 0x10)) {
LAB_000c6b02:
      return ZEXT48(p_Var1);
    }
  }
  else {
    p_Var3 = *(_Rb_tree_node_base **)(param_1 + 8);
    do {
      p_Var1 = p_Var3;
      if (*param_2 < *(uint *)(p_Var1 + 0x10)) {
        p_Var3 = *(_Rb_tree_node_base **)(p_Var1 + 8);
      }
      else {
        p_Var3 = *(_Rb_tree_node_base **)(p_Var1 + 0xc);
      }
    } while (p_Var3 != (_Rb_tree_node_base *)0x0);
    p_Var3 = p_Var1;
    if (*param_2 < *(uint *)(p_Var1 + 0x10)) goto LAB_000c6b19;
    if (*param_2 <= *(uint *)(p_Var1 + 0x10)) goto LAB_000c6b02;
  }
  uVar2 = FUN_000c6a12(param_1,0,p_Var3,param_2);
LAB_000c6b4f:
  return CONCAT44(1,uVar2);
}

