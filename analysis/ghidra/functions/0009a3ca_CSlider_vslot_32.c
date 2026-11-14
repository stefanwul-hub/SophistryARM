/* 0009a3ca CSlider_vslot_32 */

undefined4 CSlider_vslot_32(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x80);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return 1;
}

