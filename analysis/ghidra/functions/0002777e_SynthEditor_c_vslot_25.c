/* 0002777e SynthEditor_c_vslot_25 */

void SynthEditor_c_vslot_25(int *param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int local_28;
  int local_20;
  undefined1 local_d;
  
  if (((param_2 != (int *)0x0) && (param_3 != (int *)0x0)) && (*param_3 != 0)) {
    if (*param_3 < 1) {
      iVar4 = 0;
      iVar3 = -1;
    }
    else {
      iVar4 = 0;
      do {
        iVar3 = iVar4;
        iVar4 = iVar3 + 1;
      } while (0 < param_3[iVar4]);
    }
    if (param_4 < 0) {
      param_4 = 0;
    }
    if (param_4 <= iVar3) {
      iVar3 = param_4;
    }
    iVar3 = param_3[iVar3];
    if (((0 < iVar3) && (iVar3 < 0xc0)) &&
       ((iVar3 = param_1[iVar3 + 0x9616], iVar3 != 0 &&
        (cVar2 = (**(code **)(*param_2 + 0xbc))(param_2,iVar3), cVar2 == '\0')))) {
      if (iVar4 < 1) {
LAB_000278c8:
        (**(code **)(*param_2 + 0xac))(param_2,iVar3);
        (**(code **)(*param_1 + 0x7c))(param_1);
        *(undefined1 *)(iVar3 + 0x30) = 1;
        *(undefined1 *)(iVar3 + 100) = 1;
      }
      else {
        iVar1 = *param_3;
        if (((0 < iVar1) && (iVar1 < 0xc0)) && (local_20 = param_1[iVar1 + 0x9616], local_20 != 0))
        {
          local_28 = 0;
          do {
            cVar2 = (**(code **)(*param_2 + 0xbc))(param_2,local_20);
            if (cVar2 != '\0') {
              local_d = 0;
              (**(code **)(*param_2 + 0xb4))(param_2,local_20,&local_d);
            }
            local_28 = local_28 + 1;
            if (iVar4 == local_28) goto LAB_000278c8;
            iVar1 = param_3[local_28];
          } while (((0 < iVar1) && (iVar1 < 0xc0)) &&
                  (local_20 = param_1[iVar1 + 0x9616], local_20 != 0));
        }
      }
    }
  }
  return;
}

