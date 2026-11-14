/* 0001af7a Synth_vslot_158 */

void Synth_vslot_158(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int local_10;
  
  _OSAtomicAdd32Barrier(1,param_1 + 0x33f9);
  piVar1 = param_1 + 0xf3;
  iVar3 = Envelope_c_vslot_12(piVar1,0,0xb);
  param_1[0x33ed] = iVar3;
  iVar3 = Envelope_c_vslot_12(piVar1,0,0xc);
  param_1[0x33ee] = iVar3;
  if (0 < param_1[0xee2]) {
    local_10 = 0;
    piVar4 = param_1;
    do {
      if (((piVar4[0x144c] != 0) && ((int *)piVar4[0x1447] != (int *)0x0)) &&
         (piVar2 = *(int **)piVar4[0x1447], piVar2 != (int *)0x0)) {
        (**(code **)(*piVar2 + 0x10))(piVar2);
      }
      local_10 = local_10 + 1;
      piVar4 = piVar4 + 7;
    } while (local_10 < param_1[0xee2]);
  }
  Envelope_c_vslot_9(piVar1,0,0xb,param_1[0x33ed]);
  Envelope_c_vslot_9(piVar1,0,0xc,param_1[0x33ee]);
  _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0x33f9);
                    /* WARNING: Could not recover jumptable at 0x0001b09b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x3c8))();
  return;
}

