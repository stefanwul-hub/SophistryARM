/* 0004d6b4 Kaja_c_vslot_179 */

void Kaja_c_vslot_179(int *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  
  piVar3 = param_1 + 0x23678;
  FUN_00034afc(piVar3,param_2);
  piVar1 = param_1 + 0x25ee6;
  FUN_00034afc(piVar1,param_2);
  FUN_0001f38e(param_1,param_3,param_3);
  if ((char)param_1[0xcac19] != '\0') {
    piVar2 = param_1 + 0xcaa31;
    FUN_00039776(param_1 + 0x228a0,piVar2);
    FUN_00039776(param_1 + 0x22a5c,piVar2);
    FUN_00039776(param_1 + 0x22c18,piVar2);
    FUN_00039776(param_1 + 0x22dd4,piVar2);
    FUN_0008dcf0(param_1 + 0x22f90,piVar2);
    FUN_0008dcf0(param_1 + 0x2314a,piVar2);
    FUN_0008dcf0(param_1 + 0x23304,piVar2);
    FUN_0008dcf0(param_1 + 0x234be,piVar2);
    *(undefined1 *)((int)param_1 + 0x8dbb7) = 0;
    *(undefined1 *)((int)param_1 + 0x97d6f) = 0;
    FUN_00033236(piVar3,0,piVar2);
    FUN_00033236(piVar1,0,piVar2);
    *(undefined1 *)((int)param_1 + 0x8dbb7) = 1;
    *(undefined1 *)((int)param_1 + 0x97d6f) = 1;
  }
  local_20 = param_1 + 0x22c18;
  local_24 = param_1 + 0x22a5c;
  local_28 = param_1 + 0x2314a;
  local_2c = param_1 + 0x228a0;
  local_30 = param_1 + 0x234be;
  local_34 = param_1 + 0x22f90;
  local_38 = param_1 + 0x23304;
  local_3c = param_1 + 0x22dd4;
  FUN_00039762(local_2c,1);
  FUN_00039762(local_24,1);
  FUN_00039762(local_20,1);
  FUN_00039762(local_3c,1);
  FUN_0008dcde(local_34,1);
  FUN_0008dcde(local_28,1);
  FUN_0008dcde(local_38,1);
  FUN_0008dcde(local_30,1);
  FUN_00033224(piVar3,1);
  FUN_00033224(piVar1,1);
  (**(code **)(*param_1 + 0x314))(param_1,param_3);
  (**(code **)(*param_1 + 0x354))(param_1,1);
  (**(code **)(*param_1 + 0x35c))(param_1);
  if ((*(char *)((int)param_1 + 0xcfda) != '\0') &&
     ((**(code **)(*param_1 + 0x350))(param_1), param_1[0x33fa] != 0)) {
    (**(code **)(*param_1 + 700))(param_1);
  }
  piVar3 = *(int **)(param_1[0x33a9] + param_2 * 4);
  if (piVar3 == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0004d884. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar3 + 0x4c))();
  return;
}

