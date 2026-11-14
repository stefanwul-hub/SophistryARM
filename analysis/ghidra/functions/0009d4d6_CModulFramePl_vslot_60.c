/* 0009d4d6 CModulFramePl_vslot_60 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 CModulFramePl_vslot_60(int param_1,int *param_2,char param_3)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_3 == '\0') {
    piVar4 = *(int **)(param_1 + 0x3c);
  }
  else {
    piVar4 = *(int **)(param_1 + 0x40);
  }
  if (piVar4 != (int *)0x0) {
    bVar1 = false;
    if (param_2 == (int *)0x0) {
      if (param_3 == '\0') {
        do {
          piVar3 = (int *)*piVar4;
          cVar2 = (**(code **)(*piVar3 + 0x9c))(piVar3);
          if (cVar2 != '\0') goto LAB_0009d5b8;
          cVar2 = (**(code **)(*piVar3 + 0xa4))(piVar3,"CViewContainer");
          if ((cVar2 != '\0') && (cVar2 = (**(code **)(*piVar3 + 0xf0))(piVar3,0,0), cVar2 != '\0'))
          {
            return 1;
          }
          piVar4 = (int *)piVar4[1];
        } while (piVar4 != (int *)0x0);
      }
      else {
        do {
          piVar3 = (int *)*piVar4;
          cVar2 = (**(code **)(*piVar3 + 0x9c))(piVar3);
          if (cVar2 != '\0') goto LAB_0009d5b8;
          cVar2 = (**(code **)(*piVar3 + 0xa4))(piVar3,"CViewContainer");
          if ((cVar2 != '\0') &&
             (cVar2 = (**(code **)(*piVar3 + 0xf0))(piVar3,0,param_3), cVar2 != '\0')) {
            return 1;
          }
          piVar4 = (int *)piVar4[2];
        } while (piVar4 != (int *)0x0);
      }
    }
    else if (param_3 == '\0') {
      do {
        piVar3 = (int *)*piVar4;
        if (bVar1) {
          cVar2 = (**(code **)(*piVar3 + 0x9c))(piVar3);
          if (cVar2 != '\0') {
LAB_0009d5b8:
            (**(code **)(**(int **)(param_1 + 0x28) + 0x13c))(*(int **)(param_1 + 0x28),piVar3);
            return 1;
          }
          cVar2 = (**(code **)(*piVar3 + 0xa4))(piVar3,"CViewContainer");
          if ((cVar2 != '\0') && (cVar2 = (**(code **)(*piVar3 + 0xf0))(piVar3,0,0), cVar2 != '\0'))
          {
            return 1;
          }
        }
        else if (param_2 == piVar3) {
          bVar1 = true;
        }
        piVar4 = (int *)piVar4[1];
      } while (piVar4 != (int *)0x0);
    }
    else {
      do {
        piVar3 = (int *)*piVar4;
        if (bVar1) {
          cVar2 = (**(code **)(*piVar3 + 0x9c))(piVar3);
          if (cVar2 != '\0') goto LAB_0009d5b8;
          cVar2 = (**(code **)(*piVar3 + 0xa4))(piVar3,"CViewContainer");
          if ((cVar2 != '\0') &&
             (cVar2 = (**(code **)(*piVar3 + 0xf0))(piVar3,0,param_3), cVar2 != '\0')) {
            return 1;
          }
        }
        else if (param_2 == piVar3) {
          bVar1 = true;
        }
        piVar4 = (int *)piVar4[2];
      } while (piVar4 != (int *)0x0);
    }
  }
  return 0;
}

