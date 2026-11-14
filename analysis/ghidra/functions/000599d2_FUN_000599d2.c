/* 000599d2 FUN_000599d2 */

void FUN_000599d2(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int *local_b8;
  int local_a4;
  int local_90 [32];
  undefined1 local_d;
  
  if (param_1[0x13] == 0) {
    return;
  }
  piVar3 = (int *)FUN_00025e4e(param_1,5);
  local_90[0x10] = 0x1e;
  local_90[0x11] = 0x21;
  local_90[0x12] = 0x24;
  local_90[0x13] = 0x27;
  local_90[0x14] = 0x2a;
  local_90[0x15] = 0x2d;
  local_90[0x16] = 0x30;
  local_90[0x17] = 0x33;
  local_90[0x18] = 0x36;
  local_90[0x19] = 0x39;
  local_90[0x1a] = 0x3c;
  local_90[0x1b] = 0x3f;
  iVar4 = FUN_00025e4e(param_1,0x1d);
  iVar7 = *(int *)(iVar4 + 0x10) - *(int *)(iVar4 + 8);
  iVar4 = FUN_00025e4e(param_1,0x1d);
  local_90[0xf] = *(int *)(iVar4 + 0x14) - *(int *)(iVar4 + 0xc);
  local_b8 = local_90;
  piVar5 = local_b8;
  do {
    *piVar5 = 0;
    piVar5[1] = 0;
    piVar5[2] = 0;
    piVar5[3] = 0;
    piVar5 = piVar5 + 4;
  } while (local_90 + 0x10 != piVar5);
  iVar4 = local_90[0xf] + 0x1f;
  iVar1 = iVar7 + 0x109;
  if (iVar1 < 0x10a) {
    local_90[2] = 0x109;
    local_90[0] = iVar1;
  }
  else {
    local_90[0] = 0x109;
    local_90[2] = iVar1;
  }
  if (iVar4 < 0x20) {
    local_90[3] = 0x1f;
    local_90[1] = iVar4;
  }
  else {
    local_90[1] = 0x1f;
    local_90[3] = iVar4;
  }
  if (iVar1 < 0x10a) {
    local_90[6] = 0x109;
    local_90[4] = iVar1;
  }
  else {
    local_90[4] = 0x109;
    local_90[6] = iVar1;
  }
  if (local_90[0xf] + 0x95 < 0x96) {
    local_90[5] = local_90[0xf] + 0x95;
    local_90[7] = 0x95;
  }
  else {
    local_90[7] = local_90[0xf] + 0x95;
    local_90[5] = 0x95;
  }
  if (iVar7 + 0x1f9 < 0x1fa) {
    local_90[8] = iVar7 + 0x1f9;
    local_90[10] = 0x1f9;
  }
  else {
    local_90[10] = iVar7 + 0x1f9;
    local_90[8] = 0x1f9;
  }
  if (iVar4 < 0x20) {
    local_90[0xb] = 0x1f;
    local_90[9] = iVar4;
  }
  else {
    local_90[9] = 0x1f;
    local_90[0xb] = iVar4;
  }
  if (iVar7 + 0x1f9 < 0x1fa) {
    local_90[0xc] = iVar7 + 0x1f9;
    local_90[0xe] = 0x1f9;
  }
  else {
    local_90[0xe] = iVar7 + 0x1f9;
    local_90[0xc] = 0x1f9;
  }
  if (local_90[0xf] + 0x95 < 0x96) {
    local_90[0xd] = local_90[0xf] + 0x95;
    local_90[0xf] = 0x95;
  }
  else {
    local_90[0xf] = local_90[0xf] + 0x95;
    local_90[0xd] = 0x95;
  }
  local_90[0x1c] = 0;
  local_90[0x1d] = 0;
  local_90[0x1e] = 0;
  local_90[0x1f] = 0;
  local_90[0x1c] = FUN_0001d28c(param_1[0x13],0xd7);
  local_90[0x1d] = FUN_0001d28c(param_1[0x13],0xd8);
  local_90[0x1e] = FUN_0001d28c(param_1[0x13],0xd9);
  local_90[0x1f] = FUN_0001d28c(param_1[0x13],0xda);
  iVar7 = 1;
  iVar4 = param_1[0x9e6d];
  piVar6 = param_1;
  piVar5 = param_1;
  iVar1 = iVar7;
  if (iVar4 == local_90[0x1c]) goto joined_r0x00059c79;
  do {
    piVar5 = piVar6;
    iVar1 = iVar7;
    if (-1 < iVar4) {
      iVar4 = FUN_00025e4e(param_1,local_90[iVar4 + 0x10]);
      if (iVar4 == 0) {
        return;
      }
      local_d = 0;
      (**(code **)(*piVar3 + 0xb4))(piVar3,iVar4,&local_d);
    }
joined_r0x00059c79:
    do {
      iVar7 = iVar1 + 1;
      if (iVar7 == 5) {
        local_a4 = 0;
        piVar5 = param_1;
        do {
          iVar4 = local_90[local_a4 + 0x1c];
          if (iVar4 != piVar5[0x9e6d]) {
            piVar6 = (int *)FUN_00025e4e(param_1,local_90[iVar4 + 0x10]);
            if (piVar6 == (int *)0x0) {
              return;
            }
            (**(code **)(*piVar6 + 0x74))(piVar6,local_b8);
            (**(code **)(*piVar6 + 0x60))(piVar6,local_b8);
            (**(code **)(*piVar3 + 0xac))(piVar3,piVar6);
            *(undefined1 *)(piVar6 + 0xc) = 1;
            *(undefined1 *)(piVar6 + 0x19) = 1;
          }
          piVar5[0x9e6d] = iVar4;
          local_a4 = local_a4 + 1;
          local_b8 = local_b8 + 4;
          piVar5 = piVar5 + 1;
        } while (local_a4 != 4);
        (**(code **)(*param_1 + 0x7c))(param_1);
        return;
      }
      piVar6 = piVar5 + 1;
      iVar4 = piVar5[0x9e6e];
      iVar2 = iVar1 + 0x1c;
      piVar5 = piVar6;
      iVar1 = iVar7;
    } while (iVar4 == local_90[iVar2]);
  } while( true );
}

