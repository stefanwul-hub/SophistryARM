/* 00085906 InBuffer2_c_vslot_24 */

void InBuffer2_c_vslot_24(int param_1)

{
  size_t sVar1;
  char cVar2;
  void *pvVar3;
  
  sVar1 = *(int *)(param_1 + 0x30) * 4;
  if (*(char *)(param_1 + 0x27) == '\0') {
    if (*(char *)(param_1 + 0x28) != '\0') {
      if ((*(char *)(param_1 + 0x29) == '\0') && (*(char *)(param_1 + 0x2a) == '\0')) {
        cVar2 = *(char *)(param_1 + 0x2a);
      }
      else {
        _memcpy(*(void **)(param_1 + 0x38),*(void **)(param_1 + 0xc),sVar1);
        cVar2 = *(char *)(param_1 + 0x2a);
      }
      if (cVar2 != '\0') {
        pvVar3 = *(void **)(param_1 + 0x40);
        goto LAB_0008594e;
      }
    }
  }
  else if (*(char *)(param_1 + 0x29) != '\0') {
    pvVar3 = *(void **)(param_1 + 0x38);
LAB_0008594e:
    _memcpy(pvVar3,*(void **)(param_1 + 0xc),sVar1);
    return;
  }
  return;
}

