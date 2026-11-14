/* 0002eede FUN_0002eede */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int FUN_0002eede(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_19c;
  int local_194;
  int local_190;
  int local_18c;
  int local_188;
  int local_17c;
  int local_170;
  int local_16c;
  int local_168;
  int local_164;
  int local_160;
  char local_15c [332];
  
  if (*(int *)(param_1 + 0x10) != 0) {
    iVar2 = FUN_0002e1c0(param_1 + 4);
    iVar3 = iVar2 + 1;
    iVar8 = *(int *)(param_1 + 0xc);
    if (0 < iVar8) {
      piVar5 = *(int **)(param_1 + 0x10);
      if (param_4 == 0x10) {
        local_16c = 0;
        local_19c = -1;
        piVar4 = piVar5;
        local_18c = iVar3;
        do {
          if ((((param_3 == piVar4[3]) && (param_2 == piVar4[1])) && (*piVar4 == 2)) &&
             (piVar4[8] < local_18c)) {
            local_19c = local_16c;
            local_18c = piVar4[8];
          }
          local_16c = local_16c + 1;
          piVar4 = piVar4 + 9;
        } while (iVar8 != local_16c);
      }
      else {
        iVar6 = 0;
        local_19c = -1;
        piVar4 = piVar5;
        local_194 = iVar3;
        do {
          if (((param_3 == piVar4[3]) && (param_4 == piVar4[5])) &&
             ((param_2 == piVar4[1] && ((*piVar4 == 2 && (piVar4[8] < local_194)))))) {
            local_19c = iVar6;
            local_194 = piVar4[8];
          }
          iVar6 = iVar6 + 1;
          piVar4 = piVar4 + 9;
        } while (iVar8 != iVar6);
      }
      if (-1 < local_19c) {
        return local_19c;
      }
      if (param_4 == 0x10) {
        local_168 = 0;
        piVar4 = piVar5;
        local_188 = iVar3;
        do {
          if (((param_2 == piVar4[1]) && (*piVar4 == 2)) && (piVar4[8] < local_188)) {
            local_19c = local_168;
            local_188 = piVar4[8];
          }
          local_168 = local_168 + 1;
          piVar4 = piVar4 + 9;
        } while (iVar8 != local_168);
      }
      else {
        iVar6 = 0;
        piVar4 = piVar5;
        local_17c = iVar3;
        do {
          if (((param_2 == piVar4[1]) && (param_4 == piVar4[5])) &&
             ((*piVar4 == 2 && (piVar4[8] < local_17c)))) {
            local_19c = iVar6;
            local_17c = piVar4[8];
          }
          iVar6 = iVar6 + 1;
          piVar4 = piVar4 + 9;
        } while (iVar8 != iVar6);
      }
      if (-1 < local_19c) {
        return local_19c;
      }
      if (param_4 == 0x10) {
        local_164 = 0;
        piVar4 = piVar5;
        local_190 = iVar3;
        do {
          if (((piVar4[3] == param_3) && (param_2 == piVar4[1])) &&
             ((*piVar4 == 1 && (piVar4[7] < local_190)))) {
            local_19c = local_164;
            local_190 = piVar4[7];
          }
          local_164 = local_164 + 1;
          piVar4 = piVar4 + 9;
        } while (iVar8 != local_164);
      }
      else {
        iVar6 = 0;
        piVar4 = piVar5;
        local_170 = iVar3;
        do {
          if ((((piVar4[3] == param_3) && (param_4 == piVar4[5])) && (param_2 == piVar4[1])) &&
             ((*piVar4 == 1 && (piVar4[7] < local_170)))) {
            local_19c = iVar6;
            local_170 = piVar4[7];
          }
          iVar6 = iVar6 + 1;
          piVar4 = piVar4 + 9;
        } while (iVar8 != iVar6);
      }
      if (-1 < local_19c) {
        return local_19c;
      }
      if (param_4 == 0x10) {
        iVar7 = 0;
        piVar4 = piVar5;
        iVar6 = iVar3;
        do {
          if (((param_2 == piVar4[1]) && (*piVar4 == 1)) && (piVar4[7] < iVar6)) {
            iVar6 = piVar4[7];
            local_19c = iVar7;
          }
          iVar7 = iVar7 + 1;
          piVar4 = piVar4 + 9;
        } while (iVar8 != iVar7);
      }
      else {
        iVar6 = 0;
        piVar4 = piVar5;
        local_160 = iVar3;
        do {
          if ((((param_2 == piVar4[1]) && (piVar4[5] == param_4)) && (*piVar4 == 1)) &&
             (piVar4[7] < local_160)) {
            local_19c = iVar6;
            local_160 = piVar4[7];
          }
          iVar6 = iVar6 + 1;
          piVar4 = piVar4 + 9;
        } while (iVar8 != iVar6);
      }
      if (-1 < local_19c) {
        return local_19c;
      }
      iVar7 = 0;
      piVar4 = piVar5;
      iVar6 = iVar3;
      do {
        if ((*piVar4 == 2) && (piVar4[8] < iVar6)) {
          iVar6 = piVar4[8];
          local_19c = iVar7;
        }
        iVar7 = iVar7 + 1;
        piVar4 = piVar4 + 9;
      } while (iVar8 != iVar7);
      if (-1 < local_19c) {
        return local_19c;
      }
      iVar6 = 0;
      piVar4 = piVar5;
      do {
        if ((*piVar4 == 1) && (piVar4[7] < iVar3)) {
          iVar3 = piVar4[7];
          local_19c = iVar6;
        }
        iVar6 = iVar6 + 1;
        piVar4 = piVar4 + 9;
      } while (iVar8 != iVar6);
      if (-1 < local_19c) {
        return local_19c;
      }
      iVar8 = 0;
      iVar3 = 0;
      while( true ) {
        puVar1 = (undefined4 *)(iVar3 + (int)piVar5);
        _sprintf(local_15c,"Idx=%d Ins=%d (InsIdxIn=%d) State %d On=%ld Off=%ld Now=%lu",iVar8,
                 puVar1[1],param_2,*puVar1,puVar1[7],puVar1[8],iVar2);
        iVar8 = iVar8 + 1;
        iVar3 = iVar3 + 0x24;
        if (*(int *)(param_1 + 0xc) <= iVar8) break;
        piVar5 = *(int **)(param_1 + 0x10);
      }
      return local_19c;
    }
  }
  return -1;
}

