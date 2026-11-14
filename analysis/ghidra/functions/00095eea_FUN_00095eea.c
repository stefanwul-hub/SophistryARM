/* 00095eea FUN_00095eea */

byte FUN_00095eea(int param_1)

{
  return ~-((*(uint *)(param_1 + 0x44) & 0x100) == 0) & 2;
}

