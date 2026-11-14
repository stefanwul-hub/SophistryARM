/* 00011d9a ParaSet_c_vslot_3 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int ParaSet_c_vslot_3(int *param_1,int *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  float *pfVar8;
  longdouble lVar9;
  char *local_174;
  int local_16c;
  int local_168;
  int local_160;
  char local_150 [320];
  float local_10;
  
  if ((param_2 == (int *)0x0) || (param_1[1] == 0)) {
    return 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  iVar3 = param_1[3];
  if (param_3 <= param_1[3]) {
    iVar3 = param_3;
  }
  local_160 = param_1[1] + iVar3 * param_1[6] * 0x70;
  iVar3 = (**(code **)(*param_1 + 8))(param_1,iVar3);
  *param_2 = param_1[5];
  param_2[1] = iVar3;
  param_2[2] = 0;
  if (param_1[6] < 1) {
    return iVar3;
  }
  local_16c = 3;
  local_168 = 0;
  do {
    iVar2 = *(int *)(local_160 + 4);
    if (iVar2 == 7) {
      FUN_00010aee(local_160,local_150);
LAB_00011ec3:
      local_174 = local_150;
      uVar5 = 0xffffffff;
      pcVar7 = local_174;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      if ((uVar5 & 3) != 0) {
        uVar4 = uVar5 & 0x80000003;
        if ((int)uVar4 < 0) {
          uVar4 = (uVar4 - 1 | 0xfffffffc) + 1;
        }
        uVar5 = (uVar5 - uVar4) + 4;
      }
      param_2[local_16c] = uVar5;
      _strcpy((char *)(param_2 + local_16c + 1),local_174);
      local_16c = (uVar5 >> 2) + local_16c + 1;
      if (param_1[6] <= local_168 + 1) {
        return iVar3;
      }
    }
    else {
      if (iVar2 == 2) {
        FUN_00010b62(local_160,local_150);
        goto LAB_00011ec3;
      }
      if (iVar2 == 8) {
        iVar2 = *(int *)(local_160 + 0x34);
        param_2[local_16c] = iVar2;
        local_16c = local_16c + 1;
        if (0 < iVar2) {
          pfVar8 = (float *)(param_2 + local_16c);
          iVar6 = 0;
          do {
            lVar9 = (longdouble)FUN_000103d2(local_160,iVar6);
            local_10 = (float)lVar9;
            *pfVar8 = local_10;
            local_16c = local_16c + 1;
            iVar6 = iVar6 + 1;
            pfVar8 = pfVar8 + 1;
          } while (iVar2 != iVar6);
        }
      }
      else {
        param_2[local_16c] = *(int *)(local_160 + 8);
        local_16c = local_16c + 1;
      }
      if (param_1[6] <= local_168 + 1) {
        return iVar3;
      }
    }
    local_160 = local_160 + 0x70;
    local_168 = local_168 + 1;
  } while( true );
}

