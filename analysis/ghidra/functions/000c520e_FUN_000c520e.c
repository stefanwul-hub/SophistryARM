/* 000c520e FUN_000c520e */

undefined4 * FUN_000c520e(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char cVar9;
  undefined4 *puVar10;
  code *in_stack_0000002c;
  
  while( true ) {
    while( true ) {
      cVar9 = (*in_stack_0000002c)(param_1,&stack0x0000000c);
      if (cVar9 == '\0') break;
      param_1 = param_1 + 8;
    }
    do {
      puVar10 = param_2;
      param_2 = puVar10 + -8;
      cVar9 = (*in_stack_0000002c)(&stack0x0000000c,param_2);
    } while (cVar9 != '\0');
    if (param_2 <= param_1) break;
    uVar1 = *param_1;
    uVar2 = param_1[1];
    uVar3 = param_1[2];
    uVar4 = param_1[3];
    uVar5 = param_1[4];
    uVar6 = param_1[5];
    uVar7 = param_1[6];
    uVar8 = param_1[7];
    *param_1 = *param_2;
    param_1[1] = puVar10[-7];
    param_1[2] = puVar10[-6];
    param_1[3] = puVar10[-5];
    param_1[4] = puVar10[-4];
    param_1[5] = puVar10[-3];
    param_1[6] = puVar10[-2];
    param_1[7] = puVar10[-1];
    *param_2 = uVar1;
    puVar10[-7] = uVar2;
    puVar10[-6] = uVar3;
    puVar10[-5] = uVar4;
    puVar10[-4] = uVar5;
    puVar10[-3] = uVar6;
    puVar10[-2] = uVar7;
    puVar10[-1] = uVar8;
    param_1 = param_1 + 8;
  }
  return param_1;
}

