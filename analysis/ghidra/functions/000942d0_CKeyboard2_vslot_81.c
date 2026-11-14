/* 000942d0 CKeyboard2_vslot_81 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 CKeyboard2_vslot_81(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_2 / *(int *)(param_1 + 0x4dc);
  iVar4 = iVar1 * *(int *)(param_1 + 0x4dc);
  iVar3 = 0;
  do {
    if ((iVar4 <= param_2) && (param_2 < iVar4 + *(int *)(param_1 + 0x4c8))) {
      switch(iVar3) {
      case 0:
        *(int *)(param_4 + 8) = (iVar1 + *(int *)(param_1 + 0x4b8)) * 0xc;
        break;
      case 1:
        *(int *)(param_4 + 8) = (iVar1 + *(int *)(param_1 + 0x4b8)) * 0xc + 2;
        break;
      case 2:
        *(int *)(param_4 + 8) = (iVar1 + *(int *)(param_1 + 0x4b8)) * 0xc + 4;
        break;
      case 3:
        *(int *)(param_4 + 8) = (iVar1 + *(int *)(param_1 + 0x4b8)) * 0xc + 5;
        break;
      case 4:
        *(int *)(param_4 + 8) = (iVar1 + *(int *)(param_1 + 0x4b8)) * 0xc + 7;
        break;
      case 5:
        *(int *)(param_4 + 8) = (iVar1 + *(int *)(param_1 + 0x4b8)) * 0xc + 9;
        break;
      case 6:
        *(int *)(param_4 + 8) = (iVar1 + *(int *)(param_1 + 0x4b8)) * 0xc + 0xb;
      }
      break;
    }
    iVar4 = iVar4 + *(int *)(param_1 + 0x4c8);
    iVar3 = iVar3 + 1;
  } while (iVar3 != 7);
  iVar4 = iVar1 * *(int *)(param_1 + 0x4dc);
  iVar3 = 0;
  while (((iVar2 = *(int *)(param_1 + 0x4d8) + iVar4, param_2 < iVar2 ||
          (iVar2 + *(int *)(param_1 + 0x4d0) <= param_2)) || (*(int *)(param_1 + 0x4d4) <= param_3))
        ) {
    iVar4 = iVar4 + *(int *)(param_1 + 0x4c8);
    iVar3 = iVar3 + 1;
    if (iVar3 == 6) {
LAB_0009438d:
      *(int *)(param_4 + 0xc) = (param_3 * 0x7f) / (*(int *)(param_1 + 0x4d4) + -5);
      iVar1 = *(int *)(param_4 + 8);
      if (iVar1 < 0) {
        *(int *)(param_4 + 8) = 0;
        iVar1 = *(int *)(param_4 + 0xc);
      }
      else {
        if (0x7f < iVar1) {
          iVar1 = 0x7f;
        }
        *(int *)(param_4 + 8) = iVar1;
        iVar1 = *(int *)(param_4 + 0xc);
      }
      if (0 < iVar1) {
        if (0x7f < iVar1) {
          iVar1 = 0x7f;
        }
        *(int *)(param_4 + 0xc) = iVar1;
        return 1;
      }
      *(undefined4 *)(param_4 + 0xc) = 1;
      return 1;
    }
  }
  switch(iVar3) {
  case 0:
    *(int *)(param_4 + 8) = (iVar1 + *(int *)(param_1 + 0x4b8)) * 0xc + 1;
    break;
  case 1:
    *(int *)(param_4 + 8) = (iVar1 + *(int *)(param_1 + 0x4b8)) * 0xc + 3;
    break;
  default:
    break;
  case 3:
    *(int *)(param_4 + 8) = (iVar1 + *(int *)(param_1 + 0x4b8)) * 0xc + 6;
    break;
  case 4:
    *(int *)(param_4 + 8) = (iVar1 + *(int *)(param_1 + 0x4b8)) * 0xc + 8;
    break;
  case 5:
    *(int *)(param_4 + 8) = (iVar1 + *(int *)(param_1 + 0x4b8)) * 0xc + 10;
  }
  goto LAB_0009438d;
}

