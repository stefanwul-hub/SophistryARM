/* 0000e216 Instrument_c_vslot_40 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Instrument_c_vslot_40(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_40;
  undefined *local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  if ((*(int *)(param_1 + 4) != 0) && (*(int *)(param_1 + 0x1ac) != 0)) {
    for (local_40 = 0; local_40 < *(int *)(param_1 + 0x1a8); local_40 = local_40 + 1) {
      while (iVar1 = *(int *)(param_1 + 0x1ac) + local_40 * 0x14, *(int *)(iVar1 + 0x10) == param_2)
      {
        local_2c = *(undefined1 *)(iVar1 + 4);
        local_28 = *(undefined4 *)(iVar1 + 8);
        local_24 = *(undefined4 *)(iVar1 + 0xc);
        local_30 = PTR_DAT_00103814 + 8;
        local_20 = param_2;
        (**(code **)(**(int **)(param_1 + 4) + 0x38c))
                  (*(int **)(param_1 + 4),*(undefined4 *)(param_1 + 0x1a4),&local_30);
        iVar3 = local_40 + 1;
        iVar1 = *(int *)(param_1 + 0x1a8);
        if (iVar3 < iVar1) {
          iVar2 = iVar3 * 0x14;
          do {
            iVar1 = iVar2 + *(int *)(param_1 + 0x1ac);
            *(undefined1 *)(iVar1 + -0x10) = *(undefined1 *)(iVar1 + 4);
            *(undefined4 *)(iVar1 + -0xc) = *(undefined4 *)(iVar1 + 8);
            *(undefined4 *)(iVar1 + -8) = *(undefined4 *)(iVar1 + 0xc);
            *(undefined4 *)(iVar1 + -4) = *(undefined4 *)(iVar1 + 0x10);
            iVar3 = iVar3 + 1;
            iVar1 = *(int *)(param_1 + 0x1a8);
            iVar2 = iVar2 + 0x14;
          } while (iVar3 < iVar1);
        }
        *(int *)(param_1 + 0x1a8) = iVar1 + -1;
        if (*(int *)(param_1 + 0x1a8) <= local_40) {
          return;
        }
      }
    }
  }
  return;
}

