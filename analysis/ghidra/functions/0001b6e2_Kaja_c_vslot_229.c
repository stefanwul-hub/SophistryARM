/* 0001b6e2 Kaja_c_vslot_229 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Kaja_c_vslot_229(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  undefined1 local_4c [4];
  undefined1 local_48;
  undefined1 local_47;
  undefined2 local_46;
  undefined2 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined *local_34;
  undefined1 local_30;
  undefined1 local_2f;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if ((char)param_1[0x33f3] == '\0') {
    if (*(char *)((int)param_1 + 0xcfc5) == '\0') {
      (**(code **)(*param_1 + 0x338))(param_1);
      (**(code **)(*param_1 + 0x270))(param_1);
      cVar3 = (char)param_1[0x33f3];
    }
    else {
      (**(code **)(*param_1 + 0x270))(param_1);
      cVar3 = (char)param_1[0x33f3];
    }
    if (cVar3 == '\0') {
      return;
    }
  }
  *(undefined1 *)((int)param_1 + 0xcfd1) = 1;
  _OSAtomicAdd32Barrier(1,param_1 + 0xecb);
  uVar2 = (**(code **)(*param_1 + 0x380))(param_1);
  *(undefined1 *)((int)param_1 + 0xcfcd) = uVar2;
  FUN_0001ad2e(param_1);
  FUN_0002b8e2(local_4c);
  while (cVar3 = FUN_0002ba86(param_1 + 0xe29,local_4c), cVar3 != '\0') {
    local_34 = PTR_DAT_00103820 + 8;
    local_30 = local_48;
    local_2f = local_47;
    local_2e = local_46;
    local_2c = local_44;
    local_28 = local_40;
    local_24 = local_3c;
    local_20 = local_38;
    (**(code **)(*param_1 + 0x3cc))(param_1,&local_34);
    HoldData_c_vslot_0(&local_34);
  }
  HoldData_c_vslot_0(local_4c);
  piVar1 = (int *)param_1[0xdaf];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xf8))(piVar1,param_3);
  }
  if (0 < param_1[0x33ec]) {
    iVar4 = 0;
    do {
      piVar1 = *(int **)(param_1[0x33a9] + iVar4 * 4);
      (**(code **)(*piVar1 + 0x48))(piVar1,param_2,param_3);
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_1[0x33ec]);
  }
  iVar4 = param_1[0xed0];
  param_1[0xed0] = param_3 + iVar4;
  if (*(char *)((int)param_1 + 0xcfcd) != '\0') {
    if ((int)((float)(uint)(param_3 + iVar4) * (float)param_1[0xee6]) % 0x2d < 3) {
      if (param_1[0x2698] == -1) {
        iVar4 = _rand();
        param_1[0x2698] = iVar4 % (param_1[0x33ed] + param_1[0x33ee]);
        FUN_0000bc5c(param_1 + 0x319b,param_1[0xee5]);
      }
      (**(code **)(*param_1 + 0x3b0))(param_1,param_2,param_1[0x2698],param_3);
    }
    else {
      param_1[0x2698] = -1;
    }
  }
  _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0xecb);
  *(undefined1 *)((int)param_1 + 0xcfd1) = 0;
  return;
}

