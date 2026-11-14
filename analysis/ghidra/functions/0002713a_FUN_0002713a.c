/* 0002713a FUN_0002713a */

void FUN_0002713a(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  if (((((0 < param_2) && (param_2 < 0xc0)) && (-1 < param_3)) && ((-1 < param_4 && (param_5 != 0)))
      ) && ((*(int *)(param_5 + 0xc) != 0 &&
            ((*(int *)(param_5 + 0x10) != 0 && (*(int *)(param_1 + 0x25858 + param_2 * 4) == 0))))))
  {
    uVar1 = *(undefined4 *)(param_5 + 0xc);
    uVar2 = *(undefined4 *)(param_5 + 0x10);
    pvVar3 = operator_new(0x68);
    FUN_00007d88(pvVar3,param_3,param_4,uVar1,uVar2,*(undefined4 *)(param_1 + 0x1c),param_5,0);
    *(void **)(param_1 + 0x25858 + param_2 * 4) = pvVar3;
  }
  return;
}

