/* 0008032a Pan_c_vslot_56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Pan_c_vslot_56(int param_1,uint param_2)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  float fVar6;
  
  *(undefined4 *)(param_1 + 0x1e4) = *(undefined4 *)(param_1 + 0x1e0);
  if (*(char *)(*(int *)(param_1 + 0x10) + 0x26) == '\0') {
    if (((*(char *)(*(int *)(param_1 + 0x10) + 0x27) != '\0') && (*(int *)(param_1 + 0x124) != 0))
       && (*(int *)(param_1 + 0x1e0) != 0)) {
      (**(code **)(**(int **)(param_1 + 0x118) + 0x2c))
                (*(int **)(param_1 + 0x118),param_1 + 0x1f8,param_1 + 0x1fc);
      (**(code **)(**(int **)(param_1 + 0x11c) + 0x2c))
                (*(int **)(param_1 + 0x11c),param_1 + 0x200,param_1 + 0x204);
      (**(code **)(**(int **)(param_1 + 0x10) + 0x38))
                (*(int **)(param_1 + 0x10),param_1 + 0x1f0,param_1 + 500);
      if (0 < (int)param_2) {
        uVar5 = 0;
        do {
          uVar4 = uVar5 & 7;
          uVar5 = uVar5 + 1;
          if (uVar4 == 0) {
            fVar6 = (**(float **)(param_1 + 0x1e4) + 1.0) * 0.5;
            *(float *)(param_1 + 0x1ec) = fVar6;
            *(float **)(param_1 + 0x1e4) = *(float **)(param_1 + 0x1e4) + 1;
            fVar3 = 1e-05;
            if (1e-05 <= fVar6) {
              fVar3 = (float)(~-(uint)(fVar6 <= 0.99999) & (uint)0.99999 |
                             (uint)fVar6 & -(uint)(fVar6 <= 0.99999));
            }
            *(float *)(param_1 + 0x1ec) = fVar3;
            *(float *)(param_1 + 0x1e8) = 1.0 - *(float *)(param_1 + 0x1ec);
          }
          pfVar1 = *(float **)(param_1 + 0x1f8);
          *pfVar1 = **(float **)(param_1 + 0x1f0) * *(float *)(param_1 + 0x1e8) + *pfVar1;
          *(float **)(param_1 + 0x1f8) = pfVar1 + 1;
          pfVar1 = *(float **)(param_1 + 0x200);
          pfVar2 = *(float **)(param_1 + 0x1f0);
          *pfVar1 = *pfVar2 * *(float *)(param_1 + 0x1ec) + *pfVar1;
          *(float **)(param_1 + 0x200) = pfVar1 + 1;
          *(float **)(param_1 + 0x1f0) = pfVar2 + 1;
          pfVar1 = *(float **)(param_1 + 0x1fc);
          *pfVar1 = **(float **)(param_1 + 500) * *(float *)(param_1 + 0x1e8) + *pfVar1;
          *(float **)(param_1 + 0x1fc) = pfVar1 + 1;
          pfVar1 = *(float **)(param_1 + 0x204);
          pfVar2 = *(float **)(param_1 + 500);
          *pfVar1 = *pfVar2 * *(float *)(param_1 + 0x1ec) + *pfVar1;
          *(float **)(param_1 + 0x204) = pfVar1 + 1;
          *(float **)(param_1 + 500) = pfVar2 + 1;
        } while (uVar5 != param_2);
      }
      (**(code **)(**(int **)(param_1 + 0x118) + 0x44))(*(int **)(param_1 + 0x118));
                    /* WARNING: Could not recover jumptable at 0x000806fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(param_1 + 0x11c) + 0x44))();
      return;
    }
  }
  else if ((*(int *)(param_1 + 0x124) != 0) && (*(int *)(param_1 + 0x1e0) != 0)) {
    (**(code **)(**(int **)(param_1 + 0x118) + 0x28))(*(int **)(param_1 + 0x118),param_1 + 0x1f8,0);
    (**(code **)(**(int **)(param_1 + 0x11c) + 0x28))(*(int **)(param_1 + 0x11c),param_1 + 0x200,0);
    (**(code **)(**(int **)(param_1 + 0x10) + 0x34))(*(int **)(param_1 + 0x10),param_1 + 0x1f0,0);
    if (0 < (int)param_2) {
      uVar5 = 0;
      do {
        uVar4 = uVar5 & 7;
        uVar5 = uVar5 + 1;
        if (uVar4 == 0) {
          fVar6 = (**(float **)(param_1 + 0x1e4) + 1.0) * 0.5;
          *(float *)(param_1 + 0x1ec) = fVar6;
          *(float **)(param_1 + 0x1e4) = *(float **)(param_1 + 0x1e4) + 1;
          fVar3 = 1e-05;
          if (1e-05 <= fVar6) {
            fVar3 = (float)(~-(uint)(fVar6 <= 0.99999) & (uint)0.99999 |
                           (uint)fVar6 & -(uint)(fVar6 <= 0.99999));
          }
          *(float *)(param_1 + 0x1ec) = fVar3;
          *(float *)(param_1 + 0x1e8) = 1.0 - *(float *)(param_1 + 0x1ec);
        }
        pfVar1 = *(float **)(param_1 + 0x1f8);
        *pfVar1 = **(float **)(param_1 + 0x1f0) * *(float *)(param_1 + 0x1e8) + *pfVar1;
        *(float **)(param_1 + 0x1f8) = pfVar1 + 1;
        pfVar1 = *(float **)(param_1 + 0x200);
        pfVar2 = *(float **)(param_1 + 0x1f0);
        *pfVar1 = *pfVar2 * *(float *)(param_1 + 0x1ec) + *pfVar1;
        *(float **)(param_1 + 0x200) = pfVar1 + 1;
        *(float **)(param_1 + 0x1f0) = pfVar2 + 1;
      } while (param_2 != uVar5);
    }
    (**(code **)(**(int **)(param_1 + 0x118) + 0x40))(*(int **)(param_1 + 0x118));
                    /* WARNING: Could not recover jumptable at 0x0008071f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x11c) + 0x40))();
    return;
  }
  return;
}

