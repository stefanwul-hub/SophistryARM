/* 0006032e KajaEditor_c_vslot_4 */

undefined4 KajaEditor_c_vslot_4(int *param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int local_10;
  
  piVar2 = (int *)param_1[0x13];
  if (((piVar2 != (int *)0x0) && (cVar1 = (**(code **)(*piVar2 + 0x26c))(piVar2), cVar1 != '\0')) &&
     (cVar1 = SynthEditor_c_vslot_4(param_1,param_2), cVar1 != '\0')) {
    _OSAtomicAdd32Barrier(1,param_1[0x13] + 0x3b30);
    *(undefined1 *)(param_1 + 0x9774) = 0;
    iVar4 = 0;
    piVar2 = param_1;
    do {
      piVar2[0x9e6d] = -1;
      iVar4 = iVar4 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar4 != 4);
    FUN_0005efe2(param_1);
    *(undefined1 *)((int)param_1 + 0x51) = 1;
    FUN_00025e74(param_1);
    if (*(char *)((int)param_1 + 0x51) != '\0') {
      local_10 = 0;
      piVar2 = param_1 + 0x450b;
      do {
        uVar3 = FUN_00054462(param_1,0x29d,local_10,0);
        FUN_0000afac(piVar2,uVar3);
        FUN_0000b124(piVar2,0);
        local_10 = local_10 + 1;
        piVar2 = piVar2 + 0x1a;
      } while (local_10 != 10);
    }
    (**(code **)(*param_1 + 0x90))(param_1);
    _OSAtomicAdd32Barrier(0xffffffff,param_1[0x13] + 0x3b30);
    return 1;
  }
  return 0;
}

