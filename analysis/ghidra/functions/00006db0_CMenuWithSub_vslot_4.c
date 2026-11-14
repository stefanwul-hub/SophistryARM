/* 00006db0 CMenuWithSub_vslot_4 */

void CMenuWithSub_vslot_4(int *param_1,undefined4 param_2)

{
  int *piVar1;
  
  if ((char)param_1[0x3b] == '\0') {
    *(undefined1 *)(param_1 + 0xc) = 0;
    param_1[0x11] = param_1[0x13];
    return;
  }
  piVar1 = (int *)param_1[param_1[0x36b] + 0x65];
  if (piVar1 != param_1) {
    (**(code **)(*piVar1 + 0x10))(piVar1,param_2);
    *(undefined1 *)(param_1 + 0xc) = 0;
    param_1[0x11] = param_1[0x13];
    return;
  }
  if ((char)param_1[0x3b] != '\0') {
    CMenuBase_vslot_4(param_1,param_2);
  }
  *(undefined1 *)(param_1 + 0xc) = 0;
  param_1[0x11] = param_1[0x13];
  *(undefined1 *)(param_1 + 0xc) = 0;
  param_1[0x11] = param_1[0x13];
  return;
}

