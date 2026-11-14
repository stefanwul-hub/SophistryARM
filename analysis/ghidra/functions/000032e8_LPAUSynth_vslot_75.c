/* 000032e8 LPAUSynth_vslot_75 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 LPAUSynth_vslot_75(int param_1)

{
  if (*(char *)(param_1 + 0x32b432) == '\0') {
    *(undefined1 *)(param_1 + 0x32b432) = 1;
    FUN_0002e53a(param_1 + 0x398c,
                 "Plug-in IO configuration has been changed. Please quit restart your audio host software."
                 ,"IO Changed!");
  }
  return 1;
}

