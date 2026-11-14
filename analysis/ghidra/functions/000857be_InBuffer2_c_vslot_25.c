/* 000857be InBuffer2_c_vslot_25 */

void InBuffer2_c_vslot_25(int param_1)

{
  size_t sVar1;
  void *pvVar2;
  
  sVar1 = *(int *)(param_1 + 0x30) * 4;
  if (*(char *)(param_1 + 0x26) == '\0') {
    if (*(char *)(param_1 + 0x27) == '\0') {
      if (*(char *)(param_1 + 0x28) == '\0') {
        return;
      }
      if ((*(char *)(param_1 + 0x29) != '\0') || (*(char *)(param_1 + 0x2a) != '\0')) {
        _memcpy(*(void **)(param_1 + 0x38),*(void **)(param_1 + 0xc),sVar1);
      }
      if (*(char *)(param_1 + 0x2a) != '\0') {
        _memcpy(*(void **)(param_1 + 0x40),*(void **)(param_1 + 0xc),sVar1);
      }
      _memcpy(*(void **)(param_1 + 0x34),*(void **)(param_1 + 0xc),sVar1);
      _memcpy(*(void **)(param_1 + 0x3c),*(void **)(param_1 + 0xc),sVar1);
      _memcpy(*(void **)(param_1 + 0x44),*(void **)(param_1 + 0xc),sVar1);
      _memcpy(*(void **)(param_1 + 0x48),*(void **)(param_1 + 0xc),sVar1);
      _memcpy(*(void **)(param_1 + 0x4c),*(void **)(param_1 + 0xc),sVar1);
      pvVar2 = *(void **)(param_1 + 0x50);
    }
    else {
      if (*(char *)(param_1 + 0x29) != '\0') {
        _memcpy(*(void **)(param_1 + 0x38),*(void **)(param_1 + 0xc),sVar1);
      }
      _memcpy(*(void **)(param_1 + 0x34),*(void **)(param_1 + 0xc),sVar1);
      pvVar2 = *(void **)(param_1 + 0x3c);
    }
  }
  else {
    pvVar2 = *(void **)(param_1 + 0x34);
  }
  _memcpy(pvVar2,*(void **)(param_1 + 0xc),sVar1);
  return;
}

