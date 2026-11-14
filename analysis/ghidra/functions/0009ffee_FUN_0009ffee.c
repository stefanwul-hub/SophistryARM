/* 0009ffee FUN_0009ffee */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0009ffee(int param_1,int param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  
  if (*(int *)(param_1 + 0x60) != 0) {
    iVar6 = FUN_0009e3a2(param_2,0);
    if (iVar6 != 0) {
      iVar7 = _CGBitmapContextGetBytesPerRow(*(undefined4 *)(param_1 + 0x60));
      sVar5 = _CGBitmapContextGetBitsPerPixel(*(undefined4 *)(param_1 + 0x60));
      iVar8 = _CGBitmapContextGetHeight(*(undefined4 *)(param_1 + 0x60));
      uVar9 = _CGBitmapContextGetData(*(undefined4 *)(param_1 + 0x60));
      uVar10 = _CGDataProviderCreateWithData(0,uVar9,iVar7 * iVar8,0);
      uVar11 = _CGBitmapContextGetAlphaInfo(*(undefined4 *)(param_1 + 0x60));
      uVar9 = DAT_000fd500;
      uVar12 = _CGBitmapContextGetHeight(*(undefined4 *)(param_1 + 0x60));
      uVar13 = _CGBitmapContextGetWidth(*(undefined4 *)(param_1 + 0x60));
      iVar7 = _CGImageCreate(uVar13,uVar12,8,(int)sVar5,iVar7,uVar9,uVar11,uVar10,0,0,0);
      if (iVar7 != 0) {
        iVar8 = *param_3;
        iVar1 = *(int *)(param_2 + 0x10);
        iVar15 = -(param_3[1] + *(int *)(param_2 + 0x14));
        iVar2 = *(int *)(param_1 + 0x70);
        iVar3 = *(int *)(param_1 + 0x74);
        iVar4 = *(int *)(param_1 + 0x70);
        iVar14 = param_3[3] - param_3[1];
        _CGContextClipToRect
                  (iVar6,(float)(iVar8 + iVar1),(float)(iVar15 - iVar14),(float)(param_3[2] - iVar8)
                   ,(float)iVar14);
        _CGContextDrawImage(iVar6,(float)((iVar8 - param_4) + iVar1),
                            (float)(iVar15 - (iVar2 - param_5)),(float)iVar3,(float)iVar4,iVar7);
        _CGImageRelease(iVar7);
      }
      _CGDataProviderRelease(uVar10);
      _CGContextRestoreGState(iVar6);
      *(undefined1 *)(param_2 + 100) = 1;
    }
  }
  return;
}

