/* 000c3736 Phaser1SR_c_vslot_62 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Phaser1SR_c_vslot_62(int *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (param_2 - (float)param_1[0x26a]) * (float)param_1[0x289];
  param_1[0x268] = (int)fVar1;
  fVar2 = (param_3 - (float)param_1[0x26b]) * (float)param_1[0x289];
  param_1[0x269] = (int)fVar2;
  fVar1 = fVar1 + fVar1 * fVar1 * fVar1 * -0.16666667;
  param_1[0x268] = (int)fVar1;
  param_1[0x269] = (int)(fVar2 + fVar2 * fVar2 * fVar2 * -0.16666667);
  (**(code **)(*param_1 + 0xcc))
            (param_1,param_1 + 0x266,
             ((float)param_1[0x284] * fVar1 + (float)param_1[0x26c]) * (float)param_1[0x285]);
                    /* WARNING: Could not recover jumptable at 0x000c3834. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xcc))();
  return;
}

