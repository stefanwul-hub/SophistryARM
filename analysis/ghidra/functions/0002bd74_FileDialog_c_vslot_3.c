/* 0002bd74 FileDialog_c_vslot_3 */

void FileDialog_c_vslot_3(int param_1,char *param_2)

{
  char cVar1;
  void *pvVar2;
  char *pcVar3;
  uint uVar4;
  
  if (param_2 != (char *)0x0) {
    pvVar2 = *(void **)(param_1 + 0x58);
    if (pvVar2 != *(void **)(param_1 + 0x54)) {
      if (pvVar2 != (void *)0x0) {
        _free(pvVar2);
      }
      *(undefined4 *)(param_1 + 0x58) = 0;
    }
    uVar4 = 0xffffffff;
    pcVar3 = param_2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar3 = (char *)_malloc(uVar4 + 1);
    *(char **)(param_1 + 0x58) = pcVar3;
    if (pcVar3 == (char *)0x0) {
      *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x54);
      return;
    }
    _strncpy(pcVar3,param_2,uVar4 - 1);
    pcVar3[uVar4 - 1] = '\0';
  }
  return;
}

