/* 00014aaa NoteFreqTable_c_vslot_56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void NoteFreqTable_c_vslot_56(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  double local_7c [13];
  
  _memcpy(local_7c,&DAT_000e1860,0x60);
  if (*(int *)(param_1 + 0x124) != 0) {
    iVar2 = FUN_00010422(*(int *)(param_1 + 0x124) + 0xe0);
    *(int *)(param_1 + 0x1d4) = iVar2;
    if (iVar2 != 0) {
      if (param_2 == '\0') {
        iVar2 = 0;
        do {
          iVar1 = *(int *)(param_1 + 0x1d4);
          lVar3 = (longdouble)_pow(0,0x40000000,(double)iVar2 * 0.083333333333333);
          *(float *)(iVar1 + iVar2 * 4) = (float)((double)lVar3 * 8.175798915643707);
          iVar2 = iVar2 + 1;
        } while (iVar2 != 0x81);
        FUN_00010e34();
        return;
      }
      iVar2 = 0;
      do {
        iVar1 = *(int *)(param_1 + 0x1d4);
        lVar3 = (longdouble)
                _pow(0,0x40000000,((double)iVar2 + local_7c[iVar2 % 0xc] * 0.01) * 0.083333333333333
                    );
        *(float *)(iVar1 + iVar2 * 4) = (float)((double)lVar3 * 8.175798915643707);
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x81);
      FUN_00010e34();
      return;
    }
  }
  return;
}

