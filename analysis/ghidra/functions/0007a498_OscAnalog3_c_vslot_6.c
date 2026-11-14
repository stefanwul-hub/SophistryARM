/* 0007a498 OscAnalog3_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void OscAnalog3_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  if (*param_2 == 0) {
    uVar3 = (**(code **)(*param_1 + 100))(param_1);
    pvVar4 = operator_new(0x20);
    FUN_000126be(pvVar4,uVar3,param_3,0xf);
    param_1[0x48] = (int)pvVar4;
    *param_2 = (int)pvVar4;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar1 = *param_2;
  param_1[0x48] = iVar1;
  if ((iVar1 != 0) && (cVar2 = FUN_00011c32(iVar1), cVar2 == '\0')) {
    iVar1 = *(int *)(param_1[0x48] + 4);
    FUN_00011652(iVar1,"Version","",0,200,0x26ac,2,200,0);
    FUN_00010290(iVar1 + 0x70,"OffOn",1);
    FUN_00011652(iVar1 + 0xe0,"Waveform","%",0,0,100,2,0x32,0);
    FUN_00011652(iVar1 + 0x150,"PulseWidth","%",0,5,100,2,100,0);
    FUN_00010218(iVar1 + 0x1c0,"Unused Mode","",0,2,1,2,"XA0",0);
    FUN_00011652(iVar1 + 0x230,"Octave","",0,0xfffffffe,7,0,0,0);
    FUN_00011652(iVar1 + 0x2a0,"Semitone","",0,0xfffffff5,0xb,0,0,0);
    FUN_00010290(iVar1 + 0x310,"Track",1);
    FUN_00011652(iVar1 + 0x380,"Cent","cent",0,0xffffff9d,99,0,0,0);
    FUN_00011652(iVar1 + 0x460,"","%",0,0x32,0x96,2,100,0);
    FUN_00011652(iVar1 + 0x4d0,"","%",0,1,3,0,2,0);
    FUN_00011652(iVar1 + 0x540,"Spread","cent",0x40800000,0,5000,2,0,0);
    FUN_00010290(iVar1 + 0x5b0,"FreeRun",0);
    FUN_00011652(iVar1 + 0x620,"SubOsc Vol","%",0,0,100,2,0,0);
    FUN_00011b84();
    return;
  }
  return;
}

