/* 000860be InBuffer2_c_vslot_8 */

void InBuffer2_c_vslot_8(int *param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  int local_24;
  int local_20 [5];
  
  if (*(char *)((int)param_1 + 0x26) == '\0') {
    if (*(char *)((int)param_1 + 0x27) != '\0') {
      cVar2 = (**(code **)(*param_1 + 0x38))(param_1,&local_24,local_20);
      if (cVar2 != '\0') {
        iVar6 = param_4 + -1;
        if (0 < param_4) {
          pfVar5 = (float *)(param_2 + iVar6 * 4);
          pfVar4 = (float *)(local_24 + iVar6 * 4);
          iVar3 = iVar6;
          do {
            *pfVar5 = *pfVar5 + *pfVar4;
            pfVar5 = pfVar5 + -1;
            pfVar4 = pfVar4 + -1;
            bVar1 = 0 < iVar3;
            iVar3 = iVar3 + -1;
          } while (bVar1);
        }
        if (0 < param_4) {
          pfVar5 = (float *)(param_3 + iVar6 * 4);
          pfVar4 = (float *)(local_20[0] + iVar6 * 4);
          do {
            *pfVar5 = *pfVar5 + *pfVar4;
            pfVar5 = pfVar5 + -1;
            pfVar4 = pfVar4 + -1;
            bVar1 = 0 < iVar6;
            iVar6 = iVar6 + -1;
          } while (bVar1);
          return;
        }
      }
    }
  }
  else {
    cVar2 = (**(code **)(*param_1 + 0x34))(param_1,&local_24,0);
    if (cVar2 != '\0') {
      iVar6 = param_4 + -1;
      if (0 < param_4) {
        pfVar4 = (float *)(param_2 + iVar6 * 4);
        pfVar5 = (float *)(local_24 + iVar6 * 4);
        iVar3 = iVar6;
        do {
          *pfVar4 = *pfVar4 + *pfVar5;
          pfVar4 = pfVar4 + -1;
          pfVar5 = pfVar5 + -1;
          bVar1 = 0 < iVar3;
          iVar3 = iVar3 + -1;
        } while (bVar1);
        if (0 < param_4) {
          pfVar5 = (float *)(param_3 + iVar6 * 4);
          pfVar4 = (float *)(local_24 + iVar6 * 4);
          do {
            *pfVar5 = *pfVar5 + *pfVar4;
            pfVar5 = pfVar5 + -1;
            pfVar4 = pfVar4 + -1;
            bVar1 = 0 < iVar6;
            iVar6 = iVar6 + -1;
          } while (bVar1);
          return;
        }
      }
    }
  }
  return;
}

