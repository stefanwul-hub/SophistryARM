/* 000b5a12 FUN_000b5a12 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000b5a12(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char local_29c [320];
  char local_15c [332];
  
  piVar1 = *(int **)(param_1 + 0x950);
  if (piVar1 == (int *)0x0) {
    return;
  }
  if (param_2 == (int *)0x0) {
    return;
  }
  if (param_5 == 0) {
    return;
  }
  cVar3 = (**(code **)(*piVar1 + 0x17c))(piVar1,param_1 + 0x95c);
  if (cVar3 == '\0') {
    return;
  }
  _sprintf(local_15c,"%s_MOD_%s",param_1 + 0x95c,param_5);
  _sprintf(local_29c,"%s Module Parameters",param_5);
  *(int *)(param_1 + 0x29c) = param_5;
  *(char **)(param_1 + 0x2a0) = local_29c;
  *(char **)(param_1 + 0x2a8) = "*.MOD";
  *(undefined4 *)(param_1 + 0x2ac) = 0;
  iVar6 = param_1 + 0x298;
  FileDialog_c_vslot_3(iVar6,local_15c);
  switch(param_4) {
  case 0:
    *(undefined4 *)(param_1 + 0x2a4) = 0;
    FUN_0001c602(*(undefined4 *)(param_1 + 0x950),param_5);
    uVar4 = FileDialog_c_vslot_2(iVar6);
    FUN_000b5694(param_1,param_2,uVar4,param_3);
    break;
  case 1:
    *(undefined4 *)(param_1 + 0x2a4) = 1;
    FUN_0001c602(*(undefined4 *)(param_1 + 0x950),param_5);
    uVar4 = FileDialog_c_vslot_2(iVar6);
    FUN_000b58fc(param_1,param_2,uVar4,param_3);
    return;
  case 2:
    iVar6 = *(int *)(param_1 + 0x958);
    if (iVar6 == 0) {
      return;
    }
    piVar1 = (int *)param_2[0x48];
    if (piVar1 == (int *)0x0) {
      return;
    }
    iVar5 = (**(code **)(*piVar1 + 8))(piVar1,param_3);
    if (0x3fff < iVar5) {
      return;
    }
    (**(code **)(*piVar1 + 0xc))(piVar1,iVar6,param_3);
    return;
  case 3:
    piVar1 = *(int **)(param_1 + 0x958);
    if ((piVar1 != (int *)0x0) && (piVar2 = (int *)param_2[0x48], piVar2 != (int *)0x0)) {
      iVar6 = *piVar1;
      iVar5 = (**(code **)(*param_2 + 100))(param_2);
      if (iVar6 == iVar5) {
        (**(code **)(*piVar2 + 0x10))(piVar2,piVar1,piVar1[1],param_3);
        (**(code **)(**(int **)(param_1 + 0x950) + 0x360))(*(int **)(param_1 + 0x950),param_3);
      }
    }
    break;
  case 4:
    (**(code **)(*param_2 + 0x10))(param_2);
    break;
  default:
    goto LAB_000b5a59;
  }
  (**(code **)(**(int **)(param_1 + 0x950) + 0x350))(*(int **)(param_1 + 0x950));
LAB_000b5a59:
  return;
}

