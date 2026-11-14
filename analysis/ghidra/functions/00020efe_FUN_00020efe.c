/* 00020efe FUN_00020efe */

void FUN_00020efe(int *param_1,int param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_1[0x33ec] + -1 < param_2) {
    param_2 = param_1[0x33ec] + -1;
  }
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    iVar1 = FUN_0002d472(param_2 * 0x574 + param_1[0xe3d],param_3,1);
    iVar2 = FUN_0002d472(param_2 * 0x574 + param_1[0xe3e],param_3,0);
    iVar3 = 0;
    if (-1 < iVar1) {
      iVar3 = iVar1;
    }
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    piVar4 = param_1 + 0x169;
    Envelope_c_vslot_9(piVar4,param_2,0x12,iVar3,param_1,piVar4);
    Envelope_c_vslot_9(piVar4,param_2,1,iVar2);
    if ((param_1[0xe3c] == 0) && (param_2 == param_1[0x33f8])) {
      Envelope_c_vslot_9(piVar4,param_2,1,iVar2);
      iVar3 = Envelope_c_vslot_12(piVar4,param_1[0x33f8],1);
      param_1[7] = iVar3;
    }
    if (*(char *)((int)param_1 + 0xcfda) != '\0') {
      (**(code **)(*param_1 + 0x350))(param_1);
                    /* WARNING: Could not recover jumptable at 0x0002102a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 700))();
      return;
    }
  }
  return;
}

