/* 000818cc FUN_000818cc */

void FUN_000818cc(int param_1,float param_2,undefined1 *param_3)

{
  float fVar1;
  float fVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  
  lVar3 = (longdouble)FUN_00001ace(param_1,0);
  fVar1 = *(float *)(param_1 + 0xe8);
  lVar4 = (longdouble)FUN_00001ace(param_1,1);
  fVar2 = *(float *)(param_1 + 0xe8);
  lVar5 = (longdouble)FUN_00001ace(param_1,2);
  if (param_2 < (float)lVar3 * fVar1) {
    *param_3 = *(undefined1 *)(param_1 + 0xc0);
    param_3[1] = *(undefined1 *)(param_1 + 0xc1);
    param_3[2] = *(undefined1 *)(param_1 + 0xc2);
    param_3[3] = *(undefined1 *)(param_1 + 0xc3);
    return;
  }
  if (((float)lVar4 * fVar2 <= param_2) && (param_2 < (float)lVar5 * *(float *)(param_1 + 0xe8))) {
    *param_3 = *(undefined1 *)(param_1 + 0xc4);
    param_3[1] = *(undefined1 *)(param_1 + 0xc5);
    param_3[2] = *(undefined1 *)(param_1 + 0xc6);
    param_3[3] = *(undefined1 *)(param_1 + 199);
    return;
  }
  *param_3 = *(undefined1 *)(param_1 + 0xbc);
  param_3[1] = *(undefined1 *)(param_1 + 0xbd);
  param_3[2] = *(undefined1 *)(param_1 + 0xbe);
  param_3[3] = *(undefined1 *)(param_1 + 0xbf);
  return;
}

