/* 000208d4 Synth_vslot_169 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_169(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char local_15c [332];
  
  if ((((*(char *)((int)param_1 + 0xcfd5) == '\0') || (param_2 == param_1[0x33f8])) &&
      (-1 < param_3)) &&
     ((param_3 < param_1[0x2694] && (iVar3 = param_1[0x33f8], iVar3 == param_2)))) {
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    iVar4 = param_1[0x33ec] + -1;
    if (iVar3 <= param_1[0x33ec] + -1) {
      iVar4 = iVar3;
    }
    if (param_3 < *(int *)(param_1[0xe3e] + 0x528 + iVar4 * 0x574)) {
      iVar3 = 0;
      do {
        local_15c[iVar3] = '\0';
        iVar3 = iVar3 + 1;
      } while (iVar3 != 0x140);
      piVar1 = param_1 + 0x169;
      Envelope_c_vslot_9(piVar1,iVar4,1,param_3);
      pcVar2 = (char *)FUN_0002ca94(iVar4 * 0x574 + param_1[0xe3e],param_3);
      if (pcVar2 != (char *)0x0) {
        _strcpy(local_15c,pcVar2);
      }
      Envelope_c_vslot_17(piVar1,iVar4,0xe,local_15c);
      (**(code **)(*param_1 + 0x364))(param_1,iVar4,piVar1,0xe);
      if ((param_1[0xe3c] == 0) && (iVar4 == param_1[0x33f8])) {
        Envelope_c_vslot_9(piVar1,iVar4,1,param_3);
        iVar3 = Envelope_c_vslot_12(piVar1,param_1[0x33f8],1);
        param_1[7] = iVar3;
      }
      (**(code **)(*param_1 + 700))(param_1);
      return;
    }
  }
  return;
}

