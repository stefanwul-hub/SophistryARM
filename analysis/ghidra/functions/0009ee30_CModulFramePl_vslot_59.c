/* 0009ee30 CModulFramePl_vslot_59 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int * CModulFramePl_vslot_59(int param_1,int *param_2,char param_3)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int local_24;
  int local_20;
  
  if (*(int *)(param_1 + 0x28) != 0) {
    local_24 = *param_2 - *(int *)(param_1 + 8);
    local_20 = param_2[1] - *(int *)(param_1 + 0xc);
    for (piVar3 = *(int **)(param_1 + 0x40); piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
      piVar1 = (int *)*piVar3;
      if ((((piVar1 != (int *)0x0) && (piVar1[6] <= local_24)) && (local_24 <= piVar1[8])) &&
         ((piVar1[7] <= local_20 && (local_20 <= piVar1[9])))) {
        if (param_3 == '\0') {
          return piVar1;
        }
        cVar2 = (**(code **)(*piVar1 + 0xa4))(piVar1,"CViewContainer");
        if (cVar2 == '\0') {
          return piVar1;
        }
        piVar3 = (int *)(**(code **)(*piVar1 + 0xec))(piVar1,&local_24,1);
        return piVar3;
      }
    }
  }
  return (int *)0x0;
}

