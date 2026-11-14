/* 000176c2 Kaja_c_vslot_241 */

undefined1 Kaja_c_vslot_241(int param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int local_20;
  char local_11;
  char local_10;
  char local_f;
  char local_e;
  undefined1 local_d;
  
  local_20 = 0;
  iVar2 = *(int *)(param_1 + 0x9a74);
  do {
    uVar3 = 0xffffffff;
    pcVar4 = (char *)(iVar2 + local_20);
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (~uVar3 - 1 < 4) {
      return 0;
    }
    _strncpy(&local_11,(char *)(iVar2 + local_20),4);
    local_d = 0;
    if ((((int)local_11 << 0x18 | (int)local_10 << 0x10 | (int)local_f << 8 | (int)local_e) ==
         param_2) ||
       (param_2 ==
        ((int)local_11 | (int)local_e << 0x18 | (int)local_f << 0x10 | (int)local_10 << 8))) {
      return 1;
    }
    iVar2 = *(int *)(param_1 + 0x9a74);
    if (*(char *)(iVar2 + 4 + local_20) == '\0') {
      return *(undefined1 *)(param_1 + 0xcfd7);
    }
    local_20 = local_20 + 5;
  } while( true );
}

