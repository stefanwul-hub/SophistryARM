/* 0002be42 FUN_0002be42 */

undefined4 FUN_0002be42(int *param_1,int param_2,int *param_3,ushort param_4)

{
  bool bVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 local_78 [80];
  undefined1 local_28 [4];
  int local_24;
  int local_1c;
  int local_10;
  
  if (*param_1 != 0x66737266) {
    return 0;
  }
  if ((2 < param_4) || (*(char *)(param_2 + 2) != '\0')) {
    return 1;
  }
  sVar3 = _AEGetDescData(param_1,local_78,0x50);
  if (sVar3 != 0) {
    return 0;
  }
  iVar4 = _LSCopyItemInfoForRef(local_78,3,local_28);
  if (iVar4 != 0) {
    return 0;
  }
  if (param_3 != (int *)0x0) {
    if ((local_1c != 0) && (*param_3 != 0)) {
      bVar1 = false;
      for (iVar4 = 0; iVar5 = _CFArrayGetCount(*param_3), iVar4 < iVar5; iVar4 = iVar4 + 1) {
        uVar6 = _CFArrayGetValueAtIndex(*param_3,iVar4);
        iVar5 = _CFStringCompare(local_1c,uVar6,1);
        if (iVar5 == 0) {
          bVar1 = true;
        }
      }
      if (bVar1) {
LAB_0002bf7d:
        uVar6 = 1;
        goto LAB_0002bf82;
      }
    }
    if (param_3[1] != 0) {
      for (iVar4 = 0; iVar5 = _CFArrayGetCount(param_3[1]), iVar4 < iVar5; iVar4 = iVar4 + 1) {
        uVar6 = _CFArrayGetValueAtIndex(param_3[1],iVar4);
        cVar2 = _CFNumberGetValue(uVar6,3,&local_10);
        if ((cVar2 != '\0') && (local_24 == local_10)) goto LAB_0002bf7d;
      }
    }
  }
  uVar6 = 0;
LAB_0002bf82:
  if (local_1c != 0) {
    _CFRelease(local_1c);
    return uVar6;
  }
  return uVar6;
}

