/* 0001ba28 Synth_vslot_203 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined1 Synth_vslot_203(int *param_1,undefined4 param_2,int param_3,uint param_4,int param_5)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  undefined *puStack_2c;
  undefined1 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  piVar1 = param_1 + 0xecc;
  _OSAtomicAdd32Barrier(1,piVar1);
  iVar3 = param_3;
  if (param_3 == -1) {
    iVar3 = param_1[0x33f8];
  }
  switch(param_2) {
  case 5:
    param_4 = param_4 & 0x800000ff;
    if ((int)param_4 < 0) {
      param_4 = (param_4 - 1 | 0xffffff00) + 1;
    }
    uVar2 = (**(code **)(*param_1 + 0x330))(param_1,param_4);
    break;
  default:
    uVar2 = 0;
    break;
  case 0xd:
    (**(code **)(*param_1 + 0x36c))(param_1,param_3,param_1[0x33f8] * 0x140 + 0x9bd5 + (int)param_1)
    ;
    uVar2 = 1;
    break;
  case 0xf:
    (**(code **)(*param_1 + 0x2fc))(param_1,iVar3,1);
    uVar2 = 1;
    break;
  case 0x10:
    (**(code **)(*param_1 + 0x2fc))(param_1,iVar3,0);
    uVar2 = 1;
    break;
  case 0x33:
    (**(code **)(*(int *)param_1[2] + 0x98))((int *)param_1[2]);
    uVar2 = 1;
    break;
  case 0x3d:
    puStack_2c = PTR_DAT_00103808 + 8;
    uStack_28 = *(undefined1 *)(param_5 + 4);
    uStack_24 = *(undefined4 *)(param_5 + 8);
    uStack_20 = *(undefined4 *)(param_5 + 0xc);
    (**(code **)(*param_1 + 0x3ac))(param_1,param_3,&puStack_2c);
    puStack_2c = PTR_DAT_00103808 + 8;
    uVar2 = 1;
    break;
  case 0x3e:
    if (param_1[0x2695] != -1) {
      FUN_0008cea6(param_1 + 0x1e1,param_1[0x33f8],param_1[0x2695]);
    }
    goto code_r0x0001bbd3;
  case 0x3f:
    (**(code **)(*(int *)param_1[2] + 0x9c))((int *)param_1[2],1);
    uVar2 = 1;
    break;
  case 0x40:
    (**(code **)(*(int *)param_1[2] + 0x9c))((int *)param_1[2],0);
code_r0x0001bbd3:
    _OSAtomicAdd32Barrier(0xffffffff,piVar1);
    return 1;
  }
  _OSAtomicAdd32Barrier(0xffffffff,piVar1);
  return uVar2;
}

