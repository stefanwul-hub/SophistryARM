/* 000990e8 CTextEdit_vslot_4 */

void CTextEdit_vslot_4(int *param_1,undefined4 param_2)

{
  code *pcVar1;
  char local_10c [256];
  
  if (param_1[0x29] == 0) {
    local_10c[0] = '\0';
    pcVar1 = (code *)param_1[0x6e];
    if ((pcVar1 == (code *)0x0) && (pcVar1 = (code *)param_1[0x6d], pcVar1 == (code *)0x0)) {
      if (param_1[0x1c] == 0) {
        if (param_1[0x1b] == 0) {
          _strcpy(local_10c,(char *)(param_1 + 0x2d));
        }
        else {
          local_10c[0] = '\0';
          (*(code *)param_1[0x1b])(param_1[0x13],local_10c);
          _strcpy((char *)(param_1 + 0x2d),local_10c);
        }
      }
      else {
        local_10c[0] = '\0';
        (*(code *)param_1[0x1c])(param_1[0x13],local_10c,param_1[0x1e]);
        _strcpy((char *)(param_1 + 0x2d),local_10c);
      }
    }
    else {
      (*pcVar1)(param_1 + 0x2d,local_10c);
    }
    FUN_00098ac0(param_1,param_2,local_10c,0);
    (**(code **)(*param_1 + 0x54))(param_1,0);
    return;
  }
  if (param_1[0x2b] == 0) {
    _TXNDraw(param_1[0x29],0);
    (**(code **)(*param_1 + 0x54))(param_1,0);
    return;
  }
  _HIViewSetNeedsDisplay(param_1[0x2b],1);
  (**(code **)(*param_1 + 0x54))(param_1,0);
  return;
}

