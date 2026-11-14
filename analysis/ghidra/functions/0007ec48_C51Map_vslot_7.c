/* 0007ec48 C51Map_vslot_7 */

void C51Map_vslot_7(int *param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int local_28;
  int local_24;
  int local_20 [4];
  
  FUN_00001bd4(param_1);
  uVar2 = FUN_0009cba2(param_2);
  local_28 = 0;
  local_24 = 0;
  (**(code **)(*param_1 + 0x84))(param_1,param_2,&local_28);
  *(undefined1 *)(param_1 + 0x1b) = 0;
  *(undefined1 *)((int)param_1 + 0x6d) = 0;
  local_20[0] = -1;
  if ((uVar2 & 0x10) == 0) {
    while ((uVar2 & 5) != 0) {
      if (local_20[0] == -1) {
        (**(code **)(*param_1 + 0x13c))(param_1,&local_28,local_20);
        FUN_00001ca6(param_1,*(undefined4 *)(param_1[0x24] + local_20[0] * 0x48));
        FUN_00001ca6(param_1,*(undefined4 *)(local_20[0] * 0x48 + param_1[0x24] + 0x18));
        param_1[0x34] =
             (int)(*(float *)(local_20[0] * 0x48 + 0xc + param_1[0x24]) -
                  (float)(local_28 - (param_1[0x2e] / 2 + param_1[2])) * (float)param_1[0x32]);
        param_1[0x35] =
             (int)(*(float *)(local_20[0] * 0x48 + 0x24 + param_1[0x24]) -
                  (float)(local_24 - (param_1[0x2f] / 2 + param_1[3])) * (float)param_1[0x33]);
      }
      cVar1 = (**(code **)(*param_1 + 0x140))(param_1,&local_28,local_20[0]);
      if (cVar1 != '\0') {
        (*(code *)**(undefined4 **)param_1[0x25])((undefined4 *)param_1[0x25],param_2,param_1);
      }
      (**(code **)(*param_1 + 0xac))(param_1);
      uVar2 = FUN_0009cba2(param_2);
      (**(code **)(*param_1 + 0x84))(param_1,param_2,&local_28);
    }
  }
  else {
    (**(code **)(*param_1 + 0x13c))(param_1,&local_28,local_20);
    *(undefined4 *)(param_1[0x24] + 4 + local_20[0] * 0x48) = 0x3f000000;
    *(undefined4 *)(local_20[0] * 0x48 + param_1[0x24] + 0x1c) = 0x3f000000;
    (*(code *)**(undefined4 **)param_1[0x25])((undefined4 *)param_1[0x25],param_2,param_1);
  }
  if (local_20[0] != -1) {
    FUN_00001c10(param_1,*(undefined4 *)(param_1[0x24] + local_20[0] * 0x48));
    FUN_00001c10(param_1,*(undefined4 *)(local_20[0] * 0x48 + param_1[0x24] + 0x18));
  }
  return;
}

