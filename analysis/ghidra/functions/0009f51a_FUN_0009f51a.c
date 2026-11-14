/* 0009f51a FUN_0009f51a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0009f51a(int param_1,uint param_2)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  
  bVar1 = (byte)(param_2 >> 0x18);
  cVar2 = (char)(param_2 >> 8);
  cVar3 = (char)(param_2 >> 0x10);
  if ((((*(char *)(param_1 + 0x40) != (char)param_2) || (cVar2 != *(char *)(param_1 + 0x41))) ||
      (cVar3 != *(char *)(param_1 + 0x42))) || (bVar1 != *(byte *)(param_1 + 0x43))) {
    *(char *)(param_1 + 0x40) = (char)param_2;
    *(char *)(param_1 + 0x41) = cVar2;
    *(char *)(param_1 + 0x42) = cVar3;
    *(byte *)(param_1 + 0x43) = bVar1;
    if (*(int *)(param_1 + 0x60) != 0) {
      _CGContextSetRGBStrokeColor
                (*(int *)(param_1 + 0x60),(float)(param_2 & 0xff) / 255.0,
                 (float)(param_2 >> 8 & 0xff) / 255.0,(float)(param_2 >> 0x10 & 0xff) / 255.0,
                 (float)bVar1 / 255.0);
    }
  }
  return;
}

