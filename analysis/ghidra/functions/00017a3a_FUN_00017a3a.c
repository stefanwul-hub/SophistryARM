/* 00017a3a FUN_00017a3a */

void FUN_00017a3a(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  longdouble lVar3;
  
  *(undefined1 *)(param_1 + 0x33f6) = 1;
  if (param_2 < 0) {
    if (param_1[0x24b1] < 1) {
      *(undefined1 *)(param_1 + 0x33f6) = 0;
      return;
    }
    iVar1 = 0;
    piVar2 = param_1;
    do {
      lVar3 = (longdouble)(**(code **)(*param_1 + 0x2b4))(param_1,piVar2[0x22b1]);
      (**(code **)(*param_1 + 0x2b0))(param_1,piVar2[0x22b2],(float)lVar3);
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 2;
    } while (iVar1 < param_1[0x24b1]);
  }
  else if (0 < param_1[0x24b1]) {
    iVar1 = 0;
    piVar2 = param_1;
    do {
      while (param_2 != piVar2[0x22b1]) {
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 2;
        if (param_1[0x24b1] <= iVar1) goto LAB_00017ab9;
      }
      (**(code **)(*param_1 + 0x2b0))(param_1,piVar2[0x22b2],param_3);
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 2;
    } while (iVar1 < param_1[0x24b1]);
  }
LAB_00017ab9:
  *(undefined1 *)(param_1 + 0x33f6) = 0;
  return;
}

