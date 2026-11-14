/* 000a4ba0 FUN_000a4ba0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_000a4ba0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  short *psVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  undefined2 *puVar11;
  uint local_70;
  undefined1 local_68 [8];
  undefined1 local_60 [8];
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  undefined4 local_24;
  uint local_20 [4];
  
  uVar3 = _GetEventClass(param_2);
  uVar4 = _GetEventKind(param_2);
  iVar5 = param_3[0x19];
  if (uVar3 == 0x6d6f7573) {
    if (uVar4 != 10) {
      return 0xffffd96e;
    }
    _GetEventParameter(param_2,0x77696e64,0x77696e64,0,4,0,&local_28);
    _GetEventParameter(param_2,0x6d776178,0x6d776178,0,2,0,local_20);
    _GetEventParameter(param_2,0x6d77646c,0x6c6f6e67,0,4,0,&local_24);
    _GetEventParameter(param_2,0x776d6f75,0x68697074,0,8,0,&local_38);
    _GetEventParameter(param_2,0x6b6d6f64,0x6d61676e,0,4,0,&local_30);
    iVar6 = param_3[0x1f];
    uVar8 = _HIViewGetRoot(local_28);
    _HIViewConvertPoint(&local_38,uVar8,iVar6);
    local_44 = (float)(int)local_34;
    local_48 = (float)(int)local_38;
    piVar9 = (int *)param_3[0x25];
    if (piVar9 == (int *)0x0) {
      iVar6 = param_3[0x19];
      piVar9 = (int *)operator_new(0x68);
      FUN_000a171a(piVar9,param_3,0,iVar6);
    }
    else {
      (**(code **)(*piVar9 + 0xc))(piVar9);
      piVar9 = (int *)param_3[0x25];
    }
    if (((short)local_20[0] == 1) && ((local_30 & 0x100) == 0)) {
      uVar8 = 1;
    }
    else {
      uVar8 = 0;
    }
    _GetWindowAttributes(iVar5,&local_2c);
    if ((local_2c & 0x80000) == 0) {
      _GetControlBounds(param_3[0x1f],&local_58);
      _fprintf((FILE *)(PTR_001037f8 + 0xb0),"Mouse wheel: control bounds %ld %ld\n",
               (int)local_58._2_2_,(int)(short)local_58);
      local_48 = (float)((int)local_48 - (int)local_58._2_2_);
      local_44 = (float)((int)local_44 - (int)(short)local_58);
    }
    (**(code **)(*param_3 + 0x34))(param_3,piVar9,&local_48,uVar8,(float)(int)local_24);
    (**(code **)(*piVar9 + 8))(piVar9);
    return 0;
  }
  if (0x6d6f7573 < uVar3) {
    if (uVar3 == 0x7363726c) {
      if (uVar4 == 1) {
        local_58 = (float)(param_3[4] - param_3[2]);
        local_54 = (float)(param_3[5] - param_3[3]);
        _SetEventParameter(param_2,0x696d737a,0x6869737a,8,&local_58);
        local_48 = (float)param_3[0x23];
        local_44 = (float)param_3[0x24];
        _SetEventParameter(param_2,0x6f72676e,0x68697074,8,&local_48);
        local_38 = 50.0;
        local_34 = 20.0;
        _SetEventParameter(param_2,0x6c6e737a,0x6869737a,8,&local_38);
        _HIViewGetBounds(param_3[0x1f],local_68);
        _SetEventParameter(param_2,0x7677737a,0x6869737a,8,local_60);
        return 0;
      }
      if (uVar4 != 10) {
        return 0xffffd96e;
      }
      _GetEventParameter(param_2,0x6f72676e,0x68697074,0,8,0,&local_48);
      param_3[0x23] = (int)local_48;
      param_3[0x24] = (int)local_44;
      _HIViewSetBoundsOrigin(param_3[0x1f],local_48,local_44);
      _HIViewSetNeedsDisplay(param_3[0x1f],1);
      return 0;
    }
    if (uVar3 != 0x74657874) {
      return 0xffffd96e;
    }
    if (uVar4 != 2) {
      return 0xffffd96e;
    }
    _GetEventParameter(param_2,0x74736b65,0x65767266,0,4,0,&local_2c);
    if (local_2c != 0) {
      local_28 = 0;
      _GetEventParameter(local_2c,0x6b636f64,0x6d61676e,0,4,0,&local_28);
      if ((int)DAT_000e2126 == local_28) {
        return 0xffffd96e;
      }
    }
    return 0xffffd968;
  }
  if (uVar3 != 0x636e746c) {
    if (uVar3 != 0x6b657962) {
      return 0xffffd96e;
    }
    if ((char)param_3[0x20] == '\0') {
      return 0xffffd96e;
    }
    if (1 < uVar4 - 1) {
      return 0xffffd96e;
    }
    local_20[0] = local_20[0] & 0xffffff00;
    local_28 = 0;
    local_2c = 0;
    _GetEventParameter(param_2,0x6b636872,0x54455854,0,1,0,local_20);
    _GetEventParameter(param_2,0x6b636f64,0x6d61676e,0,4,0,&local_28);
    _GetEventParameter(param_2,0x6b6d6f64,0x6d61676e,0,4,0,&local_2c);
    cVar2 = (char)local_28;
    local_58 = 0.0;
    local_54 = (float)((uint)local_54._2_2_ << 0x10);
    iVar5 = _KLGetCurrentKeyboardLayout(&local_30);
    if (iVar5 == 0) {
      local_24 = 0;
      _KLGetKeyboardLayoutProperty(local_30,0,&local_24);
      if ((local_24 != 0) &&
         (local_58 = (float)_KeyTranslate(local_24,local_28 & 0xffff,&DAT_000fd52c),
         (local_2c & 0x200) != 0)) {
        local_58 = (float)___toupper((__darwin_ct_rune_t)local_58);
      }
    }
    puVar11 = &DAT_000e2120;
    if ((int)DAT_000e2122 == (int)cVar2) {
      iVar5 = 0;
    }
    else {
      iVar5 = 0;
      do {
        iVar5 = iVar5 + 2;
        if (iVar5 == 0x5e) goto LAB_000a4d5f;
        psVar1 = puVar11 + 3;
        puVar11 = puVar11 + 2;
      } while ((int)*psVar1 != (int)cVar2);
    }
    local_54 = (float)CONCAT31(local_54._1_3_,(char)(&DAT_000e2120)[iVar5]);
    local_58 = 0.0;
LAB_000a4d5f:
    if ((local_2c & 0x100) != 0) {
      local_54 = (float)((uint)local_54 | 0x800);
    }
    if ((local_2c & 0x200) != 0) {
      local_54 = (float)((uint)local_54 | 0x100);
    }
    if ((local_2c & 0x800) != 0) {
      local_54 = (float)((uint)local_54 | 0x200);
    }
    if ((local_2c & 0x1000) != 0) {
      local_54 = (float)((uint)local_54 | 0x400);
    }
    iVar5 = (**(code **)(*param_3 + 0x28))(param_3,&local_58);
    if (iVar5 == -1) {
      return 0xffffd96e;
    }
    return 0;
  }
  if (uVar4 == 0x11) {
    local_20[0] = 3;
    _SetEventParameter(param_2,0x636c6163,0x636c6163,4,local_20);
    return 0;
  }
  if (0x11 < uVar4) {
    if (uVar4 == 0x15) {
      if (DAT_000fd51c != (int *)0x0) {
        piVar9 = (int *)param_3[0x25];
        if (piVar9 == (int *)0x0) {
          piVar9 = (int *)operator_new(0x68);
          FUN_000a171a(piVar9,param_3,0,iVar5);
        }
        else {
          (**(code **)(*piVar9 + 0xc))(piVar9);
          piVar9 = (int *)param_3[0x25];
        }
        local_58 = 0.0;
        local_54 = 0.0;
        (**(code **)(*param_3 + 0x84))(param_3,piVar9,&local_58);
        (**(code **)(*param_3 + 0x38))(param_3,piVar9,DAT_000fd51c,&local_58);
        (**(code **)(*param_3 + 0x138))(param_3,0);
        (**(code **)(*piVar9 + 8))(piVar9);
        (**(code **)(*DAT_000fd51c + 8))(DAT_000fd51c);
        DAT_000fd51c = (int *)0x0;
        return 0;
      }
    }
    else {
      if (0x15 < uVar4) {
        if (uVar4 == 1000) {
          local_24 = 0x1126;
          _SetEventParameter(param_2,0x63667472,0x6d61676e,4,&local_24);
          return 0;
        }
        if (uVar4 == 0x3eb) {
          local_48 = 0.0;
          local_44 = 0.0;
          local_40 = (float)(param_3[4] - param_3[2]);
          local_3c = (float)(param_3[5] - param_3[3]);
          _SetEventParameter(param_2,0x636f626e,0x68697263,0x10,&local_48);
          return 0;
        }
        if (uVar4 != 0x33) {
          return 0xffffd96e;
        }
        goto LAB_000a5582;
      }
      if (uVar4 == 0x13) {
        if (DAT_000fd51c != (int *)0x0) {
          piVar9 = (int *)param_3[0x25];
          if (piVar9 == (int *)0x0) {
            piVar9 = (int *)operator_new(0x68);
            FUN_000a171a(piVar9,param_3,0,iVar5);
          }
          else {
            (**(code **)(*piVar9 + 0xc))(piVar9);
            piVar9 = (int *)param_3[0x25];
          }
          local_48 = 0.0;
          local_44 = 0.0;
          (**(code **)(*param_3 + 0x84))(param_3,piVar9,&local_48);
          (**(code **)(*param_3 + 0x44))(param_3,piVar9,DAT_000fd51c,&local_48);
          (**(code **)(*piVar9 + 8))(piVar9);
          return 0;
        }
      }
      else if (uVar4 < 0x14) {
        DAT_000fd520 = 1;
        iVar5 = _GetEventParameter(param_2,0x64726167,0x64726167,0,4,0,&local_30);
        if (iVar5 == 0) {
          puVar7 = (undefined4 *)operator_new(0x18);
          puVar7[1] = 1;
          *puVar7 = &PTR_CDragContainer_vslot_0_000f4400;
          puVar7[2] = local_30;
          puVar7[3] = 0;
          puVar7[4] = 0;
          puVar7[5] = 0;
          _CountDragItems(local_30,&local_24);
          puVar7[3] = local_24 & 0xffff;
          piVar9 = (int *)param_3[0x25];
          DAT_000fd51c = puVar7;
          if (piVar9 == (int *)0x0) {
            iVar5 = param_3[0x19];
            piVar9 = (int *)operator_new(0x68);
            FUN_000a171a(piVar9,param_3,0,iVar5);
          }
          else {
            (**(code **)(*piVar9 + 0xc))(piVar9);
            piVar9 = (int *)param_3[0x25];
          }
          local_48 = 0.0;
          local_44 = 0.0;
          (**(code **)(*param_3 + 0x138))(param_3,8);
          (**(code **)(*param_3 + 0x84))(param_3,piVar9,&local_48);
          (**(code **)(*param_3 + 0x3c))(param_3,piVar9,DAT_000fd51c,&local_48);
          (**(code **)(*piVar9 + 8))(piVar9);
          local_20[0] = CONCAT31(local_20[0]._1_3_,1);
          _SetEventParameter(param_2,0x636c6467,0x626f6f6c,1,local_20);
          return 0;
        }
      }
      else if (DAT_000fd51c != (int *)0x0) {
        piVar9 = (int *)param_3[0x25];
        if (piVar9 == (int *)0x0) {
          piVar9 = (int *)operator_new(0x68);
          FUN_000a171a(piVar9,param_3,0,iVar5);
        }
        else {
          (**(code **)(*piVar9 + 0xc))(piVar9);
          piVar9 = (int *)param_3[0x25];
        }
        local_48 = 0.0;
        local_44 = 0.0;
        (**(code **)(*param_3 + 0x84))(param_3,piVar9,&local_48);
        (**(code **)(*param_3 + 0x40))(param_3,piVar9,DAT_000fd51c,&local_48);
        (**(code **)(*param_3 + 0x138))(param_3,0);
        (**(code **)(*piVar9 + 8))(piVar9);
        return 0;
      }
    }
    return 0;
  }
  if (uVar4 != 7) {
    if (uVar4 < 8) {
      if (uVar4 == 3) {
        local_24 = CONCAT22(local_24._2_2_,0xfffe);
        _SetEventParameter(param_2,0x63707274,0x63707274,2,&local_24);
        return 0;
      }
      if (uVar4 != 4) {
        return 0xffffd96e;
      }
      piVar9 = (int *)param_3[0x25];
      if (piVar9 == (int *)0x0) {
        local_20[0] = 0;
        _GetEventParameter(param_2,0x636e7478,0x636e7478,0,4,0,local_20);
        piVar9 = (int *)operator_new(0x68);
        FUN_000a171a(piVar9,param_3,0,iVar5);
      }
      else {
        (**(code **)(*piVar9 + 0xc))(piVar9);
      }
      iVar6 = _GetEventParameter(param_2,0x72676e68,0x72676e68,0,4,0,&local_24);
      if (iVar6 == 0) {
        iVar6 = param_3[0xc];
        _GetRegionBounds(local_24,&local_48);
        local_58 = (float)(int)local_48._2_2_;
        local_50 = (int)local_44._2_2_;
        local_54 = (float)(int)(short)local_48;
        local_4c = (int)(short)local_44;
        _GetWindowAttributes(iVar5,local_20);
        if ((local_20[0] & 0x80000) == 0) {
          local_58 = (float)((int)local_58 + -piVar9[2]);
          local_50 = local_50 + -piVar9[2];
          local_54 = (float)((int)local_54 + -piVar9[3]);
          local_4c = local_4c + -piVar9[3];
        }
        (**(code **)(*param_3 + 0x14))(param_3,piVar9,&local_58);
        if (((char)iVar6 != '\0') &&
           ((((local_58 != (float)param_3[2] || (local_50 != param_3[4])) ||
             (local_54 != (float)param_3[3])) || (local_4c != param_3[5])))) {
          (**(code **)(*param_3 + 0x54))(param_3,1);
        }
      }
      else {
        (**(code **)(*param_3 + 0x10))(param_3,piVar9);
      }
      (**(code **)(*piVar9 + 8))(piVar9);
      return 0;
    }
    if (uVar4 != 0xc) {
      if (uVar4 != 0xd) {
        if (uVar4 != 8) {
          return 0xffffd96e;
        }
        if (DAT_000e20a0 == '\0') {
          return 0xffffd96e;
        }
        local_24 = CONCAT22(local_24._2_2_,~-(ushort)((char)param_3[0x20] == '\0')) & 0xffff007f;
        goto LAB_000a5794;
      }
      _GetEventParameter(param_2,0x6d62746e,0x6d62746e,0,2,0,local_20);
      if ((short)local_20[0] == 1) {
        uVar8 = _CallNextEventHandler(param_1,param_2);
        return uVar8;
      }
    }
LAB_000a5582:
    _GetEventParameter(param_2,0x6d6c6f63,0x68697074,0,8,0,&local_38);
    if (uVar4 == 0xc) {
      local_70 = 4;
    }
    else if (uVar4 == 0x33) {
      _GetEventParameter(param_2,0x6b6d6f64,0x6d61676e,0,4,0,&local_24);
      uVar10 = (-(uint)((local_24 & 0x100) == 0) & 0xfffffff0) + 0x11;
      uVar3 = uVar10 | 8;
      if ((local_24 & 0x200) == 0) {
        uVar3 = uVar10;
      }
      local_70 = uVar3 | 0x20;
      if ((local_24 & 0x800) == 0) {
        local_70 = uVar3;
      }
      if ((local_24 & 0x1000) != 0) {
        local_70 = local_70 | 0x40;
      }
    }
    else {
      _GetEventParameter(param_2,0x6b6d6f64,0x6d61676e,0,4,0,&local_24);
      _GetEventParameter(param_2,0x6d62746e,0x6d62746e,0,2,0,local_20);
      if ((short)local_20[0] == 1) {
        local_70 = 1;
      }
      else if ((short)local_20[0] == 2) {
        local_70 = 4;
      }
      else {
        local_70 = 2;
        if ((short)local_20[0] != 3) {
          local_70 = 0;
        }
      }
      uVar3 = local_70 | 0x10;
      if ((local_24 & 0x100) == 0) {
        uVar3 = local_70;
      }
      uVar10 = uVar3 | 8;
      if ((local_24 & 0x200) == 0) {
        uVar10 = uVar3;
      }
      uVar3 = uVar10 | 0x20;
      if ((local_24 & 0x800) == 0) {
        uVar3 = uVar10;
      }
      local_70 = uVar3 | 0x40;
      if ((local_24 & 0x1000) == 0) {
        local_70 = uVar3;
      }
    }
    _GetWindowAttributes(iVar5,&local_30);
    local_58 = (float)CONCAT22((short)(int)local_38,(short)(int)local_34);
    if ((uVar4 == 0xd) && ((local_30 & 0x80000) == 0)) {
      uVar8 = _GetWindowPort(iVar5);
      _QDGlobalToLocalPoint(uVar8,&local_58);
    }
    piVar9 = (int *)param_3[0x25];
    if (piVar9 == (int *)0x0) {
      iVar5 = param_3[0x19];
      piVar9 = (int *)operator_new(0x68);
      FUN_000a171a(piVar9,param_3,0,iVar5);
    }
    else {
      (**(code **)(*piVar9 + 0xc))(piVar9);
      piVar9 = (int *)param_3[0x25];
    }
    local_44 = (float)(int)(short)local_58;
    local_48 = (float)(int)local_58._2_2_;
    if ((local_30 & 0x80000) == 0) {
      local_48 = (float)((int)local_48 - piVar9[2]);
      local_44 = (float)((int)local_44 - piVar9[3]);
    }
    (**(code **)(*param_3 + 0x1c))(param_3,piVar9,&local_48,local_70);
    (**(code **)(*piVar9 + 8))(piVar9);
    return 0;
  }
  if (DAT_000e20a0 == '\0') {
    return 0xffffd96e;
  }
  _GetEventParameter(param_2,0x63707274,0x63707274,0,2,0,&local_24);
  if ((short)local_24 == 0) {
    *(undefined1 *)(param_3 + 0x20) = 0;
    (**(code **)(*param_3 + 0x13c))(param_3,0);
    goto LAB_000a5794;
  }
  if ((short)local_24 == -1) {
    cVar2 = (**(code **)(*param_3 + 0xf0))(param_3,param_3[0x1b],0);
LAB_000a5e40:
    if (cVar2 != '\0') {
      *(undefined1 *)(param_3 + 0x20) = 1;
      local_24 = CONCAT22(local_24._2_2_,0x7f);
      goto LAB_000a5794;
    }
  }
  else if ((short)local_24 == -2) {
    cVar2 = (**(code **)(*param_3 + 0xf0))(param_3,param_3[0x1b],1);
    goto LAB_000a5e40;
  }
  *(undefined1 *)(param_3 + 0x20) = 0;
  local_24 = local_24 & 0xffff0000;
LAB_000a5794:
  _SetEventParameter(param_2,0x63707274,0x63707274,2,&local_24);
  return 0;
}

