/* 0009d0a4 CFrame_vslot_10 */

int CFrame_vslot_10(int *param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  
  piVar1 = (int *)param_1[0x1b];
  if ((piVar1 != (int *)0x0) && (iVar3 = (**(code **)(*piVar1 + 0x28))(piVar1,param_2), iVar3 != -1)
     ) {
    return iVar3;
  }
  piVar1 = (int *)param_1[0x1a];
  if ((piVar1 != (int *)0x0) && (iVar3 = (**(code **)(*piVar1 + 0x28))(piVar1,param_2), iVar3 != -1)
     ) {
    return iVar3;
  }
  if ((*(char *)(param_2 + 4) == '\x02') &&
     (cVar2 = (**(code **)(*param_1 + 0xf0))(param_1,param_1[0x1b],*(byte *)(param_2 + 5) & 1),
     cVar2 != '\0')) {
    return 1;
  }
  return -1;
}

