/* 0002e9fe FUN_0002e9fe */

undefined1 FUN_0002e9fe(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  byte bVar2;
  undefined1 uVar3;
  void *pvVar4;
  int iVar5;
  undefined1 local_1c [16];
  
  pvVar4 = _malloc(param_4 * 2 + 2);
  if (pvVar4 == (void *)0x0) {
    return 0;
  }
  if (0 < param_4) {
    iVar5 = 0;
    do {
      bVar2 = *(byte *)(iVar5 + param_3);
      local_1c[0] = 0x30;
      local_1c[1] = 0x31;
      local_1c[2] = 0x32;
      local_1c[3] = 0x33;
      local_1c[4] = 0x34;
      local_1c[5] = 0x35;
      local_1c[6] = 0x36;
      local_1c[7] = 0x37;
      local_1c[8] = 0x38;
      local_1c[9] = 0x39;
      local_1c[10] = 0x41;
      local_1c[0xb] = 0x42;
      local_1c[0xc] = 0x43;
      local_1c[0xd] = 0x44;
      local_1c[0xe] = 0x45;
      local_1c[0xf] = 0x46;
      puVar1 = (undefined1 *)((int)pvVar4 + iVar5 * 2);
      *puVar1 = local_1c[bVar2 >> 4];
      local_1c[0] = 0x30;
      local_1c[1] = 0x31;
      local_1c[2] = 0x32;
      local_1c[3] = 0x33;
      local_1c[4] = 0x34;
      local_1c[5] = 0x35;
      local_1c[6] = 0x36;
      local_1c[7] = 0x37;
      local_1c[8] = 0x38;
      local_1c[9] = 0x39;
      local_1c[10] = 0x41;
      local_1c[0xb] = 0x42;
      local_1c[0xc] = 0x43;
      local_1c[0xd] = 0x44;
      local_1c[0xe] = 0x45;
      local_1c[0xf] = 0x46;
      puVar1[1] = local_1c[bVar2 & 0xf];
      iVar5 = iVar5 + 1;
    } while (param_4 != iVar5);
  }
  *(undefined1 *)((int)pvVar4 + param_4 * 2) = 0;
  uVar3 = FUN_0002e63a(param_1,param_2,pvVar4);
  _free(pvVar4);
  return uVar3;
}

