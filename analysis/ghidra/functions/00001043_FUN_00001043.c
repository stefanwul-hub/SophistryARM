/* 00001043 FUN_00001043 */

undefined4 FUN_00001043(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_24;
  undefined4 local_20;
  
  puVar1 = (undefined4 *)_malloc(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    __keymgr_set_and_unlock_processwide_ptr(0xe,param_1);
    local_24 = 0xffffffff;
  }
  else {
    puVar1[1] = *param_2;
    puVar1[2] = param_2[1];
    puVar1[3] = param_2[2];
    *puVar1 = *(undefined4 *)(param_1 + 4);
    *(undefined4 **)(param_1 + 4) = puVar1;
    iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,param_1);
    if (iVar2 == 0) {
      local_20 = 0;
    }
    else {
      local_20 = 0xffffffff;
    }
    local_24 = local_20;
  }
  return local_24;
}

