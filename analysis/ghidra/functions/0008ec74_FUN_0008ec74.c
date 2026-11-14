/* 0008ec74 FUN_0008ec74 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0008ec74(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  int local_20;
  
  if (*(int *)(param_1 + 0x120) != 0) {
    FUN_00012432(*(int *)(param_1 + 0x120),param_2,1,"");
    FUN_000aecdc(param_1 + param_2 * 0x274 + 0x1d8);
    local_20 = 0;
    do {
      iVar2 = 0;
      iVar3 = local_20;
      do {
        iVar1 = *(int *)(param_1 + 0x1d4);
        lVar4 = (longdouble)_sin((double)iVar2 * 0.04908738521234052);
        *(float *)(iVar1 + iVar3) = (float)lVar4;
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 4;
      } while (iVar2 != 0x80);
      FUN_00032430(param_1,local_20 + *(int *)(param_1 + 0x1d4),0x80);
      local_20 = local_20 + 0x200;
    } while (local_20 != 0x8000);
    *(undefined4 *)(param_1 + 0x44c) = 0x3f800000;
  }
  return;
}

