/* 00011c3e ParaSet_c_vslot_2 */

int ParaSet_c_vslot_2(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *local_158;
  int local_154;
  int local_150;
  char local_14c [320];
  
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  iVar5 = *(int *)(param_1 + 0xc);
  if (param_2 <= *(int *)(param_1 + 0xc)) {
    iVar5 = param_2;
  }
  iVar5 = *(int *)(param_1 + 4) + iVar5 * *(int *)(param_1 + 0x18) * 0x70;
  if (*(int *)(param_1 + 0x18) < 1) {
    local_154 = 0xc;
  }
  else {
    local_154 = 0xc;
    local_150 = 0;
    do {
      iVar2 = *(int *)(iVar5 + 4);
      if (iVar2 == 7) {
        FUN_00010aee(iVar5,local_14c);
LAB_00011cf2:
        local_158 = local_14c;
        uVar4 = 0xffffffff;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          cVar1 = *local_158;
          local_158 = local_158 + 1;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4;
        if ((uVar4 & 3) != 0) {
          uVar3 = uVar4 & 0x80000003;
          if ((int)uVar3 < 0) {
            uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
          }
          uVar4 = (uVar4 - uVar3) + 4;
        }
        local_154 = local_154 + 4 + uVar4;
      }
      else {
        if (iVar2 == 2) {
          FUN_00010b62(iVar5,local_14c);
          goto LAB_00011cf2;
        }
        if (iVar2 == 8) {
          local_154 = local_154 + 4 + *(int *)(iVar5 + 0x34) * 4;
        }
        else {
          local_154 = local_154 + 4;
        }
      }
      local_150 = local_150 + 1;
      iVar5 = iVar5 + 0x70;
    } while (local_150 < *(int *)(param_1 + 0x18));
  }
  return local_154;
}

