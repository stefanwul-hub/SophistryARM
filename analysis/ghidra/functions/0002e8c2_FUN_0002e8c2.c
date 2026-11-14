/* 0002e8c2 FUN_0002e8c2 */

undefined4 FUN_0002e8c2(undefined4 param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  void *pvVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char local_400c [16384];
  
  cVar2 = FUN_0002e564(param_1,param_2,local_400c,0x4000);
  if (cVar2 != '\0') {
    uVar6 = 0xffffffff;
    pcVar7 = local_400c;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    uVar6 = ~uVar6 - 1 >> 1;
    *param_4 = uVar6;
    pvVar5 = _malloc(uVar6 + 2);
    *param_3 = (int)pvVar5;
    if (pvVar5 != (void *)0x0) {
      if (0 < (int)*param_4) {
        iVar8 = 0;
        do {
          while( true ) {
            iVar1 = iVar8 * 2;
            cVar2 = local_400c[iVar1];
            if ((byte)(cVar2 - 0x30U) < 10) break;
            if ((byte)(cVar2 + 0xbfU) < 6) {
              cVar2 = cVar2 + -0x37;
              goto LAB_0002e94e;
            }
            bVar3 = 0;
            cVar2 = local_400c[iVar1 + 1];
            bVar4 = 0;
            if ((byte)(cVar2 - 0x30U) < 10) goto LAB_0002e965;
LAB_0002e9be:
            if ((byte)(cVar2 + 0xbfU) < 6) {
              bVar4 = cVar2 - 0x37;
              goto LAB_0002e968;
            }
            *(byte *)(*param_3 + iVar8) = bVar3;
            iVar8 = iVar8 + 1;
            if ((int)*param_4 <= iVar8) {
              return 1;
            }
          }
          cVar2 = cVar2 + -0x30;
LAB_0002e94e:
          bVar3 = cVar2 * '\x10';
          cVar2 = local_400c[iVar1 + 1];
          bVar4 = bVar3;
          if (9 < (byte)(cVar2 - 0x30U)) goto LAB_0002e9be;
LAB_0002e965:
          bVar3 = bVar4;
          bVar4 = cVar2 - 0x30;
LAB_0002e968:
          *(byte *)(*param_3 + iVar8) = bVar3 | bVar4;
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)*param_4);
      }
      return 1;
    }
  }
  return 0;
}

