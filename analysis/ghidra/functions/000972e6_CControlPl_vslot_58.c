/* 000972e6 CControlPl_vslot_58 */

void CControlPl_vslot_58(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 100) = *param_2;
  *(undefined4 *)(param_1 + 0x68) = uVar1;
  return;
}

