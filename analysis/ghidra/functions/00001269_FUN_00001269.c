/* 00001269 FUN_00001269 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_00001269(undefined4 *param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_30;
  
  iVar2 = FUN_00000ed6();
  if (iVar2 == 0) {
    local_30 = 0xffffffff;
  }
  else if ((*(char *)(iVar2 + 2) == '\0') && (*(char *)(iVar2 + 3) != '\x01')) {
    if (*(byte *)(iVar2 + 3) < 0x10) {
      pcVar1 = *(code **)(iVar2 + 8);
      iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar2);
      if (iVar2 == 0) {
        puVar3 = (undefined4 *)_malloc(0xc);
        if (puVar3 == (undefined4 *)0x0) {
          local_30 = 0xffffffff;
        }
        else {
          *puVar3 = *param_1;
          puVar3[1] = param_1[1];
          puVar3[2] = param_1[2];
          local_30 = (*pcVar1)(FUN_00001198,puVar3,param_2);
        }
      }
      else {
        local_30 = 0xffffffff;
      }
    }
    else if (param_1[1] == 0) {
      pcVar1 = *(code **)(iVar2 + 0x10);
      iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar2);
      if (iVar2 == 0) {
        local_30 = (*pcVar1)(*param_1);
      }
      else {
        local_30 = 0xffffffff;
      }
    }
    else {
      pcVar1 = *(code **)(iVar2 + 8);
      iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar2);
      if (iVar2 == 0) {
        local_30 = (*pcVar1)(*param_1,param_1[2],param_2);
      }
      else {
        local_30 = 0xffffffff;
      }
    }
  }
  else {
    local_30 = FUN_00001043(iVar2,param_1);
  }
  return local_30;
}

