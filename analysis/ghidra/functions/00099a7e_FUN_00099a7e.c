/* 00099a7e FUN_00099a7e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_00099a7e(undefined4 param_1,undefined4 param_2,int *param_3)

{
  short sVar1;
  bool bVar2;
  char cVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  __darwin_ct_rune_t _Var9;
  undefined4 uVar10;
  undefined1 local_5a [16];
  undefined1 local_4a [4];
  uint local_46;
  float local_3c;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_28;
  byte local_27;
  undefined1 local_24 [7];
  char local_1d [13];
  
  uVar5 = _GetEventClass(param_2);
  uVar6 = _GetEventKind(param_2);
  if (uVar5 == 0x6b657962) {
    if (1 < uVar6 - 1) goto LAB_00099acc;
    _GetEventParameter(param_2,0x6b636872,0x54455854,0,1,0,local_1d);
    _GetEventParameter(param_2,0x6b636f64,0x6d61676e,0,4,0,local_24);
    _GetEventParameter(param_2,0x6b6d6f64,0x6d61676e,0,4,0,&local_28);
    if ((local_1d[0] == '\r') || (local_1d[0] == '\x03')) {
      if (local_1d[0] == '\x1b') goto LAB_00099c58;
      *(undefined1 *)(param_3 + 0x2a) = 1;
    }
    else {
      if (local_1d[0] != '\x1b') {
        if (param_3[0x2b] == 0) {
          if ((local_27 & 1) == 0) {
            cVar3 = _ConvertEventRefToEventRecord(param_2,local_5a);
            if (cVar3 != '\0') {
              _TXNKeyDown(param_3[0x29],local_5a);
              return 0;
            }
          }
          else {
            iVar7 = param_3[0x29];
            _Var9 = ___toupper((int)local_1d[0]);
            if (_Var9 == 0x43) {
              cVar3 = _TXNIsSelectionEmpty(iVar7);
              if (cVar3 == '\0') {
                _ClearCurrentScrap();
                _TXNCopy(iVar7);
                return 0;
              }
            }
            else if (_Var9 < 0x44) {
              if (_Var9 == 0x41) {
                _TXNSelectAll(iVar7);
                return 0;
              }
            }
            else if (_Var9 == 0x56) {
              cVar3 = _TXNIsScrapPastable();
              if (cVar3 != '\0') {
                _TXNPaste(iVar7);
                return 0;
              }
            }
            else if ((_Var9 == 0x58) && (cVar3 = _TXNIsSelectionEmpty(iVar7), cVar3 == '\0')) {
              _ClearCurrentScrap();
              _TXNCopy(iVar7);
              _TXNGetSelection(iVar7,&local_30,&local_34);
              _TXNSetData(iVar7,0x75747874,0,0,local_30,local_34);
            }
          }
          goto LAB_00099fa3;
        }
        goto LAB_00099acc;
      }
LAB_00099c58:
      DAT_000fd4e0 = 1;
    }
    if (*(int *)(param_3[10] + 100) == 0) {
LAB_00099c8b:
      bVar2 = false;
    }
    else {
      uVar10 = _GetWindowPort(*(int *)(param_3[10] + 100));
      cVar3 = _QDSwapPort(uVar10,&local_30);
      if (cVar3 == '\0') goto LAB_00099c8b;
      bVar2 = true;
    }
    sVar4 = _CurResFile();
    sVar1 = *(short *)((int)param_3 + 0xaa);
    if ((sVar4 != sVar1) && (0 < sVar1)) {
      _UseResFile((int)sVar1);
    }
    (**(code **)(*param_3 + 0x48))(param_3,0);
    if (bVar2) {
      _QDSwapPort(local_30,0);
    }
    if (((0 < sVar4) && (sVar4 != sVar1)) && (0 < sVar1)) {
      _UseResFile((int)sVar4);
      return 0;
    }
LAB_00099fa3:
    uVar10 = 0;
  }
  else {
    if (uVar5 < 0x6b657963) {
      if ((uVar5 == 0x636d6473) && (iVar7 = param_3[0x29], uVar6 == 1)) {
        _GetEventParameter(param_2,0x2d2d2d2d,0x68636d64,0,0xe,0,local_4a);
        if (local_46 == 0x63757420) {
          cVar3 = _TXNIsSelectionEmpty(iVar7);
          if (cVar3 == '\0') {
            _ClearCurrentScrap();
            uVar10 = _TXNCopy(iVar7);
            _TXNGetSelection(iVar7,&local_30,&local_34);
            _TXNSetData(iVar7,0x75747874,0,0,local_30,local_34);
            return uVar10;
          }
        }
        else if (local_46 < 0x63757421) {
          if (local_46 == 0x636c6561) {
            cVar3 = _TXNIsSelectionEmpty(iVar7);
            if (cVar3 == '\0') {
              _TXNGetSelection(iVar7,&local_34,&local_30);
              uVar10 = _TXNSetData(iVar7,0x75747874,0,0,local_34,local_30);
              return uVar10;
            }
          }
          else {
            if (local_46 != 0x636f7079) goto LAB_00099acc;
            cVar3 = _TXNIsSelectionEmpty(iVar7);
            if (cVar3 == '\0') {
              _ClearCurrentScrap();
              uVar10 = _TXNCopy(iVar7);
              return uVar10;
            }
          }
        }
        else {
          if (local_46 != 0x70617374) {
            if (local_46 == 0x73616c6c) {
              _TXNSelectAll(iVar7);
              return 0;
            }
            goto LAB_00099acc;
          }
          cVar3 = _TXNIsScrapPastable();
          if (cVar3 != '\0') {
            uVar10 = _TXNPaste(iVar7);
            return uVar10;
          }
        }
        goto LAB_00099fa3;
      }
    }
    else if (uVar5 == 0x6d6f7573) {
      if (uVar6 != 0) {
        if (uVar6 < 3) {
          _GetEventParameter(param_2,0x77696e64,0x77696e64,0,4,0,&local_30);
          _GetEventParameter(param_2,0x6d6c6f63,0x68697074,0,8,0,&local_3c);
          local_2c = CONCAT22((short)(int)local_3c,(short)(int)local_38);
          uVar10 = _GetWindowPort(local_30);
          _QDGlobalToLocalPoint(uVar10,&local_2c);
          _TXNGetViewRect(param_3[0x29],local_4a);
          cVar3 = _PtInRect(local_2c,local_4a);
          if (cVar3 == '\0') {
            (**(code **)(*param_3 + 0x48))(param_3,0);
            return 0;
          }
          if (uVar6 == 1) {
            cVar3 = _ConvertEventRefToEventRecord(param_2,local_5a);
            if (cVar3 != '\0') {
              _TXNClick(param_3[0x29],local_5a);
              return 0;
            }
          }
          goto LAB_00099fa3;
        }
        if (uVar6 == 5) {
          _TXNAdjustCursor(param_3[0x29],0);
        }
      }
    }
    else if (((uVar5 == 0x77696e64) &&
             (iVar7 = _GetEventParameter(param_2,0x2d2d2d2d,0x77696e64,0,4,0,&local_30), iVar7 == 0)
             ) && (uVar6 == 6)) {
      uVar10 = _CallNextEventHandler(param_1,param_2);
      _ClearKeyboardFocus(local_30);
      uVar8 = _GetWindowPort(local_30);
      cVar3 = _QDSwapPort(uVar8,&local_34);
      sVar4 = _CurResFile();
      sVar1 = *(short *)((int)param_3 + 0xaa);
      if ((sVar4 != sVar1) && (0 < sVar1)) {
        _UseResFile((int)sVar1);
      }
      (**(code **)(*param_3 + 0x48))(param_3,0);
      if (cVar3 != '\0') {
        _QDSwapPort(local_34,0);
      }
      if (sVar4 < 1) {
        return uVar10;
      }
      if (sVar4 == sVar1) {
        return uVar10;
      }
      if (sVar1 < 1) {
        return uVar10;
      }
      _UseResFile((int)sVar4);
      return uVar10;
    }
LAB_00099acc:
    uVar10 = 0xffffd96e;
  }
  return uVar10;
}

