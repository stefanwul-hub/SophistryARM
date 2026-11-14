/* 000182ac Kaja_c_vslot_234 */

void Kaja_c_vslot_234(int param_1,int param_2,char param_3)

{
  undefined4 local_234;
  undefined4 local_230;
  undefined4 *local_22c;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  char local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  
  if (*(char *)(param_1 + 0xcfc4) != '\0') {
    local_230 = 0;
    local_2c = 1;
    local_28 = 0x18;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = (-(param_3 == '\0') & 0xf0U) + 0x90 + (char)*(undefined4 *)(param_2 + 0x10);
    local_13 = (undefined1)*(undefined4 *)(param_2 + 8);
    local_12 = (undefined1)*(undefined4 *)(param_2 + 0xc);
    local_11 = 0;
    local_10 = 0;
    local_f = 0;
    local_e = 0;
    local_d = 0;
    local_22c = &local_2c;
    local_234 = 1;
    FUN_00095b3c(param_1,&local_234);
  }
  return;
}

