/* 000a0ebc FUN_000a0ebc */

void FUN_000a0ebc(int param_1,int *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float local_24;
  float local_20;
  
  iVar2 = param_2[2];
  iVar3 = param_2[3];
  iVar4 = *(int *)(param_1 + 0x14);
  iVar5 = *(int *)(param_1 + 0x10);
  uVar1 = iVar5 + *param_2;
  iVar8 = param_2[1] + iVar4;
  iVar7 = FUN_0009e3a2(param_1,1);
  if (param_3 == 1) {
    cVar6 = '\0';
  }
  else {
    cVar6 = (param_3 == 2) + '\x02';
  }
  fVar9 = (float)(iVar8 + 1);
  fVar10 = (float)(int)uVar1;
  if (*(int *)(param_1 + 0x48) == 1) {
    local_24 = (float)*(int *)(param_1 + 0x3c);
    local_20 = local_24;
    _CGContextSetLineDash(iVar7,0,&local_24,2);
  }
  _CGContextBeginPath(iVar7);
  _CGContextMoveToPoint(iVar7,fVar10,fVar9);
  fVar11 = (float)(int)(~uVar1 + iVar5 + iVar2) + fVar10;
  _CGContextAddLineToPoint(iVar7,fVar11,fVar9);
  fVar9 = (float)(((iVar3 + iVar4) - iVar8) + -1) + fVar9;
  _CGContextAddLineToPoint(iVar7,fVar11,fVar9);
  _CGContextAddLineToPoint(iVar7,fVar10,fVar9);
  _CGContextClosePath(iVar7);
  _CGContextDrawPath(iVar7,cVar6);
  if (iVar7 != 0) {
    _CGContextRestoreGState(iVar7);
    *(undefined1 *)(param_1 + 100) = 1;
  }
  return;
}

