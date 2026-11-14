/* 000aba02 FUN_000aba02 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000aba02(int param_1,uint param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  bool bVar7;
  int local_4c;
  int local_48;
  undefined4 local_44;
  uint local_3c [3];
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  uint local_20 [4];
  
  bVar7 = *(char *)(param_1 + 0x20) == '\0';
  if (bVar7) {
    iVar1 = param_1 + 8;
    iVar2 = FUN_000c6836(iVar1,&param_2);
    local_3c[2] = param_1 + 0xc;
    if (iVar2 == local_3c[2]) {
      iVar2 = *(int *)(param_3 + 0xc);
      if (iVar2 == 1) {
        uVar6 = *(undefined4 *)(param_3 + 0x14);
        local_48 = param_5;
        local_4c = 0;
        local_44 = uVar6;
      }
      else {
        local_48 = *(int *)(param_3 + 0x14);
        local_4c = *(int *)(param_3 + 0x10) - param_4;
        uVar6 = *(undefined4 *)(param_3 + 0x18);
        local_44 = *(undefined4 *)(param_3 + 0x1c);
      }
      iVar3 = FUN_000c69de(iVar1,&param_2);
      if ((iVar3 == local_3c[2]) || (param_2 < *(uint *)(iVar3 + 0x10))) {
        local_3c[0] = param_2;
        local_2c = 0;
        local_3c[1] = 1;
        local_30 = local_3c[2];
        local_28 = local_3c[2];
        local_24 = local_3c[2];
        iVar3 = FUN_000c6b84(iVar1,iVar3,local_3c);
      }
      *(int *)(iVar3 + 0x18) = local_4c;
      *(int *)(iVar3 + 0x1c) = local_48;
      *(undefined4 *)(iVar3 + 0x24) = local_44;
      *(undefined4 *)(iVar3 + 0x20) = uVar6;
      *(int *)(iVar3 + 0x28) = param_5;
      *(int *)(iVar3 + 0x14) = iVar2;
    }
    else {
      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(param_3 + 0xc);
      *(int *)(iVar2 + 0x28) = param_5;
      if (*(int *)(iVar2 + 0x14) != 1) {
        *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(param_3 + 0x14);
        *(int *)(iVar2 + 0x18) = *(int *)(param_3 + 0x10) - param_4;
        *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(param_3 + 0x18);
        *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(param_3 + 0x1c);
        return;
      }
      uVar6 = *(undefined4 *)(param_3 + 0x14);
      *(undefined4 *)(iVar2 + 0x20) = uVar6;
      *(undefined4 *)(iVar2 + 0x24) = uVar6;
      *(int *)(iVar2 + 0x1c) = param_5;
      *(undefined4 *)(iVar2 + 0x18) = 0;
    }
  }
  else {
    local_20[0] = param_2;
    if (bVar7) {
      iVar1 = FUN_000c6836(param_1 + 8,local_20);
      if (iVar1 == param_1 + 0xc) goto LAB_000abc3b;
      piVar5 = (int *)(iVar1 + 0x14);
      *piVar5 = *(int *)(param_3 + 0xc);
      *(int *)(iVar1 + 0x28) = param_5;
      iVar1 = *piVar5;
    }
    else {
      if ((uint)((*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24) >> 3) * -0x55555555) <=
          param_2) {
LAB_000abc3b:
        puVar4 = (undefined4 *)___cxa_allocate_exception(4);
        *puVar4 = 0xffffd582;
                    /* WARNING: Subroutine does not return */
        ___cxa_throw(puVar4,PTR_001037fc,0);
      }
      piVar5 = (int *)(*(int *)(param_1 + 0x24) + param_2 * 0x18);
      *piVar5 = *(int *)(param_3 + 0xc);
      piVar5[5] = param_5;
      iVar1 = *piVar5;
    }
    if (iVar1 == 1) {
      iVar1 = *(int *)(param_3 + 0x14);
      piVar5[3] = iVar1;
      piVar5[4] = iVar1;
      piVar5[2] = param_5;
      piVar5[1] = 0;
      return;
    }
    piVar5[2] = *(int *)(param_3 + 0x14);
    piVar5[1] = *(int *)(param_3 + 0x10) - param_4;
    piVar5[3] = *(int *)(param_3 + 0x18);
    piVar5[4] = *(int *)(param_3 + 0x1c);
  }
  return;
}

