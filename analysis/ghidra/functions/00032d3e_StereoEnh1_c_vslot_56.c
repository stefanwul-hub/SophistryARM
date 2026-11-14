/* 00032d3e StereoEnh1_c_vslot_56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void StereoEnh1_c_vslot_56(int *param_1,int param_2)

{
  int *piVar1;
  float *pfVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  float *local_24;
  float *local_20 [4];
  
  if ((char)param_1[0x57] == '\0') {
    return;
  }
  (**(code **)(*(int *)param_1[0x46] + 0x2c))((int *)param_1[0x46],local_28,local_2c);
  piVar1 = (int *)param_1[4];
  if (*(char *)((int)piVar1 + 0x27) == '\0') {
    (**(code **)(*piVar1 + 0x34))(piVar1,local_20,0);
    local_24 = local_20[0];
  }
  else {
    (**(code **)(*piVar1 + 0x38))(piVar1,local_20,&local_24);
  }
  if (0 < param_2) {
    iVar3 = 0;
    do {
      fVar4 = *local_20[0];
      fVar6 = *local_24;
      pfVar2 = (float *)(param_1[0x78] + (param_1[0x7a] + param_1[0x7d] & param_1[0x7c]) * 4);
      *pfVar2 = *(float *)(param_1[0x78] + param_1[0x7a] * 4) * -0.5 + fVar4 + *pfVar2;
      pfVar2 = (float *)(param_1[0x79] + (param_1[0x7a] + param_1[0x7d] & param_1[0x7c]) * 4);
      *pfVar2 = *(float *)(param_1[0x79] + param_1[0x7a] * 4) * 0.5 + fVar6 + *pfVar2;
      pfVar2 = (float *)(param_1[0x7a] * 4 + param_1[0x78]);
      fVar5 = fVar4 * (float)param_1[0x7f] + (float)param_1[0x7e] * *pfVar2;
      fVar6 = fVar6 * (float)param_1[0x7f] -
              (float)param_1[0x7e] * *(float *)(param_1[0x7a] * 4 + param_1[0x79]);
      *pfVar2 = 0.0;
      *(undefined4 *)(param_1[0x79] + param_1[0x7a] * 4) = 0;
      param_1[0x7a] = param_1[0x7a] + 1U & param_1[0x7c];
      fVar4 = (fVar5 + fVar6) * 0.5 * (float)param_1[0x82];
      fVar6 = (fVar5 - fVar6) * 0.5 * (float)param_1[0x81];
      (**(code **)(*param_1 + 0xcc))(param_1,local_28,fVar4 + fVar6);
      (**(code **)(*param_1 + 0xcc))(param_1,local_2c,fVar4 - fVar6);
      local_20[0] = local_20[0] + 1;
      local_24 = local_24 + 1;
      iVar3 = iVar3 + 1;
    } while (param_2 != iVar3);
  }
  (**(code **)(*(int *)param_1[0x46] + 0x44))((int *)param_1[0x46]);
  return;
}

