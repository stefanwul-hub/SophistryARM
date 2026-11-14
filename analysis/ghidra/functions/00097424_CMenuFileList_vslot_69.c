/* 00097424 CMenuFileList_vslot_69 */

void CMenuFileList_vslot_69(int *param_1,int param_2)

{
  if (param_1[0x1f] != param_2) {
    (**(code **)(*param_1 + 0x54))(param_1,1);
  }
  param_1[0x1f] = param_2;
  return;
}

