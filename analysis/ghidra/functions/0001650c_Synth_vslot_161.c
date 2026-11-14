/* 0001650c Synth_vslot_161 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_161(void)

{
  float *pfVar1;
  undefined4 *puVar2;
  float fVar3;
  
  fVar3 = 1e-07;
  pfVar1 = (float *)&DAT_001016a0;
  puVar2 = &DAT_00101aa0;
  do {
    fVar3 = -fVar3;
    *pfVar1 = fVar3;
    *puVar2 = 0x3f800000;
    pfVar1 = pfVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (pfVar1 != (float *)&DAT_00101aa0);
  return;
}

