/* 000973bc CMenuFileList_vslot_64 */

void CMenuFileList_vslot_64(int *param_1,int param_2)

{
  if (param_1[0x21] != param_2) {
    (**(code **)(*param_1 + 0x54))(param_1,1);
  }
  param_1[0x21] = param_2;
  return;
}

