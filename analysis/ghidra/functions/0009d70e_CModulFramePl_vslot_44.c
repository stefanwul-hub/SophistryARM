/* 0009d70e CModulFramePl_vslot_44 */

void CModulFramePl_vslot_44(int *param_1,int *param_2,undefined4 param_3,undefined1 param_4)

{
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 0x58))(param_2,param_4);
    (**(code **)(*param_2 + 0x60))(param_2,param_3);
                    /* WARNING: Could not recover jumptable at 0x0009d75c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xac))();
    return;
  }
  return;
}

