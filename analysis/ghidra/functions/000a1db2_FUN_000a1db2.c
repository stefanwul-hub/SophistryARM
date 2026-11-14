/* 000a1db2 FUN_000a1db2 */

void * FUN_000a1db2(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  piVar1 = *(int **)(param_1 + 0x94);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1);
    return *(void **)(param_1 + 0x94);
  }
  uVar2 = *(undefined4 *)(param_1 + 100);
  pvVar3 = operator_new(0x68);
  FUN_000a171a(pvVar3,param_1,0,uVar2);
  return pvVar3;
}

