/* 000137fe FUN_000137fe */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

longdouble FUN_000137fe(int param_1,undefined4 param_2)

{
  float fVar1;
  
  switch(param_2) {
  case 0:
    fVar1 = 360.0;
    break;
  case 1:
    fVar1 = 240.0;
    break;
  case 2:
    fVar1 = 159.996;
    break;
  case 3:
    fVar1 = 180.0;
    break;
  case 4:
    fVar1 = 120.0;
    break;
  case 5:
    fVar1 = 79.998;
    break;
  case 6:
    fVar1 = 90.0;
    break;
  default:
    fVar1 = 60.0;
    break;
  case 8:
    fVar1 = 39.996;
    break;
  case 9:
    fVar1 = 45.0;
    break;
  case 10:
    fVar1 = 30.0;
    break;
  case 0xb:
    fVar1 = 19.998;
    break;
  case 0xc:
    fVar1 = 22.5;
    break;
  case 0xd:
    fVar1 = 15.0;
    break;
  case 0xe:
    fVar1 = 9.996;
    break;
  case 0xf:
    fVar1 = 11.25;
    break;
  case 0x10:
    fVar1 = 7.5;
    break;
  case 0x11:
    fVar1 = 4.998;
    break;
  case 0x12:
    fVar1 = 3.75;
    break;
  case 0x13:
    fVar1 = 75.0;
    break;
  case 0x14:
    fVar1 = 105.0;
    break;
  case 0x15:
    fVar1 = 135.0;
    break;
  case 0x16:
    fVar1 = 150.0;
    break;
  case 0x17:
    fVar1 = 165.0;
    break;
  case 0x18:
    fVar1 = 195.0;
    break;
  case 0x19:
    fVar1 = 210.0;
    break;
  case 0x1a:
    fVar1 = 225.0;
    break;
  case 0xfffffff4:
    fVar1 = 5760.0;
    break;
  case 0xfffffff5:
    fVar1 = 3840.0;
    break;
  case 0xfffffff6:
    fVar1 = 2559.9958;
    break;
  case 0xfffffff7:
    fVar1 = 2880.0;
    break;
  case 0xfffffff8:
    fVar1 = 1920.0;
    break;
  case 0xfffffff9:
    fVar1 = 1279.9979;
    break;
  case 0xfffffffa:
    fVar1 = 1440.0;
    break;
  case 0xfffffffb:
    fVar1 = 960.0;
    break;
  case 0xfffffffc:
    fVar1 = 639.99603;
    break;
  case 0xfffffffd:
    fVar1 = 720.0;
    break;
  case 0xfffffffe:
    fVar1 = 480.0;
    break;
  case 0xffffffff:
    fVar1 = 319.99802;
  }
  return (longdouble)(*(float *)(param_1 + 0x140) * fVar1 * *(float *)(param_1 + 0x154));
}

