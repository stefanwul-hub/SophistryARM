/* 00028716 FUN_00028716 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00028716(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  short sVar1;
  short sVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  char *local_20 [4];
  
  FUN_000a6446(param_1,param_2);
  *param_1 = &PTR_SynthEditor_c_vslot_0_000e7428;
  param_1[8] = &PTR_LAB_000e74e4;
  puVar5 = param_1 + 0x15;
  iVar7 = 0x4fe;
  do {
    FUN_0000b1ea(puVar5);
    puVar5 = puVar5 + 0x1a;
    iVar7 = iVar7 + -1;
  } while (iVar7 != -2);
  FUN_0002e178(param_1 + 0x9775);
  puVar5 = param_1 + 0x977a;
  iVar7 = 0x3e;
  do {
    FUN_00080824(puVar5);
    puVar5 = puVar5 + 0x1a;
    iVar7 = iVar7 + -1;
  } while (iVar7 != -2);
  FUN_0009470c(param_1 + 0x9dfa,0x80);
  *(undefined1 *)((int)param_1 + 0x51) = 0;
  param_1[0x9615] = param_3;
  param_1[0x9777] = param_4;
  param_1[0x9778] = param_5;
  iVar7 = 3;
  puVar5 = param_1;
  do {
    puVar5[0x9771] = 0;
    puVar5 = puVar5 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  param_1[0x9776] = 0xffffffff;
  param_1[0x13] = param_2;
  if (DAT_00101ea0 != 0) {
    do {
      cVar3 = FUN_0002ddaa(DAT_00101ea0);
    } while (cVar3 == '\0');
    iVar7 = _OSAtomicAdd32Barrier(1,&DAT_000e2020);
    if (iVar7 == 1) {
      puVar5 = &DAT_00101ec0;
      do {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      } while (puVar5 != (undefined4 *)&DAT_00102824);
    }
    FUN_0002ddc8(DAT_00101ea0);
    uVar4 = FUN_0002645a(param_1,param_1[0x9777]);
    param_1[0xb] = uVar4;
    param_1[0xc] = 0;
    if (-1 < (int)param_1[0x9778]) {
      iVar7 = FUN_0002645a(param_1,param_1[0x9778]);
      param_1[0xc] = iVar7;
      if (iVar7 == 0) {
        return;
      }
    }
    iVar7 = param_1[0xb];
    if (iVar7 != 0) {
      sVar1 = *(short *)(iVar7 + 0xc);
      param_1[0x12] = (int)sVar1;
      sVar2 = *(short *)(iVar7 + 0x10);
      param_1[0x11] = (int)sVar2;
      *(undefined2 *)((int)param_1 + 0xe) = 0;
      *(undefined2 *)(param_1 + 3) = 0;
      *(short *)((int)param_1 + 0x12) = sVar1;
      *(short *)(param_1 + 4) = sVar2;
      *(undefined1 *)(param_1 + 0x9774) = 0;
      *(undefined1 *)((int)param_1 + 0x52) = 1;
      *(undefined1 *)(param_1 + 0xd) = 0xff;
      *(undefined1 *)((int)param_1 + 0x35) = 0xff;
      *(undefined1 *)((int)param_1 + 0x36) = 0xff;
      *(undefined1 *)((int)param_1 + 0x37) = 0xff;
      *(undefined1 *)(param_1 + 0xe) = 0xff;
      *(undefined1 *)((int)param_1 + 0x39) = 0xff;
      *(undefined1 *)((int)param_1 + 0x3a) = 0xff;
      *(undefined1 *)((int)param_1 + 0x3b) = 0xff;
      *(undefined1 *)(param_1 + 0xf) = 0;
      *(undefined1 *)((int)param_1 + 0x3d) = 0;
      *(undefined1 *)((int)param_1 + 0x3e) = 0;
      *(undefined1 *)((int)param_1 + 0x3f) = 0xff;
      *(undefined1 *)(param_1 + 0x10) = 0;
      *(undefined1 *)((int)param_1 + 0x41) = 0;
      *(undefined1 *)((int)param_1 + 0x42) = 0;
      *(undefined1 *)((int)param_1 + 0x43) = 0xff;
      param_1[7] = 0;
      param_1[9] = 0;
      param_1[10] = 0;
      *(undefined1 *)((int)param_1 + 0x51) = 0;
      *(undefined1 *)(param_1 + 0x9756) = 0;
      *(undefined1 *)((int)param_1 + 0x25d59) = 0;
      *(undefined1 *)(param_1 + 0x9770) = 0;
      param_1[0x976f] = 0;
      *(undefined1 *)(param_1 + 0x14) = 1;
      iVar7 = 0;
      puVar5 = param_1;
      puVar6 = param_1;
      do {
        puVar5[0x8215] = 0;
        puVar5[0x8216] = 0;
        puVar5[0x8217] = 0;
        puVar6[0x9115] = iVar7;
        iVar7 = iVar7 + 1;
        puVar5 = puVar5 + 3;
        puVar6 = puVar6 + 1;
      } while (iVar7 != 0x500);
      if (0 < (int)param_1[0x9615]) {
        iVar7 = 0;
        puVar5 = param_1;
        do {
          puVar5[0x22] = 0;
          puVar5[0x24] = 0;
          puVar5[0x25] = 0;
          iVar7 = iVar7 + 1;
          puVar5 = puVar5 + 0x1a;
        } while (iVar7 < (int)param_1[0x9615]);
      }
      iVar7 = 0xc0;
      do {
        param_1[0x9616] = 0;
        param_1 = param_1 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      _strtod("123.4",local_20);
    }
  }
  return;
}

