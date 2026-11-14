/* 00003624 LPAUSynth_vslot_78 */

void LPAUSynth_vslot_78(int param_1)

{
  int iVar1;
  int local_1028;
  int *local_1020;
  int local_101c [1028];
  
  local_1028 = 0;
  local_1020 = local_101c;
  if (*(int *)(param_1 + 0x32b408) != *(int *)(param_1 + 0x32b40c)) {
    do {
      iVar1 = *(int *)(param_1 + 0x32b408) * 0x20 + *(int *)(param_1 + 0x32b414);
      if (iVar1 == 0) break;
      local_1020[2] = iVar1;
      local_1028 = local_1028 + 1;
      _CompareAndSwap(*(undefined4 *)(param_1 + 0x32b408),
                      *(int *)(param_1 + 0x32b408) + 1U & *(uint *)(param_1 + 0x32b410),
                      param_1 + 0x32b408);
      local_1020 = local_1020 + 1;
    } while (*(int *)(param_1 + 0x32b408) != *(int *)(param_1 + 0x32b40c));
  }
  if (local_1028 != 0) {
    local_101c[0] = local_1028;
    local_101c[1] = 0;
    Synth_vslot_78(param_1 + 0xec,local_101c);
  }
  return;
}

