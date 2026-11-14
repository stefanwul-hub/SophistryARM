/* 0004d134 Kaja_c_vslot_182 */

void Kaja_c_vslot_182(int param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  undefined1 local_28c [320];
  char local_14c [320];
  
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    _strcpy(local_14c,param_3);
    FUN_0004cbec(param_1);
    FUN_00009996(param_1 + 0x32abd8,param_3,local_28c);
    iVar2 = param_1 + 0x32aa04;
    iVar1 = Envelope_c_vslot_12(iVar2,param_2,0x5a);
    if (iVar1 == 2) {
      FUN_0008dbb8(param_1 + 0x8be40,local_28c,1);
    }
    else if (iVar1 == 3) {
      FUN_00033e52(param_1 + 0x8d9e0,local_28c,0,1);
    }
    else if (iVar1 == 1) {
      FUN_00039de2(param_1 + 0x8a280,local_28c,1);
    }
    iVar1 = Envelope_c_vslot_12(iVar2,param_2,0x5b);
    if (iVar1 == 2) {
      FUN_0008dbb8(param_1 + 0x8c528,local_28c,1);
      iVar1 = Envelope_c_vslot_12(iVar2,param_2,0x66);
    }
    else {
      if (iVar1 == 3) {
        FUN_00033e52(param_1 + 0x97b98,local_28c,0,1);
      }
      else if (iVar1 == 1) {
        FUN_00039de2(param_1 + 0x8a970,local_28c,1);
      }
      iVar1 = Envelope_c_vslot_12(iVar2,param_2,0x66);
    }
    if (iVar1 == 1) {
      FUN_00039de2(param_1 + 0x8b060,local_28c,1);
      iVar2 = Envelope_c_vslot_12(iVar2,param_2,0x67);
    }
    else {
      if (iVar1 == 2) {
        FUN_0008dbb8(param_1 + 0x8cc10,local_28c,1);
      }
      iVar2 = Envelope_c_vslot_12(iVar2,param_2,0x67);
    }
    if (iVar2 == 1) {
      FUN_00039de2(param_1 + 0x8b750,local_28c,1);
    }
    else if (iVar2 == 2) {
      FUN_0008dbb8(param_1 + 0x8d2f8,local_28c,1);
    }
    Synth_vslot_182(param_1,param_2,local_14c);
    return;
  }
  return;
}

