/* 0000796c CModDepthDisp_vslot_72 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble CModDepthDisp_vslot_72(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  
  *(undefined4 *)(param_1 + 0xf8) = 0xbf800000;
  if (*(int *)(param_1 + 0xf4) == 0) {
    fVar4 = (float)(((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0xc)) / 2 +
                    *(int *)(param_1 + 0xc)) - *(int *)(param_2 + 4)) / 150.0;
  }
  else {
    uVar2 = *(int *)(param_2 + 4) -
            ((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0xc)) / 2 + *(int *)(param_1 + 0xc));
    uVar1 = uVar2;
    if (0x7fffffff < uVar2) {
      uVar1 = -uVar2;
    }
    if (uVar1 == 0) {
      iVar3 = -1;
    }
    else {
      iVar3 = -((int)uVar2 / (int)uVar1);
      if ((int)uVar1 < 0x79) {
        if ((int)uVar1 < 0x5b) {
          if ((int)uVar1 < 0x3d) {
            if (0x1e < (int)uVar1) {
              uVar1 = uVar1 * 2 - 0x1e;
            }
          }
          else {
            uVar1 = uVar1 * 4 - 0x96;
          }
        }
        else {
          uVar1 = uVar1 * 8 - 0x1fe;
        }
      }
      else {
        uVar1 = uVar1 * 0x10 - 0x5be;
      }
    }
    fVar4 = (float)(int)(uVar1 * iVar3) / ((float)*(int *)(param_1 + 0xf4) * 100.0);
  }
  return (longdouble)((fVar4 + 1.0) * 0.5 + (*(float *)(param_1 + 0x78) - 0.5));
}

