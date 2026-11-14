/* 000703f6 StepSeq_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void StepSeq_c_vslot_31(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  char local_15c [332];
  
  iVar7 = *(int *)(param_1 + 0x124);
  if (iVar7 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x1d4) == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x1d8) == 0) {
    return;
  }
  iVar2 = *(int *)(param_1 + 0x778);
  iVar3 = *(int *)(param_1 + 0x314);
  iVar9 = *(int *)(iVar7 + 0xe8);
  *(int *)(param_1 + 0x314) = iVar9;
  *(bool *)(param_1 + 8) = iVar9 != 0;
  uVar4 = *(undefined4 *)(iVar7 + 0x1c8);
  *(undefined4 *)(param_1 + 0x1ec) = uVar4;
  FUN_00010aee(iVar7 + 0x460,local_15c);
  local_15c[1] = (char)uVar4 + '\x01';
  FUN_00010e34(*(int *)(param_1 + 0x124) + 0x460,local_15c);
  if (*(int *)(param_1 + 0x1ec) <= *(int *)(param_1 + 0x794)) {
    *(undefined4 *)(param_1 + 0x794) = 0;
  }
  iVar7 = *(int *)(param_1 + 0x124);
  *(float *)(param_1 + 0x1f0) = *(float *)(iVar7 + 0x4dc) * 0.01;
  *(undefined4 *)(param_1 + 0x30c) = *(undefined4 *)(iVar7 + 0x238);
  *(float *)(param_1 + 0x208) = *(float *)(iVar7 + 0x2ac) * 0.01;
  *(undefined1 *)(param_1 + 0x89b) = *(undefined1 *)(iVar7 + 0x5cc);
  if ((param_2 == -1) || (param_2 == 10)) {
    FUN_00010aee(iVar7 + 0x460,local_15c);
    iVar7 = -1;
    pcVar8 = local_15c;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    if (iVar7 == -0x104) {
      iVar9 = 0;
      iVar7 = param_1;
      do {
        iVar5 = iVar9 * 2;
        uVar6 = (int)local_15c[iVar5 + 2] + 0x100U & 0x800000ff;
        cVar1 = (char)uVar6;
        if ((int)uVar6 < 0) {
          *(char *)(iVar7 + 0x20c) = cVar1 + -1;
          cVar1 = local_15c[iVar5 + 3];
        }
        else {
          *(char *)(iVar7 + 0x20c) = cVar1 + -1;
          cVar1 = local_15c[iVar5 + 3];
        }
        *(char *)(iVar7 + 0x28c) = cVar1 + -1;
        iVar9 = iVar9 + 1;
        iVar7 = iVar7 + 1;
      } while (iVar9 != 0x80);
    }
    if (param_2 == -1) goto LAB_00070565;
  }
  if (param_2 != 2) {
    return;
  }
LAB_00070565:
  iVar7 = *(int *)(param_1 + 0x124);
  if ((((*(int *)(iVar7 + 0xe8) < 2) && (1 < iVar3)) &&
      (*(char *)(*(int *)(param_1 + 0x794) + 0x28c + param_1) != '\0')) && (-1 < iVar2)) {
    FUN_00020072(*(undefined4 *)(param_1 + 0x1d8),0x53,
                 *(undefined4 *)(*(int *)(param_1 + 0x1d4) + 0x1a4),0,0,0);
    FUN_0006ff0a(param_1,1);
    iVar7 = *(int *)(param_1 + 0x124);
  }
  if (((*(int *)(iVar7 + 0xe8) == 9) && (1 < iVar3)) &&
     ((*(char *)(*(int *)(param_1 + 0x794) + 0x28c + param_1) != '\0' &&
      ((-1 < iVar2 && (iVar3 != 9)))))) {
    FUN_00020072(*(undefined4 *)(param_1 + 0x1d8),0x53,
                 *(undefined4 *)(*(int *)(param_1 + 0x1d4) + 0x1a4),0,0,0);
    FUN_0006ff0a(param_1,1);
    iVar7 = *(int *)(param_1 + 0x124);
  }
  if ((((1 < *(int *)(iVar7 + 0xe8)) && (iVar3 < 2)) &&
      (iVar7 = *(int *)(param_1 + 0x1d4), iVar7 != 0)) && (*(int *)(param_1 + 0x1d8) != 0)) {
    FUN_00020072(*(undefined4 *)(iVar7 + 4),0x53,*(undefined4 *)(iVar7 + 0x1a4),0,0,0);
    FUN_0006ff0a(param_1,1);
  }
  return;
}

