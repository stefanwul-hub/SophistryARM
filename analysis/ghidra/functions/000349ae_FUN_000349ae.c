/* 000349ae FUN_000349ae */

int FUN_000349ae(int param_1,int param_2,int param_3)

{
  if ((param_2 < 1) && (param_3 < 0x40)) {
    return param_3 * 0x274 + 0x1e0 + param_2 * 0x9d00 + param_1;
  }
  return 0;
}

