/* 0003481e WaveRAM2_c_vslot_40 */

void WaveRAM2_c_vslot_40(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  Part_c_vslot_40(param_1,param_2);
  local_18 = 0;
  local_14 = 0;
  local_10 = 0xf;
  local_1c = 0;
  do {
    iVar1 = local_1c + 0x1e0 + local_18;
    if (*(int *)((int)param_1 + iVar1 + 0x21c) != 0) {
      if (param_1[0x48] == 0) {
        return;
      }
      iVar2 = FUN_00011b72(param_1[0x48],0);
      if (iVar2 == 0) {
        return;
      }
      iVar2 = iVar2 + local_14;
      FUN_000109ee(iVar2 + 0x690,*(int *)((int)param_1 + iVar1 + 0x22c) + -1);
      FUN_000109ee(iVar2 + 0x8c0,*(int *)((int)param_1 + iVar1 + 0x22c) + -1);
      FUN_000109ee(iVar2 + 0x930,*(int *)((int)param_1 + iVar1 + 0x22c) + -1);
      FUN_000109ee(iVar2 + 0xaf0,*(int *)((int)param_1 + iVar1 + 0x22c) + -1);
      (**(code **)(*param_1 + 0x78))(param_1,0,local_10);
      (**(code **)(*param_1 + 0x78))(param_1,0,local_10 + 5);
      (**(code **)(*param_1 + 0x78))(param_1,0,local_10 + 6);
      (**(code **)(*param_1 + 0x78))(param_1,0,local_10 + 10);
    }
    local_18 = local_18 + 1;
    local_1c = local_1c + 0x273;
    local_14 = local_14 + 0x8c0;
    local_10 = local_10 + 0x14;
    if (local_18 == 0x40) {
      return;
    }
  } while( true );
}

