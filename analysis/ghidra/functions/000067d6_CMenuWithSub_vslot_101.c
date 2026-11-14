/* 000067d6 CMenuWithSub_vslot_101 */

bool CMenuWithSub_vslot_101(int *param_1,int param_2,int param_3)

{
  size_t sVar1;
  int iVar2;
  char local_ac [80];
  char local_5c [80];
  
  if (param_2 + 1 != param_3) {
    sVar1 = (**(code **)(*param_1 + 0x18c))(param_1,param_2);
    if (0 < (int)sVar1) {
      _strncpy(local_5c,(char *)(param_2 * param_1[0x41] + param_1[0x40]),sVar1);
      local_5c[sVar1] = '\0';
      _strncpy(local_ac,(char *)((param_2 + 1) * param_1[0x41] + param_1[0x40]),sVar1);
      local_ac[sVar1] = '\0';
      iVar2 = _strncmp(local_5c,local_ac,sVar1);
      return iVar2 == 0;
    }
  }
  return false;
}

