/* 00014756 Instrument_c_vslot_8 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Instrument_c_vslot_8(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (0 < *(int *)(param_1 + 0x114)) {
    iVar4 = 0;
    puVar2 = PTR_DAT_00103808 + 8;
    iVar3 = param_1;
    do {
      while ((piVar1 = *(int **)(iVar3 + 0x14), piVar1 != (int *)0x0 &&
             (*(char *)(param_2 + 0x1b4 + (int)piVar1) != '\0'))) {
        local_28 = *(undefined1 *)(param_3 + 4);
        local_24 = *(undefined4 *)(param_3 + 8);
        local_20 = *(undefined4 *)(param_3 + 0xc);
        local_2c = puVar2;
        (**(code **)(*piVar1 + 0x8c))(piVar1,param_2,&local_2c);
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 4;
        if (*(int *)(param_1 + 0x114) <= iVar4) {
          return;
        }
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar4 < *(int *)(param_1 + 0x114));
  }
  return;
}

