/* 000267f6 FUN_000267f6 */

void FUN_000267f6(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int *param_6,undefined4 param_7,undefined4 param_8,int param_9,
                 int param_10,int param_11,int param_12)

{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_1c = param_9;
  local_18 = param_10;
  local_14 = param_9 + param_11;
  local_10 = param_10 + param_12;
  pvVar1 = operator_new(0x778);
  FUN_00002598(pvVar1,&local_1c,param_1 + 0x20,param_3,*(undefined4 *)(param_1 + 0x4c));
  *(undefined1 *)((int)pvVar1 + 0x6e) = 1;
  *(undefined1 *)((int)pvVar1 + 0x70) = 1;
  *(undefined4 *)((int)pvVar1 + 0xb4) = param_4;
  *(undefined4 *)((int)pvVar1 + 0xb8) = param_5;
  iVar4 = *param_6;
  if (iVar4 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    pvVar2 = pvVar1;
    do {
      *(int *)((int)pvVar2 + 0xc0) = iVar4;
      iVar3 = iVar3 + 1;
      iVar4 = param_6[iVar3];
      if (iVar4 == 0) break;
      pvVar2 = (void *)((int)pvVar2 + 4);
    } while (iVar3 != 0x10);
  }
  *(undefined4 *)((int)pvVar1 + iVar3 * 4 + 0xc0) = 0;
  FileDialog_c_vslot_3((int)pvVar1 + 0xb0,param_7);
  *(undefined4 *)((int)pvVar1 + 0xbc) = param_8;
  FUN_000266ca(param_1,pvVar1,param_3,param_2);
  return;
}

