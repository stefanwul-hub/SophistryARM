/* 0009a29c CMenuFileList_vslot_66 */

void CMenuFileList_vslot_66(int *param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  
  cVar2 = (char)((uint)param_2 >> 0x18);
  cVar3 = (char)((uint)param_2 >> 0x10);
  cVar1 = (char)((uint)param_2 >> 8);
  if (((((char)param_1[0x24] != (char)param_2) || (cVar1 != *(char *)((int)param_1 + 0x91))) ||
      (cVar3 != *(char *)((int)param_1 + 0x92))) || (cVar2 != *(char *)((int)param_1 + 0x93))) {
    (**(code **)(*param_1 + 0x54))(param_1,1);
  }
  *(char *)(param_1 + 0x24) = (char)param_2;
  *(char *)((int)param_1 + 0x91) = cVar1;
  *(char *)((int)param_1 + 0x92) = cVar3;
  *(char *)((int)param_1 + 0x93) = cVar2;
  return;
}

