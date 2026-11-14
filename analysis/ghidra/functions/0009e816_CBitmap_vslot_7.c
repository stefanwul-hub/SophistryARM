/* 0009e816 CBitmap_vslot_7 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 CBitmap_vslot_7(int param_1,char param_2)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 local_48;
  undefined4 local_34;
  short local_24;
  short local_22;
  short local_20;
  short local_1e;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    if (*(int *)(param_1 + 0x1c) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = _GetGWorldPixMap(*(int *)(param_1 + 0x1c));
      _GetPixBounds(uVar3,&local_24);
      iVar4 = _GetPixRowBytes(uVar3);
      sVar1 = _GetPixDepth(uVar3);
      iVar5 = (int)local_20;
      iVar8 = (int)local_24;
      if (param_2 == '\0') {
        uVar7 = _GetPixBaseAddr(uVar3);
        local_34 = _CGDataProviderCreateWithData(0,uVar7,(iVar5 - iVar8) * iVar4,0);
      }
      else {
        puVar6 = (undefined4 *)operator_new(0x10);
        puVar6[1] = param_1;
        *puVar6 = 0;
        uVar7 = _GetGWorldPixMap(*(undefined4 *)(param_1 + 0x1c));
        uVar7 = _GetPixBaseAddr(uVar7);
        puVar6[2] = uVar7;
        uVar7 = *(undefined4 *)(puVar6[1] + 0x14);
        *(char *)(puVar6 + 3) = (char)uVar7;
        *(char *)((int)puVar6 + 0xd) = (char)((uint)uVar7 >> 8);
        *(char *)((int)puVar6 + 0xe) = (char)((uint)uVar7 >> 0x10);
        local_48 = (undefined1)((uint)uVar7 >> 0x18);
        *(undefined1 *)((int)puVar6 + 0xf) = local_48;
        local_34 = _CGDataProviderCreate(puVar6,&PTR_FUN_000e21f0);
      }
      sVar2 = _GetPixDepth(uVar3);
      uVar3 = _CGImageCreate((int)local_1e - (int)local_22,(int)local_20 - (int)local_24,8,
                             (int)sVar1,iVar4,DAT_000fd500,(uint)(sVar2 == 0x20) << 2,local_34,0,0,0
                            );
      _CGDataProviderRelease(local_34);
      *(undefined4 *)(param_1 + 0x24) = uVar3;
      _CGImageRetain(uVar3);
    }
  }
  else {
    _CGImageRetain(*(int *)(param_1 + 0x24));
    uVar3 = *(undefined4 *)(param_1 + 0x24);
  }
  return uVar3;
}

