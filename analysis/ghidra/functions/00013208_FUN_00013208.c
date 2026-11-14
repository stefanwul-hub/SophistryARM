/* 00013208 FUN_00013208 */

int FUN_00013208(int param_1,int param_2)

{
  if (param_2 < 0x10) {
    return param_1 + 0x174 + param_2 * 4;
  }
  return 0;
}

