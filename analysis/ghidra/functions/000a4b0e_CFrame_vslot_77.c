/* 000a4b0e CFrame_vslot_77 */

undefined4 CFrame_vslot_77(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x94);
  if (piVar2 == (int *)0x0) {
    uVar1 = *(undefined4 *)(param_1 + 100);
    piVar2 = (int *)operator_new(0x68);
    FUN_000a171a(piVar2,param_1,0,uVar1);
  }
  else {
    (**(code **)(*piVar2 + 0xc))(piVar2);
    piVar2 = *(int **)(param_1 + 0x94);
  }
  if (piVar2 != (int *)0x0) {
    FUN_0009ea10(piVar2,param_2);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return 1;
}

