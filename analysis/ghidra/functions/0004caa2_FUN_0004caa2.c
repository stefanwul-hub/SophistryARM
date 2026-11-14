/* 0004caa2 FUN_0004caa2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0004caa2(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  longdouble lVar3;
  float fVar4;
  float fVar5;
  undefined4 local_28;
  
  if (param_3 == 0) {
    local_28 = 0xa5;
    uVar1 = 0xa1;
  }
  else {
    local_28 = 0xa6;
    uVar1 = 0xa2;
  }
  lVar3 = (longdouble)Envelope_c_vslot_8(param_1 + 0xcaa81,param_2,uVar1);
  lVar3 = (longdouble)_pow(0,0x40000000,(double)(float)lVar3 * 13.0);
  iVar2 = FUN_000349ae(param_1 + param_3 * 0x286e + 0x23678,param_2,param_1[param_3 + 0xcac1a]);
  if ((iVar2 != 0) && (0 < *(int *)(iVar2 + 0x22c))) {
    fVar4 = ((float)lVar3 * 317.0) / (float)*(int *)(iVar2 + 0x22c);
    if ((0.0 <= fVar4) || (NAN(fVar4))) {
      fVar5 = 1.0;
      if (fVar4 <= 1.0) {
        fVar5 = fVar4;
      }
    }
    else {
      fVar5 = 0.0;
    }
    Envelope_c_vslot_7(param_1 + 0xcaa81,param_2,local_28,fVar5);
                    /* WARNING: Could not recover jumptable at 0x0004cbbe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x350))();
    return;
  }
  return;
}

