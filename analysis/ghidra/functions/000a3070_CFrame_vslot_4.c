/* 000a3070 CFrame_vslot_4 */

void CFrame_vslot_4(int param_1,int param_2)

{
  if (*(char *)(param_1 + 0x70) != '\0') {
    *(undefined1 *)(param_1 + 0x70) = 0;
  }
  if (param_2 != 0) {
    CViewContainer_vslot_4();
    return;
  }
  CViewContainer_vslot_4();
  return;
}

