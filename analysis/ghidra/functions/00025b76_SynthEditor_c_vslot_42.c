/* 00025b76 SynthEditor_c_vslot_42 */

void SynthEditor_c_vslot_42(undefined4 param_1,int *param_2)

{
  int *piVar1;
  undefined1 local_d [5];
  
  if ((param_2 != (int *)0x0) && (piVar1 = (int *)*param_2, piVar1 != (int *)0x0)) {
    local_d[0] = 1;
    (**(code **)(*piVar1 + 0xb8))(piVar1,local_d);
    (**(code **)(*(int *)*param_2 + 8))((int *)*param_2);
    *param_2 = 0;
  }
  return;
}

