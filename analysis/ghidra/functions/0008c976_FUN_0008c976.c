/* 0008c976 FUN_0008c976 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0008c976(undefined4 *param_1,int param_2,char *param_3)

{
  char *pcVar1;
  char cVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  
  FUN_00013e4c(param_1);
  *param_1 = &PTR_ECS2_c_vslot_0_000f2f28;
  puVar3 = param_1 + 0xce;
  iVar5 = 0x7f;
  do {
    *puVar3 = &PTR_CCAss_c_vslot_0_000f2f08;
    puVar3[1] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0x3f800000;
    puVar3[5] = 0;
    puVar3[6] = 0x7f;
    puVar3[2] = 0;
    puVar3[7] = 0xffffffff;
    puVar3[8] = 0;
    puVar3[9] = 0;
    puVar3[10] = 0;
    puVar3 = puVar3 + 0xb;
    iVar5 = iVar5 + -1;
  } while (iVar5 != -1);
  puVar3 = param_1 + 0x64e;
  iVar5 = 0x7f;
  do {
    *puVar3 = &PTR_CCAss_c_vslot_0_000f2f08;
    puVar3[1] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0x3f800000;
    puVar3[5] = 0;
    puVar3[6] = 0x7f;
    puVar3[2] = 0;
    puVar3[7] = 0xffffffff;
    puVar3[8] = 0;
    puVar3[9] = 0;
    puVar3[10] = 0;
    puVar3 = puVar3 + 0xb;
    iVar5 = iVar5 + -1;
  } while (iVar5 != -1);
  if ((param_2 != 0) && (param_3 != (char *)0x0)) {
    pcVar1 = (char *)((int)param_1 + 0x1d5);
    _strcpy(pcVar1,param_3);
    uVar4 = 0xffffffff;
    pcVar6 = pcVar1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    builtin_strncpy(pcVar1 + (~uVar4 - 1),"ECS2",5);
    *(undefined1 *)((int)param_1 + 0x315) = 0;
    param_1[0xc6] = param_2;
    FUN_0008c872(param_1);
  }
  return;
}

