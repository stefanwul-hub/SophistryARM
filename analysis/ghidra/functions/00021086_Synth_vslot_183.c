/* 00021086 Synth_vslot_183 */

int Synth_vslot_183(int *param_1,int param_2,char *param_3)

{
  FILE *pFVar1;
  char cVar2;
  void *pvVar3;
  size_t sVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  undefined1 local_3e0 [320];
  undefined1 local_2a0 [320];
  char local_160 [320];
  uint local_20 [4];
  
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    return 0;
  }
  _strcpy(local_160,param_3);
  piVar5 = param_1 + 0x30f6;
  FUN_00009996(piVar5,param_3,local_2a0);
  FUN_000098ea(piVar5,param_3,local_3e0);
  FUN_0000979c(piVar5,param_3);
  pFVar1 = (FILE *)param_1[0x30f8];
  if (pFVar1 == (FILE *)0x0) {
    return 0;
  }
  _fseek(pFVar1,0x10,0);
  _fread(local_20,1,4,pFVar1);
  cVar2 = (**(code **)(*param_1 + 0x3c4))(param_1,local_20[0]);
  if (cVar2 != '\0') {
    _fseek(pFVar1,0x38,0);
    _fread(local_20,1,4,pFVar1);
    uVar7 = local_20[0] << 0x18 | (local_20[0] & 0xff00) << 8 | (int)(local_20[0] & 0xff0000) >> 8 |
            local_20[0] >> 0x18;
    pvVar3 = _malloc(uVar7 + 1);
    if ((pvVar3 != (void *)0x0) && (0 < (int)uVar7)) {
      sVar4 = _fread(pvVar3,1,uVar7,pFVar1);
      if (uVar7 == sVar4) {
        iVar6 = (**(code **)(*param_1 + 0x2c8))(param_1,param_2,pvVar3,uVar7);
      }
      else {
        iVar6 = 0;
      }
      _free(pvVar3);
      goto LAB_00021166;
    }
  }
  iVar6 = 0;
LAB_00021166:
  _fclose(pFVar1);
  if (0 < iVar6) {
    *(undefined1 *)((int)param_1 + 0xcfd9) = 1;
    if (*(char *)((int)param_1 + 0xcfd5) == '\0') {
      if (*(char *)((int)param_1 + 0xcfdb) == '\0') {
        FUN_00020efe(param_1,param_2,local_160);
        _strcpy((char *)(param_2 * 0x140 + 0x9bd5 + (int)param_1),local_160);
      }
      else {
        FUN_0001a3ce(param_1,local_160);
        Envelope_c_vslot_17(param_1 + 0xf3,0,0x1e,local_160);
      }
    }
    FUN_00095256(param_1,param_1[0xed4],0x3f800000);
    FUN_00095256(param_1,param_1[0xed4],0);
    return iVar6;
  }
  return iVar6;
}

