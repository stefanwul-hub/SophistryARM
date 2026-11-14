/* 0003b636 Gator_c_vslot_62 */

void Gator_c_vslot_62(undefined4 param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  
  if (param_2 != (char *)0x0) {
    uVar2 = 0xffffffff;
    pcVar3 = param_2;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (0 < (int)(~uVar2 - 1)) {
      iVar4 = 0;
      do {
        param_2[iVar4] = (param_2[iVar4] != '1') + '0';
        iVar4 = iVar4 + 1;
      } while (~uVar2 - 1 != iVar4);
    }
  }
  return;
}

