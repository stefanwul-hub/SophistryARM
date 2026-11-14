/* 00068500 FUN_00068500 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00068500(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined *puVar1;
  
  if (param_2 != 0) {
    Tone_c_vslot_10(param_1,param_2,param_3,param_5,param_1 + 0x13808,&DAT_000138ac + param_1,0xa0,
                    0xc);
    *(int *)(&DAT_00013958 + param_1) = param_2;
    *(undefined4 *)(&DAT_0001395c + param_1) = param_3;
    FUN_0007a45e(param_1 + 0x5c0c,*(undefined4 *)(&DAT_00013708 + param_1),
                 *(undefined4 *)(&DAT_0001370c + param_1),*(undefined4 *)(&DAT_00013710 + param_1),
                 param_4);
    FUN_0007a45e(param_1 + 0x60a4,*(undefined4 *)(&DAT_00013714 + param_1),
                 *(undefined4 *)(&DAT_00013718 + param_1),*(undefined4 *)(&DAT_0001371c + param_1),
                 param_4);
    FUN_0007a45e(param_1 + 0x653c,*(undefined4 *)(&DAT_00013720 + param_1),
                 *(undefined4 *)(&DAT_00013724 + param_1),*(undefined4 *)(&DAT_00013728 + param_1),
                 param_4);
    FUN_0007a45e(param_1 + 0x69d4,*(undefined4 *)(&DAT_0001372c + param_1),
                 *(undefined4 *)(&DAT_00013730 + param_1),*(undefined4 *)(&DAT_00013734 + param_1),
                 param_4);
    FUN_000b3266(param_1 + 0x6e6c,*(int *)(&DAT_00013958 + param_1) + 0x8a280,
                 *(undefined4 *)(&DAT_00013708 + param_1),*(undefined4 *)(&DAT_0001370c + param_1),
                 *(undefined4 *)(&DAT_00013710 + param_1));
    FUN_000b3266(param_1 + 0x7234,*(int *)(&DAT_00013958 + param_1) + 0x8a970,
                 *(undefined4 *)(&DAT_00013714 + param_1),*(undefined4 *)(&DAT_00013718 + param_1),
                 *(undefined4 *)(&DAT_0001371c + param_1));
    FUN_000b3266(param_1 + 0x75fc,*(int *)(&DAT_00013958 + param_1) + 0x8b060,
                 *(undefined4 *)(&DAT_00013720 + param_1),*(undefined4 *)(&DAT_00013724 + param_1),
                 *(undefined4 *)(&DAT_00013728 + param_1));
    FUN_000b3266(param_1 + 0x79c4,*(int *)(&DAT_00013958 + param_1) + 0x8b750,
                 *(undefined4 *)(&DAT_0001372c + param_1),*(undefined4 *)(&DAT_00013730 + param_1),
                 *(undefined4 *)(&DAT_00013734 + param_1));
    puVar1 = PTR_DAT_00103830;
    FUN_00038be2(param_1 + 0x7d8c,*(int *)(&DAT_00013958 + param_1) + 0x8be40,
                 *(undefined4 *)(&DAT_00013708 + param_1),*(undefined4 *)(&DAT_0001370c + param_1),
                 *(undefined4 *)(&DAT_00013710 + param_1),PTR_DAT_00103830);
    FUN_00038be2(param_1 + 0x8018,*(int *)(&DAT_00013958 + param_1) + 0x8c528,
                 *(undefined4 *)(&DAT_00013714 + param_1),*(undefined4 *)(&DAT_00013718 + param_1),
                 *(undefined4 *)(&DAT_0001371c + param_1),puVar1);
    FUN_00038be2(param_1 + 0x82a4,*(int *)(&DAT_00013958 + param_1) + 0x8cc10,
                 *(undefined4 *)(&DAT_00013720 + param_1),*(undefined4 *)(&DAT_00013724 + param_1),
                 *(undefined4 *)(&DAT_00013728 + param_1),puVar1);
    FUN_00038be2(param_1 + 0x8530,*(int *)(&DAT_00013958 + param_1) + 0x8d2f8,
                 *(undefined4 *)(&DAT_0001372c + param_1),*(undefined4 *)(&DAT_00013730 + param_1),
                 *(undefined4 *)(&DAT_00013734 + param_1),puVar1);
    FUN_0003645a(param_1 + 0x87bc,*(int *)(&DAT_00013958 + param_1) + 0x8d9e0,
                 *(undefined4 *)(&DAT_00013708 + param_1),*(undefined4 *)(&DAT_0001370c + param_1),
                 *(undefined4 *)(&DAT_00013710 + param_1),*(undefined4 *)(&DAT_00013738 + param_1));
    FUN_0003645a(param_1 + 0x8c1c,*(int *)(&DAT_00013958 + param_1) + 0x97b98,
                 *(undefined4 *)(&DAT_00013714 + param_1),*(undefined4 *)(&DAT_00013718 + param_1),
                 *(undefined4 *)(&DAT_0001371c + param_1),*(undefined4 *)(&DAT_0001373c + param_1));
    FUN_0007704a(param_1 + 0xa4bc,*(undefined4 *)(&DAT_00013740 + param_1),
                 *(undefined4 *)(&DAT_00013744 + param_1),*(undefined4 *)(&DAT_00013750 + param_1),
                 *(undefined4 *)(&DAT_00013758 + param_1));
    FUN_0007704a(param_1 + 0xe7f8,*(undefined4 *)(&DAT_00013748 + param_1),
                 *(undefined4 *)(&DAT_0001374c + param_1),*(undefined4 *)(&DAT_00013754 + param_1),
                 *(undefined4 *)(&DAT_0001375c + param_1));
    FUN_000745da(param_1 + 0x12b34,*(undefined4 *)(&DAT_00013740 + param_1),
                 *(undefined4 *)(&DAT_00013744 + param_1),*(undefined4 *)(&DAT_00013750 + param_1),
                 *(undefined4 *)(&DAT_00013758 + param_1),*(undefined4 *)(&DAT_00013760 + param_1));
    FUN_000745da(param_1 + 0x12e10,*(undefined4 *)(&DAT_00013748 + param_1),
                 *(undefined4 *)(&DAT_0001374c + param_1),*(undefined4 *)(&DAT_00013754 + param_1),
                 *(undefined4 *)(&DAT_0001375c + param_1),*(undefined4 *)(&DAT_00013764 + param_1));
    FUN_000897ce(&UNK_000132e0 + param_1,*(undefined4 *)(&DAT_00013750 + param_1),
                 *(undefined4 *)(&DAT_00013758 + param_1));
    FUN_000897ce(&UNK_000134e8 + param_1,*(undefined4 *)(&DAT_00013754 + param_1),
                 *(undefined4 *)(&DAT_0001375c + param_1));
    FUN_00080186(param_1 + 0x907c,*(undefined4 *)(&DAT_00013768 + param_1));
    FUN_00080186(param_1 + 0x9284,*(undefined4 *)(&DAT_0001376c + param_1));
    FUN_00080186(param_1 + 0x948c,*(undefined4 *)(&DAT_00013770 + param_1));
    FUN_00080186();
    return;
  }
  return;
}

