/* 000126be FUN_000126be */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000126be(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  
  *param_1 = &PTR_ParaSet_c_vslot_0_000e6bc8;
  param_1[5] = param_2;
  param_1[2] = param_3;
  param_1[3] = param_3 + -1;
  param_1[6] = param_4;
  param_4 = param_4 * param_1[2];
  piVar1 = (int *)operator_new__(param_4 * 0x70 + 4);
  *piVar1 = param_4;
  if (param_4 != 0) {
    param_4 = param_4 + -2;
    piVar4 = piVar1 + 1;
    do {
      FUN_0001014a(piVar4);
      piVar4 = piVar4 + 0x1c;
      param_4 = param_4 + -1;
    } while (param_4 != -2);
  }
  param_1[1] = piVar1 + 1;
  pvVar2 = operator_new__(param_1[2] << 2);
  param_1[7] = pvVar2;
  if (pvVar2 != (void *)0x0) {
    if ((int)param_1[2] < 1) {
      iVar3 = param_1[6];
      goto joined_r0x000127d8;
    }
    iVar3 = 0;
    do {
      *(int *)(param_1[7] + iVar3 * 4) = iVar3 * param_1[6] * 0x70 + param_1[1];
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1[2]);
  }
  iVar3 = param_1[6];
joined_r0x000127d8:
  if (((0 < iVar3) && (param_1[1] != 0)) && (param_1[7] != 0)) {
    *(undefined1 *)(param_1 + 4) = 1;
    *(undefined1 *)((int)param_1 + 0x11) = 0;
    *(undefined1 *)((int)param_1 + 0x12) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  return;
}

