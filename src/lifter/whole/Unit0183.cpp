// Generated static p-code lift; original i386 SHA-256: 17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12
#include "LifterRuntime.h"
int sl_unit_0183(SlCpu& c){
goto dispatch;
dispatch:
if(c.fault||c.pc==c.stop)return int(c.fault);
switch(c.pc){
case 0x64bcf:goto L_64bcf;
case 0x64bd2:goto L_64bd2;
case 0x64bd8:goto L_64bd8;
case 0x64bde:goto L_64bde;
case 0x64be1:goto L_64be1;
case 0x64be7:goto L_64be7;
case 0x64bee:goto L_64bee;
case 0x64bf8:goto L_64bf8;
case 0x64c02:goto L_64c02;
case 0x64c0a:goto L_64c0a;
case 0x64c10:goto L_64c10;
case 0x64c14:goto L_64c14;
case 0x64c1a:goto L_64c1a;
case 0x64c1e:goto L_64c1e;
case 0x64c24:goto L_64c24;
case 0x64c27:goto L_64c27;
case 0x64c2c:goto L_64c2c;
case 0x64c32:goto L_64c32;
case 0x64c35:goto L_64c35;
case 0x64c3b:goto L_64c3b;
case 0x64c41:goto L_64c41;
case 0x64c44:goto L_64c44;
case 0x64c4a:goto L_64c4a;
case 0x64c51:goto L_64c51;
case 0x64c5b:goto L_64c5b;
case 0x64c65:goto L_64c65;
case 0x64c6d:goto L_64c6d;
case 0x64c73:goto L_64c73;
case 0x64c77:goto L_64c77;
case 0x64c7d:goto L_64c7d;
case 0x64c81:goto L_64c81;
case 0x64c87:goto L_64c87;
case 0x64c8a:goto L_64c8a;
case 0x64c8f:goto L_64c8f;
case 0x64c95:goto L_64c95;
case 0x64c98:goto L_64c98;
case 0x64c9e:goto L_64c9e;
case 0x64ca4:goto L_64ca4;
case 0x64ca7:goto L_64ca7;
case 0x64cad:goto L_64cad;
case 0x64cb4:goto L_64cb4;
case 0x64cbe:goto L_64cbe;
case 0x64cc8:goto L_64cc8;
case 0x64cd0:goto L_64cd0;
case 0x64cd6:goto L_64cd6;
case 0x64cda:goto L_64cda;
case 0x64ce0:goto L_64ce0;
case 0x64ce4:goto L_64ce4;
case 0x64cea:goto L_64cea;
case 0x64ced:goto L_64ced;
case 0x64cf2:goto L_64cf2;
case 0x64cf8:goto L_64cf8;
case 0x64cfb:goto L_64cfb;
case 0x64d01:goto L_64d01;
case 0x64d07:goto L_64d07;
case 0x64d0a:goto L_64d0a;
case 0x64d10:goto L_64d10;
case 0x64d17:goto L_64d17;
case 0x64d21:goto L_64d21;
case 0x64d2b:goto L_64d2b;
case 0x64d33:goto L_64d33;
case 0x64d39:goto L_64d39;
case 0x64d3d:goto L_64d3d;
case 0x64d43:goto L_64d43;
case 0x64d47:goto L_64d47;
case 0x64d4d:goto L_64d4d;
case 0x64d50:goto L_64d50;
case 0x64d55:goto L_64d55;
case 0x64d5b:goto L_64d5b;
case 0x64d5e:goto L_64d5e;
case 0x64d64:goto L_64d64;
case 0x64d6a:goto L_64d6a;
case 0x64d6d:goto L_64d6d;
case 0x64d73:goto L_64d73;
case 0x64d7a:goto L_64d7a;
case 0x64d84:goto L_64d84;
case 0x64d8e:goto L_64d8e;
case 0x64d96:goto L_64d96;
case 0x64d9c:goto L_64d9c;
case 0x64da0:goto L_64da0;
case 0x64da6:goto L_64da6;
case 0x64daa:goto L_64daa;
case 0x64db0:goto L_64db0;
case 0x64db3:goto L_64db3;
case 0x64db8:goto L_64db8;
case 0x64dbe:goto L_64dbe;
case 0x64dc1:goto L_64dc1;
case 0x64dc7:goto L_64dc7;
case 0x64dcd:goto L_64dcd;
case 0x64dd0:goto L_64dd0;
case 0x64dd6:goto L_64dd6;
case 0x64ddd:goto L_64ddd;
case 0x64de7:goto L_64de7;
case 0x64df1:goto L_64df1;
case 0x64df9:goto L_64df9;
case 0x64dff:goto L_64dff;
case 0x64e03:goto L_64e03;
case 0x64e09:goto L_64e09;
case 0x64e0d:goto L_64e0d;
case 0x64e13:goto L_64e13;
case 0x64e16:goto L_64e16;
case 0x64e1b:goto L_64e1b;
case 0x64e21:goto L_64e21;
case 0x64e24:goto L_64e24;
case 0x64e2a:goto L_64e2a;
case 0x64e30:goto L_64e30;
case 0x64e33:goto L_64e33;
case 0x64e39:goto L_64e39;
case 0x64e40:goto L_64e40;
case 0x64e4a:goto L_64e4a;
case 0x64e54:goto L_64e54;
case 0x64e5c:goto L_64e5c;
case 0x64e62:goto L_64e62;
case 0x64e66:goto L_64e66;
case 0x64e6c:goto L_64e6c;
case 0x64e70:goto L_64e70;
case 0x64e76:goto L_64e76;
case 0x64e79:goto L_64e79;
case 0x64e7e:goto L_64e7e;
case 0x64e84:goto L_64e84;
case 0x64e87:goto L_64e87;
case 0x64e8d:goto L_64e8d;
case 0x64e93:goto L_64e93;
case 0x64e96:goto L_64e96;
case 0x64e9c:goto L_64e9c;
case 0x64ea3:goto L_64ea3;
case 0x64ead:goto L_64ead;
case 0x64eb7:goto L_64eb7;
case 0x64ebf:goto L_64ebf;
case 0x64ec5:goto L_64ec5;
case 0x64ec9:goto L_64ec9;
case 0x64ecf:goto L_64ecf;
case 0x64ed3:goto L_64ed3;
case 0x64ed9:goto L_64ed9;
case 0x64edc:goto L_64edc;
case 0x64ee1:goto L_64ee1;
case 0x64ee7:goto L_64ee7;
case 0x64eea:goto L_64eea;
case 0x64ef0:goto L_64ef0;
case 0x64ef6:goto L_64ef6;
case 0x64ef9:goto L_64ef9;
case 0x64eff:goto L_64eff;
case 0x64f06:goto L_64f06;
case 0x64f10:goto L_64f10;
case 0x64f1a:goto L_64f1a;
case 0x64f22:goto L_64f22;
case 0x64f28:goto L_64f28;
case 0x64f2c:goto L_64f2c;
case 0x64f32:goto L_64f32;
case 0x64f36:goto L_64f36;
case 0x64f3c:goto L_64f3c;
case 0x64f3f:goto L_64f3f;
case 0x64f44:goto L_64f44;
case 0x64f4a:goto L_64f4a;
case 0x64f4d:goto L_64f4d;
case 0x64f53:goto L_64f53;
case 0x64f59:goto L_64f59;
case 0x64f5c:goto L_64f5c;
case 0x64f62:goto L_64f62;
case 0x64f69:goto L_64f69;
case 0x64f73:goto L_64f73;
case 0x64f7d:goto L_64f7d;
case 0x64f85:goto L_64f85;
case 0x64f8b:goto L_64f8b;
case 0x64f8f:goto L_64f8f;
case 0x64f95:goto L_64f95;
case 0x64f99:goto L_64f99;
case 0x64f9f:goto L_64f9f;
case 0x64fa2:goto L_64fa2;
case 0x64fa7:goto L_64fa7;
case 0x64fad:goto L_64fad;
case 0x64fb0:goto L_64fb0;
case 0x64fb6:goto L_64fb6;
case 0x64fbc:goto L_64fbc;
case 0x64fbf:goto L_64fbf;
case 0x64fc5:goto L_64fc5;
case 0x64fcc:goto L_64fcc;
case 0x64fd6:goto L_64fd6;
case 0x64fe0:goto L_64fe0;
case 0x64fe8:goto L_64fe8;
case 0x64fee:goto L_64fee;
case 0x64ff2:goto L_64ff2;
case 0x64ff8:goto L_64ff8;
case 0x64ffc:goto L_64ffc;
case 0x65002:goto L_65002;
case 0x65005:goto L_65005;
case 0x6500a:goto L_6500a;
case 0x65010:goto L_65010;
case 0x65013:goto L_65013;
case 0x65019:goto L_65019;
case 0x6501f:goto L_6501f;
case 0x65022:goto L_65022;
case 0x65028:goto L_65028;
case 0x6502f:goto L_6502f;
case 0x65039:goto L_65039;
case 0x65043:goto L_65043;
case 0x6504b:goto L_6504b;
case 0x65051:goto L_65051;
case 0x65055:goto L_65055;
case 0x6505b:goto L_6505b;
case 0x6505f:goto L_6505f;
case 0x65065:goto L_65065;
case 0x65068:goto L_65068;
case 0x6506d:goto L_6506d;
case 0x65073:goto L_65073;
case 0x65076:goto L_65076;
case 0x6507c:goto L_6507c;
case 0x65082:goto L_65082;
case 0x65085:goto L_65085;
case 0x6508b:goto L_6508b;
case 0x65092:goto L_65092;
case 0x6509c:goto L_6509c;
case 0x650a6:goto L_650a6;
case 0x650ae:goto L_650ae;
case 0x650b4:goto L_650b4;
case 0x650b8:goto L_650b8;
case 0x650be:goto L_650be;
case 0x650c2:goto L_650c2;
case 0x650c8:goto L_650c8;
case 0x650cb:goto L_650cb;
case 0x650d0:goto L_650d0;
case 0x650d6:goto L_650d6;
case 0x650d9:goto L_650d9;
case 0x650df:goto L_650df;
case 0x650e5:goto L_650e5;
case 0x650e8:goto L_650e8;
case 0x650ee:goto L_650ee;
case 0x650f5:goto L_650f5;
case 0x650ff:goto L_650ff;
case 0x65109:goto L_65109;
case 0x65111:goto L_65111;
case 0x65117:goto L_65117;
case 0x6511b:goto L_6511b;
case 0x65121:goto L_65121;
case 0x65125:goto L_65125;
case 0x6512b:goto L_6512b;
case 0x6512e:goto L_6512e;
case 0x65133:goto L_65133;
case 0x65139:goto L_65139;
case 0x6513c:goto L_6513c;
case 0x65142:goto L_65142;
case 0x65148:goto L_65148;
case 0x6514b:goto L_6514b;
case 0x65151:goto L_65151;
case 0x65158:goto L_65158;
case 0x65162:goto L_65162;
case 0x6516c:goto L_6516c;
case 0x65174:goto L_65174;
case 0x6517a:goto L_6517a;
case 0x6517e:goto L_6517e;
case 0x65184:goto L_65184;
case 0x65188:goto L_65188;
case 0x6518e:goto L_6518e;
case 0x65191:goto L_65191;
case 0x65196:goto L_65196;
case 0x6519c:goto L_6519c;
case 0x6519f:goto L_6519f;
case 0x651a5:goto L_651a5;
case 0x651ab:goto L_651ab;
case 0x651ae:goto L_651ae;
case 0x651b4:goto L_651b4;
case 0x651bb:goto L_651bb;
case 0x651c5:goto L_651c5;
case 0x651cf:goto L_651cf;
case 0x651d7:goto L_651d7;
case 0x651dd:goto L_651dd;
case 0x651e1:goto L_651e1;
case 0x651e7:goto L_651e7;
case 0x651eb:goto L_651eb;
case 0x651f1:goto L_651f1;
case 0x651f4:goto L_651f4;
case 0x651f9:goto L_651f9;
case 0x651ff:goto L_651ff;
case 0x65202:goto L_65202;
case 0x65208:goto L_65208;
case 0x6520e:goto L_6520e;
case 0x65211:goto L_65211;
case 0x65217:goto L_65217;
case 0x6521e:goto L_6521e;
case 0x65228:goto L_65228;
case 0x65232:goto L_65232;
case 0x6523a:goto L_6523a;
case 0x65240:goto L_65240;
case 0x65244:goto L_65244;
case 0x6524a:goto L_6524a;
case 0x6524e:goto L_6524e;
case 0x65254:goto L_65254;
case 0x65257:goto L_65257;
case 0x6525c:goto L_6525c;
case 0x65262:goto L_65262;
case 0x65265:goto L_65265;
case 0x6526b:goto L_6526b;
case 0x65271:goto L_65271;
case 0x65274:goto L_65274;
case 0x6527a:goto L_6527a;
case 0x65281:goto L_65281;
case 0x6528b:goto L_6528b;
case 0x65295:goto L_65295;
case 0x6529d:goto L_6529d;
case 0x652a3:goto L_652a3;
case 0x652a7:goto L_652a7;
case 0x652ad:goto L_652ad;
case 0x652b1:goto L_652b1;
case 0x652b7:goto L_652b7;
case 0x652ba:goto L_652ba;
case 0x652bf:goto L_652bf;
case 0x652c5:goto L_652c5;
case 0x652c8:goto L_652c8;
case 0x652ce:goto L_652ce;
case 0x652d4:goto L_652d4;
case 0x652d7:goto L_652d7;
case 0x652dd:goto L_652dd;
case 0x652e4:goto L_652e4;
case 0x652ee:goto L_652ee;
case 0x652f8:goto L_652f8;
case 0x65300:goto L_65300;
case 0x65306:goto L_65306;
case 0x6530a:goto L_6530a;
case 0x65310:goto L_65310;
case 0x65314:goto L_65314;
case 0x6531a:goto L_6531a;
case 0x6531d:goto L_6531d;
case 0x65322:goto L_65322;
case 0x65328:goto L_65328;
case 0x6532b:goto L_6532b;
case 0x65331:goto L_65331;
case 0x65337:goto L_65337;
case 0x6533a:goto L_6533a;
case 0x65340:goto L_65340;
case 0x65347:goto L_65347;
case 0x65351:goto L_65351;
case 0x6535b:goto L_6535b;
case 0x65363:goto L_65363;
case 0x65369:goto L_65369;
case 0x6536d:goto L_6536d;
case 0x65373:goto L_65373;
case 0x65377:goto L_65377;
case 0x6537d:goto L_6537d;
case 0x65380:goto L_65380;
case 0x65385:goto L_65385;
case 0x6538b:goto L_6538b;
case 0x6538e:goto L_6538e;
case 0x65394:goto L_65394;
case 0x6539a:goto L_6539a;
case 0x6539d:goto L_6539d;
case 0x653a3:goto L_653a3;
case 0x653aa:goto L_653aa;
case 0x653b4:goto L_653b4;
case 0x653be:goto L_653be;
case 0x653c6:goto L_653c6;
case 0x653cc:goto L_653cc;
case 0x653d0:goto L_653d0;
case 0x653d6:goto L_653d6;
case 0x653da:goto L_653da;
case 0x653e0:goto L_653e0;
case 0x653e3:goto L_653e3;
case 0x653e8:goto L_653e8;
case 0x653ee:goto L_653ee;
case 0x653f1:goto L_653f1;
case 0x653f7:goto L_653f7;
case 0x653fd:goto L_653fd;
case 0x65400:goto L_65400;
case 0x65406:goto L_65406;
case 0x6540d:goto L_6540d;
case 0x65417:goto L_65417;
case 0x65421:goto L_65421;
case 0x65429:goto L_65429;
case 0x6542f:goto L_6542f;
case 0x65433:goto L_65433;
case 0x65439:goto L_65439;
case 0x6543d:goto L_6543d;
case 0x65443:goto L_65443;
case 0x65446:goto L_65446;
case 0x6544b:goto L_6544b;
case 0x65451:goto L_65451;
case 0x65454:goto L_65454;
case 0x6545a:goto L_6545a;
case 0x65460:goto L_65460;
case 0x65463:goto L_65463;
case 0x65469:goto L_65469;
case 0x65470:goto L_65470;
case 0x6547a:goto L_6547a;
case 0x65484:goto L_65484;
case 0x6548c:goto L_6548c;
case 0x65492:goto L_65492;
case 0x65496:goto L_65496;
case 0x6549c:goto L_6549c;
case 0x654a0:goto L_654a0;
case 0x654a6:goto L_654a6;
case 0x654a9:goto L_654a9;
case 0x654ae:goto L_654ae;
case 0x654b4:goto L_654b4;
case 0x654b7:goto L_654b7;
case 0x654bd:goto L_654bd;
case 0x654c3:goto L_654c3;
case 0x654c6:goto L_654c6;
case 0x654cc:goto L_654cc;
case 0x654d3:goto L_654d3;
case 0x654dd:goto L_654dd;
case 0x654e7:goto L_654e7;
case 0x654ef:goto L_654ef;
case 0x654f5:goto L_654f5;
case 0x654f9:goto L_654f9;
case 0x654ff:goto L_654ff;
case 0x65503:goto L_65503;
case 0x65509:goto L_65509;
case 0x6550c:goto L_6550c;
case 0x65511:goto L_65511;
case 0x65517:goto L_65517;
case 0x6551a:goto L_6551a;
case 0x65520:goto L_65520;
case 0x65526:goto L_65526;
case 0x65529:goto L_65529;
case 0x6552f:goto L_6552f;
case 0x65536:goto L_65536;
case 0x65540:goto L_65540;
case 0x6554a:goto L_6554a;
case 0x65552:goto L_65552;
case 0x65558:goto L_65558;
case 0x6555c:goto L_6555c;
case 0x65562:goto L_65562;
case 0x65566:goto L_65566;
case 0x6556c:goto L_6556c;
case 0x6556f:goto L_6556f;
case 0x65574:goto L_65574;
case 0x6557a:goto L_6557a;
case 0x6557d:goto L_6557d;
case 0x65583:goto L_65583;
case 0x65589:goto L_65589;
case 0x6558c:goto L_6558c;
case 0x65592:goto L_65592;
case 0x65599:goto L_65599;
case 0x655a0:goto L_655a0;
case 0x655a7:goto L_655a7;
case 0x655af:goto L_655af;
case 0x655b5:goto L_655b5;
case 0x655b9:goto L_655b9;
case 0x655bf:goto L_655bf;
case 0x655c3:goto L_655c3;
case 0x655c9:goto L_655c9;
case 0x655cc:goto L_655cc;
case 0x655d1:goto L_655d1;
case 0x655d7:goto L_655d7;
case 0x655da:goto L_655da;
case 0x655e0:goto L_655e0;
case 0x655e6:goto L_655e6;
case 0x655e9:goto L_655e9;
case 0x655ec:goto L_655ec;
case 0x655f0:goto L_655f0;
case 0x655f7:goto L_655f7;
case 0x655fe:goto L_655fe;
case 0x65606:goto L_65606;
case 0x65609:goto L_65609;
case 0x6560d:goto L_6560d;
case 0x65613:goto L_65613;
case 0x65617:goto L_65617;
case 0x6561d:goto L_6561d;
case 0x65620:goto L_65620;
case 0x65625:goto L_65625;
case 0x6562b:goto L_6562b;
case 0x6562e:goto L_6562e;
case 0x65631:goto L_65631;
case 0x65637:goto L_65637;
case 0x6563a:goto L_6563a;
case 0x6563d:goto L_6563d;
case 0x65641:goto L_65641;
case 0x65648:goto L_65648;
case 0x6564f:goto L_6564f;
case 0x65657:goto L_65657;
case 0x6565a:goto L_6565a;
case 0x6565e:goto L_6565e;
case 0x65664:goto L_65664;
case 0x65668:goto L_65668;
case 0x6566e:goto L_6566e;
case 0x65671:goto L_65671;
case 0x65676:goto L_65676;
case 0x6567c:goto L_6567c;
case 0x6567f:goto L_6567f;
case 0x65682:goto L_65682;
case 0x65688:goto L_65688;
case 0x6568b:goto L_6568b;
case 0x6568e:goto L_6568e;
case 0x65692:goto L_65692;
case 0x65699:goto L_65699;
case 0x656a0:goto L_656a0;
case 0x656a8:goto L_656a8;
case 0x656ab:goto L_656ab;
case 0x656af:goto L_656af;
case 0x656b5:goto L_656b5;
case 0x656b9:goto L_656b9;
case 0x656bf:goto L_656bf;
case 0x656c2:goto L_656c2;
case 0x656c7:goto L_656c7;
case 0x656cd:goto L_656cd;
case 0x656d0:goto L_656d0;
case 0x656d3:goto L_656d3;
case 0x656d9:goto L_656d9;
case 0x656dc:goto L_656dc;
case 0x656df:goto L_656df;
case 0x656e3:goto L_656e3;
case 0x656ea:goto L_656ea;
case 0x656f1:goto L_656f1;
case 0x656f9:goto L_656f9;
case 0x656fc:goto L_656fc;
case 0x65700:goto L_65700;
case 0x65706:goto L_65706;
case 0x6570a:goto L_6570a;
case 0x65710:goto L_65710;
case 0x65713:goto L_65713;
case 0x65718:goto L_65718;
case 0x6571e:goto L_6571e;
case 0x65721:goto L_65721;
default:return 0;}
L_64bcf:{ // ADD EAX,0x8
c.pc=0x64bcf;if(!sl_tick(c))return int(c.fault);
P_64bcf_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64bcf_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64bcf_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64bcf_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64bcf_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64bcf_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64bcf_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64bcf_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64bcf_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64bcf_9:;
goto L_64bd2;
}
L_64bd2:{ // MOV dword ptr [EBP + 0xfffffdd8],EAX
c.pc=0x64bd2;if(!sl_tick(c))return int(c.fault);
P_64bd2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffdd8ULL)),c);
P_64bd2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64bd2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64bd2_3:;
goto L_64bd8;
}
L_64bd8:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64bd8;if(!sl_tick(c))return int(c.fault);
P_64bd8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64bd8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64bd8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64bd8_3:;
goto L_64bde;
}
L_64bde:{ // ADD EAX,0x8
c.pc=0x64bde;if(!sl_tick(c))return int(c.fault);
P_64bde_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64bde_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64bde_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64bde_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64bde_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64bde_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64bde_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64bde_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64bde_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64bde_9:;
goto L_64be1;
}
L_64be1:{ // MOV dword ptr [EBP + 0xfffffde8],EAX
c.pc=0x64be1;if(!sl_tick(c))return int(c.fault);
P_64be1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffde8ULL)),c);
P_64be1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64be1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64be1_3:;
goto L_64be7;
}
L_64be7:{ // MOV byte ptr [EBP + 0xfffffdec],0x0
c.pc=0x64be7;if(!sl_tick(c))return int(c.fault);
P_64be7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffdecULL)),c);
P_64be7_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_64be7_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_64be7_3:;
goto L_64bee;
}
L_64bee:{ // MOV dword ptr [EBP + 0xfffffdf0],0x3c
c.pc=0x64bee;if(!sl_tick(c))return int(c.fault);
P_64bee_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffdf0ULL)),c);
P_64bee_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_64bee_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64bee_3:;
goto L_64bf8;
}
L_64bf8:{ // MOV dword ptr [EBP + 0xfffffdf4],0x64
c.pc=0x64bf8;if(!sl_tick(c))return int(c.fault);
P_64bf8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffdf4ULL)),c);
P_64bf8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_64bf8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64bf8_3:;
goto L_64c02;
}
L_64c02:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x64c02;if(!sl_tick(c))return int(c.fault);
P_64c02_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64c02_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_64c02_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64c02_3:;
goto L_64c0a;
}
L_64c0a:{ // LEA EAX,[EBP + 0xfffffde8]
c.pc=0x64c0a;if(!sl_tick(c))return int(c.fault);
P_64c0a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffde8ULL)),c);
P_64c0a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64c0a_2:;
goto L_64c10;
}
L_64c10:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x64c10;if(!sl_tick(c))return int(c.fault);
P_64c10_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64c10_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64c10_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64c10_3:;
goto L_64c14;
}
L_64c14:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x64c14;if(!sl_tick(c))return int(c.fault);
P_64c14_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_64c14_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64c14_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64c14_3:;
goto L_64c1a;
}
L_64c1a:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x64c1a;if(!sl_tick(c))return int(c.fault);
P_64c1a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64c1a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64c1a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64c1a_3:;
goto L_64c1e;
}
L_64c1e:{ // LEA EAX,[EDI + 0xbacc]
c.pc=0x64c1e;if(!sl_tick(c))return int(c.fault);
P_64c1e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xbaccULL)),c);
P_64c1e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64c1e_2:;
goto L_64c24;
}
L_64c24:{ // MOV dword ptr [ESP],EAX
c.pc=0x64c24;if(!sl_tick(c))return int(c.fault);
P_64c24_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64c24_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64c24_2:;
goto L_64c27;
}
L_64c27:{ // CALL 0x00013c66
c.pc=0x64c27;if(!sl_tick(c))return int(c.fault);
P_64c27_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_64c27_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x64c2cULL),c);
P_64c27_2:;
c.pc=0x13c66;goto dispatch;
P_64c27_3:;
goto L_64c2c;
}
L_64c2c:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64c2c;if(!sl_tick(c))return int(c.fault);
P_64c2c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64c2c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64c2c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64c2c_3:;
goto L_64c32;
}
L_64c32:{ // ADD EAX,0x8
c.pc=0x64c32;if(!sl_tick(c))return int(c.fault);
P_64c32_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64c32_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64c32_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64c32_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64c32_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64c32_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64c32_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64c32_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64c32_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64c32_9:;
goto L_64c35;
}
L_64c35:{ // MOV dword ptr [EBP + 0xfffffde8],EAX
c.pc=0x64c35;if(!sl_tick(c))return int(c.fault);
P_64c35_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffde8ULL)),c);
P_64c35_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64c35_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64c35_3:;
goto L_64c3b;
}
L_64c3b:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64c3b;if(!sl_tick(c))return int(c.fault);
P_64c3b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64c3b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64c3b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64c3b_3:;
goto L_64c41;
}
L_64c41:{ // ADD EAX,0x8
c.pc=0x64c41;if(!sl_tick(c))return int(c.fault);
P_64c41_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64c41_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64c41_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64c41_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64c41_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64c41_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64c41_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64c41_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64c41_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64c41_9:;
goto L_64c44;
}
L_64c44:{ // MOV dword ptr [EBP + 0xfffffdf8],EAX
c.pc=0x64c44;if(!sl_tick(c))return int(c.fault);
P_64c44_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffdf8ULL)),c);
P_64c44_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64c44_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64c44_3:;
goto L_64c4a;
}
L_64c4a:{ // MOV byte ptr [EBP + 0xfffffdfc],0x0
c.pc=0x64c4a;if(!sl_tick(c))return int(c.fault);
P_64c4a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffdfcULL)),c);
P_64c4a_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_64c4a_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_64c4a_3:;
goto L_64c51;
}
L_64c51:{ // MOV dword ptr [EBP + 0xfffffe00],0x3c
c.pc=0x64c51;if(!sl_tick(c))return int(c.fault);
P_64c51_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe00ULL)),c);
P_64c51_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_64c51_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64c51_3:;
goto L_64c5b;
}
L_64c5b:{ // MOV dword ptr [EBP + 0xfffffe04],0x64
c.pc=0x64c5b;if(!sl_tick(c))return int(c.fault);
P_64c5b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe04ULL)),c);
P_64c5b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_64c5b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64c5b_3:;
goto L_64c65;
}
L_64c65:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x64c65;if(!sl_tick(c))return int(c.fault);
P_64c65_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64c65_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_64c65_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64c65_3:;
goto L_64c6d;
}
L_64c6d:{ // LEA EAX,[EBP + 0xfffffdf8]
c.pc=0x64c6d;if(!sl_tick(c))return int(c.fault);
P_64c6d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffdf8ULL)),c);
P_64c6d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64c6d_2:;
goto L_64c73;
}
L_64c73:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x64c73;if(!sl_tick(c))return int(c.fault);
P_64c73_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64c73_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64c73_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64c73_3:;
goto L_64c77;
}
L_64c77:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x64c77;if(!sl_tick(c))return int(c.fault);
P_64c77_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_64c77_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64c77_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64c77_3:;
goto L_64c7d;
}
L_64c7d:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x64c7d;if(!sl_tick(c))return int(c.fault);
P_64c7d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64c7d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64c7d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64c7d_3:;
goto L_64c81;
}
L_64c81:{ // LEA EAX,[EDI + 0x11804]
c.pc=0x64c81;if(!sl_tick(c))return int(c.fault);
P_64c81_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x11804ULL)),c);
P_64c81_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64c81_2:;
goto L_64c87;
}
L_64c87:{ // MOV dword ptr [ESP],EAX
c.pc=0x64c87;if(!sl_tick(c))return int(c.fault);
P_64c87_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64c87_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64c87_2:;
goto L_64c8a;
}
L_64c8a:{ // CALL 0x00013c66
c.pc=0x64c8a;if(!sl_tick(c))return int(c.fault);
P_64c8a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_64c8a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x64c8fULL),c);
P_64c8a_2:;
c.pc=0x13c66;goto dispatch;
P_64c8a_3:;
goto L_64c8f;
}
L_64c8f:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64c8f;if(!sl_tick(c))return int(c.fault);
P_64c8f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64c8f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64c8f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64c8f_3:;
goto L_64c95;
}
L_64c95:{ // ADD EAX,0x8
c.pc=0x64c95;if(!sl_tick(c))return int(c.fault);
P_64c95_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64c95_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64c95_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64c95_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64c95_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64c95_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64c95_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64c95_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64c95_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64c95_9:;
goto L_64c98;
}
L_64c98:{ // MOV dword ptr [EBP + 0xfffffdf8],EAX
c.pc=0x64c98;if(!sl_tick(c))return int(c.fault);
P_64c98_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffdf8ULL)),c);
P_64c98_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64c98_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64c98_3:;
goto L_64c9e;
}
L_64c9e:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64c9e;if(!sl_tick(c))return int(c.fault);
P_64c9e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64c9e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64c9e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64c9e_3:;
goto L_64ca4;
}
L_64ca4:{ // ADD EAX,0x8
c.pc=0x64ca4;if(!sl_tick(c))return int(c.fault);
P_64ca4_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64ca4_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64ca4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64ca4_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64ca4_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64ca4_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64ca4_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64ca4_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64ca4_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64ca4_9:;
goto L_64ca7;
}
L_64ca7:{ // MOV dword ptr [EBP + 0xfffffe08],EAX
c.pc=0x64ca7;if(!sl_tick(c))return int(c.fault);
P_64ca7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe08ULL)),c);
P_64ca7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64ca7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64ca7_3:;
goto L_64cad;
}
L_64cad:{ // MOV byte ptr [EBP + 0xfffffe0c],0x0
c.pc=0x64cad;if(!sl_tick(c))return int(c.fault);
P_64cad_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe0cULL)),c);
P_64cad_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_64cad_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_64cad_3:;
goto L_64cb4;
}
L_64cb4:{ // MOV dword ptr [EBP + 0xfffffe10],0x3c
c.pc=0x64cb4;if(!sl_tick(c))return int(c.fault);
P_64cb4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe10ULL)),c);
P_64cb4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_64cb4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64cb4_3:;
goto L_64cbe;
}
L_64cbe:{ // MOV dword ptr [EBP + 0xfffffe14],0x64
c.pc=0x64cbe;if(!sl_tick(c))return int(c.fault);
P_64cbe_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe14ULL)),c);
P_64cbe_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_64cbe_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64cbe_3:;
goto L_64cc8;
}
L_64cc8:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x64cc8;if(!sl_tick(c))return int(c.fault);
P_64cc8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64cc8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_64cc8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64cc8_3:;
goto L_64cd0;
}
L_64cd0:{ // LEA EAX,[EBP + 0xfffffe08]
c.pc=0x64cd0;if(!sl_tick(c))return int(c.fault);
P_64cd0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe08ULL)),c);
P_64cd0_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64cd0_2:;
goto L_64cd6;
}
L_64cd6:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x64cd6;if(!sl_tick(c))return int(c.fault);
P_64cd6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64cd6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64cd6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64cd6_3:;
goto L_64cda;
}
L_64cda:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x64cda;if(!sl_tick(c))return int(c.fault);
P_64cda_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_64cda_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64cda_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64cda_3:;
goto L_64ce0;
}
L_64ce0:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x64ce0;if(!sl_tick(c))return int(c.fault);
P_64ce0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64ce0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64ce0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64ce0_3:;
goto L_64ce4;
}
L_64ce4:{ // LEA EAX,[EDI + 0x67bc]
c.pc=0x64ce4;if(!sl_tick(c))return int(c.fault);
P_64ce4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x67bcULL)),c);
P_64ce4_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64ce4_2:;
goto L_64cea;
}
L_64cea:{ // MOV dword ptr [ESP],EAX
c.pc=0x64cea;if(!sl_tick(c))return int(c.fault);
P_64cea_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64cea_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64cea_2:;
goto L_64ced;
}
L_64ced:{ // CALL 0x00013c66
c.pc=0x64ced;if(!sl_tick(c))return int(c.fault);
P_64ced_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_64ced_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x64cf2ULL),c);
P_64ced_2:;
c.pc=0x13c66;goto dispatch;
P_64ced_3:;
goto L_64cf2;
}
L_64cf2:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64cf2;if(!sl_tick(c))return int(c.fault);
P_64cf2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64cf2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64cf2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64cf2_3:;
goto L_64cf8;
}
L_64cf8:{ // ADD EAX,0x8
c.pc=0x64cf8;if(!sl_tick(c))return int(c.fault);
P_64cf8_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64cf8_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64cf8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64cf8_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64cf8_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64cf8_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64cf8_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64cf8_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64cf8_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64cf8_9:;
goto L_64cfb;
}
L_64cfb:{ // MOV dword ptr [EBP + 0xfffffe08],EAX
c.pc=0x64cfb;if(!sl_tick(c))return int(c.fault);
P_64cfb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe08ULL)),c);
P_64cfb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64cfb_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64cfb_3:;
goto L_64d01;
}
L_64d01:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64d01;if(!sl_tick(c))return int(c.fault);
P_64d01_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64d01_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64d01_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64d01_3:;
goto L_64d07;
}
L_64d07:{ // ADD EAX,0x8
c.pc=0x64d07;if(!sl_tick(c))return int(c.fault);
P_64d07_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64d07_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64d07_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64d07_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64d07_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64d07_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64d07_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64d07_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64d07_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64d07_9:;
goto L_64d0a;
}
L_64d0a:{ // MOV dword ptr [EBP + 0xfffffe18],EAX
c.pc=0x64d0a;if(!sl_tick(c))return int(c.fault);
P_64d0a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe18ULL)),c);
P_64d0a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64d0a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64d0a_3:;
goto L_64d10;
}
L_64d10:{ // MOV byte ptr [EBP + 0xfffffe1c],0x0
c.pc=0x64d10;if(!sl_tick(c))return int(c.fault);
P_64d10_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe1cULL)),c);
P_64d10_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_64d10_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_64d10_3:;
goto L_64d17;
}
L_64d17:{ // MOV dword ptr [EBP + 0xfffffe20],0x3c
c.pc=0x64d17;if(!sl_tick(c))return int(c.fault);
P_64d17_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe20ULL)),c);
P_64d17_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_64d17_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64d17_3:;
goto L_64d21;
}
L_64d21:{ // MOV dword ptr [EBP + 0xfffffe24],0x64
c.pc=0x64d21;if(!sl_tick(c))return int(c.fault);
P_64d21_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe24ULL)),c);
P_64d21_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_64d21_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64d21_3:;
goto L_64d2b;
}
L_64d2b:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x64d2b;if(!sl_tick(c))return int(c.fault);
P_64d2b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64d2b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_64d2b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64d2b_3:;
goto L_64d33;
}
L_64d33:{ // LEA EAX,[EBP + 0xfffffe18]
c.pc=0x64d33;if(!sl_tick(c))return int(c.fault);
P_64d33_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe18ULL)),c);
P_64d33_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64d33_2:;
goto L_64d39;
}
L_64d39:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x64d39;if(!sl_tick(c))return int(c.fault);
P_64d39_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64d39_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64d39_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64d39_3:;
goto L_64d3d;
}
L_64d3d:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x64d3d;if(!sl_tick(c))return int(c.fault);
P_64d3d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_64d3d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64d3d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64d3d_3:;
goto L_64d43;
}
L_64d43:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x64d43;if(!sl_tick(c))return int(c.fault);
P_64d43_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64d43_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64d43_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64d43_3:;
goto L_64d47;
}
L_64d47:{ // LEA EAX,[EDI + 0xc4f4]
c.pc=0x64d47;if(!sl_tick(c))return int(c.fault);
P_64d47_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xc4f4ULL)),c);
P_64d47_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64d47_2:;
goto L_64d4d;
}
L_64d4d:{ // MOV dword ptr [ESP],EAX
c.pc=0x64d4d;if(!sl_tick(c))return int(c.fault);
P_64d4d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64d4d_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64d4d_2:;
goto L_64d50;
}
L_64d50:{ // CALL 0x00013c66
c.pc=0x64d50;if(!sl_tick(c))return int(c.fault);
P_64d50_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_64d50_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x64d55ULL),c);
P_64d50_2:;
c.pc=0x13c66;goto dispatch;
P_64d50_3:;
goto L_64d55;
}
L_64d55:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64d55;if(!sl_tick(c))return int(c.fault);
P_64d55_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64d55_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64d55_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64d55_3:;
goto L_64d5b;
}
L_64d5b:{ // ADD EAX,0x8
c.pc=0x64d5b;if(!sl_tick(c))return int(c.fault);
P_64d5b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64d5b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64d5b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64d5b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64d5b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64d5b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64d5b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64d5b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64d5b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64d5b_9:;
goto L_64d5e;
}
L_64d5e:{ // MOV dword ptr [EBP + 0xfffffe18],EAX
c.pc=0x64d5e;if(!sl_tick(c))return int(c.fault);
P_64d5e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe18ULL)),c);
P_64d5e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64d5e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64d5e_3:;
goto L_64d64;
}
L_64d64:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64d64;if(!sl_tick(c))return int(c.fault);
P_64d64_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64d64_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64d64_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64d64_3:;
goto L_64d6a;
}
L_64d6a:{ // ADD EAX,0x8
c.pc=0x64d6a;if(!sl_tick(c))return int(c.fault);
P_64d6a_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64d6a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64d6a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64d6a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64d6a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64d6a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64d6a_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64d6a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64d6a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64d6a_9:;
goto L_64d6d;
}
L_64d6d:{ // MOV dword ptr [EBP + 0xfffffe28],EAX
c.pc=0x64d6d;if(!sl_tick(c))return int(c.fault);
P_64d6d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe28ULL)),c);
P_64d6d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64d6d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64d6d_3:;
goto L_64d73;
}
L_64d73:{ // MOV byte ptr [EBP + 0xfffffe2c],0x0
c.pc=0x64d73;if(!sl_tick(c))return int(c.fault);
P_64d73_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe2cULL)),c);
P_64d73_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_64d73_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_64d73_3:;
goto L_64d7a;
}
L_64d7a:{ // MOV dword ptr [EBP + 0xfffffe30],0x3c
c.pc=0x64d7a;if(!sl_tick(c))return int(c.fault);
P_64d7a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe30ULL)),c);
P_64d7a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_64d7a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64d7a_3:;
goto L_64d84;
}
L_64d84:{ // MOV dword ptr [EBP + 0xfffffe34],0x64
c.pc=0x64d84;if(!sl_tick(c))return int(c.fault);
P_64d84_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe34ULL)),c);
P_64d84_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_64d84_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64d84_3:;
goto L_64d8e;
}
L_64d8e:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x64d8e;if(!sl_tick(c))return int(c.fault);
P_64d8e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64d8e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_64d8e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64d8e_3:;
goto L_64d96;
}
L_64d96:{ // LEA EAX,[EBP + 0xfffffe28]
c.pc=0x64d96;if(!sl_tick(c))return int(c.fault);
P_64d96_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe28ULL)),c);
P_64d96_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64d96_2:;
goto L_64d9c;
}
L_64d9c:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x64d9c;if(!sl_tick(c))return int(c.fault);
P_64d9c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64d9c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64d9c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64d9c_3:;
goto L_64da0;
}
L_64da0:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x64da0;if(!sl_tick(c))return int(c.fault);
P_64da0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_64da0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64da0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64da0_3:;
goto L_64da6;
}
L_64da6:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x64da6;if(!sl_tick(c))return int(c.fault);
P_64da6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64da6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64da6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64da6_3:;
goto L_64daa;
}
L_64daa:{ // LEA EAX,[EDI + 0x1222c]
c.pc=0x64daa;if(!sl_tick(c))return int(c.fault);
P_64daa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1222cULL)),c);
P_64daa_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64daa_2:;
goto L_64db0;
}
L_64db0:{ // MOV dword ptr [ESP],EAX
c.pc=0x64db0;if(!sl_tick(c))return int(c.fault);
P_64db0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64db0_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64db0_2:;
goto L_64db3;
}
L_64db3:{ // CALL 0x00013c66
c.pc=0x64db3;if(!sl_tick(c))return int(c.fault);
P_64db3_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_64db3_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x64db8ULL),c);
P_64db3_2:;
c.pc=0x13c66;goto dispatch;
P_64db3_3:;
goto L_64db8;
}
L_64db8:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64db8;if(!sl_tick(c))return int(c.fault);
P_64db8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64db8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64db8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64db8_3:;
goto L_64dbe;
}
L_64dbe:{ // ADD EAX,0x8
c.pc=0x64dbe;if(!sl_tick(c))return int(c.fault);
P_64dbe_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64dbe_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64dbe_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64dbe_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64dbe_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64dbe_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64dbe_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64dbe_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64dbe_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64dbe_9:;
goto L_64dc1;
}
L_64dc1:{ // MOV dword ptr [EBP + 0xfffffe28],EAX
c.pc=0x64dc1;if(!sl_tick(c))return int(c.fault);
P_64dc1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe28ULL)),c);
P_64dc1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64dc1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64dc1_3:;
goto L_64dc7;
}
L_64dc7:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64dc7;if(!sl_tick(c))return int(c.fault);
P_64dc7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64dc7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64dc7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64dc7_3:;
goto L_64dcd;
}
L_64dcd:{ // ADD EAX,0x8
c.pc=0x64dcd;if(!sl_tick(c))return int(c.fault);
P_64dcd_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64dcd_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64dcd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64dcd_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64dcd_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64dcd_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64dcd_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64dcd_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64dcd_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64dcd_9:;
goto L_64dd0;
}
L_64dd0:{ // MOV dword ptr [EBP + 0xfffffe38],EAX
c.pc=0x64dd0;if(!sl_tick(c))return int(c.fault);
P_64dd0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe38ULL)),c);
P_64dd0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64dd0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64dd0_3:;
goto L_64dd6;
}
L_64dd6:{ // MOV byte ptr [EBP + 0xfffffe3c],0x0
c.pc=0x64dd6;if(!sl_tick(c))return int(c.fault);
P_64dd6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe3cULL)),c);
P_64dd6_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_64dd6_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_64dd6_3:;
goto L_64ddd;
}
L_64ddd:{ // MOV dword ptr [EBP + 0xfffffe40],0x3c
c.pc=0x64ddd;if(!sl_tick(c))return int(c.fault);
P_64ddd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe40ULL)),c);
P_64ddd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_64ddd_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64ddd_3:;
goto L_64de7;
}
L_64de7:{ // MOV dword ptr [EBP + 0xfffffe44],0x64
c.pc=0x64de7;if(!sl_tick(c))return int(c.fault);
P_64de7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe44ULL)),c);
P_64de7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_64de7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64de7_3:;
goto L_64df1;
}
L_64df1:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x64df1;if(!sl_tick(c))return int(c.fault);
P_64df1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64df1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_64df1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64df1_3:;
goto L_64df9;
}
L_64df9:{ // LEA EAX,[EBP + 0xfffffe38]
c.pc=0x64df9;if(!sl_tick(c))return int(c.fault);
P_64df9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe38ULL)),c);
P_64df9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64df9_2:;
goto L_64dff;
}
L_64dff:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x64dff;if(!sl_tick(c))return int(c.fault);
P_64dff_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64dff_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64dff_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64dff_3:;
goto L_64e03;
}
L_64e03:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x64e03;if(!sl_tick(c))return int(c.fault);
P_64e03_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_64e03_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64e03_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64e03_3:;
goto L_64e09;
}
L_64e09:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x64e09;if(!sl_tick(c))return int(c.fault);
P_64e09_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64e09_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64e09_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64e09_3:;
goto L_64e0d;
}
L_64e0d:{ // LEA EAX,[EDI + 0x71c0]
c.pc=0x64e0d;if(!sl_tick(c))return int(c.fault);
P_64e0d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x71c0ULL)),c);
P_64e0d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64e0d_2:;
goto L_64e13;
}
L_64e13:{ // MOV dword ptr [ESP],EAX
c.pc=0x64e13;if(!sl_tick(c))return int(c.fault);
P_64e13_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64e13_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64e13_2:;
goto L_64e16;
}
L_64e16:{ // CALL 0x00013c66
c.pc=0x64e16;if(!sl_tick(c))return int(c.fault);
P_64e16_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_64e16_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x64e1bULL),c);
P_64e16_2:;
c.pc=0x13c66;goto dispatch;
P_64e16_3:;
goto L_64e1b;
}
L_64e1b:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64e1b;if(!sl_tick(c))return int(c.fault);
P_64e1b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64e1b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64e1b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64e1b_3:;
goto L_64e21;
}
L_64e21:{ // ADD EAX,0x8
c.pc=0x64e21;if(!sl_tick(c))return int(c.fault);
P_64e21_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64e21_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64e21_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64e21_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64e21_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64e21_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64e21_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64e21_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64e21_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64e21_9:;
goto L_64e24;
}
L_64e24:{ // MOV dword ptr [EBP + 0xfffffe38],EAX
c.pc=0x64e24;if(!sl_tick(c))return int(c.fault);
P_64e24_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe38ULL)),c);
P_64e24_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64e24_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64e24_3:;
goto L_64e2a;
}
L_64e2a:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64e2a;if(!sl_tick(c))return int(c.fault);
P_64e2a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64e2a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64e2a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64e2a_3:;
goto L_64e30;
}
L_64e30:{ // ADD EAX,0x8
c.pc=0x64e30;if(!sl_tick(c))return int(c.fault);
P_64e30_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64e30_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64e30_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64e30_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64e30_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64e30_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64e30_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64e30_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64e30_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64e30_9:;
goto L_64e33;
}
L_64e33:{ // MOV dword ptr [EBP + 0xfffffe48],EAX
c.pc=0x64e33;if(!sl_tick(c))return int(c.fault);
P_64e33_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe48ULL)),c);
P_64e33_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64e33_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64e33_3:;
goto L_64e39;
}
L_64e39:{ // MOV byte ptr [EBP + 0xfffffe4c],0x0
c.pc=0x64e39;if(!sl_tick(c))return int(c.fault);
P_64e39_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe4cULL)),c);
P_64e39_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_64e39_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_64e39_3:;
goto L_64e40;
}
L_64e40:{ // MOV dword ptr [EBP + 0xfffffe50],0x3c
c.pc=0x64e40;if(!sl_tick(c))return int(c.fault);
P_64e40_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe50ULL)),c);
P_64e40_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_64e40_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64e40_3:;
goto L_64e4a;
}
L_64e4a:{ // MOV dword ptr [EBP + 0xfffffe54],0x64
c.pc=0x64e4a;if(!sl_tick(c))return int(c.fault);
P_64e4a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe54ULL)),c);
P_64e4a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_64e4a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64e4a_3:;
goto L_64e54;
}
L_64e54:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x64e54;if(!sl_tick(c))return int(c.fault);
P_64e54_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64e54_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_64e54_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64e54_3:;
goto L_64e5c;
}
L_64e5c:{ // LEA EAX,[EBP + 0xfffffe48]
c.pc=0x64e5c;if(!sl_tick(c))return int(c.fault);
P_64e5c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe48ULL)),c);
P_64e5c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64e5c_2:;
goto L_64e62;
}
L_64e62:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x64e62;if(!sl_tick(c))return int(c.fault);
P_64e62_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64e62_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64e62_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64e62_3:;
goto L_64e66;
}
L_64e66:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x64e66;if(!sl_tick(c))return int(c.fault);
P_64e66_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_64e66_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64e66_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64e66_3:;
goto L_64e6c;
}
L_64e6c:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x64e6c;if(!sl_tick(c))return int(c.fault);
P_64e6c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64e6c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64e6c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64e6c_3:;
goto L_64e70;
}
L_64e70:{ // LEA EAX,[EDI + 0xcef8]
c.pc=0x64e70;if(!sl_tick(c))return int(c.fault);
P_64e70_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xcef8ULL)),c);
P_64e70_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64e70_2:;
goto L_64e76;
}
L_64e76:{ // MOV dword ptr [ESP],EAX
c.pc=0x64e76;if(!sl_tick(c))return int(c.fault);
P_64e76_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64e76_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64e76_2:;
goto L_64e79;
}
L_64e79:{ // CALL 0x00013c66
c.pc=0x64e79;if(!sl_tick(c))return int(c.fault);
P_64e79_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_64e79_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x64e7eULL),c);
P_64e79_2:;
c.pc=0x13c66;goto dispatch;
P_64e79_3:;
goto L_64e7e;
}
L_64e7e:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64e7e;if(!sl_tick(c))return int(c.fault);
P_64e7e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64e7e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64e7e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64e7e_3:;
goto L_64e84;
}
L_64e84:{ // ADD EAX,0x8
c.pc=0x64e84;if(!sl_tick(c))return int(c.fault);
P_64e84_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64e84_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64e84_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64e84_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64e84_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64e84_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64e84_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64e84_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64e84_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64e84_9:;
goto L_64e87;
}
L_64e87:{ // MOV dword ptr [EBP + 0xfffffe48],EAX
c.pc=0x64e87;if(!sl_tick(c))return int(c.fault);
P_64e87_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe48ULL)),c);
P_64e87_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64e87_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64e87_3:;
goto L_64e8d;
}
L_64e8d:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64e8d;if(!sl_tick(c))return int(c.fault);
P_64e8d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64e8d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64e8d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64e8d_3:;
goto L_64e93;
}
L_64e93:{ // ADD EAX,0x8
c.pc=0x64e93;if(!sl_tick(c))return int(c.fault);
P_64e93_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64e93_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64e93_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64e93_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64e93_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64e93_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64e93_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64e93_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64e93_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64e93_9:;
goto L_64e96;
}
L_64e96:{ // MOV dword ptr [EBP + 0xfffffe58],EAX
c.pc=0x64e96;if(!sl_tick(c))return int(c.fault);
P_64e96_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe58ULL)),c);
P_64e96_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64e96_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64e96_3:;
goto L_64e9c;
}
L_64e9c:{ // MOV byte ptr [EBP + 0xfffffe5c],0x0
c.pc=0x64e9c;if(!sl_tick(c))return int(c.fault);
P_64e9c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe5cULL)),c);
P_64e9c_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_64e9c_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_64e9c_3:;
goto L_64ea3;
}
L_64ea3:{ // MOV dword ptr [EBP + 0xfffffe60],0x3c
c.pc=0x64ea3;if(!sl_tick(c))return int(c.fault);
P_64ea3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe60ULL)),c);
P_64ea3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_64ea3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64ea3_3:;
goto L_64ead;
}
L_64ead:{ // MOV dword ptr [EBP + 0xfffffe64],0x64
c.pc=0x64ead;if(!sl_tick(c))return int(c.fault);
P_64ead_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe64ULL)),c);
P_64ead_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_64ead_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64ead_3:;
goto L_64eb7;
}
L_64eb7:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x64eb7;if(!sl_tick(c))return int(c.fault);
P_64eb7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64eb7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_64eb7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64eb7_3:;
goto L_64ebf;
}
L_64ebf:{ // LEA EAX,[EBP + 0xfffffe58]
c.pc=0x64ebf;if(!sl_tick(c))return int(c.fault);
P_64ebf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe58ULL)),c);
P_64ebf_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64ebf_2:;
goto L_64ec5;
}
L_64ec5:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x64ec5;if(!sl_tick(c))return int(c.fault);
P_64ec5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64ec5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64ec5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64ec5_3:;
goto L_64ec9;
}
L_64ec9:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x64ec9;if(!sl_tick(c))return int(c.fault);
P_64ec9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_64ec9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64ec9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64ec9_3:;
goto L_64ecf;
}
L_64ecf:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x64ecf;if(!sl_tick(c))return int(c.fault);
P_64ecf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64ecf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64ecf_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64ecf_3:;
goto L_64ed3;
}
L_64ed3:{ // LEA EAX,[EDI + 0x12c30]
c.pc=0x64ed3;if(!sl_tick(c))return int(c.fault);
P_64ed3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x12c30ULL)),c);
P_64ed3_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64ed3_2:;
goto L_64ed9;
}
L_64ed9:{ // MOV dword ptr [ESP],EAX
c.pc=0x64ed9;if(!sl_tick(c))return int(c.fault);
P_64ed9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64ed9_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64ed9_2:;
goto L_64edc;
}
L_64edc:{ // CALL 0x00013c66
c.pc=0x64edc;if(!sl_tick(c))return int(c.fault);
P_64edc_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_64edc_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x64ee1ULL),c);
P_64edc_2:;
c.pc=0x13c66;goto dispatch;
P_64edc_3:;
goto L_64ee1;
}
L_64ee1:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64ee1;if(!sl_tick(c))return int(c.fault);
P_64ee1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64ee1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64ee1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64ee1_3:;
goto L_64ee7;
}
L_64ee7:{ // ADD EAX,0x8
c.pc=0x64ee7;if(!sl_tick(c))return int(c.fault);
P_64ee7_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64ee7_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64ee7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64ee7_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64ee7_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64ee7_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64ee7_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64ee7_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64ee7_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64ee7_9:;
goto L_64eea;
}
L_64eea:{ // MOV dword ptr [EBP + 0xfffffe58],EAX
c.pc=0x64eea;if(!sl_tick(c))return int(c.fault);
P_64eea_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe58ULL)),c);
P_64eea_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64eea_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64eea_3:;
goto L_64ef0;
}
L_64ef0:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64ef0;if(!sl_tick(c))return int(c.fault);
P_64ef0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64ef0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64ef0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64ef0_3:;
goto L_64ef6;
}
L_64ef6:{ // ADD EAX,0x8
c.pc=0x64ef6;if(!sl_tick(c))return int(c.fault);
P_64ef6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64ef6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64ef6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64ef6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64ef6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64ef6_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64ef6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64ef6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64ef6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64ef6_9:;
goto L_64ef9;
}
L_64ef9:{ // MOV dword ptr [EBP + 0xfffffe68],EAX
c.pc=0x64ef9;if(!sl_tick(c))return int(c.fault);
P_64ef9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe68ULL)),c);
P_64ef9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64ef9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64ef9_3:;
goto L_64eff;
}
L_64eff:{ // MOV byte ptr [EBP + 0xfffffe6c],0x0
c.pc=0x64eff;if(!sl_tick(c))return int(c.fault);
P_64eff_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe6cULL)),c);
P_64eff_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_64eff_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_64eff_3:;
goto L_64f06;
}
L_64f06:{ // MOV dword ptr [EBP + 0xfffffe70],0x3c
c.pc=0x64f06;if(!sl_tick(c))return int(c.fault);
P_64f06_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe70ULL)),c);
P_64f06_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_64f06_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64f06_3:;
goto L_64f10;
}
L_64f10:{ // MOV dword ptr [EBP + 0xfffffe74],0x64
c.pc=0x64f10;if(!sl_tick(c))return int(c.fault);
P_64f10_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe74ULL)),c);
P_64f10_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_64f10_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64f10_3:;
goto L_64f1a;
}
L_64f1a:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x64f1a;if(!sl_tick(c))return int(c.fault);
P_64f1a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64f1a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_64f1a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64f1a_3:;
goto L_64f22;
}
L_64f22:{ // LEA EAX,[EBP + 0xfffffe68]
c.pc=0x64f22;if(!sl_tick(c))return int(c.fault);
P_64f22_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe68ULL)),c);
P_64f22_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64f22_2:;
goto L_64f28;
}
L_64f28:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x64f28;if(!sl_tick(c))return int(c.fault);
P_64f28_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64f28_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64f28_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64f28_3:;
goto L_64f2c;
}
L_64f2c:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x64f2c;if(!sl_tick(c))return int(c.fault);
P_64f2c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_64f2c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64f2c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64f2c_3:;
goto L_64f32;
}
L_64f32:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x64f32;if(!sl_tick(c))return int(c.fault);
P_64f32_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64f32_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64f32_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64f32_3:;
goto L_64f36;
}
L_64f36:{ // LEA EAX,[EDI + 0x7a2c]
c.pc=0x64f36;if(!sl_tick(c))return int(c.fault);
P_64f36_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x7a2cULL)),c);
P_64f36_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64f36_2:;
goto L_64f3c;
}
L_64f3c:{ // MOV dword ptr [ESP],EAX
c.pc=0x64f3c;if(!sl_tick(c))return int(c.fault);
P_64f3c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64f3c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64f3c_2:;
goto L_64f3f;
}
L_64f3f:{ // CALL 0x00013c66
c.pc=0x64f3f;if(!sl_tick(c))return int(c.fault);
P_64f3f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_64f3f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x64f44ULL),c);
P_64f3f_2:;
c.pc=0x13c66;goto dispatch;
P_64f3f_3:;
goto L_64f44;
}
L_64f44:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64f44;if(!sl_tick(c))return int(c.fault);
P_64f44_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64f44_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64f44_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64f44_3:;
goto L_64f4a;
}
L_64f4a:{ // ADD EAX,0x8
c.pc=0x64f4a;if(!sl_tick(c))return int(c.fault);
P_64f4a_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64f4a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64f4a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64f4a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64f4a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64f4a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64f4a_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64f4a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64f4a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64f4a_9:;
goto L_64f4d;
}
L_64f4d:{ // MOV dword ptr [EBP + 0xfffffe68],EAX
c.pc=0x64f4d;if(!sl_tick(c))return int(c.fault);
P_64f4d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe68ULL)),c);
P_64f4d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64f4d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64f4d_3:;
goto L_64f53;
}
L_64f53:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64f53;if(!sl_tick(c))return int(c.fault);
P_64f53_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64f53_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64f53_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64f53_3:;
goto L_64f59;
}
L_64f59:{ // ADD EAX,0x8
c.pc=0x64f59;if(!sl_tick(c))return int(c.fault);
P_64f59_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64f59_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64f59_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64f59_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64f59_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64f59_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64f59_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64f59_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64f59_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64f59_9:;
goto L_64f5c;
}
L_64f5c:{ // MOV dword ptr [EBP + 0xfffffe78],EAX
c.pc=0x64f5c;if(!sl_tick(c))return int(c.fault);
P_64f5c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe78ULL)),c);
P_64f5c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64f5c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64f5c_3:;
goto L_64f62;
}
L_64f62:{ // MOV byte ptr [EBP + 0xfffffe7c],0x0
c.pc=0x64f62;if(!sl_tick(c))return int(c.fault);
P_64f62_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe7cULL)),c);
P_64f62_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_64f62_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_64f62_3:;
goto L_64f69;
}
L_64f69:{ // MOV dword ptr [EBP + 0xfffffe80],0x3c
c.pc=0x64f69;if(!sl_tick(c))return int(c.fault);
P_64f69_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe80ULL)),c);
P_64f69_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_64f69_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64f69_3:;
goto L_64f73;
}
L_64f73:{ // MOV dword ptr [EBP + 0xfffffe84],0x64
c.pc=0x64f73;if(!sl_tick(c))return int(c.fault);
P_64f73_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe84ULL)),c);
P_64f73_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_64f73_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64f73_3:;
goto L_64f7d;
}
L_64f7d:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x64f7d;if(!sl_tick(c))return int(c.fault);
P_64f7d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64f7d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_64f7d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64f7d_3:;
goto L_64f85;
}
L_64f85:{ // LEA EAX,[EBP + 0xfffffe78]
c.pc=0x64f85;if(!sl_tick(c))return int(c.fault);
P_64f85_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe78ULL)),c);
P_64f85_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64f85_2:;
goto L_64f8b;
}
L_64f8b:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x64f8b;if(!sl_tick(c))return int(c.fault);
P_64f8b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64f8b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64f8b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64f8b_3:;
goto L_64f8f;
}
L_64f8f:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x64f8f;if(!sl_tick(c))return int(c.fault);
P_64f8f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_64f8f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64f8f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64f8f_3:;
goto L_64f95;
}
L_64f95:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x64f95;if(!sl_tick(c))return int(c.fault);
P_64f95_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64f95_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64f95_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64f95_3:;
goto L_64f99;
}
L_64f99:{ // LEA EAX,[EDI + 0xd764]
c.pc=0x64f99;if(!sl_tick(c))return int(c.fault);
P_64f99_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xd764ULL)),c);
P_64f99_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64f99_2:;
goto L_64f9f;
}
L_64f9f:{ // MOV dword ptr [ESP],EAX
c.pc=0x64f9f;if(!sl_tick(c))return int(c.fault);
P_64f9f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64f9f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64f9f_2:;
goto L_64fa2;
}
L_64fa2:{ // CALL 0x00013c66
c.pc=0x64fa2;if(!sl_tick(c))return int(c.fault);
P_64fa2_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_64fa2_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x64fa7ULL),c);
P_64fa2_2:;
c.pc=0x13c66;goto dispatch;
P_64fa2_3:;
goto L_64fa7;
}
L_64fa7:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64fa7;if(!sl_tick(c))return int(c.fault);
P_64fa7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64fa7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64fa7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64fa7_3:;
goto L_64fad;
}
L_64fad:{ // ADD EAX,0x8
c.pc=0x64fad;if(!sl_tick(c))return int(c.fault);
P_64fad_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64fad_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64fad_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64fad_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64fad_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64fad_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64fad_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64fad_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64fad_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64fad_9:;
goto L_64fb0;
}
L_64fb0:{ // MOV dword ptr [EBP + 0xfffffe78],EAX
c.pc=0x64fb0;if(!sl_tick(c))return int(c.fault);
P_64fb0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe78ULL)),c);
P_64fb0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64fb0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64fb0_3:;
goto L_64fb6;
}
L_64fb6:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x64fb6;if(!sl_tick(c))return int(c.fault);
P_64fb6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_64fb6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64fb6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64fb6_3:;
goto L_64fbc;
}
L_64fbc:{ // ADD EAX,0x8
c.pc=0x64fbc;if(!sl_tick(c))return int(c.fault);
P_64fbc_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_64fbc_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_64fbc_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_64fbc_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_64fbc_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_64fbc_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_64fbc_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_64fbc_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_64fbc_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_64fbc_9:;
goto L_64fbf;
}
L_64fbf:{ // MOV dword ptr [EBP + 0xfffffe88],EAX
c.pc=0x64fbf;if(!sl_tick(c))return int(c.fault);
P_64fbf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe88ULL)),c);
P_64fbf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64fbf_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64fbf_3:;
goto L_64fc5;
}
L_64fc5:{ // MOV byte ptr [EBP + 0xfffffe8c],0x0
c.pc=0x64fc5;if(!sl_tick(c))return int(c.fault);
P_64fc5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe8cULL)),c);
P_64fc5_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_64fc5_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_64fc5_3:;
goto L_64fcc;
}
L_64fcc:{ // MOV dword ptr [EBP + 0xfffffe90],0x3c
c.pc=0x64fcc;if(!sl_tick(c))return int(c.fault);
P_64fcc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe90ULL)),c);
P_64fcc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_64fcc_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64fcc_3:;
goto L_64fd6;
}
L_64fd6:{ // MOV dword ptr [EBP + 0xfffffe94],0x64
c.pc=0x64fd6;if(!sl_tick(c))return int(c.fault);
P_64fd6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe94ULL)),c);
P_64fd6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_64fd6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64fd6_3:;
goto L_64fe0;
}
L_64fe0:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x64fe0;if(!sl_tick(c))return int(c.fault);
P_64fe0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64fe0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_64fe0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_64fe0_3:;
goto L_64fe8;
}
L_64fe8:{ // LEA EAX,[EBP + 0xfffffe88]
c.pc=0x64fe8;if(!sl_tick(c))return int(c.fault);
P_64fe8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe88ULL)),c);
P_64fe8_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64fe8_2:;
goto L_64fee;
}
L_64fee:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x64fee;if(!sl_tick(c))return int(c.fault);
P_64fee_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64fee_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64fee_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64fee_3:;
goto L_64ff2;
}
L_64ff2:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x64ff2;if(!sl_tick(c))return int(c.fault);
P_64ff2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_64ff2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_64ff2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_64ff2_3:;
goto L_64ff8;
}
L_64ff8:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x64ff8;if(!sl_tick(c))return int(c.fault);
P_64ff8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_64ff8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_64ff8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_64ff8_3:;
goto L_64ffc;
}
L_64ffc:{ // LEA EAX,[EDI + 0x1349c]
c.pc=0x64ffc;if(!sl_tick(c))return int(c.fault);
P_64ffc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1349cULL)),c);
P_64ffc_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_64ffc_2:;
goto L_65002;
}
L_65002:{ // MOV dword ptr [ESP],EAX
c.pc=0x65002;if(!sl_tick(c))return int(c.fault);
P_65002_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65002_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65002_2:;
goto L_65005;
}
L_65005:{ // CALL 0x00013c66
c.pc=0x65005;if(!sl_tick(c))return int(c.fault);
P_65005_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_65005_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x6500aULL),c);
P_65005_2:;
c.pc=0x13c66;goto dispatch;
P_65005_3:;
goto L_6500a;
}
L_6500a:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x6500a;if(!sl_tick(c))return int(c.fault);
P_6500a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_6500a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_6500a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_6500a_3:;
goto L_65010;
}
L_65010:{ // ADD EAX,0x8
c.pc=0x65010;if(!sl_tick(c))return int(c.fault);
P_65010_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65010_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65010_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65010_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65010_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65010_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65010_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65010_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65010_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65010_9:;
goto L_65013;
}
L_65013:{ // MOV dword ptr [EBP + 0xfffffe88],EAX
c.pc=0x65013;if(!sl_tick(c))return int(c.fault);
P_65013_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe88ULL)),c);
P_65013_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65013_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65013_3:;
goto L_65019;
}
L_65019:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65019;if(!sl_tick(c))return int(c.fault);
P_65019_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65019_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65019_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65019_3:;
goto L_6501f;
}
L_6501f:{ // ADD EAX,0x8
c.pc=0x6501f;if(!sl_tick(c))return int(c.fault);
P_6501f_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_6501f_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_6501f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_6501f_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_6501f_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_6501f_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_6501f_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_6501f_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_6501f_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_6501f_9:;
goto L_65022;
}
L_65022:{ // MOV dword ptr [EBP + 0xfffffe98],EAX
c.pc=0x65022;if(!sl_tick(c))return int(c.fault);
P_65022_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe98ULL)),c);
P_65022_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65022_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65022_3:;
goto L_65028;
}
L_65028:{ // MOV byte ptr [EBP + 0xfffffe9c],0x0
c.pc=0x65028;if(!sl_tick(c))return int(c.fault);
P_65028_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe9cULL)),c);
P_65028_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_65028_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_65028_3:;
goto L_6502f;
}
L_6502f:{ // MOV dword ptr [EBP + 0xfffffea0],0x3c
c.pc=0x6502f;if(!sl_tick(c))return int(c.fault);
P_6502f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffea0ULL)),c);
P_6502f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_6502f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_6502f_3:;
goto L_65039;
}
L_65039:{ // MOV dword ptr [EBP + 0xfffffea4],0x64
c.pc=0x65039;if(!sl_tick(c))return int(c.fault);
P_65039_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffea4ULL)),c);
P_65039_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_65039_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65039_3:;
goto L_65043;
}
L_65043:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x65043;if(!sl_tick(c))return int(c.fault);
P_65043_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65043_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_65043_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65043_3:;
goto L_6504b;
}
L_6504b:{ // LEA EAX,[EBP + 0xfffffe98]
c.pc=0x6504b;if(!sl_tick(c))return int(c.fault);
P_6504b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe98ULL)),c);
P_6504b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_6504b_2:;
goto L_65051;
}
L_65051:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x65051;if(!sl_tick(c))return int(c.fault);
P_65051_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65051_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65051_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65051_3:;
goto L_65055;
}
L_65055:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x65055;if(!sl_tick(c))return int(c.fault);
P_65055_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_65055_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65055_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65055_3:;
goto L_6505b;
}
L_6505b:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x6505b;if(!sl_tick(c))return int(c.fault);
P_6505b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_6505b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6505b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6505b_3:;
goto L_6505f;
}
L_6505f:{ // LEA EAX,[EDI + 0x7ca0]
c.pc=0x6505f;if(!sl_tick(c))return int(c.fault);
P_6505f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x7ca0ULL)),c);
P_6505f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_6505f_2:;
goto L_65065;
}
L_65065:{ // MOV dword ptr [ESP],EAX
c.pc=0x65065;if(!sl_tick(c))return int(c.fault);
P_65065_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65065_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65065_2:;
goto L_65068;
}
L_65068:{ // CALL 0x00013c66
c.pc=0x65068;if(!sl_tick(c))return int(c.fault);
P_65068_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_65068_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x6506dULL),c);
P_65068_2:;
c.pc=0x13c66;goto dispatch;
P_65068_3:;
goto L_6506d;
}
L_6506d:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x6506d;if(!sl_tick(c))return int(c.fault);
P_6506d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_6506d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_6506d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_6506d_3:;
goto L_65073;
}
L_65073:{ // ADD EAX,0x8
c.pc=0x65073;if(!sl_tick(c))return int(c.fault);
P_65073_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65073_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65073_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65073_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65073_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65073_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65073_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65073_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65073_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65073_9:;
goto L_65076;
}
L_65076:{ // MOV dword ptr [EBP + 0xfffffe98],EAX
c.pc=0x65076;if(!sl_tick(c))return int(c.fault);
P_65076_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffe98ULL)),c);
P_65076_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65076_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65076_3:;
goto L_6507c;
}
L_6507c:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x6507c;if(!sl_tick(c))return int(c.fault);
P_6507c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_6507c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_6507c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_6507c_3:;
goto L_65082;
}
L_65082:{ // ADD EAX,0x8
c.pc=0x65082;if(!sl_tick(c))return int(c.fault);
P_65082_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65082_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65082_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65082_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65082_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65082_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65082_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65082_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65082_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65082_9:;
goto L_65085;
}
L_65085:{ // MOV dword ptr [EBP + 0xfffffea8],EAX
c.pc=0x65085;if(!sl_tick(c))return int(c.fault);
P_65085_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffea8ULL)),c);
P_65085_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65085_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65085_3:;
goto L_6508b;
}
L_6508b:{ // MOV byte ptr [EBP + 0xfffffeac],0x0
c.pc=0x6508b;if(!sl_tick(c))return int(c.fault);
P_6508b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffeacULL)),c);
P_6508b_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_6508b_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_6508b_3:;
goto L_65092;
}
L_65092:{ // MOV dword ptr [EBP + 0xfffffeb0],0x3c
c.pc=0x65092;if(!sl_tick(c))return int(c.fault);
P_65092_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffeb0ULL)),c);
P_65092_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_65092_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65092_3:;
goto L_6509c;
}
L_6509c:{ // MOV dword ptr [EBP + 0xfffffeb4],0x64
c.pc=0x6509c;if(!sl_tick(c))return int(c.fault);
P_6509c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffeb4ULL)),c);
P_6509c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_6509c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_6509c_3:;
goto L_650a6;
}
L_650a6:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x650a6;if(!sl_tick(c))return int(c.fault);
P_650a6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_650a6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_650a6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_650a6_3:;
goto L_650ae;
}
L_650ae:{ // LEA EAX,[EBP + 0xfffffea8]
c.pc=0x650ae;if(!sl_tick(c))return int(c.fault);
P_650ae_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffea8ULL)),c);
P_650ae_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_650ae_2:;
goto L_650b4;
}
L_650b4:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x650b4;if(!sl_tick(c))return int(c.fault);
P_650b4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_650b4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_650b4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_650b4_3:;
goto L_650b8;
}
L_650b8:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x650b8;if(!sl_tick(c))return int(c.fault);
P_650b8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_650b8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_650b8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_650b8_3:;
goto L_650be;
}
L_650be:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x650be;if(!sl_tick(c))return int(c.fault);
P_650be_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_650be_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_650be_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_650be_3:;
goto L_650c2;
}
L_650c2:{ // LEA EAX,[EDI + 0xd9d8]
c.pc=0x650c2;if(!sl_tick(c))return int(c.fault);
P_650c2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xd9d8ULL)),c);
P_650c2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_650c2_2:;
goto L_650c8;
}
L_650c8:{ // MOV dword ptr [ESP],EAX
c.pc=0x650c8;if(!sl_tick(c))return int(c.fault);
P_650c8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_650c8_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_650c8_2:;
goto L_650cb;
}
L_650cb:{ // CALL 0x00013c66
c.pc=0x650cb;if(!sl_tick(c))return int(c.fault);
P_650cb_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_650cb_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x650d0ULL),c);
P_650cb_2:;
c.pc=0x13c66;goto dispatch;
P_650cb_3:;
goto L_650d0;
}
L_650d0:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x650d0;if(!sl_tick(c))return int(c.fault);
P_650d0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_650d0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_650d0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_650d0_3:;
goto L_650d6;
}
L_650d6:{ // ADD EAX,0x8
c.pc=0x650d6;if(!sl_tick(c))return int(c.fault);
P_650d6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_650d6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_650d6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_650d6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_650d6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_650d6_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_650d6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_650d6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_650d6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_650d6_9:;
goto L_650d9;
}
L_650d9:{ // MOV dword ptr [EBP + 0xfffffea8],EAX
c.pc=0x650d9;if(!sl_tick(c))return int(c.fault);
P_650d9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffea8ULL)),c);
P_650d9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_650d9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_650d9_3:;
goto L_650df;
}
L_650df:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x650df;if(!sl_tick(c))return int(c.fault);
P_650df_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_650df_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_650df_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_650df_3:;
goto L_650e5;
}
L_650e5:{ // ADD EAX,0x8
c.pc=0x650e5;if(!sl_tick(c))return int(c.fault);
P_650e5_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_650e5_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_650e5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_650e5_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_650e5_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_650e5_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_650e5_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_650e5_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_650e5_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_650e5_9:;
goto L_650e8;
}
L_650e8:{ // MOV dword ptr [EBP + 0xfffffeb8],EAX
c.pc=0x650e8;if(!sl_tick(c))return int(c.fault);
P_650e8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffeb8ULL)),c);
P_650e8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_650e8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_650e8_3:;
goto L_650ee;
}
L_650ee:{ // MOV byte ptr [EBP + 0xfffffebc],0x0
c.pc=0x650ee;if(!sl_tick(c))return int(c.fault);
P_650ee_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffebcULL)),c);
P_650ee_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_650ee_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_650ee_3:;
goto L_650f5;
}
L_650f5:{ // MOV dword ptr [EBP + 0xfffffec0],0x3c
c.pc=0x650f5;if(!sl_tick(c))return int(c.fault);
P_650f5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffec0ULL)),c);
P_650f5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_650f5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_650f5_3:;
goto L_650ff;
}
L_650ff:{ // MOV dword ptr [EBP + 0xfffffec4],0x64
c.pc=0x650ff;if(!sl_tick(c))return int(c.fault);
P_650ff_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffec4ULL)),c);
P_650ff_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_650ff_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_650ff_3:;
goto L_65109;
}
L_65109:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x65109;if(!sl_tick(c))return int(c.fault);
P_65109_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65109_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_65109_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65109_3:;
goto L_65111;
}
L_65111:{ // LEA EAX,[EBP + 0xfffffeb8]
c.pc=0x65111;if(!sl_tick(c))return int(c.fault);
P_65111_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffeb8ULL)),c);
P_65111_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_65111_2:;
goto L_65117;
}
L_65117:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x65117;if(!sl_tick(c))return int(c.fault);
P_65117_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65117_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65117_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65117_3:;
goto L_6511b;
}
L_6511b:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x6511b;if(!sl_tick(c))return int(c.fault);
P_6511b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_6511b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_6511b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_6511b_3:;
goto L_65121;
}
L_65121:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x65121;if(!sl_tick(c))return int(c.fault);
P_65121_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65121_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65121_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65121_3:;
goto L_65125;
}
L_65125:{ // LEA EAX,[EDI + 0x13710]
c.pc=0x65125;if(!sl_tick(c))return int(c.fault);
P_65125_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x13710ULL)),c);
P_65125_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_65125_2:;
goto L_6512b;
}
L_6512b:{ // MOV dword ptr [ESP],EAX
c.pc=0x6512b;if(!sl_tick(c))return int(c.fault);
P_6512b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6512b_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6512b_2:;
goto L_6512e;
}
L_6512e:{ // CALL 0x00013c66
c.pc=0x6512e;if(!sl_tick(c))return int(c.fault);
P_6512e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_6512e_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x65133ULL),c);
P_6512e_2:;
c.pc=0x13c66;goto dispatch;
P_6512e_3:;
goto L_65133;
}
L_65133:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65133;if(!sl_tick(c))return int(c.fault);
P_65133_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65133_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65133_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65133_3:;
goto L_65139;
}
L_65139:{ // ADD EAX,0x8
c.pc=0x65139;if(!sl_tick(c))return int(c.fault);
P_65139_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65139_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65139_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65139_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65139_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65139_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65139_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65139_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65139_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65139_9:;
goto L_6513c;
}
L_6513c:{ // MOV dword ptr [EBP + 0xfffffeb8],EAX
c.pc=0x6513c;if(!sl_tick(c))return int(c.fault);
P_6513c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffeb8ULL)),c);
P_6513c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6513c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6513c_3:;
goto L_65142;
}
L_65142:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65142;if(!sl_tick(c))return int(c.fault);
P_65142_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65142_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65142_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65142_3:;
goto L_65148;
}
L_65148:{ // ADD EAX,0x8
c.pc=0x65148;if(!sl_tick(c))return int(c.fault);
P_65148_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65148_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65148_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65148_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65148_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65148_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65148_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65148_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65148_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65148_9:;
goto L_6514b;
}
L_6514b:{ // MOV dword ptr [EBP + 0xfffffec8],EAX
c.pc=0x6514b;if(!sl_tick(c))return int(c.fault);
P_6514b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffec8ULL)),c);
P_6514b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6514b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6514b_3:;
goto L_65151;
}
L_65151:{ // MOV byte ptr [EBP + 0xfffffecc],0x0
c.pc=0x65151;if(!sl_tick(c))return int(c.fault);
P_65151_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffeccULL)),c);
P_65151_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_65151_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_65151_3:;
goto L_65158;
}
L_65158:{ // MOV dword ptr [EBP + 0xfffffed0],0x3c
c.pc=0x65158;if(!sl_tick(c))return int(c.fault);
P_65158_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffed0ULL)),c);
P_65158_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_65158_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65158_3:;
goto L_65162;
}
L_65162:{ // MOV dword ptr [EBP + 0xfffffed4],0x64
c.pc=0x65162;if(!sl_tick(c))return int(c.fault);
P_65162_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffed4ULL)),c);
P_65162_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_65162_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65162_3:;
goto L_6516c;
}
L_6516c:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x6516c;if(!sl_tick(c))return int(c.fault);
P_6516c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_6516c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_6516c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_6516c_3:;
goto L_65174;
}
L_65174:{ // LEA EAX,[EBP + 0xfffffec8]
c.pc=0x65174;if(!sl_tick(c))return int(c.fault);
P_65174_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffec8ULL)),c);
P_65174_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_65174_2:;
goto L_6517a;
}
L_6517a:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x6517a;if(!sl_tick(c))return int(c.fault);
P_6517a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_6517a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6517a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6517a_3:;
goto L_6517e;
}
L_6517e:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x6517e;if(!sl_tick(c))return int(c.fault);
P_6517e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_6517e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_6517e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_6517e_3:;
goto L_65184;
}
L_65184:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x65184;if(!sl_tick(c))return int(c.fault);
P_65184_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65184_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65184_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65184_3:;
goto L_65188;
}
L_65188:{ // LEA EAX,[EDI + 0x8410]
c.pc=0x65188;if(!sl_tick(c))return int(c.fault);
P_65188_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x8410ULL)),c);
P_65188_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_65188_2:;
goto L_6518e;
}
L_6518e:{ // MOV dword ptr [ESP],EAX
c.pc=0x6518e;if(!sl_tick(c))return int(c.fault);
P_6518e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6518e_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6518e_2:;
goto L_65191;
}
L_65191:{ // CALL 0x0003bd90
c.pc=0x65191;if(!sl_tick(c))return int(c.fault);
P_65191_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_65191_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x65196ULL),c);
P_65191_2:;
c.pc=0x3bd90;goto dispatch;
P_65191_3:;
goto L_65196;
}
L_65196:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65196;if(!sl_tick(c))return int(c.fault);
P_65196_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65196_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65196_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65196_3:;
goto L_6519c;
}
L_6519c:{ // ADD EAX,0x8
c.pc=0x6519c;if(!sl_tick(c))return int(c.fault);
P_6519c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_6519c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_6519c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_6519c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_6519c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_6519c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_6519c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_6519c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_6519c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_6519c_9:;
goto L_6519f;
}
L_6519f:{ // MOV dword ptr [EBP + 0xfffffec8],EAX
c.pc=0x6519f;if(!sl_tick(c))return int(c.fault);
P_6519f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffec8ULL)),c);
P_6519f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6519f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6519f_3:;
goto L_651a5;
}
L_651a5:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x651a5;if(!sl_tick(c))return int(c.fault);
P_651a5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_651a5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_651a5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_651a5_3:;
goto L_651ab;
}
L_651ab:{ // ADD EAX,0x8
c.pc=0x651ab;if(!sl_tick(c))return int(c.fault);
P_651ab_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_651ab_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_651ab_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_651ab_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_651ab_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_651ab_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_651ab_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_651ab_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_651ab_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_651ab_9:;
goto L_651ae;
}
L_651ae:{ // MOV dword ptr [EBP + 0xfffffed8],EAX
c.pc=0x651ae;if(!sl_tick(c))return int(c.fault);
P_651ae_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffed8ULL)),c);
P_651ae_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_651ae_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_651ae_3:;
goto L_651b4;
}
L_651b4:{ // MOV byte ptr [EBP + 0xfffffedc],0x0
c.pc=0x651b4;if(!sl_tick(c))return int(c.fault);
P_651b4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffedcULL)),c);
P_651b4_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_651b4_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_651b4_3:;
goto L_651bb;
}
L_651bb:{ // MOV dword ptr [EBP + 0xfffffee0],0x3c
c.pc=0x651bb;if(!sl_tick(c))return int(c.fault);
P_651bb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffee0ULL)),c);
P_651bb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_651bb_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_651bb_3:;
goto L_651c5;
}
L_651c5:{ // MOV dword ptr [EBP + 0xfffffee4],0x64
c.pc=0x651c5;if(!sl_tick(c))return int(c.fault);
P_651c5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffee4ULL)),c);
P_651c5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_651c5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_651c5_3:;
goto L_651cf;
}
L_651cf:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x651cf;if(!sl_tick(c))return int(c.fault);
P_651cf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_651cf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_651cf_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_651cf_3:;
goto L_651d7;
}
L_651d7:{ // LEA EAX,[EBP + 0xfffffed8]
c.pc=0x651d7;if(!sl_tick(c))return int(c.fault);
P_651d7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffed8ULL)),c);
P_651d7_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_651d7_2:;
goto L_651dd;
}
L_651dd:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x651dd;if(!sl_tick(c))return int(c.fault);
P_651dd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_651dd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_651dd_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_651dd_3:;
goto L_651e1;
}
L_651e1:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x651e1;if(!sl_tick(c))return int(c.fault);
P_651e1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_651e1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_651e1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_651e1_3:;
goto L_651e7;
}
L_651e7:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x651e7;if(!sl_tick(c))return int(c.fault);
P_651e7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_651e7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_651e7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_651e7_3:;
goto L_651eb;
}
L_651eb:{ // LEA EAX,[EDI + 0xe148]
c.pc=0x651eb;if(!sl_tick(c))return int(c.fault);
P_651eb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xe148ULL)),c);
P_651eb_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_651eb_2:;
goto L_651f1;
}
L_651f1:{ // MOV dword ptr [ESP],EAX
c.pc=0x651f1;if(!sl_tick(c))return int(c.fault);
P_651f1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_651f1_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_651f1_2:;
goto L_651f4;
}
L_651f4:{ // CALL 0x0003bd90
c.pc=0x651f4;if(!sl_tick(c))return int(c.fault);
P_651f4_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_651f4_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x651f9ULL),c);
P_651f4_2:;
c.pc=0x3bd90;goto dispatch;
P_651f4_3:;
goto L_651f9;
}
L_651f9:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x651f9;if(!sl_tick(c))return int(c.fault);
P_651f9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_651f9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_651f9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_651f9_3:;
goto L_651ff;
}
L_651ff:{ // ADD EAX,0x8
c.pc=0x651ff;if(!sl_tick(c))return int(c.fault);
P_651ff_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_651ff_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_651ff_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_651ff_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_651ff_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_651ff_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_651ff_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_651ff_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_651ff_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_651ff_9:;
goto L_65202;
}
L_65202:{ // MOV dword ptr [EBP + 0xfffffed8],EAX
c.pc=0x65202;if(!sl_tick(c))return int(c.fault);
P_65202_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffed8ULL)),c);
P_65202_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65202_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65202_3:;
goto L_65208;
}
L_65208:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65208;if(!sl_tick(c))return int(c.fault);
P_65208_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65208_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65208_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65208_3:;
goto L_6520e;
}
L_6520e:{ // ADD EAX,0x8
c.pc=0x6520e;if(!sl_tick(c))return int(c.fault);
P_6520e_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_6520e_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_6520e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_6520e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_6520e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_6520e_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_6520e_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_6520e_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_6520e_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_6520e_9:;
goto L_65211;
}
L_65211:{ // MOV dword ptr [EBP + 0xfffffee8],EAX
c.pc=0x65211;if(!sl_tick(c))return int(c.fault);
P_65211_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffee8ULL)),c);
P_65211_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65211_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65211_3:;
goto L_65217;
}
L_65217:{ // MOV byte ptr [EBP + 0xfffffeec],0x0
c.pc=0x65217;if(!sl_tick(c))return int(c.fault);
P_65217_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffeecULL)),c);
P_65217_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_65217_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_65217_3:;
goto L_6521e;
}
L_6521e:{ // MOV dword ptr [EBP + 0xfffffef0],0x3c
c.pc=0x6521e;if(!sl_tick(c))return int(c.fault);
P_6521e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffef0ULL)),c);
P_6521e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_6521e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_6521e_3:;
goto L_65228;
}
L_65228:{ // MOV dword ptr [EBP + 0xfffffef4],0x64
c.pc=0x65228;if(!sl_tick(c))return int(c.fault);
P_65228_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffef4ULL)),c);
P_65228_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_65228_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65228_3:;
goto L_65232;
}
L_65232:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x65232;if(!sl_tick(c))return int(c.fault);
P_65232_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65232_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_65232_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65232_3:;
goto L_6523a;
}
L_6523a:{ // LEA EAX,[EBP + 0xfffffee8]
c.pc=0x6523a;if(!sl_tick(c))return int(c.fault);
P_6523a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffee8ULL)),c);
P_6523a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_6523a_2:;
goto L_65240;
}
L_65240:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x65240;if(!sl_tick(c))return int(c.fault);
P_65240_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65240_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65240_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65240_3:;
goto L_65244;
}
L_65244:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x65244;if(!sl_tick(c))return int(c.fault);
P_65244_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_65244_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65244_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65244_3:;
goto L_6524a;
}
L_6524a:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x6524a;if(!sl_tick(c))return int(c.fault);
P_6524a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_6524a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6524a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6524a_3:;
goto L_6524e;
}
L_6524e:{ // LEA EAX,[EDI + 0x13e80]
c.pc=0x6524e;if(!sl_tick(c))return int(c.fault);
P_6524e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x13e80ULL)),c);
P_6524e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_6524e_2:;
goto L_65254;
}
L_65254:{ // MOV dword ptr [ESP],EAX
c.pc=0x65254;if(!sl_tick(c))return int(c.fault);
P_65254_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65254_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65254_2:;
goto L_65257;
}
L_65257:{ // CALL 0x0003bd90
c.pc=0x65257;if(!sl_tick(c))return int(c.fault);
P_65257_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_65257_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x6525cULL),c);
P_65257_2:;
c.pc=0x3bd90;goto dispatch;
P_65257_3:;
goto L_6525c;
}
L_6525c:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x6525c;if(!sl_tick(c))return int(c.fault);
P_6525c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_6525c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_6525c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_6525c_3:;
goto L_65262;
}
L_65262:{ // ADD EAX,0x8
c.pc=0x65262;if(!sl_tick(c))return int(c.fault);
P_65262_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65262_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65262_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65262_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65262_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65262_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65262_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65262_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65262_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65262_9:;
goto L_65265;
}
L_65265:{ // MOV dword ptr [EBP + 0xfffffee8],EAX
c.pc=0x65265;if(!sl_tick(c))return int(c.fault);
P_65265_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffee8ULL)),c);
P_65265_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65265_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65265_3:;
goto L_6526b;
}
L_6526b:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x6526b;if(!sl_tick(c))return int(c.fault);
P_6526b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_6526b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_6526b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_6526b_3:;
goto L_65271;
}
L_65271:{ // ADD EAX,0x8
c.pc=0x65271;if(!sl_tick(c))return int(c.fault);
P_65271_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65271_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65271_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65271_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65271_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65271_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65271_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65271_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65271_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65271_9:;
goto L_65274;
}
L_65274:{ // MOV dword ptr [EBP + 0xfffffef8],EAX
c.pc=0x65274;if(!sl_tick(c))return int(c.fault);
P_65274_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffef8ULL)),c);
P_65274_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65274_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65274_3:;
goto L_6527a;
}
L_6527a:{ // MOV byte ptr [EBP + 0xfffffefc],0x0
c.pc=0x6527a;if(!sl_tick(c))return int(c.fault);
P_6527a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffefcULL)),c);
P_6527a_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_6527a_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_6527a_3:;
goto L_65281;
}
L_65281:{ // MOV dword ptr [EBP + 0xffffff00],0x3c
c.pc=0x65281;if(!sl_tick(c))return int(c.fault);
P_65281_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff00ULL)),c);
P_65281_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_65281_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65281_3:;
goto L_6528b;
}
L_6528b:{ // MOV dword ptr [EBP + 0xffffff04],0x64
c.pc=0x6528b;if(!sl_tick(c))return int(c.fault);
P_6528b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff04ULL)),c);
P_6528b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_6528b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_6528b_3:;
goto L_65295;
}
L_65295:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x65295;if(!sl_tick(c))return int(c.fault);
P_65295_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65295_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_65295_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65295_3:;
goto L_6529d;
}
L_6529d:{ // LEA EAX,[EBP + 0xfffffef8]
c.pc=0x6529d;if(!sl_tick(c))return int(c.fault);
P_6529d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffef8ULL)),c);
P_6529d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_6529d_2:;
goto L_652a3;
}
L_652a3:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x652a3;if(!sl_tick(c))return int(c.fault);
P_652a3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_652a3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_652a3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_652a3_3:;
goto L_652a7;
}
L_652a7:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x652a7;if(!sl_tick(c))return int(c.fault);
P_652a7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_652a7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_652a7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_652a7_3:;
goto L_652ad;
}
L_652ad:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x652ad;if(!sl_tick(c))return int(c.fault);
P_652ad_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_652ad_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_652ad_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_652ad_3:;
goto L_652b1;
}
L_652b1:{ // LEA EAX,[EDI + 0x7edc]
c.pc=0x652b1;if(!sl_tick(c))return int(c.fault);
P_652b1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x7edcULL)),c);
P_652b1_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_652b1_2:;
goto L_652b7;
}
L_652b7:{ // MOV dword ptr [ESP],EAX
c.pc=0x652b7;if(!sl_tick(c))return int(c.fault);
P_652b7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_652b7_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_652b7_2:;
goto L_652ba;
}
L_652ba:{ // CALL 0x00013c66
c.pc=0x652ba;if(!sl_tick(c))return int(c.fault);
P_652ba_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_652ba_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x652bfULL),c);
P_652ba_2:;
c.pc=0x13c66;goto dispatch;
P_652ba_3:;
goto L_652bf;
}
L_652bf:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x652bf;if(!sl_tick(c))return int(c.fault);
P_652bf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_652bf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_652bf_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_652bf_3:;
goto L_652c5;
}
L_652c5:{ // ADD EAX,0x8
c.pc=0x652c5;if(!sl_tick(c))return int(c.fault);
P_652c5_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_652c5_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_652c5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_652c5_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_652c5_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_652c5_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_652c5_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_652c5_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_652c5_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_652c5_9:;
goto L_652c8;
}
L_652c8:{ // MOV dword ptr [EBP + 0xfffffef8],EAX
c.pc=0x652c8;if(!sl_tick(c))return int(c.fault);
P_652c8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffef8ULL)),c);
P_652c8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_652c8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_652c8_3:;
goto L_652ce;
}
L_652ce:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x652ce;if(!sl_tick(c))return int(c.fault);
P_652ce_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_652ce_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_652ce_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_652ce_3:;
goto L_652d4;
}
L_652d4:{ // ADD EAX,0x8
c.pc=0x652d4;if(!sl_tick(c))return int(c.fault);
P_652d4_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_652d4_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_652d4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_652d4_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_652d4_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_652d4_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_652d4_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_652d4_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_652d4_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_652d4_9:;
goto L_652d7;
}
L_652d7:{ // MOV dword ptr [EBP + 0xffffff08],EAX
c.pc=0x652d7;if(!sl_tick(c))return int(c.fault);
P_652d7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff08ULL)),c);
P_652d7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_652d7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_652d7_3:;
goto L_652dd;
}
L_652dd:{ // MOV byte ptr [EBP + 0xffffff0c],0x0
c.pc=0x652dd;if(!sl_tick(c))return int(c.fault);
P_652dd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff0cULL)),c);
P_652dd_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_652dd_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_652dd_3:;
goto L_652e4;
}
L_652e4:{ // MOV dword ptr [EBP + 0xffffff10],0x3c
c.pc=0x652e4;if(!sl_tick(c))return int(c.fault);
P_652e4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff10ULL)),c);
P_652e4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_652e4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_652e4_3:;
goto L_652ee;
}
L_652ee:{ // MOV dword ptr [EBP + 0xffffff14],0x64
c.pc=0x652ee;if(!sl_tick(c))return int(c.fault);
P_652ee_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff14ULL)),c);
P_652ee_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_652ee_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_652ee_3:;
goto L_652f8;
}
L_652f8:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x652f8;if(!sl_tick(c))return int(c.fault);
P_652f8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_652f8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_652f8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_652f8_3:;
goto L_65300;
}
L_65300:{ // LEA EAX,[EBP + 0xffffff08]
c.pc=0x65300;if(!sl_tick(c))return int(c.fault);
P_65300_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff08ULL)),c);
P_65300_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_65300_2:;
goto L_65306;
}
L_65306:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x65306;if(!sl_tick(c))return int(c.fault);
P_65306_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65306_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65306_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65306_3:;
goto L_6530a;
}
L_6530a:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x6530a;if(!sl_tick(c))return int(c.fault);
P_6530a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_6530a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_6530a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_6530a_3:;
goto L_65310;
}
L_65310:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x65310;if(!sl_tick(c))return int(c.fault);
P_65310_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65310_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65310_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65310_3:;
goto L_65314;
}
L_65314:{ // LEA EAX,[EDI + 0xdc14]
c.pc=0x65314;if(!sl_tick(c))return int(c.fault);
P_65314_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xdc14ULL)),c);
P_65314_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_65314_2:;
goto L_6531a;
}
L_6531a:{ // MOV dword ptr [ESP],EAX
c.pc=0x6531a;if(!sl_tick(c))return int(c.fault);
P_6531a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6531a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6531a_2:;
goto L_6531d;
}
L_6531d:{ // CALL 0x00013c66
c.pc=0x6531d;if(!sl_tick(c))return int(c.fault);
P_6531d_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_6531d_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x65322ULL),c);
P_6531d_2:;
c.pc=0x13c66;goto dispatch;
P_6531d_3:;
goto L_65322;
}
L_65322:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65322;if(!sl_tick(c))return int(c.fault);
P_65322_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65322_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65322_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65322_3:;
goto L_65328;
}
L_65328:{ // ADD EAX,0x8
c.pc=0x65328;if(!sl_tick(c))return int(c.fault);
P_65328_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65328_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65328_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65328_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65328_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65328_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65328_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65328_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65328_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65328_9:;
goto L_6532b;
}
L_6532b:{ // MOV dword ptr [EBP + 0xffffff08],EAX
c.pc=0x6532b;if(!sl_tick(c))return int(c.fault);
P_6532b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff08ULL)),c);
P_6532b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6532b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6532b_3:;
goto L_65331;
}
L_65331:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65331;if(!sl_tick(c))return int(c.fault);
P_65331_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65331_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65331_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65331_3:;
goto L_65337;
}
L_65337:{ // ADD EAX,0x8
c.pc=0x65337;if(!sl_tick(c))return int(c.fault);
P_65337_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65337_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65337_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65337_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65337_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65337_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65337_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65337_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65337_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65337_9:;
goto L_6533a;
}
L_6533a:{ // MOV dword ptr [EBP + 0xffffff18],EAX
c.pc=0x6533a;if(!sl_tick(c))return int(c.fault);
P_6533a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff18ULL)),c);
P_6533a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6533a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6533a_3:;
goto L_65340;
}
L_65340:{ // MOV byte ptr [EBP + 0xffffff1c],0x0
c.pc=0x65340;if(!sl_tick(c))return int(c.fault);
P_65340_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff1cULL)),c);
P_65340_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_65340_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_65340_3:;
goto L_65347;
}
L_65347:{ // MOV dword ptr [EBP + 0xffffff20],0x3c
c.pc=0x65347;if(!sl_tick(c))return int(c.fault);
P_65347_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff20ULL)),c);
P_65347_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_65347_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65347_3:;
goto L_65351;
}
L_65351:{ // MOV dword ptr [EBP + 0xffffff24],0x64
c.pc=0x65351;if(!sl_tick(c))return int(c.fault);
P_65351_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff24ULL)),c);
P_65351_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_65351_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65351_3:;
goto L_6535b;
}
L_6535b:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x6535b;if(!sl_tick(c))return int(c.fault);
P_6535b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_6535b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_6535b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_6535b_3:;
goto L_65363;
}
L_65363:{ // LEA EAX,[EBP + 0xffffff18]
c.pc=0x65363;if(!sl_tick(c))return int(c.fault);
P_65363_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff18ULL)),c);
P_65363_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_65363_2:;
goto L_65369;
}
L_65369:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x65369;if(!sl_tick(c))return int(c.fault);
P_65369_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65369_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65369_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65369_3:;
goto L_6536d;
}
L_6536d:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x6536d;if(!sl_tick(c))return int(c.fault);
P_6536d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_6536d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_6536d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_6536d_3:;
goto L_65373;
}
L_65373:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x65373;if(!sl_tick(c))return int(c.fault);
P_65373_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65373_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65373_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65373_3:;
goto L_65377;
}
L_65377:{ // LEA EAX,[EDI + 0x1394c]
c.pc=0x65377;if(!sl_tick(c))return int(c.fault);
P_65377_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1394cULL)),c);
P_65377_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_65377_2:;
goto L_6537d;
}
L_6537d:{ // MOV dword ptr [ESP],EAX
c.pc=0x6537d;if(!sl_tick(c))return int(c.fault);
P_6537d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6537d_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6537d_2:;
goto L_65380;
}
L_65380:{ // CALL 0x00013c66
c.pc=0x65380;if(!sl_tick(c))return int(c.fault);
P_65380_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_65380_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x65385ULL),c);
P_65380_2:;
c.pc=0x13c66;goto dispatch;
P_65380_3:;
goto L_65385;
}
L_65385:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65385;if(!sl_tick(c))return int(c.fault);
P_65385_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65385_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65385_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65385_3:;
goto L_6538b;
}
L_6538b:{ // ADD EAX,0x8
c.pc=0x6538b;if(!sl_tick(c))return int(c.fault);
P_6538b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_6538b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_6538b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_6538b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_6538b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_6538b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_6538b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_6538b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_6538b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_6538b_9:;
goto L_6538e;
}
L_6538e:{ // MOV dword ptr [EBP + 0xffffff18],EAX
c.pc=0x6538e;if(!sl_tick(c))return int(c.fault);
P_6538e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff18ULL)),c);
P_6538e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6538e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6538e_3:;
goto L_65394;
}
L_65394:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65394;if(!sl_tick(c))return int(c.fault);
P_65394_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65394_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65394_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65394_3:;
goto L_6539a;
}
L_6539a:{ // ADD EAX,0x8
c.pc=0x6539a;if(!sl_tick(c))return int(c.fault);
P_6539a_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_6539a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_6539a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_6539a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_6539a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_6539a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_6539a_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_6539a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_6539a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_6539a_9:;
goto L_6539d;
}
L_6539d:{ // MOV dword ptr [EBP + 0xffffff28],EAX
c.pc=0x6539d;if(!sl_tick(c))return int(c.fault);
P_6539d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff28ULL)),c);
P_6539d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6539d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6539d_3:;
goto L_653a3;
}
L_653a3:{ // MOV byte ptr [EBP + 0xffffff2c],0x0
c.pc=0x653a3;if(!sl_tick(c))return int(c.fault);
P_653a3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff2cULL)),c);
P_653a3_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_653a3_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_653a3_3:;
goto L_653aa;
}
L_653aa:{ // MOV dword ptr [EBP + 0xffffff30],0x3c
c.pc=0x653aa;if(!sl_tick(c))return int(c.fault);
P_653aa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff30ULL)),c);
P_653aa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_653aa_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_653aa_3:;
goto L_653b4;
}
L_653b4:{ // MOV dword ptr [EBP + 0xffffff34],0x64
c.pc=0x653b4;if(!sl_tick(c))return int(c.fault);
P_653b4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff34ULL)),c);
P_653b4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_653b4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_653b4_3:;
goto L_653be;
}
L_653be:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x653be;if(!sl_tick(c))return int(c.fault);
P_653be_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_653be_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_653be_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_653be_3:;
goto L_653c6;
}
L_653c6:{ // LEA EAX,[EBP + 0xffffff28]
c.pc=0x653c6;if(!sl_tick(c))return int(c.fault);
P_653c6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff28ULL)),c);
P_653c6_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_653c6_2:;
goto L_653cc;
}
L_653cc:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x653cc;if(!sl_tick(c))return int(c.fault);
P_653cc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_653cc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_653cc_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_653cc_3:;
goto L_653d0;
}
L_653d0:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x653d0;if(!sl_tick(c))return int(c.fault);
P_653d0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_653d0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_653d0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_653d0_3:;
goto L_653d6;
}
L_653d6:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x653d6;if(!sl_tick(c))return int(c.fault);
P_653d6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_653d6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_653d6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_653d6_3:;
goto L_653da;
}
L_653da:{ // LEA EAX,[EDI + 0x80e8]
c.pc=0x653da;if(!sl_tick(c))return int(c.fault);
P_653da_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x80e8ULL)),c);
P_653da_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_653da_2:;
goto L_653e0;
}
L_653e0:{ // MOV dword ptr [ESP],EAX
c.pc=0x653e0;if(!sl_tick(c))return int(c.fault);
P_653e0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_653e0_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_653e0_2:;
goto L_653e3;
}
L_653e3:{ // CALL 0x00013c66
c.pc=0x653e3;if(!sl_tick(c))return int(c.fault);
P_653e3_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_653e3_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x653e8ULL),c);
P_653e3_2:;
c.pc=0x13c66;goto dispatch;
P_653e3_3:;
goto L_653e8;
}
L_653e8:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x653e8;if(!sl_tick(c))return int(c.fault);
P_653e8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_653e8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_653e8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_653e8_3:;
goto L_653ee;
}
L_653ee:{ // ADD EAX,0x8
c.pc=0x653ee;if(!sl_tick(c))return int(c.fault);
P_653ee_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_653ee_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_653ee_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_653ee_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_653ee_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_653ee_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_653ee_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_653ee_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_653ee_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_653ee_9:;
goto L_653f1;
}
L_653f1:{ // MOV dword ptr [EBP + 0xffffff28],EAX
c.pc=0x653f1;if(!sl_tick(c))return int(c.fault);
P_653f1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff28ULL)),c);
P_653f1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_653f1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_653f1_3:;
goto L_653f7;
}
L_653f7:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x653f7;if(!sl_tick(c))return int(c.fault);
P_653f7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_653f7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_653f7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_653f7_3:;
goto L_653fd;
}
L_653fd:{ // ADD EAX,0x8
c.pc=0x653fd;if(!sl_tick(c))return int(c.fault);
P_653fd_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_653fd_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_653fd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_653fd_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_653fd_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_653fd_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_653fd_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_653fd_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_653fd_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_653fd_9:;
goto L_65400;
}
L_65400:{ // MOV dword ptr [EBP + 0xffffff38],EAX
c.pc=0x65400;if(!sl_tick(c))return int(c.fault);
P_65400_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff38ULL)),c);
P_65400_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65400_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65400_3:;
goto L_65406;
}
L_65406:{ // MOV byte ptr [EBP + 0xffffff3c],0x0
c.pc=0x65406;if(!sl_tick(c))return int(c.fault);
P_65406_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff3cULL)),c);
P_65406_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_65406_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_65406_3:;
goto L_6540d;
}
L_6540d:{ // MOV dword ptr [EBP + 0xffffff40],0x3c
c.pc=0x6540d;if(!sl_tick(c))return int(c.fault);
P_6540d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff40ULL)),c);
P_6540d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_6540d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_6540d_3:;
goto L_65417;
}
L_65417:{ // MOV dword ptr [EBP + 0xffffff44],0x64
c.pc=0x65417;if(!sl_tick(c))return int(c.fault);
P_65417_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff44ULL)),c);
P_65417_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_65417_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65417_3:;
goto L_65421;
}
L_65421:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x65421;if(!sl_tick(c))return int(c.fault);
P_65421_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65421_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_65421_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65421_3:;
goto L_65429;
}
L_65429:{ // LEA EAX,[EBP + 0xffffff38]
c.pc=0x65429;if(!sl_tick(c))return int(c.fault);
P_65429_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff38ULL)),c);
P_65429_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_65429_2:;
goto L_6542f;
}
L_6542f:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x6542f;if(!sl_tick(c))return int(c.fault);
P_6542f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_6542f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6542f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6542f_3:;
goto L_65433;
}
L_65433:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x65433;if(!sl_tick(c))return int(c.fault);
P_65433_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_65433_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65433_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65433_3:;
goto L_65439;
}
L_65439:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x65439;if(!sl_tick(c))return int(c.fault);
P_65439_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65439_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65439_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65439_3:;
goto L_6543d;
}
L_6543d:{ // LEA EAX,[EDI + 0xde20]
c.pc=0x6543d;if(!sl_tick(c))return int(c.fault);
P_6543d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xde20ULL)),c);
P_6543d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_6543d_2:;
goto L_65443;
}
L_65443:{ // MOV dword ptr [ESP],EAX
c.pc=0x65443;if(!sl_tick(c))return int(c.fault);
P_65443_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65443_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65443_2:;
goto L_65446;
}
L_65446:{ // CALL 0x00013c66
c.pc=0x65446;if(!sl_tick(c))return int(c.fault);
P_65446_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_65446_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x6544bULL),c);
P_65446_2:;
c.pc=0x13c66;goto dispatch;
P_65446_3:;
goto L_6544b;
}
L_6544b:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x6544b;if(!sl_tick(c))return int(c.fault);
P_6544b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_6544b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_6544b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_6544b_3:;
goto L_65451;
}
L_65451:{ // ADD EAX,0x8
c.pc=0x65451;if(!sl_tick(c))return int(c.fault);
P_65451_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65451_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65451_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65451_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65451_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65451_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65451_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65451_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65451_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65451_9:;
goto L_65454;
}
L_65454:{ // MOV dword ptr [EBP + 0xffffff38],EAX
c.pc=0x65454;if(!sl_tick(c))return int(c.fault);
P_65454_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff38ULL)),c);
P_65454_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65454_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65454_3:;
goto L_6545a;
}
L_6545a:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x6545a;if(!sl_tick(c))return int(c.fault);
P_6545a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_6545a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_6545a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_6545a_3:;
goto L_65460;
}
L_65460:{ // ADD EAX,0x8
c.pc=0x65460;if(!sl_tick(c))return int(c.fault);
P_65460_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65460_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65460_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65460_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65460_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65460_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65460_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65460_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65460_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65460_9:;
goto L_65463;
}
L_65463:{ // MOV dword ptr [EBP + 0xffffff48],EAX
c.pc=0x65463;if(!sl_tick(c))return int(c.fault);
P_65463_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff48ULL)),c);
P_65463_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65463_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65463_3:;
goto L_65469;
}
L_65469:{ // MOV byte ptr [EBP + 0xffffff4c],0x0
c.pc=0x65469;if(!sl_tick(c))return int(c.fault);
P_65469_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff4cULL)),c);
P_65469_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_65469_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_65469_3:;
goto L_65470;
}
L_65470:{ // MOV dword ptr [EBP + 0xffffff50],0x3c
c.pc=0x65470;if(!sl_tick(c))return int(c.fault);
P_65470_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff50ULL)),c);
P_65470_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_65470_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65470_3:;
goto L_6547a;
}
L_6547a:{ // MOV dword ptr [EBP + 0xffffff54],0x64
c.pc=0x6547a;if(!sl_tick(c))return int(c.fault);
P_6547a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff54ULL)),c);
P_6547a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_6547a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_6547a_3:;
goto L_65484;
}
L_65484:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x65484;if(!sl_tick(c))return int(c.fault);
P_65484_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65484_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_65484_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65484_3:;
goto L_6548c;
}
L_6548c:{ // LEA EAX,[EBP + 0xffffff48]
c.pc=0x6548c;if(!sl_tick(c))return int(c.fault);
P_6548c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff48ULL)),c);
P_6548c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_6548c_2:;
goto L_65492;
}
L_65492:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x65492;if(!sl_tick(c))return int(c.fault);
P_65492_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65492_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65492_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65492_3:;
goto L_65496;
}
L_65496:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x65496;if(!sl_tick(c))return int(c.fault);
P_65496_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_65496_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65496_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65496_3:;
goto L_6549c;
}
L_6549c:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x6549c;if(!sl_tick(c))return int(c.fault);
P_6549c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_6549c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6549c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6549c_3:;
goto L_654a0;
}
L_654a0:{ // LEA EAX,[EDI + 0x13b58]
c.pc=0x654a0;if(!sl_tick(c))return int(c.fault);
P_654a0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x13b58ULL)),c);
P_654a0_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_654a0_2:;
goto L_654a6;
}
L_654a6:{ // MOV dword ptr [ESP],EAX
c.pc=0x654a6;if(!sl_tick(c))return int(c.fault);
P_654a6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_654a6_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_654a6_2:;
goto L_654a9;
}
L_654a9:{ // CALL 0x00013c66
c.pc=0x654a9;if(!sl_tick(c))return int(c.fault);
P_654a9_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_654a9_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x654aeULL),c);
P_654a9_2:;
c.pc=0x13c66;goto dispatch;
P_654a9_3:;
goto L_654ae;
}
L_654ae:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x654ae;if(!sl_tick(c))return int(c.fault);
P_654ae_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_654ae_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_654ae_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_654ae_3:;
goto L_654b4;
}
L_654b4:{ // ADD EAX,0x8
c.pc=0x654b4;if(!sl_tick(c))return int(c.fault);
P_654b4_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_654b4_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_654b4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_654b4_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_654b4_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_654b4_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_654b4_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_654b4_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_654b4_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_654b4_9:;
goto L_654b7;
}
L_654b7:{ // MOV dword ptr [EBP + 0xffffff48],EAX
c.pc=0x654b7;if(!sl_tick(c))return int(c.fault);
P_654b7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff48ULL)),c);
P_654b7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_654b7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_654b7_3:;
goto L_654bd;
}
L_654bd:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x654bd;if(!sl_tick(c))return int(c.fault);
P_654bd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_654bd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_654bd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_654bd_3:;
goto L_654c3;
}
L_654c3:{ // ADD EAX,0x8
c.pc=0x654c3;if(!sl_tick(c))return int(c.fault);
P_654c3_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_654c3_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_654c3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_654c3_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_654c3_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_654c3_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_654c3_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_654c3_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_654c3_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_654c3_9:;
goto L_654c6;
}
L_654c6:{ // MOV dword ptr [EBP + 0xffffff58],EAX
c.pc=0x654c6;if(!sl_tick(c))return int(c.fault);
P_654c6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff58ULL)),c);
P_654c6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_654c6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_654c6_3:;
goto L_654cc;
}
L_654cc:{ // MOV byte ptr [EBP + 0xffffff5c],0x0
c.pc=0x654cc;if(!sl_tick(c))return int(c.fault);
P_654cc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff5cULL)),c);
P_654cc_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_654cc_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_654cc_3:;
goto L_654d3;
}
L_654d3:{ // MOV dword ptr [EBP + 0xffffff60],0x3c
c.pc=0x654d3;if(!sl_tick(c))return int(c.fault);
P_654d3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff60ULL)),c);
P_654d3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_654d3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_654d3_3:;
goto L_654dd;
}
L_654dd:{ // MOV dword ptr [EBP + 0xffffff64],0x64
c.pc=0x654dd;if(!sl_tick(c))return int(c.fault);
P_654dd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff64ULL)),c);
P_654dd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_654dd_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_654dd_3:;
goto L_654e7;
}
L_654e7:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x654e7;if(!sl_tick(c))return int(c.fault);
P_654e7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_654e7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_654e7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_654e7_3:;
goto L_654ef;
}
L_654ef:{ // LEA EAX,[EBP + 0xffffff58]
c.pc=0x654ef;if(!sl_tick(c))return int(c.fault);
P_654ef_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff58ULL)),c);
P_654ef_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_654ef_2:;
goto L_654f5;
}
L_654f5:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x654f5;if(!sl_tick(c))return int(c.fault);
P_654f5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_654f5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_654f5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_654f5_3:;
goto L_654f9;
}
L_654f9:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x654f9;if(!sl_tick(c))return int(c.fault);
P_654f9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_654f9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_654f9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_654f9_3:;
goto L_654ff;
}
L_654ff:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x654ff;if(!sl_tick(c))return int(c.fault);
P_654ff_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_654ff_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_654ff_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_654ff_3:;
goto L_65503;
}
L_65503:{ // LEA EAX,[EDI + 0x8660]
c.pc=0x65503;if(!sl_tick(c))return int(c.fault);
P_65503_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x8660ULL)),c);
P_65503_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_65503_2:;
goto L_65509;
}
L_65509:{ // MOV dword ptr [ESP],EAX
c.pc=0x65509;if(!sl_tick(c))return int(c.fault);
P_65509_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65509_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65509_2:;
goto L_6550c;
}
L_6550c:{ // CALL 0x00043ece
c.pc=0x6550c;if(!sl_tick(c))return int(c.fault);
P_6550c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_6550c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x65511ULL),c);
P_6550c_2:;
c.pc=0x43ece;goto dispatch;
P_6550c_3:;
goto L_65511;
}
L_65511:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65511;if(!sl_tick(c))return int(c.fault);
P_65511_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65511_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65511_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65511_3:;
goto L_65517;
}
L_65517:{ // ADD EAX,0x8
c.pc=0x65517;if(!sl_tick(c))return int(c.fault);
P_65517_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65517_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65517_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65517_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65517_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65517_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65517_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65517_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65517_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65517_9:;
goto L_6551a;
}
L_6551a:{ // MOV dword ptr [EBP + 0xffffff58],EAX
c.pc=0x6551a;if(!sl_tick(c))return int(c.fault);
P_6551a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff58ULL)),c);
P_6551a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6551a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6551a_3:;
goto L_65520;
}
L_65520:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65520;if(!sl_tick(c))return int(c.fault);
P_65520_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65520_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65520_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65520_3:;
goto L_65526;
}
L_65526:{ // ADD EAX,0x8
c.pc=0x65526;if(!sl_tick(c))return int(c.fault);
P_65526_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65526_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65526_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65526_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65526_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65526_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65526_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65526_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65526_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65526_9:;
goto L_65529;
}
L_65529:{ // MOV dword ptr [EBP + 0xffffff68],EAX
c.pc=0x65529;if(!sl_tick(c))return int(c.fault);
P_65529_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff68ULL)),c);
P_65529_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65529_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65529_3:;
goto L_6552f;
}
L_6552f:{ // MOV byte ptr [EBP + 0xffffff6c],0x0
c.pc=0x6552f;if(!sl_tick(c))return int(c.fault);
P_6552f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff6cULL)),c);
P_6552f_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_6552f_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_6552f_3:;
goto L_65536;
}
L_65536:{ // MOV dword ptr [EBP + 0xffffff70],0x3c
c.pc=0x65536;if(!sl_tick(c))return int(c.fault);
P_65536_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff70ULL)),c);
P_65536_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_65536_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65536_3:;
goto L_65540;
}
L_65540:{ // MOV dword ptr [EBP + 0xffffff74],0x64
c.pc=0x65540;if(!sl_tick(c))return int(c.fault);
P_65540_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff74ULL)),c);
P_65540_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_65540_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65540_3:;
goto L_6554a;
}
L_6554a:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x6554a;if(!sl_tick(c))return int(c.fault);
P_6554a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_6554a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_6554a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_6554a_3:;
goto L_65552;
}
L_65552:{ // LEA EAX,[EBP + 0xffffff68]
c.pc=0x65552;if(!sl_tick(c))return int(c.fault);
P_65552_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff68ULL)),c);
P_65552_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_65552_2:;
goto L_65558;
}
L_65558:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x65558;if(!sl_tick(c))return int(c.fault);
P_65558_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65558_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65558_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65558_3:;
goto L_6555c;
}
L_6555c:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x6555c;if(!sl_tick(c))return int(c.fault);
P_6555c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_6555c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_6555c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_6555c_3:;
goto L_65562;
}
L_65562:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x65562;if(!sl_tick(c))return int(c.fault);
P_65562_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65562_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65562_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65562_3:;
goto L_65566;
}
L_65566:{ // LEA EAX,[EDI + 0xe398]
c.pc=0x65566;if(!sl_tick(c))return int(c.fault);
P_65566_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xe398ULL)),c);
P_65566_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_65566_2:;
goto L_6556c;
}
L_6556c:{ // MOV dword ptr [ESP],EAX
c.pc=0x6556c;if(!sl_tick(c))return int(c.fault);
P_6556c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6556c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6556c_2:;
goto L_6556f;
}
L_6556f:{ // CALL 0x00043ece
c.pc=0x6556f;if(!sl_tick(c))return int(c.fault);
P_6556f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_6556f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x65574ULL),c);
P_6556f_2:;
c.pc=0x43ece;goto dispatch;
P_6556f_3:;
goto L_65574;
}
L_65574:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65574;if(!sl_tick(c))return int(c.fault);
P_65574_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65574_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65574_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65574_3:;
goto L_6557a;
}
L_6557a:{ // ADD EAX,0x8
c.pc=0x6557a;if(!sl_tick(c))return int(c.fault);
P_6557a_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_6557a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_6557a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_6557a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_6557a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_6557a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_6557a_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_6557a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_6557a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_6557a_9:;
goto L_6557d;
}
L_6557d:{ // MOV dword ptr [EBP + 0xffffff68],EAX
c.pc=0x6557d;if(!sl_tick(c))return int(c.fault);
P_6557d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff68ULL)),c);
P_6557d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6557d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6557d_3:;
goto L_65583;
}
L_65583:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65583;if(!sl_tick(c))return int(c.fault);
P_65583_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65583_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65583_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65583_3:;
goto L_65589;
}
L_65589:{ // ADD EAX,0x8
c.pc=0x65589;if(!sl_tick(c))return int(c.fault);
P_65589_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65589_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65589_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65589_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65589_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65589_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65589_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65589_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65589_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65589_9:;
goto L_6558c;
}
L_6558c:{ // MOV dword ptr [EBP + 0xffffff78],EAX
c.pc=0x6558c;if(!sl_tick(c))return int(c.fault);
P_6558c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff78ULL)),c);
P_6558c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6558c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6558c_3:;
goto L_65592;
}
L_65592:{ // MOV byte ptr [EBP + 0xffffff7c],0x0
c.pc=0x65592;if(!sl_tick(c))return int(c.fault);
P_65592_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff7cULL)),c);
P_65592_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_65592_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_65592_3:;
goto L_65599;
}
L_65599:{ // MOV dword ptr [EBP + -0x80],0x3c
c.pc=0x65599;if(!sl_tick(c))return int(c.fault);
P_65599_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff80ULL)),c);
P_65599_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_65599_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65599_3:;
goto L_655a0;
}
L_655a0:{ // MOV dword ptr [EBP + -0x7c],0x64
c.pc=0x655a0;if(!sl_tick(c))return int(c.fault);
P_655a0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff84ULL)),c);
P_655a0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_655a0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_655a0_3:;
goto L_655a7;
}
L_655a7:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x655a7;if(!sl_tick(c))return int(c.fault);
P_655a7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_655a7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_655a7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_655a7_3:;
goto L_655af;
}
L_655af:{ // LEA EAX,[EBP + 0xffffff78]
c.pc=0x655af;if(!sl_tick(c))return int(c.fault);
P_655af_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff78ULL)),c);
P_655af_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_655af_2:;
goto L_655b5;
}
L_655b5:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x655b5;if(!sl_tick(c))return int(c.fault);
P_655b5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_655b5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_655b5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_655b5_3:;
goto L_655b9;
}
L_655b9:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x655b9;if(!sl_tick(c))return int(c.fault);
P_655b9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_655b9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_655b9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_655b9_3:;
goto L_655bf;
}
L_655bf:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x655bf;if(!sl_tick(c))return int(c.fault);
P_655bf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_655bf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_655bf_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_655bf_3:;
goto L_655c3;
}
L_655c3:{ // LEA EAX,[EDI + 0x140d0]
c.pc=0x655c3;if(!sl_tick(c))return int(c.fault);
P_655c3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x140d0ULL)),c);
P_655c3_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_655c3_2:;
goto L_655c9;
}
L_655c9:{ // MOV dword ptr [ESP],EAX
c.pc=0x655c9;if(!sl_tick(c))return int(c.fault);
P_655c9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_655c9_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_655c9_2:;
goto L_655cc;
}
L_655cc:{ // CALL 0x00043ece
c.pc=0x655cc;if(!sl_tick(c))return int(c.fault);
P_655cc_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_655cc_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x655d1ULL),c);
P_655cc_2:;
c.pc=0x43ece;goto dispatch;
P_655cc_3:;
goto L_655d1;
}
L_655d1:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x655d1;if(!sl_tick(c))return int(c.fault);
P_655d1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_655d1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_655d1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_655d1_3:;
goto L_655d7;
}
L_655d7:{ // ADD EAX,0x8
c.pc=0x655d7;if(!sl_tick(c))return int(c.fault);
P_655d7_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_655d7_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_655d7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_655d7_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_655d7_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_655d7_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_655d7_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_655d7_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_655d7_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_655d7_9:;
goto L_655da;
}
L_655da:{ // MOV dword ptr [EBP + 0xffffff78],EAX
c.pc=0x655da;if(!sl_tick(c))return int(c.fault);
P_655da_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff78ULL)),c);
P_655da_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_655da_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_655da_3:;
goto L_655e0;
}
L_655e0:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x655e0;if(!sl_tick(c))return int(c.fault);
P_655e0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_655e0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_655e0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_655e0_3:;
goto L_655e6;
}
L_655e6:{ // ADD EAX,0x8
c.pc=0x655e6;if(!sl_tick(c))return int(c.fault);
P_655e6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_655e6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_655e6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_655e6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_655e6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_655e6_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_655e6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_655e6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_655e6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_655e6_9:;
goto L_655e9;
}
L_655e9:{ // MOV dword ptr [EBP + -0x78],EAX
c.pc=0x655e9;if(!sl_tick(c))return int(c.fault);
P_655e9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff88ULL)),c);
P_655e9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_655e9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_655e9_3:;
goto L_655ec;
}
L_655ec:{ // MOV byte ptr [EBP + -0x74],0x0
c.pc=0x655ec;if(!sl_tick(c))return int(c.fault);
P_655ec_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff8cULL)),c);
P_655ec_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_655ec_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_655ec_3:;
goto L_655f0;
}
L_655f0:{ // MOV dword ptr [EBP + -0x70],0x3c
c.pc=0x655f0;if(!sl_tick(c))return int(c.fault);
P_655f0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff90ULL)),c);
P_655f0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_655f0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_655f0_3:;
goto L_655f7;
}
L_655f7:{ // MOV dword ptr [EBP + -0x6c],0x64
c.pc=0x655f7;if(!sl_tick(c))return int(c.fault);
P_655f7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff94ULL)),c);
P_655f7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_655f7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_655f7_3:;
goto L_655fe;
}
L_655fe:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x655fe;if(!sl_tick(c))return int(c.fault);
P_655fe_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_655fe_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_655fe_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_655fe_3:;
goto L_65606;
}
L_65606:{ // LEA EAX,[EBP + -0x78]
c.pc=0x65606;if(!sl_tick(c))return int(c.fault);
P_65606_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff88ULL)),c);
P_65606_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_65606_2:;
goto L_65609;
}
L_65609:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x65609;if(!sl_tick(c))return int(c.fault);
P_65609_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65609_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65609_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65609_3:;
goto L_6560d;
}
L_6560d:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x6560d;if(!sl_tick(c))return int(c.fault);
P_6560d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_6560d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_6560d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_6560d_3:;
goto L_65613;
}
L_65613:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x65613;if(!sl_tick(c))return int(c.fault);
P_65613_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65613_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65613_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65613_3:;
goto L_65617;
}
L_65617:{ // LEA EAX,[EDI + 0x14998]
c.pc=0x65617;if(!sl_tick(c))return int(c.fault);
P_65617_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x14998ULL)),c);
P_65617_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_65617_2:;
goto L_6561d;
}
L_6561d:{ // MOV dword ptr [ESP],EAX
c.pc=0x6561d;if(!sl_tick(c))return int(c.fault);
P_6561d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6561d_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6561d_2:;
goto L_65620;
}
L_65620:{ // CALL 0x00080022
c.pc=0x65620;if(!sl_tick(c))return int(c.fault);
P_65620_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_65620_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x65625ULL),c);
P_65620_2:;
c.pc=0x80022;goto dispatch;
P_65620_3:;
goto L_65625;
}
L_65625:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65625;if(!sl_tick(c))return int(c.fault);
P_65625_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65625_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65625_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65625_3:;
goto L_6562b;
}
L_6562b:{ // ADD EAX,0x8
c.pc=0x6562b;if(!sl_tick(c))return int(c.fault);
P_6562b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_6562b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_6562b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_6562b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_6562b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_6562b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_6562b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_6562b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_6562b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_6562b_9:;
goto L_6562e;
}
L_6562e:{ // MOV dword ptr [EBP + -0x78],EAX
c.pc=0x6562e;if(!sl_tick(c))return int(c.fault);
P_6562e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff88ULL)),c);
P_6562e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6562e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6562e_3:;
goto L_65631;
}
L_65631:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65631;if(!sl_tick(c))return int(c.fault);
P_65631_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65631_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65631_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65631_3:;
goto L_65637;
}
L_65637:{ // ADD EAX,0x8
c.pc=0x65637;if(!sl_tick(c))return int(c.fault);
P_65637_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65637_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65637_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65637_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65637_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65637_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65637_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65637_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65637_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65637_9:;
goto L_6563a;
}
L_6563a:{ // MOV dword ptr [EBP + -0x68],EAX
c.pc=0x6563a;if(!sl_tick(c))return int(c.fault);
P_6563a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff98ULL)),c);
P_6563a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6563a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6563a_3:;
goto L_6563d;
}
L_6563d:{ // MOV byte ptr [EBP + -0x64],0x0
c.pc=0x6563d;if(!sl_tick(c))return int(c.fault);
P_6563d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff9cULL)),c);
P_6563d_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_6563d_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_6563d_3:;
goto L_65641;
}
L_65641:{ // MOV dword ptr [EBP + -0x60],0x3c
c.pc=0x65641;if(!sl_tick(c))return int(c.fault);
P_65641_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffa0ULL)),c);
P_65641_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_65641_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65641_3:;
goto L_65648;
}
L_65648:{ // MOV dword ptr [EBP + -0x5c],0x64
c.pc=0x65648;if(!sl_tick(c))return int(c.fault);
P_65648_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffa4ULL)),c);
P_65648_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_65648_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65648_3:;
goto L_6564f;
}
L_6564f:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x6564f;if(!sl_tick(c))return int(c.fault);
P_6564f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_6564f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_6564f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_6564f_3:;
goto L_65657;
}
L_65657:{ // LEA EAX,[EBP + -0x68]
c.pc=0x65657;if(!sl_tick(c))return int(c.fault);
P_65657_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff98ULL)),c);
P_65657_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_65657_2:;
goto L_6565a;
}
L_6565a:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x6565a;if(!sl_tick(c))return int(c.fault);
P_6565a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_6565a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6565a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6565a_3:;
goto L_6565e;
}
L_6565e:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x6565e;if(!sl_tick(c))return int(c.fault);
P_6565e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_6565e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_6565e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_6565e_3:;
goto L_65664;
}
L_65664:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x65664;if(!sl_tick(c))return int(c.fault);
P_65664_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65664_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65664_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65664_3:;
goto L_65668;
}
L_65668:{ // LEA EAX,[EDI + 0x14bac]
c.pc=0x65668;if(!sl_tick(c))return int(c.fault);
P_65668_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x14bacULL)),c);
P_65668_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_65668_2:;
goto L_6566e;
}
L_6566e:{ // MOV dword ptr [ESP],EAX
c.pc=0x6566e;if(!sl_tick(c))return int(c.fault);
P_6566e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6566e_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6566e_2:;
goto L_65671;
}
L_65671:{ // CALL 0x00080022
c.pc=0x65671;if(!sl_tick(c))return int(c.fault);
P_65671_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_65671_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x65676ULL),c);
P_65671_2:;
c.pc=0x80022;goto dispatch;
P_65671_3:;
goto L_65676;
}
L_65676:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65676;if(!sl_tick(c))return int(c.fault);
P_65676_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65676_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65676_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65676_3:;
goto L_6567c;
}
L_6567c:{ // ADD EAX,0x8
c.pc=0x6567c;if(!sl_tick(c))return int(c.fault);
P_6567c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_6567c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_6567c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_6567c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_6567c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_6567c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_6567c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_6567c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_6567c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_6567c_9:;
goto L_6567f;
}
L_6567f:{ // MOV dword ptr [EBP + -0x68],EAX
c.pc=0x6567f;if(!sl_tick(c))return int(c.fault);
P_6567f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffff98ULL)),c);
P_6567f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6567f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6567f_3:;
goto L_65682;
}
L_65682:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65682;if(!sl_tick(c))return int(c.fault);
P_65682_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65682_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65682_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65682_3:;
goto L_65688;
}
L_65688:{ // ADD EAX,0x8
c.pc=0x65688;if(!sl_tick(c))return int(c.fault);
P_65688_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_65688_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_65688_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_65688_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_65688_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_65688_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_65688_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_65688_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_65688_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_65688_9:;
goto L_6568b;
}
L_6568b:{ // MOV dword ptr [EBP + -0x58],EAX
c.pc=0x6568b;if(!sl_tick(c))return int(c.fault);
P_6568b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffa8ULL)),c);
P_6568b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_6568b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_6568b_3:;
goto L_6568e;
}
L_6568e:{ // MOV byte ptr [EBP + -0x54],0x0
c.pc=0x6568e;if(!sl_tick(c))return int(c.fault);
P_6568e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffacULL)),c);
P_6568e_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_6568e_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_6568e_3:;
goto L_65692;
}
L_65692:{ // MOV dword ptr [EBP + -0x50],0x3c
c.pc=0x65692;if(!sl_tick(c))return int(c.fault);
P_65692_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffb0ULL)),c);
P_65692_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_65692_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65692_3:;
goto L_65699;
}
L_65699:{ // MOV dword ptr [EBP + -0x4c],0x64
c.pc=0x65699;if(!sl_tick(c))return int(c.fault);
P_65699_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffb4ULL)),c);
P_65699_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_65699_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_65699_3:;
goto L_656a0;
}
L_656a0:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x656a0;if(!sl_tick(c))return int(c.fault);
P_656a0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_656a0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_656a0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_656a0_3:;
goto L_656a8;
}
L_656a8:{ // LEA EAX,[EBP + -0x58]
c.pc=0x656a8;if(!sl_tick(c))return int(c.fault);
P_656a8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffa8ULL)),c);
P_656a8_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_656a8_2:;
goto L_656ab;
}
L_656ab:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x656ab;if(!sl_tick(c))return int(c.fault);
P_656ab_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_656ab_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_656ab_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_656ab_3:;
goto L_656af;
}
L_656af:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x656af;if(!sl_tick(c))return int(c.fault);
P_656af_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_656af_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_656af_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_656af_3:;
goto L_656b5;
}
L_656b5:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x656b5;if(!sl_tick(c))return int(c.fault);
P_656b5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_656b5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_656b5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_656b5_3:;
goto L_656b9;
}
L_656b9:{ // LEA EAX,[EDI + 0x14dc0]
c.pc=0x656b9;if(!sl_tick(c))return int(c.fault);
P_656b9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x14dc0ULL)),c);
P_656b9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_656b9_2:;
goto L_656bf;
}
L_656bf:{ // MOV dword ptr [ESP],EAX
c.pc=0x656bf;if(!sl_tick(c))return int(c.fault);
P_656bf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_656bf_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_656bf_2:;
goto L_656c2;
}
L_656c2:{ // CALL 0x00080022
c.pc=0x656c2;if(!sl_tick(c))return int(c.fault);
P_656c2_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_656c2_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x656c7ULL),c);
P_656c2_2:;
c.pc=0x80022;goto dispatch;
P_656c2_3:;
goto L_656c7;
}
L_656c7:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x656c7;if(!sl_tick(c))return int(c.fault);
P_656c7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_656c7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_656c7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_656c7_3:;
goto L_656cd;
}
L_656cd:{ // ADD EAX,0x8
c.pc=0x656cd;if(!sl_tick(c))return int(c.fault);
P_656cd_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_656cd_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_656cd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_656cd_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_656cd_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_656cd_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_656cd_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_656cd_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_656cd_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_656cd_9:;
goto L_656d0;
}
L_656d0:{ // MOV dword ptr [EBP + -0x58],EAX
c.pc=0x656d0;if(!sl_tick(c))return int(c.fault);
P_656d0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffa8ULL)),c);
P_656d0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_656d0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_656d0_3:;
goto L_656d3;
}
L_656d3:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x656d3;if(!sl_tick(c))return int(c.fault);
P_656d3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_656d3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_656d3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_656d3_3:;
goto L_656d9;
}
L_656d9:{ // ADD EAX,0x8
c.pc=0x656d9;if(!sl_tick(c))return int(c.fault);
P_656d9_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_656d9_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_656d9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_656d9_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_656d9_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_656d9_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_656d9_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_656d9_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_656d9_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_656d9_9:;
goto L_656dc;
}
L_656dc:{ // MOV dword ptr [EBP + -0x48],EAX
c.pc=0x656dc;if(!sl_tick(c))return int(c.fault);
P_656dc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffb8ULL)),c);
P_656dc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_656dc_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_656dc_3:;
goto L_656df;
}
L_656df:{ // MOV byte ptr [EBP + -0x44],0x0
c.pc=0x656df;if(!sl_tick(c))return int(c.fault);
P_656df_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffbcULL)),c);
P_656df_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_656df_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_656df_3:;
goto L_656e3;
}
L_656e3:{ // MOV dword ptr [EBP + -0x40],0x3c
c.pc=0x656e3;if(!sl_tick(c))return int(c.fault);
P_656e3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc0ULL)),c);
P_656e3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x3cULL),c);
P_656e3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_656e3_3:;
goto L_656ea;
}
L_656ea:{ // MOV dword ptr [EBP + -0x3c],0x64
c.pc=0x656ea;if(!sl_tick(c))return int(c.fault);
P_656ea_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc4ULL)),c);
P_656ea_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x64ULL),c);
P_656ea_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_656ea_3:;
goto L_656f1;
}
L_656f1:{ // MOV dword ptr [ESP + 0xc],0x0
c.pc=0x656f1;if(!sl_tick(c))return int(c.fault);
P_656f1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_656f1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_656f1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_656f1_3:;
goto L_656f9;
}
L_656f9:{ // LEA EAX,[EBP + -0x48]
c.pc=0x656f9;if(!sl_tick(c))return int(c.fault);
P_656f9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffb8ULL)),c);
P_656f9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_656f9_2:;
goto L_656fc;
}
L_656fc:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x656fc;if(!sl_tick(c))return int(c.fault);
P_656fc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_656fc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_656fc_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_656fc_3:;
goto L_65700;
}
L_65700:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0x65700;if(!sl_tick(c))return int(c.fault);
P_65700_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_65700_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65700_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65700_3:;
goto L_65706;
}
L_65706:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x65706;if(!sl_tick(c))return int(c.fault);
P_65706_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_65706_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65706_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65706_3:;
goto L_6570a;
}
L_6570a:{ // LEA EAX,[EDI + 0x8ce8]
c.pc=0x6570a;if(!sl_tick(c))return int(c.fault);
P_6570a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x8ce8ULL)),c);
P_6570a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_6570a_2:;
goto L_65710;
}
L_65710:{ // MOV dword ptr [ESP],EAX
c.pc=0x65710;if(!sl_tick(c))return int(c.fault);
P_65710_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65710_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65710_2:;
goto L_65713;
}
L_65713:{ // CALL 0x00013c66
c.pc=0x65713;if(!sl_tick(c))return int(c.fault);
P_65713_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_65713_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x65718ULL),c);
P_65713_2:;
c.pc=0x13c66;goto dispatch;
P_65713_3:;
goto L_65718;
}
L_65718:{ // MOV EAX,dword ptr [EBX + 0x9ef19]
c.pc=0x65718;if(!sl_tick(c))return int(c.fault);
P_65718_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9ef19ULL)),c);
P_65718_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_65718_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_65718_3:;
goto L_6571e;
}
L_6571e:{ // ADD EAX,0x8
c.pc=0x6571e;if(!sl_tick(c))return int(c.fault);
P_6571e_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_6571e_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_6571e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_6571e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_6571e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_6571e_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_6571e_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_6571e_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_6571e_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_6571e_9:;
goto L_65721;
}
L_65721:{ // MOV dword ptr [EBP + -0x48],EAX
c.pc=0x65721;if(!sl_tick(c))return int(c.fault);
P_65721_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffb8ULL)),c);
P_65721_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_65721_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_65721_3:;
c.pc=0x65724;goto dispatch;
}
}
