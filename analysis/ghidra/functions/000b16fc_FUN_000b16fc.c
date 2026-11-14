/* 000b16fc FUN_000b16fc */

undefined4 FUN_000b16fc(int param_1,FILE *param_2)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar1 = *(ushort *)(param_1 + 0x21a);
  if (uVar1 == 0x18) {
    iVar5 = 3;
  }
  else if (uVar1 < 0x19) {
    if (uVar1 == 8) {
      iVar5 = 1;
    }
    else {
      if (uVar1 != 0x10) goto LAB_000b172a;
      iVar5 = 2;
    }
  }
  else if (uVar1 == 0x20) {
    iVar5 = 4;
  }
  else {
    if (uVar1 != 0x40) {
LAB_000b172a:
      _fclose(param_2);
      return 0xffffff6a;
    }
    if (*(char *)(param_1 + 0x231) == '\0') {
      _fclose(param_2);
      return 0xffffff69;
    }
    iVar5 = 8;
  }
  iVar3 = *(int *)(param_1 + 0x228) / (int)((uint)*(ushort *)(param_1 + 0x216) * iVar5);
  *(int *)(param_1 + 0x22c) = iVar3;
  iVar3 = FUN_00013124(param_1,iVar3);
  *(int *)(param_1 + 0x21c) = iVar3;
  if (iVar3 == 0) {
    _fclose(param_2);
    uVar4 = 0xffffff5e;
  }
  else if (*(short *)(param_1 + 0x216) == 1) {
    cVar2 = FUN_000aedb0(param_1,param_2,*(undefined4 *)(param_1 + 0x22c),iVar5);
    if (cVar2 != '\0') {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x22c) = 0;
    if (*(int *)(param_1 + 0x21c) != 0) {
      _free(*(void **)(param_1 + 0x21c));
      *(undefined4 *)(param_1 + 0x21c) = 0;
    }
    if (*(int *)(param_1 + 0x220) != 0) {
      *(undefined4 *)(param_1 + 0x22c) = 0;
      _free(*(void **)(param_1 + 0x220));
      *(undefined4 *)(param_1 + 0x220) = 0;
    }
    *(undefined4 *)(param_1 + 0x22c) = 0;
    *(undefined1 *)(param_1 + 0x214) = 0;
    *(undefined1 *)(param_1 + 0x230) = 0;
    *(undefined1 *)(param_1 + 0x231) = 0;
    *(undefined1 *)(param_1 + 0x232) = 0;
    *(undefined1 *)(param_1 + 600) = 0;
    *(undefined1 *)(param_1 + 0x260) = 0;
    *(undefined1 *)(param_1 + 0x233) = 0;
    *(undefined1 *)(param_1 + 0x234) = 0;
    _fclose(param_2);
    uVar4 = 0xffffff56;
  }
  else {
    if (*(short *)(param_1 + 0x216) != 2) {
      return 0;
    }
    iVar3 = FUN_00013124(param_1,*(undefined4 *)(param_1 + 0x22c));
    *(int *)(param_1 + 0x220) = iVar3;
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x22c) = 0;
      if (*(int *)(param_1 + 0x21c) != 0) {
        _free(*(void **)(param_1 + 0x21c));
        *(undefined4 *)(param_1 + 0x21c) = 0;
      }
      if (*(int *)(param_1 + 0x220) != 0) {
        *(undefined4 *)(param_1 + 0x22c) = 0;
        _free(*(void **)(param_1 + 0x220));
        *(undefined4 *)(param_1 + 0x220) = 0;
      }
      *(undefined4 *)(param_1 + 0x22c) = 0;
      *(undefined1 *)(param_1 + 0x214) = 0;
      *(undefined1 *)(param_1 + 0x230) = 0;
      *(undefined1 *)(param_1 + 0x231) = 0;
      *(undefined1 *)(param_1 + 0x232) = 0;
      *(undefined1 *)(param_1 + 600) = 0;
      *(undefined1 *)(param_1 + 0x260) = 0;
      *(undefined1 *)(param_1 + 0x233) = 0;
      *(undefined1 *)(param_1 + 0x234) = 0;
      _fclose(param_2);
      uVar4 = 0xffffff5c;
    }
    else {
      cVar2 = FUN_000aef4c(param_1,param_2,*(undefined4 *)(param_1 + 0x22c),iVar5);
      if (cVar2 != '\0') {
        return 0;
      }
      *(undefined4 *)(param_1 + 0x22c) = 0;
      if (*(int *)(param_1 + 0x21c) != 0) {
        _free(*(void **)(param_1 + 0x21c));
        *(undefined4 *)(param_1 + 0x21c) = 0;
      }
      if (*(int *)(param_1 + 0x220) != 0) {
        *(undefined4 *)(param_1 + 0x22c) = 0;
        _free(*(void **)(param_1 + 0x220));
        *(undefined4 *)(param_1 + 0x220) = 0;
      }
      *(undefined4 *)(param_1 + 0x22c) = 0;
      *(undefined1 *)(param_1 + 0x214) = 0;
      *(undefined1 *)(param_1 + 0x230) = 0;
      *(undefined1 *)(param_1 + 0x231) = 0;
      *(undefined1 *)(param_1 + 0x232) = 0;
      *(undefined1 *)(param_1 + 600) = 0;
      *(undefined1 *)(param_1 + 0x260) = 0;
      *(undefined1 *)(param_1 + 0x233) = 0;
      *(undefined1 *)(param_1 + 0x234) = 0;
      _fclose(param_2);
      uVar4 = 0xffffff55;
    }
  }
  return uVar4;
}

