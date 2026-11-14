/* 000349f0 FUN_000349f0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000349f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int local_38;
  int local_28;
  int local_24;
  int local_20;
  
  if ((*(int *)(param_1 + 0x120) != 0) &&
     (local_20 = FUN_00011b72(*(int *)(param_1 + 0x120),param_2), local_20 != 0)) {
    local_24 = param_2 * 0x9d00 + 0x1e0 + param_1;
    local_20 = local_20 + 0x3f0;
    local_28 = 0;
    local_38 = 0;
    do {
      iVar1 = local_38 + local_28 + param_2 * 0x9d00;
      iVar2 = iVar1 + 0x3b4 + param_1;
      cVar3 = FUN_0002ddaa(iVar2);
      if (*(int *)(local_24 + 0x21c) != 0) {
        FUN_000aecdc(iVar1 + 0x1e0 + param_1);
      }
      if (cVar3 != '\0') {
        FUN_0002ddc8(iVar2);
      }
      FUN_00010e34(local_20,"");
      local_28 = local_28 + 1;
      local_38 = local_38 + 0x273;
      local_24 = local_24 + 0x274;
      local_20 = local_20 + 0x8c0;
    } while (local_28 != 0x40);
  }
  return;
}

