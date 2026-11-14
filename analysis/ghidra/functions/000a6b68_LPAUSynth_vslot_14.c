/* 000a6b68 LPAUSynth_vslot_14 */

undefined4 LPAUSynth_vslot_14(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  
  if (param_2 == 0) {
    return 0xffffffce;
  }
  do {
    puVar3 = *(undefined4 **)(param_1 + 0x8c);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)_malloc(0x10);
      break;
    }
    cVar2 = _CompareAndSwap(puVar3,*puVar3,(int *)(param_1 + 0x8c));
  } while (cVar2 == '\0');
  puVar3[1] = 0;
  puVar3[2] = param_2;
  puVar3[3] = param_3;
  do {
    uVar1 = *(undefined4 *)(param_1 + 0x88);
    *puVar3 = uVar1;
    cVar2 = _CompareAndSwap(uVar1,puVar3,(undefined4 *)(param_1 + 0x88));
  } while (cVar2 == '\0');
  return 0;
}

