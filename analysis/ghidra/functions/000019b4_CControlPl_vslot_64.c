/* 000019b4 CControlPl_vslot_64 */

void CControlPl_vslot_64(int param_1,undefined1 param_2)

{
  if (*(char *)(param_1 + 0x76) == '\0') {
    *(undefined1 *)(param_1 + 0x75) = param_2;
  }
  return;
}

