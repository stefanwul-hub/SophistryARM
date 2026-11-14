/* 000068b0 CMenuWithSub_vslot_99 */

char * CMenuWithSub_vslot_99(int param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_2 * *(int *)(param_1 + 0x104) + *(int *)(param_1 + 0x100));
  pcVar1 = _strchr(pcVar2,0x24);
  if (pcVar1 != (char *)0x0) {
    pcVar1 = pcVar1 + -(int)pcVar2;
  }
  return pcVar1;
}

