/* 0009e7ca CModulFramePl_vslot_50 */

void CModulFramePl_vslot_50(int *param_1,undefined4 param_2)

{
  undefined1 local_10;
  
  *(char *)(param_1 + 0x13) = (char)param_2;
  *(char *)((int)param_1 + 0x4d) = (char)((uint)param_2 >> 8);
  *(char *)((int)param_1 + 0x4e) = (char)((uint)param_2 >> 0x10);
  local_10 = (undefined1)((uint)param_2 >> 0x18);
  *(undefined1 *)((int)param_1 + 0x4f) = local_10;
                    /* WARNING: Could not recover jumptable at 0x0009e814. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x54))();
  return;
}

