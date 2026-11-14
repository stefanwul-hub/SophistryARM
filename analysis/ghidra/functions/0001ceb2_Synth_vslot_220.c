/* 0001ceb2 Synth_vslot_220 */

void Synth_vslot_220(undefined4 param_1,undefined4 param_2,undefined1 *param_3)

{
  int local_18;
  int *local_14;
  undefined4 local_10 [2];
  
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = 0;
    FUN_0001cb52(param_1,param_2,&local_14,&local_18,local_10);
    if ((local_18 != -1) && (local_14 != (int *)0x0)) {
      (**(code **)(*local_14 + 0x48))(local_14,local_10[0],local_18,param_3);
    }
  }
  return;
}

