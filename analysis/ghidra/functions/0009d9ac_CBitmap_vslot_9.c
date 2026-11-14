/* 0009d9ac CBitmap_vslot_9 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool CBitmap_vslot_9(int *param_1,undefined4 param_2)

{
  undefined *puVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined **ppuVar6;
  char local_424 [24];
  undefined1 local_40c [4];
  short local_408;
  short local_406;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  (**(code **)(*param_1 + 0x20))(param_1);
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  puVar1 = PTR_DAT_001038a0;
  if (*(int *)PTR_DAT_001038a0 != 0) {
    _sprintf(local_424,"bmp%05d",param_2);
    iVar4 = _CFStringCreateWithCString(0,local_424,0x600);
    if (iVar4 != 0) {
      ppuVar6 = &PTR_cf_png_000e21dc;
      do {
        iVar5 = _CFBundleCopyResourceURL(*(undefined4 *)puVar1,iVar4,*ppuVar6,0);
        if (ppuVar6[1] == (undefined *)0x0) break;
        ppuVar6 = ppuVar6 + 1;
      } while (iVar5 == 0);
      _CFRelease(iVar4);
      if (iVar5 != 0) {
        cVar2 = (**(code **)(*param_1 + 0x28))(param_1,iVar5);
        _CFRelease(iVar5);
        if (cVar2 != '\0') {
          return true;
        }
      }
    }
  }
  if (param_1[7] == 0) {
    iVar4 = _GetResource(0x50494354,(int)(short)param_2);
    if (iVar4 != 0) {
      _HLock(iVar4);
      _GetPictInfo(iVar4,local_424,4,0,0,0);
      param_1[3] = (int)local_406;
      param_1[4] = (int)local_408;
      sVar3 = _NewGWorld(param_1 + 7,0x20,local_40c,0,0,0);
      if (sVar3 == 0) {
        _GetGWorld(local_20,&local_24);
        _SetGWorld(param_1[7],0);
        _DrawPicture(iVar4,local_40c);
        _SetGWorld(local_20[0],local_24);
      }
      _HUnlock(iVar4);
      _ReleaseResource(iVar4);
      return sVar3 == 0;
    }
  }
  return false;
}

