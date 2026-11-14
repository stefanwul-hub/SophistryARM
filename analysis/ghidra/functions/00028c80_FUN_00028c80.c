/* 00028c80 FUN_00028c80 */

void FUN_00028c80(int param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int local_28;
  undefined1 local_d;
  
  if (param_2 < 2) {
    return;
  }
  local_28 = 1;
LAB_00028c99:
  piVar5 = *(int **)(param_1 + 0x25858 + local_28 * 4);
LAB_00028ca6:
  iVar4 = 1;
  do {
    piVar1 = (int *)(param_1 + 0x25858 + iVar4 * 4);
    cVar2 = (**(code **)(*piVar5 + 0xbc))(piVar5,*(undefined4 *)(param_1 + 0x25858 + iVar4 * 4));
    while( true ) {
      if (cVar2 != '\0') {
        FUN_00028b5e(param_1,iVar4,param_2);
        local_d = 0;
        if (((0 < iVar4) && (iVar4 < 0xc0)) && (*piVar1 != 0)) {
          (**(code **)(*piVar5 + 0xb4))(piVar5,*piVar1,&local_d);
        }
      }
      iVar4 = iVar4 + 1;
      if (param_2 <= iVar4) {
        local_28 = local_28 + 1;
        if (param_2 <= local_28) {
          iVar4 = 1;
          do {
            uVar3 = *(undefined4 *)(param_1 + 0x25858 + iVar4 * 4);
            piVar5 = (int *)(param_1 + 0x25858 + iVar4 * 4);
            while( true ) {
              cVar2 = (**(code **)(**(int **)(param_1 + 0x24) + 0xbc))
                                (*(int **)(param_1 + 0x24),uVar3);
              if (cVar2 != '\0') {
                piVar1 = *(int **)(param_1 + 0x24);
                local_d = 0;
                if (((piVar1 != (int *)0x0) && (0 < iVar4)) && ((iVar4 < 0xc0 && (*piVar5 != 0)))) {
                  (**(code **)(*piVar1 + 0xb4))(piVar1,*piVar5,&local_d);
                }
              }
              iVar4 = iVar4 + 1;
              if (param_2 <= iVar4) {
                return;
              }
              if ((0 < iVar4) && (iVar4 < 0xc0)) break;
              piVar5 = piVar5 + 1;
              uVar3 = 0;
            }
          } while( true );
        }
        if ((0 < local_28) && (local_28 < 0xc0)) goto LAB_00028c99;
        piVar5 = (int *)0x0;
        goto LAB_00028ca6;
      }
      if ((0 < iVar4) && (iVar4 < 0xc0)) break;
      piVar1 = piVar1 + 1;
      cVar2 = (**(code **)(*piVar5 + 0xbc))(piVar5,0);
    }
  } while( true );
}

