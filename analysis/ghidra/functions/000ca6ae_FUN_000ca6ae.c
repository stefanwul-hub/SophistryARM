/* 000ca6ae FUN_000ca6ae */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

void FUN_000ca6ae(void)

{
  int in_EAX;
  int in_EDX;
  
  if ((in_EDX == 0xffff) && (in_EAX == 1)) {
    DAT_000fcff0 = 0x54442d18;
    DAT_000fcff4 = 0x3ff921fb;
    DAT_000fcfe8 = 0x7f3321d2;
    DAT_000fcfec = 0x4012d97c;
    DAT_000fcfe0 = 0x3b000000;
    return;
  }
  return;
}

