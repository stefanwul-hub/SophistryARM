/* 0001788c Synth_vslot_96 */

void Synth_vslot_96(int param_1)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = *(char **)(param_1 + 0x9a7c);
  if (pcVar1 == (char *)0x0) {
    do {
      pcVar1 = (char *)((int)pcVar1 * 10);
    } while ((int)pcVar1 < 1000);
  }
  else {
    if (9 < (byte)(*pcVar1 - 0x30U)) {
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    iVar2 = 0;
    do {
      iVar2 = *pcVar1 + -0x30 + iVar2 * 10;
    } while (iVar2 < 1000);
  }
  return;
}

