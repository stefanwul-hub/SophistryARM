/* 000a37c0 FUN_000a37c0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Removing unreachable block (ram,0x000a3888) */

void FUN_000a37c0(int *param_1,int *param_2,int param_3,int *param_4)

{
  param_1[1] = 1;
  *param_1 = (int)&PTR_CView_vslot_0_000f4088;
  param_1[2] = *param_2;
  param_1[3] = param_2[1];
  param_1[4] = param_2[2];
  param_1[5] = param_2[3];
  param_1[6] = *param_2;
  param_1[7] = param_2[1];
  param_1[8] = param_2[2];
  param_1[9] = param_2[3];
  param_1[0xb] = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined1 *)((int)param_1 + 0x31) = 1;
  *(undefined1 *)((int)param_1 + 0x32) = 0;
  *(undefined1 *)((int)param_1 + 0x33) = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  *param_1 = (int)&PTR_CViewContainer_vslot_0_000f42c8;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x17] = 0;
  *(undefined1 *)(param_1 + 0x16) = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[10] = param_3;
  param_1[0xd] = (int)param_4;
  if (param_4 != (int *)0x0) {
    (**(code **)(*param_4 + 0xc))(param_4);
  }
  (**(code **)(*param_1 + 0x54))(param_1,1);
  *(undefined1 *)(param_1 + 0x13) = DAT_000e20c8;
  *(undefined1 *)((int)param_1 + 0x4d) = DAT_000e20c9;
  *(undefined1 *)((int)param_1 + 0x4e) = DAT_000e20ca;
  *(undefined1 *)((int)param_1 + 0x4f) = DAT_000e20cb;
  param_1[0x11] = 1;
  return;
}

