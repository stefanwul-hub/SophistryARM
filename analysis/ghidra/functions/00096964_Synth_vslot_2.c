/* 00096964 Synth_vslot_2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Type propagation algorithm not settling */

uint Synth_vslot_2(int *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                  float param_6)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iStack_16;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  switch(param_2) {
  case 0x19:
    uVar3 = (**(code **)(*param_1 + 0x138))(param_1,param_5);
    break;
  case 0x1a:
    cVar2 = (**(code **)(*param_1 + 0xcc))(param_1,param_3);
    goto joined_r0x00097159;
  case 0x1b:
    cVar2 = (**(code **)(*param_1 + 0xd0))(param_1,param_3,param_5);
    goto joined_r0x00097159;
  case 0x1c:
    uVar3 = (**(code **)(*param_1 + 0x204))(param_1);
    break;
  case 0x1d:
    cVar2 = (**(code **)(*param_1 + 0xe0))(param_1,param_4,param_3,param_5);
    goto joined_r0x00097159;
  case 0x1e:
    cVar2 = (**(code **)(*param_1 + 0x208))(param_1,param_3);
    goto joined_r0x00097159;
  case 0x1f:
    (**(code **)(*param_1 + 0x218))(param_1,param_3,param_4 != 0);
    uVar3 = 1;
    break;
  case 0x20:
    (**(code **)(*param_1 + 0x21c))(param_1,param_3,param_4 != 0);
    uVar3 = 1;
    break;
  case 0x21:
    cVar2 = (**(code **)(*param_1 + 0x108))(param_1,param_3,param_5);
    goto joined_r0x00097159;
  case 0x22:
    cVar2 = (**(code **)(*param_1 + 0x10c))(param_1,param_3,param_5);
    goto joined_r0x00097159;
  case 0x23:
    uVar3 = (**(code **)(*param_1 + 400))(param_1);
    break;
  case 0x24:
    uVar3 = (**(code **)(*param_1 + 0x22c))(param_1);
    break;
  case 0x25:
    uVar3 = (**(code **)(*param_1 + 0x230))(param_1);
    break;
  case 0x26:
    uVar3 = (**(code **)(*param_1 + 0x1e0))(param_1,param_5,param_4,param_3 != 0);
    uVar3 = uVar3 & 0xff;
    break;
  case 0x27:
    uVar3 = (**(code **)(*param_1 + 0x1e4))(param_1,param_5,param_4);
    uVar3 = uVar3 & 0xff;
    break;
  case 0x28:
    uVar3 = (**(code **)(*param_1 + 0x1e8))(param_1,param_5,param_4);
    uVar3 = uVar3 & 0xff;
    break;
  case 0x29:
    cVar2 = (**(code **)(*param_1 + 0x144))(param_1,param_5);
    goto joined_r0x00097159;
  case 0x2a:
    cVar2 = (**(code **)(*param_1 + 0x110))(param_1,param_4,param_5);
    goto joined_r0x00097159;
  case 0x2b:
    (**(code **)(*param_1 + 0x248))(param_1,param_4,param_6);
    uVar3 = 1;
    break;
  case 0x2c:
    cVar2 = (**(code **)(*param_1 + 0x118))(param_1,param_4 != 0);
    goto joined_r0x00097159;
  case 0x2d:
    cVar2 = (**(code **)(*param_1 + 0x174))(param_1,param_5);
    goto joined_r0x00097159;
  case 0x2e:
    cVar2 = (**(code **)(*param_1 + 0x24c))(param_1,param_5);
    goto joined_r0x00097159;
  case 0x2f:
    cVar2 = (**(code **)(*param_1 + 0x178))(param_1,param_5);
    goto joined_r0x00097159;
  case 0x30:
    cVar2 = (**(code **)(*param_1 + 0x17c))(param_1,param_5);
    goto joined_r0x00097159;
  case 0x31:
    uVar3 = (**(code **)(*param_1 + 0x180))(param_1);
    break;
  case 0x32:
    uVar3 = (**(code **)(*param_1 + 0x184))(param_1,param_3,param_4,param_5,param_6);
    break;
  case 0x33:
    uVar3 = (**(code **)(*param_1 + 0x188))(param_1,param_5);
    break;
  case 0x34:
    uVar3 = (**(code **)(*param_1 + 0x16c))(param_1);
    break;
  case 0x35:
    uVar3 = (**(code **)(*param_1 + 600))(param_1);
    break;
  case 0x36:
    uVar3 = (**(code **)(*param_1 + 0x250))(param_1);
    break;
  case 0x37:
    cVar2 = (**(code **)(*param_1 + 0x254))(param_1,param_3,param_4);
    goto joined_r0x00097159;
  case 0x38:
    cVar2 = (**(code **)(*param_1 + 0xd4))(param_1,param_3,param_5);
    goto joined_r0x00097159;
  case 0x39:
    cVar2 = (**(code **)(*param_1 + 0x25c))(param_1);
    if (cVar2 == '\0') {
      return 1;
    }
    return 0;
  case 0x3a:
    uVar3 = (**(code **)(*param_1 + 0x18c))(param_1);
    break;
  case 0x3b:
    if (param_1[2] != 0) {
      iStack_16 = param_3;
      _uStack_12 = CONCAT11((char)(int)param_6,(char)param_4);
      cVar2 = (**(code **)(*(int *)param_1[2] + 0x34))((int *)param_1[2],&iStack_16);
      goto joined_r0x00097159;
    }
    goto code_r0x00096af0;
  case 0x3c:
    if (param_1[2] == 0) goto code_r0x00096af0;
    iStack_16 = param_3;
    _uStack_12 = CONCAT11((char)(int)param_6,(char)param_4);
    cVar2 = (**(code **)(*(int *)param_1[2] + 0x38))((int *)param_1[2],&iStack_16);
    goto joined_r0x00097159;
  case 0x3d:
    piVar1 = (int *)param_1[2];
    if (piVar1 == (int *)0x0) goto code_r0x00096af0;
    cVar2 = (**(code **)(*piVar1 + 0x40))(piVar1,param_4);
    goto joined_r0x00097159;
  case 0x3e:
    uVar3 = (**(code **)(*param_1 + 0x194))(param_1,param_3,param_5);
    break;
  case 0x3f:
    uVar3 = (**(code **)(*param_1 + 0x198))(param_1,param_3,param_5);
    break;
  case 0x40:
    uVar3 = (**(code **)(*param_1 + 0x19c))(param_1,param_3,param_5);
    break;
  case 0x41:
    cVar2 = (**(code **)(*param_1 + 0x1a0))(param_1,param_3);
    goto joined_r0x00097159;
  case 0x42:
    cVar2 = (**(code **)(*param_1 + 0x1a4))(param_1,param_3,param_5);
    goto joined_r0x00097159;
  case 0x43:
    cVar2 = (**(code **)(*param_1 + 0xe4))(param_1);
    goto joined_r0x00097159;
  case 0x44:
    cVar2 = (**(code **)(*param_1 + 0xe8))(param_1);
    goto joined_r0x00097159;
  case 0x45:
    cVar2 = (**(code **)(*param_1 + 0x114))(param_1,param_4,param_5);
    goto joined_r0x00097159;
  case 0x46:
    uVar3 = (**(code **)(*param_1 + 0x1b8))(param_1,param_5);
    break;
  case 0x47:
    uVar3 = (**(code **)(*param_1 + 0x13c))(param_1);
    break;
  case 0x48:
    uVar3 = (**(code **)(*param_1 + 0x140))(param_1);
    break;
  case 0x49:
    uVar3 = (**(code **)(*param_1 + 0x148))(param_1,param_4);
    break;
  case 0x4a:
    cVar2 = (**(code **)(*param_1 + 0x11c))(param_1,param_4,param_6);
    goto joined_r0x00097159;
  case 0x4b:
    uVar3 = (**(code **)(*param_1 + 0xec))(param_1,param_5);
    break;
  case 0x4c:
    uVar3 = (**(code **)(*param_1 + 0xf0))(param_1,param_5);
    break;
  case 0x4d:
    cVar2 = (**(code **)(*param_1 + 0x120))(param_1,param_4);
joined_r0x00097159:
    if (cVar2 != '\0') {
      return 1;
    }
code_r0x00096af0:
    uVar3 = 0;
    break;
  case 0x4e:
    uVar3 = (**(code **)(*param_1 + 0x124))(param_1);
    break;
  case 0x4f:
    uVar3 = (**(code **)(*param_1 + 0x128))(param_1);
    break;
  default:
    uVar3 = AudioEffect_vslot_2(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return uVar3;
}

