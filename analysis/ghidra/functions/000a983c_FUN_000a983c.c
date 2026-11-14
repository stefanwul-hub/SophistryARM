/* 000a983c FUN_000a983c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_000a983c(int *param_1,int param_2,uint param_3,int param_4,double *param_5)

{
  char cVar1;
  undefined4 uVar2;
  double *pdVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  longdouble lVar7;
  void *apvStack_20 [4];
  
  switch(param_2) {
  case 0:
    *(undefined4 *)param_5 = 0;
    uVar2 = (**(code **)(*param_1 + 0x74))(param_1,param_5);
    break;
  default:
    uVar2 = (**(code **)(*param_1 + 0x24))(param_1,param_2,param_3,param_4,param_5);
    break;
  case 2:
    pdVar3 = (double *)(**(code **)(*param_1 + 0xb0))(param_1,param_3,param_4);
    *param_5 = *pdVar3;
    uVar2 = 0;
    break;
  case 3:
    apvStack_20[0] = (void *)0x0;
    uVar2 = (**(code **)(*param_1 + 0x6c))(param_1,param_3,param_5,apvStack_20);
    break;
  case 4:
    uVar2 = (**(code **)(*param_1 + 0x70))(param_1,param_3,param_4,param_5);
    break;
  case 5:
    if (param_4 == 7) {
      *(undefined **)param_5 = PTR_FUN_001038bc;
      uVar2 = 0;
    }
    else if (param_4 == 0xe) {
      if (*(byte *)((int)param_1 + 0xe) < 2) {
        uVar2 = 0xffffd583;
      }
      else {
        *(undefined **)param_5 = PTR_FUN_001038b4;
        uVar2 = 0;
      }
    }
    else if (param_4 == 6) {
      *(undefined **)param_5 = PTR_FUN_001038b8;
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)(*param_1 + 0x24))(param_1,5,param_3,param_4,param_5);
    }
    break;
  case 8:
    puVar6 = (undefined4 *)(**(code **)(*param_1 + 0xb0))(param_1,param_3,param_4);
    *(undefined4 *)param_5 = *puVar6;
    *(undefined4 *)((int)param_5 + 4) = puVar6[1];
    *(undefined4 *)(param_5 + 1) = puVar6[2];
    *(undefined4 *)((int)param_5 + 0xc) = puVar6[3];
    *(undefined4 *)(param_5 + 2) = puVar6[4];
    *(undefined4 *)((int)param_5 + 0x14) = puVar6[5];
    *(undefined4 *)(param_5 + 3) = puVar6[6];
    *(undefined4 *)((int)param_5 + 0x1c) = puVar6[7];
    *(undefined4 *)(param_5 + 4) = puVar6[8];
    *(undefined4 *)((int)param_5 + 0x24) = puVar6[9];
    uVar2 = 0;
    break;
  case 0xb:
    if (4 < param_3) {
code_r0x000a9d42:
      puVar6 = (undefined4 *)___cxa_allocate_exception(4);
      *puVar6 = 0xffffd58e;
code_r0x000a9cee:
                    /* WARNING: Subroutine does not return */
      ___cxa_throw(puVar6,PTR_001037fc,0);
    }
    *(int *)param_5 = param_1[param_3 * 5 + 0xb] - param_1[param_3 * 5 + 10] >> 2;
    goto code_r0x000a9a62;
  case 0xc:
    lVar7 = (longdouble)(**(code **)(*param_1 + 0x98))(param_1);
    *param_5 = (double)lVar7;
    uVar2 = 0;
    break;
  case 0xd:
    iVar5 = (**(code **)(*param_1 + 0xa8))(param_1,apvStack_20);
    _memcpy(param_5,apvStack_20[0],iVar5 << 2);
    uVar2 = 0;
    break;
  case 0xe:
    *(int *)param_5 = param_1[0x28];
    uVar2 = 0;
    break;
  case 0x10:
    uVar2 = (**(code **)(*param_1 + 0x7c))(param_1,param_3,param_4,param_5);
    break;
  case 0x12:
    (**(code **)(*param_1 + 0x8c))(param_1,param_5);
    uVar2 = 0;
    break;
  case 0x13:
    iVar5 = (**(code **)(*param_1 + 200))(param_1,param_3,param_4,param_5,apvStack_20);
    if (iVar5 == 0) goto code_r0x000a9b1c;
    goto code_r0x000a9a62;
  case 0x14:
    cVar1 = (**(code **)(*param_1 + 0xa0))(param_1);
    if (cVar1 != '\0') {
      lVar7 = (longdouble)(**(code **)(*param_1 + 0x9c))(param_1);
      *param_5 = (double)lVar7;
      return 0;
    }
    goto code_r0x000a9b1c;
  case 0x16:
    *(int *)param_5 = param_1[0x29];
    param_1[0x29] = 0;
    uVar2 = 0;
    break;
  case 0x18:
    *(undefined4 *)param_5 = 0;
    uVar2 = (**(code **)(*param_1 + 0x80))(param_1,param_5);
    break;
  case 0x19:
    *(int *)param_5 = param_1[0x36];
    iVar5 = param_1[0x36];
    if (iVar5 != 0) {
code_r0x000a9ba5:
      _CFRetain(iVar5);
      return 0;
    }
    goto code_r0x000a9c4b;
  case 0x1b:
    *(int *)param_5 = param_1[0x32];
    *(int *)((int)param_5 + 4) = param_1[0x33];
    *(int *)(param_5 + 1) = param_1[0x34];
    *(int *)((int)param_5 + 0xc) = param_1[0x35];
    uVar2 = 0;
    break;
  case 0x1c:
  case 0x24:
    iVar5 = param_1[0x2b];
    *(int *)param_5 = param_1[0x2a];
    *(int *)((int)param_5 + 4) = iVar5;
    if (param_2 == 0x24) {
      iVar5 = param_1[0x2b];
      if (iVar5 == 0) {
        return 0;
      }
      goto code_r0x000a9ba5;
    }
code_r0x000a9a62:
    uVar2 = 0;
    break;
  case 0x1e:
    if (4 < param_3) goto code_r0x000a9d42;
    piVar4 = (int *)param_1[param_3 * 5 + 10] + param_4;
    if ((piVar4 < (int *)param_1[param_3 * 5 + 0xb]) && ((int *)param_1[param_3 * 5 + 10] <= piVar4)
       ) {
      iVar5 = *piVar4;
    }
    else {
      iVar5 = 0;
    }
    if (*(int *)(iVar5 + 0x30) != 0) {
      *(undefined4 *)param_5 = *(undefined4 *)(iVar5 + 0x30);
      iVar5 = *(int *)(iVar5 + 0x30);
      goto code_r0x000a9ba5;
    }
code_r0x000a9c4b:
    uVar2 = 0xffffd59d;
    break;
  case 0x20:
    if (4 < param_3) goto code_r0x000a9d42;
    piVar4 = (int *)param_1[param_3 * 5 + 10] + param_4;
    if (((((int *)param_1[param_3 * 5 + 0xb] <= piVar4) ||
         (piVar4 < (int *)param_1[param_3 * 5 + 10])) || (*piVar4 == 0)) ||
       (piVar4 = (int *)___dynamic_cast(*piVar4,PTR_PTR_vtable_001038c8,PTR_PTR_vtable_001038c4,0),
       piVar4 == (int *)0x0)) {
      puVar6 = (undefined4 *)___cxa_allocate_exception(4);
      *puVar6 = 0xffffd583;
      goto code_r0x000a9cee;
    }
    iVar5 = (**(code **)(*piVar4 + 0x14))(piVar4,param_5);
    if (iVar5 != 0) {
      return 0;
    }
code_r0x000a9b1c:
    uVar2 = 0xffffd581;
    break;
  case 0x27:
    uVar2 = (**(code **)(*param_1 + 0x94))(param_1);
    *(undefined4 *)param_5 = uVar2;
    uVar2 = 0;
  }
  return uVar2;
}

