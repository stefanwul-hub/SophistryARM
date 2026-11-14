/* 0006b6c0 FUN_0006b6c0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int FUN_0006b6c0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  longdouble lVar5;
  int local_90;
  char local_80;
  undefined1 local_7f;
  undefined1 local_7e;
  undefined1 local_7d;
  undefined1 local_7c;
  undefined1 local_7b;
  undefined1 local_7a;
  undefined1 local_79;
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined1 local_75;
  undefined1 local_74;
  undefined1 local_73;
  undefined1 local_72;
  undefined1 local_71;
  undefined1 local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined1 local_6d;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  byte local_58;
  char local_57;
  undefined2 local_56;
  undefined2 local_54;
  char local_50;
  undefined1 local_4f;
  undefined1 local_4e;
  undefined1 local_4d;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined1 local_49;
  undefined1 local_48;
  undefined1 local_47;
  undefined1 local_46;
  undefined1 local_45;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined1 local_40;
  undefined1 local_3f;
  undefined1 local_3e;
  undefined1 local_3d;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  byte local_28;
  char local_27;
  undefined2 local_26;
  undefined2 local_24;
  int local_20 [4];
  
  FUN_00009b22(param_1 + 4,local_20);
  iVar3 = local_20[0] / 0x2e + -1;
  if (0 < iVar3) {
    local_90 = 0;
    do {
      FUN_00009b6e(param_1 + 4,&local_50,0x2e);
      iVar1 = -1;
      iVar2 = param_2[1];
      do {
        iVar1 = iVar1 + 1;
        if ((iVar1 < *param_2) && (local_90 == *(int *)(iVar2 + 8))) goto LAB_0006b7ba;
        iVar2 = iVar2 + 0x7c;
      } while (iVar1 < *param_2);
      iVar1 = 0;
LAB_0006b7ba:
      iVar1 = param_2[1] + iVar1 * 0x7c;
      local_54 = local_24;
      local_56 = local_26;
      local_57 = local_27;
      local_58 = local_28;
      local_5c = local_2c;
      local_60 = local_30;
      local_64 = local_34;
      local_68 = local_38;
      local_6c = local_3c;
      local_6d = local_3d;
      local_6e = local_3e;
      local_6f = local_3f;
      local_70 = local_40;
      local_71 = local_41;
      local_72 = local_42;
      local_73 = local_43;
      local_74 = local_44;
      local_75 = local_45;
      local_76 = local_46;
      local_77 = local_47;
      local_78 = local_48;
      local_79 = local_49;
      local_7a = local_4a;
      local_7b = local_4b;
      local_7c = local_4c;
      local_7d = local_4d;
      local_7e = local_4e;
      local_7f = local_4f;
      local_80 = local_50;
      pcVar4 = (char *)(iVar1 + 0xc);
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        pcVar4[0] = '\0';
        pcVar4[1] = '\0';
        pcVar4[2] = '\0';
        pcVar4[3] = '\0';
        pcVar4 = pcVar4 + 4;
      }
      _strncpy((char *)(iVar1 + 0xc),&local_80,0x14);
      if (*(int *)(iVar1 + 0x24) == -1) {
        *(uint *)(iVar1 + 0x24) = (uint)local_58;
      }
      lVar5 = (longdouble)_pow(0,0x40000000,(double)(int)local_57 * 0.0008333333333333333);
      *(float *)(iVar1 + 0x28) = (float)lVar5 * *(float *)(iVar1 + 0x28);
      *(undefined4 *)(iVar1 + 0x4c) = local_6c;
      *(undefined4 *)(iVar1 + 0x50) = local_68;
      *(undefined4 *)(iVar1 + 0x54) = local_64;
      *(undefined4 *)(iVar1 + 0x58) = local_60;
      *(undefined4 *)(iVar1 + 0x5c) = local_5c;
      local_90 = local_90 + 1;
    } while (iVar3 != local_90);
  }
  _fseek(*(FILE **)(param_1 + 0xc),0x2e,1);
  return local_20[0] + 4;
}

