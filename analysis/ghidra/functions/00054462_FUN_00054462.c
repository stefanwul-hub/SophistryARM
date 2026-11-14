/* 00054462 FUN_00054462 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_00054462(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_4 < 5) {
    do {
      uVar1 = FUN_0001d28c(*(undefined4 *)(param_1 + 0x4c),param_3 + param_2);
      switch(uVar1) {
      case 4:
      case 5:
      case 6:
      case 7:
      case 0x1d:
        return 0x30;
      default:
        goto code_r0x00054479;
      case 0x1e:
        param_3 = 0;
        break;
      case 0x1f:
        param_3 = 1;
        break;
      case 0x20:
        param_3 = 2;
        break;
      case 0x21:
        param_3 = 3;
      }
      param_4 = param_4 + 1;
    } while (param_4 < 5);
  }
code_r0x00054479:
  return 0;
}

