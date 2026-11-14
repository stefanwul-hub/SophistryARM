/* 00088a8c DelayPingPongR_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void DelayPingPongR_c_vslot_31(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longdouble lVar5;
  float fVar6;
  
  if ((*(char *)(param_1 + 0x15c) != '\0') && (iVar2 = *(int *)(param_1 + 0x124), iVar2 != 0)) {
    if (*(int *)(param_1 + 0x204) < 0x11) {
      fVar6 = 0.0;
      iVar4 = *(int *)(param_1 + 0x204);
    }
    else {
      fVar6 = *(float *)(iVar2 + 0x7c) * 0.001;
      if (*(int *)(iVar2 + 0x104) < *(int *)(iVar2 + 0xe8)) {
        lVar5 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar2 + 0xe8));
        fVar6 = (float)lVar5;
        iVar2 = *(int *)(param_1 + 0x124);
      }
      iVar4 = *(int *)(param_1 + 0x204);
      for (; (float)(iVar4 + -0x10) <= fVar6 * *(float *)(param_1 + 0x140); fVar6 = fVar6 * 0.5) {
      }
    }
    iVar3 = (int)(fVar6 * *(float *)(param_1 + 0x140) + 0.5);
    iVar1 = 1;
    if (0 < iVar3) {
      iVar1 = iVar3;
    }
    *(int *)(param_1 + 0x218) = iVar1;
    if (iVar4 + -1 < *(int *)(param_1 + 0x218)) {
      *(int *)(param_1 + 0x218) = iVar4 + -1;
    }
    if ((iVar2 == 0) || (*(int *)(param_1 + 0x204) < 0x11)) {
      fVar6 = 0.0;
    }
    else {
      fVar6 = *(float *)(iVar2 + 0x15c) * 0.001;
      if (*(int *)(iVar2 + 0x1e4) < *(int *)(iVar2 + 0x1c8)) {
        lVar5 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar2 + 0x1c8));
        fVar6 = (float)lVar5;
        iVar2 = *(int *)(param_1 + 0x124);
        iVar4 = *(int *)(param_1 + 0x204);
      }
      for (; ((float)(iVar4 + -0x10) <= *(float *)(param_1 + 0x140) * fVar6 &&
             (fVar6 = fVar6 * 0.5, (float)(iVar4 + -0x10) <= *(float *)(param_1 + 0x140) * fVar6));
          fVar6 = fVar6 * 0.5) {
      }
    }
    *(int *)(param_1 + 0x21c) = (int)(fVar6 * *(float *)(param_1 + 0x140) + 0.5);
    if ((iVar2 == 0) || (*(int *)(param_1 + 0x204) < 0x11)) {
      *(int *)(param_1 + 0x220) = (int)(*(float *)(param_1 + 0x140) * 0.0 + 0.5);
      iVar1 = *(int *)(param_1 + 0x21c);
    }
    else {
      fVar6 = *(float *)(iVar2 + 0x2ac) * 0.001;
      if (*(int *)(iVar2 + 0x334) < *(int *)(iVar2 + 0x318)) {
        lVar5 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar2 + 0x318));
        fVar6 = (float)lVar5;
        iVar2 = *(int *)(param_1 + 0x124);
        iVar4 = *(int *)(param_1 + 0x204);
      }
      for (; ((float)(iVar4 + -0x10) <= *(float *)(param_1 + 0x140) * fVar6 &&
             (fVar6 = fVar6 * 0.5, (float)(iVar4 + -0x10) <= *(float *)(param_1 + 0x140) * fVar6));
          fVar6 = fVar6 * 0.5) {
      }
      *(int *)(param_1 + 0x220) = (int)(fVar6 * *(float *)(param_1 + 0x140) + 0.5);
      iVar1 = *(int *)(param_1 + 0x21c);
    }
    if (iVar1 < 1) {
      *(undefined4 *)(param_1 + 0x21c) = 1;
    }
    iVar4 = iVar4 + -1;
    if (iVar4 < *(int *)(param_1 + 0x21c)) {
      *(int *)(param_1 + 0x21c) = iVar4;
    }
    if (*(int *)(param_1 + 0x220) < 1) {
      *(undefined4 *)(param_1 + 0x220) = 1;
    }
    if (iVar4 < *(int *)(param_1 + 0x220)) {
      *(int *)(param_1 + 0x220) = iVar4;
    }
    *(float *)(param_1 + 0x224) = 1.0 - *(float *)(iVar2 + 0x46c);
    *(float *)(param_1 + 0x228) =
         *(float *)(iVar2 + 0x46c) * ((*(float *)(iVar2 + 0x23c) + 1.0) * -0.5 + 1.0);
    *(float *)(param_1 + 0x22c) =
         *(float *)(iVar2 + 0x46c) * (*(float *)(iVar2 + 0x23c) + 1.0) * 0.5;
    *(float *)(param_1 + 0x230) =
         *(float *)(iVar2 + 0x46c) * (*(float *)(iVar2 + 0x38c) + 1.0) * 0.5;
    *(float *)(param_1 + 0x234) =
         *(float *)(iVar2 + 0x46c) * ((*(float *)(iVar2 + 0x38c) + 1.0) * -0.5 + 1.0);
    *(undefined4 *)(param_1 + 0x238) = *(undefined4 *)(iVar2 + 0x4dc);
    *(undefined4 *)(param_1 + 0x23c) = *(undefined4 *)(iVar2 + 0x3fc);
  }
  return;
}

