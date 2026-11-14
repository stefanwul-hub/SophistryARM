/* 0009e6ec FUN_0009e6ec */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0009e6ec(int param_1,uint param_2)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  
  bVar1 = (byte)(param_2 >> 0x18);
  cVar2 = (char)(param_2 >> 8);
  cVar3 = (char)(param_2 >> 0x10);
  if ((((*(char *)(param_1 + 0x44) != (char)param_2) || (cVar2 != *(char *)(param_1 + 0x45))) ||
      (cVar3 != *(char *)(param_1 + 0x46))) || (bVar1 != *(byte *)(param_1 + 0x47))) {
    *(char *)(param_1 + 0x44) = (char)param_2;
    *(char *)(param_1 + 0x45) = cVar2;
    *(char *)(param_1 + 0x46) = cVar3;
    *(byte *)(param_1 + 0x47) = bVar1;
    if (*(int *)(param_1 + 0x60) != 0) {
      _CGContextSetRGBFillColor
                (*(int *)(param_1 + 0x60),(float)(param_2 & 0xff) / 255.0,
                 (float)(param_2 >> 8 & 0xff) / 255.0,(float)(param_2 >> 0x10 & 0xff) / 255.0,
                 (float)bVar1 / 255.0);
    }
  }
  return;
}

