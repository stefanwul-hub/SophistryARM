/* 00020ac2 Synth_vslot_168 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_168(int *param_1,int param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char local_15c [332];
  
  if ((param_3 < 0x7f) && (iVar4 = param_1[0x33f8], iVar4 == param_2)) {
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    iVar5 = param_1[0x33ec] + -1;
    if (iVar4 <= param_1[0x33ec] + -1) {
      iVar5 = iVar4;
    }
    iVar4 = iVar5 * 0x574;
    if ((int)param_3 < *(int *)(param_1[0xe3d] + 0x528 + iVar4)) {
      iVar2 = 0;
      do {
        local_15c[iVar2] = '\0';
        iVar2 = iVar2 + 1;
      } while (iVar2 != 0x140);
      piVar1 = param_1 + 0x169;
      Envelope_c_vslot_9(piVar1,iVar5,0x12,param_3);
      Envelope_c_vslot_9(piVar1,iVar5,1,0);
      pcVar3 = (char *)FUN_0002ca94(iVar4 + param_1[0xe3d],param_3);
      if (pcVar3 != (char *)0x0) {
        _strcpy(local_15c,pcVar3);
      }
      FUN_0002d328(iVar4 + param_1[0xe3e],local_15c,0);
      if (*(int *)(iVar4 + param_1[0xe3e] + 0x528) < 1) {
        (**(code **)(*param_1 + 0x350))(param_1);
      }
      else {
        iVar4 = FUN_0002ca94(iVar4 + param_1[0xe3e],0);
        if (iVar4 != 0) {
          Envelope_c_vslot_17(piVar1,iVar5,0xe,iVar4);
          (**(code **)(*param_1 + 0x364))(param_1,iVar5,piVar1,0xe);
          Envelope_c_vslot_9(piVar1,param_1[0x33f8],1,0);
          iVar4 = Envelope_c_vslot_12(piVar1,param_1[0x33f8],1);
          param_1[7] = iVar4;
        }
      }
      if (iVar5 == param_1[0x33f8]) {
        param_1[0x2c] = param_3;
      }
    }
  }
  return;
}

