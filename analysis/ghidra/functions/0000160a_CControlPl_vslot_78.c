/* 0000160a CControlPl_vslot_78 */

void CControlPl_vslot_78(int *param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  
  cVar2 = (char)((uint)param_2 >> 0x18);
  cVar3 = (char)((uint)param_2 >> 0x10);
  cVar1 = (char)((uint)param_2 >> 8);
  if (((((char)param_1[0x22] != (char)param_2) || (cVar1 != *(char *)((int)param_1 + 0x89))) ||
      (cVar3 != *(char *)((int)param_1 + 0x8a))) || (cVar2 != *(char *)((int)param_1 + 0x8b))) {
    (**(code **)(*param_1 + 0x54))(param_1,1);
  }
  *(char *)(param_1 + 0x22) = (char)param_2;
  *(char *)((int)param_1 + 0x89) = cVar1;
  *(char *)((int)param_1 + 0x8a) = cVar3;
  *(char *)((int)param_1 + 0x8b) = cVar2;
  return;
}

