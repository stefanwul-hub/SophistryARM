/* 000c1266 Note_c_vslot_2 */

int * Note_c_vslot_2(int *param_1,int param_2,int param_3)

{
  param_1[2] = param_2;
  param_1[3] = param_3;
  (**(code **)(*param_1 + 0x28))(param_1);
  return param_1;
}

