/* 000b0bca FUN_000b0bca */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_000b0bca(int param_1,FILE *param_2)

{
  float fVar1;
  size_t sVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined1 auStack_27 [7];
  undefined4 local_20 [4];
  
  local_20[0] = 0;
  sVar2 = _fwrite(local_20,1,4,param_2);
  if ((sVar2 == 4) && (sVar2 = _fwrite(local_20,1,4,param_2), sVar2 == 4)) {
    if (*(short *)(param_1 + 0x216) == 1) {
      if (0 < *(int *)(param_1 + 0x22c)) {
        iVar6 = 0;
        do {
          fVar1 = *(float *)(*(int *)(param_1 + 0x21c) + iVar6 * 4);
          if ((0.0 <= fVar1) || (NAN(fVar1))) {
            fVar1 = fVar1 * 8388607.0 + 0.01;
          }
          else {
            fVar1 = (fVar1 + 2.0) * 8388607.0 + 1.01;
          }
          uVar4 = (uint)fVar1;
          iVar5 = 3;
          do {
            (auStack_27 + 1)[iVar5 + -1] = (char)uVar4;
            uVar4 = uVar4 >> 8;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          sVar2 = _fwrite(auStack_27 + 1,3,1,param_2);
          if (sVar2 != 1) goto LAB_000b0c06;
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(int *)(param_1 + 0x22c));
      }
    }
    else {
      if (*(short *)(param_1 + 0x216) != 2) {
        return 0xfffffe16;
      }
      if (0 < *(int *)(param_1 + 0x22c)) {
        iVar6 = 0;
        do {
          fVar1 = *(float *)(iVar6 * 4 + *(int *)(param_1 + 0x21c));
          if ((0.0 <= fVar1) || (NAN(fVar1))) {
            fVar1 = fVar1 * 8388607.0 + 0.01;
          }
          else {
            fVar1 = (fVar1 + 2.0) * 8388607.0 + 1.01;
          }
          uVar4 = (uint)fVar1;
          iVar5 = 3;
          do {
            (auStack_27 + 1)[iVar5 + -1] = (char)uVar4;
            uVar4 = uVar4 >> 8;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          fVar1 = *(float *)(iVar6 * 4 + *(int *)(param_1 + 0x220));
          if (fVar1 < 0.0) {
            fVar1 = (fVar1 + 2.0) * 8388607.0 + 1.01;
          }
          else {
            fVar1 = fVar1 * 8388607.0 + 0.01;
          }
          uVar4 = (uint)fVar1;
          iVar5 = 3;
          do {
            auStack_27[iVar5 + 3] = (char)uVar4;
            uVar4 = uVar4 >> 8;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          sVar2 = _fwrite(auStack_27 + 1,3,2,param_2);
          if (sVar2 != 2) {
            return 0xfffffe5c;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < *(int *)(param_1 + 0x22c));
      }
    }
    if (((uint)*(ushort *)(param_1 + 0x216) * *(int *)(param_1 + 0x22c) & 1) != 0) {
      auStack_27[1] = 0;
      sVar2 = _fwrite((void *)0x0,1,1,param_2);
      if (sVar2 != 1) {
        return 0xfffffe52;
      }
    }
    uVar3 = 0;
  }
  else {
LAB_000b0c06:
    uVar3 = 0xfffffe66;
  }
  return uVar3;
}

