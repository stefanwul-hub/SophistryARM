/* 000ac49e FUN_000ac49e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000ac49e(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  bool bVar5;
  uint local_3c [3];
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  uint local_20 [4];
  
  bVar5 = *(char *)(param_1 + 0x20) == '\0';
  if (bVar5) {
    iVar1 = param_1 + 8;
    iVar2 = FUN_000c6836(iVar1,&param_2);
    if (param_1 + 0xc != iVar2) {
      *(undefined4 *)(iVar2 + 0x14) = 1;
      *(undefined4 *)(iVar2 + 0x20) = param_3;
      *(undefined4 *)(iVar2 + 0x24) = param_3;
      return;
    }
    iVar3 = FUN_000c69de(iVar1,&param_2);
    if ((iVar3 == iVar2) || (param_2 < *(uint *)(iVar3 + 0x10))) {
      local_3c[0] = param_2;
      local_2c = 0;
      local_3c[1] = 1;
      local_3c[2] = iVar2;
      local_30 = iVar2;
      local_28 = iVar2;
      local_24 = iVar2;
      iVar3 = FUN_000c6b84(iVar1,iVar3,local_3c);
    }
    *(int *)(iVar3 + 0x28) = iVar2;
    *(int *)(iVar3 + 0x1c) = iVar2;
    *(int *)(iVar3 + 0x18) = iVar2;
    *(undefined4 *)(iVar3 + 0x24) = param_3;
    *(undefined4 *)(iVar3 + 0x20) = param_3;
    *(undefined4 *)(iVar3 + 0x14) = 1;
  }
  else {
    local_20[0] = param_2;
    if (bVar5) {
      iVar1 = FUN_000c6836(param_1 + 8,local_20);
      if (iVar1 == param_1 + 0xc) goto LAB_000ac601;
      puVar4 = (undefined4 *)(iVar1 + 0x14);
    }
    else {
      if ((uint)((*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24) >> 3) * -0x55555555) <=
          param_2) {
LAB_000ac601:
        puVar4 = (undefined4 *)___cxa_allocate_exception(4);
        *puVar4 = 0xffffd582;
                    /* WARNING: Subroutine does not return */
        ___cxa_throw(puVar4,PTR_001037fc,0);
      }
      puVar4 = (undefined4 *)(*(int *)(param_1 + 0x24) + param_2 * 0x18);
    }
    *puVar4 = 1;
    puVar4[3] = param_3;
    puVar4[4] = param_3;
  }
  return;
}

