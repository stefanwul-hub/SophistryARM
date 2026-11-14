/* 00028b5e FUN_00028b5e */

void FUN_00028b5e(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined1 local_d;
  
  if (((param_2 < 1) || (0xbf < param_2)) ||
     (piVar5 = *(int **)(param_1 + 0x25858 + param_2 * 4), piVar5 == (int *)0x0)) {
    piVar5 = (int *)0x0;
  }
  if (param_3 < 2) {
    return;
  }
  iVar4 = 1;
  do {
    piVar1 = (int *)(param_1 + 0x25858 + iVar4 * 4);
    cVar3 = (**(code **)(*piVar5 + 0xbc))(piVar5,*(undefined4 *)(param_1 + 0x25858 + iVar4 * 4));
    while( true ) {
      if (cVar3 != '\0') {
        FUN_00028b5e(param_1,iVar4,param_3);
        local_d = 0;
        if ((((0 < param_2) && (param_2 < 0xc0)) &&
            ((piVar2 = *(int **)(param_1 + 0x25858 + param_2 * 4), piVar2 != (int *)0x0 &&
             ((-1 < iVar4 && (iVar4 < 0xc0)))))) && (*piVar1 != 0)) {
          (**(code **)(*piVar2 + 0xb4))(piVar2,*piVar1,&local_d);
        }
      }
      iVar4 = iVar4 + 1;
      if (param_3 <= iVar4) {
        return;
      }
      if ((0 < iVar4) && (iVar4 < 0xc0)) break;
      piVar1 = piVar1 + 1;
      cVar3 = (**(code **)(*piVar5 + 0xbc))(piVar5,0);
    }
  } while( true );
}

