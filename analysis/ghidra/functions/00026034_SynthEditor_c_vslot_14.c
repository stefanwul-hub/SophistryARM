/* 00026034 SynthEditor_c_vslot_14 */

undefined1 SynthEditor_c_vslot_14(int param_1,undefined4 *param_2)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  
  piVar1 = *(int **)(param_1 + 0x4c);
  if ((piVar1 != (int *)0x0) &&
     (cVar2 = (**(code **)(*piVar1 + 0x32c))(piVar1,6,*param_2,*(undefined2 *)(param_2 + 1),0),
     cVar2 != '\0')) {
    return 1;
  }
  uVar3 = AEffGUIEditor_vslot_14(param_1,param_2);
  return uVar3;
}

