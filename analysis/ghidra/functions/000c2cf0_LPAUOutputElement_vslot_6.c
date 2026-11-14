/* 000c2cf0 LPAUOutputElement_vslot_6 */

size_t LPAUOutputElement_vslot_6(int param_1,void *param_2,undefined1 *param_3)

{
  undefined4 *puVar1;
  size_t sVar2;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (*(int *)(param_1 + 0x78) == 0) {
    sVar2 = 0;
  }
  else {
    sVar2 = *(size_t *)(*(int *)(param_1 + 0x78) + 0xc);
  }
  if (param_2 != (void *)0x0) {
    puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x78) + 8);
    local_2c = *puVar1;
    local_28 = puVar1[1];
    local_24 = puVar1[2];
    local_20 = puVar1[3];
    local_1c = puVar1[4];
    local_18 = puVar1[5];
    local_14 = puVar1[6];
    local_10 = puVar1[7];
    _memcpy(param_2,&local_2c,sVar2);
  }
  *param_3 = 0;
  return sVar2;
}

