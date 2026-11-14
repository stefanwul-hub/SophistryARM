/* 00021338 Synth_vslot_182 */

void Synth_vslot_182(int *param_1,undefined4 param_2,char *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 local_3d4 [8];
  FILE *local_3cc;
  char local_140 [256];
  undefined4 local_40 [7];
  uint local_24;
  void *local_20 [4];
  
  local_20[0] = (void *)0x0;
  uVar2 = (**(code **)(*param_1 + 0x2d0))(param_1,param_2,local_20);
  if ((((local_20[0] != (void *)0x0) && (0 < (int)uVar2)) && (param_3 != (char *)0x0)) &&
     (*param_3 != '\0')) {
    _strcpy(local_140,param_3);
    FUN_0000a5d4(local_3d4);
    FUN_00009848(local_3d4,local_140);
    if (local_3cc != (FILE *)0x0) {
      puVar4 = local_40;
      for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      local_24 = 0x4b6e6343;
      _fwrite(&local_24,1,4,local_3cc);
      local_24 = 0;
      _fwrite(&local_24,1,4,local_3cc);
      local_24 = 0x68435046;
      _fwrite(&local_24,1,4,local_3cc);
      local_24 = 0x1000000;
      _fwrite(&local_24,1,4,local_3cc);
      uVar1 = param_1[0x1a];
      local_24 = uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (int)(uVar1 & 0xff0000) >> 8 |
                 uVar1 >> 0x18;
      _fwrite(&local_24,1,4,local_3cc);
      local_24 = 0x1000000;
      _fwrite(&local_24,1,4,local_3cc);
      local_24 = 0x1000000;
      _fwrite(&local_24,1,4,local_3cc);
      (**(code **)(*param_1 + 0x44))(param_1,local_40);
      _fwrite(local_40,1,0x1c,local_3cc);
      local_24 = uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | (int)(uVar2 & 0xff0000) >> 8 |
                 uVar2 >> 0x18;
      _fwrite(&local_24,1,4,local_3cc);
      _fwrite(local_20[0],1,uVar2,local_3cc);
      FUN_000098c4(local_3d4);
      *(undefined1 *)((int)param_1 + 0xcfd9) = 1;
      iVar3 = Envelope_c_vslot_12(param_1 + 0x2d,0,6);
      if ((iVar3 != 0) && (*(char *)((int)param_1 + 0xcfd5) == '\0')) {
        if (*(char *)((int)param_1 + 0xcfdd) == '\0') {
          FUN_00020efe(param_1,param_2,param_3);
          _strcpy((char *)(param_1[0x33f8] * 0x140 + 0x9bd5 + (int)param_1),param_3);
        }
        else {
          FUN_0001a3ce(param_1,param_3);
          Envelope_c_vslot_17(param_1 + 0xf3,0,0x1e,param_3);
        }
      }
      FUN_00095256(param_1,param_1[0xed4],0x3f800000);
      FUN_00095256(param_1,param_1[0xed4],0);
    }
    Disk_c_vslot_0(local_3d4);
    return;
  }
  return;
}

