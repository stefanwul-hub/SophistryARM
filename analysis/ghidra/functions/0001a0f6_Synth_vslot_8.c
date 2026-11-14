/* 0001a0f6 Synth_vslot_8 */

void Synth_vslot_8(int param_1,int param_2)

{
  size_t sVar1;
  void *pvVar2;
  
  if (0 < *(int *)(param_1 + 0xcfc0)) {
    if (*(void **)(param_1 + 0x79ac) != (void *)0x0) {
      _free(*(void **)(param_1 + 0x79ac));
    }
    *(undefined4 *)(param_1 + 0x79ac) = 0;
    if (*(void **)(param_1 + 0x79b0) != (void *)0x0) {
      _free(*(void **)(param_1 + 0x79b0));
    }
    *(undefined4 *)(param_1 + 0x79b0) = 0;
    sVar1 = param_2 * 4 + 0x44;
    pvVar2 = _malloc(sVar1);
    *(void **)(param_1 + 0x79ac) = pvVar2;
    pvVar2 = _malloc(sVar1);
    *(void **)(param_1 + 0x79b0) = pvVar2;
  }
  *(int *)(param_1 + 0x10) = param_2;
  return;
}

