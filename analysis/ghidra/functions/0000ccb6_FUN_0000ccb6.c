/* 0000ccb6 FUN_0000ccb6 */

void FUN_0000ccb6(int *param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  
  *(char *)((int)param_1 + 0xec3) = param_2;
  if (param_2 == '\0') {
    iVar2 = 0;
    piVar1 = param_1;
    do {
      while ((char)piVar1[0x6d] != '\0') {
        (**(code **)(*param_1 + 0xa0))(param_1,iVar2);
        *(undefined1 *)(piVar1 + 0x6d) = 0;
        iVar2 = iVar2 + 1;
        piVar1 = (int *)((int)piVar1 + 1);
        if (iVar2 == 0x10) {
          return;
        }
      }
      iVar2 = iVar2 + 1;
      piVar1 = (int *)((int)piVar1 + 1);
    } while (iVar2 != 0x10);
  }
  return;
}

