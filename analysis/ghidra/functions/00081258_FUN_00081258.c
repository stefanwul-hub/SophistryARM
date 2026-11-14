/* 00081258 FUN_00081258 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00081258(int param_1,float *param_2,float *param_3)

{
  longdouble lVar1;
  longdouble lVar2;
  float fVar3;
  float fVar4;
  
  if ((param_2 != (float *)0x0) && (param_3 != (float *)0x0)) {
    *param_2 = 0.0;
    *param_3 = 1.0;
    lVar1 = (longdouble)
            FUN_000152c0((float)*(int *)(param_1 + 0xe0),*(undefined4 *)(param_1 + 0xdc));
    lVar2 = (longdouble)FUN_00001ace(param_1,4);
    lVar2 = (longdouble)_pow(0,0x40000000,(double)(float)lVar2 * 13.0);
    fVar3 = (float)lVar2;
    if ((0.9999 <= fVar3) || (NAN(fVar3))) {
      fVar4 = 8192.1;
      if (fVar3 <= 8192.1) {
        fVar4 = fVar3;
      }
    }
    else {
      fVar4 = 0.9999;
    }
    lVar2 = (longdouble)
            FUN_000152c0((float)*(int *)(param_1 + 0xb0) * fVar4,(float)*(int *)(param_1 + 0xe0));
    fVar3 = (float)lVar2;
    lVar2 = (longdouble)FUN_00001ace(param_1,5);
    *param_2 = 0.0;
    if (fVar3 < 1.0) {
      *param_2 = (1.0 - fVar3) * (float)lVar1 * (float)lVar2;
    }
    *param_3 = (float)lVar1 * fVar3 + *param_2;
  }
  return;
}

