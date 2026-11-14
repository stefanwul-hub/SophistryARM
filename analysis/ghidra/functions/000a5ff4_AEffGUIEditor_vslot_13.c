/* 000a5ff4 AEffGUIEditor_vslot_13 */

undefined4 AEffGUIEditor_vslot_13(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x1c);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1,param_2), iVar2 == 1))
  {
    return 1;
  }
  return 0;
}

