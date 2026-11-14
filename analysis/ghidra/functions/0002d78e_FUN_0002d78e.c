/* 0002d78e FUN_0002d78e */

bool FUN_0002d78e(int param_1,uint param_2)

{
  if (param_2 < 0x80) {
    return (*(uint *)(param_1 + 4 + ((int)param_2 >> 5) * 4) & 1 << ((byte)param_2 & 0x1f)) != 0;
  }
  return false;
}

