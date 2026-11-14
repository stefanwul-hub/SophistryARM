/* 000a957c LPAUSynth_vslot_27 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 LPAUSynth_vslot_27(int param_1,uint param_2,int param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_30;
  uint local_2c;
  int local_20;
  
  if (4 < param_2) {
    puVar3 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar3 = 0xffffd58e;
                    /* WARNING: Subroutine does not return */
    ___cxa_throw(puVar3,PTR_001037fc,0);
  }
  iVar1 = param_1 + 0x20 + param_2 * 0x14;
  piVar6 = *(int **)(iVar1 + 8);
  iVar4 = (int)*(int **)(iVar1 + 0xc) - (int)piVar6 >> 2;
  if (iVar4 < 1) {
    local_30 = 0;
    local_2c = 0;
  }
  else {
    local_20 = 0;
    local_30 = 0;
    local_2c = 0;
    do {
      if ((piVar6 < *(int **)(iVar1 + 0xc)) && (*(int **)(iVar1 + 8) <= piVar6)) {
        iVar5 = *piVar6;
        if (*(char *)(iVar5 + 0x20) != '\0') goto LAB_000a95e3;
        uVar2 = *(uint *)(iVar5 + 0x1c);
      }
      else {
        iVar5 = 0;
LAB_000a95e3:
        uVar2 = (*(int *)(iVar5 + 0x28) - *(int *)(iVar5 + 0x24) >> 3) * -0x55555555;
      }
      if (local_2c < uVar2) {
        local_30 = iVar5;
        local_2c = uVar2;
      }
      local_20 = local_20 + 1;
      piVar6 = piVar6 + 1;
    } while (iVar4 != local_20);
  }
  if ((param_3 != 0) && (local_30 != 0)) {
    FUN_000abc68(local_30,param_3);
  }
  *param_4 = local_2c;
  return 0;
}

