/* 0000d1a6 Instrument_c_vslot_44 */

void Instrument_c_vslot_44(int *param_1,int *param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined1 local_10 [4];
  
  if (param_1[1] != 0) {
    (**(code **)(*param_1 + 0x68))(param_1,param_3);
    if ((*(char *)((int)param_1 + 0x151) != '\0') &&
       (iVar4 = param_1[1], 0 < *(int *)(LPAUSynth_vslot_10 + iVar4 + 4))) {
      iVar5 = 0;
      do {
        piVar1 = *(int **)(iVar4 + 0x7798 + iVar5 * 4);
        if ((*(char *)((int)piVar1 + 9) == '\0') && ((char)piVar1[2] == '\0')) {
          (**(code **)(*piVar1 + 0x14))(piVar1,param_3);
          iVar4 = param_1[1];
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(LPAUSynth_vslot_10 + iVar4 + 4));
    }
    if ((char)param_1[0x54] == '\0') {
      (**(code **)(*param_1 + 0x40))(param_1,param_2,param_3);
    }
    else {
      iVar4 = param_1[1];
      if (0 < *(int *)(LPAUSynth_vslot_10 + iVar4 + 4)) {
        iVar5 = 0;
        do {
          while (piVar1 = *(int **)(iVar4 + 0x7798 + iVar5 * 4), *(char *)((int)piVar1 + 9) == '\0')
          {
            iVar5 = iVar5 + 1;
            if (*(int *)(LPAUSynth_vslot_10 + iVar4 + 4) <= iVar5) goto LAB_0000d22b;
          }
          (**(code **)(*piVar1 + 0x14))(piVar1,param_3);
          iVar4 = param_1[1];
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(int *)(LPAUSynth_vslot_10 + iVar4 + 4));
      }
LAB_0000d22b:
      iVar4 = FUN_0002f3da(iVar4 + 0x38cc,param_1[0x69],local_10);
      param_1[0x3b2] = iVar4;
      while (-1 < iVar4) {
        iVar4 = param_1[1];
        if (0 < *(int *)(LPAUSynth_vslot_10 + iVar4 + 4)) {
          iVar5 = 0;
          do {
            while (piVar1 = *(int **)(iVar4 + 0x7798 + iVar5 * 4), (char)piVar1[2] == '\0') {
              iVar5 = iVar5 + 1;
              if (*(int *)(LPAUSynth_vslot_10 + iVar4 + 4) <= iVar5) goto LAB_0000d2a1;
            }
            (**(code **)(*piVar1 + 0x14))(piVar1,param_3);
            iVar4 = param_1[1];
            iVar5 = iVar5 + 1;
          } while (iVar5 < *(int *)(LPAUSynth_vslot_10 + iVar4 + 4));
        }
LAB_0000d2a1:
        (**(code **)(*param_1 + 0x6c))(param_1);
        piVar1 = *(int **)(*(int *)(param_1[1] + 0x3b0c) + param_1[0x3b2] * 4);
        cVar3 = (**(code **)(*piVar1 + 0x30))(piVar1,param_3);
        if (cVar3 != '\0') {
          FUN_00018d78(param_1[1],param_1[0x3b2]);
        }
        iVar4 = FUN_0002ecd6(param_1[1] + 0x38cc,param_1[0x69],local_10);
        param_1[0x3b2] = iVar4;
      }
      (**(code **)(*param_1 + 0x3c))(param_1,param_2,param_3);
    }
    (**(code **)(*param_1 + 0x2c))(param_1,param_3);
    (**(code **)(*param_1 + 0x74))(param_1,param_3);
    if (0 < param_1[0x6c]) {
      iVar4 = 1;
      do {
        *param_2 = *param_2 + param_3 * 4;
        bVar2 = iVar4 < param_1[0x6c];
        iVar4 = iVar4 + 1;
        param_2 = param_2 + 1;
      } while (bVar2);
    }
  }
  return;
}

