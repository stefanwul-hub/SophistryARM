/* 00094d90 AudioEffect_vslot_2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int AudioEffect_vslot_2(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                       undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  longdouble lVar4;
  
  switch(param_2) {
  case 0:
    (**(code **)(*param_1 + 0xc))(param_1);
    iVar3 = 0;
    break;
  case 1:
    (**(code **)(*param_1 + 0x10))(param_1);
    iVar3 = 0;
    break;
  case 2:
    if (param_4 < param_1[5]) {
      (**(code **)(*param_1 + 0x3c))(param_1,param_4);
      return 0;
    }
  default:
LAB_00094e37:
    iVar3 = 0;
    break;
  case 3:
                    /* WARNING: Could not recover jumptable at 0x00094e7d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (**(code **)(*param_1 + 0x38))();
    return iVar3;
  case 4:
    (**(code **)(*param_1 + 0x40))(param_1,param_5);
    iVar3 = 0;
    break;
  case 5:
    (**(code **)(*param_1 + 0x44))(param_1,param_5);
    iVar3 = 0;
    break;
  case 6:
    (**(code **)(*param_1 + 0x48))(param_1,param_3,param_5);
    iVar3 = 0;
    break;
  case 7:
    (**(code **)(*param_1 + 0x4c))(param_1,param_3,param_5);
    iVar3 = 0;
    break;
  case 8:
    (**(code **)(*param_1 + 0x50))(param_1,param_3,param_5);
    iVar3 = 0;
    break;
  case 9:
    lVar4 = (longdouble)(**(code **)(*param_1 + 0xb4))(param_1);
    iVar3 = (int)((float)lVar4 * 32767.0);
    break;
  case 10:
    (**(code **)(*param_1 + 0x1c))(param_1,param_6);
    iVar3 = 0;
    break;
  case 0xb:
    (**(code **)(*param_1 + 0x20))(param_1,param_4);
    iVar3 = 0;
    break;
  case 0xc:
    if (param_4 == 0) {
      (**(code **)(*param_1 + 0x14))(param_1);
      iVar3 = 0;
    }
    else {
      (**(code **)(*param_1 + 0x18))(param_1);
      iVar3 = 0;
    }
    break;
  case 0xd:
    piVar1 = (int *)param_1[2];
    if ((piVar1 != (int *)0x0) &&
       (cVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,param_5), cVar2 != '\0')) {
      return 1;
    }
    goto LAB_00094e37;
  case 0xe:
    piVar1 = (int *)param_1[2];
    if ((piVar1 != (int *)0x0) &&
       (cVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,param_5), cVar2 != '\0')) {
      return 1;
    }
    goto LAB_00094e37;
  case 0xf:
    piVar1 = (int *)param_1[2];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x14))(piVar1);
    }
    goto LAB_00094e37;
  case 0x10:
    piVar1 = (int *)param_1[2];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x20))(piVar1,param_5);
      return 0;
    }
    goto LAB_00094e37;
  case 0x11:
    if ((int *)param_1[2] != (int *)0x0) {
      UNRECOVERED_JUMPTABLE = *(code **)(*(int *)param_1[2] + 0x24);
      goto code_r0x00094ffe;
    }
    goto LAB_00094e37;
  case 0x12:
    if ((int *)param_1[2] != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00095024. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar3 = (**(code **)(*(int *)param_1[2] + 0x28))();
      return iVar3;
    }
    goto LAB_00094e37;
  case 0x13:
    piVar1 = (int *)param_1[2];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x1c))(piVar1);
      return 0;
    }
    goto LAB_00094e37;
  case 0x14:
    piVar1 = (int *)param_1[2];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x2c))(piVar1);
      return 0;
    }
    goto LAB_00094e37;
  case 0x15:
    piVar1 = (int *)param_1[2];
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x30))(piVar1);
    }
    goto LAB_00094e37;
  case 0x16:
    iVar3 = 0x4e764566;
    break;
  case 0x17:
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x54);
code_r0x00094ffe:
                    /* WARNING: Could not recover jumptable at 0x00095005. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (*UNRECOVERED_JUMPTABLE)();
    return iVar3;
  case 0x18:
                    /* WARNING: Could not recover jumptable at 0x000950a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (**(code **)(*param_1 + 0x58))();
    return iVar3;
  }
  return iVar3;
}

