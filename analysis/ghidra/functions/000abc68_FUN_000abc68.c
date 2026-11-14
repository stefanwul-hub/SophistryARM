/* 000abc68 FUN_000abc68 */

void FUN_000abc68(int param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  _Rb_tree_node_base *p_Var3;
  
  if (*(char *)(param_1 + 0x20) == '\0') {
    p_Var3 = *(_Rb_tree_node_base **)(param_1 + 0x14);
    if (p_Var3 != (_Rb_tree_node_base *)(param_1 + 0xc)) {
      do {
        *param_2 = *(uint *)(p_Var3 + 0x10);
        param_2 = param_2 + 1;
        p_Var3 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var3);
      } while (p_Var3 != (_Rb_tree_node_base *)(param_1 + 0xc));
      return;
    }
  }
  else {
    uVar1 = (*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24) >> 3) * -0x55555555;
    if (uVar1 != 0) {
      uVar2 = 0;
      do {
        *param_2 = uVar2;
        param_2 = param_2 + 1;
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar1);
    }
  }
  return;
}

