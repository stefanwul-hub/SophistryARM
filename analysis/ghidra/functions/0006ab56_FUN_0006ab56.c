/* 0006ab56 FUN_0006ab56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0006ab56(undefined4 param_1,uint param_2,uint *param_3)

{
  short sVar1;
  uint uVar2;
  longdouble lVar3;
  float fVar4;
  
  if ((ushort)param_2 < 0x3b) {
    uVar2 = (int)param_2 >> 0x10;
    switch((ushort)param_2) {
    case 0:
      param_3[0xf] = param_3[0xf] + uVar2;
      break;
    case 1:
      param_3[0x10] = param_3[0x10] + uVar2;
      break;
    case 2:
      param_3[0x13] = param_3[0x13] + uVar2;
      break;
    case 3:
      param_3[0x14] = param_3[0x14] + uVar2;
      break;
    case 4:
      param_3[0xf] = param_3[0xf] + uVar2 * 0x8000;
      break;
    case 0x11:
      param_3[0xe] = (uint)((float)(int)uVar2 / 500.0);
      break;
    case 0x21:
      lVar3 = (longdouble)_pow(0,0x40000000,(double)((float)(int)uVar2 / 1200.0));
      param_3[0x17] = (uint)(float)((double)lVar3 * 1000.0);
      break;
    case 0x22:
      lVar3 = (longdouble)_pow(0,0x40000000,(double)((float)(int)uVar2 / 1200.0));
      param_3[0x18] = (uint)(float)((double)lVar3 * 1000.0);
      break;
    case 0x23:
      lVar3 = (longdouble)_pow(0,0x40000000,(double)((float)(int)uVar2 / 1200.0));
      param_3[0x19] = (uint)(float)((double)lVar3 * 1000.0);
      break;
    case 0x24:
      lVar3 = (longdouble)_pow(0,0x40000000,(double)((float)(int)uVar2 / 1200.0));
      param_3[0x1a] = (uint)(float)((double)lVar3 * 1000.0);
      break;
    case 0x25:
      if ((int)uVar2 < 0) {
        fVar4 = 0.0;
      }
      else if ((int)uVar2 < 0x3e9) {
        fVar4 = (float)(int)uVar2;
      }
      else {
        fVar4 = 1000.0;
      }
      lVar3 = (longdouble)_pow(0,0x40240000,(double)(fVar4 * 0.1 * -0.05));
      param_3[0x1b] = (uint)(float)lVar3;
      break;
    case 0x26:
      lVar3 = (longdouble)_pow(0,0x40000000,(double)((float)(int)uVar2 / 1200.0));
      param_3[0x1c] = (uint)(float)((double)lVar3 * 1000.0);
      break;
    case 0x2b:
      param_3[9] = param_2 >> 0x10 & 0xff;
      param_3[10] = param_2 >> 0x18;
      break;
    case 0x2c:
      param_3[0xb] = param_2 >> 0x10 & 0xff;
      param_3[0xc] = param_2 >> 0x18;
      break;
    case 0x2d:
      param_3[0x13] = param_3[0x13] + uVar2 * 0x8000;
      break;
    case 0x30:
      fVar4 = (float)param_3[0xd];
      lVar3 = (longdouble)_pow(0,0x40240000,(double)((float)(int)uVar2 / -200.0));
      param_3[0xd] = (uint)(fVar4 * (float)lVar3);
      break;
    case 0x32:
      param_3[0x14] = param_3[0x14] + uVar2 * 0x8000;
      break;
    case 0x33:
      fVar4 = (float)param_3[8];
      lVar3 = (longdouble)_pow(0,0x40000000,(double)((float)(int)uVar2 / 12.0));
      param_3[8] = (uint)(fVar4 * (float)lVar3);
      break;
    case 0x34:
      fVar4 = (float)param_3[8];
      lVar3 = (longdouble)_pow(0,0x40000000,(double)((float)(int)uVar2 / 1200.0));
      param_3[8] = (uint)(fVar4 * (float)lVar3);
      break;
    case 0x35:
      *param_3 = uVar2;
      break;
    case 0x36:
      if ((uVar2 & 1) == 1) {
        *(undefined1 *)(param_3 + 0x16) = 1;
        *(undefined1 *)((int)param_3 + 0x59) = 1;
      }
      else if ((uVar2 & 1) == 3) {
        *(undefined1 *)(param_3 + 0x16) = 1;
      }
      else {
        *(undefined1 *)(param_3 + 0x16) = 0;
        *(undefined1 *)((int)param_3 + 0x59) = 0;
      }
      break;
    case 0x3a:
      sVar1 = (short)(param_2 >> 0x10);
      if (sVar1 != -1) {
        if (sVar1 == 0xff) {
          param_3[7] = 0x3c;
        }
        else {
          uVar2 = 0x3c;
          if ((int)sVar1 + 1U < 0x81) {
            uVar2 = (int)sVar1;
          }
          param_3[7] = uVar2;
        }
      }
    }
  }
  return;
}

