/* 00098a64 CSlider_vslot_68 */

void CSlider_vslot_68(int param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x7c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(int **)(param_1 + 0x7c) = param_2;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 0xc))(param_2);
    *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0xc);
    *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x10);
  }
  return;
}

