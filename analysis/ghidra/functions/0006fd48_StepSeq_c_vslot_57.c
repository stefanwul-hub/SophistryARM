/* 0006fd48 StepSeq_c_vslot_57 */

longdouble StepSeq_c_vslot_57(int param_1,char param_2,int param_3)

{
  int iVar1;
  longdouble lVar2;
  
  if ((*(int *)(param_1 + 0x314) != 0) && (*(int *)(*(int *)(param_1 + 0x124) + 0x158) <= param_3))
  {
    lVar2 = (longdouble)FUN_000137fe(param_1,param_3);
    if (param_2 == '\0') {
      iVar1 = *(int *)(param_1 + 0x778);
    }
    else {
      iVar1 = *(int *)(param_1 + 0x77c);
    }
    if (0.0 < (float)iVar1) {
      lVar2 = (longdouble)_fmod((double)iVar1,(double)(float)lVar2);
      return (longdouble)-(float)lVar2;
    }
  }
  return (longdouble)0.0;
}

