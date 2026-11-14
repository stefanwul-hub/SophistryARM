/* 00031abc GloFil_c_vslot_58 */

void GloFil_c_vslot_58(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (((iVar1 != 0) && (piVar2 = *(int **)(param_1 + 0x118), piVar2 != (int *)0x0)) &&
     (*(int *)(iVar1 + 0x20) != 0)) {
    (**(code **)(*piVar2 + 0x18))(piVar2,iVar1,param_2,0,0);
    return;
  }
  return;
}

