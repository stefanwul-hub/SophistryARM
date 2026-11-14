/* 00070abe FUN_00070abe */

void FUN_00070abe(int param_1,char param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_14;
  
  iVar5 = *(int *)(param_1 + 0x758);
  if (1 < iVar5) {
    cVar2 = -1;
    iVar3 = 0;
    local_14 = -1;
    iVar4 = param_1;
    do {
      cVar1 = *(char *)(iVar4 + 0x318);
      if ((cVar1 < *(char *)(param_1 + 0x75c)) && (cVar2 < cVar1)) {
        local_14 = iVar3;
        cVar2 = cVar1;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x1c;
    } while (iVar5 != iVar3);
    if (local_14 == -1) {
      if (0 < *(int *)(param_1 + 0x310)) {
        iVar5 = iVar5 * 0x1c + 0x2f4 + param_1;
        *(undefined1 *)(param_1 + 0x75c) = *(undefined1 *)(iVar5 + 8);
        *(undefined1 *)(param_1 + 0x75d) = *(undefined1 *)(iVar5 + 9);
        *(undefined4 *)(param_1 + 0x760) = *(undefined4 *)(iVar5 + 0xc);
        *(undefined1 *)(param_1 + 0x768) = *(undefined1 *)(iVar5 + 0x14);
        *(undefined4 *)(param_1 + 0x76c) = *(undefined4 *)(iVar5 + 0x18);
        *(undefined4 *)(param_1 + 0x770) = *(undefined4 *)(iVar5 + 0x1c);
        *(undefined4 *)(param_1 + 0x774) = *(undefined4 *)(iVar5 + 0x20);
        *(int *)(param_1 + 0x310) = *(int *)(param_1 + 0x310) + -1;
        return;
      }
      *(undefined4 *)(param_1 + 0x790) = 0;
      if (param_2 == '\0') {
        *(undefined1 *)(param_1 + 0x75c) = *(undefined1 *)(param_1 + 0x318);
        *(undefined1 *)(param_1 + 0x75d) = *(undefined1 *)(param_1 + 0x319);
        *(undefined4 *)(param_1 + 0x760) = *(undefined4 *)(param_1 + 0x31c);
        iVar5 = param_1 + 800;
      }
      else {
        *(undefined1 *)(param_1 + 0x75c) = *(undefined1 *)(param_1 + 0x334);
        *(undefined1 *)(param_1 + 0x75d) = *(undefined1 *)(param_1 + 0x335);
        *(undefined4 *)(param_1 + 0x760) = *(undefined4 *)(param_1 + 0x338);
        iVar5 = param_1 + 0x33c;
      }
    }
    else {
      iVar5 = local_14 * 0x1c + 0x310 + param_1;
      *(undefined1 *)(param_1 + 0x75c) = *(undefined1 *)(iVar5 + 8);
      *(undefined1 *)(param_1 + 0x75d) = *(undefined1 *)(iVar5 + 9);
      *(undefined4 *)(param_1 + 0x760) = *(undefined4 *)(iVar5 + 0xc);
      iVar5 = iVar5 + 0x10;
    }
    *(undefined1 *)(param_1 + 0x768) = *(undefined1 *)(iVar5 + 4);
    *(undefined4 *)(param_1 + 0x76c) = *(undefined4 *)(iVar5 + 8);
    *(undefined4 *)(param_1 + 0x770) = *(undefined4 *)(iVar5 + 0xc);
    *(undefined4 *)(param_1 + 0x774) = *(undefined4 *)(iVar5 + 0x10);
  }
  return;
}

