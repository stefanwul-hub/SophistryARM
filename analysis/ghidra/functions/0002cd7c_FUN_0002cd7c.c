/* 0002cd7c FUN_0002cd7c */

void FUN_0002cd7c(int param_1,int param_2,int param_3,int *param_4,undefined1 param_5)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  if ((0 < param_2) && (param_3 != 0)) {
    *(undefined4 *)(param_1 + 0x298) = 0x80;
    *(int *)(param_1 + 0x29c) = param_2;
    *(int *)(param_1 + 0x2a0) = param_3;
    if (param_4 != (int *)0x0) {
      iVar4 = *param_4;
      if (iVar4 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = 0;
        iVar3 = param_1;
        do {
          *(int *)(iVar3 + 0x52c) = iVar4;
          iVar1 = iVar1 + 1;
          iVar4 = param_4[iVar1];
          if (iVar4 == 0) break;
          iVar3 = iVar3 + 4;
        } while (iVar1 != 0x10);
      }
      *(undefined4 *)(param_1 + 0x52c + iVar1 * 4) = 0;
    }
    *(undefined1 *)(param_1 + 0x570) = param_5;
    pvVar2 = _malloc(*(int *)(param_1 + 0x298) * 4 + 0xc);
    *(void **)(param_1 + 0x2a4) = pvVar2;
    if ((pvVar2 != (void *)0x0) && (0 < *(int *)(param_1 + 0x298))) {
      iVar4 = 0;
      do {
        *(undefined4 *)(*(int *)(param_1 + 0x2a4) + iVar4 * 4) = *(undefined4 *)(param_1 + 0x2a0);
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 0x298));
    }
  }
  return;
}

