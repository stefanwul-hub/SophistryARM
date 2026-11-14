/* 000a605c SynthEditor_c_vslot_8 */

void SynthEditor_c_vslot_8(int param_1,short *param_2)

{
  int *piVar1;
  undefined1 local_84 [104];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  piVar1 = *(int **)(param_1 + 0x1c);
  if (piVar1 != (int *)0x0) {
    if (param_2 == (short *)0x0) {
      (**(code **)(*piVar1 + 0x160))(piVar1,0);
      return;
    }
    local_10 = (int)param_2[2];
    local_14 = (int)param_2[3];
    local_18 = (int)*param_2;
    local_1c = (int)param_2[1];
    FUN_000a171a(local_84,piVar1,0,*(undefined4 *)(param_1 + 8));
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x14))(*(int **)(param_1 + 0x1c),local_84,&local_1c);
    CDrawContext_vslot_0(local_84);
  }
  return;
}

