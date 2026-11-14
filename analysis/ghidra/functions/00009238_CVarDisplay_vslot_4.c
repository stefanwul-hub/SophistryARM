/* 00009238 CVarDisplay_vslot_4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CVarDisplay_vslot_4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  longdouble lVar5;
  undefined4 *local_60;
  undefined4 local_3c [6];
  undefined4 local_24;
  undefined4 local_20;
  
  if (**(char **)(param_1 + 0x84) == '\0') {
    if (*(int *)(param_1 + 0xc4) == 5) {
      iVar1 = *(int *)(param_1 + 0xcc);
      iVar2 = *(int *)(param_1 + 200);
      lVar4 = (longdouble)FUN_000019e8(param_1);
      iVar1 = (int)((float)(iVar1 - iVar2) * (float)lVar4) + *(int *)(param_1 + 200);
      if (*(int *)(param_1 + 200) != iVar1) {
        _sprintf((char *)local_3c,"%d",iVar1 / 5);
        iVar1 = *(int *)(param_1 + 0xb0);
        goto joined_r0x0000945a;
      }
      local_3c[0] = 0x6f6f2d;
    }
    else {
      iVar1 = *(int *)(param_1 + 200);
      iVar2 = *(int *)(param_1 + 0xd8);
      lVar4 = (longdouble)_pow(0,0x40240000,(double)iVar2);
      iVar3 = *(int *)(param_1 + 0xcc);
      _sprintf((char *)&local_24,"%%0.%df",iVar2);
      lVar5 = (longdouble)FUN_000019e8(param_1);
      _sprintf((char *)local_3c,(char *)&local_24,
               (double)((float)iVar1 / (float)lVar4 +
                       ((float)(iVar3 - iVar1) / (float)lVar4) * (float)lVar5));
    }
  }
  else {
    _strcpy((char *)local_3c,*(char **)(param_1 + 0x84));
  }
  iVar1 = *(int *)(param_1 + 0xb0);
joined_r0x0000945a:
  if (iVar1 != 0) {
    local_20 = *(undefined4 *)(param_1 + 0xe4);
    local_24 = *(undefined4 *)(param_1 + 0xe0);
    (**(code **)(**(int **)(param_1 + 0xb0) + 0x10))
              (*(int **)(param_1 + 0xb0),param_2,param_1 + 8,&local_24);
  }
  local_60 = local_3c;
  FUN_0009e6ec(param_2,*(undefined4 *)(param_1 + 0xbc));
  FUN_0009f51a(param_2,*(undefined4 *)(param_1 + 0xbc));
  FUN_0009e6ac(param_2,*(undefined4 *)(param_1 + 0x88));
  FUN_0009ca22(param_2,*(undefined4 *)(param_1 + 0xb4),0,0);
  FUN_0009fe14(param_2,local_60,param_1 + 8,0,*(undefined4 *)(param_1 + 0xc0));
  CControlPl_vslot_4(param_1,param_2);
  return;
}

