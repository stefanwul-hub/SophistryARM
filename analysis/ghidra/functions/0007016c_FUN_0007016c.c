/* 0007016c FUN_0007016c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0007016c(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined *puVar2;
  int iVar3;
  
  FUN_00013e4c(param_1);
  *param_1 = &PTR_StepSeq_c_vslot_0_000f10a8;
  param_1[0x7d] = PTR_DAT_00103808 + 8;
  *(undefined1 *)(param_1 + 0x7e) = 0;
  param_1[0x7f] = 0xffffffff;
  param_1[0x80] = 0xffffffff;
  puVar2 = PTR_DAT_00103814 + 8;
  param_1[0x7d] = puVar2;
  param_1[0x81] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x7e) = 1;
  puVar1 = param_1 + 0xc6;
  iVar3 = 0x20;
  do {
    puVar1[2] = puVar2;
    puVar1[4] = 0xffffffff;
    puVar1[5] = 0xffffffff;
    puVar1[6] = 0xffffffff;
    *(undefined1 *)(puVar1 + 3) = 1;
    puVar1 = puVar1 + 7;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  param_1[0x1d9] = puVar2;
  param_1[0x1db] = 0xffffffff;
  param_1[0x1dc] = 0xffffffff;
  param_1[0x1dd] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x1da) = 1;
  if (param_2 != 0) {
    if (param_3 < 2) {
      param_3 = 2;
      iVar3 = param_3;
    }
    else {
      iVar3 = 0x80;
      if (param_3 < 0x81) {
        iVar3 = param_3;
      }
    }
    param_3 = iVar3;
    param_1[0x75] = param_2;
    param_1[0x76] = 0;
    param_1[0x77] = param_3;
    param_1[0x78] = 0x462ca800;
    param_1[0x7b] = 0x10;
    param_1[0x7c] = 0x3f000000;
    param_1[0x79] = 0x1595;
    param_1[0x7a] = 0x1595;
    param_1[0x7f] = 0xfffffffe;
    param_1[0x80] = 0xfffffffe;
    param_1[0x82] = 0;
    iVar3 = 0x80;
    puVar1 = param_1;
    do {
      *(undefined1 *)(puVar1 + 0x83) = 0x3c;
      *(undefined1 *)(puVar1 + 0xa3) = 100;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    param_1[0xc3] = 3;
    param_1[0xc4] = 0;
    param_1[0xc5] = 0;
    iVar3 = 0x20;
    puVar1 = param_1;
    do {
      *(undefined1 *)(puVar1 + 0xc6) = 0xff;
      *(undefined1 *)((int)puVar1 + 0x319) = 0xff;
      puVar1[199] = 0xffffffff;
      puVar1 = puVar1 + 7;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = 0x30;
    puVar1 = param_1;
    do {
      puVar1[0x1a6] = 0xffffffff;
      puVar1 = puVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    param_1[0x1d6] = 0;
    *(undefined1 *)(param_1 + 0x1d7) = 0xff;
    param_1[0x1df] = 0xffffffff;
    param_1[0x1de] = 0xffffffff;
    param_1[0x1e0] = 0;
    param_1[0x1e1] = 0xffffffff;
    param_1[0x1e2] = 0xffffffff;
    param_1[0x1e3] = 0;
    param_1[0x1e4] = 0;
    param_1[0x1e5] = 0;
    *(undefined1 *)(param_1 + 0x1e6) = 1;
    *(undefined1 *)((int)param_1 + 0x799) = 0x11;
    iVar3 = 0;
    puVar1 = param_1;
    do {
      *(undefined1 *)((int)puVar1 + 0x79a) = 0x3d;
      *(undefined1 *)((int)puVar1 + 0x79b) = 0x65;
      iVar3 = iVar3 + 1;
      puVar1 = (undefined4 *)((int)puVar1 + 2);
    } while (iVar3 != 0x80);
    *(undefined1 *)((int)param_1 + 0x89a) = 0;
    *(undefined1 *)((int)param_1 + 0x89b) = 1;
    param_1[0x227] = 0;
    *(undefined1 *)(param_1 + 0x228) = 0;
  }
  return;
}

