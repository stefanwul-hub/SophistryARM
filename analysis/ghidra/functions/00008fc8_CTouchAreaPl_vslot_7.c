/* 00008fc8 CTouchAreaPl_vslot_7 */

void CTouchAreaPl_vslot_7(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int local_10;
  
  if ((char)param_1[0x33] == '\0') {
    if (param_1[0x2c] != 0) {
      if ((-1 < param_1[0x30]) && (uVar1 = FUN_0009cba2(param_2), (uVar1 & 0x20) != 0)) {
        (**(code **)(*(int *)param_1[0x2c] + 0x32c))
                  ((int *)param_1[0x2c],param_1[0x30],param_1[0x31],param_1[0x32],param_2);
        return;
      }
      (**(code **)(*(int *)param_1[0x2c] + 0x32c))
                ((int *)param_1[0x2c],param_1[0x2d],param_1[0x2e],param_1[0x2f],param_2);
    }
  }
  else {
    local_10 = 0xc;
    while (uVar1 = FUN_0009cba2(param_2), (uVar1 & 5) != 0) {
      if (param_1[0x2c] != 0) {
        if ((param_1[0x30] < 0) || (uVar1 = FUN_0009cba2(param_2), (uVar1 & 0x20) == 0)) {
          (**(code **)(*(int *)param_1[0x2c] + 0x32c))
                    ((int *)param_1[0x2c],param_1[0x2d],param_1[0x2e],param_1[0x2f],param_2);
        }
        else {
          (**(code **)(*(int *)param_1[0x2c] + 0x32c))
                    ((int *)param_1[0x2c],param_1[0x30],param_1[0x31],param_1[0x32],param_2);
        }
      }
      if (0 < local_10) {
        iVar2 = 0;
        do {
          uVar1 = FUN_0009cba2(param_2);
          if ((uVar1 & 5) != 0) {
            FUN_00001c28(param_1,0x28);
            (**(code **)(*param_1 + 0xac))(param_1);
          }
          iVar2 = iVar2 + 1;
        } while (local_10 != iVar2);
      }
      iVar2 = local_10 + -1;
      local_10 = 5;
      if (4 < iVar2) {
        local_10 = iVar2;
      }
    }
  }
  return;
}

