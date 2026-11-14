/* 000186c4 Kaja_c_vslot_225 */

undefined4 Kaja_c_vslot_225(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + 0x9a78);
  cVar1 = *pcVar2;
  if ((((cVar1 == pcVar2[1]) && (cVar1 == pcVar2[2])) && (cVar1 == pcVar2[3])) && (cVar1 == '0')) {
    return 1;
  }
  return 0;
}

