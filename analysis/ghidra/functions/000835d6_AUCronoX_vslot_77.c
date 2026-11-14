/* 000835d6 AUCronoX_vslot_77 */

undefined4 AUCronoX_vslot_77(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = *param_2;
  if (600 < uVar1) {
    return 0;
  }
  if ((((((int)uVar1 < 0x1e8) && (3 < uVar1 - 0x1c)) && (3 < uVar1 - 0x40)) &&
      ((3 < uVar1 - 0x58 && (1 < uVar1 - 0x33c)))) ||
     ((uVar1 - 0x1ec < 6 || ((uVar1 - 0x1fe < 7 || (uVar1 - 0x20b < 0x23)))))) {
    return 1;
  }
  if (uVar1 == 0x205) {
    *param_2 = 0xdb;
    return 1;
  }
  if ((int)uVar1 < 0x206) {
    if (uVar1 != 0x1e9) {
      if (0x1e9 < (int)uVar1) {
        if (uVar1 == 0x1f6) {
          *param_2 = 0x1f0;
          return 1;
        }
        if (0x1f6 < (int)uVar1) {
          if (uVar1 == 0x1fa) {
            *param_2 = 2;
            return 1;
          }
          if ((int)uVar1 < 0x1fb) {
            if (uVar1 == 0x1f8) {
              *param_2 = 0;
              return 1;
            }
            if ((int)uVar1 < 0x1f9) {
              *param_2 = 0x1f1;
              return 1;
            }
            *param_2 = 1;
            return 1;
          }
          if (uVar1 == 0x1fc) {
            *param_2 = 0x70;
            return 1;
          }
          if ((int)uVar1 < 0x1fc) {
            *param_2 = 3;
            return 1;
          }
          if (uVar1 == 0x1fd) {
            *param_2 = 0x71;
            return 1;
          }
          return 0;
        }
        if (uVar1 == 0x1f2) {
          *param_2 = 0x1ec;
          return 1;
        }
        if (0x1f2 < (int)uVar1) {
          if (uVar1 == 500) {
            *param_2 = 0x1ee;
            return 1;
          }
          if ((int)uVar1 < 0x1f5) {
            *param_2 = 0x1ed;
            return 1;
          }
          *param_2 = 0x1ef;
          return 1;
        }
        if (uVar1 != 0x1ea) {
          if (uVar1 != 0x1eb) {
            return 0;
          }
          goto LAB_000837d1;
        }
LAB_0008389f:
        *param_2 = 0x74;
        return 1;
      }
      if (uVar1 != 0x42) {
        if (0x42 < (int)uVar1) {
          if (uVar1 != 0x59) {
            if ((int)uVar1 < 0x5a) {
              if (uVar1 != 0x43) {
                if (uVar1 != 0x58) {
                  return 0;
                }
                goto LAB_0008383d;
              }
            }
            else if (uVar1 != 0x5b) {
              if (0x5a < (int)uVar1) {
                if (uVar1 != 0x1e8) {
                  return 0;
                }
                goto LAB_0008393e;
              }
              goto LAB_000837de;
            }
LAB_00083963:
            *param_2 = 0x1e7;
            return 1;
          }
          goto LAB_00083673;
        }
        if (uVar1 != 0x1e) {
          if ((int)uVar1 < 0x1f) {
            if (uVar1 == 0x1c) {
LAB_0008383d:
              *param_2 = 0x1e4;
              return 1;
            }
            if (uVar1 != 0x1d) {
              return 0;
            }
          }
          else {
            if (uVar1 == 0x40) goto LAB_0008383d;
            if ((int)uVar1 < 0x41) {
              if (uVar1 != 0x1f) {
                return 0;
              }
              goto LAB_00083963;
            }
          }
LAB_00083673:
          *param_2 = 0x1e5;
          return 1;
        }
      }
LAB_000837de:
      *param_2 = 0x1e6;
      return 1;
    }
  }
  else {
    if (uVar1 == 0x24c) {
      *param_2 = 5;
      return 1;
    }
    if ((int)uVar1 < 0x24d) {
      if (uVar1 == 0x244) {
        *param_2 = 0xd6;
        return 1;
      }
      if (0x244 < (int)uVar1) {
        if (uVar1 == 0x248) {
          *param_2 = 0xda;
          return 1;
        }
        if (0x248 < (int)uVar1) {
          if (uVar1 == 0x24a) {
            *param_2 = 4;
            return 1;
          }
          if ((int)uVar1 < 0x24b) {
            *param_2 = 8;
            return 1;
          }
          *param_2 = 9;
          return 1;
        }
        if (uVar1 == 0x246) {
          *param_2 = 0xd8;
          return 1;
        }
        if ((int)uVar1 < 0x247) {
          *param_2 = 0xd7;
          return 1;
        }
        *param_2 = 0xd9;
        return 1;
      }
      if (uVar1 == 0x208) {
        *param_2 = 0xde;
        return 1;
      }
      if (0x208 < (int)uVar1) {
        if (uVar1 == 0x20a) {
          *param_2 = 0xe0;
          return 1;
        }
        if (0x209 < (int)uVar1) {
          if (uVar1 != 0x243) {
            return 0;
          }
          *param_2 = 0xd5;
          return 1;
        }
        *param_2 = 0xdf;
        return 1;
      }
      if (uVar1 == 0x206) {
        *param_2 = 0xdc;
        return 1;
      }
      if (uVar1 != 0x207) {
        return 0;
      }
      *param_2 = 0xdd;
      return 1;
    }
    if (uVar1 != 0x253) {
      if ((int)uVar1 < 0x254) {
        if (uVar1 == 0x24f) {
          *param_2 = 0xb;
          return 1;
        }
        if ((int)uVar1 < 0x250) {
          if (uVar1 == 0x24d) {
            *param_2 = 10;
            return 1;
          }
          if (uVar1 == 0x24e) {
            *param_2 = 6;
            return 1;
          }
          return 0;
        }
        if (uVar1 != 0x251) {
          if ((int)uVar1 < 0x252) {
            *param_2 = 7;
            return 1;
          }
          goto LAB_0008389f;
        }
LAB_0008393e:
        *param_2 = 0x72;
        return 1;
      }
      if (uVar1 != 599) {
        if ((int)uVar1 < 600) {
          if (uVar1 == 0x255) goto LAB_0008393e;
          if (0x255 < (int)uVar1) goto LAB_0008389f;
        }
        else {
          if (uVar1 == 0x33c) goto LAB_0008383d;
          if (uVar1 == 0x33d) goto LAB_00083673;
          if (uVar1 != 600) {
            return 0;
          }
        }
LAB_000837d1:
        *param_2 = 0x75;
        return 1;
      }
    }
  }
  *param_2 = 0x73;
  return 1;
}

