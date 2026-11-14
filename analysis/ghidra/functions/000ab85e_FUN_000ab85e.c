/* 000ab85e FUN_000ab85e */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_000ab85e(int param_1,undefined4 param_2)

{
  uint uVar1;
  _Rb_tree_node_base *p_Var2;
  int iVar3;
  uint uVar4;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  
  if (*(char *)(param_1 + 0x20) == '\0') {
    uVar1 = *(uint *)(param_1 + 0x1c);
    local_10 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
    _CFDataAppendBytes(param_2,&local_10,4);
    p_Var2 = *(_Rb_tree_node_base **)(param_1 + 0x14);
    if ((_Rb_tree_node_base *)(param_1 + 0xc) != p_Var2) {
      do {
        uVar1 = *(uint *)(p_Var2 + 0x10);
        local_1c = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
        local_14 = *(uint *)(p_Var2 + 0x20);
        local_18 = local_14 >> 0x18 | (local_14 & 0xff0000) >> 8 | (local_14 & 0xff00) << 8 |
                   local_14 << 0x18;
        _CFDataAppendBytes(param_2,&local_1c,8);
        p_Var2 = (_Rb_tree_node_base *)std::_Rb_tree_increment(p_Var2);
      } while (p_Var2 != (_Rb_tree_node_base *)(param_1 + 0xc));
      return;
    }
  }
  else {
    iVar3 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24) >> 3;
    uVar1 = iVar3 * -0x55555555;
    local_14 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | iVar3 * -0x55000000
    ;
    _CFDataAppendBytes(param_2,&local_14,4);
    if (uVar1 != 0) {
      uVar4 = 0;
      iVar3 = 0;
      do {
        local_1c = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
        local_10 = *(uint *)(*(int *)(param_1 + 0x24) + iVar3 + 0xc);
        local_18 = local_10 >> 0x18 | (local_10 & 0xff0000) >> 8 | (local_10 & 0xff00) << 8 |
                   local_10 << 0x18;
        _CFDataAppendBytes(param_2,&local_1c,8);
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 0x18;
      } while (uVar4 < uVar1);
      return;
    }
  }
  return;
}

