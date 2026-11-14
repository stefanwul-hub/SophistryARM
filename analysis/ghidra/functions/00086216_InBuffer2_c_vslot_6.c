/* 00086216 InBuffer2_c_vslot_6 */

void InBuffer2_c_vslot_6(int *param_1,int *param_2,int param_3,char param_4,int param_5)

{
  bool bVar1;
  char cVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if ((param_4 == '\0') && (*(char *)((int)param_2 + 0x26) != '\0')) {
    cVar2 = (**(code **)(*param_1 + 0x28))(param_1,&local_3c,0);
    if (cVar2 != '\0') {
      cVar2 = (**(code **)(*param_2 + 0x34))(param_2,&local_24,0);
      if (cVar2 != '\0') {
        if (param_5 == 0) {
          if (0 < param_3) {
            iVar6 = (param_3 + -1) * 4;
            pfVar5 = (float *)(local_3c + iVar6);
            pfVar3 = (float *)(local_24 + iVar6);
            iVar6 = param_3 + -1;
            do {
              *pfVar5 = *pfVar5 + *pfVar3;
              pfVar5 = pfVar5 + -1;
              pfVar3 = pfVar3 + -1;
              bVar1 = 0 < iVar6;
              iVar6 = iVar6 + -1;
            } while (bVar1);
          }
        }
        else {
          (**(code **)(*param_1 + 0x4c))(param_1,local_3c,local_24,param_3,param_5);
        }
      }
      (**(code **)(*param_1 + 0x40))(param_1);
    }
  }
  else if ((*(char *)((int)param_2 + 0x27) == '\0') && (param_4 == '\0')) {
    if (((char)param_2[10] != '\0') &&
       (cVar2 = (**(code **)(*param_1 + 0x30))(param_1,&local_3c), cVar2 != '\0')) {
      cVar2 = (**(code **)(*param_2 + 0x3c))(param_2,&local_24);
      if (cVar2 != '\0') {
        if (param_5 == 0) {
          iVar6 = param_3 + -1;
          if (0 < param_3) {
            pfVar5 = (float *)(local_3c + iVar6 * 4);
            pfVar3 = (float *)(local_24 + iVar6 * 4);
            iVar4 = iVar6;
            do {
              *pfVar5 = *pfVar5 + *pfVar3;
              pfVar5 = pfVar5 + -1;
              pfVar3 = pfVar3 + -1;
              bVar1 = 0 < iVar4;
              iVar4 = iVar4 + -1;
            } while (bVar1);
          }
          if (0 < param_3) {
            pfVar5 = (float *)(local_38 + iVar6 * 4);
            pfVar3 = (float *)(local_20 + iVar6 * 4);
            iVar4 = iVar6;
            do {
              *pfVar5 = *pfVar5 + *pfVar3;
              pfVar5 = pfVar5 + -1;
              pfVar3 = pfVar3 + -1;
              bVar1 = 0 < iVar4;
              iVar4 = iVar4 + -1;
            } while (bVar1);
          }
          if (0 < param_3) {
            pfVar5 = (float *)(local_34 + iVar6 * 4);
            pfVar3 = (float *)(local_1c + iVar6 * 4);
            iVar4 = iVar6;
            do {
              *pfVar5 = *pfVar5 + *pfVar3;
              pfVar5 = pfVar5 + -1;
              pfVar3 = pfVar3 + -1;
              bVar1 = 0 < iVar4;
              iVar4 = iVar4 + -1;
            } while (bVar1);
          }
          if (0 < param_3) {
            pfVar5 = (float *)(local_30 + iVar6 * 4);
            pfVar3 = (float *)(local_18 + iVar6 * 4);
            iVar4 = iVar6;
            do {
              *pfVar5 = *pfVar5 + *pfVar3;
              pfVar5 = pfVar5 + -1;
              pfVar3 = pfVar3 + -1;
              bVar1 = 0 < iVar4;
              iVar4 = iVar4 + -1;
            } while (bVar1);
          }
          if (0 < param_3) {
            pfVar5 = (float *)(local_2c + iVar6 * 4);
            pfVar3 = (float *)(local_14 + iVar6 * 4);
            iVar4 = iVar6;
            do {
              *pfVar5 = *pfVar5 + *pfVar3;
              pfVar5 = pfVar5 + -1;
              pfVar3 = pfVar3 + -1;
              bVar1 = 0 < iVar4;
              iVar4 = iVar4 + -1;
            } while (bVar1);
          }
          if (0 < param_3) {
            pfVar3 = (float *)(iVar6 * 4 + local_28);
            pfVar5 = (float *)(iVar6 * 4 + local_10);
            do {
              *pfVar3 = *pfVar3 + *pfVar5;
              pfVar3 = pfVar3 + -1;
              pfVar5 = pfVar5 + -1;
              bVar1 = 0 < iVar6;
              iVar6 = iVar6 + -1;
            } while (bVar1);
          }
        }
        else {
          (**(code **)(*param_1 + 0x4c))(param_1,local_3c,local_24,param_3,param_5);
          (**(code **)(*param_1 + 0x4c))(param_1,local_38,local_20,param_3,param_5);
          (**(code **)(*param_1 + 0x4c))(param_1,local_34,local_1c,param_3,param_5);
          (**(code **)(*param_1 + 0x4c))(param_1,local_30,local_18,param_3,param_5);
          (**(code **)(*param_1 + 0x4c))(param_1,local_2c,local_14,param_3,param_5);
          (**(code **)(*param_1 + 0x4c))(param_1,local_28,local_10,param_3,param_5);
        }
      }
      (**(code **)(*param_1 + 0x48))(param_1);
    }
  }
  else {
    cVar2 = (**(code **)(*param_1 + 0x2c))(param_1,&local_3c,&local_38);
    if (cVar2 != '\0') {
      cVar2 = (**(code **)(*param_2 + 0x38))(param_2,&local_24,&local_20);
      if (cVar2 != '\0') {
        if (param_5 == 0) {
          iVar6 = param_3 + -1;
          if (0 < param_3) {
            pfVar3 = (float *)(iVar6 * 4 + local_3c);
            pfVar5 = (float *)(iVar6 * 4 + local_24);
            iVar4 = iVar6;
            do {
              *pfVar3 = *pfVar3 + *pfVar5;
              pfVar3 = pfVar3 + -1;
              pfVar5 = pfVar5 + -1;
              bVar1 = 0 < iVar4;
              iVar4 = iVar4 + -1;
            } while (bVar1);
          }
          if (0 < param_3) {
            pfVar5 = (float *)(local_38 + iVar6 * 4);
            pfVar3 = (float *)(local_20 + iVar6 * 4);
            do {
              *pfVar5 = *pfVar5 + *pfVar3;
              pfVar5 = pfVar5 + -1;
              pfVar3 = pfVar3 + -1;
              bVar1 = 0 < iVar6;
              iVar6 = iVar6 + -1;
            } while (bVar1);
          }
        }
        else {
          (**(code **)(*param_1 + 0x4c))(param_1,local_3c,local_24,param_3,param_5);
          (**(code **)(*param_1 + 0x4c))(param_1,local_38,local_20,param_3,param_5);
        }
      }
      (**(code **)(*param_1 + 0x44))(param_1);
      return;
    }
  }
  return;
}

