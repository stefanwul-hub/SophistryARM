/* 00097322 CControlPl_vslot_63 */

undefined4 CControlPl_vslot_63(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  char cVar2;
  longdouble lVar3;
  
  if (param_3 != 0x11) {
    return 0;
  }
  (**(code **)(*param_1 + 0xe0))(param_1);
  lVar3 = (longdouble)(**(code **)(*param_1 + 0xd4))(param_1);
  param_1[0x13] = (int)(float)lVar3;
  cVar2 = (**(code **)(*param_1 + 0x50))(param_1);
  if ((cVar2 != '\0') && (puVar1 = (undefined4 *)param_1[0xf], puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(puVar1,param_2,param_1);
  }
  (**(code **)(*param_1 + 0xe4))(param_1);
  return 1;
}

