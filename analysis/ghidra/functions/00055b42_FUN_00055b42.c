/* 00055b42 FUN_00055b42 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00055b42(int param_1,int param_2,int *param_3,int param_4,int param_5,int param_6,
                 int param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined1 local_1b8 [4];
  int aiStack_1b4 [8];
  undefined4 local_194;
  undefined4 local_180;
  undefined4 local_16c;
  undefined4 local_158;
  undefined4 local_144;
  undefined4 local_130;
  undefined4 local_11c;
  undefined4 local_108;
  undefined4 local_f4;
  undefined4 local_e0;
  undefined4 local_cc;
  undefined4 local_b8;
  undefined4 local_a4;
  undefined4 local_90;
  undefined4 local_7c;
  undefined4 local_68;
  undefined4 local_54;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  _memcpy(local_1b8,&DAT_000f0ac0,0x17c);
  aiStack_1b4[3] = *(undefined4 *)(param_1 + 0x278c4);
  local_194 = *(undefined4 *)(param_1 + 0x278c8);
  local_180 = *(undefined4 *)(param_1 + 0x278d0);
  local_16c = *(undefined4 *)(param_1 + 0x278cc);
  local_158 = *(undefined4 *)(param_1 + 0x278d4);
  local_144 = *(undefined4 *)(param_1 + 0x278dc);
  local_130 = *(undefined4 *)(param_1 + 0x278d8);
  local_11c = *(undefined4 *)(param_1 + 0x278e0);
  local_108 = *(undefined4 *)(param_1 + 0x278ec);
  local_f4 = *(undefined4 *)(param_1 + 0x278f0);
  local_e0 = *(undefined4 *)(param_1 + 0x278f4);
  local_cc = *(undefined4 *)(param_1 + 0x278f8);
  local_b8 = *(undefined4 *)(param_1 + 0x278fc);
  local_a4 = *(undefined4 *)(param_1 + 0x27900);
  local_90 = *(undefined4 *)(param_1 + 0x27904);
  local_7c = *(undefined4 *)(param_1 + 0x27908);
  local_68 = *(undefined4 *)(FUN_0002790a + param_1 + 2);
  local_54 = *(undefined4 *)(param_1 + 0x278e4);
  local_40 = *(undefined4 *)(param_1 + 0x278e8);
  uVar2 = (**(code **)(*param_3 + 0x24))(param_3);
  local_34 = aiStack_1b4[param_2 * 5] / 2;
  local_38 = aiStack_1b4[param_2 * 5 + 1] / 2;
  local_30 = (aiStack_1b4[param_2 * 5 + 1] + param_6) - local_38;
  local_3c = param_5 - local_34;
  local_38 = param_6 - local_38;
  local_34 = (aiStack_1b4[param_2 * 5] + param_5) - local_34;
  local_2c = local_3c;
  local_28 = local_38;
  local_24 = local_34;
  local_20 = local_30;
  pvVar3 = operator_new(0xe4);
  iVar1 = param_1 + 0x54 + param_4 * 0x68;
  FUN_00007460(pvVar3,&local_2c,iVar1,param_4,uVar2,aiStack_1b4[param_2 * 5 + 3],
               aiStack_1b4[param_2 * 5 + 2],0x43960000,0,1);
  if (pvVar3 != (void *)0x0) {
    *(undefined1 *)((int)pvVar3 + 0x72) = 1;
    if (param_2 == 7) {
      *(undefined1 *)((int)pvVar3 + 0xb5) = 1;
    }
    FUN_0000b7e2(iVar1,pvVar3,param_4,param_1,*(undefined4 *)(param_1 + 0x4c),param_3);
    if (param_7 != 0) {
      FUN_0000b2b0(iVar1,param_5,param_6 + param_7,0x24,8,param_8);
      return;
    }
  }
  return;
}

