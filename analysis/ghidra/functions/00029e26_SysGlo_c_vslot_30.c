/* 00029e26 SysGlo_c_vslot_30 */

void SysGlo_c_vslot_30(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  void *pvVar2;
  
  Envelope_c_vslot_30(param_1,param_2,param_3);
  if (*(char *)(param_1 + 0x315) != '\0') {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x120) + 8))(*(int **)(param_1 + 0x120),0);
    pvVar2 = _malloc(iVar1 + 1);
    if (pvVar2 != (void *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x120) + 0xc))(*(int **)(param_1 + 0x120),pvVar2,0);
      FUN_0002e9fe(param_1 + 0x168,param_1 + 0x1d4,pvVar2,iVar1);
      _free(pvVar2);
      return;
    }
  }
  return;
}

