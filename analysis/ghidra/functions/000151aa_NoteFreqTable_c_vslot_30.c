/* 000151aa NoteFreqTable_c_vslot_30 */

void NoteFreqTable_c_vslot_30(int *param_1,int param_2,int param_3)

{
  int iVar1;
  char local_14c [320];
  
  Envelope_c_vslot_30(param_1,param_2,param_3);
  if ((((param_1[0x48] != 0) && (-1 < param_2)) && (param_2 < 0x20)) &&
     (iVar1 = FUN_00011b72(param_1[0x48],param_2), iVar1 != 0)) {
    if ((param_3 == -1) || (param_3 == 3)) {
      FUN_00010aee(iVar1 + 0x150,local_14c);
      FUN_00014e50(param_1,local_14c);
      FUN_00014d00(param_1);
    }
    if (param_3 == 4) {
      FUN_00010aee(iVar1 + 0x1c0,local_14c);
      if (local_14c[0] != '\0') {
        FUN_00010e34(iVar1 + 0x150,local_14c);
        (**(code **)(*param_1 + 0x78))(param_1,param_2,3);
      }
    }
  }
  return;
}

