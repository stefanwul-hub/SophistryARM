/* 000068e6 CMenuWithSub_vslot_100 */

int CMenuWithSub_vslot_100(int param_1,int param_2,int param_3,size_t param_4)

{
  if ((*(int *)(param_1 + 0x114 + *(int *)(param_1 + 0xda4) * 4) != 0) && (0 < (int)param_4)) {
    _strncpy((char *)(*(int *)(param_1 + 0x114 + param_2 * 4) + 0xe8),
             (char *)(param_3 * *(int *)(param_1 + 0x104) + *(int *)(param_1 + 0x100)),param_4);
    *(undefined1 *)(param_4 + 0xe8 + *(int *)(param_1 + 0x114 + param_2 * 4)) = 0;
    return *(int *)(param_1 + 0x114 + param_2 * 4) + 0xe8;
  }
  return 0;
}

