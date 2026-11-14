/* 0003f7c4 DelayStereo_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void DelayStereo_c_vslot_31(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  float fVar5;
  float fVar6;
  
  if ((*(char *)(param_1 + 0x15c) != '\0') && (iVar3 = *(int *)(param_1 + 0x124), iVar3 != 0)) {
    if (*(int *)(param_1 + 0x228) < 0x11) {
      fVar5 = 0.0;
      iVar2 = *(int *)(param_1 + 0x228);
    }
    else {
      fVar5 = *(float *)(iVar3 + 0xec) * 0.001;
      if (*(int *)(iVar3 + 0x174) < *(int *)(iVar3 + 0x158)) {
        lVar4 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar3 + 0x158));
        fVar5 = (float)lVar4;
        iVar3 = *(int *)(param_1 + 0x124);
      }
      iVar2 = *(int *)(param_1 + 0x228);
      for (; (float)(iVar2 + -0x10) <= fVar5 * *(float *)(param_1 + 0x140); fVar5 = fVar5 * 0.5) {
      }
    }
    iVar1 = (int)(fVar5 * *(float *)(param_1 + 0x140) + 0.5);
    if (iVar1 < 1) {
      iVar1 = 1;
    }
    if (iVar2 + -1 < iVar1) {
      iVar1 = iVar2 + -1;
    }
    *(int *)(param_1 + 0x24c) = iVar1;
    if ((iVar3 == 0) || (*(int *)(param_1 + 0x228) < 0x11)) {
      fVar5 = 0.0;
    }
    else {
      fVar5 = *(float *)(iVar3 + 0x1cc) * 0.001;
      if (*(int *)(iVar3 + 0x254) < *(int *)(iVar3 + 0x238)) {
        lVar4 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar3 + 0x238));
        fVar5 = (float)lVar4;
        iVar3 = *(int *)(param_1 + 0x124);
        iVar2 = *(int *)(param_1 + 0x228);
      }
      for (; ((float)(iVar2 + -0x10) <= *(float *)(param_1 + 0x140) * fVar5 &&
             (fVar5 = fVar5 * 0.5, (float)(iVar2 + -0x10) <= fVar5 * *(float *)(param_1 + 0x140)));
          fVar5 = fVar5 * 0.5) {
      }
    }
    iVar1 = (int)(fVar5 * *(float *)(param_1 + 0x140) + 0.5);
    if (iVar1 < 1) {
      iVar1 = 1;
    }
    if (iVar2 + -1 < iVar1) {
      iVar1 = iVar2 + -1;
    }
    *(int *)(param_1 + 0x250) = iVar1;
    *(undefined4 *)(param_1 + 0x254) = *(undefined4 *)(iVar3 + 0x3fc);
    *(float *)(param_1 + 600) = (*(float *)(iVar3 + 0x46c) + 1.0) * 0.5;
    *(float *)(param_1 + 0x25c) = (1.0 - *(float *)(iVar3 + 0x46c)) * 0.5;
    *(undefined4 *)(param_1 + 0x260) = *(undefined4 *)(iVar3 + 0x2ac);
    fVar5 = *(float *)(iVar3 + 0x2ac);
    *(float *)(param_1 + 0x264) = fVar5;
    if (*(char *)(iVar3 + 0x4ec) != '\0') {
      iVar2 = *(int *)(param_1 + 0x24c);
      if (iVar1 < iVar2) {
        lVar4 = (longdouble)_pow((double)fVar5,(double)((float)iVar1 / (float)iVar2));
        *(float *)(param_1 + 0x264) = (float)lVar4;
      }
      else {
        lVar4 = (longdouble)
                _pow((double)*(float *)(param_1 + 0x260),(double)((float)iVar2 / (float)iVar1));
        *(float *)(param_1 + 0x260) = (float)lVar4;
      }
    }
    fVar5 = (*(float *)(iVar3 + 0x31c) + *(float *)(iVar3 + 0x31c)) * *(float *)(param_1 + 0x144);
    *(float *)(param_1 + 0x26c) = fVar5;
    fVar6 = (*(float *)(iVar3 + 0x38c) + *(float *)(iVar3 + 0x38c)) * *(float *)(param_1 + 0x144);
    *(uint *)(param_1 + 0x26c) =
         ~-(uint)(fVar5 <= 1.0) & (uint)1.0 | (uint)fVar5 & -(uint)(fVar5 <= 1.0);
    fVar5 = 1.0;
    if (fVar6 <= 1.0) {
      fVar5 = fVar6;
    }
    *(float *)(param_1 + 0x268) = fVar5;
    *(undefined1 *)(param_1 + 0x270) = *(undefined1 *)(iVar3 + 0x55c);
    *(undefined1 *)(param_1 + 0x271) = *(undefined1 *)(iVar3 + 0x5cc);
  }
  return;
}

