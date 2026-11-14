/* 0002bf9e FileDialog_c_vslot_2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

char * FileDialog_c_vslot_2(int param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  short sVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  void *pvVar11;
  int iVar12;
  undefined1 *local_2c8;
  int local_284;
  undefined1 local_272 [2];
  char local_270;
  char local_26f;
  undefined1 local_26c [18];
  undefined4 local_25a;
  undefined1 local_172 [80];
  undefined1 local_122 [80];
  undefined1 local_d2 [80];
  undefined2 local_82;
  undefined4 local_80;
  int local_74;
  int local_68;
  int local_64;
  undefined4 local_58;
  int local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  undefined4 local_24;
  undefined1 local_1d [13];
  
  if ((*(int *)(param_1 + 0x41c) == 0) || (*(int *)(param_1 + 0x10) == 0)) {
    return "";
  }
  pcVar4 = (char *)(param_1 + 0x19c);
  _memset(pcVar4,0,0x140);
  iVar12 = param_1 + 0x5c;
  FUN_0002e564(param_1 + 0x6b4,*(undefined4 *)(param_1 + 0x58),iVar12,0x140);
  iVar5 = _NewNavEventUPP(FUN_0002be04);
  iVar6 = _NewNavObjectFilterUPP(FUN_0002be42);
  puVar1 = PTR_001037ec;
  if ((iVar5 == 0) || (iVar6 == 0)) {
    return (char *)0x0;
  }
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  iVar7 = _CFArrayCreateMutable(*(undefined4 *)PTR_001037ec,0,PTR_00103824);
  iVar9 = param_1;
  if (iVar7 == 0) {
    local_40 = 0;
    iVar9 = local_3c;
  }
  else {
    while (puVar2 = PTR_001037ec, iVar8 = *(int *)(iVar9 + 0x10), iVar8 != 0) {
      if ((*(char *)(iVar8 + 2) == '\0') ||
         (iVar8 = _CFStringCreateWithCString(*(undefined4 *)puVar1,iVar8 + 2,0x8000100), iVar8 == 0)
         ) {
        iVar9 = iVar9 + 4;
      }
      else {
        _CFArrayAppendValue(iVar7,iVar8);
        _CFRelease(iVar8);
        iVar9 = iVar9 + 4;
      }
    }
    local_40 = iVar7;
    iVar9 = _CFArrayCreateMutable(*(undefined4 *)PTR_001037ec,0,PTR_00103824);
    if (iVar9 == 0) {
      local_3c = 0;
      iVar9 = local_3c;
    }
    else {
      for (local_284 = 0; iVar8 = _CFArrayGetCount(iVar7), local_284 < iVar8;
          local_284 = local_284 + 1) {
        uVar10 = _CFArrayGetValueAtIndex(iVar7,local_284);
        iVar8 = _CFStringCompare(uVar10,&cf_AIF,1);
        if (iVar8 == 0) {
          local_30 = 0x41494646;
          uVar10 = *(undefined4 *)puVar2;
          iVar8 = _CFNumberCreate(uVar10,3,&local_30);
          if (iVar8 != 0) {
            _CFArrayAppendValue(iVar9,iVar8);
            _CFRelease(iVar8);
          }
          local_30 = 0x41494643;
          iVar8 = _CFNumberCreate(uVar10,3,&local_30);
joined_r0x0002c22a:
          if (iVar8 != 0) {
            _CFArrayAppendValue(iVar9,iVar8);
            _CFRelease(iVar8);
          }
        }
        else {
          iVar8 = _CFStringCompare(uVar10,&cf_WAV,1);
          if (iVar8 == 0) {
            local_30 = 0x57415645;
LAB_0002c2e0:
            iVar8 = _CFNumberCreate(*(undefined4 *)puVar2,3,&local_30);
            goto joined_r0x0002c22a;
          }
          iVar8 = _CFStringCompare(uVar10,&cf_TXT,1);
          if (iVar8 == 0) {
            local_30 = 0x54455854;
            goto LAB_0002c2e0;
          }
        }
      }
    }
  }
  local_3c = iVar9;
  _FSPathMakeRef(iVar12,local_d2,0);
  local_1d[0] = 1;
  iVar9 = _FSPathMakeRef(iVar12,local_d2,local_1d);
  if (iVar9 == 0) {
    _AECreateDesc(0x66737266,local_d2,0x50,&local_38);
  }
  _memset(&local_82,0,0x42);
  local_2c = 0;
  _memset(local_272,0,0x100);
  iVar9 = _NavGetDefaultDialogCreationOptions(&local_82);
  if (iVar9 != 0) {
    _fprintf((FILE *)(PTR_001037f8 + 0xb0),
             "[LinPlug] Cannot get default dialog options! Error code: %ld\n",iVar9);
    _memset(&local_82,0,0x42);
    local_82 = 0;
    local_80 = 0xe4;
    local_58 = 2;
  }
  uVar10 = *(undefined4 *)PTR_001037ec;
  local_74 = _CFStringCreateWithCString(uVar10,*(undefined4 *)(param_1 + 4),0x8000100);
  local_64 = _CFStringCreateWithCString(uVar10,*(undefined4 *)(param_1 + 8),0x8000100);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar9 = _NavCreateChooseFileDialog(&local_82,0,iVar5,0,iVar6,&local_40,&local_2c);
  }
  else {
    if (*(int *)(param_1 + 0xc) != 1) goto LAB_0002c439;
    iVar9 = _CFURLCreateWithString(uVar10,&cf_Untitled,0);
    if (iVar9 != 0) {
      if ((((local_40 != 0) && (iVar8 = _CFArrayGetCount(local_40), 0 < iVar8)) &&
          (iVar7 = _CFArrayGetValueAtIndex(iVar7,0), iVar7 != 0)) &&
         ((iVar8 = _CFStringGetLength(iVar7), 0 < iVar8 &&
          (iVar7 = _CFURLCreateCopyAppendingPathExtension(uVar10,iVar9,iVar7), iVar7 != 0)))) {
        local_68 = _CFURLGetString(iVar7);
        _CFRetain(local_68);
        _CFRelease(iVar7);
      }
      _CFRelease(iVar9);
    }
    iVar9 = _NavCreatePutFileDialog(&local_82,0,0x2a2a2a2a,iVar5,&local_40,&local_2c);
  }
  if (iVar9 != 0) goto LAB_0002c439;
  iVar9 = _NavDialogRun(local_2c);
  if (iVar9 == 0) {
    _memset(local_272,0,0x100);
    iVar9 = _NavDialogGetReply(local_2c,local_272);
    _NavDialogDispose(local_2c);
    local_2c = 0;
    if ((iVar9 == 0) && (local_270 != '\0')) {
      local_24 = 0;
      sVar3 = _AEGetNthPtr(local_26c,1,0x66737266,&local_30,local_28,local_122,0x50,&local_24);
      iVar9 = (int)sVar3;
      if (sVar3 == 0) {
        if (*(int *)(param_1 + 0xc) == 1) {
          iVar9 = _CFStringGetLength(local_25a);
          pvVar11 = operator_new__(iVar9 * 2);
          _CFStringGetCharacters(local_25a,0,iVar9,pvVar11);
          if (local_26f == '\0') {
            sVar3 = _FSCreateFileUnicode(local_122,iVar9,pvVar11,0,0,local_172,0);
          }
          else {
            sVar3 = _FSMakeFSRefUnicode(local_122,iVar9,pvVar11,0xffff,local_172);
          }
          local_2c8 = local_172;
          iVar9 = (int)sVar3;
          if (iVar9 == 0) {
            iVar9 = _FSRefMakePath(local_2c8,pcVar4,0x140);
          }
          else {
            _fprintf((FILE *)(PTR_001037f8 + 0xb0),
                     "[LinPlug] Cannot create save filepath! Error code: %ld\n",iVar9);
          }
          if (pvVar11 != (void *)0x0) {
            operator_delete__(pvVar11);
          }
        }
        else {
          iVar9 = _FSRefMakePath(local_122,pcVar4,0x140);
        }
        if (iVar9 == 0) goto LAB_0002c522;
      }
      _fprintf((FILE *)(PTR_001037f8 + 0xb0),"[LinPlug] NavDialog error! Error code: %ld\n",iVar9);
    }
  }
LAB_0002c522:
  if (*(int *)(param_1 + 0xc) == 1) {
    _NavCompleteSave(local_272,0);
  }
  _NavDisposeReply(local_272);
LAB_0002c439:
  if (local_74 != 0) {
    _CFRelease(local_74);
  }
  if (local_64 != 0) {
    _CFRelease(local_64);
  }
  if (local_68 != 0) {
    _CFRelease(local_68);
  }
  if (local_40 != 0) {
    _CFRelease(local_40);
  }
  if (local_3c != 0) {
    _CFRelease(local_3c);
  }
  if (local_34 != 0) {
    _AEDisposeDesc(&local_38);
  }
  _DisposeNavEventUPP(iVar5);
  _DisposeNavObjectFilterUPP(iVar6);
  if (*(char *)(param_1 + 0x19c) != '\0') {
    FUN_00009996(param_1 + 0x420,pcVar4,iVar12);
    FUN_0002e63a(param_1 + 0x6b4,*(undefined4 *)(param_1 + 0x58),iVar12);
  }
  return pcVar4;
}

