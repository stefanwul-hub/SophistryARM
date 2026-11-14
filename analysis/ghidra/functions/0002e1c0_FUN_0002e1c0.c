/* 0002e1c0 FUN_0002e1c0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

uint FUN_0002e1c0(void)

{
  undefined1 auVar1 [12];
  undefined1 auVar2 [12];
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined1 auVar6 [16];
  uint64_t uVar7;
  uint local_5c;
  mach_timebase_info local_14;
  
  if ((DAT_000fc210 == 0.0) && (!NAN(DAT_000fc210))) {
    _mach_timebase_info(&local_14);
    auVar1._4_4_ = local_14.numer;
    auVar1._0_4_ = local_14.numer;
    auVar1._8_4_ = 0x43300000;
    auVar2._4_4_ = local_14.denom;
    auVar2._0_4_ = local_14.denom;
    auVar2._8_4_ = 0x43300000;
    DAT_000fc210 = (((auVar1._4_8_ - 4503599627370496.0) + 0.0) * 1e-06) /
                   ((auVar2._4_8_ - 4503599627370496.0) + 0.0);
  }
  uVar7 = _mach_absolute_time();
  uVar3 = (undefined4)(uVar7 >> 0x20);
  auVar6._4_4_ = (int)uVar7;
  auVar6._0_4_ = uVar3;
  auVar6._8_4_ = (int)uVar7;
  auVar6._12_4_ = 0x43300000;
  dVar4 = (((double)CONCAT44(0x45300000,uVar3) - 1.9342813113834067e+25) +
          (auVar6._8_8_ - 4503599627370496.0)) * DAT_000fc210;
  dVar5 = dVar4;
  if (4294967295.0 <= dVar4) {
    dVar5 = 4294967295.0;
  }
  if (dVar5 <= 0.0) {
    dVar5 = 0.0;
  }
  local_5c = (uint)(2147483648.0 <= dVar4) * -0x80000000 ^
             (int)(dVar5 - (double)(-(ulonglong)(2147483648.0 <= dVar4) & 0x41e0000000000000));
  return local_5c;
}

