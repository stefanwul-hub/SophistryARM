/* 000c14e4 Envelope_c_vslot_51 */

void Envelope_c_vslot_51(undefined4 param_1,undefined4 *param_2,float param_3)

{
  float *pfVar1;
  
  pfVar1 = (float *)*param_2;
  *pfVar1 = param_3 + *pfVar1;
  *param_2 = pfVar1 + 1;
  return;
}

