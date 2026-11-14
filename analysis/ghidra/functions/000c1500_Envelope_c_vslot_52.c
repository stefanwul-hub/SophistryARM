/* 000c1500 Envelope_c_vslot_52 */

void Envelope_c_vslot_52(undefined4 param_1,int *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_2;
  *puVar1 = param_3;
  *param_2 = (int)(puVar1 + 1);
  return;
}

