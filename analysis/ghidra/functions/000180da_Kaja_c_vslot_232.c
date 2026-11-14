/* 000180da Kaja_c_vslot_232 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Kaja_c_vslot_232(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  longdouble lVar4;
  float local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  if (((char)param_1[0x33f1] != '\0') && (0 < param_1[0x2696])) {
    lVar4 = (longdouble)(**(code **)(*param_1 + 0x2b4))(param_1,param_3);
    local_30 = (float)lVar4;
    cVar1 = (**(code **)(*param_1 + 0x39c))(param_1,param_3);
    if (cVar1 != '\0') {
      local_30 = 1.0 - local_30;
    }
    iVar3 = 0;
    while( true ) {
      cVar1 = FUN_0008c0fc(param_1 + 0x1e1,param_2,param_3,iVar3,local_20,&local_24,&local_28);
      if (cVar1 == '\0') break;
      uVar2 = FUN_0008c1dc(param_1 + 0x1e1,local_28,local_30);
      (**(code **)(*param_1 + 0x3a4))(param_1,local_20[0],local_24,uVar2);
      iVar3 = iVar3 + 1;
    }
  }
  return;
}

