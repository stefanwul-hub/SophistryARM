/* 000a8af2 AUBase_vslot_25 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int AUBase_vslot_25(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_48 [10];
  undefined4 local_20 [4];
  
  piVar1 = *(int **)(param_1 + 0x3c) + param_2[2];
  if (((*(int **)(param_1 + 0x40) <= piVar1) || (piVar1 < *(int **)(param_1 + 0x3c))) ||
     (iVar2 = *piVar1, iVar2 == 0)) {
    puVar3 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar3 = 0xffffd583;
                    /* WARNING: Subroutine does not return */
    ___cxa_throw(puVar3,PTR_001037fc,0);
  }
  if (*param_2 != 0) {
    puVar3 = local_48;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    local_20[0] = 0x28;
    iVar4 = _AudioUnitGetProperty(*param_2,8,2,param_2[1],local_48,local_20);
    if (iVar4 == 0) {
      iVar4 = FUN_000a81f0(param_1,8,1,param_2[2],local_48,0x28);
      if (iVar4 == 0) goto LAB_000a8be1;
    }
    return iVar4;
  }
LAB_000a8be1:
  FUN_000ab23c(iVar2,param_2);
  FUN_000a67ae(param_1,1,1,param_2[2]);
  return 0;
}

