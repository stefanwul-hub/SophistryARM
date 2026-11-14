/* 000a62f2 AEffGUIEditor_vslot_15 */

undefined1 AEffGUIEditor_vslot_15(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined1 local_7c [104];
  undefined4 local_14;
  undefined4 local_10;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    FUN_000a171a(local_7c,*(int *)(param_1 + 0x1c),0,*(undefined4 *)(param_1 + 8));
    local_14 = 0;
    local_10 = 0;
    FUN_0009ea10(local_7c,&local_14);
    uVar1 = (**(code **)(**(int **)(param_1 + 0x1c) + 0x30))
                      (*(int **)(param_1 + 0x1c),local_7c,&local_14,param_2);
    CDrawContext_vslot_0(local_7c);
    return uVar1;
  }
  return 0;
}

