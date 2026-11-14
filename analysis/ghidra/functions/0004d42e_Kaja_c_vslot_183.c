/* 0004d42e Kaja_c_vslot_183 */

undefined4 Kaja_c_vslot_183(int param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
    *(undefined1 *)(param_1 + 0xcfca) = 0;
    FUN_00009996(param_1 + 0x32abd8,param_3,param_1 + 0x32a8c4);
    FUN_00039762(param_1 + 0x8a280,0);
    FUN_00039762(param_1 + 0x8a970,0);
    FUN_00039762(param_1 + 0x8b060,0);
    FUN_00039762(param_1 + 0x8b750,0);
    FUN_0008dcde(param_1 + 0x8be40,0);
    FUN_0008dcde(param_1 + 0x8c528,0);
    FUN_0008dcde(param_1 + 0x8cc10,0);
    FUN_0008dcde(param_1 + 0x8d2f8,0);
    iVar1 = param_1 + 0x8d9e0;
    FUN_00033224(iVar1,0);
    iVar2 = param_1 + 0x97b98;
    FUN_00033224(iVar2,0);
    (**(code **)(*(int *)(FUN_0008d9dc + param_1 + 4) + 0x28))(iVar1,0,0x14,9999999);
    (**(code **)(*(int *)(FUN_0008d9dc + param_1 + 4) + 0x28))(iVar1,0,0x15,9999999);
    (**(code **)(*(int *)(FUN_0008d9dc + param_1 + 4) + 0x28))(iVar1,0,0xf,9999999);
    (**(code **)(*(int *)(FUN_0008d9dc + param_1 + 4) + 0x28))(iVar1,0,0x19,9999999);
    (**(code **)(*(int *)(param_1 + 0x97b98) + 0x28))(iVar2,0,0x14,9999999);
    (**(code **)(*(int *)(param_1 + 0x97b98) + 0x28))(iVar2,0,0x15,9999999);
    (**(code **)(*(int *)(param_1 + 0x97b98) + 0x28))(iVar2,0,0xf,9999999);
    (**(code **)(*(int *)(param_1 + 0x97b98) + 0x28))(iVar2,0,0x19,9999999);
    *(undefined1 *)(param_1 + 0x32b064) = 1;
    uVar3 = Synth_vslot_183(param_1,param_2,param_3);
    *(undefined1 *)(param_1 + 0x32b064) = 0;
    *(undefined1 *)(param_1 + 0xcfca) = 1;
    return uVar3;
  }
  return 0;
}

