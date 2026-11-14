/* 0000ce94 Instrument_c_vslot_17 */

void Instrument_c_vslot_17(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int local_34;
  undefined4 local_24 [6];
  
  if (param_1[1] != 0) {
    param_1[0x6d8] = 0;
    iVar4 = Envelope_c_vslot_12(param_1[1] + 0x5a4,param_1[0x69],3);
    iVar1 = *(int *)(param_1[1] + 0xcfb4);
    if (iVar4 < iVar1 + *(int *)(param_1[1] + 0xcfb8)) {
      cVar3 = FUN_0002ddfc(param_1 + 0x387);
      if (cVar3 != '\0') {
        if (iVar4 < iVar1) {
          _memcpy(local_24,(void *)(param_2 + iVar4 * 8),param_1[0x6c] << 2);
        }
        else {
          iVar2 = param_1[0x6c];
          if (0 < iVar2) {
            iVar5 = 0;
            do {
              local_24[iVar5] = *(undefined4 *)(param_2 + ((iVar2 + -1) * iVar1 + iVar4) * 4);
              iVar5 = iVar5 + 1;
            } while (iVar5 < iVar2);
          }
        }
        for (local_34 = 0; local_34 < param_1[0x3ae]; local_34 = local_34 + 1) {
          while( true ) {
            iVar1 = param_1[local_34 * 2 + 0x87];
            if (iVar1 <= param_1[0x6d8]) break;
            (**(code **)(*param_1 + 0xac))(param_1,local_24,iVar1 - param_1[0x6d8]);
            param_1[0x6d8] = iVar1;
            if (param_1[0x3ae] <= local_34) goto LAB_0000cf90;
          }
          (**(code **)(*param_1 + 0x54))(param_1,param_1 + local_34 * 2 + 0x88,1);
        }
LAB_0000cf90:
        if (param_1[0x6d8] < param_3) {
          (**(code **)(*param_1 + 0xac))(param_1,local_24,param_3 - param_1[0x6d8]);
        }
        param_1[0x3ae] = 0;
        FUN_0002de1a(param_1 + 0x387);
        return;
      }
    }
  }
  return;
}

