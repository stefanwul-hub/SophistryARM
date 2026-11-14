/* 00082cbe AUCronoX_vslot_27 */

undefined4 AUCronoX_vslot_27(undefined4 param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  undefined3 uVar2;
  uint uVar3;
  int iVar4;
  
  FUN_00002918(param_1);
  if ((param_2 != 0) || (*param_4 = 0x20a, param_3 == 0)) {
    return 0;
  }
  iVar1 = 0;
  uVar3 = 0;
LAB_00082cec:
  if (iVar1 == 0x33c) {
    iVar4 = 0x33e;
    iVar1 = 0x33f;
  }
  else {
    uVar2 = (undefined3)((uint)iVar1 >> 8);
    if (iVar1 == 0x1e8) {
      iVar4 = 0x1ec;
      iVar1 = CONCAT31(uVar2,0xed);
    }
    else {
      iVar4 = iVar1;
      if (iVar1 != 0x1f2) goto LAB_00082d3e;
      iVar1 = 0x1ff;
      iVar4 = CONCAT31(uVar2,0xfe);
    }
  }
LAB_00082cfd:
  do {
    *(int *)(param_3 + uVar3 * 4) = iVar4;
    uVar3 = uVar3 + 1;
    if (*param_4 <= uVar3) {
      return 0;
    }
    if (iVar1 == 0x1c) {
      iVar4 = 0x20;
LAB_00082d3e:
      iVar1 = 0x20c;
      if (iVar4 == 0x205) {
        iVar4 = 0x20b;
        goto LAB_00082cfd;
      }
    }
    else {
      if (iVar1 == 0x40) {
        iVar4 = 0x44;
        goto LAB_00082d3e;
      }
      if (iVar1 != 0x58) goto LAB_00082cec;
      iVar4 = 0x5c;
    }
    iVar1 = iVar4 + 1;
  } while( true );
}

