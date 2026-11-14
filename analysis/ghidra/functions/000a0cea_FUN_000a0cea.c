/* 000a0cea FUN_000a0cea */

void FUN_000a0cea(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float local_24;
  float local_20;
  
  iVar3 = *param_2 + *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 0x14) + param_2[1];
  iVar1 = FUN_0009e3a2(param_1,1);
  if (*(int *)(param_1 + 0x48) == 1) {
    local_24 = (float)*(int *)(param_1 + 0x3c);
    local_20 = local_24;
    _CGContextSetLineDash(iVar1,0,&local_24,2);
  }
  _CGContextBeginPath(iVar1);
  _CGContextMoveToPoint(iVar1,(float)*(int *)(param_1 + 0x34),(float)*(int *)(param_1 + 0x38));
  _CGContextAddLineToPoint(iVar1,(float)iVar3,(float)iVar2);
  _CGContextDrawPath(iVar1,2);
  if (iVar1 != 0) {
    _CGContextRestoreGState(iVar1);
    *(undefined1 *)(param_1 + 100) = 1;
  }
  *(int *)(param_1 + 0x34) = iVar3;
  *(int *)(param_1 + 0x38) = iVar2;
  return;
}

