/* 000ab74e FUN_000ab74e */

uint FUN_000ab74e(int param_1,int *param_2)

{
  short sVar1;
  uint uVar2;
  
  if (param_2 == (int *)0x0) {
    uVar2 = 0xffffffce;
  }
  else {
    sVar1 = *(short *)(param_1 + 2);
    if (sVar1 == -3) {
      uVar2 = (uint)(*(int *)(param_1 + 4) + 4U < 4);
    }
    else if (sVar1 == -2) {
      (**(code **)(*param_2 + 0x10))(param_2);
      (**(code **)(*param_2 + 4))(param_2);
      uVar2 = 0;
    }
    else {
      if (sVar1 == -4) {
                    /* WARNING: Could not recover jumptable at 0x000ab7b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (**(code **)(*param_2 + 8))();
        return uVar2;
      }
      uVar2 = 0x80008002;
    }
  }
  return uVar2;
}

