/* 00026e72 SynthEditor_c_vslot_38 */

void SynthEditor_c_vslot_38(int param_1)

{
  char cVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_e;
  undefined1 local_d;
  
  if ((*(int *)(param_1 + 0x28) != 0) && (*(int *)(param_1 + 0x4c) != 0)) {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x1c) + 0xbc))
                      (*(int **)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24));
    if (cVar1 == '\0') {
      if (*(int *)(param_1 + 0x2c) == 0) {
        return;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        return;
      }
      local_d = 0;
      (**(code **)(**(int **)(param_1 + 0x1c) + 0xb4))
                (*(int **)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x28),&local_d);
      *(int *)(param_1 + 0x48) = (int)*(short *)(*(int *)(param_1 + 0x2c) + 0xc);
      *(int *)(param_1 + 0x44) = (int)*(short *)(*(int *)(param_1 + 0x2c) + 0x10);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0xac))
                (*(int **)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24));
      *(undefined1 *)(param_1 + 0x25dd0) = 0;
    }
    else {
      if (*(int *)(param_1 + 0x30) == 0) {
        return;
      }
      if (*(int *)(param_1 + 0x28) == 0) {
        return;
      }
      local_e = 0;
      (**(code **)(**(int **)(param_1 + 0x1c) + 0xb4))
                (*(int **)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x24),&local_e);
      *(int *)(param_1 + 0x48) = (int)*(short *)(*(int *)(param_1 + 0x30) + 0xc);
      *(int *)(param_1 + 0x44) = (int)*(short *)(*(int *)(param_1 + 0x30) + 0x10);
      (**(code **)(**(int **)(param_1 + 0x1c) + 0xac))
                (*(int **)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x28));
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x118))
                (*(int **)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x48),
                 *(undefined4 *)(param_1 + 0x44));
      local_14 = *(undefined4 *)(param_1 + 0x44);
      local_18 = *(undefined4 *)(param_1 + 0x48);
      local_20 = 0;
      local_1c = 0;
      (**(code **)(**(int **)(param_1 + 0x1c) + 0x60))(*(int **)(param_1 + 0x1c),&local_20);
      *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0xe) + *(short *)(param_1 + 0x48);
      *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0xc) + *(short *)(param_1 + 0x44);
      *(undefined1 *)(param_1 + 0x25dd0) = 1;
    }
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x54))(*(int **)(param_1 + 0x1c),1);
  }
  return;
}

