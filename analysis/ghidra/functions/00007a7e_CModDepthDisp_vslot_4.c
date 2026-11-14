/* 00007a7e CModDepthDisp_vslot_4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CModDepthDisp_vslot_4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  char *pcVar4;
  int iVar5;
  longdouble lVar6;
  longdouble lVar7;
  undefined8 uVar8;
  char *local_68;
  char local_3c [24];
  undefined4 local_24;
  undefined4 local_20;
  
  if (*(int *)(param_1 + 0xf4) == 0) {
    if (**(char **)(param_1 + 0x84) == '\0') {
      iVar5 = *(int *)(param_1 + 0xdc);
      iVar1 = *(int *)(param_1 + 0xec);
      lVar6 = (longdouble)_pow(0,0x40240000,(double)iVar1);
      iVar2 = *(int *)(param_1 + 0xe0);
      _sprintf((char *)&local_24,"%%0.%df",iVar1);
      lVar7 = (longdouble)FUN_000019e8(param_1);
      _sprintf(local_3c,(char *)&local_24,
               (double)((float)iVar5 / (float)lVar6 +
                       ((float)(iVar2 - iVar5) / (float)lVar6) * (float)lVar7));
      iVar5 = *(int *)(param_1 + 0xc0);
      goto joined_r0x00007c54;
    }
    _strcpy(local_3c,*(char **)(param_1 + 0x84));
  }
  else {
    lVar6 = (longdouble)FUN_000019e8(param_1);
    if ((0.5 <= (float)lVar6) || (NAN((float)lVar6))) {
      lVar6 = (longdouble)FUN_000019e8(param_1);
      fVar3 = (float)*(int *)(param_1 + 0xf4) * -100.0 +
              (float)*(int *)(param_1 + 0xf4) * 200.0 * (float)lVar6 + 0.5;
    }
    else {
      lVar6 = (longdouble)FUN_000019e8(param_1);
      fVar3 = ((float)*(int *)(param_1 + 0xf4) * -100.0 +
              (float)*(int *)(param_1 + 0xf4) * 200.0 * (float)lVar6) - 0.5;
    }
    iVar5 = (int)fVar3;
    if (iVar5 < 0) {
      uVar8 = CONCAT44(-iVar5 % 100,-iVar5 / 100);
      pcVar4 = "-%1d:%02d";
    }
    else {
      uVar8 = CONCAT44(iVar5 % 100,iVar5 / 100);
      pcVar4 = "%1d:%02d";
    }
    _sprintf(local_3c,pcVar4,uVar8);
  }
  iVar5 = *(int *)(param_1 + 0xc0);
joined_r0x00007c54:
  if (iVar5 != 0) {
    local_20 = *(undefined4 *)(param_1 + 200);
    local_24 = *(undefined4 *)(param_1 + 0xc4);
    (**(code **)(**(int **)(param_1 + 0xc0) + 0x10))
              (*(int **)(param_1 + 0xc0),param_2,param_1 + 8,&local_24);
  }
  local_68 = local_3c;
  FUN_0009e6ec(param_2,*(undefined4 *)(param_1 + 0xd0));
  FUN_0009f51a(param_2,*(undefined4 *)(param_1 + 0xd0));
  FUN_0009e6ac(param_2,*(undefined4 *)(param_1 + 0x88));
  FUN_0009ca22(param_2,*(undefined4 *)(param_1 + 0xcc),0,0);
  FUN_0009fe14(param_2,local_68,param_1 + 8,0,*(undefined4 *)(param_1 + 0xd4));
  CControlPl_vslot_4(param_1,param_2);
  return;
}

