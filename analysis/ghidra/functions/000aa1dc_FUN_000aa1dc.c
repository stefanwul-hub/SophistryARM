/* 000aa1dc FUN_000aa1dc */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int FUN_000aa1dc(int *param_1,undefined4 param_2,uint param_3,int param_4,int *param_5,
                undefined1 *param_6)

{
  undefined1 uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int local_20 [4];
  
  switch(param_2) {
  case 0:
  case 0xe:
  case 0x19:
    if (param_3 != 0) {
      return -0x2a72;
    }
    *param_5 = 4;
    *param_6 = 1;
    break;
  case 1:
    if (1 < param_3) {
      return -0x2a72;
    }
    *param_5 = 0xc;
    *param_6 = 1;
    break;
  case 2:
    *param_5 = 8;
    goto LAB_000aa464;
  case 3:
    local_20[0] = 0;
    iVar3 = (**(code **)(*param_1 + 0x6c))(param_1,param_3,0,local_20);
    *param_5 = local_20[0] << 2;
    *param_6 = 0;
    return iVar3;
  case 4:
    *param_5 = 0x54;
    *param_6 = 0;
    return 0;
  case 5:
    if (param_3 != 0) {
      return -0x2a72;
    }
    *param_5 = 4;
    *param_6 = 0;
    return 0;
  default:
    iVar3 = (**(code **)(*param_1 + 0x20))(param_1,param_2,param_3,param_4,param_5,param_6);
    return iVar3;
  case 8:
    *param_5 = 0x28;
LAB_000aa464:
    uVar1 = FUN_000a6dba(param_1,param_3,param_4);
    *param_6 = uVar1;
LAB_000aa47c:
    if (4 < param_3) {
LAB_000aa485:
      puVar4 = (undefined4 *)___cxa_allocate_exception(4);
      *puVar4 = 0xffffd58e;
LAB_000aa497:
                    /* WARNING: Subroutine does not return */
      ___cxa_throw(puVar4,PTR_001037fc,0);
    }
    break;
  case 0xb:
    *param_5 = 4;
    uVar1 = (**(code **)(*param_1 + 0x5c))(param_1,param_3);
    *param_6 = uVar1;
    return 0;
  case 0xc:
    if (param_3 != 0) {
      return -0x2a72;
    }
    *param_5 = 8;
    *param_6 = 0;
    break;
  case 0xd:
    if (param_3 != 0) {
      return -0x2a72;
    }
    iVar3 = (**(code **)(*param_1 + 0xa8))(param_1,0);
    if (iVar3 == 0) {
      return -0x2a7f;
    }
    *param_5 = iVar3 << 2;
    *param_6 = 0;
    break;
  case 0x10:
    iVar3 = (**(code **)(*param_1 + 0x7c))(param_1,param_3,param_4,0);
    if (iVar3 == 0) {
      *param_5 = 4;
      *param_6 = 0;
      return 0;
    }
    return iVar3;
  case 0x12:
    if (param_3 != 0) {
      return -0x2a72;
    }
    iVar3 = (**(code **)(*param_1 + 0x88))(param_1);
    *param_5 = iVar3;
    if (iVar3 == 0) {
      return -0x2a7f;
    }
    *param_5 = iVar3 * 0x14;
    *param_6 = 0;
    break;
  case 0x13:
    iVar3 = (**(code **)(*param_1 + 200))(param_1,param_3,param_4,0,param_6);
    *param_5 = iVar3;
    if (iVar3 != 0) {
      return 0;
    }
    *param_6 = 0;
    return -0x2a7f;
  case 0x14:
    if (param_3 != 0) {
      return -0x2a72;
    }
    cVar2 = (**(code **)(*param_1 + 0xa0))(param_1);
    if (cVar2 == '\0') {
      return -0x2a7f;
    }
    *param_5 = 8;
    *param_6 = 0;
    break;
  case 0x16:
    if (param_3 != 0) {
      return -0x2a72;
    }
    goto LAB_000aa40d;
  case 0x17:
    if (*(byte *)((int)param_1 + 0xe) < 2) {
      return -0x2a7f;
    }
    if (1 < param_3) {
      return -0x2a72;
    }
    *param_5 = 8;
    *param_6 = 1;
    break;
  case 0x18:
    if (param_3 != 0) {
      return -0x2a72;
    }
    iVar3 = (**(code **)(*param_1 + 0x80))(param_1,0);
    if (iVar3 != 0) {
      return iVar3;
    }
LAB_000aa40d:
    *param_5 = 4;
    *param_6 = 0;
    break;
  case 0x1b:
    if (param_3 != 0) {
      return -0x2a72;
    }
    *param_5 = 0x10;
    *param_6 = 1;
    break;
  case 0x1c:
  case 0x24:
    if (param_3 != 0) {
      return -0x2a72;
    }
    *param_5 = 8;
    *param_6 = 1;
    break;
  case 0x1e:
    *param_5 = 4;
    *param_6 = 1;
    goto LAB_000aa47c;
  case 0x20:
    if (param_3 < 5) {
      piVar5 = (int *)param_1[param_3 * 5 + 10] + param_4;
      if ((((piVar5 < (int *)param_1[param_3 * 5 + 0xb]) &&
           ((int *)param_1[param_3 * 5 + 10] <= piVar5)) && (*piVar5 != 0)) &&
         (piVar5 = (int *)___dynamic_cast(*piVar5,PTR_PTR_vtable_001038c8,PTR_PTR_vtable_001038c4,0)
         , piVar5 != (int *)0x0)) {
        iVar3 = (**(code **)(*piVar5 + 0x14))(piVar5,0);
        if (iVar3 == 0) {
          return -0x2a7f;
        }
        *param_5 = iVar3 << 2;
        *param_6 = 0;
        return 0;
      }
      puVar4 = (undefined4 *)___cxa_allocate_exception(4);
      *puVar4 = 0xffffd583;
      goto LAB_000aa497;
    }
    goto LAB_000aa485;
  case 0x27:
    if (param_3 != 0) {
      return -0x2a72;
    }
    *param_6 = 0;
    cVar2 = (**(code **)(*param_1 + 0x90))(param_1);
    if (cVar2 == '\0') {
      return -0x2a7f;
    }
    *param_5 = 4;
  }
  piVar5 = (int *)(param_4 * 4 + param_1[param_3 * 5 + 10]);
  if (((piVar5 < (int *)param_1[param_3 * 5 + 0xb]) && ((int *)param_1[param_3 * 5 + 10] <= piVar5))
     && (*piVar5 != 0)) {
    return 0;
  }
  return -0x2a7d;
}

