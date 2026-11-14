/* 0007eea4 C51Map_vslot_4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void C51Map_vslot_4(int param_1,undefined4 param_2)

{
  int iVar1;
  int local_44;
  int local_40;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  
  if (0 < *(int *)(param_1 + 0xb4)) {
    local_44 = 0;
    local_40 = 0;
    do {
      while (iVar1 = local_40 + *(int *)(param_1 + 0x90), 0.5 < *(float *)(iVar1 + 0x3c)) {
        local_20 = local_44 * *(int *)(param_1 + 0xbc);
        local_24 = 0;
        local_30 = (int)((float)*(int *)(param_1 + 0xc4) * *(float *)(iVar1 + 0x24)) +
                   *(int *)(param_1 + 0xc);
        local_28 = local_30 + *(int *)(param_1 + 0xbc);
        local_34 = (int)((float)*(int *)(param_1 + 0xc0) * *(float *)(iVar1 + 0xc)) +
                   *(int *)(param_1 + 8);
        local_2c = local_34 + *(int *)(param_1 + 0xb8);
        (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))
                  (*(int **)(param_1 + 0xb0),param_2,&local_34,&local_24);
        local_44 = local_44 + 1;
        local_40 = local_40 + 0x48;
        if (*(int *)(param_1 + 0xb4) <= local_44) goto LAB_0007ef93;
      }
      local_44 = local_44 + 1;
      local_40 = local_40 + 0x48;
    } while (local_44 < *(int *)(param_1 + 0xb4));
  }
LAB_0007ef93:
  CControlPl_vslot_4(param_1,param_2);
  return;
}

