/* 00016e9e Synth_vslot_160 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_160(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  char *pcVar6;
  char *pcVar7;
  undefined1 uVar8;
  bool bVar9;
  
  piVar4 = param_1 + 0x33fb;
  (**(code **)(*param_1 + 0x150))(param_1,piVar4);
  piVar5 = param_1 + 0x344b;
  uVar8 = piVar5 == (int *)0x0;
  (**(code **)(*param_1 + 0x14c))(param_1,piVar5);
  iVar1 = (**(code **)(*param_1 + 0x154))(param_1);
  param_1[0x349b] = iVar1;
  param_1[0x33fa] = 0x12;
  iVar1 = 6;
  piVar3 = piVar4;
  pcVar6 = "Cubase";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    uVar8 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while ((bool)uVar8);
  iVar1 = 0;
  if (!(bool)uVar8) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 0;
  }
  iVar1 = 7;
  piVar3 = piVar4;
  pcVar6 = "Cubasis";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 0;
  }
  iVar1 = 6;
  piVar3 = piVar4;
  pcVar6 = "Nuendo";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 0;
  }
  iVar1 = 8;
  piVar3 = piVar4;
  pcVar6 = "ProTools";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 1;
  }
  iVar1 = 4;
  piVar3 = piVar4;
  pcVar6 = "Live";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 5;
  }
  iVar1 = 6;
  piVar3 = piVar4;
  pcVar6 = "Fruity";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 6;
  }
  iVar1 = 5;
  piVar3 = piVar4;
  pcVar6 = "Orion";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 4;
  }
  iVar1 = 5;
  piVar3 = piVar4;
  pcVar6 = "Logic";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 2;
    *(undefined1 *)((int)param_1 + 0xcfc6) = 0;
  }
  iVar1 = 0xc;
  piVar3 = piVar4;
  pcVar6 = "Making Waves";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 8;
  }
  iVar1 = 0x10;
  piVar3 = piVar4;
  pcVar6 = "MultitrackStudio";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 9;
  }
  iVar1 = 0x10;
  piVar3 = piVar4;
  pcVar6 = "SingerSongWriter";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 10;
  }
  iVar1 = 8;
  piVar3 = piVar4;
  pcVar6 = "Cakewalk";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 0xb;
  }
  iVar1 = 10;
  piVar3 = piVar4;
  pcVar6 = "Samplitude";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 0xc;
  }
  iVar1 = 9;
  piVar3 = piVar4;
  pcVar6 = "Tracktion";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 0xd;
  }
  iVar1 = 10;
  piVar3 = piVar4;
  pcVar6 = "GarageBand";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 0xe;
  }
  iVar1 = 8;
  piVar3 = piVar4;
  pcVar6 = "Receptor";
  do {
    piVar2 = piVar3;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar2 = (int *)((int)piVar3 + 1);
    bVar9 = (char)*piVar3 == *pcVar6;
    piVar3 = piVar2;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar2 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 0xf;
  }
  iVar1 = 0xd;
  pcVar6 = "Muse Research";
  do {
    piVar3 = piVar5;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar3 = (int *)((int)piVar5 + 1);
    bVar9 = (char)*piVar5 == *pcVar6;
    piVar5 = piVar3;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar3 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 0xf;
  }
  iVar1 = 7;
  piVar5 = piVar4;
  pcVar6 = "Chainer";
  do {
    piVar3 = piVar5;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar3 = (int *)((int)piVar5 + 1);
    bVar9 = (char)*piVar5 == *pcVar6;
    piVar5 = piVar3;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar3 + -1) - (uint)(byte)pcVar7[-1];
  }
  bVar9 = iVar1 == 0;
  if (bVar9) {
    param_1[0x33fa] = 0x10;
  }
  iVar1 = 0x12;
  pcVar6 = "FX Teleport Server";
  do {
    piVar5 = piVar4;
    pcVar7 = pcVar6;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar7 = pcVar6 + 1;
    piVar5 = (int *)((int)piVar4 + 1);
    bVar9 = (char)*piVar4 == *pcVar6;
    piVar4 = piVar5;
    pcVar6 = pcVar7;
  } while (bVar9);
  iVar1 = 0;
  if (!bVar9) {
    iVar1 = (uint)*(byte *)((int)piVar5 + -1) - (uint)(byte)pcVar7[-1];
  }
  if (iVar1 == 0) {
    param_1[0x33fa] = 0x11;
  }
  return;
}

