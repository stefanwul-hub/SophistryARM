/* 000973f0 CMenuFileList_vslot_74 */

void CMenuFileList_vslot_74(int *param_1,int param_2)

{
  if (param_1[0x22] != param_2) {
    (**(code **)(*param_1 + 0x54))(param_1,1);
  }
  param_1[0x22] = param_2;
  return;
}

