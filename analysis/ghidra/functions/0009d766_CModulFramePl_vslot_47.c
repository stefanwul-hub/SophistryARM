/* 0009d766 CModulFramePl_vslot_47 */

undefined4 CModulFramePl_vslot_47(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x3c);
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    while( true ) {
      if (param_2 == iVar1) {
        return 1;
      }
      piVar2 = (int *)piVar2[1];
      if (piVar2 == (int *)0x0) break;
      iVar1 = *piVar2;
    }
  }
  return 0;
}

