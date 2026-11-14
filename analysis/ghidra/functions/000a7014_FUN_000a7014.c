/* 000a7014 FUN_000a7014 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int FUN_000a7014(int *param_1,uint *param_2,undefined4 param_3,int param_4,uint param_5,
                uint *param_6)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  pthread_t p_Var8;
  undefined4 *puVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  int *piVar14;
  uint *puVar15;
  uint local_3c;
  uint local_20 [4];
  
  uVar3 = MXCSR;
  MXCSR = MXCSR | 0x8040;
  local_20[0] = MXCSR;
  if (*(char *)((int)param_1 + 0xd) == '\0') {
    puVar9 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar9 = 0xffffd58d;
  }
  else if ((uint)param_1[0x28] < param_5) {
    puVar9 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar9 = 0xffffd586;
  }
  else {
    piVar14 = (int *)param_1[0x14] + param_4;
    if (((piVar14 < (int *)param_1[0x15]) && ((int *)param_1[0x14] <= piVar14)) &&
       (iVar1 = *piVar14, iVar1 != 0)) {
      if ((*(int *)(iVar1 + 0x3c) == 0x6c70636d) && ((*(byte *)(iVar1 + 0x40) & 0x20) != 0)) {
        uVar5 = *(uint *)(iVar1 + 0x50);
      }
      else {
        uVar5 = 1;
      }
      if (uVar5 != *param_6) {
        return -0x32;
      }
      if ((char)param_1[0x25] != '\0') {
        p_Var8 = _pthread_self();
        param_1[0x24] = (int)p_Var8;
      }
      piVar14 = param_1 + 0x21;
      do {
        piVar12 = (int *)param_1[0x22];
        if (piVar12 == (int *)0x0) goto LAB_000a7243;
        cVar4 = _CompareAndSwap(piVar12,0,param_1 + 0x22);
      } while (cVar4 == '\0');
      piVar7 = (int *)0x0;
      do {
        piVar10 = piVar12;
        piVar11 = piVar7;
        piVar12 = (int *)*piVar10;
        *piVar10 = (int)piVar11;
        piVar7 = piVar10;
      } while (piVar12 != (int *)0x0);
      iVar6 = piVar10[1];
      do {
        piVar12 = piVar11;
        if (iVar6 == 1) {
          if ((int *)*piVar14 != (int *)0x0) {
            piVar7 = piVar14;
            piVar11 = (int *)*piVar14;
LAB_000a71f7:
            if ((piVar11[2] != piVar10[2]) || (piVar11[3] != piVar10[3])) goto LAB_000a71eb;
            *piVar7 = *piVar11;
            do {
              iVar6 = param_1[0x23];
              *piVar11 = iVar6;
              cVar4 = _CompareAndSwap(iVar6,piVar11,param_1 + 0x23);
            } while (cVar4 == '\0');
          }
LAB_000a74a0:
          do {
            iVar6 = param_1[0x23];
            *piVar10 = iVar6;
            cVar4 = _CompareAndSwap(iVar6,piVar10,param_1 + 0x23);
          } while (cVar4 == '\0');
        }
        else if (iVar6 == 2) {
          if ((int *)*piVar14 != (int *)0x0) {
            piVar7 = (int *)*piVar14;
            do {
              piVar11 = (int *)*piVar7;
              do {
                iVar6 = param_1[0x23];
                *piVar7 = iVar6;
                cVar4 = _CompareAndSwap(iVar6,piVar7,param_1 + 0x23);
              } while (cVar4 == '\0');
              piVar7 = piVar11;
            } while (piVar11 != (int *)0x0);
          }
          do {
            iVar6 = param_1[0x23];
            *piVar10 = iVar6;
            cVar4 = _CompareAndSwap(iVar6,piVar10,param_1 + 0x23);
          } while (cVar4 == '\0');
        }
        else if (iVar6 == 0) {
          piVar7 = piVar14;
          if ((int *)*piVar14 != (int *)0x0) {
            piVar11 = (int *)*piVar14;
LAB_000a717a:
            piVar7 = piVar11;
            if ((piVar7[2] != piVar10[2]) || (piVar7[3] != piVar10[3])) goto LAB_000a716e;
            do {
              iVar6 = param_1[0x23];
              *piVar10 = iVar6;
              cVar4 = _CompareAndSwap(iVar6,piVar10,param_1 + 0x23);
            } while (cVar4 == '\0');
            goto LAB_000a71ab;
          }
LAB_000a748a:
          *piVar7 = (int)piVar10;
          *piVar10 = 0;
        }
LAB_000a71ab:
        if (piVar12 == (int *)0x0) goto LAB_000a7243;
        iVar6 = piVar12[1];
        piVar11 = (int *)*piVar12;
        piVar10 = piVar12;
      } while( true );
    }
    puVar9 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar9 = 0xffffd583;
  }
  goto LAB_000a70bd;
LAB_000a71eb:
  piVar2 = (int *)*piVar11;
  piVar7 = piVar11;
  piVar11 = piVar2;
  if (piVar2 == (int *)0x0) goto LAB_000a74a0;
  goto LAB_000a71f7;
LAB_000a716e:
  piVar11 = (int *)*piVar7;
  if ((int *)*piVar7 == (int *)0x0) goto LAB_000a748a;
  goto LAB_000a717a;
LAB_000a7243:
  local_20[0] = *param_2 | 4;
  piVar12 = (int *)*piVar14;
  if (piVar12 != (int *)0x0) {
    do {
      (*(code *)piVar12[2])(piVar12[3],local_20,param_3,param_4,param_5,param_6);
      piVar12 = (int *)*piVar12;
    } while (piVar12 != (int *)0x0);
  }
  if ((param_6[3] == 0) || (1 < (uint)(param_1[0x15] - param_1[0x14] >> 2))) {
    FUN_000ae306(iVar1 + 0x5c,iVar1 + 0x34,param_5);
LAB_000a72c4:
    iVar6 = (**(code **)(*param_1 + 0x54))(param_1,param_2,param_3,param_4,param_5);
    if (iVar6 != 0) {
LAB_000a736f:
      local_20[0] = *param_2 | 8;
      piVar14 = (int *)*piVar14;
      if (piVar14 != (int *)0x0) {
        do {
          (*(code *)piVar14[2])(piVar14[3],local_20,param_3,param_4,param_5,param_6);
          piVar14 = (int *)*piVar14;
        } while (piVar14 != (int *)0x0);
      }
      if (param_1[0x2d] != param_1[0x2c]) {
        FUN_000c52f4(param_1 + 0x2c,param_1[0x2c],param_1[0x2d]);
      }
      local_20[0] = uVar3;
      MXCSR = uVar3;
      if ((iVar6 != 0) && (param_1[0x29] == 0)) {
        param_1[0x29] = iVar6;
        FUN_000a67ae(param_1,0x16,0,0);
      }
      return iVar6;
    }
    if (param_6[3] == 0) {
      if (*(int *)(iVar1 + 0x5c) != 0) {
        _memcpy(param_6,*(void **)(iVar1 + 100),*param_6 * 0xc + 4);
        goto LAB_000a736f;
      }
    }
    else if (*(int *)(iVar1 + 0x5c) != 0) {
      iVar13 = *(int *)(iVar1 + 100) + 4;
      puVar15 = param_6 + 1;
      uVar5 = *param_6;
      if (uVar5 != 0) {
        local_3c = 0;
        do {
          if ((void *)puVar15[2] != *(void **)(iVar13 + 8)) {
            _memmove((void *)puVar15[2],*(void **)(iVar13 + 8),*(size_t *)(iVar13 + 4));
          }
          puVar15[1] = *(uint *)(iVar13 + 4);
          iVar13 = iVar13 + 0xc;
          puVar15 = puVar15 + 3;
          local_3c = local_3c + 1;
        } while (uVar5 != local_3c);
      }
      *(undefined4 *)(iVar1 + 0x5c) = 0;
      goto LAB_000a736f;
    }
  }
  else if (*param_6 <= *(uint *)(iVar1 + 0x6c)) {
    *(undefined4 *)(iVar1 + 0x5c) = 2;
    _memcpy(*(void **)(iVar1 + 100),param_6,*param_6 * 0xc + 4);
    goto LAB_000a72c4;
  }
  puVar9 = (undefined4 *)___cxa_allocate_exception(4);
  *puVar9 = 0xffffffff;
LAB_000a70bd:
                    /* WARNING: Subroutine does not return */
  ___cxa_throw(puVar9,PTR_001037fc,0);
}

