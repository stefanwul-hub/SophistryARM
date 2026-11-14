/* 0004e68e Kaja_c_vslot_68 */

undefined4 Kaja_c_vslot_68(undefined *param_1,undefined4 param_2,int *param_3)

{
  undefined *puVar1;
  int iVar2;
  
  if (param_3 == (int *)0x0) {
    return 0;
  }
  if (param_3[1] == 2) {
    if (*param_3 != 1) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0xcfbc) = 2;
    iVar2 = 0x20;
    puVar1 = param_1;
    do {
      "*.MOD"[(int)(puVar1 + 5)] = '\x01';
      CControlPl_vslot_32[(int)(puVar1 + 5)] = (code)0x1;
      Synth_vslot_59[(int)(puVar1 + 5)] = (code)0x1;
      AUMIDIBase_vslot_17[(int)(puVar1 + 1)] = (code)0x1;
      puVar1 = &UNK_000139dc + (int)puVar1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (0 < *(int *)(param_1 + 0xcfb0)) {
      iVar2 = 0;
      puVar1 = param_1;
      do {
        puVar1[0xb68c9] = 1;
        puVar1[0xb6add] = 1;
        puVar1[0xb6cf1] = 1;
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 0x14ff4;
      } while (iVar2 < *(int *)(param_1 + 0xcfb0));
    }
  }
  else {
    if (param_3[1] != 6) {
      return 0;
    }
    if (*param_3 != 0xf) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0xcfbc) = 6;
    iVar2 = 0x20;
    puVar1 = param_1;
    do {
      "*.MOD"[(int)(puVar1 + 5)] = '\0';
      CControlPl_vslot_32[(int)(puVar1 + 5)] = (code)0x0;
      Synth_vslot_59[(int)(puVar1 + 5)] = (code)0x0;
      AUMIDIBase_vslot_17[(int)(puVar1 + 1)] = (code)0x0;
      puVar1 = &UNK_000139dc + (int)puVar1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (0 < *(int *)(param_1 + 0xcfb0)) {
      iVar2 = 0;
      puVar1 = param_1;
      do {
        puVar1[0xb68c9] = 0;
        puVar1[0xb6add] = 0;
        puVar1[0xb6cf1] = 0;
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 0x14ff4;
      } while (iVar2 < *(int *)(param_1 + 0xcfb0));
    }
  }
  return 1;
}

