/* 00082d68 AUCronoX_vslot_28 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 AUCronoX_vslot_28(int *param_1,int param_2,int param_3,undefined1 *param_4)

{
  char cVar1;
  int iVar2;
  longdouble lVar3;
  float fVar4;
  float fVar5;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_34;
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  int local_20 [4];
  
  FUN_00002918(param_1);
  if (param_2 == 0) {
    local_20[0] = param_3;
    cVar1 = (**(code **)(*param_1 + 0x134))(param_1,local_20);
    if (cVar1 == '\0') {
      return 0xffffd59d;
    }
    FUN_0001ce0e(param_1 + 0x3b,param_3,&local_48);
    FUN_0001cb52(param_1 + 0x3b,param_3,local_24,local_28,local_2c);
    if (param_1[0xcad18] == 0) {
      (**(code **)(*param_1 + 0x154))(param_1);
    }
    *(undefined4 *)(param_4 + 0x50) = 0xc0000000;
    iVar2 = _CFArrayGetValueAtIndex(param_1[0xcad18],param_3);
    *(int *)(param_4 + 0x3c) = iVar2;
    if (iVar2 != 0) {
      *(uint *)(param_4 + 0x50) = *(uint *)(param_4 + 0x50) | 0x8000000;
      cVar1 = _CFStringGetCString(iVar2,param_4,0x34,0x8000100);
      if (cVar1 == '\0') {
        *param_4 = 0;
      }
    }
    fVar5 = (float)local_44;
    *(float *)(param_4 + 0x44) = fVar5;
    *(float *)(param_4 + 0x48) = (float)local_40;
    *(float *)(param_4 + 0x4c) = (float)local_3c;
    if (local_48 == 5) {
      *(float *)(param_4 + 0x44) = fVar5 / 5.0;
      *(float *)(param_4 + 0x48) = (float)local_40 / 5.0;
      *(float *)(param_4 + 0x4c) = (float)local_3c / 5.0;
      *(undefined4 *)(param_4 + 0x40) = 0xd;
      *(uint *)(param_4 + 0x50) = *(uint *)(param_4 + 0x50) | 0x200000;
    }
    else if (local_48 == 6) {
      *(undefined4 *)(param_4 + 0x40) = 2;
    }
    else if (local_48 == 2) {
      *(undefined4 *)(param_4 + 0x40) = 1;
      *(uint *)(param_4 + 0x50) = *(uint *)(param_4 + 0x50) | 0x200000;
    }
    else {
      lVar3 = (longdouble)_pow(0,0x40240000,(double)local_34);
      fVar4 = (float)(int)((double)lVar3 + 0.5);
      lVar3 = (longdouble)FUN_000152c0(fVar5,fVar4);
      *(float *)(param_4 + 0x44) = (float)lVar3;
      lVar3 = (longdouble)FUN_000152c0((float)local_40,fVar4);
      *(float *)(param_4 + 0x48) = (float)lVar3;
      lVar3 = (longdouble)FUN_000152c0((float)local_3c,fVar4);
      *(float *)(param_4 + 0x4c) = (float)lVar3;
      *(undefined4 *)(param_4 + 0x40) = 0;
      *(uint *)(param_4 + 0x50) = *(uint *)(param_4 + 0x50) | 0x800000;
    }
    if (param_3 - 0xd5U < 6) {
      *(uint *)(param_4 + 0x50) = *(uint *)(param_4 + 0x50) | 0x10000000;
      return 0;
    }
  }
  return 0;
}

