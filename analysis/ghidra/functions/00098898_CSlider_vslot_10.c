/* 00098898 CSlider_vslot_10 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 CSlider_vslot_10(int *param_1,int param_2)

{
  float fVar1;
  byte bVar2;
  char cVar3;
  
  cVar3 = *(char *)(param_2 + 4);
  if (3 < (byte)(cVar3 - 0xbU)) {
    return 0xffffffff;
  }
  if ((cVar3 == '\x0e') || (cVar3 == '\v')) {
    fVar1 = -1.0;
    bVar2 = *(byte *)(param_2 + 5);
  }
  else {
    fVar1 = 1.0;
    bVar2 = *(byte *)(param_2 + 5);
  }
  if ((bVar2 & 1) == 0) {
    param_1[0x13] = (int)(fVar1 * (float)param_1[0x16] + (float)param_1[0x13]);
    (**(code **)(*param_1 + 0xf8))(param_1);
    cVar3 = (**(code **)(*param_1 + 0x50))(param_1);
  }
  else {
    param_1[0x13] = (int)(fVar1 * 0.1 * (float)param_1[0x16] + (float)param_1[0x13]);
    (**(code **)(*param_1 + 0xf8))(param_1);
    cVar3 = (**(code **)(*param_1 + 0x50))(param_1);
  }
  if ((cVar3 != '\0') && (param_1[0xf] != 0)) {
    (**(code **)(*param_1 + 0xe0))(param_1);
    (*(code *)**(undefined4 **)param_1[0xf])((undefined4 *)param_1[0xf],0,param_1);
    (**(code **)(*param_1 + 0xe4))(param_1);
    return 1;
  }
  return 1;
}

