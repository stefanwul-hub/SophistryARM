/* 000ad0e8 AUPropertyControl_vslot_3 */

undefined4 AUPropertyControl_vslot_3(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = _GetEventClass(param_2);
  iVar2 = _GetEventKind(param_2);
  if ((iVar1 == 0x636e746c) && (iVar2 == 0x97)) {
    (**(code **)(*param_1 + 0x1c))(param_1);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

