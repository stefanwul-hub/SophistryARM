/* 00080f32 CScrollbarPl_vslot_4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CScrollbarPl_vslot_4(int param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  int local_50;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (*(int *)(param_1 + 0xd0) != 0) {
    local_20 = *(undefined4 *)(param_1 + 0xb4);
    local_24 = *(undefined4 *)(param_1 + 0xb0);
    (**(code **)(**(int **)(param_1 + 0xd0) + 0x10))
              (*(int **)(param_1 + 0xd0),param_2,param_1 + 0xc0,&local_24);
  }
  if (*(char *)(param_1 + 0xd4) == '\0') {
    iVar2 = *(int *)(param_1 + 0xcc) - *(int *)(param_1 + 0xc4);
  }
  else {
    iVar2 = *(int *)(param_1 + 200) - *(int *)(param_1 + 0xc0);
  }
  fVar1 = (float)(iVar2 + *(int *)(param_1 + 0xd8) * -2);
  lVar4 = (longdouble)FUN_00001ace(param_1,1);
  iVar2 = (int)((float)lVar4 * fVar1);
  local_50 = (int)fVar1;
  if (iVar2 < 8) {
    iVar3 = local_50 + -8;
    local_50 = 8;
  }
  else if (local_50 < iVar2) {
    iVar3 = 0;
  }
  else {
    iVar3 = local_50 - iVar2;
    local_50 = iVar2;
  }
  iVar2 = *(int *)(param_1 + 0xd8);
  lVar4 = (longdouble)FUN_00001ace(param_1,0);
  iVar2 = iVar2 + (int)((float)iVar3 * (float)lVar4 + 0.499);
  FUN_0009e6ec(param_2,0xff949e80);
  FUN_0009f51a(param_2,0xff949e80);
  if (*(char *)(param_1 + 0xd4) == '\0') {
    local_34 = *(int *)(param_1 + 0xc0);
    local_2c = *(int *)(param_1 + 200);
    local_30 = iVar2 + *(int *)(param_1 + 0xc4);
    local_28 = local_50 + local_30;
  }
  else {
    local_34 = iVar2 + *(int *)(param_1 + 0xc0);
    local_2c = local_50 + local_34;
    local_30 = *(int *)(param_1 + 0xc4);
    local_28 = *(int *)(param_1 + 0xcc) + -1;
  }
  FUN_000a0ebc(param_2,&local_34,0);
  FUN_0009fcae(param_2,&local_34);
  CControlPl_vslot_4(param_1,param_2);
  return;
}

