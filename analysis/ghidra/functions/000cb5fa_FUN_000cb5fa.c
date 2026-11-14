/* 000cb5fa FUN_000cb5fa */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

void FUN_000cb5fa(void)

{
  int in_EAX;
  int in_EDX;
  
  if ((in_EDX == 0xffff) && (in_EAX == 1)) {
    DAT_000fd5c0 = &cf_FactoryPreset;
    return;
  }
  return;
}

