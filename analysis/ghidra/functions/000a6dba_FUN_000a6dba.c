/* 000a6dba FUN_000a6dba */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined1 FUN_000a6dba(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  
  if (param_2 == 1) {
    piVar1 = (int *)param_1[0xf] + param_3;
    if ((((int *)param_1[0x10] <= piVar1) || (piVar1 < (int *)param_1[0xf])) || (*piVar1 == 0)) {
      puVar3 = (undefined4 *)___cxa_allocate_exception(4);
      *puVar3 = 0xffffd583;
                    /* WARNING: Subroutine does not return */
      ___cxa_throw(puVar3,PTR_001037fc,0);
    }
    if (*(int *)(*piVar1 + 0x78) != 1) goto LAB_000a6e28;
  }
  else {
    if (param_2 == 0) {
      uVar2 = (**(code **)(*param_1 + 0xa4))(param_1,2,0);
      return uVar2;
    }
    if (param_2 == 2) {
LAB_000a6e28:
      uVar2 = (**(code **)(*param_1 + 0xa4))(param_1,param_2,param_3);
      return uVar2;
    }
  }
  return 0;
}

