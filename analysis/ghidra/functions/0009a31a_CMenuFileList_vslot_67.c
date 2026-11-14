/* 0009a31a CMenuFileList_vslot_67 */

void CMenuFileList_vslot_67(int *param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  
  cVar2 = (char)((uint)param_2 >> 0x18);
  cVar3 = (char)((uint)param_2 >> 0x10);
  cVar1 = (char)((uint)param_2 >> 8);
  if (((((char)param_1[0x25] != (char)param_2) || (cVar1 != *(char *)((int)param_1 + 0x95))) ||
      (cVar3 != *(char *)((int)param_1 + 0x96))) || (cVar2 != *(char *)((int)param_1 + 0x97))) {
    (**(code **)(*param_1 + 0x54))(param_1,1);
  }
  *(char *)(param_1 + 0x25) = (char)param_2;
  *(char *)((int)param_1 + 0x95) = cVar1;
  *(char *)((int)param_1 + 0x96) = cVar3;
  *(char *)((int)param_1 + 0x97) = cVar2;
  return;
}

