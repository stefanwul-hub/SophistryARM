/* 00026254 FUN_00026254 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00026254(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  float local_24;
  int local_20 [4];
  
  if (*(int *)(param_1 + 0x4c) == 0) {
    return;
  }
  if (param_2 == (int *)0x0) {
    return;
  }
  _OSAtomicAdd32Barrier(1,*(int *)(param_1 + 0x4c) + 0x3b30);
  if (*(char *)((int)param_2 + 0x6d) == '\0') {
    if ((char)param_2[0x1b] == '\0') {
      if (*(char *)((int)param_2 + 0x6e) == '\0') {
        if (param_2[0x2a] - 0xfU < 2) {
          cVar1 = (**(code **)(*param_2 + 0x110))(param_2,local_20,&local_24);
          while (cVar1 != '\0') {
            local_24 = (float)((uint)local_24 & -(uint)(0.0 <= local_24));
            uVar3 = -(uint)(local_24 <= 1.0);
            local_24 = (float)(~uVar3 & (uint)1.0 | (uint)local_24 & uVar3);
            cVar1 = (**(code **)(*param_2 + 0x110))(param_2,local_20,&local_24);
          }
        }
        else {
          while (cVar1 = (**(code **)(*param_2 + 0x110))(param_2,local_20,&local_24), cVar1 != '\0')
          {
            local_24 = (float)((uint)local_24 & -(uint)(0.0 <= local_24));
            uVar3 = -(uint)(local_24 <= 1.0);
            local_24 = (float)(~uVar3 & (uint)1.0 | (uint)local_24 & uVar3);
            (**(code **)(**(int **)(param_1 + 0x4c) + 0x34))
                      (*(int **)(param_1 + 0x4c),
                       *(undefined4 *)(param_1 + 0x24454 + local_20[0] * 4),local_24);
          }
        }
      }
      else {
        (**(code **)(*param_2 + 300))(param_2,local_20);
        iVar2 = (**(code **)(*param_2 + 0xdc))(param_2);
        (**(code **)(**(int **)(param_1 + 0x4c) + 0x36c))
                  (*(int **)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x24454 + iVar2 * 4),
                   local_20[0]);
      }
      goto LAB_00026366;
    }
    iVar2 = (**(code **)(*param_2 + 0xdc))(param_2);
    uVar4 = 0xffffffff;
  }
  else {
    iVar2 = (**(code **)(*param_2 + 0xdc))(param_2);
    uVar4 = 1;
  }
  FUN_0001dd36(*(undefined4 *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x24454 + iVar2 * 4),uVar4)
  ;
LAB_00026366:
  _OSAtomicAdd32Barrier(0xffffffff,*(int *)(param_1 + 0x4c) + 0x3b30);
  return;
}

