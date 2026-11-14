/* 0005a1ae FUN_0005a1ae */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0005a1ae(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int local_94;
  int local_90;
  undefined1 local_80 [84];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_94 = 0x1fe;
  local_90 = 0x18;
  do {
    iVar1 = local_90 + -4;
    FUN_00026b74(param_1,param_2,local_94,0x61,local_90 + -1,*(undefined4 *)(param_1 + 0x278c0),1);
    if (param_2 != (int *)0x0) {
      uVar2 = (**(code **)(*param_2 + 0x24))(param_2);
      FUN_00026ff0(param_1,local_94 + 0xd,0x75,iVar1,0x48,10,0x79,local_90,0x40,2,uVar2,
                   *(undefined4 *)(FUN_0002790a + param_1 + 6),param_2);
    }
    if (param_2 != (int *)0x0) {
      uVar2 = (**(code **)(*param_2 + 0x24))(param_2);
      FUN_00026ff0(param_1,local_94 + 0x14,0xc4,iVar1,0x48,10,200,local_90,0x40,2,uVar2,
                   *(undefined4 *)(FUN_0002790a + param_1 + 6),param_2);
    }
    if (param_2 != (int *)0x0) {
      uVar2 = (**(code **)(*param_2 + 0x24))(param_2);
      FUN_00026ff0(param_1,local_94 + 0x1b,0x113,iVar1,0x48,10,0x117,local_90,0x40,2,uVar2,
                   *(undefined4 *)(FUN_0002790a + param_1 + 6),param_2);
    }
    if (param_2 != (int *)0x0) {
      uVar2 = (**(code **)(*param_2 + 0x24))(param_2);
      FUN_00026ff0(param_1,local_94 + 0x22,0x162,iVar1,0x48,10,0x166,local_90,0x40,2,uVar2,
                   *(undefined4 *)(FUN_0002790a + param_1 + 6),param_2);
    }
    if (param_2 != (int *)0x0) {
      uVar2 = (**(code **)(*param_2 + 0x24))(param_2);
      FUN_00026ff0(param_1,local_94 + 0x29,0x1b1,iVar1,0x48,10,0x1b5,local_90,0x40,2,uVar2,
                   *(undefined4 *)(FUN_0002790a + param_1 + 6),param_2);
    }
    local_94 = local_94 + 1;
    local_90 = local_90 + 0xf;
  } while (local_94 != 0x205);
  (**(code **)(*param_2 + 0x24))(param_2);
  _memcpy(local_80,&DAT_000e1ac0,0x54);
  local_2c = 0x1fe;
  local_28 = 0x15;
  local_24 = 0x296;
  local_20 = 0x80;
  pvVar3 = operator_new(0xd8);
  FUN_0007ea14(pvVar3,&local_2c,param_1 + 0x20,0x22e,*(undefined4 *)(param_1 + 0x279b0),7);
  if (pvVar3 != (void *)0x0) {
    FUN_00025a06(param_1,pvVar3,local_80,0x15,param_2);
    *(undefined4 *)(param_1 + 0x22284) = 0xe;
  }
  return;
}

