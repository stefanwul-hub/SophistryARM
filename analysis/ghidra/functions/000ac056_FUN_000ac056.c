/* 000ac056 FUN_000ac056 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined1 FUN_000ac056(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *local_50;
  undefined1 local_31;
  int local_30;
  uint local_20 [4];
  
  iVar2 = _CFDictionaryGetCount(*param_2);
  puVar3 = (undefined4 *)_malloc(iVar2 << 2);
  _CFDictionaryGetKeysAndValues(*param_2,puVar3,0);
  if (iVar2 < 1) {
    uVar6 = 0;
    if (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2 != 0) {
LAB_000ac0c1:
      local_31 = 0;
      goto joined_r0x000ac188;
    }
  }
  else {
    iVar4 = 0;
    uVar6 = 0;
    do {
      _CFStringGetCString(puVar3[iVar4],&DAT_000fd5a0,0x20,0x600);
      _sscanf(&DAT_000fd5a0,"%ld",local_20);
      if (uVar6 < local_20[0]) {
        uVar6 = local_20[0];
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != iVar2);
    if (uVar6 < (uint)(*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2)) goto LAB_000ac0c1;
  }
  FUN_000abf88(param_1,uVar6 + 1);
  local_31 = 1;
joined_r0x000ac188:
  if (0 < iVar2) {
    local_30 = 0;
    local_50 = puVar3;
    do {
      iVar4 = _CFDictionaryGetValue(*param_2,*local_50);
      _CFStringGetCString(*local_50,&DAT_000fd5a0,0x20,0x600);
      _sscanf(&DAT_000fd5a0,"%ld",local_20);
      piVar1 = *(int **)(param_1 + 8) + local_20[0];
      if ((piVar1 < *(int **)(param_1 + 0xc)) && (*(int **)(param_1 + 8) <= piVar1)) {
        iVar5 = *piVar1;
      }
      else {
        iVar5 = 0;
      }
      if (*(int *)(iVar5 + 0x30) != 0) {
        _CFRelease(*(int *)(iVar5 + 0x30));
      }
      *(int *)(iVar5 + 0x30) = iVar4;
      if (iVar4 != 0) {
        _CFRetain(iVar4);
      }
      local_30 = local_30 + 1;
      local_50 = local_50 + 1;
    } while (local_30 != iVar2);
  }
  _free(puVar3);
  return local_31;
}

