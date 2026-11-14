/* 0009fcae FUN_0009fcae */

void FUN_0009fcae(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = param_2[2];
  iVar4 = param_2[3];
  iVar5 = *(int *)(param_1 + 0x14);
  iVar6 = *(int *)(param_1 + 0x10);
  iVar1 = iVar6 + *param_2;
  iVar2 = iVar5 + param_2[1];
  iVar7 = FUN_0009e3a2(param_1,1);
  _CGContextFillRect(iVar7,(float)iVar1,(float)iVar2,(float)((iVar6 + iVar3) - iVar1),
                     (float)((iVar5 + iVar4) - iVar2));
  if (iVar7 != 0) {
    _CGContextRestoreGState(iVar7);
    *(undefined1 *)(param_1 + 100) = 1;
  }
  return;
}

