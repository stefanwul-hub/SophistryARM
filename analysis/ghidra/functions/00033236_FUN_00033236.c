/* 00033236 FUN_00033236 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00033236(int *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  undefined1 local_51c [320];
  char local_3dc [320];
  char local_29c [320];
  char local_15c [332];
  
  if (param_3 != 0) {
    iVar5 = 9;
    piVar4 = param_1 + 0x27c8;
    do {
      FUN_00012482(param_1[0x48],0,iVar5,local_15c);
      if (local_15c[0] != '\0') {
        if (param_2 == (char *)0x0) {
          FUN_000098ea(piVar4,local_15c,local_29c);
          FUN_00009fa4(piVar4,param_3,local_29c);
          cVar1 = FUN_000096d0(piVar4,local_29c);
          if (cVar1 == '\0') {
            FUN_00009996(piVar4,param_3,local_51c);
            FUN_0000a024(piVar4,local_51c,"Samples");
            FUN_000098ea(piVar4,local_15c,local_29c);
            FUN_00009fa4(piVar4,local_51c,local_29c);
          }
LAB_000333e6:
          FUN_00012432(param_1[0x48],0,iVar5,local_29c);
        }
        else {
          _strcpy(local_3dc,param_2);
          if (local_3dc[0] != '\0') {
            uVar3 = 0xffffffff;
            pcVar6 = local_3dc;
            do {
              if (uVar3 == 0) break;
              uVar3 = uVar3 - 1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            iVar2 = _strncmp(local_15c,local_3dc,~uVar3 - 1);
            if (iVar2 == 0) {
              _strcpy(local_29c,local_15c + ~uVar3);
              FUN_0000a0de(piVar4,local_29c);
              FUN_00009ebe(piVar4,param_3,local_29c);
              goto LAB_000333e6;
            }
          }
        }
        (**(code **)(*param_1 + 0x78))(param_1,0,iVar5);
        (**(code **)(*param_1 + 0x78))(param_1,0,iVar5 + 10);
      }
      iVar5 = iVar5 + 0x14;
    } while (iVar5 != 0x509);
  }
  return;
}

