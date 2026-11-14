/* 000a610e SynthEditor_c_vslot_9 */

undefined4 SynthEditor_c_vslot_9(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined1 local_7c [104];
  undefined4 local_14;
  undefined4 local_10;
  
  FUN_000a171a(local_7c,*(undefined4 *)(param_1 + 0x1c),0,*(undefined4 *)(param_1 + 8));
  local_14 = param_2;
  local_10 = param_3;
  piVar1 = *(int **)(param_1 + 0x1c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))(piVar1,local_7c,&local_14,0xffffffff);
  }
  CDrawContext_vslot_0(local_7c);
  return 1;
}

