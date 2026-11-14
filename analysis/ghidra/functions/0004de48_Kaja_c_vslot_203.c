/* 0004de48 Kaja_c_vslot_203 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined1
Kaja_c_vslot_203(int *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  undefined1 uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int local_2c;
  int iStack_20;
  
  piVar4 = param_1 + 0xecc;
  _OSAtomicAdd32Barrier(1,piVar4);
  if (param_3 == -1) {
    local_2c = param_1[0x33f8];
  }
  else {
    local_2c = param_3;
  }
  iVar6 = param_3 % 10;
  switch(param_2) {
  default:
    uVar2 = Synth_vslot_203(param_1,param_2,param_3,param_4,param_5);
    break;
  case 2:
    if (param_3 < 0) {
      param_3 = 0x2bd;
code_r0x0004e510:
      FUN_0003a05c(param_1 + iVar6 * 0x1bc + 0x228a0,1,0);
      (**(code **)(*param_1 + 0x34c))(param_1,param_3,1);
      uVar2 = 1;
      break;
    }
    if ((param_3 < 0xf) && (param_3 < 10)) {
      param_3 = param_3 + 0x2bd;
      goto code_r0x0004e510;
    }
    if (iVar6 == 0) {
      param_3 = FUN_0001d28c(param_1,0x3aa);
    }
    else if (iVar6 == 1) {
      param_3 = FUN_0001d28c(param_1,0x3ab);
    }
    FUN_000346d8(param_1 + iVar6 * 0x286e + 0x23678,1,0,param_3);
    goto code_r0x0004e0f5;
  case 3:
    if (param_3 < 0) {
      param_3 = 0x2bd;
    }
    else {
      if ((0xe < param_3) || (9 < param_3)) {
        if (iVar6 == 0) {
          param_3 = FUN_0001d28c(param_1,0x3aa);
        }
        else if (iVar6 == 1) {
          param_3 = FUN_0001d28c(param_1,0x3ab);
        }
        FUN_000346d8(param_1 + iVar6 * 0x286e + 0x23678,0,0,param_3);
        (**(code **)(*param_1 + 0x350))(param_1);
        uVar2 = 1;
        break;
      }
      param_3 = param_3 + 0x2bd;
    }
    FUN_0003a05c(param_1 + iVar6 * 0x1bc + 0x228a0,0,0);
    (**(code **)(*param_1 + 0x34c))(param_1,param_3,1);
    uVar2 = 1;
    break;
  case 4:
    cVar3 = FUN_0002e50e(param_1 + 0xe28,"Clear Sample","Do you want to unload the sample ?");
    if (cVar3 == '\0') goto code_r0x0004e108;
    if (param_3 < 0) {
      param_3 = 0x2bd;
    }
    else {
      if ((0xe < param_3) || (9 < param_3)) {
        if (iVar6 == 0) {
          iVar5 = FUN_0001d28c(param_1,0x3aa);
          iStack_20 = iVar5 * 0x14;
        }
        else if (iVar6 == 1) {
          iVar5 = FUN_0001d28c(param_1,0x3ab);
          iStack_20 = iVar5 * 0x14;
        }
        piVar1 = param_1 + iVar6 * 0x286e + 0x23678;
        (**(code **)(param_1[iVar6 * 0x286e + 0x23678] + 0x44))(piVar1,0,iStack_20 + 9,"");
        (**(code **)(param_1[iVar6 * 0x286e + 0x23678] + 0x24))(piVar1,0,iStack_20 + 0xf,0);
        (**(code **)(param_1[iVar6 * 0x286e + 0x23678] + 0x24))(piVar1,0,iStack_20 + 0x14,0);
        (**(code **)(param_1[iVar6 * 0x286e + 0x23678] + 0x24))(piVar1,0,iStack_20 + 0x15,0);
        goto code_r0x0004e2b7;
      }
      param_3 = param_3 + 0x2bd;
    }
    (**(code **)(param_1[iVar6 * 0x1bc + 0x228a0] + 0x44))(param_1 + iVar6 * 0x1bc + 0x228a0,0,3,"")
    ;
    goto code_r0x0004e34e;
  case 0x29:
    if (param_4 < 0) {
      param_4 = 0;
      param_3 = 0x2e1;
    }
    else if (param_4 < 4) {
      param_3 = param_4 + 0x2e1;
    }
    else {
      param_4 = 3;
      param_3 = 0x2e4;
    }
    FUN_0008d892(param_1 + param_4 * 0x1ba + 0x22f90,1,0);
code_r0x0004e34e:
    (**(code **)(*param_1 + 0x34c))(param_1,param_3,1);
code_r0x0004e108:
    _OSAtomicAdd32Barrier(0xffffffff,piVar4);
    return 1;
  case 0x2a:
    if (param_4 < 0) {
      param_4 = 0;
      iVar6 = 0x2e1;
    }
    else if (param_4 < 4) {
      iVar6 = param_4 + 0x2e1;
    }
    else {
      param_4 = 3;
      iVar6 = 0x2e4;
    }
    FUN_0008d892(param_1 + param_4 * 0x1ba + 0x22f90,0,0);
    goto code_r0x0004e3b9;
  case 0x2b:
    if (param_4 < 0) {
      param_4 = 0;
      iVar6 = 0x2e1;
    }
    else if (param_4 < 4) {
      iVar6 = param_4 + 0x2e1;
    }
    else {
      param_4 = 3;
      iVar6 = 0x2e4;
    }
    cVar3 = FUN_0002e50e(param_1 + 0xe28,"Clear Sample","Do you want to unload the sample ?");
    if (cVar3 != '\0') {
      FUN_0008ec74(param_1 + param_4 * 0x1ba + 0x22f90,local_2c);
    }
code_r0x0004e3b9:
    (**(code **)(*param_1 + 0x34c))(param_1,iVar6,1);
    uVar2 = 1;
    break;
  case 0x5c:
    uVar7 = 0x30c;
    goto code_r0x0004e2db;
  case 0x5d:
    FUN_0001d1ca(param_1,0x30d,param_4);
code_r0x0004e2b7:
    (**(code **)(*param_1 + 0x350))(param_1);
    goto code_r0x0004e108;
  case 0x5e:
    uVar7 = 0x25b;
code_r0x0004e2db:
    FUN_0001d1ca(param_1,uVar7,param_4);
code_r0x0004e0f5:
    (**(code **)(*param_1 + 0x350))(param_1);
    goto code_r0x0004e108;
  case 0x5f:
    FUN_0004dd56(param_1);
    uVar2 = 1;
  }
  _OSAtomicAdd32Barrier(0xffffffff,piVar4);
  return uVar2;
}

