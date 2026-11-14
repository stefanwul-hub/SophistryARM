// Generated static p-code lift; original i386 SHA-256: 17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12
#include "LifterRuntime.h"
int sl_unit_0000(SlCpu& c){
goto dispatch;
dispatch:
if(c.fault||c.pc==c.stop)return int(c.fault);
switch(c.pc){
case 0xe0c:goto L_e0c;
case 0xe0d:goto L_e0d;
case 0xe0f:goto L_e0f;
case 0xe12:goto L_e12;
case 0xe15:goto L_e15;
case 0xe1b:goto L_e1b;
case 0xe1c:goto L_e1c;
case 0xe1d:goto L_e1d;
case 0xe1e:goto L_e1e;
case 0xe20:goto L_e20;
case 0xe21:goto L_e21;
case 0xe24:goto L_e24;
case 0xe29:goto L_e29;
case 0xe2c:goto L_e2c;
case 0xe2f:goto L_e2f;
case 0xe32:goto L_e32;
case 0xe35:goto L_e35;
case 0xe38:goto L_e38;
case 0xe3c:goto L_e3c;
case 0xe3f:goto L_e3f;
case 0xe43:goto L_e43;
case 0xe49:goto L_e49;
case 0xe4c:goto L_e4c;
case 0xe4e:goto L_e4e;
case 0xe50:goto L_e50;
case 0xe52:goto L_e52;
case 0xe55:goto L_e55;
case 0xe5b:goto L_e5b;
case 0xe5e:goto L_e5e;
case 0xe5f:goto L_e5f;
case 0xe60:goto L_e60;
case 0xe61:goto L_e61;
case 0xe62:goto L_e62;
case 0xe64:goto L_e64;
case 0xe65:goto L_e65;
case 0xe68:goto L_e68;
case 0xe6d:goto L_e6d;
case 0xe74:goto L_e74;
case 0xe77:goto L_e77;
case 0xe7a:goto L_e7a;
case 0xe7d:goto L_e7d;
case 0xe81:goto L_e81;
case 0xe84:goto L_e84;
case 0xe88:goto L_e88;
case 0xe8e:goto L_e8e;
case 0xe91:goto L_e91;
case 0xe94:goto L_e94;
case 0xe96:goto L_e96;
case 0xe98:goto L_e98;
case 0xe9a:goto L_e9a;
case 0xea1:goto L_ea1;
case 0xea3:goto L_ea3;
case 0xea6:goto L_ea6;
case 0xea9:goto L_ea9;
case 0xeac:goto L_eac;
case 0xeae:goto L_eae;
case 0xeb1:goto L_eb1;
case 0xeb3:goto L_eb3;
case 0xeb5:goto L_eb5;
case 0xeb8:goto L_eb8;
case 0xebb:goto L_ebb;
case 0xebe:goto L_ebe;
case 0xec0:goto L_ec0;
case 0xec7:goto L_ec7;
case 0xeca:goto L_eca;
case 0xecd:goto L_ecd;
case 0xed0:goto L_ed0;
case 0xed3:goto L_ed3;
case 0xed4:goto L_ed4;
case 0xed5:goto L_ed5;
case 0xed6:goto L_ed6;
case 0xed7:goto L_ed7;
case 0xed9:goto L_ed9;
case 0xeda:goto L_eda;
case 0xedd:goto L_edd;
case 0xee2:goto L_ee2;
case 0xee5:goto L_ee5;
case 0xee9:goto L_ee9;
case 0xef0:goto L_ef0;
case 0xef5:goto L_ef5;
case 0xef7:goto L_ef7;
case 0xef9:goto L_ef9;
case 0xf00:goto L_f00;
case 0xf05:goto L_f05;
case 0xf08:goto L_f08;
case 0xf0b:goto L_f0b;
case 0xf0f:goto L_f0f;
case 0xf11:goto L_f11;
case 0xf19:goto L_f19;
case 0xf20:goto L_f20;
case 0xf25:goto L_f25;
case 0xf28:goto L_f28;
case 0xf2c:goto L_f2c;
case 0xf2e:goto L_f2e;
case 0xf35:goto L_f35;
case 0xf3a:goto L_f3a;
case 0xf3d:goto L_f3d;
case 0xf41:goto L_f41;
case 0xf43:goto L_f43;
case 0xf49:goto L_f49;
case 0xf51:goto L_f51;
case 0xf57:goto L_f57;
case 0xf5a:goto L_f5a;
case 0xf5f:goto L_f5f;
case 0xf62:goto L_f62;
case 0xf66:goto L_f66;
case 0xf6c:goto L_f6c;
case 0xf72:goto L_f72;
case 0xf76:goto L_f76;
case 0xf79:goto L_f79;
case 0xf7c:goto L_f7c;
case 0xf81:goto L_f81;
case 0xf83:goto L_f83;
case 0xf86:goto L_f86;
case 0xf89:goto L_f89;
case 0xf8f:goto L_f8f;
case 0xf93:goto L_f93;
case 0xf96:goto L_f96;
case 0xf99:goto L_f99;
case 0xf9e:goto L_f9e;
case 0xfa0:goto L_fa0;
case 0xfa3:goto L_fa3;
case 0xfa6:goto L_fa6;
case 0xfa9:goto L_fa9;
case 0xfac:goto L_fac;
case 0xfae:goto L_fae;
case 0xfb0:goto L_fb0;
case 0xfb3:goto L_fb3;
case 0xfb6:goto L_fb6;
case 0xfb8:goto L_fb8;
case 0xfba:goto L_fba;
case 0xfbd:goto L_fbd;
case 0xfc0:goto L_fc0;
case 0xfc3:goto L_fc3;
case 0xfc6:goto L_fc6;
case 0xfca:goto L_fca;
case 0xfcd:goto L_fcd;
case 0xfd2:goto L_fd2;
case 0xfd5:goto L_fd5;
case 0xfd9:goto L_fd9;
case 0xfdb:goto L_fdb;
case 0xfdf:goto L_fdf;
case 0xfe1:goto L_fe1;
case 0xfe4:goto L_fe4;
case 0xfe8:goto L_fe8;
case 0xfea:goto L_fea;
case 0xff0:goto L_ff0;
case 0xff4:goto L_ff4;
case 0xff7:goto L_ff7;
case 0xffa:goto L_ffa;
case 0xfff:goto L_fff;
case 0x1001:goto L_1001;
case 0x1004:goto L_1004;
case 0x1007:goto L_1007;
case 0x100a:goto L_100a;
case 0x100d:goto L_100d;
case 0x100f:goto L_100f;
case 0x1011:goto L_1011;
case 0x1014:goto L_1014;
case 0x1018:goto L_1018;
case 0x101b:goto L_101b;
case 0x101e:goto L_101e;
case 0x1020:goto L_1020;
case 0x1023:goto L_1023;
case 0x1027:goto L_1027;
case 0x102e:goto L_102e;
case 0x1033:goto L_1033;
case 0x103a:goto L_103a;
case 0x103d:goto L_103d;
case 0x1040:goto L_1040;
case 0x1041:goto L_1041;
case 0x1042:goto L_1042;
case 0x1043:goto L_1043;
case 0x1044:goto L_1044;
case 0x1046:goto L_1046;
case 0x1049:goto L_1049;
case 0x1050:goto L_1050;
case 0x1055:goto L_1055;
case 0x1058:goto L_1058;
case 0x105c:goto L_105c;
case 0x105e:goto L_105e;
case 0x1061:goto L_1061;
case 0x1065:goto L_1065;
case 0x106c:goto L_106c;
case 0x1071:goto L_1071;
case 0x1078:goto L_1078;
case 0x107a:goto L_107a;
case 0x107d:goto L_107d;
case 0x1080:goto L_1080;
case 0x1082:goto L_1082;
case 0x1085:goto L_1085;
case 0x1088:goto L_1088;
case 0x108b:goto L_108b;
case 0x108e:goto L_108e;
case 0x1091:goto L_1091;
case 0x1094:goto L_1094;
case 0x1097:goto L_1097;
case 0x109a:goto L_109a;
case 0x109c:goto L_109c;
case 0x109f:goto L_109f;
case 0x10a2:goto L_10a2;
case 0x10a5:goto L_10a5;
case 0x10a8:goto L_10a8;
case 0x10ac:goto L_10ac;
case 0x10b3:goto L_10b3;
case 0x10b8:goto L_10b8;
case 0x10bb:goto L_10bb;
case 0x10bf:goto L_10bf;
case 0x10c1:goto L_10c1;
case 0x10c8:goto L_10c8;
case 0x10ca:goto L_10ca;
case 0x10d1:goto L_10d1;
case 0x10d4:goto L_10d4;
case 0x10d7:goto L_10d7;
case 0x10da:goto L_10da;
case 0x10db:goto L_10db;
case 0x10dc:goto L_10dc;
case 0x10dd:goto L_10dd;
case 0x10df:goto L_10df;
case 0x10e2:goto L_10e2;
case 0x10e5:goto L_10e5;
case 0x10e8:goto L_10e8;
case 0x10eb:goto L_10eb;
case 0x10ef:goto L_10ef;
case 0x10f5:goto L_10f5;
case 0x10f8:goto L_10f8;
case 0x10fb:goto L_10fb;
case 0x1101:goto L_1101;
case 0x1104:goto L_1104;
case 0x1106:goto L_1106;
case 0x1109:goto L_1109;
case 0x110c:goto L_110c;
case 0x110f:goto L_110f;
case 0x1113:goto L_1113;
case 0x111a:goto L_111a;
case 0x111f:goto L_111f;
case 0x1122:goto L_1122;
case 0x1125:goto L_1125;
case 0x1128:goto L_1128;
case 0x112c:goto L_112c;
case 0x112e:goto L_112e;
case 0x1133:goto L_1133;
case 0x1135:goto L_1135;
case 0x1139:goto L_1139;
case 0x113b:goto L_113b;
case 0x113e:goto L_113e;
case 0x1141:goto L_1141;
case 0x1144:goto L_1144;
case 0x1146:goto L_1146;
case 0x1148:goto L_1148;
case 0x114b:goto L_114b;
case 0x114e:goto L_114e;
case 0x1150:goto L_1150;
case 0x1152:goto L_1152;
case 0x1154:goto L_1154;
case 0x1157:goto L_1157;
case 0x115a:goto L_115a;
case 0x115c:goto L_115c;
case 0x115e:goto L_115e;
case 0x1161:goto L_1161;
case 0x1164:goto L_1164;
case 0x1167:goto L_1167;
case 0x116a:goto L_116a;
case 0x116d:goto L_116d;
case 0x116f:goto L_116f;
case 0x1172:goto L_1172;
case 0x1175:goto L_1175;
case 0x117a:goto L_117a;
case 0x1181:goto L_1181;
case 0x1186:goto L_1186;
case 0x1189:goto L_1189;
case 0x118d:goto L_118d;
case 0x1193:goto L_1193;
case 0x1196:goto L_1196;
case 0x1197:goto L_1197;
case 0x1198:goto L_1198;
case 0x1199:goto L_1199;
case 0x119b:goto L_119b;
case 0x119e:goto L_119e;
case 0x11a1:goto L_11a1;
case 0x11a4:goto L_11a4;
case 0x11ab:goto L_11ab;
case 0x11af:goto L_11af;
case 0x11b6:goto L_11b6;
case 0x11bb:goto L_11bb;
case 0x11be:goto L_11be;
case 0x11c2:goto L_11c2;
case 0x11c4:goto L_11c4;
case 0x11c7:goto L_11c7;
case 0x11cb:goto L_11cb;
case 0x11ce:goto L_11ce;
case 0x11d1:goto L_11d1;
case 0x11d5:goto L_11d5;
case 0x11d8:goto L_11d8;
case 0x11db:goto L_11db;
case 0x11de:goto L_11de;
case 0x11e1:goto L_11e1;
case 0x11e5:goto L_11e5;
case 0x11ec:goto L_11ec;
case 0x11f1:goto L_11f1;
case 0x11f4:goto L_11f4;
case 0x11f7:goto L_11f7;
case 0x11f9:goto L_11f9;
case 0x11fb:goto L_11fb;
case 0x11fe:goto L_11fe;
case 0x1200:goto L_1200;
case 0x1203:goto L_1203;
case 0x1206:goto L_1206;
case 0x1209:goto L_1209;
case 0x120b:goto L_120b;
case 0x120d:goto L_120d;
case 0x1210:goto L_1210;
case 0x1212:goto L_1212;
case 0x1214:goto L_1214;
case 0x1218:goto L_1218;
case 0x121a:goto L_121a;
case 0x1221:goto L_1221;
case 0x1226:goto L_1226;
case 0x1229:goto L_1229;
case 0x122d:goto L_122d;
case 0x122f:goto L_122f;
case 0x1232:goto L_1232;
case 0x1236:goto L_1236;
case 0x1239:goto L_1239;
case 0x123c:goto L_123c;
case 0x1241:goto L_1241;
case 0x1244:goto L_1244;
case 0x1248:goto L_1248;
case 0x124a:goto L_124a;
case 0x124d:goto L_124d;
case 0x1251:goto L_1251;
case 0x1254:goto L_1254;
case 0x1257:goto L_1257;
case 0x125b:goto L_125b;
case 0x1262:goto L_1262;
case 0x1267:goto L_1267;
case 0x1268:goto L_1268;
case 0x1269:goto L_1269;
case 0x126a:goto L_126a;
case 0x126c:goto L_126c;
case 0x126d:goto L_126d;
case 0x1270:goto L_1270;
case 0x1275:goto L_1275;
case 0x127a:goto L_127a;
case 0x127d:goto L_127d;
case 0x1281:goto L_1281;
case 0x1283:goto L_1283;
case 0x128a:goto L_128a;
case 0x128f:goto L_128f;
case 0x1292:goto L_1292;
case 0x1296:goto L_1296;
case 0x1298:goto L_1298;
case 0x129a:goto L_129a;
case 0x129d:goto L_129d;
case 0x12a1:goto L_12a1;
case 0x12a3:goto L_12a3;
case 0x12a5:goto L_12a5;
case 0x12a8:goto L_12a8;
case 0x12ac:goto L_12ac;
case 0x12af:goto L_12af;
case 0x12b2:goto L_12b2;
case 0x12b7:goto L_12b7;
case 0x12ba:goto L_12ba;
case 0x12bf:goto L_12bf;
case 0x12c2:goto L_12c2;
case 0x12c6:goto L_12c6;
case 0x12c8:goto L_12c8;
case 0x12ce:goto L_12ce;
case 0x12d1:goto L_12d1;
case 0x12d4:goto L_12d4;
case 0x12d6:goto L_12d6;
case 0x12d8:goto L_12d8;
case 0x12db:goto L_12db;
case 0x12de:goto L_12de;
case 0x12e1:goto L_12e1;
case 0x12e4:goto L_12e4;
case 0x12e8:goto L_12e8;
case 0x12ef:goto L_12ef;
case 0x12f4:goto L_12f4;
case 0x12f7:goto L_12f7;
case 0x12fb:goto L_12fb;
case 0x12fd:goto L_12fd;
case 0x1304:goto L_1304;
case 0x1309:goto L_1309;
case 0x130c:goto L_130c;
case 0x130f:goto L_130f;
case 0x1312:goto L_1312;
case 0x1314:goto L_1314;
case 0x1317:goto L_1317;
case 0x131b:goto L_131b;
case 0x131f:goto L_131f;
case 0x1322:goto L_1322;
case 0x1325:goto L_1325;
case 0x1327:goto L_1327;
case 0x132a:goto L_132a;
case 0x132f:goto L_132f;
case 0x1332:goto L_1332;
case 0x1335:goto L_1335;
case 0x1338:goto L_1338;
case 0x133b:goto L_133b;
case 0x133f:goto L_133f;
case 0x1346:goto L_1346;
case 0x134b:goto L_134b;
case 0x134e:goto L_134e;
case 0x1352:goto L_1352;
case 0x1354:goto L_1354;
case 0x135b:goto L_135b;
case 0x1360:goto L_1360;
case 0x1363:goto L_1363;
case 0x1365:goto L_1365;
case 0x1368:goto L_1368;
case 0x136b:goto L_136b;
case 0x136d:goto L_136d;
case 0x1370:goto L_1370;
case 0x1375:goto L_1375;
case 0x1378:goto L_1378;
case 0x137b:goto L_137b;
case 0x137e:goto L_137e;
case 0x1381:goto L_1381;
case 0x1385:goto L_1385;
case 0x138c:goto L_138c;
case 0x1391:goto L_1391;
case 0x1394:goto L_1394;
case 0x1398:goto L_1398;
case 0x139a:goto L_139a;
case 0x13a1:goto L_13a1;
case 0x13a3:goto L_13a3;
case 0x13aa:goto L_13aa;
case 0x13af:goto L_13af;
case 0x13b2:goto L_13b2;
case 0x13b6:goto L_13b6;
case 0x13b8:goto L_13b8;
case 0x13bf:goto L_13bf;
case 0x13c1:goto L_13c1;
case 0x13c4:goto L_13c4;
case 0x13c7:goto L_13c7;
case 0x13c9:goto L_13c9;
case 0x13cb:goto L_13cb;
case 0x13ce:goto L_13ce;
case 0x13d1:goto L_13d1;
case 0x13d4:goto L_13d4;
case 0x13d7:goto L_13d7;
case 0x13da:goto L_13da;
case 0x13de:goto L_13de;
case 0x13e1:goto L_13e1;
case 0x13e5:goto L_13e5;
case 0x13eb:goto L_13eb;
case 0x13ee:goto L_13ee;
case 0x13f1:goto L_13f1;
case 0x13f3:goto L_13f3;
case 0x13f6:goto L_13f6;
case 0x13f9:goto L_13f9;
case 0x13fc:goto L_13fc;
case 0x13fd:goto L_13fd;
case 0x13fe:goto L_13fe;
case 0x13ff:goto L_13ff;
case 0x1400:goto L_1400;
case 0x1402:goto L_1402;
case 0x1405:goto L_1405;
case 0x1408:goto L_1408;
case 0x140b:goto L_140b;
case 0x1412:goto L_1412;
case 0x1415:goto L_1415;
case 0x1418:goto L_1418;
case 0x141b:goto L_141b;
case 0x141f:goto L_141f;
case 0x1422:goto L_1422;
case 0x1425:goto L_1425;
case 0x142a:goto L_142a;
case 0x142b:goto L_142b;
case 0x142c:goto L_142c;
case 0x142d:goto L_142d;
case 0x142f:goto L_142f;
case 0x1432:goto L_1432;
case 0x1435:goto L_1435;
case 0x143b:goto L_143b;
case 0x143d:goto L_143d;
case 0x143f:goto L_143f;
case 0x1445:goto L_1445;
case 0x1447:goto L_1447;
case 0x144a:goto L_144a;
case 0x144d:goto L_144d;
case 0x1450:goto L_1450;
case 0x1451:goto L_1451;
case 0x1452:goto L_1452;
case 0x1453:goto L_1453;
case 0x1455:goto L_1455;
case 0x1456:goto L_1456;
case 0x1457:goto L_1457;
case 0x1458:goto L_1458;
case 0x145b:goto L_145b;
case 0x1460:goto L_1460;
case 0x1463:goto L_1463;
case 0x1469:goto L_1469;
case 0x146b:goto L_146b;
case 0x1471:goto L_1471;
case 0x1473:goto L_1473;
case 0x1475:goto L_1475;
case 0x1478:goto L_1478;
case 0x147d:goto L_147d;
case 0x1487:goto L_1487;
case 0x148d:goto L_148d;
case 0x1493:goto L_1493;
case 0x1495:goto L_1495;
case 0x1497:goto L_1497;
case 0x1499:goto L_1499;
case 0x149b:goto L_149b;
case 0x149e:goto L_149e;
case 0x14a3:goto L_14a3;
case 0x14ad:goto L_14ad;
case 0x14b3:goto L_14b3;
case 0x14b6:goto L_14b6;
default:return 0;}
L_e0c:{ // PUSH EBP
c.pc=0xe0c;if(!sl_tick(c))return int(c.fault);
P_e0c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_e0c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_e0c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_e0c_3:;
goto L_e0d;
}
L_e0d:{ // MOV EBP,ESP
c.pc=0xe0d;if(!sl_tick(c))return int(c.fault);
P_e0d_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_e0d_1:;
goto L_e0f;
}
L_e0f:{ // SUB ESP,0x8
c.pc=0xe0f;if(!sl_tick(c))return int(c.fault);
P_e0f_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x8ULL)),c);
P_e0f_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x8ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_e0f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x8ULL)),c);
P_e0f_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_e0f_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_e0f_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_e0f_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_e0f_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_e0f_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_e0f_9:;
goto L_e12;
}
L_e12:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0xe12;if(!sl_tick(c))return int(c.fault);
P_e12_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_e12_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_e12_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_e12_3:;
goto L_e15;
}
L_e15:{ // MOV dword ptr [EAX],0x1
c.pc=0xe15;if(!sl_tick(c))return int(c.fault);
P_e15_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x1ULL),c);
P_e15_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_e15_2:;
goto L_e1b;
}
L_e1b:{ // LEAVE
c.pc=0xe1b;if(!sl_tick(c))return int(c.fault);
P_e1b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_e1b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_e1b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_e1b_3:;
goto L_e1c;
}
L_e1c:{ // RET
c.pc=0xe1c;if(!sl_tick(c))return int(c.fault);
P_e1c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_e1c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_e1c_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_e1c_3:;
goto L_e1d;
}
L_e1d:{ // PUSH EBP
c.pc=0xe1d;if(!sl_tick(c))return int(c.fault);
P_e1d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_e1d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_e1d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_e1d_3:;
goto L_e1e;
}
L_e1e:{ // MOV EBP,ESP
c.pc=0xe1e;if(!sl_tick(c))return int(c.fault);
P_e1e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_e1e_1:;
goto L_e20;
}
L_e20:{ // PUSH EBX
c.pc=0xe20;if(!sl_tick(c))return int(c.fault);
P_e20_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_e20_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_e20_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_e20_3:;
goto L_e21;
}
L_e21:{ // SUB ESP,0x24
c.pc=0xe21;if(!sl_tick(c))return int(c.fault);
P_e21_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x24ULL)),c);
P_e21_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x24ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x24ULL)))&(SlU(1)<<31))!=0),c);
P_e21_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x24ULL)),c);
P_e21_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_e21_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_e21_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_e21_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_e21_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_e21_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_e21_9:;
goto L_e24;
}
L_e24:{ // CALL 0x000c086c
c.pc=0xe24;if(!sl_tick(c))return int(c.fault);
P_e24_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_e24_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xe29ULL),c);
P_e24_2:;
c.pc=0xc086c;goto dispatch;
P_e24_3:;
goto L_e29;
}
L_e29:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0xe29;if(!sl_tick(c))return int(c.fault);
P_e29_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_e29_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_e29_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_e29_3:;
goto L_e2c;
}
L_e2c:{ // MOV dword ptr [EBP + -0xc],EAX
c.pc=0xe2c;if(!sl_tick(c))return int(c.fault);
P_e2c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_e2c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_e2c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_e2c_3:;
goto L_e2f;
}
L_e2f:{ // MOV EAX,dword ptr [EBP + -0xc]
c.pc=0xe2f;if(!sl_tick(c))return int(c.fault);
P_e2f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_e2f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_e2f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_e2f_3:;
goto L_e32;
}
L_e32:{ // MOV EDX,dword ptr [EAX + 0x4]
c.pc=0xe32;if(!sl_tick(c))return int(c.fault);
P_e32_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_e32_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_e32_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_e32_3:;
goto L_e35;
}
L_e35:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0xe35;if(!sl_tick(c))return int(c.fault);
P_e35_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_e35_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_e35_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_e35_3:;
goto L_e38;
}
L_e38:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0xe38;if(!sl_tick(c))return int(c.fault);
P_e38_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_e38_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_e38_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_e38_3:;
goto L_e3c;
}
L_e3c:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0xe3c;if(!sl_tick(c))return int(c.fault);
P_e3c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_e3c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_e3c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_e3c_3:;
goto L_e3f;
}
L_e3f:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xe3f;if(!sl_tick(c))return int(c.fault);
P_e3f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_e3f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_e3f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_e3f_3:;
goto L_e43;
}
L_e43:{ // LEA EAX,[EBX + 0xffffffe3]
c.pc=0xe43;if(!sl_tick(c))return int(c.fault);
P_e43_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xffffffe3ULL)),c);
P_e43_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_e43_2:;
goto L_e49;
}
L_e49:{ // MOV dword ptr [ESP],EAX
c.pc=0xe49;if(!sl_tick(c))return int(c.fault);
P_e49_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_e49_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_e49_2:;
goto L_e4c;
}
L_e4c:{ // CALL EDX
c.pc=0xe4c;if(!sl_tick(c))return int(c.fault);
P_e4c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_e4c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_e4c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xe4eULL),c);
P_e4c_3:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_e4c_4:;
goto L_e4e;
}
L_e4e:{ // TEST EAX,EAX
c.pc=0xe4e;if(!sl_tick(c))return int(c.fault);
P_e4e_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_e4e_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_e4e_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_e4e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_e4e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_e4e_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_e4e_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_e4e_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_e4e_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_e4e_9:;
goto L_e50;
}
L_e50:{ // JZ 0x00000e5b
c.pc=0xe50;if(!sl_tick(c))return int(c.fault);
P_e50_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_e5b;}
P_e50_1:;
goto L_e52;
}
L_e52:{ // MOV EAX,dword ptr [EBP + -0xc]
c.pc=0xe52;if(!sl_tick(c))return int(c.fault);
P_e52_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_e52_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_e52_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_e52_3:;
goto L_e55;
}
L_e55:{ // MOV dword ptr [EAX],0xffffffff
c.pc=0xe55;if(!sl_tick(c))return int(c.fault);
P_e55_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xffffffffULL),c);
P_e55_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_e55_2:;
goto L_e5b;
}
L_e5b:{ // ADD ESP,0x24
c.pc=0xe5b;if(!sl_tick(c))return int(c.fault);
P_e5b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x24ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_e5b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x24ULL)))&(SlU(0x24ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x24ULL)))&(SlU(1)<<31))!=0),c);
P_e5b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x24ULL)),c);
P_e5b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_e5b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_e5b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_e5b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_e5b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_e5b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_e5b_9:;
goto L_e5e;
}
L_e5e:{ // POP EBX
c.pc=0xe5e;if(!sl_tick(c))return int(c.fault);
P_e5e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_e5e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_e5e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_e5e_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_e5e_4:;
goto L_e5f;
}
L_e5f:{ // POP EBP
c.pc=0xe5f;if(!sl_tick(c))return int(c.fault);
P_e5f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_e5f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_e5f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_e5f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_e5f_4:;
goto L_e60;
}
L_e60:{ // RET
c.pc=0xe60;if(!sl_tick(c))return int(c.fault);
P_e60_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_e60_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_e60_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_e60_3:;
goto L_e61;
}
L_e61:{ // PUSH EBP
c.pc=0xe61;if(!sl_tick(c))return int(c.fault);
P_e61_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_e61_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_e61_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_e61_3:;
goto L_e62;
}
L_e62:{ // MOV EBP,ESP
c.pc=0xe62;if(!sl_tick(c))return int(c.fault);
P_e62_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_e62_1:;
goto L_e64;
}
L_e64:{ // PUSH EBX
c.pc=0xe64;if(!sl_tick(c))return int(c.fault);
P_e64_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_e64_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_e64_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_e64_3:;
goto L_e65;
}
L_e65:{ // SUB ESP,0x34
c.pc=0xe65;if(!sl_tick(c))return int(c.fault);
P_e65_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x34ULL)),c);
P_e65_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x34ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x34ULL)))&(SlU(1)<<31))!=0),c);
P_e65_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x34ULL)),c);
P_e65_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_e65_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_e65_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_e65_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_e65_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_e65_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_e65_9:;
goto L_e68;
}
L_e68:{ // CALL 0x000c086c
c.pc=0xe68;if(!sl_tick(c))return int(c.fault);
P_e68_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_e68_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xe6dULL),c);
P_e68_2:;
c.pc=0xc086c;goto dispatch;
P_e68_3:;
goto L_e6d;
}
L_e6d:{ // MOV dword ptr [EBP + -0x10],0x0
c.pc=0xe6d;if(!sl_tick(c))return int(c.fault);
P_e6d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_e6d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_e6d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_e6d_3:;
goto L_e74;
}
L_e74:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0xe74;if(!sl_tick(c))return int(c.fault);
P_e74_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_e74_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_e74_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_e74_3:;
goto L_e77;
}
L_e77:{ // MOV dword ptr [EBP + -0xc],EAX
c.pc=0xe77;if(!sl_tick(c))return int(c.fault);
P_e77_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_e77_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_e77_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_e77_3:;
goto L_e7a;
}
L_e7a:{ // LEA EAX,[EBP + -0x10]
c.pc=0xe7a;if(!sl_tick(c))return int(c.fault);
P_e7a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_e7a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_e7a_2:;
goto L_e7d;
}
L_e7d:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0xe7d;if(!sl_tick(c))return int(c.fault);
P_e7d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_e7d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_e7d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_e7d_3:;
goto L_e81;
}
L_e81:{ // LEA EAX,[EBP + -0x10]
c.pc=0xe81;if(!sl_tick(c))return int(c.fault);
P_e81_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_e81_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_e81_2:;
goto L_e84;
}
L_e84:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xe84;if(!sl_tick(c))return int(c.fault);
P_e84_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_e84_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_e84_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_e84_3:;
goto L_e88;
}
L_e88:{ // LEA EAX,[EBX + 0xffffffb0]
c.pc=0xe88;if(!sl_tick(c))return int(c.fault);
P_e88_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xffffffb0ULL)),c);
P_e88_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_e88_2:;
goto L_e8e;
}
L_e8e:{ // MOV dword ptr [ESP],EAX
c.pc=0xe8e;if(!sl_tick(c))return int(c.fault);
P_e8e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_e8e_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_e8e_2:;
goto L_e91;
}
L_e91:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0xe91;if(!sl_tick(c))return int(c.fault);
P_e91_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_e91_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_e91_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_e91_3:;
goto L_e94;
}
L_e94:{ // CALL EAX
c.pc=0xe94;if(!sl_tick(c))return int(c.fault);
P_e94_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_e94_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_e94_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xe96ULL),c);
P_e94_3:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_e94_4:;
goto L_e96;
}
L_e96:{ // TEST EAX,EAX
c.pc=0xe96;if(!sl_tick(c))return int(c.fault);
P_e96_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_e96_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_e96_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_e96_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_e96_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_e96_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_e96_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_e96_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_e96_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_e96_9:;
goto L_e98;
}
L_e98:{ // JZ 0x00000ea3
c.pc=0xe98;if(!sl_tick(c))return int(c.fault);
P_e98_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_ea3;}
P_e98_1:;
goto L_e9a;
}
L_e9a:{ // MOV dword ptr [EBP + -0x1c],0xffffffff
c.pc=0xe9a;if(!sl_tick(c))return int(c.fault);
P_e9a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_e9a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xffffffffULL),c);
P_e9a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_e9a_3:;
goto L_ea1;
}
L_ea1:{ // JMP 0x00000ecd
c.pc=0xea1;if(!sl_tick(c))return int(c.fault);
P_ea1_0:;
goto L_ecd;
P_ea1_1:;
goto L_ea3;
}
L_ea3:{ // LEA EAX,[EBP + -0x10]
c.pc=0xea3;if(!sl_tick(c))return int(c.fault);
P_ea3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_ea3_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_ea3_2:;
goto L_ea6;
}
L_ea6:{ // MOV dword ptr [ESP],EAX
c.pc=0xea6;if(!sl_tick(c))return int(c.fault);
P_ea6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ea6_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ea6_2:;
goto L_ea9;
}
L_ea9:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0xea9;if(!sl_tick(c))return int(c.fault);
P_ea9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_ea9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ea9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ea9_3:;
goto L_eac;
}
L_eac:{ // CALL EAX
c.pc=0xeac;if(!sl_tick(c))return int(c.fault);
P_eac_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_eac_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_eac_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xeaeULL),c);
P_eac_3:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_eac_4:;
goto L_eae;
}
L_eae:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0xeae;if(!sl_tick(c))return int(c.fault);
P_eae_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_eae_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_eae_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_eae_3:;
goto L_eb1;
}
L_eb1:{ // TEST EAX,EAX
c.pc=0xeb1;if(!sl_tick(c))return int(c.fault);
P_eb1_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_eb1_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_eb1_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_eb1_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_eb1_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_eb1_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_eb1_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_eb1_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_eb1_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_eb1_9:;
goto L_eb3;
}
L_eb3:{ // JNZ 0x00000ec7
c.pc=0xeb3;if(!sl_tick(c))return int(c.fault);
P_eb3_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_eb3_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_ec7;}
P_eb3_2:;
goto L_eb5;
}
L_eb5:{ // LEA EAX,[EBP + -0x10]
c.pc=0xeb5;if(!sl_tick(c))return int(c.fault);
P_eb5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_eb5_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_eb5_2:;
goto L_eb8;
}
L_eb8:{ // MOV dword ptr [ESP],EAX
c.pc=0xeb8;if(!sl_tick(c))return int(c.fault);
P_eb8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_eb8_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_eb8_2:;
goto L_ebb;
}
L_ebb:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0xebb;if(!sl_tick(c))return int(c.fault);
P_ebb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_ebb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ebb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ebb_3:;
goto L_ebe;
}
L_ebe:{ // CALL EAX
c.pc=0xebe;if(!sl_tick(c))return int(c.fault);
P_ebe_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ebe_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ebe_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xec0ULL),c);
P_ebe_3:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_ebe_4:;
goto L_ec0;
}
L_ec0:{ // MOV dword ptr [EBP + -0x10],0x0
c.pc=0xec0;if(!sl_tick(c))return int(c.fault);
P_ec0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_ec0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_ec0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ec0_3:;
goto L_ec7;
}
L_ec7:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0xec7;if(!sl_tick(c))return int(c.fault);
P_ec7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_ec7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ec7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ec7_3:;
goto L_eca;
}
L_eca:{ // MOV dword ptr [EBP + -0x1c],EAX
c.pc=0xeca;if(!sl_tick(c))return int(c.fault);
P_eca_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_eca_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_eca_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_eca_3:;
goto L_ecd;
}
L_ecd:{ // MOV EAX,dword ptr [EBP + -0x1c]
c.pc=0xecd;if(!sl_tick(c))return int(c.fault);
P_ecd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_ecd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ecd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ecd_3:;
goto L_ed0;
}
L_ed0:{ // ADD ESP,0x34
c.pc=0xed0;if(!sl_tick(c))return int(c.fault);
P_ed0_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x34ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ed0_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x34ULL)))&(SlU(0x34ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x34ULL)))&(SlU(1)<<31))!=0),c);
P_ed0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x34ULL)),c);
P_ed0_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ed0_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ed0_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ed0_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ed0_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ed0_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ed0_9:;
goto L_ed3;
}
L_ed3:{ // POP EBX
c.pc=0xed3;if(!sl_tick(c))return int(c.fault);
P_ed3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ed3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ed3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ed3_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ed3_4:;
goto L_ed4;
}
L_ed4:{ // POP EBP
c.pc=0xed4;if(!sl_tick(c))return int(c.fault);
P_ed4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ed4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ed4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ed4_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ed4_4:;
goto L_ed5;
}
L_ed5:{ // RET
c.pc=0xed5;if(!sl_tick(c))return int(c.fault);
P_ed5_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ed5_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ed5_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_ed5_3:;
goto L_ed6;
}
L_ed6:{ // PUSH EBP
c.pc=0xed6;if(!sl_tick(c))return int(c.fault);
P_ed6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_ed6_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ed6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ed6_3:;
goto L_ed7;
}
L_ed7:{ // MOV EBP,ESP
c.pc=0xed7;if(!sl_tick(c))return int(c.fault);
P_ed7_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_ed7_1:;
goto L_ed9;
}
L_ed9:{ // PUSH EBX
c.pc=0xed9;if(!sl_tick(c))return int(c.fault);
P_ed9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_ed9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ed9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ed9_3:;
goto L_eda;
}
L_eda:{ // SUB ESP,0x34
c.pc=0xeda;if(!sl_tick(c))return int(c.fault);
P_eda_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x34ULL)),c);
P_eda_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x34ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x34ULL)))&(SlU(1)<<31))!=0),c);
P_eda_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x34ULL)),c);
P_eda_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_eda_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_eda_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_eda_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_eda_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_eda_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_eda_9:;
goto L_edd;
}
L_edd:{ // CALL 0x000c086c
c.pc=0xedd;if(!sl_tick(c))return int(c.fault);
P_edd_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_edd_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xee2ULL),c);
P_edd_2:;
c.pc=0xc086c;goto dispatch;
P_edd_3:;
goto L_ee2;
}
L_ee2:{ // LEA EAX,[EBP + -0x18]
c.pc=0xee2;if(!sl_tick(c))return int(c.fault);
P_ee2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_ee2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_ee2_2:;
goto L_ee5;
}
L_ee5:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xee5;if(!sl_tick(c))return int(c.fault);
P_ee5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ee5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ee5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ee5_3:;
goto L_ee9;
}
L_ee9:{ // MOV dword ptr [ESP],0xe
c.pc=0xee9;if(!sl_tick(c))return int(c.fault);
P_ee9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xeULL),c);
P_ee9_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ee9_2:;
goto L_ef0;
}
L_ef0:{ // CALL 0x0010301e
c.pc=0xef0;if(!sl_tick(c))return int(c.fault);
P_ef0_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ef0_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xef5ULL),c);
P_ef0_2:;
c.pc=0x10301e;goto dispatch;
P_ef0_3:;
goto L_ef5;
}
L_ef5:{ // TEST EAX,EAX
c.pc=0xef5;if(!sl_tick(c))return int(c.fault);
P_ef5_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_ef5_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_ef5_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_ef5_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ef5_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_ef5_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_ef5_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ef5_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ef5_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ef5_9:;
goto L_ef7;
}
L_ef7:{ // JZ 0x00000f05
c.pc=0xef7;if(!sl_tick(c))return int(c.fault);
P_ef7_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_f05;}
P_ef7_1:;
goto L_ef9;
}
L_ef9:{ // MOV dword ptr [EBP + -0x1c],0x0
c.pc=0xef9;if(!sl_tick(c))return int(c.fault);
P_ef9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_ef9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_ef9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ef9_3:;
goto L_f00;
}
L_f00:{ // JMP 0x0000103a
c.pc=0xf00;if(!sl_tick(c))return int(c.fault);
P_f00_0:;
goto L_103a;
P_f00_1:;
goto L_f05;
}
L_f05:{ // MOV EAX,dword ptr [EBP + -0x18]
c.pc=0xf05;if(!sl_tick(c))return int(c.fault);
P_f05_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_f05_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_f05_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_f05_3:;
goto L_f08;
}
L_f08:{ // MOV dword ptr [EBP + -0x14],EAX
c.pc=0xf08;if(!sl_tick(c))return int(c.fault);
P_f08_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_f08_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_f08_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_f08_3:;
goto L_f0b;
}
L_f0b:{ // CMP dword ptr [EBP + -0x14],0x0
c.pc=0xf0b;if(!sl_tick(c))return int(c.fault);
P_f0b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_f0b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_f0b_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_f0b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_f0b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_f0b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_f0b_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_f0b_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_f0b_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_f0b_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_f0b_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_f0b_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_f0b_12:;
goto L_f0f;
}
L_f0f:{ // JNZ 0x00000f3a
c.pc=0xf0f;if(!sl_tick(c))return int(c.fault);
P_f0f_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_f0f_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_f3a;}
P_f0f_2:;
goto L_f11;
}
L_f11:{ // MOV dword ptr [ESP + 0x4],0x1
c.pc=0xf11;if(!sl_tick(c))return int(c.fault);
P_f11_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_f11_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x1ULL),c);
P_f11_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_f11_3:;
goto L_f19;
}
L_f19:{ // MOV dword ptr [ESP],0x14
c.pc=0xf19;if(!sl_tick(c))return int(c.fault);
P_f19_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x14ULL),c);
P_f19_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_f19_2:;
goto L_f20;
}
L_f20:{ // CALL 0x00103023
c.pc=0xf20;if(!sl_tick(c))return int(c.fault);
P_f20_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_f20_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xf25ULL),c);
P_f20_2:;
c.pc=0x103023;goto dispatch;
P_f20_3:;
goto L_f25;
}
L_f25:{ // MOV dword ptr [EBP + -0x14],EAX
c.pc=0xf25;if(!sl_tick(c))return int(c.fault);
P_f25_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_f25_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_f25_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_f25_3:;
goto L_f28;
}
L_f28:{ // CMP dword ptr [EBP + -0x14],0x0
c.pc=0xf28;if(!sl_tick(c))return int(c.fault);
P_f28_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_f28_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_f28_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_f28_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_f28_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_f28_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_f28_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_f28_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_f28_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_f28_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_f28_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_f28_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_f28_12:;
goto L_f2c;
}
L_f2c:{ // JNZ 0x00000f3a
c.pc=0xf2c;if(!sl_tick(c))return int(c.fault);
P_f2c_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_f2c_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_f3a;}
P_f2c_2:;
goto L_f2e;
}
L_f2e:{ // MOV dword ptr [EBP + -0x1c],0x0
c.pc=0xf2e;if(!sl_tick(c))return int(c.fault);
P_f2e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_f2e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_f2e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_f2e_3:;
goto L_f35;
}
L_f35:{ // JMP 0x0000103a
c.pc=0xf35;if(!sl_tick(c))return int(c.fault);
P_f35_0:;
goto L_103a;
P_f35_1:;
goto L_f3a;
}
L_f3a:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0xf3a;if(!sl_tick(c))return int(c.fault);
P_f3a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_f3a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_f3a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_f3a_3:;
goto L_f3d;
}
L_f3d:{ // MOVZX EAX,byte ptr [EAX + 0x3]
c.pc=0xf3d;if(!sl_tick(c))return int(c.fault);
P_f3d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x3ULL)),c);
P_f3d_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_f3d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_f3d_3:;
goto L_f41;
}
L_f41:{ // TEST AL,AL
c.pc=0xf41;if(!sl_tick(c))return int(c.fault);
P_f41_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_f41_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_f41_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x54d80,(sl_get<1>(c.reg,sizeof(c.reg),0x0,c) & sl_get<1>(c.reg,sizeof(c.reg),0x0,c)),c);
P_f41_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_f41_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c) == SlU(0x0ULL)),c);
P_f41_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c) & SlU(0xffULL)),c);
P_f41_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_f41_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_f41_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_f41_9:;
goto L_f43;
}
L_f43:{ // JNZ 0x00001018
c.pc=0xf43;if(!sl_tick(c))return int(c.fault);
P_f43_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_f43_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_1018;}
P_f43_2:;
goto L_f49;
}
L_f49:{ // MOV dword ptr [ESP + 0x4],0x10
c.pc=0xf49;if(!sl_tick(c))return int(c.fault);
P_f49_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_f49_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x10ULL),c);
P_f49_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_f49_3:;
goto L_f51;
}
L_f51:{ // LEA EAX,[EBX + 0xb7a6a]
c.pc=0xf51;if(!sl_tick(c))return int(c.fault);
P_f51_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xb7a6aULL)),c);
P_f51_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_f51_2:;
goto L_f57;
}
L_f57:{ // MOV dword ptr [ESP],EAX
c.pc=0xf57;if(!sl_tick(c))return int(c.fault);
P_f57_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_f57_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_f57_2:;
goto L_f5a;
}
L_f5a:{ // CALL 0x00103000
c.pc=0xf5a;if(!sl_tick(c))return int(c.fault);
P_f5a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_f5a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xf5fULL),c);
P_f5a_2:;
c.pc=0x103000;goto dispatch;
P_f5a_3:;
goto L_f5f;
}
L_f5f:{ // MOV dword ptr [EBP + -0x10],EAX
c.pc=0xf5f;if(!sl_tick(c))return int(c.fault);
P_f5f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_f5f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_f5f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_f5f_3:;
goto L_f62;
}
L_f62:{ // CMP dword ptr [EBP + -0x10],0x0
c.pc=0xf62;if(!sl_tick(c))return int(c.fault);
P_f62_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_f62_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_f62_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_f62_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_f62_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_f62_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_f62_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_f62_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_f62_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_f62_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_f62_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_f62_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_f62_12:;
goto L_f66;
}
L_f66:{ // JZ 0x00001020
c.pc=0xf66;if(!sl_tick(c))return int(c.fault);
P_f66_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_1020;}
P_f66_1:;
goto L_f6c;
}
L_f6c:{ // LEA EAX,[EBX + 0xb7a86]
c.pc=0xf6c;if(!sl_tick(c))return int(c.fault);
P_f6c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xb7a86ULL)),c);
P_f6c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_f6c_2:;
goto L_f72;
}
L_f72:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xf72;if(!sl_tick(c))return int(c.fault);
P_f72_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_f72_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_f72_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_f72_3:;
goto L_f76;
}
L_f76:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0xf76;if(!sl_tick(c))return int(c.fault);
P_f76_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_f76_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_f76_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_f76_3:;
goto L_f79;
}
L_f79:{ // MOV dword ptr [ESP],EAX
c.pc=0xf79;if(!sl_tick(c))return int(c.fault);
P_f79_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_f79_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_f79_2:;
goto L_f7c;
}
L_f7c:{ // CALL 0x00103019
c.pc=0xf7c;if(!sl_tick(c))return int(c.fault);
P_f7c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_f7c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xf81ULL),c);
P_f7c_2:;
c.pc=0x103019;goto dispatch;
P_f7c_3:;
goto L_f81;
}
L_f81:{ // MOV EDX,EAX
c.pc=0xf81;if(!sl_tick(c))return int(c.fault);
P_f81_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_f81_1:;
goto L_f83;
}
L_f83:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0xf83;if(!sl_tick(c))return int(c.fault);
P_f83_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_f83_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_f83_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_f83_3:;
goto L_f86;
}
L_f86:{ // MOV dword ptr [EAX + 0x8],EDX
c.pc=0xf86;if(!sl_tick(c))return int(c.fault);
P_f86_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_f86_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_f86_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_f86_3:;
goto L_f89;
}
L_f89:{ // LEA EAX,[EBX + 0xb7a96]
c.pc=0xf89;if(!sl_tick(c))return int(c.fault);
P_f89_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xb7a96ULL)),c);
P_f89_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_f89_2:;
goto L_f8f;
}
L_f8f:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xf8f;if(!sl_tick(c))return int(c.fault);
P_f8f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_f8f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_f8f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_f8f_3:;
goto L_f93;
}
L_f93:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0xf93;if(!sl_tick(c))return int(c.fault);
P_f93_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_f93_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_f93_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_f93_3:;
goto L_f96;
}
L_f96:{ // MOV dword ptr [ESP],EAX
c.pc=0xf96;if(!sl_tick(c))return int(c.fault);
P_f96_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_f96_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_f96_2:;
goto L_f99;
}
L_f99:{ // CALL 0x00103019
c.pc=0xf99;if(!sl_tick(c))return int(c.fault);
P_f99_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_f99_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xf9eULL),c);
P_f99_2:;
c.pc=0x103019;goto dispatch;
P_f99_3:;
goto L_f9e;
}
L_f9e:{ // MOV EDX,EAX
c.pc=0xf9e;if(!sl_tick(c))return int(c.fault);
P_f9e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_f9e_1:;
goto L_fa0;
}
L_fa0:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0xfa0;if(!sl_tick(c))return int(c.fault);
P_fa0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_fa0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_fa0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_fa0_3:;
goto L_fa3;
}
L_fa3:{ // MOV dword ptr [EAX + 0xc],EDX
c.pc=0xfa3;if(!sl_tick(c))return int(c.fault);
P_fa3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xcULL)),c);
P_fa3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_fa3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_fa3_3:;
goto L_fa6;
}
L_fa6:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0xfa6;if(!sl_tick(c))return int(c.fault);
P_fa6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_fa6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_fa6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_fa6_3:;
goto L_fa9;
}
L_fa9:{ // MOV EAX,dword ptr [EAX + 0x8]
c.pc=0xfa9;if(!sl_tick(c))return int(c.fault);
P_fa9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_fa9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_fa9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_fa9_3:;
goto L_fac;
}
L_fac:{ // TEST EAX,EAX
c.pc=0xfac;if(!sl_tick(c))return int(c.fault);
P_fac_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_fac_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_fac_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_fac_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_fac_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_fac_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_fac_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_fac_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_fac_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_fac_9:;
goto L_fae;
}
L_fae:{ // JZ 0x00001020
c.pc=0xfae;if(!sl_tick(c))return int(c.fault);
P_fae_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_1020;}
P_fae_1:;
goto L_fb0;
}
L_fb0:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0xfb0;if(!sl_tick(c))return int(c.fault);
P_fb0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_fb0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_fb0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_fb0_3:;
goto L_fb3;
}
L_fb3:{ // MOV EAX,dword ptr [EAX + 0xc]
c.pc=0xfb3;if(!sl_tick(c))return int(c.fault);
P_fb3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xcULL)),c);
P_fb3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_fb3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_fb3_3:;
goto L_fb6;
}
L_fb6:{ // TEST EAX,EAX
c.pc=0xfb6;if(!sl_tick(c))return int(c.fault);
P_fb6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_fb6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_fb6_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_fb6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_fb6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_fb6_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_fb6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_fb6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_fb6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_fb6_9:;
goto L_fb8;
}
L_fb8:{ // JZ 0x00001020
c.pc=0xfb8;if(!sl_tick(c))return int(c.fault);
P_fb8_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_1020;}
P_fb8_1:;
goto L_fba;
}
L_fba:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0xfba;if(!sl_tick(c))return int(c.fault);
P_fba_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_fba_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_fba_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_fba_3:;
goto L_fbd;
}
L_fbd:{ // MOV EDX,dword ptr [EAX + 0xc]
c.pc=0xfbd;if(!sl_tick(c))return int(c.fault);
P_fbd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xcULL)),c);
P_fbd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_fbd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_fbd_3:;
goto L_fc0;
}
L_fc0:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0xfc0;if(!sl_tick(c))return int(c.fault);
P_fc0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_fc0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_fc0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_fc0_3:;
goto L_fc3;
}
L_fc3:{ // MOV EAX,dword ptr [EAX + 0x8]
c.pc=0xfc3;if(!sl_tick(c))return int(c.fault);
P_fc3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_fc3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_fc3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_fc3_3:;
goto L_fc6;
}
L_fc6:{ // MOV dword ptr [ESP + 0x4],EDX
c.pc=0xfc6;if(!sl_tick(c))return int(c.fault);
P_fc6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_fc6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_fc6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_fc6_3:;
goto L_fca;
}
L_fca:{ // MOV dword ptr [ESP],EAX
c.pc=0xfca;if(!sl_tick(c))return int(c.fault);
P_fca_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_fca_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_fca_2:;
goto L_fcd;
}
L_fcd:{ // CALL 0x00000e61
c.pc=0xfcd;if(!sl_tick(c))return int(c.fault);
P_fcd_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_fcd_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xfd2ULL),c);
P_fcd_2:;
goto L_e61;
P_fcd_3:;
goto L_fd2;
}
L_fd2:{ // MOV dword ptr [EBP + -0xc],EAX
c.pc=0xfd2;if(!sl_tick(c))return int(c.fault);
P_fd2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_fd2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_fd2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_fd2_3:;
goto L_fd5;
}
L_fd5:{ // CMP dword ptr [EBP + -0xc],-0x1
c.pc=0xfd5;if(!sl_tick(c))return int(c.fault);
P_fd5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_fd5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_fd5_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_fd5_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0xffffffffULL)),c);
P_fd5_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0xffffffffULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0xffffffffULL)))&(SlU(1)<<31))!=0),c);
P_fd5_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0xffffffffULL)),c);
P_fd5_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_fd5_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_fd5_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_fd5_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_fd5_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_fd5_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_fd5_12:;
goto L_fd9;
}
L_fd9:{ // JZ 0x00001020
c.pc=0xfd9;if(!sl_tick(c))return int(c.fault);
P_fd9_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_1020;}
P_fd9_1:;
goto L_fdb;
}
L_fdb:{ // CMP dword ptr [EBP + -0xc],0x0
c.pc=0xfdb;if(!sl_tick(c))return int(c.fault);
P_fdb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_fdb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_fdb_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_fdb_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_fdb_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_fdb_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_fdb_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_fdb_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_fdb_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_fdb_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_fdb_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_fdb_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_fdb_12:;
goto L_fdf;
}
L_fdf:{ // JNZ 0x00000fea
c.pc=0xfdf;if(!sl_tick(c))return int(c.fault);
P_fdf_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_fdf_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_fea;}
P_fdf_2:;
goto L_fe1;
}
L_fe1:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0xfe1;if(!sl_tick(c))return int(c.fault);
P_fe1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_fe1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_fe1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_fe1_3:;
goto L_fe4;
}
L_fe4:{ // MOV byte ptr [EAX + 0x3],0x2
c.pc=0xfe4;if(!sl_tick(c))return int(c.fault);
P_fe4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x3ULL)),c);
P_fe4_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x2ULL),c);
P_fe4_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_fe4_3:;
goto L_fe8;
}
L_fe8:{ // JMP 0x00001018
c.pc=0xfe8;if(!sl_tick(c))return int(c.fault);
P_fe8_0:;
goto L_1018;
P_fe8_1:;
goto L_fea;
}
L_fea:{ // LEA EAX,[EBX + 0xb7aa6]
c.pc=0xfea;if(!sl_tick(c))return int(c.fault);
P_fea_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xb7aa6ULL)),c);
P_fea_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_fea_2:;
goto L_ff0;
}
L_ff0:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xff0;if(!sl_tick(c))return int(c.fault);
P_ff0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ff0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ff0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ff0_3:;
goto L_ff4;
}
L_ff4:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0xff4;if(!sl_tick(c))return int(c.fault);
P_ff4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_ff4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ff4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ff4_3:;
goto L_ff7;
}
L_ff7:{ // MOV dword ptr [ESP],EAX
c.pc=0xff7;if(!sl_tick(c))return int(c.fault);
P_ff7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ff7_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ff7_2:;
goto L_ffa;
}
L_ffa:{ // CALL 0x00103019
c.pc=0xffa;if(!sl_tick(c))return int(c.fault);
P_ffa_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ffa_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xfffULL),c);
P_ffa_2:;
c.pc=0x103019;goto dispatch;
P_ffa_3:;
goto L_fff;
}
L_fff:{ // MOV EDX,EAX
c.pc=0xfff;if(!sl_tick(c))return int(c.fault);
P_fff_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_fff_1:;
goto L_1001;
}
L_1001:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0x1001;if(!sl_tick(c))return int(c.fault);
P_1001_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_1001_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1001_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1001_3:;
goto L_1004;
}
L_1004:{ // MOV dword ptr [EAX + 0x10],EDX
c.pc=0x1004;if(!sl_tick(c))return int(c.fault);
P_1004_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x10ULL)),c);
P_1004_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_1004_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1004_3:;
goto L_1007;
}
L_1007:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0x1007;if(!sl_tick(c))return int(c.fault);
P_1007_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_1007_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1007_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1007_3:;
goto L_100a;
}
L_100a:{ // MOV EAX,dword ptr [EAX + 0x10]
c.pc=0x100a;if(!sl_tick(c))return int(c.fault);
P_100a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x10ULL)),c);
P_100a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_100a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_100a_3:;
goto L_100d;
}
L_100d:{ // TEST EAX,EAX
c.pc=0x100d;if(!sl_tick(c))return int(c.fault);
P_100d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_100d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_100d_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_100d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_100d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_100d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_100d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_100d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_100d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_100d_9:;
goto L_100f;
}
L_100f:{ // JZ 0x00001020
c.pc=0x100f;if(!sl_tick(c))return int(c.fault);
P_100f_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_1020;}
P_100f_1:;
goto L_1011;
}
L_1011:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0x1011;if(!sl_tick(c))return int(c.fault);
P_1011_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_1011_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1011_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1011_3:;
goto L_1014;
}
L_1014:{ // MOV byte ptr [EAX + 0x3],0x10
c.pc=0x1014;if(!sl_tick(c))return int(c.fault);
P_1014_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x3ULL)),c);
P_1014_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x10ULL),c);
P_1014_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_1014_3:;
goto L_1018;
}
L_1018:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0x1018;if(!sl_tick(c))return int(c.fault);
P_1018_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_1018_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1018_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1018_3:;
goto L_101b;
}
L_101b:{ // MOV dword ptr [EBP + -0x1c],EAX
c.pc=0x101b;if(!sl_tick(c))return int(c.fault);
P_101b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_101b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_101b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_101b_3:;
goto L_101e;
}
L_101e:{ // JMP 0x0000103a
c.pc=0x101e;if(!sl_tick(c))return int(c.fault);
P_101e_0:;
goto L_103a;
P_101e_1:;
goto L_1020;
}
L_1020:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0x1020;if(!sl_tick(c))return int(c.fault);
P_1020_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_1020_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1020_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1020_3:;
goto L_1023;
}
L_1023:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x1023;if(!sl_tick(c))return int(c.fault);
P_1023_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_1023_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1023_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1023_3:;
goto L_1027;
}
L_1027:{ // MOV dword ptr [ESP],0xe
c.pc=0x1027;if(!sl_tick(c))return int(c.fault);
P_1027_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xeULL),c);
P_1027_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_1027_2:;
goto L_102e;
}
L_102e:{ // CALL 0x00103014
c.pc=0x102e;if(!sl_tick(c))return int(c.fault);
P_102e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_102e_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x1033ULL),c);
P_102e_2:;
c.pc=0x103014;goto dispatch;
P_102e_3:;
goto L_1033;
}
L_1033:{ // MOV dword ptr [EBP + -0x1c],0x0
c.pc=0x1033;if(!sl_tick(c))return int(c.fault);
P_1033_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_1033_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_1033_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_1033_3:;
goto L_103a;
}
L_103a:{ // MOV EAX,dword ptr [EBP + -0x1c]
c.pc=0x103a;if(!sl_tick(c))return int(c.fault);
P_103a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_103a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_103a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_103a_3:;
goto L_103d;
}
L_103d:{ // ADD ESP,0x34
c.pc=0x103d;if(!sl_tick(c))return int(c.fault);
P_103d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x34ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_103d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x34ULL)))&(SlU(0x34ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x34ULL)))&(SlU(1)<<31))!=0),c);
P_103d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x34ULL)),c);
P_103d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_103d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_103d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_103d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_103d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_103d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_103d_9:;
goto L_1040;
}
L_1040:{ // POP EBX
c.pc=0x1040;if(!sl_tick(c))return int(c.fault);
P_1040_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_1040_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_1040_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_1040_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_1040_4:;
goto L_1041;
}
L_1041:{ // POP EBP
c.pc=0x1041;if(!sl_tick(c))return int(c.fault);
P_1041_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_1041_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_1041_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_1041_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_1041_4:;
goto L_1042;
}
L_1042:{ // RET
c.pc=0x1042;if(!sl_tick(c))return int(c.fault);
P_1042_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_1042_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_1042_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_1042_3:;
goto L_1043;
}
L_1043:{ // PUSH EBP
c.pc=0x1043;if(!sl_tick(c))return int(c.fault);
P_1043_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_1043_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1043_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_1043_3:;
goto L_1044;
}
L_1044:{ // MOV EBP,ESP
c.pc=0x1044;if(!sl_tick(c))return int(c.fault);
P_1044_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_1044_1:;
goto L_1046;
}
L_1046:{ // SUB ESP,0x38
c.pc=0x1046;if(!sl_tick(c))return int(c.fault);
P_1046_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x38ULL)),c);
P_1046_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x38ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x38ULL)))&(SlU(1)<<31))!=0),c);
P_1046_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x38ULL)),c);
P_1046_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1046_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_1046_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_1046_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1046_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1046_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1046_9:;
goto L_1049;
}
L_1049:{ // MOV dword ptr [ESP],0x10
c.pc=0x1049;if(!sl_tick(c))return int(c.fault);
P_1049_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x10ULL),c);
P_1049_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_1049_2:;
goto L_1050;
}
L_1050:{ // CALL 0x0010300f
c.pc=0x1050;if(!sl_tick(c))return int(c.fault);
P_1050_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1050_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x1055ULL),c);
P_1050_2:;
c.pc=0x10300f;goto dispatch;
P_1050_3:;
goto L_1055;
}
L_1055:{ // MOV dword ptr [EBP + -0x10],EAX
c.pc=0x1055;if(!sl_tick(c))return int(c.fault);
P_1055_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_1055_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1055_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1055_3:;
goto L_1058;
}
L_1058:{ // CMP dword ptr [EBP + -0x10],0x0
c.pc=0x1058;if(!sl_tick(c))return int(c.fault);
P_1058_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_1058_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1058_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_1058_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_1058_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_1058_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_1058_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1058_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_1058_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_1058_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1058_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1058_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1058_12:;
goto L_105c;
}
L_105c:{ // JNZ 0x0000107a
c.pc=0x105c;if(!sl_tick(c))return int(c.fault);
P_105c_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_105c_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_107a;}
P_105c_2:;
goto L_105e;
}
L_105e:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x105e;if(!sl_tick(c))return int(c.fault);
P_105e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_105e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_105e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_105e_3:;
goto L_1061;
}
L_1061:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x1061;if(!sl_tick(c))return int(c.fault);
P_1061_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_1061_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1061_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1061_3:;
goto L_1065;
}
L_1065:{ // MOV dword ptr [ESP],0xe
c.pc=0x1065;if(!sl_tick(c))return int(c.fault);
P_1065_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xeULL),c);
P_1065_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_1065_2:;
goto L_106c;
}
L_106c:{ // CALL 0x00103014
c.pc=0x106c;if(!sl_tick(c))return int(c.fault);
P_106c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_106c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x1071ULL),c);
P_106c_2:;
c.pc=0x103014;goto dispatch;
P_106c_3:;
goto L_1071;
}
L_1071:{ // MOV dword ptr [EBP + -0x20],0xffffffff
c.pc=0x1071;if(!sl_tick(c))return int(c.fault);
P_1071_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_1071_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xffffffffULL),c);
P_1071_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_1071_3:;
goto L_1078;
}
L_1078:{ // JMP 0x000010d7
c.pc=0x1078;if(!sl_tick(c))return int(c.fault);
P_1078_0:;
goto L_10d7;
P_1078_1:;
goto L_107a;
}
L_107a:{ // MOV ECX,dword ptr [EBP + -0x10]
c.pc=0x107a;if(!sl_tick(c))return int(c.fault);
P_107a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_107a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_107a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_107a_3:;
goto L_107d;
}
L_107d:{ // MOV EDX,dword ptr [EBP + 0xc]
c.pc=0x107d;if(!sl_tick(c))return int(c.fault);
P_107d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_107d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_107d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_107d_3:;
goto L_1080;
}
L_1080:{ // MOV EAX,dword ptr [EDX]
c.pc=0x1080;if(!sl_tick(c))return int(c.fault);
P_1080_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_1080_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1080_2:;
goto L_1082;
}
L_1082:{ // MOV dword ptr [ECX + 0x4],EAX
c.pc=0x1082;if(!sl_tick(c))return int(c.fault);
P_1082_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x4ULL)),c);
P_1082_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1082_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1082_3:;
goto L_1085;
}
L_1085:{ // MOV EAX,dword ptr [EDX + 0x4]
c.pc=0x1085;if(!sl_tick(c))return int(c.fault);
P_1085_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x4ULL)),c);
P_1085_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1085_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1085_3:;
goto L_1088;
}
L_1088:{ // MOV dword ptr [ECX + 0x8],EAX
c.pc=0x1088;if(!sl_tick(c))return int(c.fault);
P_1088_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x8ULL)),c);
P_1088_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1088_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1088_3:;
goto L_108b;
}
L_108b:{ // MOV EAX,dword ptr [EDX + 0x8]
c.pc=0x108b;if(!sl_tick(c))return int(c.fault);
P_108b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x8ULL)),c);
P_108b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_108b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_108b_3:;
goto L_108e;
}
L_108e:{ // MOV dword ptr [ECX + 0xc],EAX
c.pc=0x108e;if(!sl_tick(c))return int(c.fault);
P_108e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0xcULL)),c);
P_108e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_108e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_108e_3:;
goto L_1091;
}
L_1091:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x1091;if(!sl_tick(c))return int(c.fault);
P_1091_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_1091_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1091_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1091_3:;
goto L_1094;
}
L_1094:{ // MOV EDX,dword ptr [EAX + 0x4]
c.pc=0x1094;if(!sl_tick(c))return int(c.fault);
P_1094_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_1094_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1094_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1094_3:;
goto L_1097;
}
L_1097:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0x1097;if(!sl_tick(c))return int(c.fault);
P_1097_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_1097_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1097_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1097_3:;
goto L_109a;
}
L_109a:{ // MOV dword ptr [EAX],EDX
c.pc=0x109a;if(!sl_tick(c))return int(c.fault);
P_109a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_109a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_109a_2:;
goto L_109c;
}
L_109c:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0x109c;if(!sl_tick(c))return int(c.fault);
P_109c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_109c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_109c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_109c_3:;
goto L_109f;
}
L_109f:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0x109f;if(!sl_tick(c))return int(c.fault);
P_109f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_109f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_109f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_109f_3:;
goto L_10a2;
}
L_10a2:{ // MOV dword ptr [EDX + 0x4],EAX
c.pc=0x10a2;if(!sl_tick(c))return int(c.fault);
P_10a2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x4ULL)),c);
P_10a2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_10a2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_10a2_3:;
goto L_10a5;
}
L_10a5:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x10a5;if(!sl_tick(c))return int(c.fault);
P_10a5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_10a5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_10a5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_10a5_3:;
goto L_10a8;
}
L_10a8:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x10a8;if(!sl_tick(c))return int(c.fault);
P_10a8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_10a8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_10a8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_10a8_3:;
goto L_10ac;
}
L_10ac:{ // MOV dword ptr [ESP],0xe
c.pc=0x10ac;if(!sl_tick(c))return int(c.fault);
P_10ac_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xeULL),c);
P_10ac_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_10ac_2:;
goto L_10b3;
}
L_10b3:{ // CALL 0x00103014
c.pc=0x10b3;if(!sl_tick(c))return int(c.fault);
P_10b3_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_10b3_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x10b8ULL),c);
P_10b3_2:;
c.pc=0x103014;goto dispatch;
P_10b3_3:;
goto L_10b8;
}
L_10b8:{ // MOV dword ptr [EBP + -0xc],EAX
c.pc=0x10b8;if(!sl_tick(c))return int(c.fault);
P_10b8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_10b8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_10b8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_10b8_3:;
goto L_10bb;
}
L_10bb:{ // CMP dword ptr [EBP + -0xc],0x0
c.pc=0x10bb;if(!sl_tick(c))return int(c.fault);
P_10bb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_10bb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_10bb_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_10bb_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_10bb_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_10bb_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_10bb_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_10bb_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_10bb_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_10bb_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_10bb_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_10bb_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_10bb_12:;
goto L_10bf;
}
L_10bf:{ // JNZ 0x000010ca
c.pc=0x10bf;if(!sl_tick(c))return int(c.fault);
P_10bf_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_10bf_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_10ca;}
P_10bf_2:;
goto L_10c1;
}
L_10c1:{ // MOV dword ptr [EBP + -0x1c],0x0
c.pc=0x10c1;if(!sl_tick(c))return int(c.fault);
P_10c1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_10c1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_10c1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_10c1_3:;
goto L_10c8;
}
L_10c8:{ // JMP 0x000010d1
c.pc=0x10c8;if(!sl_tick(c))return int(c.fault);
P_10c8_0:;
goto L_10d1;
P_10c8_1:;
goto L_10ca;
}
L_10ca:{ // MOV dword ptr [EBP + -0x1c],0xffffffff
c.pc=0x10ca;if(!sl_tick(c))return int(c.fault);
P_10ca_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_10ca_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xffffffffULL),c);
P_10ca_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_10ca_3:;
goto L_10d1;
}
L_10d1:{ // MOV EAX,dword ptr [EBP + -0x1c]
c.pc=0x10d1;if(!sl_tick(c))return int(c.fault);
P_10d1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_10d1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_10d1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_10d1_3:;
goto L_10d4;
}
L_10d4:{ // MOV dword ptr [EBP + -0x20],EAX
c.pc=0x10d4;if(!sl_tick(c))return int(c.fault);
P_10d4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_10d4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_10d4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_10d4_3:;
goto L_10d7;
}
L_10d7:{ // MOV EAX,dword ptr [EBP + -0x20]
c.pc=0x10d7;if(!sl_tick(c))return int(c.fault);
P_10d7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_10d7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_10d7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_10d7_3:;
goto L_10da;
}
L_10da:{ // LEAVE
c.pc=0x10da;if(!sl_tick(c))return int(c.fault);
P_10da_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_10da_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_10da_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_10da_3:;
goto L_10db;
}
L_10db:{ // RET
c.pc=0x10db;if(!sl_tick(c))return int(c.fault);
P_10db_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_10db_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_10db_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_10db_3:;
goto L_10dc;
}
L_10dc:{ // PUSH EBP
c.pc=0x10dc;if(!sl_tick(c))return int(c.fault);
P_10dc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_10dc_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_10dc_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_10dc_3:;
goto L_10dd;
}
L_10dd:{ // MOV EBP,ESP
c.pc=0x10dd;if(!sl_tick(c))return int(c.fault);
P_10dd_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_10dd_1:;
goto L_10df;
}
L_10df:{ // SUB ESP,0x38
c.pc=0x10df;if(!sl_tick(c))return int(c.fault);
P_10df_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x38ULL)),c);
P_10df_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x38ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x38ULL)))&(SlU(1)<<31))!=0),c);
P_10df_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x38ULL)),c);
P_10df_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_10df_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_10df_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_10df_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_10df_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_10df_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_10df_9:;
goto L_10e2;
}
L_10e2:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x10e2;if(!sl_tick(c))return int(c.fault);
P_10e2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_10e2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_10e2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_10e2_3:;
goto L_10e5;
}
L_10e5:{ // MOV EAX,dword ptr [EAX + 0x4]
c.pc=0x10e5;if(!sl_tick(c))return int(c.fault);
P_10e5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_10e5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_10e5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_10e5_3:;
goto L_10e8;
}
L_10e8:{ // MOV dword ptr [EBP + -0xc],EAX
c.pc=0x10e8;if(!sl_tick(c))return int(c.fault);
P_10e8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_10e8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_10e8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_10e8_3:;
goto L_10eb;
}
L_10eb:{ // CMP dword ptr [EBP + -0xc],0x0
c.pc=0x10eb;if(!sl_tick(c))return int(c.fault);
P_10eb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_10eb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_10eb_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_10eb_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_10eb_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_10eb_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_10eb_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_10eb_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_10eb_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_10eb_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_10eb_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_10eb_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_10eb_12:;
goto L_10ef;
}
L_10ef:{ // JZ 0x00001193
c.pc=0x10ef;if(!sl_tick(c))return int(c.fault);
P_10ef_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_1193;}
P_10ef_1:;
goto L_10f5;
}
L_10f5:{ // MOV EAX,dword ptr [EBP + -0xc]
c.pc=0x10f5;if(!sl_tick(c))return int(c.fault);
P_10f5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_10f5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_10f5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_10f5_3:;
goto L_10f8;
}
L_10f8:{ // CMP EAX,dword ptr [EBP + 0xc]
c.pc=0x10f8;if(!sl_tick(c))return int(c.fault);
P_10f8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_10f8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_10f8_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_10f8_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_10f8_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_10f8_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_10f8_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_10f8_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_10f8_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_10f8_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_10f8_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_10f8_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_10f8_12:;
goto L_10fb;
}
L_10fb:{ // JZ 0x00001193
c.pc=0x10fb;if(!sl_tick(c))return int(c.fault);
P_10fb_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_1193;}
P_10fb_1:;
goto L_1101;
}
L_1101:{ // MOV EAX,dword ptr [EBP + -0xc]
c.pc=0x1101;if(!sl_tick(c))return int(c.fault);
P_1101_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_1101_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1101_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1101_3:;
goto L_1104;
}
L_1104:{ // MOV EDX,dword ptr [EAX]
c.pc=0x1104;if(!sl_tick(c))return int(c.fault);
P_1104_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_1104_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1104_2:;
goto L_1106;
}
L_1106:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x1106;if(!sl_tick(c))return int(c.fault);
P_1106_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_1106_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1106_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1106_3:;
goto L_1109;
}
L_1109:{ // MOV dword ptr [EAX + 0x4],EDX
c.pc=0x1109;if(!sl_tick(c))return int(c.fault);
P_1109_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_1109_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_1109_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1109_3:;
goto L_110c;
}
L_110c:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x110c;if(!sl_tick(c))return int(c.fault);
P_110c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_110c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_110c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_110c_3:;
goto L_110f;
}
L_110f:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x110f;if(!sl_tick(c))return int(c.fault);
P_110f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_110f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_110f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_110f_3:;
goto L_1113;
}
L_1113:{ // MOV dword ptr [ESP],0xe
c.pc=0x1113;if(!sl_tick(c))return int(c.fault);
P_1113_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xeULL),c);
P_1113_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_1113_2:;
goto L_111a;
}
L_111a:{ // CALL 0x00103014
c.pc=0x111a;if(!sl_tick(c))return int(c.fault);
P_111a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_111a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x111fULL),c);
P_111a_2:;
c.pc=0x103014;goto dispatch;
P_111a_3:;
goto L_111f;
}
L_111f:{ // MOV EAX,dword ptr [EBP + -0xc]
c.pc=0x111f;if(!sl_tick(c))return int(c.fault);
P_111f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_111f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_111f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_111f_3:;
goto L_1122;
}
L_1122:{ // MOV EAX,dword ptr [EAX + 0x8]
c.pc=0x1122;if(!sl_tick(c))return int(c.fault);
P_1122_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_1122_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1122_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1122_3:;
goto L_1125;
}
L_1125:{ // MOV dword ptr [EBP + -0x1c],EAX
c.pc=0x1125;if(!sl_tick(c))return int(c.fault);
P_1125_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_1125_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1125_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1125_3:;
goto L_1128;
}
L_1128:{ // CMP dword ptr [EBP + -0x1c],0x5
c.pc=0x1128;if(!sl_tick(c))return int(c.fault);
P_1128_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_1128_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1128_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_1128_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x5ULL)),c);
P_1128_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x5ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x5ULL)))&(SlU(1)<<31))!=0),c);
P_1128_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x5ULL)),c);
P_1128_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1128_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_1128_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_1128_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1128_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1128_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1128_12:;
goto L_112c;
}
L_112c:{ // JA 0x0000116f
c.pc=0x112c;if(!sl_tick(c))return int(c.fault);
P_112c_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9d80,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x200,c)) || bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c))),c);
P_112c_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9e80,(!sl_get<1>(c.temp,sizeof(c.temp),0x9d80,c)),c);
P_112c_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9e80,c)){goto L_116f;}
P_112c_3:;
goto L_112e;
}
L_112e:{ // MOV EAX,0x1
c.pc=0x112e;if(!sl_tick(c))return int(c.fault);
P_112e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,SlU(0x1ULL),c);
P_112e_1:;
goto L_1133;
}
L_1133:{ // MOV EDX,EAX
c.pc=0x1133;if(!sl_tick(c))return int(c.fault);
P_1133_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1133_1:;
goto L_1135;
}
L_1135:{ // MOVZX ECX,byte ptr [EBP + -0x1c]
c.pc=0x1135;if(!sl_tick(c))return int(c.fault);
P_1135_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_1135_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1135_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_1135_3:;
goto L_1139;
}
L_1139:{ // SHL EDX,CL
c.pc=0x1139;if(!sl_tick(c))return int(c.fault);
P_1139_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x50c00,(sl_get<1>(c.reg,sizeof(c.reg),0x4,c) & SlU(0x1fULL)),c);
P_1139_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x50c80,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_1139_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_lshift(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),sl_get<1>(c.temp,sizeof(c.temp),0x50c00,c)),c);
P_1139_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x24d00,(sl_get<1>(c.temp,sizeof(c.temp),0x50c00,c) != SlU(0x0ULL)),c);
P_1139_4:;
sl_put<1>(c.temp,sizeof(c.temp),0x24d80,(sl_get<1>(c.temp,sizeof(c.temp),0x50c00,c) - SlU(0x1ULL)),c);
P_1139_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x24e00,sl_lshift(sl_get<4>(c.temp,sizeof(c.temp),0x50c80,c),sl_get<1>(c.temp,sizeof(c.temp),0x24d80,c)),c);
P_1139_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x24f00,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x24e00,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1139_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x24f80,(!sl_get<1>(c.temp,sizeof(c.temp),0x24d00,c)),c);
P_1139_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x25000,(sl_get<1>(c.temp,sizeof(c.temp),0x24f80,c) & sl_get<1>(c.reg,sizeof(c.reg),0x200,c)),c);
P_1139_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x25080,(sl_get<1>(c.temp,sizeof(c.temp),0x24d00,c) & sl_get<1>(c.temp,sizeof(c.temp),0x24f00,c)),c);
P_1139_10:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x25000,c) | sl_get<1>(c.temp,sizeof(c.temp),0x25080,c)),c);
P_1139_11:;
sl_put<1>(c.temp,sizeof(c.temp),0x25200,(sl_get<1>(c.temp,sizeof(c.temp),0x50c00,c) == SlU(0x1ULL)),c);
P_1139_12:;
sl_put<1>(c.temp,sizeof(c.temp),0x25280,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1139_13:;
sl_put<1>(c.temp,sizeof(c.temp),0x25380,(sl_get<1>(c.reg,sizeof(c.reg),0x200,c) ^ sl_get<1>(c.temp,sizeof(c.temp),0x25280,c)),c);
P_1139_14:;
sl_put<1>(c.temp,sizeof(c.temp),0x25400,(!sl_get<1>(c.temp,sizeof(c.temp),0x25200,c)),c);
P_1139_15:;
sl_put<1>(c.temp,sizeof(c.temp),0x25480,(sl_get<1>(c.temp,sizeof(c.temp),0x25400,c) & sl_get<1>(c.reg,sizeof(c.reg),0x20b,c)),c);
P_1139_16:;
sl_put<1>(c.temp,sizeof(c.temp),0x25500,(sl_get<1>(c.temp,sizeof(c.temp),0x25200,c) & sl_get<1>(c.temp,sizeof(c.temp),0x25380,c)),c);
P_1139_17:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(sl_get<1>(c.temp,sizeof(c.temp),0x25480,c) | sl_get<1>(c.temp,sizeof(c.temp),0x25500,c)),c);
P_1139_18:;
sl_put<1>(c.temp,sizeof(c.temp),0x22b80,(sl_get<1>(c.temp,sizeof(c.temp),0x50c00,c) != SlU(0x0ULL)),c);
P_1139_19:;
sl_put<1>(c.temp,sizeof(c.temp),0x22c80,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1139_20:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d00,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_1139_21:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d80,(sl_get<1>(c.temp,sizeof(c.temp),0x22d00,c) & sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_1139_22:;
sl_put<1>(c.temp,sizeof(c.temp),0x22e00,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22c80,c)),c);
P_1139_23:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_get<1>(c.temp,sizeof(c.temp),0x22d80,c) | sl_get<1>(c.temp,sizeof(c.temp),0x22e00,c)),c);
P_1139_24:;
sl_put<1>(c.temp,sizeof(c.temp),0x22f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_1139_25:;
sl_put<1>(c.temp,sizeof(c.temp),0x23000,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_1139_26:;
sl_put<1>(c.temp,sizeof(c.temp),0x23080,(sl_get<1>(c.temp,sizeof(c.temp),0x23000,c) & sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_1139_27:;
sl_put<1>(c.temp,sizeof(c.temp),0x23100,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22f80,c)),c);
P_1139_28:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x23080,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23100,c)),c);
P_1139_29:;
sl_put<4>(c.temp,sizeof(c.temp),0x23200,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_1139_30:;
sl_put<1>(c.temp,sizeof(c.temp),0x23280,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x23200,c)),c);
P_1139_31:;
sl_put<1>(c.temp,sizeof(c.temp),0x23300,(sl_get<1>(c.temp,sizeof(c.temp),0x23280,c) & SlU(0x1ULL)),c);
P_1139_32:;
sl_put<1>(c.temp,sizeof(c.temp),0x23400,(sl_get<1>(c.temp,sizeof(c.temp),0x23300,c) == SlU(0x0ULL)),c);
P_1139_33:;
sl_put<1>(c.temp,sizeof(c.temp),0x23480,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_1139_34:;
sl_put<1>(c.temp,sizeof(c.temp),0x23500,(sl_get<1>(c.temp,sizeof(c.temp),0x23480,c) & sl_get<1>(c.reg,sizeof(c.reg),0x202,c)),c);
P_1139_35:;
sl_put<1>(c.temp,sizeof(c.temp),0x23580,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x23400,c)),c);
P_1139_36:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x23500,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23580,c)),c);
P_1139_37:;
goto L_113b;
}
L_113b:{ // MOV dword ptr [EBP + -0x20],EDX
c.pc=0x113b;if(!sl_tick(c))return int(c.fault);
P_113b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_113b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_113b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_113b_3:;
goto L_113e;
}
L_113e:{ // MOV EAX,dword ptr [EBP + -0x20]
c.pc=0x113e;if(!sl_tick(c))return int(c.fault);
P_113e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_113e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_113e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_113e_3:;
goto L_1141;
}
L_1141:{ // AND EAX,0x15
c.pc=0x1141;if(!sl_tick(c))return int(c.fault);
P_1141_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_1141_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_1141_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0x15ULL)),c);
P_1141_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1141_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_1141_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_1141_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1141_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1141_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1141_9:;
goto L_1144;
}
L_1144:{ // TEST EAX,EAX
c.pc=0x1144;if(!sl_tick(c))return int(c.fault);
P_1144_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_1144_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_1144_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_1144_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1144_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_1144_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_1144_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1144_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1144_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1144_9:;
goto L_1146;
}
L_1146:{ // JNZ 0x00001154
c.pc=0x1146;if(!sl_tick(c))return int(c.fault);
P_1146_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_1146_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_1154;}
P_1146_2:;
goto L_1148;
}
L_1148:{ // MOV EAX,dword ptr [EBP + -0x20]
c.pc=0x1148;if(!sl_tick(c))return int(c.fault);
P_1148_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_1148_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1148_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1148_3:;
goto L_114b;
}
L_114b:{ // AND EAX,0x2a
c.pc=0x114b;if(!sl_tick(c))return int(c.fault);
P_114b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_114b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_114b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0x2aULL)),c);
P_114b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_114b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_114b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_114b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_114b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_114b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_114b_9:;
goto L_114e;
}
L_114e:{ // TEST EAX,EAX
c.pc=0x114e;if(!sl_tick(c))return int(c.fault);
P_114e_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_114e_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_114e_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_114e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_114e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_114e_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_114e_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_114e_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_114e_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_114e_9:;
goto L_1150;
}
L_1150:{ // JNZ 0x0000115e
c.pc=0x1150;if(!sl_tick(c))return int(c.fault);
P_1150_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_1150_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_115e;}
P_1150_2:;
goto L_1152;
}
L_1152:{ // JMP 0x0000116f
c.pc=0x1152;if(!sl_tick(c))return int(c.fault);
P_1152_0:;
goto L_116f;
P_1152_1:;
goto L_1154;
}
L_1154:{ // MOV EAX,dword ptr [EBP + -0xc]
c.pc=0x1154;if(!sl_tick(c))return int(c.fault);
P_1154_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_1154_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1154_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1154_3:;
goto L_1157;
}
L_1157:{ // MOV EAX,dword ptr [EAX + 0x4]
c.pc=0x1157;if(!sl_tick(c))return int(c.fault);
P_1157_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_1157_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1157_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1157_3:;
goto L_115a;
}
L_115a:{ // CALL EAX
c.pc=0x115a;if(!sl_tick(c))return int(c.fault);
P_115a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_115a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_115a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x115cULL),c);
P_115a_3:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_115a_4:;
goto L_115c;
}
L_115c:{ // JMP 0x0000116f
c.pc=0x115c;if(!sl_tick(c))return int(c.fault);
P_115c_0:;
goto L_116f;
P_115c_1:;
goto L_115e;
}
L_115e:{ // MOV EAX,dword ptr [EBP + -0xc]
c.pc=0x115e;if(!sl_tick(c))return int(c.fault);
P_115e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_115e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_115e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_115e_3:;
goto L_1161;
}
L_1161:{ // MOV EDX,dword ptr [EAX + 0x4]
c.pc=0x1161;if(!sl_tick(c))return int(c.fault);
P_1161_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_1161_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1161_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1161_3:;
goto L_1164;
}
L_1164:{ // MOV EAX,dword ptr [EBP + -0xc]
c.pc=0x1164;if(!sl_tick(c))return int(c.fault);
P_1164_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_1164_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1164_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1164_3:;
goto L_1167;
}
L_1167:{ // MOV EAX,dword ptr [EAX + 0xc]
c.pc=0x1167;if(!sl_tick(c))return int(c.fault);
P_1167_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xcULL)),c);
P_1167_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1167_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1167_3:;
goto L_116a;
}
L_116a:{ // MOV dword ptr [ESP],EAX
c.pc=0x116a;if(!sl_tick(c))return int(c.fault);
P_116a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_116a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_116a_2:;
goto L_116d;
}
L_116d:{ // CALL EDX
c.pc=0x116d;if(!sl_tick(c))return int(c.fault);
P_116d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_116d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_116d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x116fULL),c);
P_116d_3:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_116d_4:;
goto L_116f;
}
L_116f:{ // MOV EAX,dword ptr [EBP + -0xc]
c.pc=0x116f;if(!sl_tick(c))return int(c.fault);
P_116f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_116f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_116f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_116f_3:;
goto L_1172;
}
L_1172:{ // MOV dword ptr [ESP],EAX
c.pc=0x1172;if(!sl_tick(c))return int(c.fault);
P_1172_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1172_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1172_2:;
goto L_1175;
}
L_1175:{ // CALL 0x0010300a
c.pc=0x1175;if(!sl_tick(c))return int(c.fault);
P_1175_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1175_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x117aULL),c);
P_1175_2:;
c.pc=0x10300a;goto dispatch;
P_1175_3:;
goto L_117a;
}
L_117a:{ // MOV dword ptr [ESP],0xe
c.pc=0x117a;if(!sl_tick(c))return int(c.fault);
P_117a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xeULL),c);
P_117a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_117a_2:;
goto L_1181;
}
L_1181:{ // CALL 0x00103005
c.pc=0x1181;if(!sl_tick(c))return int(c.fault);
P_1181_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1181_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x1186ULL),c);
P_1181_2:;
c.pc=0x103005;goto dispatch;
P_1181_3:;
goto L_1186;
}
L_1186:{ // MOV dword ptr [EBP + 0x8],EAX
c.pc=0x1186;if(!sl_tick(c))return int(c.fault);
P_1186_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_1186_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1186_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1186_3:;
goto L_1189;
}
L_1189:{ // CMP dword ptr [EBP + 0x8],0x0
c.pc=0x1189;if(!sl_tick(c))return int(c.fault);
P_1189_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_1189_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1189_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_1189_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_1189_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_1189_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_1189_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1189_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_1189_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_1189_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1189_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1189_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1189_12:;
goto L_118d;
}
L_118d:{ // JNZ 0x000010e2
c.pc=0x118d;if(!sl_tick(c))return int(c.fault);
P_118d_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_118d_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_10e2;}
P_118d_2:;
goto L_1193;
}
L_1193:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x1193;if(!sl_tick(c))return int(c.fault);
P_1193_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_1193_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1193_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1193_3:;
goto L_1196;
}
L_1196:{ // LEAVE
c.pc=0x1196;if(!sl_tick(c))return int(c.fault);
P_1196_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_1196_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_1196_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_1196_3:;
goto L_1197;
}
L_1197:{ // RET
c.pc=0x1197;if(!sl_tick(c))return int(c.fault);
P_1197_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_1197_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_1197_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_1197_3:;
goto L_1198;
}
L_1198:{ // PUSH EBP
c.pc=0x1198;if(!sl_tick(c))return int(c.fault);
P_1198_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_1198_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1198_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_1198_3:;
goto L_1199;
}
L_1199:{ // MOV EBP,ESP
c.pc=0x1199;if(!sl_tick(c))return int(c.fault);
P_1199_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_1199_1:;
goto L_119b;
}
L_119b:{ // SUB ESP,0x28
c.pc=0x119b;if(!sl_tick(c))return int(c.fault);
P_119b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x28ULL)),c);
P_119b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x28ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x28ULL)))&(SlU(1)<<31))!=0),c);
P_119b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x28ULL)),c);
P_119b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_119b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_119b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_119b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_119b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_119b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_119b_9:;
goto L_119e;
}
L_119e:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x119e;if(!sl_tick(c))return int(c.fault);
P_119e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_119e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_119e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_119e_3:;
goto L_11a1;
}
L_11a1:{ // MOV dword ptr [EBP + -0x18],EAX
c.pc=0x11a1;if(!sl_tick(c))return int(c.fault);
P_11a1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_11a1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_11a1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_11a1_3:;
goto L_11a4;
}
L_11a4:{ // MOV dword ptr [EBP + -0x10],0x0
c.pc=0x11a4;if(!sl_tick(c))return int(c.fault);
P_11a4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_11a4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_11a4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_11a4_3:;
goto L_11ab;
}
L_11ab:{ // MOV byte ptr [EBP + -0x9],0x0
c.pc=0x11ab;if(!sl_tick(c))return int(c.fault);
P_11ab_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff7ULL)),c);
P_11ab_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_11ab_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_11ab_3:;
goto L_11af;
}
L_11af:{ // MOV dword ptr [ESP],0xe
c.pc=0x11af;if(!sl_tick(c))return int(c.fault);
P_11af_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xeULL),c);
P_11af_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_11af_2:;
goto L_11b6;
}
L_11b6:{ // CALL 0x00103005
c.pc=0x11b6;if(!sl_tick(c))return int(c.fault);
P_11b6_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_11b6_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x11bbULL),c);
P_11b6_2:;
c.pc=0x103005;goto dispatch;
P_11b6_3:;
goto L_11bb;
}
L_11bb:{ // MOV dword ptr [EBP + -0x14],EAX
c.pc=0x11bb;if(!sl_tick(c))return int(c.fault);
P_11bb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_11bb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_11bb_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_11bb_3:;
goto L_11be;
}
L_11be:{ // CMP dword ptr [EBP + -0x14],0x0
c.pc=0x11be;if(!sl_tick(c))return int(c.fault);
P_11be_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_11be_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_11be_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_11be_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_11be_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_11be_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_11be_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_11be_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_11be_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_11be_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_11be_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_11be_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_11be_12:;
goto L_11c2;
}
L_11c2:{ // JZ 0x000011f1
c.pc=0x11c2;if(!sl_tick(c))return int(c.fault);
P_11c2_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_11f1;}
P_11c2_1:;
goto L_11c4;
}
L_11c4:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0x11c4;if(!sl_tick(c))return int(c.fault);
P_11c4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_11c4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_11c4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_11c4_3:;
goto L_11c7;
}
L_11c7:{ // MOVZX EAX,byte ptr [EAX + 0x2]
c.pc=0x11c7;if(!sl_tick(c))return int(c.fault);
P_11c7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x2ULL)),c);
P_11c7_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_11c7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_11c7_3:;
goto L_11cb;
}
L_11cb:{ // MOV byte ptr [EBP + -0x9],AL
c.pc=0x11cb;if(!sl_tick(c))return int(c.fault);
P_11cb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff7ULL)),c);
P_11cb_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,sl_get<1>(c.reg,sizeof(c.reg),0x0,c),c);
P_11cb_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5100,c),c);
P_11cb_3:;
goto L_11ce;
}
L_11ce:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0x11ce;if(!sl_tick(c))return int(c.fault);
P_11ce_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_11ce_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_11ce_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_11ce_3:;
goto L_11d1;
}
L_11d1:{ // MOV byte ptr [EAX + 0x2],0x1
c.pc=0x11d1;if(!sl_tick(c))return int(c.fault);
P_11d1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x2ULL)),c);
P_11d1_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x1ULL),c);
P_11d1_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_11d1_3:;
goto L_11d5;
}
L_11d5:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0x11d5;if(!sl_tick(c))return int(c.fault);
P_11d5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_11d5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_11d5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_11d5_3:;
goto L_11d8;
}
L_11d8:{ // MOV EAX,dword ptr [EAX + 0x4]
c.pc=0x11d8;if(!sl_tick(c))return int(c.fault);
P_11d8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_11d8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_11d8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_11d8_3:;
goto L_11db;
}
L_11db:{ // MOV dword ptr [EBP + -0x10],EAX
c.pc=0x11db;if(!sl_tick(c))return int(c.fault);
P_11db_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_11db_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_11db_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_11db_3:;
goto L_11de;
}
L_11de:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0x11de;if(!sl_tick(c))return int(c.fault);
P_11de_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_11de_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_11de_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_11de_3:;
goto L_11e1;
}
L_11e1:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x11e1;if(!sl_tick(c))return int(c.fault);
P_11e1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_11e1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_11e1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_11e1_3:;
goto L_11e5;
}
L_11e5:{ // MOV dword ptr [ESP],0xe
c.pc=0x11e5;if(!sl_tick(c))return int(c.fault);
P_11e5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xeULL),c);
P_11e5_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_11e5_2:;
goto L_11ec;
}
L_11ec:{ // CALL 0x00103014
c.pc=0x11ec;if(!sl_tick(c))return int(c.fault);
P_11ec_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_11ec_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x11f1ULL),c);
P_11ec_2:;
c.pc=0x103014;goto dispatch;
P_11ec_3:;
goto L_11f1;
}
L_11f1:{ // MOV EAX,dword ptr [EBP + -0x18]
c.pc=0x11f1;if(!sl_tick(c))return int(c.fault);
P_11f1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_11f1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_11f1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_11f1_3:;
goto L_11f4;
}
L_11f4:{ // MOV EAX,dword ptr [EAX + 0x4]
c.pc=0x11f4;if(!sl_tick(c))return int(c.fault);
P_11f4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_11f4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_11f4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_11f4_3:;
goto L_11f7;
}
L_11f7:{ // TEST EAX,EAX
c.pc=0x11f7;if(!sl_tick(c))return int(c.fault);
P_11f7_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_11f7_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_11f7_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_11f7_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_11f7_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_11f7_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_11f7_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_11f7_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_11f7_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_11f7_9:;
goto L_11f9;
}
L_11f9:{ // JZ 0x0000120d
c.pc=0x11f9;if(!sl_tick(c))return int(c.fault);
P_11f9_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_120d;}
P_11f9_1:;
goto L_11fb;
}
L_11fb:{ // MOV EAX,dword ptr [EBP + -0x18]
c.pc=0x11fb;if(!sl_tick(c))return int(c.fault);
P_11fb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_11fb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_11fb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_11fb_3:;
goto L_11fe;
}
L_11fe:{ // MOV EDX,dword ptr [EAX]
c.pc=0x11fe;if(!sl_tick(c))return int(c.fault);
P_11fe_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_11fe_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_11fe_2:;
goto L_1200;
}
L_1200:{ // MOV EAX,dword ptr [EBP + -0x18]
c.pc=0x1200;if(!sl_tick(c))return int(c.fault);
P_1200_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_1200_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1200_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1200_3:;
goto L_1203;
}
L_1203:{ // MOV EAX,dword ptr [EAX + 0x8]
c.pc=0x1203;if(!sl_tick(c))return int(c.fault);
P_1203_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_1203_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1203_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1203_3:;
goto L_1206;
}
L_1206:{ // MOV dword ptr [ESP],EAX
c.pc=0x1206;if(!sl_tick(c))return int(c.fault);
P_1206_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1206_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1206_2:;
goto L_1209;
}
L_1209:{ // CALL EDX
c.pc=0x1209;if(!sl_tick(c))return int(c.fault);
P_1209_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_1209_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1209_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x120bULL),c);
P_1209_3:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_1209_4:;
goto L_120b;
}
L_120b:{ // JMP 0x00001214
c.pc=0x120b;if(!sl_tick(c))return int(c.fault);
P_120b_0:;
goto L_1214;
P_120b_1:;
goto L_120d;
}
L_120d:{ // MOV EAX,dword ptr [EBP + -0x18]
c.pc=0x120d;if(!sl_tick(c))return int(c.fault);
P_120d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_120d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_120d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_120d_3:;
goto L_1210;
}
L_1210:{ // MOV EAX,dword ptr [EAX]
c.pc=0x1210;if(!sl_tick(c))return int(c.fault);
P_1210_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_1210_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1210_2:;
goto L_1212;
}
L_1212:{ // CALL EAX
c.pc=0x1212;if(!sl_tick(c))return int(c.fault);
P_1212_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1212_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1212_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x1214ULL),c);
P_1212_3:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_1212_4:;
goto L_1214;
}
L_1214:{ // CMP dword ptr [EBP + -0x14],0x0
c.pc=0x1214;if(!sl_tick(c))return int(c.fault);
P_1214_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_1214_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1214_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_1214_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_1214_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_1214_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_1214_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1214_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_1214_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_1214_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1214_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1214_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1214_12:;
goto L_1218;
}
L_1218:{ // JZ 0x00001229
c.pc=0x1218;if(!sl_tick(c))return int(c.fault);
P_1218_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_1229;}
P_1218_1:;
goto L_121a;
}
L_121a:{ // MOV dword ptr [ESP],0xe
c.pc=0x121a;if(!sl_tick(c))return int(c.fault);
P_121a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xeULL),c);
P_121a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_121a_2:;
goto L_1221;
}
L_1221:{ // CALL 0x00103005
c.pc=0x1221;if(!sl_tick(c))return int(c.fault);
P_1221_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1221_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x1226ULL),c);
P_1221_2:;
c.pc=0x103005;goto dispatch;
P_1221_3:;
goto L_1226;
}
L_1226:{ // MOV dword ptr [EBP + -0x14],EAX
c.pc=0x1226;if(!sl_tick(c))return int(c.fault);
P_1226_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_1226_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1226_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1226_3:;
goto L_1229;
}
L_1229:{ // CMP dword ptr [EBP + -0x14],0x0
c.pc=0x1229;if(!sl_tick(c))return int(c.fault);
P_1229_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_1229_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1229_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_1229_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_1229_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_1229_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_1229_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1229_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_1229_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_1229_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1229_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1229_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1229_12:;
goto L_122d;
}
L_122d:{ // JZ 0x00001244
c.pc=0x122d;if(!sl_tick(c))return int(c.fault);
P_122d_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_1244;}
P_122d_1:;
goto L_122f;
}
L_122f:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0x122f;if(!sl_tick(c))return int(c.fault);
P_122f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_122f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_122f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_122f_3:;
goto L_1232;
}
L_1232:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x1232;if(!sl_tick(c))return int(c.fault);
P_1232_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_1232_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1232_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1232_3:;
goto L_1236;
}
L_1236:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0x1236;if(!sl_tick(c))return int(c.fault);
P_1236_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_1236_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1236_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1236_3:;
goto L_1239;
}
L_1239:{ // MOV dword ptr [ESP],EAX
c.pc=0x1239;if(!sl_tick(c))return int(c.fault);
P_1239_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1239_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1239_2:;
goto L_123c;
}
L_123c:{ // CALL 0x000010dc
c.pc=0x123c;if(!sl_tick(c))return int(c.fault);
P_123c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_123c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x1241ULL),c);
P_123c_2:;
goto L_10dc;
P_123c_3:;
goto L_1241;
}
L_1241:{ // MOV dword ptr [EBP + -0x14],EAX
c.pc=0x1241;if(!sl_tick(c))return int(c.fault);
P_1241_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_1241_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1241_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1241_3:;
goto L_1244;
}
L_1244:{ // CMP dword ptr [EBP + -0x14],0x0
c.pc=0x1244;if(!sl_tick(c))return int(c.fault);
P_1244_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_1244_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1244_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_1244_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_1244_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_1244_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_1244_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1244_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_1244_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_1244_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1244_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1244_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1244_12:;
goto L_1248;
}
L_1248:{ // JZ 0x00001267
c.pc=0x1248;if(!sl_tick(c))return int(c.fault);
P_1248_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_1267;}
P_1248_1:;
goto L_124a;
}
L_124a:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0x124a;if(!sl_tick(c))return int(c.fault);
P_124a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_124a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_124a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_124a_3:;
goto L_124d;
}
L_124d:{ // MOVZX EDX,byte ptr [EBP + -0x9]
c.pc=0x124d;if(!sl_tick(c))return int(c.fault);
P_124d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff7ULL)),c);
P_124d_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_124d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_124d_3:;
goto L_1251;
}
L_1251:{ // MOV byte ptr [EAX + 0x2],DL
c.pc=0x1251;if(!sl_tick(c))return int(c.fault);
P_1251_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x2ULL)),c);
P_1251_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,sl_get<1>(c.reg,sizeof(c.reg),0x8,c),c);
P_1251_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5100,c),c);
P_1251_3:;
goto L_1254;
}
L_1254:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0x1254;if(!sl_tick(c))return int(c.fault);
P_1254_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_1254_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1254_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1254_3:;
goto L_1257;
}
L_1257:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x1257;if(!sl_tick(c))return int(c.fault);
P_1257_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_1257_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1257_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1257_3:;
goto L_125b;
}
L_125b:{ // MOV dword ptr [ESP],0xe
c.pc=0x125b;if(!sl_tick(c))return int(c.fault);
P_125b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xeULL),c);
P_125b_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_125b_2:;
goto L_1262;
}
L_1262:{ // CALL 0x00103014
c.pc=0x1262;if(!sl_tick(c))return int(c.fault);
P_1262_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1262_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x1267ULL),c);
P_1262_2:;
c.pc=0x103014;goto dispatch;
P_1262_3:;
goto L_1267;
}
L_1267:{ // LEAVE
c.pc=0x1267;if(!sl_tick(c))return int(c.fault);
P_1267_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_1267_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_1267_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_1267_3:;
goto L_1268;
}
L_1268:{ // RET
c.pc=0x1268;if(!sl_tick(c))return int(c.fault);
P_1268_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_1268_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_1268_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_1268_3:;
goto L_1269;
}
L_1269:{ // PUSH EBP
c.pc=0x1269;if(!sl_tick(c))return int(c.fault);
P_1269_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_1269_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1269_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_1269_3:;
goto L_126a;
}
L_126a:{ // MOV EBP,ESP
c.pc=0x126a;if(!sl_tick(c))return int(c.fault);
P_126a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_126a_1:;
goto L_126c;
}
L_126c:{ // PUSH EBX
c.pc=0x126c;if(!sl_tick(c))return int(c.fault);
P_126c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_126c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_126c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_126c_3:;
goto L_126d;
}
L_126d:{ // SUB ESP,0x44
c.pc=0x126d;if(!sl_tick(c))return int(c.fault);
P_126d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x44ULL)),c);
P_126d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x44ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x44ULL)))&(SlU(1)<<31))!=0),c);
P_126d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x44ULL)),c);
P_126d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_126d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_126d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_126d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_126d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_126d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_126d_9:;
goto L_1270;
}
L_1270:{ // CALL 0x000c086c
c.pc=0x1270;if(!sl_tick(c))return int(c.fault);
P_1270_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1270_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x1275ULL),c);
P_1270_2:;
c.pc=0xc086c;goto dispatch;
P_1270_3:;
goto L_1275;
}
L_1275:{ // CALL 0x00000ed6
c.pc=0x1275;if(!sl_tick(c))return int(c.fault);
P_1275_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1275_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x127aULL),c);
P_1275_2:;
goto L_ed6;
P_1275_3:;
goto L_127a;
}
L_127a:{ // MOV dword ptr [EBP + -0x24],EAX
c.pc=0x127a;if(!sl_tick(c))return int(c.fault);
P_127a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_127a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_127a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_127a_3:;
goto L_127d;
}
L_127d:{ // CMP dword ptr [EBP + -0x24],0x0
c.pc=0x127d;if(!sl_tick(c))return int(c.fault);
P_127d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_127d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_127d_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_127d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_127d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_127d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_127d_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_127d_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_127d_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_127d_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_127d_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_127d_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_127d_12:;
goto L_1281;
}
L_1281:{ // JNZ 0x0000128f
c.pc=0x1281;if(!sl_tick(c))return int(c.fault);
P_1281_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_1281_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_128f;}
P_1281_2:;
goto L_1283;
}
L_1283:{ // MOV dword ptr [EBP + -0x2c],0xffffffff
c.pc=0x1283;if(!sl_tick(c))return int(c.fault);
P_1283_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_1283_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xffffffffULL),c);
P_1283_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_1283_3:;
goto L_128a;
}
L_128a:{ // JMP 0x000013f6
c.pc=0x128a;if(!sl_tick(c))return int(c.fault);
P_128a_0:;
goto L_13f6;
P_128a_1:;
goto L_128f;
}
L_128f:{ // MOV EAX,dword ptr [EBP + -0x24]
c.pc=0x128f;if(!sl_tick(c))return int(c.fault);
P_128f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_128f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_128f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_128f_3:;
goto L_1292;
}
L_1292:{ // MOVZX EAX,byte ptr [EAX + 0x2]
c.pc=0x1292;if(!sl_tick(c))return int(c.fault);
P_1292_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x2ULL)),c);
P_1292_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1292_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_1292_3:;
goto L_1296;
}
L_1296:{ // TEST AL,AL
c.pc=0x1296;if(!sl_tick(c))return int(c.fault);
P_1296_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_1296_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_1296_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x54d80,(sl_get<1>(c.reg,sizeof(c.reg),0x0,c) & sl_get<1>(c.reg,sizeof(c.reg),0x0,c)),c);
P_1296_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_1296_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c) == SlU(0x0ULL)),c);
P_1296_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c) & SlU(0xffULL)),c);
P_1296_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1296_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1296_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1296_9:;
goto L_1298;
}
L_1298:{ // JNZ 0x000012a5
c.pc=0x1298;if(!sl_tick(c))return int(c.fault);
P_1298_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_1298_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_12a5;}
P_1298_2:;
goto L_129a;
}
L_129a:{ // MOV EAX,dword ptr [EBP + -0x24]
c.pc=0x129a;if(!sl_tick(c))return int(c.fault);
P_129a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_129a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_129a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_129a_3:;
goto L_129d;
}
L_129d:{ // MOVZX EAX,byte ptr [EAX + 0x3]
c.pc=0x129d;if(!sl_tick(c))return int(c.fault);
P_129d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x3ULL)),c);
P_129d_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_129d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_129d_3:;
goto L_12a1;
}
L_12a1:{ // CMP AL,0x1
c.pc=0x12a1;if(!sl_tick(c))return int(c.fault);
P_12a1_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.reg,sizeof(c.reg),0x0,c) < SlU(0x1ULL)),c);
P_12a1_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.reg,sizeof(c.reg),0x0,c)^SlU(0x1ULL))&(sl_get<1>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<1>(c.reg,sizeof(c.reg),0x0,c)-SlU(0x1ULL)))&(SlU(1)<<7))!=0),c);
P_12a1_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30500,(sl_get<1>(c.reg,sizeof(c.reg),0x0,c) - SlU(0x1ULL)),c);
P_12a1_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30500,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_12a1_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30500,c) == SlU(0x0ULL)),c);
P_12a1_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30500,c) & SlU(0xffULL)),c);
P_12a1_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_12a1_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_12a1_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_12a1_9:;
goto L_12a3;
}
L_12a3:{ // JNZ 0x000012bf
c.pc=0x12a3;if(!sl_tick(c))return int(c.fault);
P_12a3_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_12a3_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_12bf;}
P_12a3_2:;
goto L_12a5;
}
L_12a5:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x12a5;if(!sl_tick(c))return int(c.fault);
P_12a5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_12a5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_12a5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_12a5_3:;
goto L_12a8;
}
L_12a8:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x12a8;if(!sl_tick(c))return int(c.fault);
P_12a8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_12a8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_12a8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_12a8_3:;
goto L_12ac;
}
L_12ac:{ // MOV EAX,dword ptr [EBP + -0x24]
c.pc=0x12ac;if(!sl_tick(c))return int(c.fault);
P_12ac_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_12ac_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_12ac_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_12ac_3:;
goto L_12af;
}
L_12af:{ // MOV dword ptr [ESP],EAX
c.pc=0x12af;if(!sl_tick(c))return int(c.fault);
P_12af_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_12af_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_12af_2:;
goto L_12b2;
}
L_12b2:{ // CALL 0x00001043
c.pc=0x12b2;if(!sl_tick(c))return int(c.fault);
P_12b2_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_12b2_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x12b7ULL),c);
P_12b2_2:;
goto L_1043;
P_12b2_3:;
goto L_12b7;
}
L_12b7:{ // MOV dword ptr [EBP + -0x2c],EAX
c.pc=0x12b7;if(!sl_tick(c))return int(c.fault);
P_12b7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_12b7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_12b7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_12b7_3:;
goto L_12ba;
}
L_12ba:{ // JMP 0x000013f6
c.pc=0x12ba;if(!sl_tick(c))return int(c.fault);
P_12ba_0:;
goto L_13f6;
P_12ba_1:;
goto L_12bf;
}
L_12bf:{ // MOV EAX,dword ptr [EBP + -0x24]
c.pc=0x12bf;if(!sl_tick(c))return int(c.fault);
P_12bf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_12bf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_12bf_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_12bf_3:;
goto L_12c2;
}
L_12c2:{ // MOVZX EAX,byte ptr [EAX + 0x3]
c.pc=0x12c2;if(!sl_tick(c))return int(c.fault);
P_12c2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x3ULL)),c);
P_12c2_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_12c2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_12c2_3:;
goto L_12c6;
}
L_12c6:{ // CMP AL,0xf
c.pc=0x12c6;if(!sl_tick(c))return int(c.fault);
P_12c6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.reg,sizeof(c.reg),0x0,c) < SlU(0xfULL)),c);
P_12c6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.reg,sizeof(c.reg),0x0,c)^SlU(0xfULL))&(sl_get<1>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<1>(c.reg,sizeof(c.reg),0x0,c)-SlU(0xfULL)))&(SlU(1)<<7))!=0),c);
P_12c6_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30500,(sl_get<1>(c.reg,sizeof(c.reg),0x0,c) - SlU(0xfULL)),c);
P_12c6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30500,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_12c6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30500,c) == SlU(0x0ULL)),c);
P_12c6_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30500,c) & SlU(0xffULL)),c);
P_12c6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_12c6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_12c6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_12c6_9:;
goto L_12c8;
}
L_12c8:{ // JBE 0x00001375
c.pc=0x12c8;if(!sl_tick(c))return int(c.fault);
P_12c8_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9d00,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x200,c)) || bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c))),c);
P_12c8_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9d00,c)){goto L_1375;}
P_12c8_2:;
goto L_12ce;
}
L_12ce:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x12ce;if(!sl_tick(c))return int(c.fault);
P_12ce_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_12ce_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_12ce_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_12ce_3:;
goto L_12d1;
}
L_12d1:{ // MOV EAX,dword ptr [EAX + 0x4]
c.pc=0x12d1;if(!sl_tick(c))return int(c.fault);
P_12d1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_12d1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_12d1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_12d1_3:;
goto L_12d4;
}
L_12d4:{ // TEST EAX,EAX
c.pc=0x12d4;if(!sl_tick(c))return int(c.fault);
P_12d4_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_12d4_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_12d4_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_12d4_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_12d4_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_12d4_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_12d4_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_12d4_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_12d4_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_12d4_9:;
goto L_12d6;
}
L_12d6:{ // JZ 0x0000132f
c.pc=0x12d6;if(!sl_tick(c))return int(c.fault);
P_12d6_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_132f;}
P_12d6_1:;
goto L_12d8;
}
L_12d8:{ // MOV EAX,dword ptr [EBP + -0x24]
c.pc=0x12d8;if(!sl_tick(c))return int(c.fault);
P_12d8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_12d8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_12d8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_12d8_3:;
goto L_12db;
}
L_12db:{ // MOV EAX,dword ptr [EAX + 0x8]
c.pc=0x12db;if(!sl_tick(c))return int(c.fault);
P_12db_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_12db_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_12db_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_12db_3:;
goto L_12de;
}
L_12de:{ // MOV dword ptr [EBP + -0x1c],EAX
c.pc=0x12de;if(!sl_tick(c))return int(c.fault);
P_12de_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_12de_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_12de_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_12de_3:;
goto L_12e1;
}
L_12e1:{ // MOV EAX,dword ptr [EBP + -0x24]
c.pc=0x12e1;if(!sl_tick(c))return int(c.fault);
P_12e1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_12e1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_12e1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_12e1_3:;
goto L_12e4;
}
L_12e4:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x12e4;if(!sl_tick(c))return int(c.fault);
P_12e4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_12e4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_12e4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_12e4_3:;
goto L_12e8;
}
L_12e8:{ // MOV dword ptr [ESP],0xe
c.pc=0x12e8;if(!sl_tick(c))return int(c.fault);
P_12e8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xeULL),c);
P_12e8_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_12e8_2:;
goto L_12ef;
}
L_12ef:{ // CALL 0x00103014
c.pc=0x12ef;if(!sl_tick(c))return int(c.fault);
P_12ef_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_12ef_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x12f4ULL),c);
P_12ef_2:;
c.pc=0x103014;goto dispatch;
P_12ef_3:;
goto L_12f4;
}
L_12f4:{ // MOV dword ptr [EBP + -0x20],EAX
c.pc=0x12f4;if(!sl_tick(c))return int(c.fault);
P_12f4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_12f4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_12f4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_12f4_3:;
goto L_12f7;
}
L_12f7:{ // CMP dword ptr [EBP + -0x20],0x0
c.pc=0x12f7;if(!sl_tick(c))return int(c.fault);
P_12f7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_12f7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_12f7_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_12f7_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_12f7_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_12f7_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_12f7_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_12f7_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_12f7_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_12f7_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_12f7_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_12f7_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_12f7_12:;
goto L_12fb;
}
L_12fb:{ // JZ 0x00001309
c.pc=0x12fb;if(!sl_tick(c))return int(c.fault);
P_12fb_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_1309;}
P_12fb_1:;
goto L_12fd;
}
L_12fd:{ // MOV dword ptr [EBP + -0x2c],0xffffffff
c.pc=0x12fd;if(!sl_tick(c))return int(c.fault);
P_12fd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_12fd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xffffffffULL),c);
P_12fd_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_12fd_3:;
goto L_1304;
}
L_1304:{ // JMP 0x000013f6
c.pc=0x1304;if(!sl_tick(c))return int(c.fault);
P_1304_0:;
goto L_13f6;
P_1304_1:;
goto L_1309;
}
L_1309:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x1309;if(!sl_tick(c))return int(c.fault);
P_1309_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_1309_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1309_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1309_3:;
goto L_130c;
}
L_130c:{ // MOV EDX,dword ptr [EAX + 0x8]
c.pc=0x130c;if(!sl_tick(c))return int(c.fault);
P_130c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_130c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_130c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_130c_3:;
goto L_130f;
}
L_130f:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x130f;if(!sl_tick(c))return int(c.fault);
P_130f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_130f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_130f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_130f_3:;
goto L_1312;
}
L_1312:{ // MOV ECX,dword ptr [EAX]
c.pc=0x1312;if(!sl_tick(c))return int(c.fault);
P_1312_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_1312_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1312_2:;
goto L_1314;
}
L_1314:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0x1314;if(!sl_tick(c))return int(c.fault);
P_1314_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_1314_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1314_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1314_3:;
goto L_1317;
}
L_1317:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x1317;if(!sl_tick(c))return int(c.fault);
P_1317_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_1317_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1317_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1317_3:;
goto L_131b;
}
L_131b:{ // MOV dword ptr [ESP + 0x4],EDX
c.pc=0x131b;if(!sl_tick(c))return int(c.fault);
P_131b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_131b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_131b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_131b_3:;
goto L_131f;
}
L_131f:{ // MOV dword ptr [ESP],ECX
c.pc=0x131f;if(!sl_tick(c))return int(c.fault);
P_131f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_131f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_131f_2:;
goto L_1322;
}
L_1322:{ // MOV EAX,dword ptr [EBP + -0x1c]
c.pc=0x1322;if(!sl_tick(c))return int(c.fault);
P_1322_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_1322_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1322_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1322_3:;
goto L_1325;
}
L_1325:{ // CALL EAX
c.pc=0x1325;if(!sl_tick(c))return int(c.fault);
P_1325_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1325_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1325_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x1327ULL),c);
P_1325_3:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_1325_4:;
goto L_1327;
}
L_1327:{ // MOV dword ptr [EBP + -0x2c],EAX
c.pc=0x1327;if(!sl_tick(c))return int(c.fault);
P_1327_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_1327_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1327_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1327_3:;
goto L_132a;
}
L_132a:{ // JMP 0x000013f6
c.pc=0x132a;if(!sl_tick(c))return int(c.fault);
P_132a_0:;
goto L_13f6;
P_132a_1:;
goto L_132f;
}
L_132f:{ // MOV EAX,dword ptr [EBP + -0x24]
c.pc=0x132f;if(!sl_tick(c))return int(c.fault);
P_132f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_132f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_132f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_132f_3:;
goto L_1332;
}
L_1332:{ // MOV EAX,dword ptr [EAX + 0x10]
c.pc=0x1332;if(!sl_tick(c))return int(c.fault);
P_1332_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x10ULL)),c);
P_1332_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1332_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1332_3:;
goto L_1335;
}
L_1335:{ // MOV dword ptr [EBP + -0x18],EAX
c.pc=0x1335;if(!sl_tick(c))return int(c.fault);
P_1335_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_1335_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1335_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1335_3:;
goto L_1338;
}
L_1338:{ // MOV EAX,dword ptr [EBP + -0x24]
c.pc=0x1338;if(!sl_tick(c))return int(c.fault);
P_1338_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_1338_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1338_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1338_3:;
goto L_133b;
}
L_133b:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x133b;if(!sl_tick(c))return int(c.fault);
P_133b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_133b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_133b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_133b_3:;
goto L_133f;
}
L_133f:{ // MOV dword ptr [ESP],0xe
c.pc=0x133f;if(!sl_tick(c))return int(c.fault);
P_133f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xeULL),c);
P_133f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_133f_2:;
goto L_1346;
}
L_1346:{ // CALL 0x00103014
c.pc=0x1346;if(!sl_tick(c))return int(c.fault);
P_1346_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1346_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x134bULL),c);
P_1346_2:;
c.pc=0x103014;goto dispatch;
P_1346_3:;
goto L_134b;
}
L_134b:{ // MOV dword ptr [EBP + -0x20],EAX
c.pc=0x134b;if(!sl_tick(c))return int(c.fault);
P_134b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_134b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_134b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_134b_3:;
goto L_134e;
}
L_134e:{ // CMP dword ptr [EBP + -0x20],0x0
c.pc=0x134e;if(!sl_tick(c))return int(c.fault);
P_134e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_134e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_134e_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_134e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_134e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_134e_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_134e_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_134e_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_134e_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_134e_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_134e_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_134e_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_134e_12:;
goto L_1352;
}
L_1352:{ // JZ 0x00001360
c.pc=0x1352;if(!sl_tick(c))return int(c.fault);
P_1352_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_1360;}
P_1352_1:;
goto L_1354;
}
L_1354:{ // MOV dword ptr [EBP + -0x2c],0xffffffff
c.pc=0x1354;if(!sl_tick(c))return int(c.fault);
P_1354_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_1354_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xffffffffULL),c);
P_1354_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_1354_3:;
goto L_135b;
}
L_135b:{ // JMP 0x000013f6
c.pc=0x135b;if(!sl_tick(c))return int(c.fault);
P_135b_0:;
goto L_13f6;
P_135b_1:;
goto L_1360;
}
L_1360:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x1360;if(!sl_tick(c))return int(c.fault);
P_1360_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_1360_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1360_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1360_3:;
goto L_1363;
}
L_1363:{ // MOV EAX,dword ptr [EAX]
c.pc=0x1363;if(!sl_tick(c))return int(c.fault);
P_1363_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_1363_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1363_2:;
goto L_1365;
}
L_1365:{ // MOV dword ptr [ESP],EAX
c.pc=0x1365;if(!sl_tick(c))return int(c.fault);
P_1365_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1365_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1365_2:;
goto L_1368;
}
L_1368:{ // MOV EAX,dword ptr [EBP + -0x18]
c.pc=0x1368;if(!sl_tick(c))return int(c.fault);
P_1368_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_1368_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1368_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1368_3:;
goto L_136b;
}
L_136b:{ // CALL EAX
c.pc=0x136b;if(!sl_tick(c))return int(c.fault);
P_136b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_136b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_136b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x136dULL),c);
P_136b_3:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_136b_4:;
goto L_136d;
}
L_136d:{ // MOV dword ptr [EBP + -0x2c],EAX
c.pc=0x136d;if(!sl_tick(c))return int(c.fault);
P_136d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_136d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_136d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_136d_3:;
goto L_1370;
}
L_1370:{ // JMP 0x000013f6
c.pc=0x1370;if(!sl_tick(c))return int(c.fault);
P_1370_0:;
goto L_13f6;
P_1370_1:;
goto L_1375;
}
L_1375:{ // MOV EAX,dword ptr [EBP + -0x24]
c.pc=0x1375;if(!sl_tick(c))return int(c.fault);
P_1375_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_1375_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1375_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1375_3:;
goto L_1378;
}
L_1378:{ // MOV EAX,dword ptr [EAX + 0x8]
c.pc=0x1378;if(!sl_tick(c))return int(c.fault);
P_1378_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_1378_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1378_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1378_3:;
goto L_137b;
}
L_137b:{ // MOV dword ptr [EBP + -0x14],EAX
c.pc=0x137b;if(!sl_tick(c))return int(c.fault);
P_137b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_137b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_137b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_137b_3:;
goto L_137e;
}
L_137e:{ // MOV EAX,dword ptr [EBP + -0x24]
c.pc=0x137e;if(!sl_tick(c))return int(c.fault);
P_137e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_137e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_137e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_137e_3:;
goto L_1381;
}
L_1381:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x1381;if(!sl_tick(c))return int(c.fault);
P_1381_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_1381_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1381_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1381_3:;
goto L_1385;
}
L_1385:{ // MOV dword ptr [ESP],0xe
c.pc=0x1385;if(!sl_tick(c))return int(c.fault);
P_1385_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xeULL),c);
P_1385_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_1385_2:;
goto L_138c;
}
L_138c:{ // CALL 0x00103014
c.pc=0x138c;if(!sl_tick(c))return int(c.fault);
P_138c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_138c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x1391ULL),c);
P_138c_2:;
c.pc=0x103014;goto dispatch;
P_138c_3:;
goto L_1391;
}
L_1391:{ // MOV dword ptr [EBP + -0xc],EAX
c.pc=0x1391;if(!sl_tick(c))return int(c.fault);
P_1391_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_1391_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1391_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1391_3:;
goto L_1394;
}
L_1394:{ // CMP dword ptr [EBP + -0xc],0x0
c.pc=0x1394;if(!sl_tick(c))return int(c.fault);
P_1394_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_1394_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1394_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_1394_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_1394_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_1394_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_1394_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1394_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_1394_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_1394_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1394_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1394_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1394_12:;
goto L_1398;
}
L_1398:{ // JZ 0x000013a3
c.pc=0x1398;if(!sl_tick(c))return int(c.fault);
P_1398_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_13a3;}
P_1398_1:;
goto L_139a;
}
L_139a:{ // MOV dword ptr [EBP + -0x2c],0xffffffff
c.pc=0x139a;if(!sl_tick(c))return int(c.fault);
P_139a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_139a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xffffffffULL),c);
P_139a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_139a_3:;
goto L_13a1;
}
L_13a1:{ // JMP 0x000013f6
c.pc=0x13a1;if(!sl_tick(c))return int(c.fault);
P_13a1_0:;
goto L_13f6;
P_13a1_1:;
goto L_13a3;
}
L_13a3:{ // MOV dword ptr [ESP],0xc
c.pc=0x13a3;if(!sl_tick(c))return int(c.fault);
P_13a3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xcULL),c);
P_13a3_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_13a3_2:;
goto L_13aa;
}
L_13aa:{ // CALL 0x0010300f
c.pc=0x13aa;if(!sl_tick(c))return int(c.fault);
P_13aa_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_13aa_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x13afULL),c);
P_13aa_2:;
c.pc=0x10300f;goto dispatch;
P_13aa_3:;
goto L_13af;
}
L_13af:{ // MOV dword ptr [EBP + -0x10],EAX
c.pc=0x13af;if(!sl_tick(c))return int(c.fault);
P_13af_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_13af_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_13af_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_13af_3:;
goto L_13b2;
}
L_13b2:{ // CMP dword ptr [EBP + -0x10],0x0
c.pc=0x13b2;if(!sl_tick(c))return int(c.fault);
P_13b2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_13b2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_13b2_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_13b2_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x0ULL)),c);
P_13b2_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x0ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x0ULL)))&(SlU(1)<<31))!=0),c);
P_13b2_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x0ULL)),c);
P_13b2_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_13b2_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_13b2_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_13b2_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_13b2_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_13b2_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_13b2_12:;
goto L_13b6;
}
L_13b6:{ // JNZ 0x000013c1
c.pc=0x13b6;if(!sl_tick(c))return int(c.fault);
P_13b6_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_13b6_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_13c1;}
P_13b6_2:;
goto L_13b8;
}
L_13b8:{ // MOV dword ptr [EBP + -0x2c],0xffffffff
c.pc=0x13b8;if(!sl_tick(c))return int(c.fault);
P_13b8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_13b8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xffffffffULL),c);
P_13b8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_13b8_3:;
goto L_13bf;
}
L_13bf:{ // JMP 0x000013f6
c.pc=0x13bf;if(!sl_tick(c))return int(c.fault);
P_13bf_0:;
goto L_13f6;
P_13bf_1:;
goto L_13c1;
}
L_13c1:{ // MOV ECX,dword ptr [EBP + -0x10]
c.pc=0x13c1;if(!sl_tick(c))return int(c.fault);
P_13c1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_13c1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_13c1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_13c1_3:;
goto L_13c4;
}
L_13c4:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0x13c4;if(!sl_tick(c))return int(c.fault);
P_13c4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_13c4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_13c4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_13c4_3:;
goto L_13c7;
}
L_13c7:{ // MOV EAX,dword ptr [EDX]
c.pc=0x13c7;if(!sl_tick(c))return int(c.fault);
P_13c7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_13c7_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_13c7_2:;
goto L_13c9;
}
L_13c9:{ // MOV dword ptr [ECX],EAX
c.pc=0x13c9;if(!sl_tick(c))return int(c.fault);
P_13c9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_13c9_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_13c9_2:;
goto L_13cb;
}
L_13cb:{ // MOV EAX,dword ptr [EDX + 0x4]
c.pc=0x13cb;if(!sl_tick(c))return int(c.fault);
P_13cb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x4ULL)),c);
P_13cb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_13cb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_13cb_3:;
goto L_13ce;
}
L_13ce:{ // MOV dword ptr [ECX + 0x4],EAX
c.pc=0x13ce;if(!sl_tick(c))return int(c.fault);
P_13ce_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x4ULL)),c);
P_13ce_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_13ce_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_13ce_3:;
goto L_13d1;
}
L_13d1:{ // MOV EAX,dword ptr [EDX + 0x8]
c.pc=0x13d1;if(!sl_tick(c))return int(c.fault);
P_13d1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x8ULL)),c);
P_13d1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_13d1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_13d1_3:;
goto L_13d4;
}
L_13d4:{ // MOV dword ptr [ECX + 0x8],EAX
c.pc=0x13d4;if(!sl_tick(c))return int(c.fault);
P_13d4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x8ULL)),c);
P_13d4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_13d4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_13d4_3:;
goto L_13d7;
}
L_13d7:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0x13d7;if(!sl_tick(c))return int(c.fault);
P_13d7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_13d7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_13d7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_13d7_3:;
goto L_13da;
}
L_13da:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x13da;if(!sl_tick(c))return int(c.fault);
P_13da_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_13da_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_13da_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_13da_3:;
goto L_13de;
}
L_13de:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0x13de;if(!sl_tick(c))return int(c.fault);
P_13de_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_13de_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_13de_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_13de_3:;
goto L_13e1;
}
L_13e1:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x13e1;if(!sl_tick(c))return int(c.fault);
P_13e1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_13e1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_13e1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_13e1_3:;
goto L_13e5;
}
L_13e5:{ // LEA EAX,[EBX + 0xffffff23]
c.pc=0x13e5;if(!sl_tick(c))return int(c.fault);
P_13e5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xffffff23ULL)),c);
P_13e5_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_13e5_2:;
goto L_13eb;
}
L_13eb:{ // MOV dword ptr [ESP],EAX
c.pc=0x13eb;if(!sl_tick(c))return int(c.fault);
P_13eb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_13eb_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_13eb_2:;
goto L_13ee;
}
L_13ee:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0x13ee;if(!sl_tick(c))return int(c.fault);
P_13ee_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_13ee_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_13ee_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_13ee_3:;
goto L_13f1;
}
L_13f1:{ // CALL EAX
c.pc=0x13f1;if(!sl_tick(c))return int(c.fault);
P_13f1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_13f1_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_13f1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x13f3ULL),c);
P_13f1_3:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_13f1_4:;
goto L_13f3;
}
L_13f3:{ // MOV dword ptr [EBP + -0x2c],EAX
c.pc=0x13f3;if(!sl_tick(c))return int(c.fault);
P_13f3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_13f3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_13f3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_13f3_3:;
goto L_13f6;
}
L_13f6:{ // MOV EAX,dword ptr [EBP + -0x2c]
c.pc=0x13f6;if(!sl_tick(c))return int(c.fault);
P_13f6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_13f6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_13f6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_13f6_3:;
goto L_13f9;
}
L_13f9:{ // ADD ESP,0x44
c.pc=0x13f9;if(!sl_tick(c))return int(c.fault);
P_13f9_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x44ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_13f9_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x44ULL)))&(SlU(0x44ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x44ULL)))&(SlU(1)<<31))!=0),c);
P_13f9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x44ULL)),c);
P_13f9_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_13f9_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_13f9_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_13f9_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_13f9_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_13f9_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_13f9_9:;
goto L_13fc;
}
L_13fc:{ // POP EBX
c.pc=0x13fc;if(!sl_tick(c))return int(c.fault);
P_13fc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_13fc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_13fc_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_13fc_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_13fc_4:;
goto L_13fd;
}
L_13fd:{ // POP EBP
c.pc=0x13fd;if(!sl_tick(c))return int(c.fault);
P_13fd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_13fd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_13fd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_13fd_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_13fd_4:;
goto L_13fe;
}
L_13fe:{ // RET
c.pc=0x13fe;if(!sl_tick(c))return int(c.fault);
P_13fe_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_13fe_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_13fe_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_13fe_3:;
goto L_13ff;
}
L_13ff:{ // PUSH EBP
c.pc=0x13ff;if(!sl_tick(c))return int(c.fault);
P_13ff_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_13ff_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_13ff_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_13ff_3:;
goto L_1400;
}
L_1400:{ // MOV EBP,ESP
c.pc=0x1400;if(!sl_tick(c))return int(c.fault);
P_1400_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_1400_1:;
goto L_1402;
}
L_1402:{ // SUB ESP,0x28
c.pc=0x1402;if(!sl_tick(c))return int(c.fault);
P_1402_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x28ULL)),c);
P_1402_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x28ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x28ULL)))&(SlU(1)<<31))!=0),c);
P_1402_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x28ULL)),c);
P_1402_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1402_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_1402_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_1402_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1402_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1402_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1402_9:;
goto L_1405;
}
L_1405:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x1405;if(!sl_tick(c))return int(c.fault);
P_1405_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_1405_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1405_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1405_3:;
goto L_1408;
}
L_1408:{ // MOV dword ptr [EBP + -0x14],EAX
c.pc=0x1408;if(!sl_tick(c))return int(c.fault);
P_1408_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_1408_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1408_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1408_3:;
goto L_140b;
}
L_140b:{ // MOV dword ptr [EBP + -0x10],0x1
c.pc=0x140b;if(!sl_tick(c))return int(c.fault);
P_140b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_140b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x1ULL),c);
P_140b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_140b_3:;
goto L_1412;
}
L_1412:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0x1412;if(!sl_tick(c))return int(c.fault);
P_1412_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_1412_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1412_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1412_3:;
goto L_1415;
}
L_1415:{ // MOV dword ptr [EBP + -0xc],EAX
c.pc=0x1415;if(!sl_tick(c))return int(c.fault);
P_1415_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_1415_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1415_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1415_3:;
goto L_1418;
}
L_1418:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0x1418;if(!sl_tick(c))return int(c.fault);
P_1418_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_1418_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1418_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1418_3:;
goto L_141b;
}
L_141b:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x141b;if(!sl_tick(c))return int(c.fault);
P_141b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_141b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_141b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_141b_3:;
goto L_141f;
}
L_141f:{ // LEA EAX,[EBP + -0x14]
c.pc=0x141f;if(!sl_tick(c))return int(c.fault);
P_141f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_141f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_141f_2:;
goto L_1422;
}
L_1422:{ // MOV dword ptr [ESP],EAX
c.pc=0x1422;if(!sl_tick(c))return int(c.fault);
P_1422_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1422_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1422_2:;
goto L_1425;
}
L_1425:{ // CALL 0x00001269
c.pc=0x1425;if(!sl_tick(c))return int(c.fault);
P_1425_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1425_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x142aULL),c);
P_1425_2:;
goto L_1269;
P_1425_3:;
goto L_142a;
}
L_142a:{ // LEAVE
c.pc=0x142a;if(!sl_tick(c))return int(c.fault);
P_142a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_142a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_142a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_142a_3:;
goto L_142b;
}
L_142b:{ // RET
c.pc=0x142b;if(!sl_tick(c))return int(c.fault);
P_142b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_142b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_142b_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_142b_3:;
goto L_142c;
}
L_142c:{ // PUSH EBP
c.pc=0x142c;if(!sl_tick(c))return int(c.fault);
P_142c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_142c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_142c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_142c_3:;
goto L_142d;
}
L_142d:{ // MOV EBP,ESP
c.pc=0x142d;if(!sl_tick(c))return int(c.fault);
P_142d_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_142d_1:;
goto L_142f;
}
L_142f:{ // MOV ECX,dword ptr [EBP + 0x8]
c.pc=0x142f;if(!sl_tick(c))return int(c.fault);
P_142f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_142f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_142f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_142f_3:;
goto L_1432;
}
L_1432:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0x1432;if(!sl_tick(c))return int(c.fault);
P_1432_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_1432_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1432_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1432_3:;
goto L_1435;
}
L_1435:{ // MOV EDX,dword ptr [ECX + 0x90]
c.pc=0x1435;if(!sl_tick(c))return int(c.fault);
P_1435_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x90ULL)),c);
P_1435_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_1435_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1435_3:;
goto L_143b;
}
L_143b:{ // TEST EDX,EDX
c.pc=0x143b;if(!sl_tick(c))return int(c.fault);
P_143b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_143b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_143b_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_143b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_143b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_143b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_143b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_143b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_143b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_143b_9:;
goto L_143d;
}
L_143d:{ // JZ 0x00001450
c.pc=0x143d;if(!sl_tick(c))return int(c.fault);
P_143d_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_1450;}
P_143d_1:;
goto L_143f;
}
L_143f:{ // CMP dword ptr [ECX + 0xa4],EAX
c.pc=0x143f;if(!sl_tick(c))return int(c.fault);
P_143f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0xa4ULL)),c);
P_143f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_143f_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_143f_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_143f_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x0,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x0,c)))&(SlU(1)<<31))!=0),c);
P_143f_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_143f_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_143f_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_143f_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_143f_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_143f_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_143f_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_143f_12:;
goto L_1445;
}
L_1445:{ // JLE 0x00001450
c.pc=0x1445;if(!sl_tick(c))return int(c.fault);
P_1445_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_1445_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_1445_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_1450;}
P_1445_3:;
goto L_1447;
}
L_1447:{ // LEA EAX,[EAX + EAX*0x2]
c.pc=0x1447;if(!sl_tick(c))return int(c.fault);
P_1447_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x2ULL)),c);
P_1447_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_1447_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3580,c),c);
P_1447_3:;
goto L_144a;
}
L_144a:{ // MOV ECX,dword ptr [EBP + 0x10]
c.pc=0x144a;if(!sl_tick(c))return int(c.fault);
P_144a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_144a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_144a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_144a_3:;
goto L_144d;
}
L_144d:{ // MOV dword ptr [EDX + EAX*0x8],ECX
c.pc=0x144d;if(!sl_tick(c))return int(c.fault);
P_144d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x8ULL)),c);
P_144d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_144d_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_144d_3:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_144d_4:;
goto L_1450;
}
L_1450:{ // POP EBP
c.pc=0x1450;if(!sl_tick(c))return int(c.fault);
P_1450_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_1450_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_1450_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_1450_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_1450_4:;
goto L_1451;
}
L_1451:{ // RET
c.pc=0x1451;if(!sl_tick(c))return int(c.fault);
P_1451_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_1451_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_1451_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_1451_3:;
goto L_1452;
}
L_1452:{ // PUSH EBP
c.pc=0x1452;if(!sl_tick(c))return int(c.fault);
P_1452_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_1452_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1452_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_1452_3:;
goto L_1453;
}
L_1453:{ // MOV EBP,ESP
c.pc=0x1453;if(!sl_tick(c))return int(c.fault);
P_1453_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_1453_1:;
goto L_1455;
}
L_1455:{ // PUSH EDI
c.pc=0x1455;if(!sl_tick(c))return int(c.fault);
P_1455_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_1455_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1455_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_1455_3:;
goto L_1456;
}
L_1456:{ // PUSH ESI
c.pc=0x1456;if(!sl_tick(c))return int(c.fault);
P_1456_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_1456_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1456_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_1456_3:;
goto L_1457;
}
L_1457:{ // PUSH EBX
c.pc=0x1457;if(!sl_tick(c))return int(c.fault);
P_1457_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_1457_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1457_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_1457_3:;
goto L_1458;
}
L_1458:{ // SUB ESP,0x1c
c.pc=0x1458;if(!sl_tick(c))return int(c.fault);
P_1458_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x1cULL)),c);
P_1458_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x1cULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x1cULL)))&(SlU(1)<<31))!=0),c);
P_1458_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x1cULL)),c);
P_1458_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1458_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_1458_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_1458_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1458_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1458_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1458_9:;
goto L_145b;
}
L_145b:{ // CALL 0x000c086c
c.pc=0x145b;if(!sl_tick(c))return int(c.fault);
P_145b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_145b_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x1460ULL),c);
P_145b_2:;
c.pc=0xc086c;goto dispatch;
P_145b_3:;
goto L_1460;
}
L_1460:{ // MOV EDI,dword ptr [EBP + 0x8]
c.pc=0x1460;if(!sl_tick(c))return int(c.fault);
P_1460_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_1460_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1460_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1460_3:;
goto L_1463;
}
L_1463:{ // LEA EAX,[EBX + 0xe31e8]
c.pc=0x1463;if(!sl_tick(c))return int(c.fault);
P_1463_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xe31e8ULL)),c);
P_1463_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_1463_2:;
goto L_1469;
}
L_1469:{ // MOV dword ptr [EDI],EAX
c.pc=0x1469;if(!sl_tick(c))return int(c.fault);
P_1469_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1469_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1469_2:;
goto L_146b;
}
L_146b:{ // MOV EAX,dword ptr [EDI + 0x90]
c.pc=0x146b;if(!sl_tick(c))return int(c.fault);
P_146b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x90ULL)),c);
P_146b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_146b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_146b_3:;
goto L_1471;
}
L_1471:{ // TEST EAX,EAX
c.pc=0x1471;if(!sl_tick(c))return int(c.fault);
P_1471_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_1471_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_1471_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_1471_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1471_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_1471_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_1471_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1471_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1471_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1471_9:;
goto L_1473;
}
L_1473:{ // JZ 0x0000147d
c.pc=0x1473;if(!sl_tick(c))return int(c.fault);
P_1473_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_147d;}
P_1473_1:;
goto L_1475;
}
L_1475:{ // MOV dword ptr [ESP],EAX
c.pc=0x1475;if(!sl_tick(c))return int(c.fault);
P_1475_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_1475_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_1475_2:;
goto L_1478;
}
L_1478:{ // CALL 0x0010300a
c.pc=0x1478;if(!sl_tick(c))return int(c.fault);
P_1478_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_1478_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x147dULL),c);
P_1478_2:;
c.pc=0x10300a;goto dispatch;
P_1478_3:;
goto L_147d;
}
L_147d:{ // MOV dword ptr [EDI + 0x90],0x0
c.pc=0x147d;if(!sl_tick(c))return int(c.fault);
P_147d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x90ULL)),c);
P_147d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_147d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_147d_3:;
goto L_1487;
}
L_1487:{ // MOV EDX,dword ptr [EDI + 0x84]
c.pc=0x1487;if(!sl_tick(c))return int(c.fault);
P_1487_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x84ULL)),c);
P_1487_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_1487_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1487_3:;
goto L_148d;
}
L_148d:{ // LEA EAX,[EDI + 0x98]
c.pc=0x148d;if(!sl_tick(c))return int(c.fault);
P_148d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x98ULL)),c);
P_148d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_148d_2:;
goto L_1493;
}
L_1493:{ // CMP EDX,EAX
c.pc=0x1493;if(!sl_tick(c))return int(c.fault);
P_1493_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_1493_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_1493_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x0,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x0,c)))&(SlU(1)<<31))!=0),c);
P_1493_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_1493_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1493_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_1493_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_1493_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1493_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1493_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1493_10:;
goto L_1495;
}
L_1495:{ // JZ 0x000014ad
c.pc=0x1495;if(!sl_tick(c))return int(c.fault);
P_1495_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_14ad;}
P_1495_1:;
goto L_1497;
}
L_1497:{ // TEST EDX,EDX
c.pc=0x1497;if(!sl_tick(c))return int(c.fault);
P_1497_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_1497_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_1497_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_1497_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1497_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_1497_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_1497_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1497_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1497_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1497_9:;
goto L_1499;
}
L_1499:{ // JZ 0x000014a3
c.pc=0x1499;if(!sl_tick(c))return int(c.fault);
P_1499_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_14a3;}
P_1499_1:;
goto L_149b;
}
L_149b:{ // MOV dword ptr [ESP],EDX
c.pc=0x149b;if(!sl_tick(c))return int(c.fault);
P_149b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_149b_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_149b_2:;
goto L_149e;
}
L_149e:{ // CALL 0x0010300a
c.pc=0x149e;if(!sl_tick(c))return int(c.fault);
P_149e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_149e_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x14a3ULL),c);
P_149e_2:;
c.pc=0x10300a;goto dispatch;
P_149e_3:;
goto L_14a3;
}
L_14a3:{ // MOV dword ptr [EDI + 0x84],0x0
c.pc=0x14a3;if(!sl_tick(c))return int(c.fault);
P_14a3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x84ULL)),c);
P_14a3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_14a3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_14a3_3:;
goto L_14ad;
}
L_14ad:{ // LEA EAX,[EDI + 0x8c]
c.pc=0x14ad;if(!sl_tick(c))return int(c.fault);
P_14ad_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x8cULL)),c);
P_14ad_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_14ad_2:;
goto L_14b3;
}
L_14b3:{ // MOV dword ptr [ESP],EAX
c.pc=0x14b3;if(!sl_tick(c))return int(c.fault);
P_14b3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_14b3_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_14b3_2:;
goto L_14b6;
}
L_14b6:{ // CALL 0x0002e18e
c.pc=0x14b6;if(!sl_tick(c))return int(c.fault);
P_14b6_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_14b6_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x14bbULL),c);
P_14b6_2:;
c.pc=0x2e18e;goto dispatch;
P_14b6_3:;
c.pc=0x14bb;goto dispatch;
}
}
