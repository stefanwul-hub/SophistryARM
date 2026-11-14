/* 000010dc FUN_000010dc */

int FUN_000010dc(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  byte local_20;
  
  while( true ) {
    puVar1 = *(undefined4 **)(param_1 + 4);
    if (puVar1 == (undefined4 *)0x0) {
      return param_1;
    }
    if (puVar1 == param_2) break;
    *(undefined4 *)(param_1 + 4) = *puVar1;
    __keymgr_set_and_unlock_processwide_ptr(0xe,param_1);
    if ((uint)puVar1[2] < 6) {
      local_20 = (byte)puVar1[2];
      uVar2 = 1 << (local_20 & 0x1f);
      if ((uVar2 & 0x15) == 0) {
        if ((uVar2 & 0x2a) != 0) {
          (*(code *)puVar1[1])(puVar1[3]);
        }
      }
      else {
        (*(code *)puVar1[1])();
      }
    }
    _free(puVar1);
    param_1 = __keymgr_get_and_lock_processwide_ptr(0xe);
    if (param_1 == 0) {
      return 0;
    }
  }
  return param_1;
}

