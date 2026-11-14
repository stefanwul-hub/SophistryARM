/* 000ae9ec FUN_000ae9ec */

void FUN_000ae9ec(undefined4 param_1,int param_2)

{
  if ((param_2 != 0) && (*(code **)(param_2 + 0x10) != (code *)0x0)) {
    param_1 = *(undefined4 *)(param_2 + 0xc);
                    /* WARNING: Could not recover jumptable at 0x000aea04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_2 + 0x10))();
    return;
  }
  return;
}

