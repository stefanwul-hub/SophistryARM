/* 0008c872 FUN_0008c872 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0008c872(int param_1)

{
  int iVar1;
  undefined **local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (*(int *)(param_1 + 0x120) != 0) {
    iVar1 = 0;
    do {
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0x3f800000;
      local_34 = 0;
      local_30 = 0x7f;
      local_2c = 0xffffffff;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_48 = &PTR_CCAss_c_vslot_0_000f2f08;
      FUN_0008bcda(param_1,iVar1,&local_48);
      iVar1 = iVar1 + 1;
    } while (iVar1 != 0x80);
  }
  *(undefined4 *)(param_1 + 0x324) = 0;
  *(undefined4 *)(param_1 + 0x328) = 0;
  *(undefined4 *)(param_1 + 0x32c) = 0;
  *(undefined1 *)(param_1 + 0x330) = 0;
  *(undefined1 *)(param_1 + 0x316) = 0;
  *(undefined1 *)(param_1 + 0x1d4) = 0;
  *(undefined4 *)(param_1 + 0x31c) = 0xffffffff;
  *(undefined4 *)(param_1 + 800) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x334) = 0;
  return;
}

