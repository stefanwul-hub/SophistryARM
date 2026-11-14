/* 0001ab48 FUN_0001ab48 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

uint FUN_0001ab48(int *param_1,int *param_2,int *param_3)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  double dVar4;
  double local_24;
  
  *param_2 = (int)((float)param_1[0xee5] + (float)param_1[0xee5] + 0.1);
  *param_3 = 0;
  iVar2 = (**(code **)(*param_1 + 300))(param_1,&DAT_00002602);
  param_1[0xeca] = iVar2;
  if ((((iVar2 != 0) && ((*(uint *)(iVar2 + 0x54) & 0x400) != 0)) &&
      (0.0 < *(double *)(iVar2 + 0x20))) &&
     (0.0 < *(double *)(iVar2 + 0x18) || *(double *)(iVar2 + 0x18) == 0.0)) {
    if ((*(uint *)(iVar2 + 0x54) & 0x2000) == 0) {
      dVar4 = 4.0;
      local_24 = dVar4;
    }
    else {
      dVar4 = (double)*(int *)(iVar2 + 0x44);
      local_24 = (double)*(int *)(iVar2 + 0x40);
    }
    lVar3 = (longdouble)FUN_00015302(local_24,dVar4);
    fVar1 = (float)param_1[0xee5];
    lVar3 = (longdouble)FUN_00015302((double)lVar3 * 240.0,*(undefined8 *)(param_1[0xeca] + 0x20));
    *param_2 = (int)(fVar1 * (float)lVar3 + 0.1);
    lVar3 = (longdouble)_fmod(*(undefined8 *)(param_1[0xeca] + 0x18),local_24);
    *param_3 = (int)((double)(float)param_1[0xee5] *
                    (double)lVar3 * 60.0 * *(double *)(param_1 + 0xec7));
    return *(uint *)(param_1[0xeca] + 0x54) >> 1 & 1;
  }
  return 0;
}

