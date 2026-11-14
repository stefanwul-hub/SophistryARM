/* 0001898a Kaja_c_vslot_238 */

int Kaja_c_vslot_238(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_10;
  
  local_10 = param_3 + 1;
  if (0 < *(int *)(param_1 + 0xcfb0)) {
    iVar5 = 0;
    iVar2 = param_1 + 0x5a4;
    do {
      iVar3 = Envelope_c_vslot_12(iVar2,iVar5,4);
      iVar1 = local_10;
      if ((iVar3 == 0) && (iVar5 != param_2)) {
        iVar3 = Envelope_c_vslot_12(iVar2,iVar5,0x13);
        iVar4 = Envelope_c_vslot_12(iVar2,iVar5,0x14);
        if (((iVar3 != 0) || (iVar4 != 0x7f)) &&
           (((iVar3 <= param_3 && (param_3 < iVar4)) && (iVar1 = iVar3, local_10 <= iVar3)))) {
          iVar1 = local_10;
        }
      }
      local_10 = iVar1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)(param_1 + 0xcfb0));
  }
  return local_10;
}

