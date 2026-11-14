/* 00017d92 Kaja_c_vslot_222 */

undefined1 Kaja_c_vslot_222(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  char local_14c [320];
  
  cVar1 = FUN_0002d8c4(param_1 + 0x38fc,(char *)(param_1 + 0x9a84),*(undefined4 *)(param_1 + 0x9a78)
                       ,param_1 + 0x3fb4);
  if (cVar1 != '\0') {
    return 1;
  }
  FUN_00029ada(param_1 + 0xb4);
  Envelope_c_vslot_18(param_1 + 0xb4,0,1,local_14c);
  if (local_14c[0] != '\0') {
    _strcpy((char *)(param_1 + 0x9a84),local_14c);
  }
  uVar2 = FUN_0002d8c4(param_1 + 0x38fc,local_14c,*(undefined4 *)(param_1 + 0x9a78),param_1 + 0x3fb4
                      );
  return uVar2;
}

