/* 0009e3a2 FUN_0009e3a2 */

int FUN_0009e3a2(int param_1,char param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60);
  if (iVar1 != 0) {
    _CGContextSaveGState(iVar1);
    _CGContextScaleCTM(*(undefined4 *)(param_1 + 0x60),0x3f800000,0xbf800000);
    _CGContextClipToRect
              (*(undefined4 *)(param_1 + 0x60),(float)*(int *)(param_1 + 0x50),
               (float)*(int *)(param_1 + 0x54),
               (float)(*(int *)(param_1 + 0x58) - *(int *)(param_1 + 0x50)),
               (float)(*(int *)(param_1 + 0x5c) - *(int *)(param_1 + 0x54)));
    if (param_2 == '\0') {
      _CGContextScaleCTM(*(undefined4 *)(param_1 + 0x60),0x3f800000,0xbf800000);
    }
    iVar1 = *(int *)(param_1 + 0x60);
  }
  return iVar1;
}

