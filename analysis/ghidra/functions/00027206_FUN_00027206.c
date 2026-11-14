/* 00027206 FUN_00027206 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00027206(int *param_1,int *param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,uint param_8)

{
  byte bVar1;
  undefined4 uVar2;
  int *piVar3;
  byte bVar4;
  undefined1 local_19d;
  undefined1 local_19c;
  undefined1 local_17d;
  undefined1 local_174 [320];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  bVar4 = (byte)(param_8 >> 0x10);
  bVar1 = (byte)(param_8 >> 8);
  if (param_1[0x13] == 0) {
    return;
  }
  if (param_6 < 1) {
    return;
  }
  if (param_7 < 1) {
    return;
  }
  uVar2 = (**(code **)(*param_2 + 0x24))(param_2);
  local_34 = param_4;
  local_30 = param_5;
  local_2c = param_6 + param_4;
  local_28 = param_7 + param_5;
  piVar3 = (int *)operator_new(0x1bc);
  FUN_0009c750(piVar3,&local_34,param_1 + 8,param_3,"",uVar2,0);
  if (piVar3 != (int *)0x0) {
    param_1[param_3 * 3 + 0x8216] = (int)piVar3;
    param_1[param_3 * 3 + 0x8217] = 0x11;
    (**(code **)(*param_1 + 0x94))(param_1,param_3);
    (**(code **)(*param_2 + 0xac))(param_2,param_1[param_3 * 3 + 0x8216]);
    local_24 = param_4;
    local_20 = param_5;
    if ((param_8 & 0xff) + (uint)bVar1 + (uint)bVar4 < 0x14e) {
      local_19d = 0xff;
      local_19c = 0xf0;
      local_17d = 0xf0;
    }
    else {
      local_19d = 0x28;
      local_19c = 0x14;
      local_17d = 0x14;
    }
    if (param_7 - 10U < 4) {
      (**(code **)(*piVar3 + 0x100))(piVar3,4);
    }
    else {
      (**(code **)(*piVar3 + 0x100))(piVar3,3);
    }
    (**(code **)(*piVar3 + 0x104))
              (piVar3,CONCAT31(CONCAT21((ushort)(param_8 >> 0x10) & 0xff00 | (ushort)bVar4,bVar1),
                               (char)param_8));
    (**(code **)(*piVar3 + 0x108))
              (piVar3,CONCAT21(CONCAT11(local_19d,local_19c),local_17d) | 0xff000000);
    (**(code **)(*piVar3 + 0x114))(piVar3,0);
    (**(code **)(*piVar3 + 0xe8))(piVar3,&local_24);
    FUN_0001d532(param_1[0x13],param_1[param_3 + 0x9115],local_174,0x13f);
    (**(code **)(*piVar3 + 0x130))(piVar3,local_174);
    return;
  }
  return;
}

