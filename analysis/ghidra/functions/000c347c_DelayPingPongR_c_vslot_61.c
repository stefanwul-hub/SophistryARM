/* 000c347c DelayPingPongR_c_vslot_61 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble DelayPingPongR_c_vslot_61(int param_1)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if (*(int *)(param_1 + 0x124) != 0) {
    lVar2 = (longdouble)_log10((double)*(float *)(*(int *)(param_1 + 0x124) + 0x3fc) + 0.0001);
    lVar2 = (longdouble)FUN_00015302(0,0xc0100000,(double)lVar2);
    iVar1 = *(int *)(param_1 + 0x124);
    if ((iVar1 == 0) || (*(int *)(param_1 + 0x204) < 0x11)) {
      fVar4 = 0.1;
    }
    else {
      fVar4 = *(float *)(iVar1 + 0x7c) * 0.001;
      if (*(int *)(iVar1 + 0x104) < *(int *)(iVar1 + 0xe8)) {
        lVar3 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar1 + 0xe8));
        fVar4 = (float)lVar3;
        iVar1 = *(int *)(param_1 + 0x124);
      }
      for (; (float)(*(int *)(param_1 + 0x204) + -0x10) <= fVar4 * *(float *)(param_1 + 0x140);
          fVar4 = fVar4 * 0.5) {
      }
      fVar4 = fVar4 + 0.1;
    }
    if (iVar1 == 0) {
      fVar6 = 0.0;
      fVar5 = 0.0;
    }
    else {
      fVar6 = 0.0;
      if (0x10 < *(int *)(param_1 + 0x204)) {
        fVar6 = *(float *)(iVar1 + 0x15c) * 0.001;
        if (*(int *)(iVar1 + 0x1e4) < *(int *)(iVar1 + 0x1c8)) {
          lVar3 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar1 + 0x1c8));
          fVar6 = (float)lVar3;
          iVar1 = *(int *)(param_1 + 0x124);
        }
        for (; (float)(*(int *)(param_1 + 0x204) + -0x10) <= *(float *)(param_1 + 0x140) * fVar6;
            fVar6 = fVar6 * 0.5) {
        }
      }
      if ((iVar1 == 0) || (*(int *)(param_1 + 0x204) < 0x11)) {
        fVar5 = 0.0;
      }
      else {
        fVar5 = *(float *)(iVar1 + 0x2ac) * 0.001;
        if (*(int *)(iVar1 + 0x334) < *(int *)(iVar1 + 0x318)) {
          lVar3 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar1 + 0x318));
          fVar5 = (float)lVar3;
        }
        for (; (float)(*(int *)(param_1 + 0x204) + -0x10) <= *(float *)(param_1 + 0x140) * fVar5;
            fVar5 = fVar5 * 0.5) {
        }
      }
    }
    return (longdouble)(fVar4 + (fVar6 + fVar5) * (float)lVar2 + 0.1);
  }
  return (longdouble)0.0;
}

