/* 0001c762 Synth_vslot_16 */

void Synth_vslot_16(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  _OSAtomicAdd32Barrier(1,param_1 + 0xecc);
  iVar1 = param_1[0x33f8];
  if ((2 < param_1[0xee2]) && (param_1[0x145a] != 0)) {
    FUN_00012432(param_1[0x145a],iVar1,1,param_2);
    if (((int *)param_1[0x1455] != (int *)0x0) && (iVar2 = *(int *)param_1[0x1455], iVar2 != 0)) {
      (**(code **)(*param_1 + 0x348))(param_1,iVar2,1,iVar1,1);
    }
  }
  _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0xecc);
  return;
}

