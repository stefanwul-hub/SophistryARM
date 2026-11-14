/* 0009a398 CSlider_vslot_31 */

undefined4 CSlider_vslot_31(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x80);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  return 1;
}

