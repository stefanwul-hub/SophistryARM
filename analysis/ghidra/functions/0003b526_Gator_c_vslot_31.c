/* 0003b526 Gator_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Gator_c_vslot_31(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  float fVar4;
  
  iVar1 = *(int *)(param_1 + 0x124);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x20c) = *(undefined4 *)(iVar1 + 0x2ac);
    FUN_00010aee(iVar1 + 0x70,param_1 + 0x210);
    FUN_00010aee(*(int *)(param_1 + 0x124) + 0xe0,param_1 + 0x221);
    *(undefined4 *)(param_1 + 0x234) = *(undefined4 *)(*(int *)(param_1 + 0x124) + 0x238);
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x124) + 0x158);
    lVar3 = (longdouble)FUN_000137fe(param_1,uVar2);
    *(float *)(param_1 + 0x24c) = (float)lVar3;
    lVar3 = (longdouble)FUN_00012f08(uVar2);
    *(float *)(param_1 + 0x238) = (float)lVar3 * 0.25;
    *(int *)(param_1 + 0x240) = (int)(1.0 / ((float)lVar3 * 0.25) + 0.1);
    fVar4 = *(float *)(*(int *)(param_1 + 0x124) + 0x1cc) * -0.8 + 1.0;
    *(float *)(param_1 + 0x23c) = fVar4 * fVar4 * fVar4 * *(float *)(param_1 + 0x144) * 1000.0;
  }
  return;
}

