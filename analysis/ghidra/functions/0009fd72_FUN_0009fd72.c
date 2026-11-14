/* 0009fd72 FUN_0009fd72 */

int FUN_0009fd72(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  char *pcVar5;
  
  iVar2 = FUN_0009e3a2(param_1,1);
  if (iVar2 == 0) {
    return 0;
  }
  _CGContextSetTextDrawingMode(iVar2,3);
  _CGContextSetTextPosition(iVar2,0,0);
  uVar4 = 0xffffffff;
  pcVar5 = param_2;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  _CGContextShowText(iVar2,param_2,~uVar4 - 1);
  fVar3 = (float)_CGContextGetTextPosition(iVar2);
  _CGContextRestoreGState(iVar2);
  *(undefined1 *)(param_1 + 100) = 1;
  return (int)fVar3;
}

