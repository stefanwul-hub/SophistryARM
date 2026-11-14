/* 000188c6 Kaja_c_vslot_237 */

int Kaja_c_vslot_237(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_14;
  
  if (*(int *)(param_1 + 0xcfb0) < 1) {
    return param_3 + -1;
  }
  iVar4 = 0;
  iVar1 = param_1 + 0x5a4;
  local_14 = param_3 + -1;
LAB_000188f3:
  do {
    iVar2 = Envelope_c_vslot_12(iVar1,iVar4,4);
    if ((iVar2 == 0) && (iVar4 != param_2)) {
      iVar3 = Envelope_c_vslot_12(iVar1,iVar4,0x13);
      iVar2 = Envelope_c_vslot_12(iVar1,iVar4,0x14);
      if (((iVar3 != 0) || (iVar2 != 0x7f)) && ((param_3 <= iVar2 && (iVar3 < param_3)))) {
        if (iVar2 <= local_14) {
          iVar2 = local_14;
        }
        iVar4 = iVar4 + 1;
        local_14 = iVar2;
        if (*(int *)(param_1 + 0xcfb0) <= iVar4) {
          return iVar2;
        }
        goto LAB_000188f3;
      }
    }
    iVar4 = iVar4 + 1;
    if (*(int *)(param_1 + 0xcfb0) <= iVar4) {
      return local_14;
    }
  } while( true );
}

