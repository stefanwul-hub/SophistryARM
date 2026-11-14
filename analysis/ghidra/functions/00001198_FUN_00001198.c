/* 00001198 FUN_00001198 */

void FUN_00001198(undefined4 *param_1)

{
  int local_18;
  undefined4 local_14;
  undefined1 local_d;
  
  local_14 = 0;
  local_d = 0;
  local_18 = __keymgr_get_and_lock_processwide_ptr(0xe);
  if (local_18 != 0) {
    local_d = *(undefined1 *)(local_18 + 2);
    *(undefined1 *)(local_18 + 2) = 1;
    local_14 = *(undefined4 *)(local_18 + 4);
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_18);
  }
  if (param_1[1] == 0) {
    (*(code *)*param_1)();
  }
  else {
    (*(code *)*param_1)(param_1[2]);
  }
  if (local_18 != 0) {
    local_18 = __keymgr_get_and_lock_processwide_ptr(0xe);
  }
  if (local_18 != 0) {
    local_18 = FUN_000010dc(local_18,local_14);
  }
  if (local_18 != 0) {
    *(undefined1 *)(local_18 + 2) = local_d;
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_18);
  }
  return;
}

