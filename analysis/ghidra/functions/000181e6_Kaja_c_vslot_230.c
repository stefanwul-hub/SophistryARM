/* 000181e6 Kaja_c_vslot_230 */

void Kaja_c_vslot_230(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  longdouble lVar4;
  undefined4 local_1c;
  undefined1 local_18 [4];
  undefined4 local_14;
  undefined4 local_10;
  
  if (((char)param_1[0x33f1] != '\0') && (0 < param_1[0x2696])) {
    iVar3 = 0;
    while( true ) {
      cVar1 = FUN_0008c078(param_1 + 0x1e1,iVar3,&local_10,&local_14,local_18,&local_1c);
      if (cVar1 == '\0') break;
      lVar4 = (longdouble)(**(code **)(*param_1 + 0x2b4))(param_1,local_1c);
      uVar2 = FUN_0008c1dc(param_1 + 0x1e1,iVar3,(float)lVar4);
      (**(code **)(*param_1 + 0x3a4))(param_1,local_10,local_14,uVar2);
      iVar3 = iVar3 + 1;
    }
  }
  return;
}

