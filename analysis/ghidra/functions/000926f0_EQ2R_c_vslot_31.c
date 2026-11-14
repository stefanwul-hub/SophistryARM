/* 000926f0 EQ2R_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void EQ2R_c_vslot_31(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  int iVar5;
  
  if ((*(char *)(param_1 + 0x15c) != '\0') && (iVar5 = *(int *)(param_1 + 0x124), iVar5 != 0)) {
    uVar2 = *(undefined4 *)(iVar5 + 0x7c);
    fVar1 = *(float *)(iVar5 + 0xec);
    uVar3 = *(undefined4 *)(iVar5 + 0x15c);
    bVar4 = 0.1 < ABS(fVar1);
    *(bool *)(param_1 + 0x1e0) = bVar4;
    if (bVar4) {
      FUN_00092582(param_1,uVar2,fVar1,uVar3,*(undefined4 *)(param_1 + 0x144));
      iVar5 = *(int *)(param_1 + 0x124);
    }
    uVar2 = *(undefined4 *)(iVar5 + 0x1cc);
    fVar1 = *(float *)(iVar5 + 0x23c);
    uVar3 = *(undefined4 *)(iVar5 + 0x2ac);
    bVar4 = 0.1 < ABS(fVar1);
    *(bool *)(param_1 + 0x1e1) = bVar4;
    if (bVar4) {
      FUN_00091d52(param_1,uVar2,fVar1,uVar3,*(undefined4 *)(param_1 + 0x144));
      return;
    }
  }
  return;
}

