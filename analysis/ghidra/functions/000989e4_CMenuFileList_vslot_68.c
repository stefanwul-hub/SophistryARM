/* 000989e4 CMenuFileList_vslot_68 */

void CMenuFileList_vslot_68(int *param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  
  cVar2 = (char)((uint)param_2 >> 0x18);
  cVar3 = (char)((uint)param_2 >> 0x10);
  cVar1 = (char)((uint)param_2 >> 8);
  if (((((char)param_1[0x26] != (char)param_2) || (cVar1 != *(char *)((int)param_1 + 0x99))) ||
      (cVar3 != *(char *)((int)param_1 + 0x9a))) || (cVar2 != *(char *)((int)param_1 + 0x9b))) {
    (**(code **)(*param_1 + 0x54))(param_1,1);
  }
  *(char *)(param_1 + 0x26) = (char)param_2;
  *(char *)((int)param_1 + 0x99) = cVar1;
  *(char *)((int)param_1 + 0x9a) = cVar3;
  *(char *)((int)param_1 + 0x9b) = cVar2;
  return;
}

