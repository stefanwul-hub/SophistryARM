/* 00070c94 FUN_00070c94 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int FUN_00070c94(int param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iStack_38;
  int iStack_34;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  
  iVar5 = *(int *)(param_1 + 0x758);
  if ((iVar5 == 0) || (10 < *(uint *)(param_1 + 0x314))) {
    *(undefined1 *)(param_1 + 0x75c) = 0xff;
    return param_1;
  }
  iVar4 = *(int *)(&DAT_00070cd8 + *(int *)(param_1 + 0x314) * 4) + 0x70ca2;
  switch(*(int *)(param_1 + 0x314)) {
  case 0:
    *(undefined1 *)(param_1 + 0x75c) = 0xff;
    break;
  case 1:
    if (0 < iVar5) {
      iStack_38 = 0x80;
      iVar6 = 0;
      iStack_28 = -1;
      iVar4 = param_1;
      do {
        cVar2 = *(char *)(iVar4 + 0x318);
        if ((*(char *)(param_1 + 0x75c) < cVar2) && (cVar2 < iStack_38)) {
          iStack_38 = (int)cVar2;
          iStack_28 = iVar6;
        }
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + 0x1c;
      } while (iVar5 != iVar6);
      if (iStack_28 != -1) {
        iStack_28 = iStack_28 * 0x1c;
        goto code_r0x00070f2f;
      }
    }
    goto code_r0x00071020;
  case 2:
    if (0 < iVar5) {
      iStack_34 = 0x80;
      iVar6 = 0;
      iStack_24 = -1;
      iVar4 = param_1;
      do {
        cVar2 = *(char *)(iVar4 + 0x318);
        if ((*(char *)(param_1 + 0x75c) < cVar2) && (cVar2 < iStack_34)) {
          iStack_34 = (int)cVar2;
          iStack_24 = iVar6;
        }
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + 0x1c;
      } while (iVar5 != iVar6);
      if (iStack_24 != -1) {
        iStack_28 = iStack_24 * 0x1c;
        goto code_r0x00070f2f;
      }
    }
code_r0x00071020:
    *(undefined1 *)(param_1 + 0x75c) = *(undefined1 *)(param_1 + 0x318);
    *(undefined1 *)(param_1 + 0x75d) = *(undefined1 *)(param_1 + 0x319);
    *(undefined4 *)(param_1 + 0x760) = *(undefined4 *)(param_1 + 0x31c);
    *(undefined1 *)(param_1 + 0x768) = *(undefined1 *)(param_1 + 0x324);
    *(undefined4 *)(param_1 + 0x76c) = *(undefined4 *)(param_1 + 0x328);
    *(undefined4 *)(param_1 + 0x770) = *(undefined4 *)(param_1 + 0x32c);
    *(undefined4 *)(param_1 + 0x774) = *(undefined4 *)(param_1 + 0x330);
    iVar5 = *(int *)(param_1 + 0x310) + 1;
    iVar4 = iVar5 / *(int *)(param_1 + 0x30c);
    *(int *)(param_1 + 0x310) = iVar5 % *(int *)(param_1 + 0x30c);
    break;
  case 3:
    if (0 < iVar5) {
      cVar2 = -1;
      iVar6 = 0;
      iStack_20 = -1;
      iVar4 = param_1;
      do {
        cVar1 = *(char *)(iVar4 + 0x318);
        if ((cVar1 < *(char *)(param_1 + 0x75c)) && (cVar2 < cVar1)) {
          iStack_20 = iVar6;
          cVar2 = cVar1;
        }
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + 0x1c;
      } while (iVar5 != iVar6);
      if (iStack_20 != -1) {
        iStack_28 = iStack_20 * 0x1c;
        goto code_r0x00070f2f;
      }
    }
    iVar5 = iVar5 * 0x1c + 0x2f4 + param_1;
    *(undefined1 *)(param_1 + 0x75c) = *(undefined1 *)(iVar5 + 8);
    *(undefined1 *)(param_1 + 0x75d) = *(undefined1 *)(iVar5 + 9);
    *(undefined4 *)(param_1 + 0x760) = *(undefined4 *)(iVar5 + 0xc);
    *(undefined1 *)(param_1 + 0x768) = *(undefined1 *)(iVar5 + 0x14);
    *(undefined4 *)(param_1 + 0x76c) = *(undefined4 *)(iVar5 + 0x18);
    *(undefined4 *)(param_1 + 0x770) = *(undefined4 *)(iVar5 + 0x1c);
    *(undefined4 *)(param_1 + 0x774) = *(undefined4 *)(iVar5 + 0x20);
    iVar5 = *(int *)(param_1 + 0x30c);
    iVar6 = iVar5 + *(int *)(param_1 + 0x310) + -1;
    iVar4 = iVar6 / iVar5;
    *(int *)(param_1 + 0x310) = iVar6 % iVar5;
    break;
  default:
    if (iVar5 != 1) {
      if (*(int *)(param_1 + 0x790) == 0) {
        iVar5 = FUN_0007091a(param_1,1);
        return iVar5;
      }
      iVar5 = FUN_00070abe(param_1,1);
      return iVar5;
    }
    *(undefined1 *)(param_1 + 0x75c) = *(undefined1 *)(param_1 + 0x318);
    *(undefined1 *)(param_1 + 0x75d) = *(undefined1 *)(param_1 + 0x319);
    *(undefined4 *)(param_1 + 0x760) = *(undefined4 *)(param_1 + 0x31c);
    *(undefined1 *)(param_1 + 0x768) = *(undefined1 *)(param_1 + 0x324);
    *(undefined4 *)(param_1 + 0x76c) = *(undefined4 *)(param_1 + 0x328);
    *(undefined4 *)(param_1 + 0x770) = *(undefined4 *)(param_1 + 0x32c);
    *(undefined4 *)(param_1 + 0x774) = *(undefined4 *)(param_1 + 0x330);
    iVar5 = *(int *)(param_1 + 0x30c);
    if (iVar5 < 2) {
      return iVar5;
    }
    if (*(int *)(param_1 + 0x790) != 0) {
      iVar5 = *(int *)(param_1 + 0x310);
      if (iVar5 < 1) {
        *(undefined4 *)(param_1 + 0x790) = 0;
        *(int *)(param_1 + 0x310) = iVar5 + 1;
        return iVar5 + 1;
      }
code_r0x000712db:
      *(int *)(param_1 + 0x310) = iVar5 + -1;
      return iVar5 + -1;
    }
    iVar4 = *(int *)(param_1 + 0x310);
    if (iVar5 + -1 <= iVar4) {
      *(undefined4 *)(param_1 + 0x790) = 1;
      *(int *)(param_1 + 0x310) = iVar4 + -1;
      return iVar4 + -1;
    }
    goto code_r0x000711c4;
  case 5:
  case 7:
    if (iVar5 != 1) {
      if (*(int *)(param_1 + 0x790) == 0) {
        iVar5 = FUN_0007091a(param_1,0);
        return iVar5;
      }
      iVar5 = FUN_00070abe(param_1,0);
      return iVar5;
    }
    *(undefined1 *)(param_1 + 0x75c) = *(undefined1 *)(param_1 + 0x318);
    *(undefined1 *)(param_1 + 0x75d) = *(undefined1 *)(param_1 + 0x319);
    *(undefined4 *)(param_1 + 0x760) = *(undefined4 *)(param_1 + 0x31c);
    *(undefined1 *)(param_1 + 0x768) = *(undefined1 *)(param_1 + 0x324);
    *(undefined4 *)(param_1 + 0x76c) = *(undefined4 *)(param_1 + 0x328);
    *(undefined4 *)(param_1 + 0x770) = *(undefined4 *)(param_1 + 0x32c);
    *(undefined4 *)(param_1 + 0x774) = *(undefined4 *)(param_1 + 0x330);
    iVar5 = *(int *)(param_1 + 0x30c);
    if (iVar5 < 2) {
      return iVar5;
    }
    if (*(int *)(param_1 + 0x790) != 0) {
      iVar5 = *(int *)(param_1 + 0x310);
      if (iVar5 < 1) {
        *(undefined4 *)(param_1 + 0x790) = 0;
        return iVar5;
      }
      goto code_r0x000712db;
    }
    iVar4 = *(int *)(param_1 + 0x310);
    if (iVar5 + -1 <= iVar4) {
      *(undefined4 *)(param_1 + 0x790) = 1;
      return iVar5 + -1;
    }
code_r0x000711c4:
    iVar4 = iVar4 + 1;
    *(int *)(param_1 + 0x310) = iVar4;
    break;
  case 8:
    iVar4 = FUN_0002e30a();
    iVar5 = (iVar4 % iVar5) * 0x1c + 0x310 + param_1;
    *(undefined1 *)(param_1 + 0x75c) = *(undefined1 *)(iVar5 + 8);
    *(undefined1 *)(param_1 + 0x75d) = *(undefined1 *)(iVar5 + 9);
    *(undefined4 *)(param_1 + 0x760) = *(undefined4 *)(iVar5 + 0xc);
    *(undefined1 *)(param_1 + 0x768) = *(undefined1 *)(iVar5 + 0x14);
    *(undefined4 *)(param_1 + 0x76c) = *(undefined4 *)(iVar5 + 0x18);
    *(undefined4 *)(param_1 + 0x770) = *(undefined4 *)(iVar5 + 0x1c);
    *(undefined4 *)(param_1 + 0x774) = *(undefined4 *)(iVar5 + 0x20);
    iVar4 = FUN_0002e30a();
    iVar4 = iVar4 % *(int *)(param_1 + 0x30c);
    iVar5 = 0;
    if (-1 < iVar4) {
      iVar5 = iVar4;
    }
    *(int *)(param_1 + 0x310) = iVar5;
    iVar4 = *(int *)(param_1 + 0x30c) + -1;
    if (iVar4 < *(int *)(param_1 + 0x310)) {
      *(int *)(param_1 + 0x310) = iVar4;
    }
    break;
  case 9:
    break;
  case 10:
    iVar5 = *(int *)(param_1 + 0x760) + 0x100;
    iStack_2c = -1;
    iVar6 = 0;
    iVar4 = param_1;
    do {
      if (((-1 < *(char *)(iVar4 + 0x318)) &&
          (iVar3 = *(int *)(iVar4 + 0x31c), *(int *)(param_1 + 0x760) < iVar3)) && (iVar3 < iVar5))
      {
        iVar5 = iVar3;
        iStack_2c = iVar6;
      }
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + 0x1c;
    } while (iVar6 != 0x20);
    if (iStack_2c == -1) {
      *(int *)(param_1 + 0x310) = (*(int *)(param_1 + 0x310) + 1) % *(int *)(param_1 + 0x30c);
      iVar6 = 0;
      iVar4 = param_1;
      do {
        if ((-1 < *(char *)(iVar4 + 0x318)) && (*(int *)(iVar4 + 0x31c) < iVar5)) {
          iVar5 = *(int *)(iVar4 + 0x31c);
          iStack_2c = iVar6;
        }
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + 0x1c;
      } while (iVar6 != 0x20);
      if (iStack_2c == -1) {
        *(undefined1 *)(param_1 + 0x75c) = 0xff;
        return iVar4;
      }
    }
    iStack_28 = iStack_2c * 0x1c;
code_r0x00070f2f:
    iVar5 = iStack_28 + 0x310 + param_1;
    *(undefined1 *)(param_1 + 0x75c) = *(undefined1 *)(iVar5 + 8);
    *(undefined1 *)(param_1 + 0x75d) = *(undefined1 *)(iVar5 + 9);
    *(undefined4 *)(param_1 + 0x760) = *(undefined4 *)(iVar5 + 0xc);
    *(undefined1 *)(param_1 + 0x768) = *(undefined1 *)(iVar5 + 0x14);
    *(undefined4 *)(param_1 + 0x76c) = *(undefined4 *)(iVar5 + 0x18);
    *(undefined4 *)(param_1 + 0x770) = *(undefined4 *)(iVar5 + 0x1c);
    iVar4 = *(int *)(iVar5 + 0x20);
    *(int *)(param_1 + 0x774) = iVar4;
  }
  return iVar4;
}

