/* 000cb450 FUN_000cb450 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000cb450(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int in_EDX;
  undefined2 local_112;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined2 local_d8;
  undefined1 local_d6;
  int local_10;
  
  if ((in_EDX == 0xffff) && (in_EAX == 1)) {
    DAT_000fd500 = 0;
    local_112 = 5;
    local_110 = 0x7379532f;
    local_10c = 0x2f6d6574;
    local_108 = 0x7262694c;
    local_104 = 0x2f797261;
    local_100 = 0x6f6c6f43;
    local_fc = 0x6e795372;
    local_f8 = 0x72502f63;
    local_f4 = 0x6c69666f;
    local_f0 = 0x472f7365;
    local_ec = 0x72656e65;
    local_e8 = 0x52206369;
    local_e4 = 0x50204247;
    local_e0 = 0x69666f72;
    local_dc = 0x692e656c;
    local_d8 = 0x6363;
    local_d6 = 0;
    iVar1 = _CMOpenProfile(&local_10,&local_112);
    iVar2 = 0;
    if (iVar1 == 0) {
      iVar2 = local_10;
    }
    local_10 = iVar2;
    if (iVar2 != 0) {
      DAT_000fd500 = _CGColorSpaceCreateWithPlatformColorSpace(iVar2);
      _CMCloseProfile(iVar2);
    }
    if (DAT_000fd500 == 0) {
      DAT_000fd500 = _CGColorSpaceCreateDeviceRGB();
    }
    iVar2 = _CFBundleGetBundleWithIdentifier(&cf_com_apple_CoreGraphics);
    if (iVar2 != 0) {
      DAT_000fd508 = _CFBundleGetFunctionPointerForName(iVar2,&cf_CGImageCreateWithImageInRect);
      DAT_000fd504 = _CFBundleGetFunctionPointerForName(iVar2,&cf_CGContextStrokeLineSegments);
    }
    FUN_000013ff(FUN_0009ddde,0,PTR_001038a8);
    return;
  }
  return;
}

