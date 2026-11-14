/* 0002cfde FUN_0002cfde */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0002cfde(int param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  char cVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  int local_168;
  int local_164;
  char local_15c [332];
  
  if (*(int *)(param_1 + 0x2a4) != 0) {
    if (0 < *(int *)(param_1 + 0x298)) {
      iVar5 = 0;
      do {
        iVar1 = iVar5 * 4;
        iVar8 = *(int *)(param_1 + 0x2a4);
        pvVar4 = *(void **)(iVar1 + iVar8);
        if (pvVar4 == *(void **)(param_1 + 0x2a0)) {
          if (*(int *)(param_1 + 0x298) <= iVar5 + 1) break;
        }
        else {
          if (pvVar4 != (void *)0x0) {
            _free(pvVar4);
            iVar8 = *(int *)(param_1 + 0x2a4);
          }
          *(undefined4 *)(iVar1 + iVar8) = 0;
          *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x2a4)) = *(undefined4 *)(param_1 + 0x2a0);
          if (*(int *)(param_1 + 0x298) <= iVar5 + 1) break;
        }
        iVar5 = iVar5 + 1;
      } while( true );
    }
    *(undefined4 *)(param_1 + 0x528) = 0;
    cVar3 = FUN_0000a3be(param_1 + 4,param_1 + 1000,local_15c,0,param_2,param_1 + 0x52c);
    if ((cVar3 == '\0') || (*(int *)(param_1 + 0x298) <= *(int *)(param_1 + 0x528))) {
      local_168 = 0;
      local_164 = 0;
    }
    else {
      local_168 = 0;
      local_164 = 0;
      do {
        uVar6 = 0xffffffff;
        pcVar9 = local_15c;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar3 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar3 != '\0');
        uVar7 = ~uVar6;
        if ((int)*(uint *)(param_1 + 0x29c) <= (int)~uVar6) {
          uVar7 = *(uint *)(param_1 + 0x29c);
        }
        iVar5 = _strcasecmp(local_15c,"z patterns arp");
        if (iVar5 == 0) {
          *(int *)(param_1 + 0x528) = *(int *)(param_1 + 0x528) + 1;
          local_168 = local_168 + 1;
        }
        else {
          iVar5 = *(int *)(param_1 + 0x2a4);
          pvVar4 = _malloc(uVar7 + 1);
          *(void **)(local_164 * 4 + iVar5) = pvVar4;
          pcVar9 = *(char **)(local_164 * 4 + *(int *)(param_1 + 0x2a4));
          if (pcVar9 != (char *)0x0) {
            _strncpy(pcVar9,local_15c,uVar7 - 1);
            pcVar9[uVar7 - 1] = '\0';
            local_164 = local_164 + 1;
            *(int *)(param_1 + 0x528) = *(int *)(param_1 + 0x528) + 1;
          }
        }
        cVar3 = FUN_0000a3be(param_1 + 4,param_1 + 1000,local_15c,*(undefined4 *)(param_1 + 0x528),
                             param_2,param_1 + 0x52c);
      } while ((cVar3 != '\0') && (*(int *)(param_1 + 0x528) < *(int *)(param_1 + 0x298)));
    }
    if (*(char *)(param_1 + 0x570) != '\0') {
      iVar5 = *(int *)(param_1 + 0x2a4);
      pvVar4 = _malloc(7);
      *(void **)(local_164 * 4 + iVar5) = pvVar4;
      puVar2 = *(undefined4 **)(local_164 * 4 + *(int *)(param_1 + 0x2a4));
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = 0x6579614c;
        *(undefined2 *)(puVar2 + 1) = 0x72;
        *(int *)(param_1 + 0x528) = *(int *)(param_1 + 0x528) + 1;
      }
    }
    *(int *)(param_1 + 0x528) = *(int *)(param_1 + 0x528) - local_168;
  }
  return;
}

