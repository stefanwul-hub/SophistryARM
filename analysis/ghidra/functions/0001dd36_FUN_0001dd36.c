/* 0001dd36 FUN_0001dd36 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0001dd36(int *param_1,undefined4 param_2,undefined4 param_3)

{
  longdouble lVar1;
  longdouble lVar2;
  float fVar3;
  
  lVar1 = (longdouble)(**(code **)(*param_1 + 0x2b4))(param_1,param_2);
  lVar2 = (longdouble)FUN_0001dbe0(param_1,param_2,(float)lVar1,param_3);
  fVar3 = (float)lVar2 + (float)lVar1;
  if ((fVar3 < 0.0) && (!NAN(fVar3))) {
                    /* WARNING: Could not recover jumptable at 0x0001dde4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x34))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001ddc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x34))();
  return;
}

