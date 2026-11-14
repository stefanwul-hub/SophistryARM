/* 0007091a FUN_0007091a */

void FUN_0007091a(int param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar4 = *(int *)(param_1 + 0x758);
  if (1 < iVar4) {
    local_10 = 0x80;
    iVar2 = 0;
    local_14 = -1;
    iVar3 = param_1;
    do {
      cVar1 = *(char *)(iVar3 + 0x318);
      if ((*(char *)(param_1 + 0x75c) < cVar1) && (cVar1 < local_10)) {
        local_14 = iVar2;
        local_10 = (int)cVar1;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x1c;
    } while (iVar4 != iVar2);
    if (local_14 == -1) {
      if (*(int *)(param_1 + 0x310) < *(int *)(param_1 + 0x30c) + -1) {
        *(undefined1 *)(param_1 + 0x75c) = *(undefined1 *)(param_1 + 0x318);
        *(undefined1 *)(param_1 + 0x75d) = *(undefined1 *)(param_1 + 0x319);
        *(undefined4 *)(param_1 + 0x760) = *(undefined4 *)(param_1 + 0x31c);
        *(undefined1 *)(param_1 + 0x768) = *(undefined1 *)(param_1 + 0x324);
        *(undefined4 *)(param_1 + 0x76c) = *(undefined4 *)(param_1 + 0x328);
        *(undefined4 *)(param_1 + 0x770) = *(undefined4 *)(param_1 + 0x32c);
        *(undefined4 *)(param_1 + 0x774) = *(undefined4 *)(param_1 + 0x330);
        *(int *)(param_1 + 0x310) = *(int *)(param_1 + 0x310) + 1;
        return;
      }
      *(undefined4 *)(param_1 + 0x790) = 1;
      if (param_2 == '\0') {
        iVar4 = iVar4 * 0x1c + 0x2f4 + param_1;
      }
      else {
        iVar4 = iVar4 * 0x1c + 0x2d8 + param_1;
      }
    }
    else {
      iVar4 = local_14 * 0x1c + 0x310 + param_1;
    }
    *(undefined1 *)(param_1 + 0x75c) = *(undefined1 *)(iVar4 + 8);
    *(undefined1 *)(param_1 + 0x75d) = *(undefined1 *)(iVar4 + 9);
    *(undefined4 *)(param_1 + 0x760) = *(undefined4 *)(iVar4 + 0xc);
    *(undefined1 *)(param_1 + 0x768) = *(undefined1 *)(iVar4 + 0x14);
    *(undefined4 *)(param_1 + 0x76c) = *(undefined4 *)(iVar4 + 0x18);
    *(undefined4 *)(param_1 + 0x770) = *(undefined4 *)(iVar4 + 0x1c);
    *(undefined4 *)(param_1 + 0x774) = *(undefined4 *)(iVar4 + 0x20);
  }
  return;
}

