/* 0001c80a FUN_0001c80a */

void FUN_0001c80a(int param_1,void *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int local_20;
  int local_1c;
  
  if ((*(void **)(param_1 + 0x8abc) != (void *)0x0) && (*(int *)(param_1 + 0x8ac0) != 0)) {
    _memset(*(void **)(param_1 + 0x8abc),0,*(int *)(param_1 + 0x9a48) << 5);
    if (0 < *(int *)(param_1 + 0x9a48)) {
      iVar6 = 0;
      do {
        iVar3 = 0;
        iVar5 = iVar6 << 4;
        do {
          *(undefined4 *)(iVar5 + *(int *)(param_1 + 0x8ac0)) = 0xffffffff;
          iVar3 = iVar3 + 1;
          iVar5 = iVar5 + 4;
        } while (iVar3 != 4);
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(param_1 + 0x9a48));
    }
    _memcpy(*(void **)(param_1 + 0x8abc),param_2,*(int *)(param_1 + 0x9a48) << 5);
    if (0 < *(int *)(param_1 + 0x9a48)) {
      local_1c = 0;
      do {
        iVar6 = *(int *)(param_1 + 0x8abc);
        iVar1 = local_1c * 0x20 + iVar6;
        iVar3 = *(int *)(iVar1 + 0x18);
        iVar5 = *(int *)(iVar1 + 0xc);
        iVar1 = *(int *)(iVar1 + 0x14);
        if (((iVar1 != 0) && (*(int *)(param_1 + 0x8ac0) != 0)) && (0 < *(int *)(param_1 + 0x9a48)))
        {
          iVar4 = 0;
          while( true ) {
            iVar6 = iVar4 * 0x20 + iVar6;
            if (((iVar1 == *(int *)(iVar6 + 0x14)) && (iVar5 == *(int *)(iVar6 + 0xc))) &&
               ((iVar3 == *(int *)(iVar6 + 0x18) && (local_1c != iVar4)))) {
              piVar7 = (int *)(iVar4 * 0x10 + *(int *)(param_1 + 0x8ac0));
              local_20 = 0;
              piVar2 = piVar7;
              while (-1 < *piVar2) {
                local_20 = local_20 + 1;
                piVar2 = piVar2 + 1;
                if (local_20 == 4) goto LAB_0001c95b;
              }
              piVar7[local_20] = local_1c;
            }
            iVar4 = iVar4 + 1;
            if (*(int *)(param_1 + 0x9a48) <= iVar4) break;
            iVar6 = *(int *)(param_1 + 0x8abc);
          }
        }
LAB_0001c95b:
        local_1c = local_1c + 1;
      } while (local_1c < *(int *)(param_1 + 0x9a48));
    }
  }
  return;
}

