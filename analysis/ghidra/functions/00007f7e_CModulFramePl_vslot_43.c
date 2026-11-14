/* 00007f7e CModulFramePl_vslot_43 */

void CModulFramePl_vslot_43(int *param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0xbc))(param_1,param_2);
  if (cVar1 != '\0') {
    return;
  }
  CViewContainer_vslot_43();
  return;
}

