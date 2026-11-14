/* 0001a3ce FUN_0001a3ce */

void FUN_0001a3ce(int *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int local_10;
  
  if ((((param_2 != (char *)0x0) && (param_1[0xe3c] != 0)) && (param_1[0xe3b] != 0)) &&
     (*param_2 != '\0')) {
    iVar1 = FUN_0002d472(param_1[0xe3b],param_2,1);
    iVar2 = FUN_0002d472(param_1[0xe3c],param_2,0);
    param_1[7] = iVar2;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    Envelope_c_vslot_9(param_1 + 0xf3,0,0x1b,iVar1);
    Envelope_c_vslot_9(param_1 + 0xf3,0,0x1a,iVar2);
    if (0 < param_1[0x33ec]) {
      iVar1 = 0;
      local_10 = 0;
      do {
        FUN_0002c9e0(local_10 + param_1[0xe3d]);
        FUN_0002c9e0(local_10 + param_1[0xe3e]);
        Envelope_c_vslot_9(param_1 + 0x169,iVar1,0x12,0);
        Envelope_c_vslot_9(param_1 + 0x169,iVar1,1,0);
        iVar1 = iVar1 + 1;
        local_10 = local_10 + 0x574;
      } while (iVar1 < param_1[0x33ec]);
    }
    if (*(char *)((int)param_1 + 0xcfda) != '\0') {
      (**(code **)(*param_1 + 0x350))(param_1);
                    /* WARNING: Could not recover jumptable at 0x0001a4bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 700))();
      return;
    }
  }
  return;
}

