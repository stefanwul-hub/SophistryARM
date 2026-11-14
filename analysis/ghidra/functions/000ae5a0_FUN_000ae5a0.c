/* 000ae5a0 FUN_000ae5a0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000ae5a0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    iVar2 = _DecrementAtomic(piVar1 + 1);
    if (iVar2 == 1) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
  }
  puVar3 = (undefined4 *)operator_new(0x10);
  *puVar3 = PTR_DAT_001038d8 + 8;
  puVar3[1] = 1;
  *puVar3 = PTR_DAT_001038d4 + 8;
  puVar4 = (undefined4 *)_malloc(0xc);
  puVar3[2] = puVar4;
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = 0;
  puVar3[3] = 0xc;
  *param_1 = (int)puVar3;
  *(undefined4 *)puVar3[2] = param_2;
  return;
}

