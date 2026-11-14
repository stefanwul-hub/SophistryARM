/* 000c1550 NoteC_c_vslot_3 */

int * NoteC_c_vslot_3(int *param_1,int param_2,int param_3,int param_4)

{
  param_1[2] = param_2;
  param_1[3] = param_3;
  param_1[4] = param_4;
  (**(code **)(*param_1 + 0x28))(param_1);
  return param_1;
}

