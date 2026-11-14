/* 000a22ec CModulFramePl_vslot_32 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CModulFramePl_vslot_32(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  void *pvVar6;
  
  uVar5 = _DAT_000e20c8;
  if ((*(int *)(param_1 + 0x48) == 0) && (*(char *)(param_1 + 0x58) != '\0')) {
    iVar1 = *(int *)(param_1 + 0x10);
    iVar2 = *(int *)(param_1 + 8);
    iVar3 = *(int *)(param_1 + 0x14);
    iVar4 = *(int *)(param_1 + 0xc);
    pvVar6 = operator_new(0x84);
    FUN_000a2030(pvVar6,*(undefined4 *)(param_1 + 0x28),iVar1 - iVar2,iVar3 - iVar4,uVar5);
    *(void **)(param_1 + 0x48) = pvVar6;
    return 1;
  }
  return 1;
}

