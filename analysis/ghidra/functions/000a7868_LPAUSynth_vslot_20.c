/* 000a7868 LPAUSynth_vslot_20 */

undefined4 LPAUSynth_vslot_20(int *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int local_10;
  
  if (param_3 != 0) {
    local_10 = 0;
    do {
      while (param_2[3] == 1) {
        (**(code **)(*param_1 + 0x44))(param_1,param_2[2],*param_2,param_2[1],param_2[5],param_2[4])
        ;
        puVar1 = (undefined4 *)param_1[0x2d];
        if (puVar1 != (undefined4 *)param_1[0x2e]) goto LAB_000a789c;
LAB_000a7928:
        FUN_000c5ff2(param_1 + 0x2c,puVar1,param_2);
        local_10 = local_10 + 1;
        param_2 = param_2 + 8;
        if (param_3 == local_10) {
          return 0;
        }
      }
      puVar1 = (undefined4 *)param_1[0x2d];
      if (puVar1 == (undefined4 *)param_1[0x2e]) goto LAB_000a7928;
LAB_000a789c:
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = *param_2;
        puVar1[1] = param_2[1];
        puVar1[2] = param_2[2];
        puVar1[3] = param_2[3];
        puVar1[4] = param_2[4];
        puVar1[5] = param_2[5];
        puVar1[6] = param_2[6];
        puVar1[7] = param_2[7];
        puVar1 = (undefined4 *)param_1[0x2d];
      }
      param_1[0x2d] = (int)(puVar1 + 8);
      local_10 = local_10 + 1;
      param_2 = param_2 + 8;
    } while (param_3 != local_10);
  }
  return 0;
}

