/* 0009fe14 FUN_0009fe14 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0009fe14(int param_1,char *param_2,int *param_3,undefined4 param_4,int param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  int local_2c;
  
  if (param_2 != (char *)0x0) {
    iVar2 = param_3[1];
    iVar3 = *(int *)(param_1 + 0x14);
    local_2c = *(int *)(param_1 + 0x10) + *param_3;
    iVar5 = *(int *)(param_1 + 0x10) + param_3[2];
    iVar9 = iVar3 + param_3[3];
    iVar6 = FUN_0009e3a2(param_1,1);
    if (iVar6 != 0) {
      iVar7 = FUN_0009fd72(param_1,param_2);
      iVar4 = *(int *)(param_1 + 0x24);
      if (param_5 == 1) {
        local_2c = local_2c + ((iVar5 - local_2c) / 2 - iVar7 / 2);
      }
      else if (param_5 == 2) {
        local_2c = iVar5 - iVar7;
      }
      else {
        local_2c = local_2c + 1;
      }
      _CGContextSetShouldAntialias(iVar6,1);
      _CGContextSetTextDrawingMode(iVar6,0);
      _CGContextSetRGBFillColor
                (iVar6,(float)*(byte *)(param_1 + 0x30) / 255.0,
                 (float)*(byte *)(param_1 + 0x31) / 255.0,(float)*(byte *)(param_1 + 0x32) / 255.0,
                 (float)*(byte *)(param_1 + 0x33) / 255.0);
      _CGContextSetTextPosition
                (iVar6,(float)local_2c,
                 (float)(iVar9 + -1 + (iVar4 / 2 - (iVar9 - (iVar3 + iVar2)) / 2)));
      uVar8 = 0xffffffff;
      pcVar10 = param_2;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      _CGContextShowText(iVar6,param_2,~uVar8 - 1);
      _CGContextRestoreGState(iVar6);
      *(undefined1 *)(param_1 + 100) = 1;
    }
  }
  return;
}

