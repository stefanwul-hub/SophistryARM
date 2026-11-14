/* 0009d2b8 CFrame_vslot_73 */

undefined4 CFrame_vslot_73(int *param_1,int param_2)

{
  undefined1 local_d;
  
  if (param_2 == 0) {
    if (param_1[0x1a] != 0) {
      local_d = 0;
      (**(code **)(*param_1 + 0xb4))(param_1,param_1[0x1a],&local_d);
    }
  }
  else if (param_1[0x1a] != 0) {
    return 0;
  }
  param_1[0x1a] = param_2;
  if (param_2 != 0) {
    (**(code **)(*param_1 + 0xac))(param_1,param_2);
  }
  return 1;
}

