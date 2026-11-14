/* 0001acca Kaja_c_vslot_245 */

void Kaja_c_vslot_245(int param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 local_14;
  undefined4 local_10 [2];
  
  piVar1 = *(int **)(param_1 + 0x36bc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xe4))(piVar1);
    cVar2 = FUN_0001ab48(param_1,local_10,&local_14);
    if (cVar2 != '\0') {
      (**(code **)(**(int **)(param_1 + 0x36bc) + 0xe0))
                (*(int **)(param_1 + 0x36bc),local_10[0],local_14);
      return;
    }
  }
  return;
}

