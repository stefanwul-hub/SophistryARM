/* 00002ec8 LPAUSynth_vslot_69 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int LPAUSynth_vslot_69(int param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  longdouble lVar4;
  undefined1 auVar5 [16];
  undefined8 local_44;
  undefined1 local_3c [8];
  double local_34;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  float local_20 [4];
  
  if (((*(byte *)(param_1 + 0x32b394) & 1) != 0) && (*(char *)(param_1 + 0x32b431) == '\0')) {
    *(undefined4 *)(param_1 + 0x32b3f0) = 0;
    *(undefined4 *)(param_1 + 0x32b39c) = 0;
    *(undefined4 *)(param_1 + 0x32b3a0) = 0;
    lVar4 = (longdouble)(**(code **)(*(int *)(param_1 + 0xec) + 0x80))(param_1 + 0xec);
    *(double *)(param_1 + 0x32b3a4) = (double)(float)lVar4;
    if ((((*(char *)(param_1 + 0x32b405) == '\0') || (*(code **)(param_1 + 0xd4) == (code *)0x0)) ||
        (iVar3 = (**(code **)(param_1 + 0xd4))(*(undefined4 *)(param_1 + 200),0,0,&local_2c,0,0,0),
        *(char *)(param_1 + 0x32b406) == '\0')) || (iVar3 != 0)) {
      bVar2 = false;
    }
    else {
      if (0.0 < (double)CONCAT44(uStack_28,local_2c)) {
        *(ulonglong *)(param_1 + 0x32b39c) = CONCAT44(uStack_28,local_2c);
      }
      bVar2 = true;
    }
    if ((((param_2 & 0x4000) != 0) && ((*(byte *)(param_1 + 0x32b394) & 0x10) != 0)) &&
       (*(uint *)(param_1 + 0x32b384) < 6)) {
      *(undefined4 *)(param_1 + 0x32b3e8) =
           *(undefined4 *)(&DAT_000e1744 + *(uint *)(param_1 + 0x32b384) * 4);
      *(undefined4 *)(param_1 + 0x32b3e4) = *(undefined4 *)(param_1 + 0x32b380);
      *(uint *)(param_1 + 0x32b3f0) = *(uint *)(param_1 + 0x32b3f0) | 0x4000;
    }
    if (((param_2 & 0x100) != 0) && ((*(byte *)(param_1 + 0x32b394) & 2) != 0)) {
      auVar5._4_4_ = *(undefined4 *)(param_1 + 0x32b364);
      auVar5._0_4_ = *(undefined4 *)(param_1 + 0x32b368);
      auVar5._8_4_ = *(undefined4 *)(param_1 + 0x32b364);
      auVar5._12_4_ = 0x43300000;
      *(double *)(param_1 + 0x32b3ac) =
           ((double)CONCAT44(0x45300000,*(undefined4 *)(param_1 + 0x32b368)) -
           1.9342813113834067e+25) + (auVar5._8_8_ - 4503599627370496.0);
      *(uint *)(param_1 + 0x32b3f0) = *(uint *)(param_1 + 0x32b3f0) | 0x100;
    }
    if ((((!bVar2) || ((param_2 & 0x600) != 0)) && (*(code **)(param_1 + 0xcc) != (code *)0x0)) &&
       (iVar3 = (**(code **)(param_1 + 0xcc))(*(undefined4 *)(param_1 + 200),&local_34,&local_2c),
       iVar3 == 0)) {
      *(double *)(param_1 + 0x32b3b4) = local_34;
      *(ulonglong *)(param_1 + 0x32b3bc) = CONCAT44(uStack_28,local_2c);
      uVar1 = *(uint *)(param_1 + 0x32b3f0);
      *(uint *)(param_1 + 0x32b3f0) = uVar1 | 0x200;
      if (((0.0 < (double)CONCAT44(uStack_28,local_2c)) &&
          (*(uint *)(param_1 + 0x32b3f0) = uVar1 | 0x600, !bVar2)) && (0.0 <= local_34)) {
        *(double *)(param_1 + 0x32b39c) =
             local_34 * *(double *)(param_1 + 0x32b3a4) *
             (60.0 / (double)CONCAT44(uStack_28,local_2c));
      }
    }
    if ((((param_2 & 0xa800) != 0) && (*(code **)(param_1 + 0xd0) != (code *)0x0)) &&
       (iVar3 = (**(code **)(param_1 + 0xd0))
                          (*(undefined4 *)(param_1 + 200),&local_2c,local_20,&local_24,&local_34),
       iVar3 == 0)) {
      *(undefined4 *)(param_1 + 0x32b3ec) = local_2c;
      *(int *)(param_1 + 0x32b3dc) = (int)local_20[0];
      *(undefined4 *)(param_1 + 0x32b3e0) = local_24;
      *(double *)(param_1 + 0x32b3c4) = local_34;
      *(uint *)(param_1 + 0x32b3f0) = *(uint *)(param_1 + 0x32b3f0) | 0xa800;
    }
    if (((((param_2 & 7) != 0) && (*(char *)(param_1 + 0x32b405) != '\0')) &&
        (*(code **)(param_1 + 0xd4) != (code *)0x0)) &&
       (iVar3 = (**(code **)(param_1 + 0xd4))
                          (*(undefined4 *)(param_1 + 200),&local_2c,&local_24,local_3c,local_20,
                           &local_44,&local_34), iVar3 == 0)) {
      if ((char)local_2c != '\0') {
        *(uint *)(param_1 + 0x32b3f0) = *(uint *)(param_1 + 0x32b3f0) | 2;
      }
      if ((char)local_24 != '\0') {
        *(uint *)(param_1 + 0x32b3f0) = *(uint *)(param_1 + 0x32b3f0) | 1;
      }
      if (local_20[0]._0_1_ != '\0') {
        *(uint *)(param_1 + 0x32b3f0) = *(uint *)(param_1 + 0x32b3f0) | 4;
        *(undefined8 *)(param_1 + 0x32b3cc) = local_44;
        *(double *)(param_1 + 0x32b3d4) = local_34;
      }
    }
    return param_1 + 0x32b39c;
  }
  return 0;
}

