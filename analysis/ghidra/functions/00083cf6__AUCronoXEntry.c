/* 00083cf6 _AUCronoXEntry */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 _AUCronoXEntry(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  if (*(short *)(param_1 + 2) != -1) {
    uVar1 = FUN_000adfd6(param_1,param_2);
    return uVar1;
  }
  uVar1 = *(undefined4 *)(param_1 + 4);
  piVar2 = (int *)operator_new(0x32b468);
  FUN_000048b0(piVar2,uVar1);
  *piVar2 = (int)&PTR_AUCronoX_vslot_0_000f2048;
  piVar2[2] = (int)&PTR_LAB_000f21a8;
  piVar2[0x39] = (int)&PTR_LAB_000f21b4;
  piVar2[0x3b] = (int)&PTR_LAB_000f2208;
  piVar2[0xcad18] = 0;
  piVar2[0xcad19] = 0;
  iVar3 = _CFDictionaryCreateMutable(*(undefined4 *)PTR_001037ec,0,PTR_00103880,PTR_00103868);
  piVar2[0xcad19] = iVar3;
  (**(code **)(*piVar2 + 0xc))(piVar2);
  _SetComponentInstanceStorage(uVar1,piVar2);
  return 0;
}

