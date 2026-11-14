/* 00003286 LPAUSynth_vslot_74 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 LPAUSynth_vslot_74(undefined4 param_1,char *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar3 = &DAT_000e4ec4;
  do {
    iVar2 = _strcmp((char *)puVar3[-1],param_2);
    if (iVar2 == 0) {
      return (&DAT_000e4ec4)[iVar4 * 2];
    }
    iVar4 = iVar4 + 1;
    piVar1 = puVar3 + 2;
    puVar3 = puVar3 + 2;
  } while (-1 < *piVar1);
  return 0;
}

