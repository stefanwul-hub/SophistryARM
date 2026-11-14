/* 00025864 SynthEditor_c_vslot_21 */

void SynthEditor_c_vslot_21(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined1 *)(param_1 + 0x51) = 0;
  *(undefined1 *)(param_1 + 0x25d58) = 0;
  *(undefined1 *)(param_1 + 0x25d59) = 0;
  *(undefined1 *)(param_1 + 0x25dc0) = 0;
  *(undefined4 *)(param_1 + 0x25dbc) = 0;
  *(undefined1 *)(param_1 + 0x50) = 1;
  iVar2 = 0;
  iVar1 = param_1;
  iVar3 = param_1;
  do {
    *(undefined4 *)(iVar1 + 0x20854) = 0;
    *(undefined4 *)(iVar1 + 0x20858) = 0;
    *(undefined4 *)(iVar1 + 0x2085c) = 0;
    *(int *)(iVar3 + 0x24454) = iVar2;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0xc;
    iVar3 = iVar3 + 4;
  } while (iVar2 != 0x500);
  if (0 < *(int *)(param_1 + 0x25854)) {
    iVar3 = 0;
    iVar1 = param_1;
    do {
      *(undefined4 *)(iVar1 + 0x88) = 0;
      *(undefined4 *)(iVar1 + 0x90) = 0;
      *(undefined4 *)(iVar1 + 0x94) = 0;
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0x68;
    } while (iVar3 < *(int *)(param_1 + 0x25854));
  }
  iVar1 = 0xc0;
  do {
    *(undefined4 *)(param_1 + 0x25858) = 0;
    param_1 = param_1 + 4;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

