/* 0000b6b6 FUN_0000b6b6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0000b6b6(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  double dVar5;
  float fVar6;
  
  if ((param_2 != 0) && (*(int *)(param_1 + 0x4c) != 0)) {
    *(int *)(param_1 + 0x34) = param_2;
    iVar2 = *(int *)(param_1 + 0x14);
    if (iVar2 < *(int *)(param_1 + 0x18)) {
      fVar6 = (float)(*(int *)(param_1 + 0x1c) - iVar2) / (float)(*(int *)(param_1 + 0x18) - iVar2);
    }
    else {
      fVar6 = 0.5;
    }
    lVar3 = (longdouble)
            (**(code **)(**(int **)(param_1 + 0x4c) + 0x2b4))
                      (*(int **)(param_1 + 0x4c),*(undefined4 *)(param_1 + 8));
    fVar1 = *(float *)(param_1 + 0x28);
    dVar5 = (double)fVar1;
    if ((0.01 < dVar5) || ((dVar5 < -0.01 && (!NAN(dVar5))))) {
      lVar4 = (longdouble)_exp(dVar5);
      lVar4 = (longdouble)_log(((double)lVar4 * (double)fVar6 - (double)fVar6) + 1.0);
      fVar6 = (float)lVar4 / fVar1;
    }
    (**(code **)(**(int **)(param_1 + 0x34) + 0xd0))(*(int **)(param_1 + 0x34),fVar6);
    FUN_0000afe2(param_1,(float)lVar3);
                    /* WARNING: Could not recover jumptable at 0x0000b7c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x44) + 0xac))();
    return;
  }
  return;
}

