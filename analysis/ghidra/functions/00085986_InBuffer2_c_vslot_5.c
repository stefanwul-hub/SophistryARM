/* 00085986 InBuffer2_c_vslot_5 */

void InBuffer2_c_vslot_5(int *param_1,int param_2)

{
  if (((char)param_1[9] != '\0') && (param_2 <= param_1[7])) {
    param_1[0xb] = param_2;
    if (*(char *)((int)param_1 + 0x25) == '\0') {
      if (param_1[8] != 0) {
        (**(code **)(*param_1 + 100))(param_1);
      }
    }
    else {
      (**(code **)(*param_1 + 0x60))(param_1);
    }
    param_1[0xc] = param_2;
    *(undefined1 *)((int)param_1 + 0x26) = 0;
    *(undefined1 *)((int)param_1 + 0x27) = 0;
    *(undefined1 *)(param_1 + 10) = 0;
    *(undefined1 *)((int)param_1 + 0x29) = 0;
    *(undefined1 *)((int)param_1 + 0x2a) = 0;
    param_1[8] = 0;
  }
  return;
}

