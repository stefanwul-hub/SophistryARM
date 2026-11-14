/* 000c9ada FUN_000c9ada */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000c9ada(void)

{
  int in_EAX;
  void *pvVar1;
  int in_EDX;
  
  if ((in_EDX == 0xffff) && (in_EAX == 1)) {
    DAT_000fc0e8 = 0x54442d18;
    DAT_000fc0ec = 0x3ff921fb;
    DAT_000fc0e0 = 0x7f3321d2;
    DAT_000fc0e4 = 0x4012d97c;
    pvVar1 = operator_new(0x34);
    FUN_0002de30(pvVar1);
    DAT_00101ea0 = pvVar1;
    return;
  }
  return;
}

