// Generated static p-code lift; original i386 SHA-256: 17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12
#include "LifterRuntime.h"
int sl_unit_0027(SlCpu& c){
goto dispatch;
dispatch:
if(c.fault||c.pc==c.stop)return int(c.fault);
switch(c.pc){
case 0xced2:goto L_ced2;
case 0xced5:goto L_ced5;
case 0xced8:goto L_ced8;
case 0xcede:goto L_cede;
case 0xcee4:goto L_cee4;
case 0xcee7:goto L_cee7;
case 0xceea:goto L_ceea;
case 0xceec:goto L_ceec;
case 0xceef:goto L_ceef;
case 0xcef0:goto L_cef0;
case 0xcef1:goto L_cef1;
case 0xcef2:goto L_cef2;
case 0xcef3:goto L_cef3;
case 0xcef9:goto L_cef9;
case 0xcefc:goto L_cefc;
case 0xceff:goto L_ceff;
case 0xcf04:goto L_cf04;
case 0xcf06:goto L_cf06;
case 0xcf08:goto L_cf08;
case 0xcf0b:goto L_cf0b;
case 0xcf11:goto L_cf11;
case 0xcf17:goto L_cf17;
case 0xcf1a:goto L_cf1a;
case 0xcf1c:goto L_cf1c;
case 0xcf1e:goto L_cf1e;
case 0xcf20:goto L_cf20;
case 0xcf23:goto L_cf23;
case 0xcf26:goto L_cf26;
case 0xcf29:goto L_cf29;
case 0xcf2c:goto L_cf2c;
case 0xcf2f:goto L_cf2f;
case 0xcf32:goto L_cf32;
case 0xcf36:goto L_cf36;
case 0xcf39:goto L_cf39;
case 0xcf3c:goto L_cf3c;
case 0xcf3e:goto L_cf3e;
case 0xcf45:goto L_cf45;
case 0xcf48:goto L_cf48;
case 0xcf4e:goto L_cf4e;
case 0xcf50:goto L_cf50;
case 0xcf57:goto L_cf57;
case 0xcf5d:goto L_cf5d;
case 0xcf5f:goto L_cf5f;
case 0xcf65:goto L_cf65;
case 0xcf67:goto L_cf67;
case 0xcf69:goto L_cf69;
case 0xcf6b:goto L_cf6b;
case 0xcf6f:goto L_cf6f;
case 0xcf72:goto L_cf72;
case 0xcf76:goto L_cf76;
case 0xcf79:goto L_cf79;
case 0xcf7f:goto L_cf7f;
case 0xcf85:goto L_cf85;
case 0xcf88:goto L_cf88;
case 0xcf8e:goto L_cf8e;
case 0xcf90:goto L_cf90;
case 0xcf96:goto L_cf96;
case 0xcf99:goto L_cf99;
case 0xcf9b:goto L_cf9b;
case 0xcfa5:goto L_cfa5;
case 0xcfa8:goto L_cfa8;
case 0xcfab:goto L_cfab;
case 0xcfb0:goto L_cfb0;
case 0xcfb3:goto L_cfb3;
case 0xcfb4:goto L_cfb4;
case 0xcfb5:goto L_cfb5;
case 0xcfb6:goto L_cfb6;
case 0xcfb7:goto L_cfb7;
case 0xcfba:goto L_cfba;
case 0xcfbd:goto L_cfbd;
case 0xcfc3:goto L_cfc3;
case 0xcfc6:goto L_cfc6;
case 0xcfc9:goto L_cfc9;
case 0xcfcc:goto L_cfcc;
case 0xcfcf:goto L_cfcf;
case 0xcfd3:goto L_cfd3;
case 0xcfd7:goto L_cfd7;
case 0xcfda:goto L_cfda;
case 0xcfdd:goto L_cfdd;
case 0xcfe2:goto L_cfe2;
case 0xcfe7:goto L_cfe7;
case 0xcfe9:goto L_cfe9;
case 0xcfeb:goto L_cfeb;
case 0xcff3:goto L_cff3;
case 0xcffa:goto L_cffa;
case 0xcffe:goto L_cffe;
case 0xd001:goto L_d001;
case 0xd004:goto L_d004;
case 0xd007:goto L_d007;
case 0xd00a:goto L_d00a;
case 0xd00c:goto L_d00c;
case 0xd011:goto L_d011;
case 0xd013:goto L_d013;
case 0xd016:goto L_d016;
case 0xd019:goto L_d019;
case 0xd01d:goto L_d01d;
case 0xd020:goto L_d020;
case 0xd024:goto L_d024;
case 0xd027:goto L_d027;
case 0xd02d:goto L_d02d;
case 0xd032:goto L_d032;
case 0xd033:goto L_d033;
case 0xd035:goto L_d035;
case 0xd036:goto L_d036;
case 0xd037:goto L_d037;
case 0xd03a:goto L_d03a;
case 0xd03d:goto L_d03d;
case 0xd040:goto L_d040;
case 0xd046:goto L_d046;
case 0xd04a:goto L_d04a;
case 0xd04d:goto L_d04d;
case 0xd050:goto L_d050;
case 0xd055:goto L_d055;
case 0xd058:goto L_d058;
case 0xd05a:goto L_d05a;
case 0xd062:goto L_d062;
case 0xd064:goto L_d064;
case 0xd06c:goto L_d06c;
case 0xd06f:goto L_d06f;
case 0xd070:goto L_d070;
case 0xd071:goto L_d071;
case 0xd072:goto L_d072;
case 0xd073:goto L_d073;
case 0xd075:goto L_d075;
case 0xd079:goto L_d079;
case 0xd07c:goto L_d07c;
case 0xd082:goto L_d082;
case 0xd084:goto L_d084;
case 0xd086:goto L_d086;
case 0xd088:goto L_d088;
case 0xd08c:goto L_d08c;
case 0xd08f:goto L_d08f;
case 0xd095:goto L_d095;
case 0xd098:goto L_d098;
case 0xd09b:goto L_d09b;
case 0xd09d:goto L_d09d;
case 0xd0a0:goto L_d0a0;
case 0xd0a1:goto L_d0a1;
case 0xd0a2:goto L_d0a2;
case 0xd0a3:goto L_d0a3;
case 0xd0a4:goto L_d0a4;
case 0xd0a5:goto L_d0a5;
case 0xd0a7:goto L_d0a7;
case 0xd0aa:goto L_d0aa;
case 0xd0ac:goto L_d0ac;
case 0xd0b2:goto L_d0b2;
case 0xd0b3:goto L_d0b3;
case 0xd0b6:goto L_d0b6;
case 0xd0b7:goto L_d0b7;
case 0xd0b9:goto L_d0b9;
case 0xd0ba:goto L_d0ba;
case 0xd0bb:goto L_d0bb;
case 0xd0be:goto L_d0be;
case 0xd0c1:goto L_d0c1;
case 0xd0c4:goto L_d0c4;
case 0xd0c7:goto L_d0c7;
case 0xd0ca:goto L_d0ca;
case 0xd0d0:goto L_d0d0;
case 0xd0d3:goto L_d0d3;
case 0xd0d6:goto L_d0d6;
case 0xd0db:goto L_d0db;
case 0xd0dd:goto L_d0dd;
case 0xd0df:goto L_d0df;
case 0xd0e2:goto L_d0e2;
case 0xd0e3:goto L_d0e3;
case 0xd0e4:goto L_d0e4;
case 0xd0e5:goto L_d0e5;
case 0xd0e6:goto L_d0e6;
case 0xd0ec:goto L_d0ec;
case 0xd0ef:goto L_d0ef;
case 0xd0f2:goto L_d0f2;
case 0xd0f7:goto L_d0f7;
case 0xd0fa:goto L_d0fa;
case 0xd100:goto L_d100;
case 0xd102:goto L_d102;
case 0xd108:goto L_d108;
case 0xd10a:goto L_d10a;
case 0xd10c:goto L_d10c;
case 0xd110:goto L_d110;
case 0xd113:goto L_d113;
case 0xd117:goto L_d117;
case 0xd11a:goto L_d11a;
case 0xd120:goto L_d120;
case 0xd124:goto L_d124;
case 0xd126:goto L_d126;
case 0xd129:goto L_d129;
case 0xd12c:goto L_d12c;
case 0xd12f:goto L_d12f;
case 0xd130:goto L_d130;
case 0xd131:goto L_d131;
case 0xd132:goto L_d132;
case 0xd137:goto L_d137;
case 0xd139:goto L_d139;
case 0xd141:goto L_d141;
case 0xd144:goto L_d144;
case 0xd148:goto L_d148;
case 0xd14b:goto L_d14b;
case 0xd151:goto L_d151;
case 0xd157:goto L_d157;
case 0xd161:goto L_d161;
case 0xd164:goto L_d164;
case 0xd16a:goto L_d16a;
case 0xd170:goto L_d170;
case 0xd173:goto L_d173;
case 0xd179:goto L_d179;
case 0xd180:goto L_d180;
case 0xd186:goto L_d186;
case 0xd188:goto L_d188;
case 0xd18a:goto L_d18a;
case 0xd18d:goto L_d18d;
case 0xd190:goto L_d190;
case 0xd195:goto L_d195;
case 0xd198:goto L_d198;
case 0xd19b:goto L_d19b;
case 0xd19e:goto L_d19e;
case 0xd19f:goto L_d19f;
case 0xd1a0:goto L_d1a0;
case 0xd1a1:goto L_d1a1;
case 0xd1a6:goto L_d1a6;
case 0xd1a7:goto L_d1a7;
case 0xd1a9:goto L_d1a9;
case 0xd1aa:goto L_d1aa;
case 0xd1ab:goto L_d1ab;
case 0xd1ae:goto L_d1ae;
case 0xd1b1:goto L_d1b1;
case 0xd1b4:goto L_d1b4;
case 0xd1b6:goto L_d1b6;
case 0xd1bc:goto L_d1bc;
case 0xd1be:goto L_d1be;
case 0xd1c1:goto L_d1c1;
case 0xd1c5:goto L_d1c5;
case 0xd1c8:goto L_d1c8;
case 0xd1cb:goto L_d1cb;
case 0xd1d2:goto L_d1d2;
case 0xd1d8:goto L_d1d8;
case 0xd1df:goto L_d1df;
case 0xd1e5:goto L_d1e5;
case 0xd1e8:goto L_d1e8;
case 0xd1ee:goto L_d1ee;
case 0xd1f0:goto L_d1f0;
case 0xd1f2:goto L_d1f2;
case 0xd1f4:goto L_d1f4;
case 0xd1f6:goto L_d1f6;
case 0xd1f9:goto L_d1f9;
case 0xd1ff:goto L_d1ff;
case 0xd201:goto L_d201;
case 0xd208:goto L_d208;
case 0xd20c:goto L_d20c;
case 0xd20e:goto L_d20e;
case 0xd210:goto L_d210;
case 0xd213:goto L_d213;
case 0xd217:goto L_d217;
case 0xd21a:goto L_d21a;
case 0xd21d:goto L_d21d;
case 0xd220:goto L_d220;
case 0xd223:goto L_d223;
case 0xd229:goto L_d229;
case 0xd22b:goto L_d22b;
case 0xd22e:goto L_d22e;
case 0xd231:goto L_d231;
case 0xd235:goto L_d235;
case 0xd23b:goto L_d23b;
case 0xd23f:goto L_d23f;
case 0xd245:goto L_d245;
case 0xd248:goto L_d248;
case 0xd24d:goto L_d24d;
case 0xd253:goto L_d253;
case 0xd255:goto L_d255;
case 0xd25b:goto L_d25b;
case 0xd25e:goto L_d25e;
case 0xd264:goto L_d264;
case 0xd266:goto L_d266;
case 0xd268:goto L_d268;
case 0xd26a:goto L_d26a;
case 0xd26c:goto L_d26c;
case 0xd26f:goto L_d26f;
case 0xd275:goto L_d275;
case 0xd277:goto L_d277;
case 0xd27e:goto L_d27e;
case 0xd282:goto L_d282;
case 0xd284:goto L_d284;
case 0xd286:goto L_d286;
case 0xd289:goto L_d289;
case 0xd28d:goto L_d28d;
case 0xd290:goto L_d290;
case 0xd293:goto L_d293;
case 0xd296:goto L_d296;
case 0xd299:goto L_d299;
case 0xd29f:goto L_d29f;
case 0xd2a1:goto L_d2a1;
case 0xd2a3:goto L_d2a3;
case 0xd2a6:goto L_d2a6;
case 0xd2a9:goto L_d2a9;
case 0xd2ac:goto L_d2ac;
case 0xd2b2:goto L_d2b2;
case 0xd2b8:goto L_d2b8;
case 0xd2bb:goto L_d2bb;
case 0xd2bd:goto L_d2bd;
case 0xd2c0:goto L_d2c0;
case 0xd2c4:goto L_d2c4;
case 0xd2c7:goto L_d2c7;
case 0xd2ca:goto L_d2ca;
case 0xd2cc:goto L_d2cc;
case 0xd2d2:goto L_d2d2;
case 0xd2d5:goto L_d2d5;
case 0xd2d9:goto L_d2d9;
case 0xd2df:goto L_d2df;
case 0xd2e3:goto L_d2e3;
case 0xd2e6:goto L_d2e6;
case 0xd2eb:goto L_d2eb;
case 0xd2ee:goto L_d2ee;
case 0xd2f3:goto L_d2f3;
case 0xd2f9:goto L_d2f9;
case 0xd2fb:goto L_d2fb;
case 0xd301:goto L_d301;
case 0xd303:goto L_d303;
case 0xd306:goto L_d306;
case 0xd30a:goto L_d30a;
case 0xd30d:goto L_d30d;
case 0xd311:goto L_d311;
case 0xd314:goto L_d314;
case 0xd317:goto L_d317;
case 0xd319:goto L_d319;
case 0xd31c:goto L_d31c;
case 0xd320:goto L_d320;
case 0xd323:goto L_d323;
case 0xd326:goto L_d326;
case 0xd328:goto L_d328;
case 0xd32b:goto L_d32b;
case 0xd32f:goto L_d32f;
case 0xd332:goto L_d332;
case 0xd335:goto L_d335;
case 0xd33b:goto L_d33b;
case 0xd33d:goto L_d33d;
case 0xd33f:goto L_d33f;
case 0xd342:goto L_d342;
case 0xd345:goto L_d345;
case 0xd34a:goto L_d34a;
case 0xd34d:goto L_d34d;
case 0xd350:goto L_d350;
case 0xd353:goto L_d353;
case 0xd355:goto L_d355;
case 0xd358:goto L_d358;
case 0xd35b:goto L_d35b;
case 0xd361:goto L_d361;
case 0xd363:goto L_d363;
case 0xd366:goto L_d366;
case 0xd367:goto L_d367;
case 0xd368:goto L_d368;
case 0xd369:goto L_d369;
case 0xd36a:goto L_d36a;
case 0xd370:goto L_d370;
case 0xd374:goto L_d374;
case 0xd377:goto L_d377;
case 0xd37a:goto L_d37a;
case 0xd37f:goto L_d37f;
case 0xd384:goto L_d384;
case 0xd387:goto L_d387;
case 0xd38d:goto L_d38d;
case 0xd38f:goto L_d38f;
case 0xd395:goto L_d395;
case 0xd397:goto L_d397;
case 0xd399:goto L_d399;
case 0xd39c:goto L_d39c;
case 0xd3a2:goto L_d3a2;
case 0xd3a8:goto L_d3a8;
case 0xd3af:goto L_d3af;
case 0xd3b3:goto L_d3b3;
case 0xd3b5:goto L_d3b5;
case 0xd3b9:goto L_d3b9;
case 0xd3bb:goto L_d3bb;
case 0xd3bd:goto L_d3bd;
case 0xd3c0:goto L_d3c0;
case 0xd3c4:goto L_d3c4;
case 0xd3c7:goto L_d3c7;
case 0xd3ca:goto L_d3ca;
case 0xd3cd:goto L_d3cd;
case 0xd3cf:goto L_d3cf;
case 0xd3d1:goto L_d3d1;
case 0xd3d4:goto L_d3d4;
case 0xd3d8:goto L_d3d8;
case 0xd3db:goto L_d3db;
case 0xd3df:goto L_d3df;
case 0xd3e2:goto L_d3e2;
case 0xd3e5:goto L_d3e5;
case 0xd3ec:goto L_d3ec;
case 0xd3ed:goto L_d3ed;
case 0xd3ef:goto L_d3ef;
case 0xd3f2:goto L_d3f2;
case 0xd3f5:goto L_d3f5;
case 0xd3f8:goto L_d3f8;
case 0xd403:goto L_d403;
case 0xd406:goto L_d406;
case 0xd409:goto L_d409;
case 0xd40c:goto L_d40c;
case 0xd413:goto L_d413;
case 0xd41a:goto L_d41a;
case 0xd41d:goto L_d41d;
case 0xd420:goto L_d420;
case 0xd421:goto L_d421;
case 0xd424:goto L_d424;
case 0xd425:goto L_d425;
case 0xd427:goto L_d427;
case 0xd428:goto L_d428;
case 0xd429:goto L_d429;
case 0xd42c:goto L_d42c;
case 0xd42f:goto L_d42f;
case 0xd432:goto L_d432;
case 0xd436:goto L_d436;
case 0xd439:goto L_d439;
case 0xd441:goto L_d441;
case 0xd443:goto L_d443;
case 0xd445:goto L_d445;
case 0xd447:goto L_d447;
case 0xd44b:goto L_d44b;
case 0xd452:goto L_d452;
case 0xd455:goto L_d455;
case 0xd456:goto L_d456;
case 0xd457:goto L_d457;
case 0xd458:goto L_d458;
case 0xd459:goto L_d459;
case 0xd45b:goto L_d45b;
case 0xd45f:goto L_d45f;
case 0xd462:goto L_d462;
case 0xd468:goto L_d468;
case 0xd46c:goto L_d46c;
case 0xd473:goto L_d473;
case 0xd476:goto L_d476;
case 0xd477:goto L_d477;
case 0xd478:goto L_d478;
case 0xd479:goto L_d479;
case 0xd47a:goto L_d47a;
case 0xd47b:goto L_d47b;
case 0xd47d:goto L_d47d;
case 0xd47e:goto L_d47e;
case 0xd47f:goto L_d47f;
case 0xd482:goto L_d482;
case 0xd487:goto L_d487;
case 0xd48a:goto L_d48a;
case 0xd48d:goto L_d48d;
case 0xd490:goto L_d490;
case 0xd493:goto L_d493;
case 0xd497:goto L_d497;
case 0xd49f:goto L_d49f;
case 0xd4a2:goto L_d4a2;
case 0xd4a6:goto L_d4a6;
case 0xd4ae:goto L_d4ae;
case 0xd4b2:goto L_d4b2;
case 0xd4b5:goto L_d4b5;
case 0xd4bb:goto L_d4bb;
case 0xd4c2:goto L_d4c2;
case 0xd4c4:goto L_d4c4;
case 0xd660:goto L_d660;
case 0xd667:goto L_d667;
case 0xd66d:goto L_d66d;
case 0xd670:goto L_d670;
case 0xd676:goto L_d676;
case 0xd67d:goto L_d67d;
case 0xd680:goto L_d680;
case 0xd681:goto L_d681;
case 0xd682:goto L_d682;
case 0xd683:goto L_d683;
case 0xd684:goto L_d684;
case 0xd68b:goto L_d68b;
case 0xd68d:goto L_d68d;
case 0xd695:goto L_d695;
case 0xd697:goto L_d697;
case 0xd69f:goto L_d69f;
case 0xd6a1:goto L_d6a1;
case 0xd6a9:goto L_d6a9;
case 0xd6ab:goto L_d6ab;
case 0xd6b2:goto L_d6b2;
case 0xd6b4:goto L_d6b4;
case 0xd6ba:goto L_d6ba;
case 0xd6bc:goto L_d6bc;
case 0xd6be:goto L_d6be;
case 0xd6c2:goto L_d6c2;
case 0xd6ca:goto L_d6ca;
case 0xd6d2:goto L_d6d2;
case 0xd6d5:goto L_d6d5;
case 0xd6da:goto L_d6da;
case 0xd6dd:goto L_d6dd;
case 0xd6e2:goto L_d6e2;
case 0xd6e9:goto L_d6e9;
case 0xd6f0:goto L_d6f0;
case 0xd6f7:goto L_d6f7;
case 0xd6fa:goto L_d6fa;
case 0xd6ff:goto L_d6ff;
case 0xd702:goto L_d702;
case 0xd705:goto L_d705;
case 0xd706:goto L_d706;
case 0xd707:goto L_d707;
case 0xd708:goto L_d708;
case 0xd70d:goto L_d70d;
case 0xd711:goto L_d711;
case 0xd719:goto L_d719;
case 0xd71e:goto L_d71e;
case 0xd721:goto L_d721;
case 0xd727:goto L_d727;
case 0xd72f:goto L_d72f;
case 0xd734:goto L_d734;
case 0xd73c:goto L_d73c;
case 0xd741:goto L_d741;
case 0xd749:goto L_d749;
case 0xd74e:goto L_d74e;
case 0xd755:goto L_d755;
case 0xd75b:goto L_d75b;
case 0xd75d:goto L_d75d;
case 0xd760:goto L_d760;
case 0xd763:goto L_d763;
case 0xd766:goto L_d766;
case 0xd769:goto L_d769;
case 0xd76c:goto L_d76c;
case 0xd76f:goto L_d76f;
case 0xd772:goto L_d772;
case 0xd775:goto L_d775;
case 0xd776:goto L_d776;
case 0xd777:goto L_d777;
case 0xd778:goto L_d778;
case 0xd77a:goto L_d77a;
case 0xd781:goto L_d781;
case 0xd787:goto L_d787;
case 0xd78d:goto L_d78d;
case 0xd794:goto L_d794;
case 0xd799:goto L_d799;
case 0xd7a1:goto L_d7a1;
case 0xd7a6:goto L_d7a6;
case 0xd7ae:goto L_d7ae;
case 0xd7b3:goto L_d7b3;
case 0xd7bb:goto L_d7bb;
case 0xd7c0:goto L_d7c0;
case 0xd7c3:goto L_d7c3;
case 0xd7c5:goto L_d7c5;
case 0xd7cf:goto L_d7cf;
case 0xd7d4:goto L_d7d4;
case 0xd7d5:goto L_d7d5;
case 0xd7d7:goto L_d7d7;
case 0xd7d8:goto L_d7d8;
case 0xd7d9:goto L_d7d9;
case 0xd7de:goto L_d7de;
case 0xd7e1:goto L_d7e1;
case 0xd7e4:goto L_d7e4;
case 0xd7e6:goto L_d7e6;
case 0xd7e8:goto L_d7e8;
case 0xd7ee:goto L_d7ee;
case 0xd7f0:goto L_d7f0;
case 0xd7f3:goto L_d7f3;
case 0xd7f6:goto L_d7f6;
case 0xd7f9:goto L_d7f9;
case 0xd7fc:goto L_d7fc;
case 0xd803:goto L_d803;
case 0xd809:goto L_d809;
case 0xd811:goto L_d811;
case 0xd816:goto L_d816;
case 0xd81d:goto L_d81d;
case 0xd823:goto L_d823;
case 0xd829:goto L_d829;
case 0xd831:goto L_d831;
case 0xd839:goto L_d839;
case 0xd83c:goto L_d83c;
case 0xd844:goto L_d844;
case 0xd847:goto L_d847;
case 0xd84f:goto L_d84f;
case 0xd853:goto L_d853;
case 0xd85b:goto L_d85b;
case 0xd85e:goto L_d85e;
case 0xd866:goto L_d866;
case 0xd869:goto L_d869;
case 0xd871:goto L_d871;
case 0xd875:goto L_d875;
case 0xd87d:goto L_d87d;
case 0xd880:goto L_d880;
case 0xd888:goto L_d888;
case 0xd88b:goto L_d88b;
case 0xd893:goto L_d893;
case 0xd897:goto L_d897;
case 0xd89f:goto L_d89f;
case 0xd8a2:goto L_d8a2;
case 0xd8aa:goto L_d8aa;
case 0xd8ad:goto L_d8ad;
case 0xd8b5:goto L_d8b5;
case 0xd8b9:goto L_d8b9;
case 0xd8c1:goto L_d8c1;
case 0xd8c4:goto L_d8c4;
case 0xd8cc:goto L_d8cc;
case 0xd8d4:goto L_d8d4;
case 0xd8d8:goto L_d8d8;
case 0xd8e0:goto L_d8e0;
case 0xd8e3:goto L_d8e3;
default:return 0;}
L_ced2:{ // MOV dword ptr [EBP + -0x2c],EAX
c.pc=0xced2;if(!sl_tick(c))return int(c.fault);
P_ced2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_ced2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ced2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ced2_3:;
goto L_ced5;
}
L_ced5:{ // MOV EAX,dword ptr [EDI + 0x4]
c.pc=0xced5;if(!sl_tick(c))return int(c.fault);
P_ced5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x4ULL)),c);
P_ced5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ced5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ced5_3:;
goto L_ced8;
}
L_ced8:{ // MOV ESI,dword ptr [EAX + 0xcfb4]
c.pc=0xced8;if(!sl_tick(c))return int(c.fault);
P_ced8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xcfb4ULL)),c);
P_ced8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_ced8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ced8_3:;
goto L_cede;
}
L_cede:{ // MOV EDX,dword ptr [EAX + 0xcfb8]
c.pc=0xcede;if(!sl_tick(c))return int(c.fault);
P_cede_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xcfb8ULL)),c);
P_cede_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_cede_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cede_3:;
goto L_cee4;
}
L_cee4:{ // LEA EAX,[ESI + EDX*0x1]
c.pc=0xcee4;if(!sl_tick(c))return int(c.fault);
P_cee4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x1ULL)),c);
P_cee4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_cee4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3580,c),c);
P_cee4_3:;
goto L_cee7;
}
L_cee7:{ // CMP dword ptr [EBP + -0x2c],EAX
c.pc=0xcee7;if(!sl_tick(c))return int(c.fault);
P_cee7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_cee7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cee7_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cee7_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_cee7_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x0,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x0,c)))&(SlU(1)<<31))!=0),c);
P_cee7_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_cee7_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cee7_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_cee7_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_cee7_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cee7_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cee7_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cee7_12:;
goto L_ceea;
}
L_ceea:{ // JL 0x0000cef3
c.pc=0xceea;if(!sl_tick(c))return int(c.fault);
P_ceea_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa180,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_ceea_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa180,c)){goto L_cef3;}
P_ceea_2:;
goto L_ceec;
}
L_ceec:{ // ADD ESP,0x50
c.pc=0xceec;if(!sl_tick(c))return int(c.fault);
P_ceec_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x50ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ceec_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x50ULL)))&(SlU(0x50ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x50ULL)))&(SlU(1)<<31))!=0),c);
P_ceec_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x50ULL)),c);
P_ceec_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ceec_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ceec_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ceec_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ceec_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ceec_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ceec_9:;
goto L_ceef;
}
L_ceef:{ // POP ESI
c.pc=0xceef;if(!sl_tick(c))return int(c.fault);
P_ceef_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ceef_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ceef_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ceef_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ceef_4:;
goto L_cef0;
}
L_cef0:{ // POP EDI
c.pc=0xcef0;if(!sl_tick(c))return int(c.fault);
P_cef0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_cef0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_cef0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_cef0_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_cef0_4:;
goto L_cef1;
}
L_cef1:{ // POP EBP
c.pc=0xcef1;if(!sl_tick(c))return int(c.fault);
P_cef1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_cef1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_cef1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_cef1_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_cef1_4:;
goto L_cef2;
}
L_cef2:{ // RET
c.pc=0xcef2;if(!sl_tick(c))return int(c.fault);
P_cef2_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_cef2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_cef2_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_cef2_3:;
goto L_cef3;
}
L_cef3:{ // LEA ECX,[EDI + 0xe1c]
c.pc=0xcef3;if(!sl_tick(c))return int(c.fault);
P_cef3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xe1cULL)),c);
P_cef3_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_cef3_2:;
goto L_cef9;
}
L_cef9:{ // MOV dword ptr [EBP + -0x34],ECX
c.pc=0xcef9;if(!sl_tick(c))return int(c.fault);
P_cef9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffccULL)),c);
P_cef9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_cef9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cef9_3:;
goto L_cefc;
}
L_cefc:{ // MOV dword ptr [ESP],ECX
c.pc=0xcefc;if(!sl_tick(c))return int(c.fault);
P_cefc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_cefc_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cefc_2:;
goto L_ceff;
}
L_ceff:{ // CALL 0x0002ddfc
c.pc=0xceff;if(!sl_tick(c))return int(c.fault);
P_ceff_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ceff_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xcf04ULL),c);
P_ceff_2:;
c.pc=0x2ddfc;goto dispatch;
P_ceff_3:;
goto L_cf04;
}
L_cf04:{ // TEST AL,AL
c.pc=0xcf04;if(!sl_tick(c))return int(c.fault);
P_cf04_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_cf04_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_cf04_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x54d80,(sl_get<1>(c.reg,sizeof(c.reg),0x0,c) & sl_get<1>(c.reg,sizeof(c.reg),0x0,c)),c);
P_cf04_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_cf04_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c) == SlU(0x0ULL)),c);
P_cf04_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c) & SlU(0xffULL)),c);
P_cf04_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cf04_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cf04_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cf04_9:;
goto L_cf06;
}
L_cf06:{ // JZ 0x0000ceec
c.pc=0xcf06;if(!sl_tick(c))return int(c.fault);
P_cf06_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_ceec;}
P_cf06_1:;
goto L_cf08;
}
L_cf08:{ // CMP dword ptr [EBP + -0x2c],ESI
c.pc=0xcf08;if(!sl_tick(c))return int(c.fault);
P_cf08_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_cf08_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cf08_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cf08_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_cf08_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x18,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x18,c)))&(SlU(1)<<31))!=0),c);
P_cf08_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_cf08_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cf08_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_cf08_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_cf08_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cf08_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cf08_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cf08_12:;
goto L_cf0b;
}
L_cf0b:{ // JL 0x0000cfb7
c.pc=0xcf0b;if(!sl_tick(c))return int(c.fault);
P_cf0b_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa180,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_cf0b_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa180,c)){goto L_cfb7;}
P_cf0b_2:;
goto L_cf11;
}
L_cf11:{ // MOV EAX,dword ptr [EDI + 0x1b0]
c.pc=0xcf11;if(!sl_tick(c))return int(c.fault);
P_cf11_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1b0ULL)),c);
P_cf11_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_cf11_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cf11_3:;
goto L_cf17;
}
L_cf17:{ // MOV dword ptr [EBP + -0x40],EAX
c.pc=0xcf17;if(!sl_tick(c))return int(c.fault);
P_cf17_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc0ULL)),c);
P_cf17_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_cf17_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cf17_3:;
goto L_cf1a;
}
L_cf1a:{ // TEST EAX,EAX
c.pc=0xcf1a;if(!sl_tick(c))return int(c.fault);
P_cf1a_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_cf1a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_cf1a_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_cf1a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cf1a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_cf1a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_cf1a_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cf1a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cf1a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cf1a_9:;
goto L_cf1c;
}
L_cf1c:{ // JLE 0x0000cf3e
c.pc=0xcf1c;if(!sl_tick(c))return int(c.fault);
P_cf1c_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_cf1c_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_cf1c_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_cf3e;}
P_cf1c_3:;
goto L_cf1e;
}
L_cf1e:{ // XOR EDX,EDX
c.pc=0xcf1e;if(!sl_tick(c))return int(c.fault);
P_cf1e_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_cf1e_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_cf1e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_cf1e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cf1e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_cf1e_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_cf1e_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cf1e_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cf1e_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cf1e_9:;
goto L_cf20;
}
L_cf20:{ // MOV EAX,dword ptr [EBP + -0x40]
c.pc=0xcf20;if(!sl_tick(c))return int(c.fault);
P_cf20_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc0ULL)),c);
P_cf20_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cf20_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cf20_3:;
goto L_cf23;
}
L_cf23:{ // SUB EAX,0x1
c.pc=0xcf23;if(!sl_tick(c))return int(c.fault);
P_cf23_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < SlU(0x1ULL)),c);
P_cf23_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^SlU(0x1ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_cf23_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - SlU(0x1ULL)),c);
P_cf23_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cf23_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_cf23_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_cf23_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cf23_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cf23_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cf23_9:;
goto L_cf26;
}
L_cf26:{ // IMUL EAX,ESI
c.pc=0xcf26;if(!sl_tick(c))return int(c.fault);
P_cf26_0:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a480,SlU(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32)),c);
P_cf26_1:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a500,SlU(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32)),c);
P_cf26_2:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a600,(sl_get<8>(c.temp,sizeof(c.temp),0x3a480,c) * sl_get<8>(c.temp,sizeof(c.temp),0x3a500,c)),c);
P_cf26_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c),8*SlU(0x0ULL)),c);
P_cf26_4:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a780,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c),8*SlU(0x4ULL)),c);
P_cf26_5:;
sl_put<8>(c.temp,sizeof(c.temp),0x23880,SlU(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32)),c);
P_cf26_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<8>(c.temp,sizeof(c.temp),0x23880,c) != sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c)),c);
P_cf26_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,sl_get<1>(c.reg,sizeof(c.reg),0x200,c),c);
P_cf26_8:;
goto L_cf29;
}
L_cf29:{ // ADD EAX,dword ptr [EBP + -0x2c]
c.pc=0xcf29;if(!sl_tick(c))return int(c.fault);
P_cf29_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_cf29_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cf29_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+sl_get<4>(c.temp,sizeof(c.temp),0x9680,c))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_cf29_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cf29_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+sl_get<4>(c.temp,sizeof(c.temp),0x9680,c)))&(sl_get<4>(c.temp,sizeof(c.temp),0x9680,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+sl_get<4>(c.temp,sizeof(c.temp),0x9680,c)))&(SlU(1)<<31))!=0),c);
P_cf29_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cf29_6:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x9680,c)),c);
P_cf29_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cf29_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_cf29_9:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_cf29_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cf29_11:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cf29_12:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cf29_13:;
goto L_cf2c;
}
L_cf2c:{ // MOV ECX,dword ptr [EBP + 0xc]
c.pc=0xcf2c;if(!sl_tick(c))return int(c.fault);
P_cf2c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_cf2c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cf2c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cf2c_3:;
goto L_cf2f;
}
L_cf2f:{ // MOV EAX,dword ptr [ECX + EAX*0x4]
c.pc=0xcf2f;if(!sl_tick(c))return int(c.fault);
P_cf2f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x4ULL)),c);
P_cf2f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_cf2f_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),c),c);
P_cf2f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cf2f_4:;
goto L_cf32;
}
L_cf32:{ // MOV dword ptr [EBP + EDX*0x4 + -0x20],EAX
c.pc=0xcf32;if(!sl_tick(c))return int(c.fault);
P_cf32_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3800,(SlU(0xffffffe0ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x14,c)),c);
P_cf32_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3880,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x4ULL)),c);
P_cf32_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3980,(sl_get<4>(c.temp,sizeof(c.temp),0x3800,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3880,c)),c);
P_cf32_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_cf32_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3980,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cf32_5:;
goto L_cf36;
}
L_cf36:{ // ADD EDX,0x1
c.pc=0xcf36;if(!sl_tick(c))return int(c.fault);
P_cf36_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_cf36_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_cf36_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x1ULL)),c);
P_cf36_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cf36_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_cf36_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_cf36_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cf36_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cf36_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cf36_9:;
goto L_cf39;
}
L_cf39:{ // CMP dword ptr [EBP + -0x40],EDX
c.pc=0xcf39;if(!sl_tick(c))return int(c.fault);
P_cf39_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc0ULL)),c);
P_cf39_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cf39_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cf39_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_cf39_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x8,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x8,c)))&(SlU(1)<<31))!=0),c);
P_cf39_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_cf39_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cf39_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_cf39_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_cf39_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cf39_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cf39_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cf39_12:;
goto L_cf3c;
}
L_cf3c:{ // JG 0x0000cf20
c.pc=0xcf3c;if(!sl_tick(c))return int(c.fault);
P_cf3c_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_cf3c_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_cf3c_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_cf3c_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_cf20;}
P_cf3c_4:;
goto L_cf3e;
}
L_cf3e:{ // MOV dword ptr [EBP + -0x30],0x0
c.pc=0xcf3e;if(!sl_tick(c))return int(c.fault);
P_cf3e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd0ULL)),c);
P_cf3e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_cf3e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_cf3e_3:;
goto L_cf45;
}
L_cf45:{ // MOV EAX,dword ptr [EBP + -0x30]
c.pc=0xcf45;if(!sl_tick(c))return int(c.fault);
P_cf45_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd0ULL)),c);
P_cf45_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cf45_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cf45_3:;
goto L_cf48;
}
L_cf48:{ // CMP EAX,dword ptr [EDI + 0xeb8]
c.pc=0xcf48;if(!sl_tick(c))return int(c.fault);
P_cf48_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xeb8ULL)),c);
P_cf48_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_cf48_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cf48_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_cf48_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_cf48_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_cf48_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cf48_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_cf48_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_cf48_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cf48_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cf48_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cf48_12:;
goto L_cf4e;
}
L_cf4e:{ // JGE 0x0000cf90
c.pc=0xcf4e;if(!sl_tick(c))return int(c.fault);
P_cf4e_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa280,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_cf4e_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa280,c)){goto L_cf90;}
P_cf4e_2:;
goto L_cf50;
}
L_cf50:{ // MOV ESI,dword ptr [EDI + EAX*0x8 + 0x21c]
c.pc=0xcf50;if(!sl_tick(c))return int(c.fault);
P_cf50_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x21cULL) + sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c);
P_cf50_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x8ULL)),c);
P_cf50_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_cf50_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c)),c),c);
P_cf50_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cf50_5:;
goto L_cf57;
}
L_cf57:{ // MOV EDX,dword ptr [EDI + 0x1b60]
c.pc=0xcf57;if(!sl_tick(c))return int(c.fault);
P_cf57_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1b60ULL)),c);
P_cf57_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_cf57_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cf57_3:;
goto L_cf5d;
}
L_cf5d:{ // CMP ESI,EDX
c.pc=0xcf5d;if(!sl_tick(c))return int(c.fault);
P_cf5d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_cf5d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_cf5d_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x8,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x8,c)))&(SlU(1)<<31))!=0),c);
P_cf5d_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_cf5d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cf5d_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_cf5d_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_cf5d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cf5d_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cf5d_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cf5d_10:;
goto L_cf5f;
}
L_cf5f:{ // JLE 0x0000cfe7
c.pc=0xcf5f;if(!sl_tick(c))return int(c.fault);
P_cf5f_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_cf5f_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_cf5f_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_cfe7;}
P_cf5f_3:;
goto L_cf65;
}
L_cf65:{ // MOV EAX,dword ptr [EDI]
c.pc=0xcf65;if(!sl_tick(c))return int(c.fault);
P_cf65_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_cf65_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cf65_2:;
goto L_cf67;
}
L_cf67:{ // MOV ECX,ESI
c.pc=0xcf67;if(!sl_tick(c))return int(c.fault);
P_cf67_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_cf67_1:;
goto L_cf69;
}
L_cf69:{ // SUB ECX,EDX
c.pc=0xcf69;if(!sl_tick(c))return int(c.fault);
P_cf69_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) < sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_cf69_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x4,c)^sl_get<4>(c.reg,sizeof(c.reg),0x8,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)-sl_get<4>(c.reg,sizeof(c.reg),0x8,c)))&(SlU(1)<<31))!=0),c);
P_cf69_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) - sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_cf69_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x4,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cf69_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) == SlU(0x0ULL)),c);
P_cf69_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & SlU(0xffULL)),c);
P_cf69_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cf69_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cf69_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cf69_9:;
goto L_cf6b;
}
L_cf6b:{ // MOV dword ptr [ESP + 0x8],ECX
c.pc=0xcf6b;if(!sl_tick(c))return int(c.fault);
P_cf6b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_cf6b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_cf6b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cf6b_3:;
goto L_cf6f;
}
L_cf6f:{ // LEA EDX,[EBP + -0x20]
c.pc=0xcf6f;if(!sl_tick(c))return int(c.fault);
P_cf6f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_cf6f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_cf6f_2:;
goto L_cf72;
}
L_cf72:{ // MOV dword ptr [ESP + 0x4],EDX
c.pc=0xcf72;if(!sl_tick(c))return int(c.fault);
P_cf72_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_cf72_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_cf72_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cf72_3:;
goto L_cf76;
}
L_cf76:{ // MOV dword ptr [ESP],EDI
c.pc=0xcf76;if(!sl_tick(c))return int(c.fault);
P_cf76_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_cf76_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cf76_2:;
goto L_cf79;
}
L_cf79:{ // CALL dword ptr [EAX + 0xac]
c.pc=0xcf79;if(!sl_tick(c))return int(c.fault);
P_cf79_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xacULL)),c);
P_cf79_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_cf79_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cf79_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_cf79_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xcf7fULL),c);
P_cf79_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_cf79_6:;
goto L_cf7f;
}
L_cf7f:{ // MOV dword ptr [EDI + 0x1b60],ESI
c.pc=0xcf7f;if(!sl_tick(c))return int(c.fault);
P_cf7f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1b60ULL)),c);
P_cf7f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_cf7f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cf7f_3:;
goto L_cf85;
}
L_cf85:{ // MOV EAX,dword ptr [EBP + -0x30]
c.pc=0xcf85;if(!sl_tick(c))return int(c.fault);
P_cf85_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd0ULL)),c);
P_cf85_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cf85_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cf85_3:;
goto L_cf88;
}
L_cf88:{ // CMP EAX,dword ptr [EDI + 0xeb8]
c.pc=0xcf88;if(!sl_tick(c))return int(c.fault);
P_cf88_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xeb8ULL)),c);
P_cf88_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_cf88_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cf88_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_cf88_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_cf88_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_cf88_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cf88_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_cf88_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_cf88_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cf88_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cf88_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cf88_12:;
goto L_cf8e;
}
L_cf8e:{ // JL 0x0000cf50
c.pc=0xcf8e;if(!sl_tick(c))return int(c.fault);
P_cf8e_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa180,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_cf8e_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa180,c)){goto L_cf50;}
P_cf8e_2:;
goto L_cf90;
}
L_cf90:{ // MOV EAX,dword ptr [EDI + 0x1b60]
c.pc=0xcf90;if(!sl_tick(c))return int(c.fault);
P_cf90_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1b60ULL)),c);
P_cf90_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_cf90_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cf90_3:;
goto L_cf96;
}
L_cf96:{ // CMP EAX,dword ptr [EBP + 0x10]
c.pc=0xcf96;if(!sl_tick(c))return int(c.fault);
P_cf96_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_cf96_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cf96_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cf96_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_cf96_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_cf96_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_cf96_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cf96_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_cf96_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_cf96_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cf96_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cf96_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cf96_12:;
goto L_cf99;
}
L_cf99:{ // JL 0x0000d011
c.pc=0xcf99;if(!sl_tick(c))return int(c.fault);
P_cf99_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa180,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_cf99_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa180,c)){goto L_d011;}
P_cf99_2:;
goto L_cf9b;
}
L_cf9b:{ // MOV dword ptr [EDI + 0xeb8],0x0
c.pc=0xcf9b;if(!sl_tick(c))return int(c.fault);
P_cf9b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xeb8ULL)),c);
P_cf9b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_cf9b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_cf9b_3:;
goto L_cfa5;
}
L_cfa5:{ // MOV ESI,dword ptr [EBP + -0x34]
c.pc=0xcfa5;if(!sl_tick(c))return int(c.fault);
P_cfa5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffccULL)),c);
P_cfa5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cfa5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cfa5_3:;
goto L_cfa8;
}
L_cfa8:{ // MOV dword ptr [ESP],ESI
c.pc=0xcfa8;if(!sl_tick(c))return int(c.fault);
P_cfa8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_cfa8_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cfa8_2:;
goto L_cfab;
}
L_cfab:{ // CALL 0x0002de1a
c.pc=0xcfab;if(!sl_tick(c))return int(c.fault);
P_cfab_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_cfab_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xcfb0ULL),c);
P_cfab_2:;
c.pc=0x2de1a;goto dispatch;
P_cfab_3:;
goto L_cfb0;
}
L_cfb0:{ // ADD ESP,0x50
c.pc=0xcfb0;if(!sl_tick(c))return int(c.fault);
P_cfb0_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x50ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_cfb0_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x50ULL)))&(SlU(0x50ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x50ULL)))&(SlU(1)<<31))!=0),c);
P_cfb0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x50ULL)),c);
P_cfb0_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cfb0_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_cfb0_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_cfb0_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_cfb0_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_cfb0_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_cfb0_9:;
goto L_cfb3;
}
L_cfb3:{ // POP ESI
c.pc=0xcfb3;if(!sl_tick(c))return int(c.fault);
P_cfb3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_cfb3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_cfb3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_cfb3_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_cfb3_4:;
goto L_cfb4;
}
L_cfb4:{ // POP EDI
c.pc=0xcfb4;if(!sl_tick(c))return int(c.fault);
P_cfb4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_cfb4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_cfb4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_cfb4_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_cfb4_4:;
goto L_cfb5;
}
L_cfb5:{ // POP EBP
c.pc=0xcfb5;if(!sl_tick(c))return int(c.fault);
P_cfb5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_cfb5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_cfb5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_cfb5_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_cfb5_4:;
goto L_cfb6;
}
L_cfb6:{ // RET
c.pc=0xcfb6;if(!sl_tick(c))return int(c.fault);
P_cfb6_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_cfb6_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_cfb6_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_cfb6_3:;
goto L_cfb7;
}
L_cfb7:{ // LEA ESI,[EBP + -0x20]
c.pc=0xcfb7;if(!sl_tick(c))return int(c.fault);
P_cfb7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_cfb7_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_cfb7_2:;
goto L_cfba;
}
L_cfba:{ // MOV dword ptr [EBP + -0x3c],ESI
c.pc=0xcfba;if(!sl_tick(c))return int(c.fault);
P_cfba_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc4ULL)),c);
P_cfba_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_cfba_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cfba_3:;
goto L_cfbd;
}
L_cfbd:{ // MOV EDX,dword ptr [EDI + 0x1b0]
c.pc=0xcfbd;if(!sl_tick(c))return int(c.fault);
P_cfbd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1b0ULL)),c);
P_cfbd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_cfbd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cfbd_3:;
goto L_cfc3;
}
L_cfc3:{ // SHL EDX,0x2
c.pc=0xcfc3;if(!sl_tick(c))return int(c.fault);
P_cfc3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x50e00,(SlU(0x2ULL) & SlU(0x1fULL)),c);
P_cfc3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x50e80,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_cfc3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_lshift(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c)),c);
P_cfc3_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x24d00,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) != SlU(0x0ULL)),c);
P_cfc3_4:;
sl_put<4>(c.temp,sizeof(c.temp),0x24d80,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) - SlU(0x1ULL)),c);
P_cfc3_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x24e00,sl_lshift(sl_get<4>(c.temp,sizeof(c.temp),0x50e80,c),sl_get<4>(c.temp,sizeof(c.temp),0x24d80,c)),c);
P_cfc3_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x24f00,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x24e00,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cfc3_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x24f80,(!sl_get<1>(c.temp,sizeof(c.temp),0x24d00,c)),c);
P_cfc3_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x25000,(sl_get<1>(c.temp,sizeof(c.temp),0x24f80,c) & sl_get<1>(c.reg,sizeof(c.reg),0x200,c)),c);
P_cfc3_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x25080,(sl_get<1>(c.temp,sizeof(c.temp),0x24d00,c) & sl_get<1>(c.temp,sizeof(c.temp),0x24f00,c)),c);
P_cfc3_10:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x25000,c) | sl_get<1>(c.temp,sizeof(c.temp),0x25080,c)),c);
P_cfc3_11:;
sl_put<1>(c.temp,sizeof(c.temp),0x25200,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) == SlU(0x1ULL)),c);
P_cfc3_12:;
sl_put<1>(c.temp,sizeof(c.temp),0x25280,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cfc3_13:;
sl_put<1>(c.temp,sizeof(c.temp),0x25380,(sl_get<1>(c.reg,sizeof(c.reg),0x200,c) ^ sl_get<1>(c.temp,sizeof(c.temp),0x25280,c)),c);
P_cfc3_14:;
sl_put<1>(c.temp,sizeof(c.temp),0x25400,(!sl_get<1>(c.temp,sizeof(c.temp),0x25200,c)),c);
P_cfc3_15:;
sl_put<1>(c.temp,sizeof(c.temp),0x25480,(sl_get<1>(c.temp,sizeof(c.temp),0x25400,c) & sl_get<1>(c.reg,sizeof(c.reg),0x20b,c)),c);
P_cfc3_16:;
sl_put<1>(c.temp,sizeof(c.temp),0x25500,(sl_get<1>(c.temp,sizeof(c.temp),0x25200,c) & sl_get<1>(c.temp,sizeof(c.temp),0x25380,c)),c);
P_cfc3_17:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(sl_get<1>(c.temp,sizeof(c.temp),0x25480,c) | sl_get<1>(c.temp,sizeof(c.temp),0x25500,c)),c);
P_cfc3_18:;
sl_put<1>(c.temp,sizeof(c.temp),0x22b80,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) != SlU(0x0ULL)),c);
P_cfc3_19:;
sl_put<1>(c.temp,sizeof(c.temp),0x22c80,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_cfc3_20:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d00,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_cfc3_21:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d80,(sl_get<1>(c.temp,sizeof(c.temp),0x22d00,c) & sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_cfc3_22:;
sl_put<1>(c.temp,sizeof(c.temp),0x22e00,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22c80,c)),c);
P_cfc3_23:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_get<1>(c.temp,sizeof(c.temp),0x22d80,c) | sl_get<1>(c.temp,sizeof(c.temp),0x22e00,c)),c);
P_cfc3_24:;
sl_put<1>(c.temp,sizeof(c.temp),0x22f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_cfc3_25:;
sl_put<1>(c.temp,sizeof(c.temp),0x23000,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_cfc3_26:;
sl_put<1>(c.temp,sizeof(c.temp),0x23080,(sl_get<1>(c.temp,sizeof(c.temp),0x23000,c) & sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_cfc3_27:;
sl_put<1>(c.temp,sizeof(c.temp),0x23100,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22f80,c)),c);
P_cfc3_28:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x23080,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23100,c)),c);
P_cfc3_29:;
sl_put<4>(c.temp,sizeof(c.temp),0x23200,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_cfc3_30:;
sl_put<1>(c.temp,sizeof(c.temp),0x23280,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x23200,c)),c);
P_cfc3_31:;
sl_put<1>(c.temp,sizeof(c.temp),0x23300,(sl_get<1>(c.temp,sizeof(c.temp),0x23280,c) & SlU(0x1ULL)),c);
P_cfc3_32:;
sl_put<1>(c.temp,sizeof(c.temp),0x23400,(sl_get<1>(c.temp,sizeof(c.temp),0x23300,c) == SlU(0x0ULL)),c);
P_cfc3_33:;
sl_put<1>(c.temp,sizeof(c.temp),0x23480,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_cfc3_34:;
sl_put<1>(c.temp,sizeof(c.temp),0x23500,(sl_get<1>(c.temp,sizeof(c.temp),0x23480,c) & sl_get<1>(c.reg,sizeof(c.reg),0x202,c)),c);
P_cfc3_35:;
sl_put<1>(c.temp,sizeof(c.temp),0x23580,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x23400,c)),c);
P_cfc3_36:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x23500,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23580,c)),c);
P_cfc3_37:;
goto L_cfc6;
}
L_cfc6:{ // MOV EAX,dword ptr [EBP + -0x2c]
c.pc=0xcfc6;if(!sl_tick(c))return int(c.fault);
P_cfc6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_cfc6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cfc6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cfc6_3:;
goto L_cfc9;
}
L_cfc9:{ // MOV ESI,dword ptr [EBP + 0xc]
c.pc=0xcfc9;if(!sl_tick(c))return int(c.fault);
P_cfc9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_cfc9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cfc9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cfc9_3:;
goto L_cfcc;
}
L_cfcc:{ // LEA ECX,[ESI + EAX*0x8]
c.pc=0xcfcc;if(!sl_tick(c))return int(c.fault);
P_cfcc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x8ULL)),c);
P_cfcc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_cfcc_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x3580,c),c);
P_cfcc_3:;
goto L_cfcf;
}
L_cfcf:{ // MOV dword ptr [ESP + 0x8],EDX
c.pc=0xcfcf;if(!sl_tick(c))return int(c.fault);
P_cfcf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_cfcf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_cfcf_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cfcf_3:;
goto L_cfd3;
}
L_cfd3:{ // MOV dword ptr [ESP + 0x4],ECX
c.pc=0xcfd3;if(!sl_tick(c))return int(c.fault);
P_cfd3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_cfd3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_cfd3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cfd3_3:;
goto L_cfd7;
}
L_cfd7:{ // MOV EAX,dword ptr [EBP + -0x3c]
c.pc=0xcfd7;if(!sl_tick(c))return int(c.fault);
P_cfd7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc4ULL)),c);
P_cfd7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_cfd7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cfd7_3:;
goto L_cfda;
}
L_cfda:{ // MOV dword ptr [ESP],EAX
c.pc=0xcfda;if(!sl_tick(c))return int(c.fault);
P_cfda_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_cfda_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cfda_2:;
goto L_cfdd;
}
L_cfdd:{ // CALL 0x001031e5
c.pc=0xcfdd;if(!sl_tick(c))return int(c.fault);
P_cfdd_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_cfdd_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xcfe2ULL),c);
P_cfdd_2:;
c.pc=0x1031e5;goto dispatch;
P_cfdd_3:;
goto L_cfe2;
}
L_cfe2:{ // JMP 0x0000cf3e
c.pc=0xcfe2;if(!sl_tick(c))return int(c.fault);
P_cfe2_0:;
goto L_cf3e;
P_cfe2_1:;
goto L_cfe7;
}
L_cfe7:{ // MOV ESI,EAX
c.pc=0xcfe7;if(!sl_tick(c))return int(c.fault);
P_cfe7_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_cfe7_1:;
goto L_cfe9;
}
L_cfe9:{ // MOV EDX,dword ptr [EDI]
c.pc=0xcfe9;if(!sl_tick(c))return int(c.fault);
P_cfe9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_cfe9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_cfe9_2:;
goto L_cfeb;
}
L_cfeb:{ // MOV dword ptr [ESP + 0x8],0x1
c.pc=0xcfeb;if(!sl_tick(c))return int(c.fault);
P_cfeb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_cfeb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x1ULL),c);
P_cfeb_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_cfeb_3:;
goto L_cff3;
}
L_cff3:{ // LEA EAX,[EDI + EAX*0x8 + 0x220]
c.pc=0xcff3;if(!sl_tick(c))return int(c.fault);
P_cff3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x220ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c);
P_cff3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x8ULL)),c);
P_cff3_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_cff3_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c),c);
P_cff3_4:;
goto L_cffa;
}
L_cffa:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xcffa;if(!sl_tick(c))return int(c.fault);
P_cffa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_cffa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_cffa_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cffa_3:;
goto L_cffe;
}
L_cffe:{ // MOV dword ptr [ESP],EDI
c.pc=0xcffe;if(!sl_tick(c))return int(c.fault);
P_cffe_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_cffe_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_cffe_2:;
goto L_d001;
}
L_d001:{ // CALL dword ptr [EDX + 0x54]
c.pc=0xd001;if(!sl_tick(c))return int(c.fault);
P_d001_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x54ULL)),c);
P_d001_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d001_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d001_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d001_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd004ULL),c);
P_d001_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d001_6:;
goto L_d004;
}
L_d004:{ // ADD ESI,0x1
c.pc=0xd004;if(!sl_tick(c))return int(c.fault);
P_d004_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d004_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_d004_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ULL)),c);
P_d004_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d004_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_d004_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_d004_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d004_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d004_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d004_9:;
goto L_d007;
}
L_d007:{ // MOV dword ptr [EBP + -0x30],ESI
c.pc=0xd007;if(!sl_tick(c))return int(c.fault);
P_d007_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd0ULL)),c);
P_d007_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d007_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d007_3:;
goto L_d00a;
}
L_d00a:{ // MOV EAX,ESI
c.pc=0xd00a;if(!sl_tick(c))return int(c.fault);
P_d00a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d00a_1:;
goto L_d00c;
}
L_d00c:{ // JMP 0x0000cf48
c.pc=0xd00c;if(!sl_tick(c))return int(c.fault);
P_d00c_0:;
goto L_cf48;
P_d00c_1:;
goto L_d011;
}
L_d011:{ // MOV EDX,dword ptr [EDI]
c.pc=0xd011;if(!sl_tick(c))return int(c.fault);
P_d011_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_d011_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d011_2:;
goto L_d013;
}
L_d013:{ // SUB dword ptr [EBP + 0x10],EAX
c.pc=0xd013;if(!sl_tick(c))return int(c.fault);
P_d013_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d013_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d013_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d013_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d013_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x0,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x0,c)))&(SlU(1)<<31))!=0),c);
P_d013_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d013_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d013_7:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d013_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d013_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d013_10:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d013_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c) == SlU(0x0ULL)),c);
P_d013_12:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d013_13:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c) & SlU(0xffULL)),c);
P_d013_14:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d013_15:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d013_16:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d013_17:;
goto L_d016;
}
L_d016:{ // MOV ECX,dword ptr [EBP + 0x10]
c.pc=0xd016;if(!sl_tick(c))return int(c.fault);
P_d016_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d016_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d016_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d016_3:;
goto L_d019;
}
L_d019:{ // MOV dword ptr [ESP + 0x8],ECX
c.pc=0xd019;if(!sl_tick(c))return int(c.fault);
P_d019_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d019_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_d019_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d019_3:;
goto L_d01d;
}
L_d01d:{ // LEA EAX,[EBP + -0x20]
c.pc=0xd01d;if(!sl_tick(c))return int(c.fault);
P_d01d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_d01d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_d01d_2:;
goto L_d020;
}
L_d020:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xd020;if(!sl_tick(c))return int(c.fault);
P_d020_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d020_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d020_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d020_3:;
goto L_d024;
}
L_d024:{ // MOV dword ptr [ESP],EDI
c.pc=0xd024;if(!sl_tick(c))return int(c.fault);
P_d024_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d024_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d024_2:;
goto L_d027;
}
L_d027:{ // CALL dword ptr [EDX + 0xac]
c.pc=0xd027;if(!sl_tick(c))return int(c.fault);
P_d027_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0xacULL)),c);
P_d027_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d027_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d027_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d027_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd02dULL),c);
P_d027_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d027_6:;
goto L_d02d;
}
L_d02d:{ // JMP 0x0000cf9b
c.pc=0xd02d;if(!sl_tick(c))return int(c.fault);
P_d02d_0:;
goto L_cf9b;
P_d02d_1:;
goto L_d032;
}
L_d032:{ // PUSH EBP
c.pc=0xd032;if(!sl_tick(c))return int(c.fault);
P_d032_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_d032_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d032_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d032_3:;
goto L_d033;
}
L_d033:{ // MOV EBP,ESP
c.pc=0xd033;if(!sl_tick(c))return int(c.fault);
P_d033_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_d033_1:;
goto L_d035;
}
L_d035:{ // PUSH EDI
c.pc=0xd035;if(!sl_tick(c))return int(c.fault);
P_d035_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d035_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d035_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d035_3:;
goto L_d036;
}
L_d036:{ // PUSH ESI
c.pc=0xd036;if(!sl_tick(c))return int(c.fault);
P_d036_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d036_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d036_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d036_3:;
goto L_d037;
}
L_d037:{ // SUB ESP,0x10
c.pc=0xd037;if(!sl_tick(c))return int(c.fault);
P_d037_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x10ULL)),c);
P_d037_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x10ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_d037_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x10ULL)),c);
P_d037_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d037_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d037_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d037_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d037_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d037_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d037_9:;
goto L_d03a;
}
L_d03a:{ // MOV EDI,dword ptr [EBP + 0x8]
c.pc=0xd03a;if(!sl_tick(c))return int(c.fault);
P_d03a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_d03a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d03a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d03a_3:;
goto L_d03d;
}
L_d03d:{ // MOV ESI,dword ptr [EBP + 0xc]
c.pc=0xd03d;if(!sl_tick(c))return int(c.fault);
P_d03d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_d03d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d03d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d03d_3:;
goto L_d040;
}
L_d040:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0xd040;if(!sl_tick(c))return int(c.fault);
P_d040_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_d040_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d040_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d040_3:;
goto L_d046;
}
L_d046:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xd046;if(!sl_tick(c))return int(c.fault);
P_d046_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d046_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d046_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d046_3:;
goto L_d04a;
}
L_d04a:{ // MOV EAX,dword ptr [EDI + 0x4]
c.pc=0xd04a;if(!sl_tick(c))return int(c.fault);
P_d04a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x4ULL)),c);
P_d04a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d04a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d04a_3:;
goto L_d04d;
}
L_d04d:{ // MOV dword ptr [ESP],EAX
c.pc=0xd04d;if(!sl_tick(c))return int(c.fault);
P_d04d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d04d_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d04d_2:;
goto L_d050;
}
L_d050:{ // CALL 0x00024cf6
c.pc=0xd050;if(!sl_tick(c))return int(c.fault);
P_d050_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d050_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd055ULL),c);
P_d050_2:;
c.pc=0x24cf6;goto dispatch;
P_d050_3:;
goto L_d055;
}
L_d055:{ // CMP ESI,0xf
c.pc=0xd055;if(!sl_tick(c))return int(c.fault);
P_d055_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d055_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0xfULL)),c);
P_d055_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0xfULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0xfULL)))&(SlU(1)<<31))!=0),c);
P_d055_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0xfULL)),c);
P_d055_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d055_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_d055_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_d055_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d055_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d055_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d055_10:;
goto L_d058;
}
L_d058:{ // JG 0x0000d084
c.pc=0xd058;if(!sl_tick(c))return int(c.fault);
P_d058_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d058_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d058_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_d058_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_d084;}
P_d058_4:;
goto L_d05a;
}
L_d05a:{ // CMP byte ptr [ESI + EDI*0x1 + 0x1b4],0x0
c.pc=0xd05a;if(!sl_tick(c))return int(c.fault);
P_d05a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x1b4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d05a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) * SlU(0x1ULL)),c);
P_d05a_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_d05a_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c)),c),c);
P_d05a_4:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d05a_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d05a_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d05a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d05a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d05a_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d05a_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d05a_11:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d05a_12:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d05a_13:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d05a_14:;
goto L_d062;
}
L_d062:{ // JNZ 0x0000d073
c.pc=0xd062;if(!sl_tick(c))return int(c.fault);
P_d062_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d062_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_d073;}
P_d062_2:;
goto L_d064;
}
L_d064:{ // MOV byte ptr [ESI + EDI*0x1 + 0x1b4],0x0
c.pc=0xd064;if(!sl_tick(c))return int(c.fault);
P_d064_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x1b4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d064_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) * SlU(0x1ULL)),c);
P_d064_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_d064_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_d064_4:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_d064_5:;
goto L_d06c;
}
L_d06c:{ // ADD ESP,0x10
c.pc=0xd06c;if(!sl_tick(c))return int(c.fault);
P_d06c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d06c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_d06c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_d06c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d06c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d06c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d06c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d06c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d06c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d06c_9:;
goto L_d06f;
}
L_d06f:{ // POP ESI
c.pc=0xd06f;if(!sl_tick(c))return int(c.fault);
P_d06f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d06f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d06f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d06f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d06f_4:;
goto L_d070;
}
L_d070:{ // POP EDI
c.pc=0xd070;if(!sl_tick(c))return int(c.fault);
P_d070_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d070_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d070_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d070_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d070_4:;
goto L_d071;
}
L_d071:{ // POP EBP
c.pc=0xd071;if(!sl_tick(c))return int(c.fault);
P_d071_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d071_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d071_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d071_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d071_4:;
goto L_d072;
}
L_d072:{ // RET
c.pc=0xd072;if(!sl_tick(c))return int(c.fault);
P_d072_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d072_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d072_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_d072_3:;
goto L_d073;
}
L_d073:{ // MOV EAX,dword ptr [EDI]
c.pc=0xd073;if(!sl_tick(c))return int(c.fault);
P_d073_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_d073_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d073_2:;
goto L_d075;
}
L_d075:{ // MOV dword ptr [ESP + 0x4],ESI
c.pc=0xd075;if(!sl_tick(c))return int(c.fault);
P_d075_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d075_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d075_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d075_3:;
goto L_d079;
}
L_d079:{ // MOV dword ptr [ESP],EDI
c.pc=0xd079;if(!sl_tick(c))return int(c.fault);
P_d079_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d079_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d079_2:;
goto L_d07c;
}
L_d07c:{ // CALL dword ptr [EAX + 0xa0]
c.pc=0xd07c;if(!sl_tick(c))return int(c.fault);
P_d07c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xa0ULL)),c);
P_d07c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d07c_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d07c_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d07c_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd082ULL),c);
P_d07c_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d07c_6:;
goto L_d082;
}
L_d082:{ // JMP 0x0000d064
c.pc=0xd082;if(!sl_tick(c))return int(c.fault);
P_d082_0:;
goto L_d064;
P_d082_1:;
goto L_d084;
}
L_d084:{ // XOR ESI,ESI
c.pc=0xd084;if(!sl_tick(c))return int(c.fault);
P_d084_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d084_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d084_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d084_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d084_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_d084_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_d084_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d084_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d084_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d084_9:;
goto L_d086;
}
L_d086:{ // MOV EAX,dword ptr [EDI]
c.pc=0xd086;if(!sl_tick(c))return int(c.fault);
P_d086_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_d086_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d086_2:;
goto L_d088;
}
L_d088:{ // MOV dword ptr [ESP + 0x4],ESI
c.pc=0xd088;if(!sl_tick(c))return int(c.fault);
P_d088_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d088_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d088_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d088_3:;
goto L_d08c;
}
L_d08c:{ // MOV dword ptr [ESP],EDI
c.pc=0xd08c;if(!sl_tick(c))return int(c.fault);
P_d08c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d08c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d08c_2:;
goto L_d08f;
}
L_d08f:{ // CALL dword ptr [EAX + 0xa8]
c.pc=0xd08f;if(!sl_tick(c))return int(c.fault);
P_d08f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xa8ULL)),c);
P_d08f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d08f_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d08f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d08f_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd095ULL),c);
P_d08f_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d08f_6:;
goto L_d095;
}
L_d095:{ // ADD ESI,0x1
c.pc=0xd095;if(!sl_tick(c))return int(c.fault);
P_d095_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d095_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_d095_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ULL)),c);
P_d095_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d095_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_d095_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_d095_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d095_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d095_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d095_9:;
goto L_d098;
}
L_d098:{ // CMP ESI,0x10
c.pc=0xd098;if(!sl_tick(c))return int(c.fault);
P_d098_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d098_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x10ULL)),c);
P_d098_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x10ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_d098_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x10ULL)),c);
P_d098_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d098_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_d098_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_d098_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d098_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d098_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d098_10:;
goto L_d09b;
}
L_d09b:{ // JNZ 0x0000d086
c.pc=0xd09b;if(!sl_tick(c))return int(c.fault);
P_d09b_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d09b_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_d086;}
P_d09b_2:;
goto L_d09d;
}
L_d09d:{ // ADD ESP,0x10
c.pc=0xd09d;if(!sl_tick(c))return int(c.fault);
P_d09d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d09d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_d09d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_d09d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d09d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d09d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d09d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d09d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d09d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d09d_9:;
goto L_d0a0;
}
L_d0a0:{ // POP ESI
c.pc=0xd0a0;if(!sl_tick(c))return int(c.fault);
P_d0a0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d0a0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d0a0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d0a0_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d0a0_4:;
goto L_d0a1;
}
L_d0a1:{ // POP EDI
c.pc=0xd0a1;if(!sl_tick(c))return int(c.fault);
P_d0a1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d0a1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d0a1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d0a1_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d0a1_4:;
goto L_d0a2;
}
L_d0a2:{ // POP EBP
c.pc=0xd0a2;if(!sl_tick(c))return int(c.fault);
P_d0a2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d0a2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d0a2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d0a2_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d0a2_4:;
goto L_d0a3;
}
L_d0a3:{ // RET
c.pc=0xd0a3;if(!sl_tick(c))return int(c.fault);
P_d0a3_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d0a3_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d0a3_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_d0a3_3:;
goto L_d0a4;
}
L_d0a4:{ // PUSH EBP
c.pc=0xd0a4;if(!sl_tick(c))return int(c.fault);
P_d0a4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_d0a4_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d0a4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d0a4_3:;
goto L_d0a5;
}
L_d0a5:{ // MOV EBP,ESP
c.pc=0xd0a5;if(!sl_tick(c))return int(c.fault);
P_d0a5_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_d0a5_1:;
goto L_d0a7;
}
L_d0a7:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0xd0a7;if(!sl_tick(c))return int(c.fault);
P_d0a7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_d0a7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d0a7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d0a7_3:;
goto L_d0aa;
}
L_d0aa:{ // MOV ECX,dword ptr [EDX]
c.pc=0xd0aa;if(!sl_tick(c))return int(c.fault);
P_d0aa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_d0aa_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d0aa_2:;
goto L_d0ac;
}
L_d0ac:{ // MOV ECX,dword ptr [ECX + 0x9c]
c.pc=0xd0ac;if(!sl_tick(c))return int(c.fault);
P_d0ac_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x9cULL)),c);
P_d0ac_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d0ac_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d0ac_3:;
goto L_d0b2;
}
L_d0b2:{ // POP EBP
c.pc=0xd0b2;if(!sl_tick(c))return int(c.fault);
P_d0b2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d0b2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d0b2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d0b2_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d0b2_4:;
goto L_d0b3;
}
L_d0b3:{ // JMP ECX
c.pc=0xd0b3;if(!sl_tick(c))return int(c.fault);
P_d0b3_0:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c));goto dispatch;
P_d0b3_1:;
c.pc=0xd0b5;goto dispatch;
}
L_d0b6:{ // PUSH EBP
c.pc=0xd0b6;if(!sl_tick(c))return int(c.fault);
P_d0b6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_d0b6_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d0b6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d0b6_3:;
goto L_d0b7;
}
L_d0b7:{ // MOV EBP,ESP
c.pc=0xd0b7;if(!sl_tick(c))return int(c.fault);
P_d0b7_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_d0b7_1:;
goto L_d0b9;
}
L_d0b9:{ // PUSH EDI
c.pc=0xd0b9;if(!sl_tick(c))return int(c.fault);
P_d0b9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d0b9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d0b9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d0b9_3:;
goto L_d0ba;
}
L_d0ba:{ // PUSH ESI
c.pc=0xd0ba;if(!sl_tick(c))return int(c.fault);
P_d0ba_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d0ba_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d0ba_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d0ba_3:;
goto L_d0bb;
}
L_d0bb:{ // SUB ESP,0x20
c.pc=0xd0bb;if(!sl_tick(c))return int(c.fault);
P_d0bb_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x20ULL)),c);
P_d0bb_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x20ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_d0bb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x20ULL)),c);
P_d0bb_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d0bb_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d0bb_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d0bb_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d0bb_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d0bb_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d0bb_9:;
goto L_d0be;
}
L_d0be:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0xd0be;if(!sl_tick(c))return int(c.fault);
P_d0be_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_d0be_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d0be_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d0be_3:;
goto L_d0c1;
}
L_d0c1:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0xd0c1;if(!sl_tick(c))return int(c.fault);
P_d0c1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_d0c1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d0c1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d0c1_3:;
goto L_d0c4;
}
L_d0c4:{ // MOV dword ptr [EBP + -0x18],EAX
c.pc=0xd0c4;if(!sl_tick(c))return int(c.fault);
P_d0c4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_d0c4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d0c4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d0c4_3:;
goto L_d0c7;
}
L_d0c7:{ // MOV EDI,dword ptr [EBP + 0x10]
c.pc=0xd0c7;if(!sl_tick(c))return int(c.fault);
P_d0c7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d0c7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d0c7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d0c7_3:;
goto L_d0ca;
}
L_d0ca:{ // LEA EDX,[ESI + 0xe50]
c.pc=0xd0ca;if(!sl_tick(c))return int(c.fault);
P_d0ca_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0xe50ULL)),c);
P_d0ca_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_d0ca_2:;
goto L_d0d0;
}
L_d0d0:{ // MOV dword ptr [EBP + -0x14],EDX
c.pc=0xd0d0;if(!sl_tick(c))return int(c.fault);
P_d0d0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_d0d0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d0d0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d0d0_3:;
goto L_d0d3;
}
L_d0d3:{ // MOV dword ptr [ESP],EDX
c.pc=0xd0d3;if(!sl_tick(c))return int(c.fault);
P_d0d3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d0d3_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d0d3_2:;
goto L_d0d6;
}
L_d0d6:{ // CALL 0x0002ddfc
c.pc=0xd0d6;if(!sl_tick(c))return int(c.fault);
P_d0d6_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d0d6_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd0dbULL),c);
P_d0d6_2:;
c.pc=0x2ddfc;goto dispatch;
P_d0d6_3:;
goto L_d0db;
}
L_d0db:{ // TEST AL,AL
c.pc=0xd0db;if(!sl_tick(c))return int(c.fault);
P_d0db_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d0db_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d0db_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x54d80,(sl_get<1>(c.reg,sizeof(c.reg),0x0,c) & sl_get<1>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d0db_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d0db_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c) == SlU(0x0ULL)),c);
P_d0db_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c) & SlU(0xffULL)),c);
P_d0db_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d0db_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d0db_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d0db_9:;
goto L_d0dd;
}
L_d0dd:{ // JNZ 0x0000d0e6
c.pc=0xd0dd;if(!sl_tick(c))return int(c.fault);
P_d0dd_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d0dd_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_d0e6;}
P_d0dd_2:;
goto L_d0df;
}
L_d0df:{ // ADD ESP,0x20
c.pc=0xd0df;if(!sl_tick(c))return int(c.fault);
P_d0df_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d0df_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(0x20ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_d0df_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x20ULL)),c);
P_d0df_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d0df_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d0df_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d0df_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d0df_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d0df_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d0df_9:;
goto L_d0e2;
}
L_d0e2:{ // POP ESI
c.pc=0xd0e2;if(!sl_tick(c))return int(c.fault);
P_d0e2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d0e2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d0e2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d0e2_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d0e2_4:;
goto L_d0e3;
}
L_d0e3:{ // POP EDI
c.pc=0xd0e3;if(!sl_tick(c))return int(c.fault);
P_d0e3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d0e3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d0e3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d0e3_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d0e3_4:;
goto L_d0e4;
}
L_d0e4:{ // POP EBP
c.pc=0xd0e4;if(!sl_tick(c))return int(c.fault);
P_d0e4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d0e4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d0e4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d0e4_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d0e4_4:;
goto L_d0e5;
}
L_d0e5:{ // RET
c.pc=0xd0e5;if(!sl_tick(c))return int(c.fault);
P_d0e5_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d0e5_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d0e5_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_d0e5_3:;
goto L_d0e6;
}
L_d0e6:{ // LEA EAX,[ESI + 0xe84]
c.pc=0xd0e6;if(!sl_tick(c))return int(c.fault);
P_d0e6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0xe84ULL)),c);
P_d0e6_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_d0e6_2:;
goto L_d0ec;
}
L_d0ec:{ // MOV dword ptr [EBP + -0x10],EAX
c.pc=0xd0ec;if(!sl_tick(c))return int(c.fault);
P_d0ec_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_d0ec_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d0ec_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d0ec_3:;
goto L_d0ef;
}
L_d0ef:{ // MOV dword ptr [ESP],EAX
c.pc=0xd0ef;if(!sl_tick(c))return int(c.fault);
P_d0ef_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d0ef_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d0ef_2:;
goto L_d0f2;
}
L_d0f2:{ // CALL 0x0002ddfc
c.pc=0xd0f2;if(!sl_tick(c))return int(c.fault);
P_d0f2_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d0f2_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd0f7ULL),c);
P_d0f2_2:;
c.pc=0x2ddfc;goto dispatch;
P_d0f2_3:;
goto L_d0f7;
}
L_d0f7:{ // MOV byte ptr [EBP + -0x9],AL
c.pc=0xd0f7;if(!sl_tick(c))return int(c.fault);
P_d0f7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff7ULL)),c);
P_d0f7_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,sl_get<1>(c.reg,sizeof(c.reg),0x0,c),c);
P_d0f7_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5100,c),c);
P_d0f7_3:;
goto L_d0fa;
}
L_d0fa:{ // CMP EDI,0xff
c.pc=0xd0fa;if(!sl_tick(c))return int(c.fault);
P_d0fa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30a80,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d0fa_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) < SlU(0xffULL)),c);
P_d0fa_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^SlU(0xffULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)-SlU(0xffULL)))&(SlU(1)<<31))!=0),c);
P_d0fa_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30b80,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) - SlU(0xffULL)),c);
P_d0fa_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d0fa_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) == SlU(0x0ULL)),c);
P_d0fa_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) & SlU(0xffULL)),c);
P_d0fa_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d0fa_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d0fa_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d0fa_10:;
goto L_d100;
}
L_d100:{ // JLE 0x0000d10a
c.pc=0xd100;if(!sl_tick(c))return int(c.fault);
P_d100_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d100_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_d100_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_d10a;}
P_d100_3:;
goto L_d102;
}
L_d102:{ // CMP EDI,0x100
c.pc=0xd102;if(!sl_tick(c))return int(c.fault);
P_d102_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30a80,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d102_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) < SlU(0x100ULL)),c);
P_d102_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^SlU(0x100ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)-SlU(0x100ULL)))&(SlU(1)<<31))!=0),c);
P_d102_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30b80,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) - SlU(0x100ULL)),c);
P_d102_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d102_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) == SlU(0x0ULL)),c);
P_d102_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) & SlU(0xffULL)),c);
P_d102_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d102_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d102_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d102_10:;
goto L_d108;
}
L_d108:{ // JG 0x0000d137
c.pc=0xd108;if(!sl_tick(c))return int(c.fault);
P_d108_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d108_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d108_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_d108_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_d137;}
P_d108_4:;
goto L_d10a;
}
L_d10a:{ // MOV EAX,dword ptr [ESI]
c.pc=0xd10a;if(!sl_tick(c))return int(c.fault);
P_d10a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_d10a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d10a_2:;
goto L_d10c;
}
L_d10c:{ // MOV dword ptr [ESP + 0x8],EDI
c.pc=0xd10c;if(!sl_tick(c))return int(c.fault);
P_d10c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d10c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d10c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d10c_3:;
goto L_d110;
}
L_d110:{ // MOV EDX,dword ptr [EBP + -0x18]
c.pc=0xd110;if(!sl_tick(c))return int(c.fault);
P_d110_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_d110_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d110_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d110_3:;
goto L_d113;
}
L_d113:{ // MOV dword ptr [ESP + 0x4],EDX
c.pc=0xd113;if(!sl_tick(c))return int(c.fault);
P_d113_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d113_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d113_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d113_3:;
goto L_d117;
}
L_d117:{ // MOV dword ptr [ESP],ESI
c.pc=0xd117;if(!sl_tick(c))return int(c.fault);
P_d117_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d117_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d117_2:;
goto L_d11a;
}
L_d11a:{ // CALL dword ptr [EAX + 0xb0]
c.pc=0xd11a;if(!sl_tick(c))return int(c.fault);
P_d11a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xb0ULL)),c);
P_d11a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d11a_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d11a_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d11a_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd120ULL),c);
P_d11a_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d11a_6:;
goto L_d120;
}
L_d120:{ // CMP byte ptr [EBP + -0x9],0x0
c.pc=0xd120;if(!sl_tick(c))return int(c.fault);
P_d120_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff7ULL)),c);
P_d120_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d120_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d120_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d120_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d120_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d120_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d120_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d120_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d120_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d120_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d120_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d120_12:;
goto L_d124;
}
L_d124:{ // JNZ 0x0000d18a
c.pc=0xd124;if(!sl_tick(c))return int(c.fault);
P_d124_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d124_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_d18a;}
P_d124_2:;
goto L_d126;
}
L_d126:{ // MOV EDX,dword ptr [EBP + -0x14]
c.pc=0xd126;if(!sl_tick(c))return int(c.fault);
P_d126_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_d126_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d126_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d126_3:;
goto L_d129;
}
L_d129:{ // MOV dword ptr [EBP + 0x8],EDX
c.pc=0xd129;if(!sl_tick(c))return int(c.fault);
P_d129_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_d129_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d129_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d129_3:;
goto L_d12c;
}
L_d12c:{ // ADD ESP,0x20
c.pc=0xd12c;if(!sl_tick(c))return int(c.fault);
P_d12c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d12c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(0x20ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_d12c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x20ULL)),c);
P_d12c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d12c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d12c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d12c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d12c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d12c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d12c_9:;
goto L_d12f;
}
L_d12f:{ // POP ESI
c.pc=0xd12f;if(!sl_tick(c))return int(c.fault);
P_d12f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d12f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d12f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d12f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d12f_4:;
goto L_d130;
}
L_d130:{ // POP EDI
c.pc=0xd130;if(!sl_tick(c))return int(c.fault);
P_d130_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d130_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d130_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d130_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d130_4:;
goto L_d131;
}
L_d131:{ // POP EBP
c.pc=0xd131;if(!sl_tick(c))return int(c.fault);
P_d131_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d131_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d131_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d131_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d131_4:;
goto L_d132;
}
L_d132:{ // JMP 0x0002de1a
c.pc=0xd132;if(!sl_tick(c))return int(c.fault);
P_d132_0:;
c.pc=0x2de1a;goto dispatch;
P_d132_1:;
goto L_d137;
}
L_d137:{ // MOV EAX,dword ptr [ESI]
c.pc=0xd137;if(!sl_tick(c))return int(c.fault);
P_d137_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_d137_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d137_2:;
goto L_d139;
}
L_d139:{ // MOV dword ptr [ESP + 0x8],0x100
c.pc=0xd139;if(!sl_tick(c))return int(c.fault);
P_d139_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d139_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x100ULL),c);
P_d139_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_d139_3:;
goto L_d141;
}
L_d141:{ // MOV EDX,dword ptr [EBP + -0x18]
c.pc=0xd141;if(!sl_tick(c))return int(c.fault);
P_d141_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_d141_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d141_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d141_3:;
goto L_d144;
}
L_d144:{ // MOV dword ptr [ESP + 0x4],EDX
c.pc=0xd144;if(!sl_tick(c))return int(c.fault);
P_d144_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d144_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d144_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d144_3:;
goto L_d148;
}
L_d148:{ // MOV dword ptr [ESP],ESI
c.pc=0xd148;if(!sl_tick(c))return int(c.fault);
P_d148_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d148_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d148_2:;
goto L_d14b;
}
L_d14b:{ // CALL dword ptr [EAX + 0xb0]
c.pc=0xd14b;if(!sl_tick(c))return int(c.fault);
P_d14b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xb0ULL)),c);
P_d14b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d14b_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d14b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d14b_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd151ULL),c);
P_d14b_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d14b_6:;
goto L_d151;
}
L_d151:{ // SUB EDI,0x100
c.pc=0xd151;if(!sl_tick(c))return int(c.fault);
P_d151_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) < SlU(0x100ULL)),c);
P_d151_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)^SlU(0x100ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)-SlU(0x100ULL)))&(SlU(1)<<31))!=0),c);
P_d151_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) - SlU(0x100ULL)),c);
P_d151_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d151_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) == SlU(0x0ULL)),c);
P_d151_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) & SlU(0xffULL)),c);
P_d151_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d151_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d151_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d151_9:;
goto L_d157;
}
L_d157:{ // ADD dword ptr [ESI + 0x1b60],0x100
c.pc=0xd157;if(!sl_tick(c))return int(c.fault);
P_d157_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1b60ULL)),c);
P_d157_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d157_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)+SlU(0x100ULL))&sl_mask(32))<sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)),c);
P_d157_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d157_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)+SlU(0x100ULL)))&(SlU(0x100ULL)^(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)+SlU(0x100ULL)))&(SlU(1)<<31))!=0),c);
P_d157_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d157_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c) + SlU(0x100ULL)),c);
P_d157_7:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_d157_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d157_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d157_10:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d157_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c) == SlU(0x0ULL)),c);
P_d157_12:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d157_13:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c) & SlU(0xffULL)),c);
P_d157_14:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d157_15:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d157_16:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d157_17:;
goto L_d161;
}
L_d161:{ // MOV EAX,dword ptr [ESI + 0x4]
c.pc=0xd161;if(!sl_tick(c))return int(c.fault);
P_d161_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x4ULL)),c);
P_d161_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d161_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d161_3:;
goto L_d164;
}
L_d164:{ // MOV EAX,dword ptr [EAX + 0x3ba8]
c.pc=0xd164;if(!sl_tick(c))return int(c.fault);
P_d164_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x3ba8ULL)),c);
P_d164_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d164_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d164_3:;
goto L_d16a;
}
L_d16a:{ // ADD dword ptr [EAX],0x400
c.pc=0xd16a;if(!sl_tick(c))return int(c.fault);
P_d16a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_d16a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)+SlU(0x400ULL))&sl_mask(32))<sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)),c);
P_d16a_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_d16a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)+SlU(0x400ULL)))&(SlU(0x400ULL)^(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)+SlU(0x400ULL)))&(SlU(1)<<31))!=0),c);
P_d16a_4:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_d16a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c) + SlU(0x400ULL)),c);
P_d16a_6:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_d16a_7:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_d16a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d16a_9:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_d16a_10:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c) == SlU(0x0ULL)),c);
P_d16a_11:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_d16a_12:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c) & SlU(0xffULL)),c);
P_d16a_13:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d16a_14:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d16a_15:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d16a_16:;
goto L_d170;
}
L_d170:{ // MOV EAX,dword ptr [ESI + 0x4]
c.pc=0xd170;if(!sl_tick(c))return int(c.fault);
P_d170_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x4ULL)),c);
P_d170_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d170_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d170_3:;
goto L_d173;
}
L_d173:{ // MOV EAX,dword ptr [EAX + 0x3ba8]
c.pc=0xd173;if(!sl_tick(c))return int(c.fault);
P_d173_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x3ba8ULL)),c);
P_d173_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d173_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d173_3:;
goto L_d179;
}
L_d179:{ // ADD dword ptr [EAX + 0x4],0x400
c.pc=0xd179;if(!sl_tick(c))return int(c.fault);
P_d179_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_d179_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d179_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)+SlU(0x400ULL))&sl_mask(32))<sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)),c);
P_d179_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d179_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)+SlU(0x400ULL)))&(SlU(0x400ULL)^(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c)+SlU(0x400ULL)))&(SlU(1)<<31))!=0),c);
P_d179_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d179_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c) + SlU(0x400ULL)),c);
P_d179_7:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_d179_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d179_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d179_10:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d179_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c) == SlU(0x0ULL)),c);
P_d179_12:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d179_13:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x5580,c) & SlU(0xffULL)),c);
P_d179_14:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d179_15:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d179_16:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d179_17:;
goto L_d180;
}
L_d180:{ // CMP EDI,0x100
c.pc=0xd180;if(!sl_tick(c))return int(c.fault);
P_d180_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30a80,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d180_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) < SlU(0x100ULL)),c);
P_d180_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^SlU(0x100ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)-SlU(0x100ULL)))&(SlU(1)<<31))!=0),c);
P_d180_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30b80,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) - SlU(0x100ULL)),c);
P_d180_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d180_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) == SlU(0x0ULL)),c);
P_d180_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) & SlU(0xffULL)),c);
P_d180_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d180_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d180_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d180_10:;
goto L_d186;
}
L_d186:{ // JG 0x0000d137
c.pc=0xd186;if(!sl_tick(c))return int(c.fault);
P_d186_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d186_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d186_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_d186_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_d137;}
P_d186_4:;
goto L_d188;
}
L_d188:{ // JMP 0x0000d10a
c.pc=0xd188;if(!sl_tick(c))return int(c.fault);
P_d188_0:;
goto L_d10a;
P_d188_1:;
goto L_d18a;
}
L_d18a:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0xd18a;if(!sl_tick(c))return int(c.fault);
P_d18a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_d18a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d18a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d18a_3:;
goto L_d18d;
}
L_d18d:{ // MOV dword ptr [ESP],EAX
c.pc=0xd18d;if(!sl_tick(c))return int(c.fault);
P_d18d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d18d_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d18d_2:;
goto L_d190;
}
L_d190:{ // CALL 0x0002de1a
c.pc=0xd190;if(!sl_tick(c))return int(c.fault);
P_d190_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d190_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd195ULL),c);
P_d190_2:;
c.pc=0x2de1a;goto dispatch;
P_d190_3:;
goto L_d195;
}
L_d195:{ // MOV EDX,dword ptr [EBP + -0x14]
c.pc=0xd195;if(!sl_tick(c))return int(c.fault);
P_d195_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_d195_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d195_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d195_3:;
goto L_d198;
}
L_d198:{ // MOV dword ptr [EBP + 0x8],EDX
c.pc=0xd198;if(!sl_tick(c))return int(c.fault);
P_d198_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_d198_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d198_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d198_3:;
goto L_d19b;
}
L_d19b:{ // ADD ESP,0x20
c.pc=0xd19b;if(!sl_tick(c))return int(c.fault);
P_d19b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d19b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(0x20ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_d19b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x20ULL)),c);
P_d19b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d19b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d19b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d19b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d19b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d19b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d19b_9:;
goto L_d19e;
}
L_d19e:{ // POP ESI
c.pc=0xd19e;if(!sl_tick(c))return int(c.fault);
P_d19e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d19e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d19e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d19e_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d19e_4:;
goto L_d19f;
}
L_d19f:{ // POP EDI
c.pc=0xd19f;if(!sl_tick(c))return int(c.fault);
P_d19f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d19f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d19f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d19f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d19f_4:;
goto L_d1a0;
}
L_d1a0:{ // POP EBP
c.pc=0xd1a0;if(!sl_tick(c))return int(c.fault);
P_d1a0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d1a0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d1a0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d1a0_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d1a0_4:;
goto L_d1a1;
}
L_d1a1:{ // JMP 0x0002de1a
c.pc=0xd1a1;if(!sl_tick(c))return int(c.fault);
P_d1a1_0:;
c.pc=0x2de1a;goto dispatch;
P_d1a1_1:;
goto L_d1a6;
}
L_d1a6:{ // PUSH EBP
c.pc=0xd1a6;if(!sl_tick(c))return int(c.fault);
P_d1a6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_d1a6_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d1a6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d1a6_3:;
goto L_d1a7;
}
L_d1a7:{ // MOV EBP,ESP
c.pc=0xd1a7;if(!sl_tick(c))return int(c.fault);
P_d1a7_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_d1a7_1:;
goto L_d1a9;
}
L_d1a9:{ // PUSH EDI
c.pc=0xd1a9;if(!sl_tick(c))return int(c.fault);
P_d1a9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d1a9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d1a9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d1a9_3:;
goto L_d1aa;
}
L_d1aa:{ // PUSH ESI
c.pc=0xd1aa;if(!sl_tick(c))return int(c.fault);
P_d1aa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d1aa_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d1aa_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d1aa_3:;
goto L_d1ab;
}
L_d1ab:{ // SUB ESP,0x30
c.pc=0xd1ab;if(!sl_tick(c))return int(c.fault);
P_d1ab_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x30ULL)),c);
P_d1ab_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x30ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x30ULL)))&(SlU(1)<<31))!=0),c);
P_d1ab_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x30ULL)),c);
P_d1ab_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d1ab_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d1ab_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d1ab_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d1ab_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d1ab_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d1ab_9:;
goto L_d1ae;
}
L_d1ae:{ // MOV EDI,dword ptr [EBP + 0x8]
c.pc=0xd1ae;if(!sl_tick(c))return int(c.fault);
P_d1ae_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_d1ae_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d1ae_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d1ae_3:;
goto L_d1b1;
}
L_d1b1:{ // MOV EAX,dword ptr [EDI + 0x4]
c.pc=0xd1b1;if(!sl_tick(c))return int(c.fault);
P_d1b1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x4ULL)),c);
P_d1b1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d1b1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d1b1_3:;
goto L_d1b4;
}
L_d1b4:{ // TEST EAX,EAX
c.pc=0xd1b4;if(!sl_tick(c))return int(c.fault);
P_d1b4_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d1b4_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d1b4_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d1b4_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d1b4_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_d1b4_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_d1b4_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d1b4_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d1b4_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d1b4_9:;
goto L_d1b6;
}
L_d1b6:{ // JZ 0x0000d363
c.pc=0xd1b6;if(!sl_tick(c))return int(c.fault);
P_d1b6_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_d363;}
P_d1b6_1:;
goto L_d1bc;
}
L_d1bc:{ // MOV EAX,dword ptr [EDI]
c.pc=0xd1bc;if(!sl_tick(c))return int(c.fault);
P_d1bc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_d1bc_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d1bc_2:;
goto L_d1be;
}
L_d1be:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xd1be;if(!sl_tick(c))return int(c.fault);
P_d1be_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d1be_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d1be_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d1be_3:;
goto L_d1c1;
}
L_d1c1:{ // MOV dword ptr [ESP + 0x4],EDX
c.pc=0xd1c1;if(!sl_tick(c))return int(c.fault);
P_d1c1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d1c1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d1c1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d1c1_3:;
goto L_d1c5;
}
L_d1c5:{ // MOV dword ptr [ESP],EDI
c.pc=0xd1c5;if(!sl_tick(c))return int(c.fault);
P_d1c5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d1c5_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d1c5_2:;
goto L_d1c8;
}
L_d1c8:{ // CALL dword ptr [EAX + 0x68]
c.pc=0xd1c8;if(!sl_tick(c))return int(c.fault);
P_d1c8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x68ULL)),c);
P_d1c8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d1c8_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d1c8_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d1c8_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd1cbULL),c);
P_d1c8_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d1c8_6:;
goto L_d1cb;
}
L_d1cb:{ // CMP byte ptr [EDI + 0x151],0x0
c.pc=0xd1cb;if(!sl_tick(c))return int(c.fault);
P_d1cb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x151ULL)),c);
P_d1cb_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d1cb_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d1cb_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d1cb_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d1cb_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d1cb_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d1cb_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d1cb_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d1cb_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d1cb_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d1cb_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d1cb_12:;
goto L_d1d2;
}
L_d1d2:{ // JNZ 0x0000d384
c.pc=0xd1d2;if(!sl_tick(c))return int(c.fault);
P_d1d2_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d1d2_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_d384;}
P_d1d2_2:;
goto L_d1d8;
}
L_d1d8:{ // CMP byte ptr [EDI + 0x150],0x0
c.pc=0xd1d8;if(!sl_tick(c))return int(c.fault);
P_d1d8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x150ULL)),c);
P_d1d8_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d1d8_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d1d8_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d1d8_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d1d8_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d1d8_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d1d8_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d1d8_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d1d8_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d1d8_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d1d8_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d1d8_12:;
goto L_d1df;
}
L_d1df:{ // JZ 0x0000d3cf
c.pc=0xd1df;if(!sl_tick(c))return int(c.fault);
P_d1df_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_d3cf;}
P_d1df_1:;
goto L_d1e5;
}
L_d1e5:{ // MOV ECX,dword ptr [EDI + 0x4]
c.pc=0xd1e5;if(!sl_tick(c))return int(c.fault);
P_d1e5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x4ULL)),c);
P_d1e5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d1e5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d1e5_3:;
goto L_d1e8;
}
L_d1e8:{ // MOV ESI,dword ptr [ECX + 0x3b90]
c.pc=0xd1e8;if(!sl_tick(c))return int(c.fault);
P_d1e8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x3b90ULL)),c);
P_d1e8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d1e8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d1e8_3:;
goto L_d1ee;
}
L_d1ee:{ // TEST ESI,ESI
c.pc=0xd1ee;if(!sl_tick(c))return int(c.fault);
P_d1ee_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d1ee_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d1ee_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d1ee_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d1ee_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_d1ee_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_d1ee_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d1ee_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d1ee_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d1ee_9:;
goto L_d1f0;
}
L_d1f0:{ // JLE 0x0000d22b
c.pc=0xd1f0;if(!sl_tick(c))return int(c.fault);
P_d1f0_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d1f0_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_d1f0_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_d22b;}
P_d1f0_3:;
goto L_d1f2;
}
L_d1f2:{ // XOR ESI,ESI
c.pc=0xd1f2;if(!sl_tick(c))return int(c.fault);
P_d1f2_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d1f2_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d1f2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d1f2_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d1f2_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_d1f2_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_d1f2_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d1f2_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d1f2_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d1f2_9:;
goto L_d1f4;
}
L_d1f4:{ // JMP 0x0000d201
c.pc=0xd1f4;if(!sl_tick(c))return int(c.fault);
P_d1f4_0:;
goto L_d201;
P_d1f4_1:;
goto L_d1f6;
}
L_d1f6:{ // ADD ESI,0x1
c.pc=0xd1f6;if(!sl_tick(c))return int(c.fault);
P_d1f6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d1f6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_d1f6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ULL)),c);
P_d1f6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d1f6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_d1f6_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_d1f6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d1f6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d1f6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d1f6_9:;
goto L_d1f9;
}
L_d1f9:{ // CMP dword ptr [ECX + 0x3b90],ESI
c.pc=0xd1f9;if(!sl_tick(c))return int(c.fault);
P_d1f9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x3b90ULL)),c);
P_d1f9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d1f9_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d1f9_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d1f9_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x18,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x18,c)))&(SlU(1)<<31))!=0),c);
P_d1f9_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d1f9_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d1f9_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_d1f9_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_d1f9_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d1f9_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d1f9_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d1f9_12:;
goto L_d1ff;
}
L_d1ff:{ // JLE 0x0000d22b
c.pc=0xd1ff;if(!sl_tick(c))return int(c.fault);
P_d1ff_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d1ff_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_d1ff_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_d22b;}
P_d1ff_3:;
goto L_d201;
}
L_d201:{ // MOV EDX,dword ptr [ECX + ESI*0x4 + 0x7798]
c.pc=0xd201;if(!sl_tick(c))return int(c.fault);
P_d201_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x7798ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_d201_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) * SlU(0x4ULL)),c);
P_d201_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_d201_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c)),c),c);
P_d201_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d201_5:;
goto L_d208;
}
L_d208:{ // CMP byte ptr [EDX + 0x9],0x0
c.pc=0xd208;if(!sl_tick(c))return int(c.fault);
P_d208_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x9ULL)),c);
P_d208_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d208_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d208_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d208_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d208_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d208_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d208_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d208_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d208_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d208_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d208_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d208_12:;
goto L_d20c;
}
L_d20c:{ // JZ 0x0000d1f6
c.pc=0xd20c;if(!sl_tick(c))return int(c.fault);
P_d20c_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_d1f6;}
P_d20c_1:;
goto L_d20e;
}
L_d20e:{ // MOV EAX,dword ptr [EDX]
c.pc=0xd20e;if(!sl_tick(c))return int(c.fault);
P_d20e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_d20e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d20e_2:;
goto L_d210;
}
L_d210:{ // MOV ECX,dword ptr [EBP + 0x10]
c.pc=0xd210;if(!sl_tick(c))return int(c.fault);
P_d210_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d210_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d210_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d210_3:;
goto L_d213;
}
L_d213:{ // MOV dword ptr [ESP + 0x4],ECX
c.pc=0xd213;if(!sl_tick(c))return int(c.fault);
P_d213_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d213_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_d213_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d213_3:;
goto L_d217;
}
L_d217:{ // MOV dword ptr [ESP],EDX
c.pc=0xd217;if(!sl_tick(c))return int(c.fault);
P_d217_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d217_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d217_2:;
goto L_d21a;
}
L_d21a:{ // CALL dword ptr [EAX + 0x14]
c.pc=0xd21a;if(!sl_tick(c))return int(c.fault);
P_d21a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x14ULL)),c);
P_d21a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d21a_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d21a_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d21a_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd21dULL),c);
P_d21a_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d21a_6:;
goto L_d21d;
}
L_d21d:{ // MOV ECX,dword ptr [EDI + 0x4]
c.pc=0xd21d;if(!sl_tick(c))return int(c.fault);
P_d21d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x4ULL)),c);
P_d21d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d21d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d21d_3:;
goto L_d220;
}
L_d220:{ // ADD ESI,0x1
c.pc=0xd220;if(!sl_tick(c))return int(c.fault);
P_d220_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d220_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_d220_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ULL)),c);
P_d220_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d220_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_d220_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_d220_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d220_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d220_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d220_9:;
goto L_d223;
}
L_d223:{ // CMP dword ptr [ECX + 0x3b90],ESI
c.pc=0xd223;if(!sl_tick(c))return int(c.fault);
P_d223_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x3b90ULL)),c);
P_d223_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d223_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d223_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d223_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x18,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x18,c)))&(SlU(1)<<31))!=0),c);
P_d223_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d223_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d223_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_d223_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_d223_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d223_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d223_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d223_12:;
goto L_d229;
}
L_d229:{ // JG 0x0000d201
c.pc=0xd229;if(!sl_tick(c))return int(c.fault);
P_d229_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d229_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d229_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_d229_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_d201;}
P_d229_4:;
goto L_d22b;
}
L_d22b:{ // LEA EAX,[EBP + -0xc]
c.pc=0xd22b;if(!sl_tick(c))return int(c.fault);
P_d22b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_d22b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_d22b_2:;
goto L_d22e;
}
L_d22e:{ // MOV dword ptr [EBP + -0x1c],EAX
c.pc=0xd22e;if(!sl_tick(c))return int(c.fault);
P_d22e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_d22e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d22e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d22e_3:;
goto L_d231;
}
L_d231:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0xd231;if(!sl_tick(c))return int(c.fault);
P_d231_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d231_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d231_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d231_3:;
goto L_d235;
}
L_d235:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0xd235;if(!sl_tick(c))return int(c.fault);
P_d235_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_d235_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d235_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d235_3:;
goto L_d23b;
}
L_d23b:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xd23b;if(!sl_tick(c))return int(c.fault);
P_d23b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d23b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d23b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d23b_3:;
goto L_d23f;
}
L_d23f:{ // LEA EAX,[ECX + 0x38cc]
c.pc=0xd23f;if(!sl_tick(c))return int(c.fault);
P_d23f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x38ccULL)),c);
P_d23f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_d23f_2:;
goto L_d245;
}
L_d245:{ // MOV dword ptr [ESP],EAX
c.pc=0xd245;if(!sl_tick(c))return int(c.fault);
P_d245_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d245_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d245_2:;
goto L_d248;
}
L_d248:{ // CALL 0x0002f3da
c.pc=0xd248;if(!sl_tick(c))return int(c.fault);
P_d248_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d248_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd24dULL),c);
P_d248_2:;
c.pc=0x2f3da;goto dispatch;
P_d248_3:;
goto L_d24d;
}
L_d24d:{ // MOV dword ptr [EDI + 0xec8],EAX
c.pc=0xd24d;if(!sl_tick(c))return int(c.fault);
P_d24d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xec8ULL)),c);
P_d24d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d24d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d24d_3:;
goto L_d253;
}
L_d253:{ // TEST EAX,EAX
c.pc=0xd253;if(!sl_tick(c))return int(c.fault);
P_d253_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d253_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d253_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d253_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d253_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_d253_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_d253_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d253_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d253_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d253_9:;
goto L_d255;
}
L_d255:{ // JS 0x0000d301
c.pc=0xd255;if(!sl_tick(c))return int(c.fault);
P_d255_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x207,c)){goto L_d301;}
P_d255_1:;
goto L_d25b;
}
L_d25b:{ // MOV ECX,dword ptr [EDI + 0x4]
c.pc=0xd25b;if(!sl_tick(c))return int(c.fault);
P_d25b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x4ULL)),c);
P_d25b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d25b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d25b_3:;
goto L_d25e;
}
L_d25e:{ // MOV EAX,dword ptr [ECX + 0x3b90]
c.pc=0xd25e;if(!sl_tick(c))return int(c.fault);
P_d25e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x3b90ULL)),c);
P_d25e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d25e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d25e_3:;
goto L_d264;
}
L_d264:{ // TEST EAX,EAX
c.pc=0xd264;if(!sl_tick(c))return int(c.fault);
P_d264_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d264_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d264_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d264_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d264_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_d264_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_d264_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d264_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d264_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d264_9:;
goto L_d266;
}
L_d266:{ // JLE 0x0000d2a1
c.pc=0xd266;if(!sl_tick(c))return int(c.fault);
P_d266_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d266_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_d266_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_d2a1;}
P_d266_3:;
goto L_d268;
}
L_d268:{ // XOR ESI,ESI
c.pc=0xd268;if(!sl_tick(c))return int(c.fault);
P_d268_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d268_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d268_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d268_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d268_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_d268_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_d268_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d268_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d268_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d268_9:;
goto L_d26a;
}
L_d26a:{ // JMP 0x0000d277
c.pc=0xd26a;if(!sl_tick(c))return int(c.fault);
P_d26a_0:;
goto L_d277;
P_d26a_1:;
goto L_d26c;
}
L_d26c:{ // ADD ESI,0x1
c.pc=0xd26c;if(!sl_tick(c))return int(c.fault);
P_d26c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d26c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_d26c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ULL)),c);
P_d26c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d26c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_d26c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_d26c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d26c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d26c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d26c_9:;
goto L_d26f;
}
L_d26f:{ // CMP ESI,dword ptr [ECX + 0x3b90]
c.pc=0xd26f;if(!sl_tick(c))return int(c.fault);
P_d26f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x3b90ULL)),c);
P_d26f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d26f_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d26f_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_d26f_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_d26f_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_d26f_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d26f_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_d26f_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_d26f_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d26f_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d26f_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d26f_12:;
goto L_d275;
}
L_d275:{ // JGE 0x0000d2a1
c.pc=0xd275;if(!sl_tick(c))return int(c.fault);
P_d275_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa280,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d275_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa280,c)){goto L_d2a1;}
P_d275_2:;
goto L_d277;
}
L_d277:{ // MOV EDX,dword ptr [ECX + ESI*0x4 + 0x7798]
c.pc=0xd277;if(!sl_tick(c))return int(c.fault);
P_d277_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x7798ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_d277_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) * SlU(0x4ULL)),c);
P_d277_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_d277_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c)),c),c);
P_d277_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d277_5:;
goto L_d27e;
}
L_d27e:{ // CMP byte ptr [EDX + 0x8],0x0
c.pc=0xd27e;if(!sl_tick(c))return int(c.fault);
P_d27e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x8ULL)),c);
P_d27e_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d27e_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d27e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d27e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d27e_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d27e_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d27e_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d27e_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d27e_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d27e_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d27e_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d27e_12:;
goto L_d282;
}
L_d282:{ // JZ 0x0000d26c
c.pc=0xd282;if(!sl_tick(c))return int(c.fault);
P_d282_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_d26c;}
P_d282_1:;
goto L_d284;
}
L_d284:{ // MOV EAX,dword ptr [EDX]
c.pc=0xd284;if(!sl_tick(c))return int(c.fault);
P_d284_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_d284_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d284_2:;
goto L_d286;
}
L_d286:{ // MOV ECX,dword ptr [EBP + 0x10]
c.pc=0xd286;if(!sl_tick(c))return int(c.fault);
P_d286_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d286_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d286_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d286_3:;
goto L_d289;
}
L_d289:{ // MOV dword ptr [ESP + 0x4],ECX
c.pc=0xd289;if(!sl_tick(c))return int(c.fault);
P_d289_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d289_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_d289_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d289_3:;
goto L_d28d;
}
L_d28d:{ // MOV dword ptr [ESP],EDX
c.pc=0xd28d;if(!sl_tick(c))return int(c.fault);
P_d28d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d28d_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d28d_2:;
goto L_d290;
}
L_d290:{ // CALL dword ptr [EAX + 0x14]
c.pc=0xd290;if(!sl_tick(c))return int(c.fault);
P_d290_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x14ULL)),c);
P_d290_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d290_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d290_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d290_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd293ULL),c);
P_d290_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d290_6:;
goto L_d293;
}
L_d293:{ // MOV ECX,dword ptr [EDI + 0x4]
c.pc=0xd293;if(!sl_tick(c))return int(c.fault);
P_d293_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x4ULL)),c);
P_d293_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d293_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d293_3:;
goto L_d296;
}
L_d296:{ // ADD ESI,0x1
c.pc=0xd296;if(!sl_tick(c))return int(c.fault);
P_d296_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d296_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_d296_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ULL)),c);
P_d296_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d296_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_d296_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_d296_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d296_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d296_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d296_9:;
goto L_d299;
}
L_d299:{ // CMP ESI,dword ptr [ECX + 0x3b90]
c.pc=0xd299;if(!sl_tick(c))return int(c.fault);
P_d299_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x3b90ULL)),c);
P_d299_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d299_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d299_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_d299_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_d299_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_d299_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d299_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_d299_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_d299_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d299_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d299_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d299_12:;
goto L_d29f;
}
L_d29f:{ // JL 0x0000d277
c.pc=0xd29f;if(!sl_tick(c))return int(c.fault);
P_d29f_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa180,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d29f_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa180,c)){goto L_d277;}
P_d29f_2:;
goto L_d2a1;
}
L_d2a1:{ // MOV EAX,dword ptr [EDI]
c.pc=0xd2a1;if(!sl_tick(c))return int(c.fault);
P_d2a1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_d2a1_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d2a1_2:;
goto L_d2a3;
}
L_d2a3:{ // MOV dword ptr [ESP],EDI
c.pc=0xd2a3;if(!sl_tick(c))return int(c.fault);
P_d2a3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d2a3_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d2a3_2:;
goto L_d2a6;
}
L_d2a6:{ // CALL dword ptr [EAX + 0x6c]
c.pc=0xd2a6;if(!sl_tick(c))return int(c.fault);
P_d2a6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x6cULL)),c);
P_d2a6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d2a6_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d2a6_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d2a6_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd2a9ULL),c);
P_d2a6_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d2a6_6:;
goto L_d2a9;
}
L_d2a9:{ // MOV EAX,dword ptr [EDI + 0x4]
c.pc=0xd2a9;if(!sl_tick(c))return int(c.fault);
P_d2a9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x4ULL)),c);
P_d2a9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d2a9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d2a9_3:;
goto L_d2ac;
}
L_d2ac:{ // MOV EDX,dword ptr [EDI + 0xec8]
c.pc=0xd2ac;if(!sl_tick(c))return int(c.fault);
P_d2ac_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xec8ULL)),c);
P_d2ac_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d2ac_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d2ac_3:;
goto L_d2b2;
}
L_d2b2:{ // MOV EAX,dword ptr [EAX + 0x3b0c]
c.pc=0xd2b2;if(!sl_tick(c))return int(c.fault);
P_d2b2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x3b0cULL)),c);
P_d2b2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d2b2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d2b2_3:;
goto L_d2b8;
}
L_d2b8:{ // MOV EAX,dword ptr [EAX + EDX*0x4]
c.pc=0xd2b8;if(!sl_tick(c))return int(c.fault);
P_d2b8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x4ULL)),c);
P_d2b8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_d2b8_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),c),c);
P_d2b8_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d2b8_4:;
goto L_d2bb;
}
L_d2bb:{ // MOV EDX,dword ptr [EAX]
c.pc=0xd2bb;if(!sl_tick(c))return int(c.fault);
P_d2bb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_d2bb_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d2bb_2:;
goto L_d2bd;
}
L_d2bd:{ // MOV ECX,dword ptr [EBP + 0x10]
c.pc=0xd2bd;if(!sl_tick(c))return int(c.fault);
P_d2bd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d2bd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d2bd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d2bd_3:;
goto L_d2c0;
}
L_d2c0:{ // MOV dword ptr [ESP + 0x4],ECX
c.pc=0xd2c0;if(!sl_tick(c))return int(c.fault);
P_d2c0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d2c0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_d2c0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d2c0_3:;
goto L_d2c4;
}
L_d2c4:{ // MOV dword ptr [ESP],EAX
c.pc=0xd2c4;if(!sl_tick(c))return int(c.fault);
P_d2c4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d2c4_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d2c4_2:;
goto L_d2c7;
}
L_d2c7:{ // CALL dword ptr [EDX + 0x30]
c.pc=0xd2c7;if(!sl_tick(c))return int(c.fault);
P_d2c7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x30ULL)),c);
P_d2c7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d2c7_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d2c7_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d2c7_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd2caULL),c);
P_d2c7_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d2c7_6:;
goto L_d2ca;
}
L_d2ca:{ // TEST AL,AL
c.pc=0xd2ca;if(!sl_tick(c))return int(c.fault);
P_d2ca_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d2ca_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d2ca_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x54d80,(sl_get<1>(c.reg,sizeof(c.reg),0x0,c) & sl_get<1>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d2ca_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d2ca_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c) == SlU(0x0ULL)),c);
P_d2ca_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c) & SlU(0xffULL)),c);
P_d2ca_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d2ca_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d2ca_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d2ca_9:;
goto L_d2cc;
}
L_d2cc:{ // JNZ 0x0000d36a
c.pc=0xd2cc;if(!sl_tick(c))return int(c.fault);
P_d2cc_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d2cc_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_d36a;}
P_d2cc_2:;
goto L_d2d2;
}
L_d2d2:{ // MOV EAX,dword ptr [EBP + -0x1c]
c.pc=0xd2d2;if(!sl_tick(c))return int(c.fault);
P_d2d2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_d2d2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d2d2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d2d2_3:;
goto L_d2d5;
}
L_d2d5:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0xd2d5;if(!sl_tick(c))return int(c.fault);
P_d2d5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d2d5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d2d5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d2d5_3:;
goto L_d2d9;
}
L_d2d9:{ // MOV EAX,dword ptr [EDI + 0x1a4]
c.pc=0xd2d9;if(!sl_tick(c))return int(c.fault);
P_d2d9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1a4ULL)),c);
P_d2d9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d2d9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d2d9_3:;
goto L_d2df;
}
L_d2df:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xd2df;if(!sl_tick(c))return int(c.fault);
P_d2df_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d2df_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d2df_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d2df_3:;
goto L_d2e3;
}
L_d2e3:{ // MOV EAX,dword ptr [EDI + 0x4]
c.pc=0xd2e3;if(!sl_tick(c))return int(c.fault);
P_d2e3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x4ULL)),c);
P_d2e3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d2e3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d2e3_3:;
goto L_d2e6;
}
L_d2e6:{ // ADD EAX,0x38cc
c.pc=0xd2e6;if(!sl_tick(c))return int(c.fault);
P_d2e6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x38ccULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d2e6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x38ccULL)))&(SlU(0x38ccULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x38ccULL)))&(SlU(1)<<31))!=0),c);
P_d2e6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x38ccULL)),c);
P_d2e6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d2e6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_d2e6_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_d2e6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d2e6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d2e6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d2e6_9:;
goto L_d2eb;
}
L_d2eb:{ // MOV dword ptr [ESP],EAX
c.pc=0xd2eb;if(!sl_tick(c))return int(c.fault);
P_d2eb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d2eb_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d2eb_2:;
goto L_d2ee;
}
L_d2ee:{ // CALL 0x0002ecd6
c.pc=0xd2ee;if(!sl_tick(c))return int(c.fault);
P_d2ee_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d2ee_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd2f3ULL),c);
P_d2ee_2:;
c.pc=0x2ecd6;goto dispatch;
P_d2ee_3:;
goto L_d2f3;
}
L_d2f3:{ // MOV dword ptr [EDI + 0xec8],EAX
c.pc=0xd2f3;if(!sl_tick(c))return int(c.fault);
P_d2f3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xec8ULL)),c);
P_d2f3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d2f3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d2f3_3:;
goto L_d2f9;
}
L_d2f9:{ // TEST EAX,EAX
c.pc=0xd2f9;if(!sl_tick(c))return int(c.fault);
P_d2f9_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d2f9_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d2f9_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d2f9_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d2f9_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_d2f9_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_d2f9_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d2f9_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d2f9_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d2f9_9:;
goto L_d2fb;
}
L_d2fb:{ // JNS 0x0000d25b
c.pc=0xd2fb;if(!sl_tick(c))return int(c.fault);
P_d2fb_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9f80,(!sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d2fb_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9f80,c)){goto L_d25b;}
P_d2fb_2:;
goto L_d301;
}
L_d301:{ // MOV EAX,dword ptr [EDI]
c.pc=0xd301;if(!sl_tick(c))return int(c.fault);
P_d301_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_d301_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d301_2:;
goto L_d303;
}
L_d303:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xd303;if(!sl_tick(c))return int(c.fault);
P_d303_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d303_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d303_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d303_3:;
goto L_d306;
}
L_d306:{ // MOV dword ptr [ESP + 0x8],EDX
c.pc=0xd306;if(!sl_tick(c))return int(c.fault);
P_d306_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d306_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d306_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d306_3:;
goto L_d30a;
}
L_d30a:{ // MOV ECX,dword ptr [EBP + 0xc]
c.pc=0xd30a;if(!sl_tick(c))return int(c.fault);
P_d30a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_d30a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d30a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d30a_3:;
goto L_d30d;
}
L_d30d:{ // MOV dword ptr [ESP + 0x4],ECX
c.pc=0xd30d;if(!sl_tick(c))return int(c.fault);
P_d30d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d30d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_d30d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d30d_3:;
goto L_d311;
}
L_d311:{ // MOV dword ptr [ESP],EDI
c.pc=0xd311;if(!sl_tick(c))return int(c.fault);
P_d311_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d311_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d311_2:;
goto L_d314;
}
L_d314:{ // CALL dword ptr [EAX + 0x3c]
c.pc=0xd314;if(!sl_tick(c))return int(c.fault);
P_d314_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x3cULL)),c);
P_d314_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d314_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d314_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d314_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd317ULL),c);
P_d314_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d314_6:;
goto L_d317;
}
L_d317:{ // MOV EAX,dword ptr [EDI]
c.pc=0xd317;if(!sl_tick(c))return int(c.fault);
P_d317_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_d317_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d317_2:;
goto L_d319;
}
L_d319:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xd319;if(!sl_tick(c))return int(c.fault);
P_d319_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d319_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d319_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d319_3:;
goto L_d31c;
}
L_d31c:{ // MOV dword ptr [ESP + 0x4],EDX
c.pc=0xd31c;if(!sl_tick(c))return int(c.fault);
P_d31c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d31c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d31c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d31c_3:;
goto L_d320;
}
L_d320:{ // MOV dword ptr [ESP],EDI
c.pc=0xd320;if(!sl_tick(c))return int(c.fault);
P_d320_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d320_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d320_2:;
goto L_d323;
}
L_d323:{ // CALL dword ptr [EAX + 0x2c]
c.pc=0xd323;if(!sl_tick(c))return int(c.fault);
P_d323_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x2cULL)),c);
P_d323_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d323_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d323_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d323_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd326ULL),c);
P_d323_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d323_6:;
goto L_d326;
}
L_d326:{ // MOV EAX,dword ptr [EDI]
c.pc=0xd326;if(!sl_tick(c))return int(c.fault);
P_d326_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_d326_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d326_2:;
goto L_d328;
}
L_d328:{ // MOV ECX,dword ptr [EBP + 0x10]
c.pc=0xd328;if(!sl_tick(c))return int(c.fault);
P_d328_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d328_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d328_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d328_3:;
goto L_d32b;
}
L_d32b:{ // MOV dword ptr [ESP + 0x4],ECX
c.pc=0xd32b;if(!sl_tick(c))return int(c.fault);
P_d32b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d32b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_d32b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d32b_3:;
goto L_d32f;
}
L_d32f:{ // MOV dword ptr [ESP],EDI
c.pc=0xd32f;if(!sl_tick(c))return int(c.fault);
P_d32f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d32f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d32f_2:;
goto L_d332;
}
L_d332:{ // CALL dword ptr [EAX + 0x74]
c.pc=0xd332;if(!sl_tick(c))return int(c.fault);
P_d332_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x74ULL)),c);
P_d332_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d332_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d332_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d332_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd335ULL),c);
P_d332_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d332_6:;
goto L_d335;
}
L_d335:{ // MOV EAX,dword ptr [EDI + 0x1b0]
c.pc=0xd335;if(!sl_tick(c))return int(c.fault);
P_d335_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1b0ULL)),c);
P_d335_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d335_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d335_3:;
goto L_d33b;
}
L_d33b:{ // TEST EAX,EAX
c.pc=0xd33b;if(!sl_tick(c))return int(c.fault);
P_d33b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d33b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d33b_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d33b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d33b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_d33b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_d33b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d33b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d33b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d33b_9:;
goto L_d33d;
}
L_d33d:{ // JLE 0x0000d363
c.pc=0xd33d;if(!sl_tick(c))return int(c.fault);
P_d33d_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d33d_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_d33d_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_d363;}
P_d33d_3:;
goto L_d33f;
}
L_d33f:{ // MOV ESI,dword ptr [EBP + 0x10]
c.pc=0xd33f;if(!sl_tick(c))return int(c.fault);
P_d33f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d33f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d33f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d33f_3:;
goto L_d342;
}
L_d342:{ // SHL ESI,0x2
c.pc=0xd342;if(!sl_tick(c))return int(c.fault);
P_d342_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x50e00,(SlU(0x2ULL) & SlU(0x1fULL)),c);
P_d342_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x50e80,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d342_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_lshift(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c)),c);
P_d342_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x24d00,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) != SlU(0x0ULL)),c);
P_d342_4:;
sl_put<4>(c.temp,sizeof(c.temp),0x24d80,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) - SlU(0x1ULL)),c);
P_d342_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x24e00,sl_lshift(sl_get<4>(c.temp,sizeof(c.temp),0x50e80,c),sl_get<4>(c.temp,sizeof(c.temp),0x24d80,c)),c);
P_d342_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x24f00,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x24e00,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d342_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x24f80,(!sl_get<1>(c.temp,sizeof(c.temp),0x24d00,c)),c);
P_d342_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x25000,(sl_get<1>(c.temp,sizeof(c.temp),0x24f80,c) & sl_get<1>(c.reg,sizeof(c.reg),0x200,c)),c);
P_d342_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x25080,(sl_get<1>(c.temp,sizeof(c.temp),0x24d00,c) & sl_get<1>(c.temp,sizeof(c.temp),0x24f00,c)),c);
P_d342_10:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x25000,c) | sl_get<1>(c.temp,sizeof(c.temp),0x25080,c)),c);
P_d342_11:;
sl_put<1>(c.temp,sizeof(c.temp),0x25200,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) == SlU(0x1ULL)),c);
P_d342_12:;
sl_put<1>(c.temp,sizeof(c.temp),0x25280,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d342_13:;
sl_put<1>(c.temp,sizeof(c.temp),0x25380,(sl_get<1>(c.reg,sizeof(c.reg),0x200,c) ^ sl_get<1>(c.temp,sizeof(c.temp),0x25280,c)),c);
P_d342_14:;
sl_put<1>(c.temp,sizeof(c.temp),0x25400,(!sl_get<1>(c.temp,sizeof(c.temp),0x25200,c)),c);
P_d342_15:;
sl_put<1>(c.temp,sizeof(c.temp),0x25480,(sl_get<1>(c.temp,sizeof(c.temp),0x25400,c) & sl_get<1>(c.reg,sizeof(c.reg),0x20b,c)),c);
P_d342_16:;
sl_put<1>(c.temp,sizeof(c.temp),0x25500,(sl_get<1>(c.temp,sizeof(c.temp),0x25200,c) & sl_get<1>(c.temp,sizeof(c.temp),0x25380,c)),c);
P_d342_17:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(sl_get<1>(c.temp,sizeof(c.temp),0x25480,c) | sl_get<1>(c.temp,sizeof(c.temp),0x25500,c)),c);
P_d342_18:;
sl_put<1>(c.temp,sizeof(c.temp),0x22b80,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) != SlU(0x0ULL)),c);
P_d342_19:;
sl_put<1>(c.temp,sizeof(c.temp),0x22c80,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d342_20:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d00,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d342_21:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d80,(sl_get<1>(c.temp,sizeof(c.temp),0x22d00,c) & sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d342_22:;
sl_put<1>(c.temp,sizeof(c.temp),0x22e00,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22c80,c)),c);
P_d342_23:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_get<1>(c.temp,sizeof(c.temp),0x22d80,c) | sl_get<1>(c.temp,sizeof(c.temp),0x22e00,c)),c);
P_d342_24:;
sl_put<1>(c.temp,sizeof(c.temp),0x22f80,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_d342_25:;
sl_put<1>(c.temp,sizeof(c.temp),0x23000,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d342_26:;
sl_put<1>(c.temp,sizeof(c.temp),0x23080,(sl_get<1>(c.temp,sizeof(c.temp),0x23000,c) & sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d342_27:;
sl_put<1>(c.temp,sizeof(c.temp),0x23100,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22f80,c)),c);
P_d342_28:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x23080,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23100,c)),c);
P_d342_29:;
sl_put<4>(c.temp,sizeof(c.temp),0x23200,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_d342_30:;
sl_put<1>(c.temp,sizeof(c.temp),0x23280,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x23200,c)),c);
P_d342_31:;
sl_put<1>(c.temp,sizeof(c.temp),0x23300,(sl_get<1>(c.temp,sizeof(c.temp),0x23280,c) & SlU(0x1ULL)),c);
P_d342_32:;
sl_put<1>(c.temp,sizeof(c.temp),0x23400,(sl_get<1>(c.temp,sizeof(c.temp),0x23300,c) == SlU(0x0ULL)),c);
P_d342_33:;
sl_put<1>(c.temp,sizeof(c.temp),0x23480,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d342_34:;
sl_put<1>(c.temp,sizeof(c.temp),0x23500,(sl_get<1>(c.temp,sizeof(c.temp),0x23480,c) & sl_get<1>(c.reg,sizeof(c.reg),0x202,c)),c);
P_d342_35:;
sl_put<1>(c.temp,sizeof(c.temp),0x23580,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x23400,c)),c);
P_d342_36:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x23500,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23580,c)),c);
P_d342_37:;
goto L_d345;
}
L_d345:{ // MOV ECX,0x1
c.pc=0xd345;if(!sl_tick(c))return int(c.fault);
P_d345_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,SlU(0x1ULL),c);
P_d345_1:;
goto L_d34a;
}
L_d34a:{ // MOV EDX,dword ptr [EBP + 0xc]
c.pc=0xd34a;if(!sl_tick(c))return int(c.fault);
P_d34a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_d34a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d34a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d34a_3:;
goto L_d34d;
}
L_d34d:{ // ADD EDX,0x4
c.pc=0xd34d;if(!sl_tick(c))return int(c.fault);
P_d34d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_d34d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x4ULL)))&(SlU(0x4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x4ULL)))&(SlU(1)<<31))!=0),c);
P_d34d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x4ULL)),c);
P_d34d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d34d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_d34d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_d34d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d34d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d34d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d34d_9:;
goto L_d350;
}
L_d350:{ // ADD dword ptr [EDX + -0x4],ESI
c.pc=0xd350;if(!sl_tick(c))return int(c.fault);
P_d350_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0xfffffffcULL)),c);
P_d350_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d350_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)+sl_get<4>(c.reg,sizeof(c.reg),0x18,c))&sl_mask(32))<sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)),c);
P_d350_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d350_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)+sl_get<4>(c.reg,sizeof(c.reg),0x18,c)))&(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)+sl_get<4>(c.reg,sizeof(c.reg),0x18,c)))&(SlU(1)<<31))!=0),c);
P_d350_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d350_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c) + sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d350_7:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d350_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d350_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d350_10:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d350_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c) == SlU(0x0ULL)),c);
P_d350_12:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d350_13:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c) & SlU(0xffULL)),c);
P_d350_14:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d350_15:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d350_16:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d350_17:;
goto L_d353;
}
L_d353:{ // MOV EAX,ECX
c.pc=0xd353;if(!sl_tick(c))return int(c.fault);
P_d353_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_d353_1:;
goto L_d355;
}
L_d355:{ // ADD ECX,0x1
c.pc=0xd355;if(!sl_tick(c))return int(c.fault);
P_d355_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x4,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_d355_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x4,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_d355_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x1ULL)),c);
P_d355_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x4,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d355_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) == SlU(0x0ULL)),c);
P_d355_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & SlU(0xffULL)),c);
P_d355_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d355_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d355_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d355_9:;
goto L_d358;
}
L_d358:{ // ADD EDX,0x4
c.pc=0xd358;if(!sl_tick(c))return int(c.fault);
P_d358_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_d358_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x4ULL)))&(SlU(0x4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x4ULL)))&(SlU(1)<<31))!=0),c);
P_d358_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x4ULL)),c);
P_d358_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d358_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_d358_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_d358_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d358_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d358_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d358_9:;
goto L_d35b;
}
L_d35b:{ // CMP EAX,dword ptr [EDI + 0x1b0]
c.pc=0xd35b;if(!sl_tick(c))return int(c.fault);
P_d35b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1b0ULL)),c);
P_d35b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d35b_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d35b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_d35b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_d35b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_d35b_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d35b_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_d35b_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_d35b_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d35b_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d35b_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d35b_12:;
goto L_d361;
}
L_d361:{ // JL 0x0000d350
c.pc=0xd361;if(!sl_tick(c))return int(c.fault);
P_d361_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa180,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d361_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa180,c)){goto L_d350;}
P_d361_2:;
goto L_d363;
}
L_d363:{ // ADD ESP,0x30
c.pc=0xd363;if(!sl_tick(c))return int(c.fault);
P_d363_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d363_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL)))&(SlU(0x30ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL)))&(SlU(1)<<31))!=0),c);
P_d363_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x30ULL)),c);
P_d363_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d363_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d363_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d363_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d363_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d363_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d363_9:;
goto L_d366;
}
L_d366:{ // POP ESI
c.pc=0xd366;if(!sl_tick(c))return int(c.fault);
P_d366_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d366_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d366_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d366_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d366_4:;
goto L_d367;
}
L_d367:{ // POP EDI
c.pc=0xd367;if(!sl_tick(c))return int(c.fault);
P_d367_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d367_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d367_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d367_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d367_4:;
goto L_d368;
}
L_d368:{ // POP EBP
c.pc=0xd368;if(!sl_tick(c))return int(c.fault);
P_d368_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d368_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d368_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d368_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d368_4:;
goto L_d369;
}
L_d369:{ // RET
c.pc=0xd369;if(!sl_tick(c))return int(c.fault);
P_d369_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d369_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d369_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_d369_3:;
goto L_d36a;
}
L_d36a:{ // MOV EAX,dword ptr [EDI + 0xec8]
c.pc=0xd36a;if(!sl_tick(c))return int(c.fault);
P_d36a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xec8ULL)),c);
P_d36a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d36a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d36a_3:;
goto L_d370;
}
L_d370:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xd370;if(!sl_tick(c))return int(c.fault);
P_d370_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d370_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d370_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d370_3:;
goto L_d374;
}
L_d374:{ // MOV EAX,dword ptr [EDI + 0x4]
c.pc=0xd374;if(!sl_tick(c))return int(c.fault);
P_d374_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x4ULL)),c);
P_d374_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d374_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d374_3:;
goto L_d377;
}
L_d377:{ // MOV dword ptr [ESP],EAX
c.pc=0xd377;if(!sl_tick(c))return int(c.fault);
P_d377_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d377_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d377_2:;
goto L_d37a;
}
L_d37a:{ // CALL 0x00018d78
c.pc=0xd37a;if(!sl_tick(c))return int(c.fault);
P_d37a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d37a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd37fULL),c);
P_d37a_2:;
c.pc=0x18d78;goto dispatch;
P_d37a_3:;
goto L_d37f;
}
L_d37f:{ // JMP 0x0000d2d2
c.pc=0xd37f;if(!sl_tick(c))return int(c.fault);
P_d37f_0:;
goto L_d2d2;
P_d37f_1:;
goto L_d384;
}
L_d384:{ // MOV ECX,dword ptr [EDI + 0x4]
c.pc=0xd384;if(!sl_tick(c))return int(c.fault);
P_d384_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x4ULL)),c);
P_d384_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d384_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d384_3:;
goto L_d387;
}
L_d387:{ // MOV EAX,dword ptr [ECX + 0x3b90]
c.pc=0xd387;if(!sl_tick(c))return int(c.fault);
P_d387_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x3b90ULL)),c);
P_d387_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d387_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d387_3:;
goto L_d38d;
}
L_d38d:{ // TEST EAX,EAX
c.pc=0xd38d;if(!sl_tick(c))return int(c.fault);
P_d38d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d38d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d38d_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d38d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d38d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_d38d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_d38d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d38d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d38d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d38d_9:;
goto L_d38f;
}
L_d38f:{ // JLE 0x0000d1d8
c.pc=0xd38f;if(!sl_tick(c))return int(c.fault);
P_d38f_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d38f_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_d38f_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_d1d8;}
P_d38f_3:;
goto L_d395;
}
L_d395:{ // XOR ESI,ESI
c.pc=0xd395;if(!sl_tick(c))return int(c.fault);
P_d395_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d395_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d395_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d395_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d395_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_d395_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_d395_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d395_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d395_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d395_9:;
goto L_d397;
}
L_d397:{ // JMP 0x0000d3a8
c.pc=0xd397;if(!sl_tick(c))return int(c.fault);
P_d397_0:;
goto L_d3a8;
P_d397_1:;
goto L_d399;
}
L_d399:{ // ADD ESI,0x1
c.pc=0xd399;if(!sl_tick(c))return int(c.fault);
P_d399_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_d399_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_d399_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ULL)),c);
P_d399_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d399_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_d399_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_d399_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d399_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d399_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d399_9:;
goto L_d39c;
}
L_d39c:{ // CMP ESI,dword ptr [ECX + 0x3b90]
c.pc=0xd39c;if(!sl_tick(c))return int(c.fault);
P_d39c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x3b90ULL)),c);
P_d39c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d39c_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d39c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_d39c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_d39c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_d39c_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d39c_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_d39c_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_d39c_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d39c_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d39c_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d39c_12:;
goto L_d3a2;
}
L_d3a2:{ // JGE 0x0000d1d8
c.pc=0xd3a2;if(!sl_tick(c))return int(c.fault);
P_d3a2_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa280,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d3a2_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa280,c)){goto L_d1d8;}
P_d3a2_2:;
goto L_d3a8;
}
L_d3a8:{ // MOV EDX,dword ptr [ECX + ESI*0x4 + 0x7798]
c.pc=0xd3a8;if(!sl_tick(c))return int(c.fault);
P_d3a8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x7798ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_d3a8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) * SlU(0x4ULL)),c);
P_d3a8_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_d3a8_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c)),c),c);
P_d3a8_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d3a8_5:;
goto L_d3af;
}
L_d3af:{ // CMP byte ptr [EDX + 0x9],0x0
c.pc=0xd3af;if(!sl_tick(c))return int(c.fault);
P_d3af_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x9ULL)),c);
P_d3af_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d3af_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d3af_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d3af_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d3af_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d3af_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d3af_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d3af_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d3af_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d3af_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d3af_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d3af_12:;
goto L_d3b3;
}
L_d3b3:{ // JNZ 0x0000d399
c.pc=0xd3b3;if(!sl_tick(c))return int(c.fault);
P_d3b3_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d3b3_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_d399;}
P_d3b3_2:;
goto L_d3b5;
}
L_d3b5:{ // CMP byte ptr [EDX + 0x8],0x0
c.pc=0xd3b5;if(!sl_tick(c))return int(c.fault);
P_d3b5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x8ULL)),c);
P_d3b5_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d3b5_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d3b5_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d3b5_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d3b5_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d3b5_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d3b5_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d3b5_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d3b5_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d3b5_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d3b5_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d3b5_12:;
goto L_d3b9;
}
L_d3b9:{ // JNZ 0x0000d399
c.pc=0xd3b9;if(!sl_tick(c))return int(c.fault);
P_d3b9_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d3b9_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_d399;}
P_d3b9_2:;
goto L_d3bb;
}
L_d3bb:{ // MOV EAX,dword ptr [EDX]
c.pc=0xd3bb;if(!sl_tick(c))return int(c.fault);
P_d3bb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_d3bb_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d3bb_2:;
goto L_d3bd;
}
L_d3bd:{ // MOV ECX,dword ptr [EBP + 0x10]
c.pc=0xd3bd;if(!sl_tick(c))return int(c.fault);
P_d3bd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d3bd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d3bd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d3bd_3:;
goto L_d3c0;
}
L_d3c0:{ // MOV dword ptr [ESP + 0x4],ECX
c.pc=0xd3c0;if(!sl_tick(c))return int(c.fault);
P_d3c0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d3c0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_d3c0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d3c0_3:;
goto L_d3c4;
}
L_d3c4:{ // MOV dword ptr [ESP],EDX
c.pc=0xd3c4;if(!sl_tick(c))return int(c.fault);
P_d3c4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d3c4_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d3c4_2:;
goto L_d3c7;
}
L_d3c7:{ // CALL dword ptr [EAX + 0x14]
c.pc=0xd3c7;if(!sl_tick(c))return int(c.fault);
P_d3c7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x14ULL)),c);
P_d3c7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d3c7_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d3c7_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d3c7_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd3caULL),c);
P_d3c7_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d3c7_6:;
goto L_d3ca;
}
L_d3ca:{ // MOV ECX,dword ptr [EDI + 0x4]
c.pc=0xd3ca;if(!sl_tick(c))return int(c.fault);
P_d3ca_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x4ULL)),c);
P_d3ca_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d3ca_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d3ca_3:;
goto L_d3cd;
}
L_d3cd:{ // JMP 0x0000d399
c.pc=0xd3cd;if(!sl_tick(c))return int(c.fault);
P_d3cd_0:;
goto L_d399;
P_d3cd_1:;
goto L_d3cf;
}
L_d3cf:{ // MOV EAX,dword ptr [EDI]
c.pc=0xd3cf;if(!sl_tick(c))return int(c.fault);
P_d3cf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_d3cf_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d3cf_2:;
goto L_d3d1;
}
L_d3d1:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xd3d1;if(!sl_tick(c))return int(c.fault);
P_d3d1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d3d1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d3d1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d3d1_3:;
goto L_d3d4;
}
L_d3d4:{ // MOV dword ptr [ESP + 0x8],EDX
c.pc=0xd3d4;if(!sl_tick(c))return int(c.fault);
P_d3d4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d3d4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d3d4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d3d4_3:;
goto L_d3d8;
}
L_d3d8:{ // MOV ECX,dword ptr [EBP + 0xc]
c.pc=0xd3d8;if(!sl_tick(c))return int(c.fault);
P_d3d8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_d3d8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d3d8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d3d8_3:;
goto L_d3db;
}
L_d3db:{ // MOV dword ptr [ESP + 0x4],ECX
c.pc=0xd3db;if(!sl_tick(c))return int(c.fault);
P_d3db_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d3db_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_d3db_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d3db_3:;
goto L_d3df;
}
L_d3df:{ // MOV dword ptr [ESP],EDI
c.pc=0xd3df;if(!sl_tick(c))return int(c.fault);
P_d3df_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d3df_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d3df_2:;
goto L_d3e2;
}
L_d3e2:{ // CALL dword ptr [EAX + 0x40]
c.pc=0xd3e2;if(!sl_tick(c))return int(c.fault);
P_d3e2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x40ULL)),c);
P_d3e2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d3e2_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d3e2_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d3e2_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd3e5ULL),c);
P_d3e2_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d3e2_6:;
goto L_d3e5;
}
L_d3e5:{ // JMP 0x0000d317
c.pc=0xd3e5;if(!sl_tick(c))return int(c.fault);
P_d3e5_0:;
goto L_d317;
P_d3e5_1:;
c.pc=0xd3ea;goto dispatch;
}
L_d3ec:{ // PUSH EBP
c.pc=0xd3ec;if(!sl_tick(c))return int(c.fault);
P_d3ec_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_d3ec_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d3ec_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d3ec_3:;
goto L_d3ed;
}
L_d3ed:{ // MOV EBP,ESP
c.pc=0xd3ed;if(!sl_tick(c))return int(c.fault);
P_d3ed_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_d3ed_1:;
goto L_d3ef;
}
L_d3ef:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0xd3ef;if(!sl_tick(c))return int(c.fault);
P_d3ef_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_d3ef_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d3ef_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d3ef_3:;
goto L_d3f2;
}
L_d3f2:{ // MOV ECX,dword ptr [EBP + 0xc]
c.pc=0xd3f2;if(!sl_tick(c))return int(c.fault);
P_d3f2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_d3f2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d3f2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d3f2_3:;
goto L_d3f5;
}
L_d3f5:{ // MOV EAX,dword ptr [ECX + 0x8]
c.pc=0xd3f5;if(!sl_tick(c))return int(c.fault);
P_d3f5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x8ULL)),c);
P_d3f5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d3f5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d3f5_3:;
goto L_d3f8;
}
L_d3f8:{ // MOV dword ptr [EDX + EAX*0x4 + 0xed4],0xffffffff
c.pc=0xd3f8;if(!sl_tick(c))return int(c.fault);
P_d3f8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0xed4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_d3f8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x4ULL)),c);
P_d3f8_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_d3f8_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xffffffffULL),c);
P_d3f8_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_d3f8_5:;
goto L_d403;
}
L_d403:{ // MOV EAX,dword ptr [ECX + 0x8]
c.pc=0xd403;if(!sl_tick(c))return int(c.fault);
P_d403_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x8ULL)),c);
P_d403_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d403_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d403_3:;
goto L_d406;
}
L_d406:{ // LEA EAX,[EAX + EAX*0x4]
c.pc=0xd406;if(!sl_tick(c))return int(c.fault);
P_d406_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x4ULL)),c);
P_d406_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_d406_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3580,c),c);
P_d406_3:;
goto L_d409;
}
L_d409:{ // SHL EAX,0x2
c.pc=0xd409;if(!sl_tick(c))return int(c.fault);
P_d409_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x50e00,(SlU(0x2ULL) & SlU(0x1fULL)),c);
P_d409_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x50e80,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d409_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_lshift(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c)),c);
P_d409_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x24d00,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) != SlU(0x0ULL)),c);
P_d409_4:;
sl_put<4>(c.temp,sizeof(c.temp),0x24d80,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) - SlU(0x1ULL)),c);
P_d409_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x24e00,sl_lshift(sl_get<4>(c.temp,sizeof(c.temp),0x50e80,c),sl_get<4>(c.temp,sizeof(c.temp),0x24d80,c)),c);
P_d409_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x24f00,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x24e00,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d409_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x24f80,(!sl_get<1>(c.temp,sizeof(c.temp),0x24d00,c)),c);
P_d409_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x25000,(sl_get<1>(c.temp,sizeof(c.temp),0x24f80,c) & sl_get<1>(c.reg,sizeof(c.reg),0x200,c)),c);
P_d409_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x25080,(sl_get<1>(c.temp,sizeof(c.temp),0x24d00,c) & sl_get<1>(c.temp,sizeof(c.temp),0x24f00,c)),c);
P_d409_10:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x25000,c) | sl_get<1>(c.temp,sizeof(c.temp),0x25080,c)),c);
P_d409_11:;
sl_put<1>(c.temp,sizeof(c.temp),0x25200,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) == SlU(0x1ULL)),c);
P_d409_12:;
sl_put<1>(c.temp,sizeof(c.temp),0x25280,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d409_13:;
sl_put<1>(c.temp,sizeof(c.temp),0x25380,(sl_get<1>(c.reg,sizeof(c.reg),0x200,c) ^ sl_get<1>(c.temp,sizeof(c.temp),0x25280,c)),c);
P_d409_14:;
sl_put<1>(c.temp,sizeof(c.temp),0x25400,(!sl_get<1>(c.temp,sizeof(c.temp),0x25200,c)),c);
P_d409_15:;
sl_put<1>(c.temp,sizeof(c.temp),0x25480,(sl_get<1>(c.temp,sizeof(c.temp),0x25400,c) & sl_get<1>(c.reg,sizeof(c.reg),0x20b,c)),c);
P_d409_16:;
sl_put<1>(c.temp,sizeof(c.temp),0x25500,(sl_get<1>(c.temp,sizeof(c.temp),0x25200,c) & sl_get<1>(c.temp,sizeof(c.temp),0x25380,c)),c);
P_d409_17:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(sl_get<1>(c.temp,sizeof(c.temp),0x25480,c) | sl_get<1>(c.temp,sizeof(c.temp),0x25500,c)),c);
P_d409_18:;
sl_put<1>(c.temp,sizeof(c.temp),0x22b80,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) != SlU(0x0ULL)),c);
P_d409_19:;
sl_put<1>(c.temp,sizeof(c.temp),0x22c80,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d409_20:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d00,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d409_21:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d80,(sl_get<1>(c.temp,sizeof(c.temp),0x22d00,c) & sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d409_22:;
sl_put<1>(c.temp,sizeof(c.temp),0x22e00,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22c80,c)),c);
P_d409_23:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_get<1>(c.temp,sizeof(c.temp),0x22d80,c) | sl_get<1>(c.temp,sizeof(c.temp),0x22e00,c)),c);
P_d409_24:;
sl_put<1>(c.temp,sizeof(c.temp),0x22f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_d409_25:;
sl_put<1>(c.temp,sizeof(c.temp),0x23000,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d409_26:;
sl_put<1>(c.temp,sizeof(c.temp),0x23080,(sl_get<1>(c.temp,sizeof(c.temp),0x23000,c) & sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d409_27:;
sl_put<1>(c.temp,sizeof(c.temp),0x23100,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22f80,c)),c);
P_d409_28:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x23080,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23100,c)),c);
P_d409_29:;
sl_put<4>(c.temp,sizeof(c.temp),0x23200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_d409_30:;
sl_put<1>(c.temp,sizeof(c.temp),0x23280,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x23200,c)),c);
P_d409_31:;
sl_put<1>(c.temp,sizeof(c.temp),0x23300,(sl_get<1>(c.temp,sizeof(c.temp),0x23280,c) & SlU(0x1ULL)),c);
P_d409_32:;
sl_put<1>(c.temp,sizeof(c.temp),0x23400,(sl_get<1>(c.temp,sizeof(c.temp),0x23300,c) == SlU(0x0ULL)),c);
P_d409_33:;
sl_put<1>(c.temp,sizeof(c.temp),0x23480,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d409_34:;
sl_put<1>(c.temp,sizeof(c.temp),0x23500,(sl_get<1>(c.temp,sizeof(c.temp),0x23480,c) & sl_get<1>(c.reg,sizeof(c.reg),0x202,c)),c);
P_d409_35:;
sl_put<1>(c.temp,sizeof(c.temp),0x23580,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x23400,c)),c);
P_d409_36:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x23500,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23580,c)),c);
P_d409_37:;
goto L_d40c;
}
L_d40c:{ // LEA ECX,[EAX + EDX*0x1 + 0x10d4]
c.pc=0xd40c;if(!sl_tick(c))return int(c.fault);
P_d40c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x10d4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d40c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x1ULL)),c);
P_d40c_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_d40c_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c),c);
P_d40c_4:;
goto L_d413;
}
L_d413:{ // MOV EAX,dword ptr [EAX + EDX*0x1 + 0x10d4]
c.pc=0xd413;if(!sl_tick(c))return int(c.fault);
P_d413_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x10d4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d413_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x1ULL)),c);
P_d413_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_d413_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c)),c),c);
P_d413_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d413_5:;
goto L_d41a;
}
L_d41a:{ // MOV dword ptr [EBP + 0x8],ECX
c.pc=0xd41a;if(!sl_tick(c))return int(c.fault);
P_d41a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_d41a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_d41a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d41a_3:;
goto L_d41d;
}
L_d41d:{ // MOV ECX,dword ptr [EAX + 0x10]
c.pc=0xd41d;if(!sl_tick(c))return int(c.fault);
P_d41d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x10ULL)),c);
P_d41d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d41d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d41d_3:;
goto L_d420;
}
L_d420:{ // POP EBP
c.pc=0xd420;if(!sl_tick(c))return int(c.fault);
P_d420_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d420_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d420_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d420_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d420_4:;
goto L_d421;
}
L_d421:{ // JMP ECX
c.pc=0xd421;if(!sl_tick(c))return int(c.fault);
P_d421_0:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c));goto dispatch;
P_d421_1:;
c.pc=0xd423;goto dispatch;
}
L_d424:{ // PUSH EBP
c.pc=0xd424;if(!sl_tick(c))return int(c.fault);
P_d424_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_d424_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d424_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d424_3:;
goto L_d425;
}
L_d425:{ // MOV EBP,ESP
c.pc=0xd425;if(!sl_tick(c))return int(c.fault);
P_d425_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_d425_1:;
goto L_d427;
}
L_d427:{ // PUSH EDI
c.pc=0xd427;if(!sl_tick(c))return int(c.fault);
P_d427_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d427_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d427_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d427_3:;
goto L_d428;
}
L_d428:{ // PUSH ESI
c.pc=0xd428;if(!sl_tick(c))return int(c.fault);
P_d428_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d428_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d428_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d428_3:;
goto L_d429;
}
L_d429:{ // SUB ESP,0x20
c.pc=0xd429;if(!sl_tick(c))return int(c.fault);
P_d429_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x20ULL)),c);
P_d429_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x20ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_d429_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x20ULL)),c);
P_d429_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d429_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d429_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d429_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d429_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d429_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d429_9:;
goto L_d42c;
}
L_d42c:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0xd42c;if(!sl_tick(c))return int(c.fault);
P_d42c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_d42c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d42c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d42c_3:;
goto L_d42f;
}
L_d42f:{ // MOV EDI,dword ptr [EBP + 0xc]
c.pc=0xd42f;if(!sl_tick(c))return int(c.fault);
P_d42f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_d42f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d42f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d42f_3:;
goto L_d432;
}
L_d432:{ // MOVZX EAX,byte ptr [EBP + 0x10]
c.pc=0xd432;if(!sl_tick(c))return int(c.fault);
P_d432_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d432_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d432_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d432_3:;
goto L_d436;
}
L_d436:{ // MOV byte ptr [EBP + -0x9],AL
c.pc=0xd436;if(!sl_tick(c))return int(c.fault);
P_d436_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff7ULL)),c);
P_d436_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,sl_get<1>(c.reg,sizeof(c.reg),0x0,c),c);
P_d436_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5100,c),c);
P_d436_3:;
goto L_d439;
}
L_d439:{ // CMP byte ptr [EDI + ESI*0x1 + 0x1b4],0x0
c.pc=0xd439;if(!sl_tick(c))return int(c.fault);
P_d439_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x1b4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c);
P_d439_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) * SlU(0x1ULL)),c);
P_d439_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_d439_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c)),c),c);
P_d439_4:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d439_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d439_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d439_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d439_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d439_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d439_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d439_11:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d439_12:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d439_13:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d439_14:;
goto L_d441;
}
L_d441:{ // JZ 0x0000d44b
c.pc=0xd441;if(!sl_tick(c))return int(c.fault);
P_d441_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_d44b;}
P_d441_1:;
goto L_d443;
}
L_d443:{ // TEST AL,AL
c.pc=0xd443;if(!sl_tick(c))return int(c.fault);
P_d443_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d443_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d443_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x54d80,(sl_get<1>(c.reg,sizeof(c.reg),0x0,c) & sl_get<1>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d443_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d443_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c) == SlU(0x0ULL)),c);
P_d443_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c) & SlU(0xffULL)),c);
P_d443_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d443_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d443_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d443_9:;
goto L_d445;
}
L_d445:{ // JZ 0x0000d459
c.pc=0xd445;if(!sl_tick(c))return int(c.fault);
P_d445_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_d459;}
P_d445_1:;
goto L_d447;
}
L_d447:{ // MOVZX EAX,byte ptr [EBP + -0x9]
c.pc=0xd447;if(!sl_tick(c))return int(c.fault);
P_d447_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff7ULL)),c);
P_d447_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d447_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d447_3:;
goto L_d44b;
}
L_d44b:{ // MOV byte ptr [EDI + ESI*0x1 + 0x1b4],AL
c.pc=0xd44b;if(!sl_tick(c))return int(c.fault);
P_d44b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x1b4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c);
P_d44b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) * SlU(0x1ULL)),c);
P_d44b_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_d44b_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,sl_get<1>(c.reg,sizeof(c.reg),0x0,c),c);
P_d44b_4:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5100,c),c);
P_d44b_5:;
goto L_d452;
}
L_d452:{ // ADD ESP,0x20
c.pc=0xd452;if(!sl_tick(c))return int(c.fault);
P_d452_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d452_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(0x20ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_d452_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x20ULL)),c);
P_d452_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d452_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d452_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d452_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d452_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d452_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d452_9:;
goto L_d455;
}
L_d455:{ // POP ESI
c.pc=0xd455;if(!sl_tick(c))return int(c.fault);
P_d455_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d455_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d455_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d455_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d455_4:;
goto L_d456;
}
L_d456:{ // POP EDI
c.pc=0xd456;if(!sl_tick(c))return int(c.fault);
P_d456_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d456_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d456_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d456_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d456_4:;
goto L_d457;
}
L_d457:{ // POP EBP
c.pc=0xd457;if(!sl_tick(c))return int(c.fault);
P_d457_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d457_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d457_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d457_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d457_4:;
goto L_d458;
}
L_d458:{ // RET
c.pc=0xd458;if(!sl_tick(c))return int(c.fault);
P_d458_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d458_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d458_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_d458_3:;
goto L_d459;
}
L_d459:{ // MOV EAX,dword ptr [ESI]
c.pc=0xd459;if(!sl_tick(c))return int(c.fault);
P_d459_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_d459_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d459_2:;
goto L_d45b;
}
L_d45b:{ // MOV dword ptr [ESP + 0x4],EDI
c.pc=0xd45b;if(!sl_tick(c))return int(c.fault);
P_d45b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d45b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_d45b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d45b_3:;
goto L_d45f;
}
L_d45f:{ // MOV dword ptr [ESP],ESI
c.pc=0xd45f;if(!sl_tick(c))return int(c.fault);
P_d45f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d45f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d45f_2:;
goto L_d462;
}
L_d462:{ // CALL dword ptr [EAX + 0xa0]
c.pc=0xd462;if(!sl_tick(c))return int(c.fault);
P_d462_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xa0ULL)),c);
P_d462_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d462_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d462_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d462_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd468ULL),c);
P_d462_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_d462_6:;
goto L_d468;
}
L_d468:{ // MOVZX EAX,byte ptr [EBP + -0x9]
c.pc=0xd468;if(!sl_tick(c))return int(c.fault);
P_d468_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff7ULL)),c);
P_d468_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d468_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d468_3:;
goto L_d46c;
}
L_d46c:{ // MOV byte ptr [EDI + ESI*0x1 + 0x1b4],AL
c.pc=0xd46c;if(!sl_tick(c))return int(c.fault);
P_d46c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x1b4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c);
P_d46c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) * SlU(0x1ULL)),c);
P_d46c_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_d46c_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,sl_get<1>(c.reg,sizeof(c.reg),0x0,c),c);
P_d46c_4:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5100,c),c);
P_d46c_5:;
goto L_d473;
}
L_d473:{ // ADD ESP,0x20
c.pc=0xd473;if(!sl_tick(c))return int(c.fault);
P_d473_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d473_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(0x20ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_d473_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x20ULL)),c);
P_d473_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d473_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d473_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d473_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d473_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d473_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d473_9:;
goto L_d476;
}
L_d476:{ // POP ESI
c.pc=0xd476;if(!sl_tick(c))return int(c.fault);
P_d476_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d476_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d476_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d476_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d476_4:;
goto L_d477;
}
L_d477:{ // POP EDI
c.pc=0xd477;if(!sl_tick(c))return int(c.fault);
P_d477_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d477_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d477_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d477_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d477_4:;
goto L_d478;
}
L_d478:{ // POP EBP
c.pc=0xd478;if(!sl_tick(c))return int(c.fault);
P_d478_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d478_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d478_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d478_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d478_4:;
goto L_d479;
}
L_d479:{ // RET
c.pc=0xd479;if(!sl_tick(c))return int(c.fault);
P_d479_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d479_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d479_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_d479_3:;
goto L_d47a;
}
L_d47a:{ // PUSH EBP
c.pc=0xd47a;if(!sl_tick(c))return int(c.fault);
P_d47a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_d47a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d47a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d47a_3:;
goto L_d47b;
}
L_d47b:{ // MOV EBP,ESP
c.pc=0xd47b;if(!sl_tick(c))return int(c.fault);
P_d47b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_d47b_1:;
goto L_d47d;
}
L_d47d:{ // PUSH ESI
c.pc=0xd47d;if(!sl_tick(c))return int(c.fault);
P_d47d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d47d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d47d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d47d_3:;
goto L_d47e;
}
L_d47e:{ // PUSH EBX
c.pc=0xd47e;if(!sl_tick(c))return int(c.fault);
P_d47e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_d47e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d47e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d47e_3:;
goto L_d47f;
}
L_d47f:{ // SUB ESP,0x10
c.pc=0xd47f;if(!sl_tick(c))return int(c.fault);
P_d47f_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x10ULL)),c);
P_d47f_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x10ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_d47f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x10ULL)),c);
P_d47f_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d47f_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d47f_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d47f_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d47f_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d47f_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d47f_9:;
goto L_d482;
}
L_d482:{ // CALL 0x000c086c
c.pc=0xd482;if(!sl_tick(c))return int(c.fault);
P_d482_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d482_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd487ULL),c);
P_d482_2:;
c.pc=0xc086c;goto dispatch;
P_d482_3:;
goto L_d487;
}
L_d487:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0xd487;if(!sl_tick(c))return int(c.fault);
P_d487_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_d487_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d487_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d487_3:;
goto L_d48a;
}
L_d48a:{ // MOV ECX,dword ptr [EBP + 0xc]
c.pc=0xd48a;if(!sl_tick(c))return int(c.fault);
P_d48a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_d48a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d48a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d48a_3:;
goto L_d48d;
}
L_d48d:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xd48d;if(!sl_tick(c))return int(c.fault);
P_d48d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d48d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d48d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d48d_3:;
goto L_d490;
}
L_d490:{ // MOV EDX,dword ptr [EBP + 0x14]
c.pc=0xd490;if(!sl_tick(c))return int(c.fault);
P_d490_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_d490_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d490_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d490_3:;
goto L_d493;
}
L_d493:{ // CVTSI2SS XMM0,EDX
c.pc=0xd493;if(!sl_tick(c))return int(c.fault);
P_d493_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<float>(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32))),c);
P_d493_1:;
goto L_d497;
}
L_d497:{ // DIVSS XMM0,dword ptr [EBX + 0xbb5f9]
c.pc=0xd497;if(!sl_tick(c))return int(c.fault);
P_d497_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xbb5f9ULL)),c);
P_d497_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d497_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) / sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d497_3:;
goto L_d49f;
}
L_d49f:{ // MOVAPS XMM1,XMM0
c.pc=0xd49f;if(!sl_tick(c))return int(c.fault);
P_d49f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_d49f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,sl_get<4>(c.reg,sizeof(c.reg),0x1204,c),c);
P_d49f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,sl_get<4>(c.reg,sizeof(c.reg),0x1208,c),c);
P_d49f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,sl_get<4>(c.reg,sizeof(c.reg),0x120c,c),c);
P_d49f_4:;
goto L_d4a2;
}
L_d4a2:{ // ADDSS XMM1,XMM0
c.pc=0xd4a2;if(!sl_tick(c))return int(c.fault);
P_d4a2_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_d4a2_1:;
goto L_d4a6;
}
L_d4a6:{ // MOVSS XMM2,dword ptr [EBX + 0xbb59d]
c.pc=0xd4a6;if(!sl_tick(c))return int(c.fault);
P_d4a6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xbb59dULL)),c);
P_d4a6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d4a6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1280,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d4a6_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1284,SlU(0x0ULL),c);
P_d4a6_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1288,SlU(0x0ULL),c);
P_d4a6_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x128c,SlU(0x0ULL),c);
P_d4a6_6:;
goto L_d4ae;
}
L_d4ae:{ // SUBSS XMM1,XMM2
c.pc=0xd4ae;if(!sl_tick(c))return int(c.fault);
P_d4ae_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) - sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_d4ae_1:;
goto L_d4b2;
}
L_d4b2:{ // CMP EAX,0x65
c.pc=0xd4b2;if(!sl_tick(c))return int(c.fault);
P_d4b2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d4b2_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x65ULL)),c);
P_d4b2_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x65ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x65ULL)))&(SlU(1)<<31))!=0),c);
P_d4b2_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x65ULL)),c);
P_d4b2_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d4b2_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_d4b2_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_d4b2_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d4b2_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d4b2_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d4b2_10:;
goto L_d4b5;
}
L_d4b5:{ // JA 0x0000d67d
c.pc=0xd4b5;if(!sl_tick(c))return int(c.fault);
P_d4b5_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9d80,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x200,c)) || bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c))),c);
P_d4b5_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9e80,(!sl_get<1>(c.temp,sizeof(c.temp),0x9d80,c)),c);
P_d4b5_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9e80,c)){goto L_d67d;}
P_d4b5_3:;
goto L_d4bb;
}
L_d4bb:{ // MOV EAX,dword ptr [EBX + EAX*0x4 + 0x41]
c.pc=0xd4bb;if(!sl_tick(c))return int(c.fault);
P_d4bb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x41ULL) + sl_get<4>(c.reg,sizeof(c.reg),0xc,c)),c);
P_d4bb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x4ULL)),c);
P_d4bb_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_d4bb_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c)),c),c);
P_d4bb_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d4bb_5:;
goto L_d4c2;
}
L_d4c2:{ // ADD EAX,EBX
c.pc=0xd4c2;if(!sl_tick(c))return int(c.fault);
P_d4c2_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+sl_get<4>(c.reg,sizeof(c.reg),0xc,c))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d4c2_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+sl_get<4>(c.reg,sizeof(c.reg),0xc,c)))&(sl_get<4>(c.reg,sizeof(c.reg),0xc,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+sl_get<4>(c.reg,sizeof(c.reg),0xc,c)))&(SlU(1)<<31))!=0),c);
P_d4c2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.reg,sizeof(c.reg),0xc,c)),c);
P_d4c2_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d4c2_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_d4c2_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_d4c2_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d4c2_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d4c2_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d4c2_9:;
goto L_d4c4;
}
L_d4c4:{ // JMP EAX
c.pc=0xd4c4;if(!sl_tick(c))return int(c.fault);
P_d4c4_0:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c));goto dispatch;
P_d4c4_1:;
c.pc=0xd4c6;goto dispatch;
}
L_d660:{ // CMP byte ptr [ESI + 0x1b54],0x0
c.pc=0xd660;if(!sl_tick(c))return int(c.fault);
P_d660_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1b54ULL)),c);
P_d660_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d660_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d660_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d660_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d660_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d660_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d660_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d660_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d660_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d660_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d660_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d660_12:;
goto L_d667;
}
L_d667:{ // JZ 0x0000d7c0
c.pc=0xd667;if(!sl_tick(c))return int(c.fault);
P_d667_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_d7c0;}
P_d667_1:;
goto L_d66d;
}
L_d66d:{ // SHL EDX,0x7
c.pc=0xd66d;if(!sl_tick(c))return int(c.fault);
P_d66d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x50e00,(SlU(0x7ULL) & SlU(0x1fULL)),c);
P_d66d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x50e80,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d66d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_lshift(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c)),c);
P_d66d_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x24d00,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) != SlU(0x0ULL)),c);
P_d66d_4:;
sl_put<4>(c.temp,sizeof(c.temp),0x24d80,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) - SlU(0x1ULL)),c);
P_d66d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x24e00,sl_lshift(sl_get<4>(c.temp,sizeof(c.temp),0x50e80,c),sl_get<4>(c.temp,sizeof(c.temp),0x24d80,c)),c);
P_d66d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x24f00,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x24e00,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d66d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x24f80,(!sl_get<1>(c.temp,sizeof(c.temp),0x24d00,c)),c);
P_d66d_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x25000,(sl_get<1>(c.temp,sizeof(c.temp),0x24f80,c) & sl_get<1>(c.reg,sizeof(c.reg),0x200,c)),c);
P_d66d_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x25080,(sl_get<1>(c.temp,sizeof(c.temp),0x24d00,c) & sl_get<1>(c.temp,sizeof(c.temp),0x24f00,c)),c);
P_d66d_10:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x25000,c) | sl_get<1>(c.temp,sizeof(c.temp),0x25080,c)),c);
P_d66d_11:;
sl_put<1>(c.temp,sizeof(c.temp),0x25200,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) == SlU(0x1ULL)),c);
P_d66d_12:;
sl_put<1>(c.temp,sizeof(c.temp),0x25280,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d66d_13:;
sl_put<1>(c.temp,sizeof(c.temp),0x25380,(sl_get<1>(c.reg,sizeof(c.reg),0x200,c) ^ sl_get<1>(c.temp,sizeof(c.temp),0x25280,c)),c);
P_d66d_14:;
sl_put<1>(c.temp,sizeof(c.temp),0x25400,(!sl_get<1>(c.temp,sizeof(c.temp),0x25200,c)),c);
P_d66d_15:;
sl_put<1>(c.temp,sizeof(c.temp),0x25480,(sl_get<1>(c.temp,sizeof(c.temp),0x25400,c) & sl_get<1>(c.reg,sizeof(c.reg),0x20b,c)),c);
P_d66d_16:;
sl_put<1>(c.temp,sizeof(c.temp),0x25500,(sl_get<1>(c.temp,sizeof(c.temp),0x25200,c) & sl_get<1>(c.temp,sizeof(c.temp),0x25380,c)),c);
P_d66d_17:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(sl_get<1>(c.temp,sizeof(c.temp),0x25480,c) | sl_get<1>(c.temp,sizeof(c.temp),0x25500,c)),c);
P_d66d_18:;
sl_put<1>(c.temp,sizeof(c.temp),0x22b80,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) != SlU(0x0ULL)),c);
P_d66d_19:;
sl_put<1>(c.temp,sizeof(c.temp),0x22c80,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d66d_20:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d00,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d66d_21:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d80,(sl_get<1>(c.temp,sizeof(c.temp),0x22d00,c) & sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d66d_22:;
sl_put<1>(c.temp,sizeof(c.temp),0x22e00,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22c80,c)),c);
P_d66d_23:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_get<1>(c.temp,sizeof(c.temp),0x22d80,c) | sl_get<1>(c.temp,sizeof(c.temp),0x22e00,c)),c);
P_d66d_24:;
sl_put<1>(c.temp,sizeof(c.temp),0x22f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_d66d_25:;
sl_put<1>(c.temp,sizeof(c.temp),0x23000,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d66d_26:;
sl_put<1>(c.temp,sizeof(c.temp),0x23080,(sl_get<1>(c.temp,sizeof(c.temp),0x23000,c) & sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d66d_27:;
sl_put<1>(c.temp,sizeof(c.temp),0x23100,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22f80,c)),c);
P_d66d_28:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x23080,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23100,c)),c);
P_d66d_29:;
sl_put<4>(c.temp,sizeof(c.temp),0x23200,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_d66d_30:;
sl_put<1>(c.temp,sizeof(c.temp),0x23280,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x23200,c)),c);
P_d66d_31:;
sl_put<1>(c.temp,sizeof(c.temp),0x23300,(sl_get<1>(c.temp,sizeof(c.temp),0x23280,c) & SlU(0x1ULL)),c);
P_d66d_32:;
sl_put<1>(c.temp,sizeof(c.temp),0x23400,(sl_get<1>(c.temp,sizeof(c.temp),0x23300,c) == SlU(0x0ULL)),c);
P_d66d_33:;
sl_put<1>(c.temp,sizeof(c.temp),0x23480,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d66d_34:;
sl_put<1>(c.temp,sizeof(c.temp),0x23500,(sl_get<1>(c.temp,sizeof(c.temp),0x23480,c) & sl_get<1>(c.reg,sizeof(c.reg),0x202,c)),c);
P_d66d_35:;
sl_put<1>(c.temp,sizeof(c.temp),0x23580,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x23400,c)),c);
P_d66d_36:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x23500,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23580,c)),c);
P_d66d_37:;
goto L_d670;
}
L_d670:{ // MOV dword ptr [ESI + 0x1b58],EDX
c.pc=0xd670;if(!sl_tick(c))return int(c.fault);
P_d670_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1b58ULL)),c);
P_d670_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d670_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d670_3:;
goto L_d676;
}
L_d676:{ // MOV byte ptr [ESI + 0x1b54],0x0
c.pc=0xd676;if(!sl_tick(c))return int(c.fault);
P_d676_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1b54ULL)),c);
P_d676_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_d676_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_d676_3:;
goto L_d67d;
}
L_d67d:{ // ADD ESP,0x10
c.pc=0xd67d;if(!sl_tick(c))return int(c.fault);
P_d67d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d67d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_d67d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_d67d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d67d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d67d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d67d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d67d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d67d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d67d_9:;
goto L_d680;
}
L_d680:{ // POP EBX
c.pc=0xd680;if(!sl_tick(c))return int(c.fault);
P_d680_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d680_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d680_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d680_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d680_4:;
goto L_d681;
}
L_d681:{ // POP ESI
c.pc=0xd681;if(!sl_tick(c))return int(c.fault);
P_d681_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d681_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d681_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d681_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d681_4:;
goto L_d682;
}
L_d682:{ // POP EBP
c.pc=0xd682;if(!sl_tick(c))return int(c.fault);
P_d682_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d682_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d682_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d682_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d682_4:;
goto L_d683;
}
L_d683:{ // RET
c.pc=0xd683;if(!sl_tick(c))return int(c.fault);
P_d683_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d683_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d683_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_d683_3:;
goto L_d684;
}
L_d684:{ // CMP byte ptr [ESI + 0xec0],0x0
c.pc=0xd684;if(!sl_tick(c))return int(c.fault);
P_d684_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0xec0ULL)),c);
P_d684_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d684_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d684_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d684_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d684_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d684_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d684_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d684_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d684_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d684_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d684_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d684_12:;
goto L_d68b;
}
L_d68b:{ // JZ 0x0000d67d
c.pc=0xd68b;if(!sl_tick(c))return int(c.fault);
P_d68b_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_d67d;}
P_d68b_1:;
goto L_d68d;
}
L_d68d:{ // MOVSS dword ptr [ESI + 0x1adc],XMM0
c.pc=0xd68d;if(!sl_tick(c))return int(c.fault);
P_d68d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1adcULL)),c);
P_d68d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_d68d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d68d_3:;
goto L_d695;
}
L_d695:{ // JMP 0x0000d67d
c.pc=0xd695;if(!sl_tick(c))return int(c.fault);
P_d695_0:;
goto L_d67d;
P_d695_1:;
goto L_d697;
}
L_d697:{ // MOVSS dword ptr [ESI + 0x1ae0],XMM0
c.pc=0xd697;if(!sl_tick(c))return int(c.fault);
P_d697_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ae0ULL)),c);
P_d697_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_d697_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d697_3:;
goto L_d69f;
}
L_d69f:{ // JMP 0x0000d67d
c.pc=0xd69f;if(!sl_tick(c))return int(c.fault);
P_d69f_0:;
goto L_d67d;
P_d69f_1:;
goto L_d6a1;
}
L_d6a1:{ // MOVSS dword ptr [ESI + 0x1ae4],XMM0
c.pc=0xd6a1;if(!sl_tick(c))return int(c.fault);
P_d6a1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ae4ULL)),c);
P_d6a1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_d6a1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d6a1_3:;
goto L_d6a9;
}
L_d6a9:{ // JMP 0x0000d67d
c.pc=0xd6a9;if(!sl_tick(c))return int(c.fault);
P_d6a9_0:;
goto L_d67d;
P_d6a9_1:;
goto L_d6ab;
}
L_d6ab:{ // CMP byte ptr [ESI + 0x1b54],0x0
c.pc=0xd6ab;if(!sl_tick(c))return int(c.fault);
P_d6ab_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1b54ULL)),c);
P_d6ab_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d6ab_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d6ab_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d6ab_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d6ab_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d6ab_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d6ab_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d6ab_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d6ab_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d6ab_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d6ab_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d6ab_12:;
goto L_d6b2;
}
L_d6b2:{ // JZ 0x0000d67d
c.pc=0xd6b2;if(!sl_tick(c))return int(c.fault);
P_d6b2_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_d67d;}
P_d6b2_1:;
goto L_d6b4;
}
L_d6b4:{ // MOV EAX,dword ptr [ESI + 0x1b58]
c.pc=0xd6b4;if(!sl_tick(c))return int(c.fault);
P_d6b4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1b58ULL)),c);
P_d6b4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d6b4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d6b4_3:;
goto L_d6ba;
}
L_d6ba:{ // TEST EAX,EAX
c.pc=0xd6ba;if(!sl_tick(c))return int(c.fault);
P_d6ba_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d6ba_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d6ba_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d6ba_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d6ba_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_d6ba_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_d6ba_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d6ba_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d6ba_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d6ba_9:;
goto L_d6bc;
}
L_d6bc:{ // JNZ 0x0000d67d
c.pc=0xd6bc;if(!sl_tick(c))return int(c.fault);
P_d6bc_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d6bc_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_d67d;}
P_d6bc_2:;
goto L_d6be;
}
L_d6be:{ // MOV dword ptr [ESP + 0xc],EDX
c.pc=0xd6be;if(!sl_tick(c))return int(c.fault);
P_d6be_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d6be_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d6be_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d6be_3:;
goto L_d6c2;
}
L_d6c2:{ // MOV dword ptr [ESP + 0x8],0xc
c.pc=0xd6c2;if(!sl_tick(c))return int(c.fault);
P_d6c2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d6c2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xcULL),c);
P_d6c2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_d6c2_3:;
goto L_d6ca;
}
L_d6ca:{ // MOV dword ptr [ESP + 0x4],0x0
c.pc=0xd6ca;if(!sl_tick(c))return int(c.fault);
P_d6ca_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d6ca_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_d6ca_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_d6ca_3:;
goto L_d6d2;
}
L_d6d2:{ // MOV EAX,dword ptr [ESI + 0x4]
c.pc=0xd6d2;if(!sl_tick(c))return int(c.fault);
P_d6d2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x4ULL)),c);
P_d6d2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d6d2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d6d2_3:;
goto L_d6d5;
}
L_d6d5:{ // ADD EAX,0x5a4
c.pc=0xd6d5;if(!sl_tick(c))return int(c.fault);
P_d6d5_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x5a4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d6d5_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x5a4ULL)))&(SlU(0x5a4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x5a4ULL)))&(SlU(1)<<31))!=0),c);
P_d6d5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x5a4ULL)),c);
P_d6d5_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d6d5_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_d6d5_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_d6d5_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d6d5_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d6d5_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d6d5_9:;
goto L_d6da;
}
L_d6da:{ // MOV dword ptr [ESP],EAX
c.pc=0xd6da;if(!sl_tick(c))return int(c.fault);
P_d6da_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d6da_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d6da_2:;
goto L_d6dd;
}
L_d6dd:{ // CALL 0x00012b64
c.pc=0xd6dd;if(!sl_tick(c))return int(c.fault);
P_d6dd_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d6dd_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd6e2ULL),c);
P_d6dd_2:;
c.pc=0x12b64;goto dispatch;
P_d6dd_3:;
goto L_d6e2;
}
L_d6e2:{ // MOV dword ptr [EBP + 0x14],0xffffffff
c.pc=0xd6e2;if(!sl_tick(c))return int(c.fault);
P_d6e2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_d6e2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xffffffffULL),c);
P_d6e2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_d6e2_3:;
goto L_d6e9;
}
L_d6e9:{ // MOV dword ptr [EBP + 0x10],0x19
c.pc=0xd6e9;if(!sl_tick(c))return int(c.fault);
P_d6e9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d6e9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x19ULL),c);
P_d6e9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_d6e9_3:;
goto L_d6f0;
}
L_d6f0:{ // MOV dword ptr [EBP + 0xc],0x0
c.pc=0xd6f0;if(!sl_tick(c))return int(c.fault);
P_d6f0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_d6f0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_d6f0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_d6f0_3:;
goto L_d6f7;
}
L_d6f7:{ // MOV EAX,dword ptr [ESI + 0x4]
c.pc=0xd6f7;if(!sl_tick(c))return int(c.fault);
P_d6f7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x4ULL)),c);
P_d6f7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d6f7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d6f7_3:;
goto L_d6fa;
}
L_d6fa:{ // ADD EAX,0x5a4
c.pc=0xd6fa;if(!sl_tick(c))return int(c.fault);
P_d6fa_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x5a4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_d6fa_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x5a4ULL)))&(SlU(0x5a4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x5a4ULL)))&(SlU(1)<<31))!=0),c);
P_d6fa_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x5a4ULL)),c);
P_d6fa_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d6fa_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_d6fa_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_d6fa_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d6fa_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d6fa_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d6fa_9:;
goto L_d6ff;
}
L_d6ff:{ // MOV dword ptr [EBP + 0x8],EAX
c.pc=0xd6ff;if(!sl_tick(c))return int(c.fault);
P_d6ff_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_d6ff_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d6ff_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d6ff_3:;
goto L_d702;
}
L_d702:{ // ADD ESP,0x10
c.pc=0xd702;if(!sl_tick(c))return int(c.fault);
P_d702_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d702_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_d702_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_d702_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d702_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d702_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d702_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d702_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d702_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d702_9:;
goto L_d705;
}
L_d705:{ // POP EBX
c.pc=0xd705;if(!sl_tick(c))return int(c.fault);
P_d705_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d705_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d705_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d705_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d705_4:;
goto L_d706;
}
L_d706:{ // POP ESI
c.pc=0xd706;if(!sl_tick(c))return int(c.fault);
P_d706_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d706_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d706_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d706_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d706_4:;
goto L_d707;
}
L_d707:{ // POP EBP
c.pc=0xd707;if(!sl_tick(c))return int(c.fault);
P_d707_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d707_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d707_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d707_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d707_4:;
goto L_d708;
}
L_d708:{ // JMP 0x00012b64
c.pc=0xd708;if(!sl_tick(c))return int(c.fault);
P_d708_0:;
c.pc=0x12b64;goto dispatch;
P_d708_1:;
goto L_d70d;
}
L_d70d:{ // SUBSS XMM0,XMM2
c.pc=0xd70d;if(!sl_tick(c))return int(c.fault);
P_d70d_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) - sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_d70d_1:;
goto L_d711;
}
L_d711:{ // MOVSS dword ptr [ESI + 0x130],XMM0
c.pc=0xd711;if(!sl_tick(c))return int(c.fault);
P_d711_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x130ULL)),c);
P_d711_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_d711_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d711_3:;
goto L_d719;
}
L_d719:{ // JMP 0x0000d67d
c.pc=0xd719;if(!sl_tick(c))return int(c.fault);
P_d719_0:;
goto L_d67d;
P_d719_1:;
goto L_d71e;
}
L_d71e:{ // CMP EDX,0x40
c.pc=0xd71e;if(!sl_tick(c))return int(c.fault);
P_d71e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d71e_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x40ULL)),c);
P_d71e_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x40ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x40ULL)))&(SlU(1)<<31))!=0),c);
P_d71e_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x40ULL)),c);
P_d71e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d71e_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_d71e_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_d71e_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d71e_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d71e_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d71e_10:;
goto L_d721;
}
L_d721:{ // JZ 0x0000d7c5
c.pc=0xd721;if(!sl_tick(c))return int(c.fault);
P_d721_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_d7c5;}
P_d721_1:;
goto L_d727;
}
L_d727:{ // MOVSS dword ptr [ESI + 0x134],XMM1
c.pc=0xd727;if(!sl_tick(c))return int(c.fault);
P_d727_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x134ULL)),c);
P_d727_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_d727_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d727_3:;
goto L_d72f;
}
L_d72f:{ // JMP 0x0000d67d
c.pc=0xd72f;if(!sl_tick(c))return int(c.fault);
P_d72f_0:;
goto L_d67d;
P_d72f_1:;
goto L_d734;
}
L_d734:{ // MOVSS dword ptr [ESI + 0x1ae8],XMM0
c.pc=0xd734;if(!sl_tick(c))return int(c.fault);
P_d734_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ae8ULL)),c);
P_d734_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_d734_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d734_3:;
goto L_d73c;
}
L_d73c:{ // JMP 0x0000d67d
c.pc=0xd73c;if(!sl_tick(c))return int(c.fault);
P_d73c_0:;
goto L_d67d;
P_d73c_1:;
goto L_d741;
}
L_d741:{ // MOVSS dword ptr [ESI + 0x144],XMM1
c.pc=0xd741;if(!sl_tick(c))return int(c.fault);
P_d741_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x144ULL)),c);
P_d741_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_d741_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d741_3:;
goto L_d749;
}
L_d749:{ // JMP 0x0000d67d
c.pc=0xd749;if(!sl_tick(c))return int(c.fault);
P_d749_0:;
goto L_d67d;
P_d749_1:;
goto L_d74e;
}
L_d74e:{ // CMP byte ptr [ESI + 0xec3],0x0
c.pc=0xd74e;if(!sl_tick(c))return int(c.fault);
P_d74e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0xec3ULL)),c);
P_d74e_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d74e_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d74e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d74e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d74e_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d74e_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d74e_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d74e_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d74e_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d74e_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d74e_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d74e_12:;
goto L_d755;
}
L_d755:{ // JZ 0x0000d67d
c.pc=0xd755;if(!sl_tick(c))return int(c.fault);
P_d755_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_d67d;}
P_d755_1:;
goto L_d75b;
}
L_d75b:{ // MOV EAX,dword ptr [ESI]
c.pc=0xd75b;if(!sl_tick(c))return int(c.fault);
P_d75b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_d75b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d75b_2:;
goto L_d75d;
}
L_d75d:{ // CMP EDX,0x1f
c.pc=0xd75d;if(!sl_tick(c))return int(c.fault);
P_d75d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d75d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x1fULL)),c);
P_d75d_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x1fULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x1fULL)))&(SlU(1)<<31))!=0),c);
P_d75d_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x1fULL)),c);
P_d75d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d75d_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_d75d_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_d75d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d75d_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d75d_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d75d_10:;
goto L_d760;
}
L_d760:{ // SETG DL
c.pc=0xd760;if(!sl_tick(c))return int(c.fault);
P_d760_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d760_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d760_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_d760_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x8,sl_get<1>(c.temp,sizeof(c.temp),0xa600,c),c);
P_d760_4:;
goto L_d763;
}
L_d763:{ // MOVZX EDX,DL
c.pc=0xd763;if(!sl_tick(c))return int(c.fault);
P_d763_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<1>(c.reg,sizeof(c.reg),0x8,c),c);
P_d763_1:;
goto L_d766;
}
L_d766:{ // MOV dword ptr [EBP + 0x10],EDX
c.pc=0xd766;if(!sl_tick(c))return int(c.fault);
P_d766_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_d766_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d766_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d766_3:;
goto L_d769;
}
L_d769:{ // MOV dword ptr [EBP + 0xc],ECX
c.pc=0xd769;if(!sl_tick(c))return int(c.fault);
P_d769_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_d769_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_d769_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d769_3:;
goto L_d76c;
}
L_d76c:{ // MOV dword ptr [EBP + 0x8],ESI
c.pc=0xd76c;if(!sl_tick(c))return int(c.fault);
P_d76c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_d76c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d76c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d76c_3:;
goto L_d76f;
}
L_d76f:{ // MOV ECX,dword ptr [EAX + 0x58]
c.pc=0xd76f;if(!sl_tick(c))return int(c.fault);
P_d76f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x58ULL)),c);
P_d76f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d76f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d76f_3:;
goto L_d772;
}
L_d772:{ // ADD ESP,0x10
c.pc=0xd772;if(!sl_tick(c))return int(c.fault);
P_d772_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_d772_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_d772_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_d772_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d772_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_d772_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_d772_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d772_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d772_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d772_9:;
goto L_d775;
}
L_d775:{ // POP EBX
c.pc=0xd775;if(!sl_tick(c))return int(c.fault);
P_d775_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d775_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d775_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d775_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d775_4:;
goto L_d776;
}
L_d776:{ // POP ESI
c.pc=0xd776;if(!sl_tick(c))return int(c.fault);
P_d776_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d776_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d776_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d776_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d776_4:;
goto L_d777;
}
L_d777:{ // POP EBP
c.pc=0xd777;if(!sl_tick(c))return int(c.fault);
P_d777_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_d777_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_d777_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_d777_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_d777_4:;
goto L_d778;
}
L_d778:{ // JMP ECX
c.pc=0xd778;if(!sl_tick(c))return int(c.fault);
P_d778_0:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c));goto dispatch;
P_d778_1:;
goto L_d77a;
}
L_d77a:{ // CMP byte ptr [ESI + 0x1b54],0x0
c.pc=0xd77a;if(!sl_tick(c))return int(c.fault);
P_d77a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1b54ULL)),c);
P_d77a_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d77a_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d77a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d77a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d77a_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d77a_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d77a_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d77a_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d77a_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d77a_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d77a_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d77a_12:;
goto L_d781;
}
L_d781:{ // JNZ 0x0000d670
c.pc=0xd781;if(!sl_tick(c))return int(c.fault);
P_d781_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d781_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_d670;}
P_d781_2:;
goto L_d787;
}
L_d787:{ // ADD dword ptr [ESI + 0x1b58],EDX
c.pc=0xd787;if(!sl_tick(c))return int(c.fault);
P_d787_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1b58ULL)),c);
P_d787_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d787_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)+sl_get<4>(c.reg,sizeof(c.reg),0x8,c))&sl_mask(32))<sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)),c);
P_d787_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d787_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)+sl_get<4>(c.reg,sizeof(c.reg),0x8,c)))&(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)+sl_get<4>(c.reg,sizeof(c.reg),0x8,c)))&(SlU(1)<<31))!=0),c);
P_d787_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d787_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c) + sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_d787_7:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d787_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d787_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d787_10:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d787_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c) == SlU(0x0ULL)),c);
P_d787_12:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d787_13:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c) & SlU(0xffULL)),c);
P_d787_14:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d787_15:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d787_16:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d787_17:;
goto L_d78d;
}
L_d78d:{ // MOV byte ptr [ESI + 0x1b54],0x1
c.pc=0xd78d;if(!sl_tick(c))return int(c.fault);
P_d78d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1b54ULL)),c);
P_d78d_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x1ULL),c);
P_d78d_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_d78d_3:;
goto L_d794;
}
L_d794:{ // JMP 0x0000d67d
c.pc=0xd794;if(!sl_tick(c))return int(c.fault);
P_d794_0:;
goto L_d67d;
P_d794_1:;
goto L_d799;
}
L_d799:{ // MOVSS dword ptr [ESI + 0x13c],XMM1
c.pc=0xd799;if(!sl_tick(c))return int(c.fault);
P_d799_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x13cULL)),c);
P_d799_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_d799_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d799_3:;
goto L_d7a1;
}
L_d7a1:{ // JMP 0x0000d67d
c.pc=0xd7a1;if(!sl_tick(c))return int(c.fault);
P_d7a1_0:;
goto L_d67d;
P_d7a1_1:;
goto L_d7a6;
}
L_d7a6:{ // MOVSS dword ptr [ESI + 0x140],XMM1
c.pc=0xd7a6;if(!sl_tick(c))return int(c.fault);
P_d7a6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x140ULL)),c);
P_d7a6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_d7a6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d7a6_3:;
goto L_d7ae;
}
L_d7ae:{ // JMP 0x0000d67d
c.pc=0xd7ae;if(!sl_tick(c))return int(c.fault);
P_d7ae_0:;
goto L_d67d;
P_d7ae_1:;
goto L_d7b3;
}
L_d7b3:{ // MOVSS dword ptr [ESI + 0x138],XMM1
c.pc=0xd7b3;if(!sl_tick(c))return int(c.fault);
P_d7b3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x138ULL)),c);
P_d7b3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_d7b3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d7b3_3:;
goto L_d7bb;
}
L_d7bb:{ // JMP 0x0000d67d
c.pc=0xd7bb;if(!sl_tick(c))return int(c.fault);
P_d7bb_0:;
goto L_d67d;
P_d7bb_1:;
goto L_d7c0;
}
L_d7c0:{ // SHL EDX,0x7
c.pc=0xd7c0;if(!sl_tick(c))return int(c.fault);
P_d7c0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x50e00,(SlU(0x7ULL) & SlU(0x1fULL)),c);
P_d7c0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x50e80,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d7c0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_lshift(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c)),c);
P_d7c0_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x24d00,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) != SlU(0x0ULL)),c);
P_d7c0_4:;
sl_put<4>(c.temp,sizeof(c.temp),0x24d80,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) - SlU(0x1ULL)),c);
P_d7c0_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x24e00,sl_lshift(sl_get<4>(c.temp,sizeof(c.temp),0x50e80,c),sl_get<4>(c.temp,sizeof(c.temp),0x24d80,c)),c);
P_d7c0_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x24f00,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x24e00,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d7c0_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x24f80,(!sl_get<1>(c.temp,sizeof(c.temp),0x24d00,c)),c);
P_d7c0_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x25000,(sl_get<1>(c.temp,sizeof(c.temp),0x24f80,c) & sl_get<1>(c.reg,sizeof(c.reg),0x200,c)),c);
P_d7c0_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x25080,(sl_get<1>(c.temp,sizeof(c.temp),0x24d00,c) & sl_get<1>(c.temp,sizeof(c.temp),0x24f00,c)),c);
P_d7c0_10:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x25000,c) | sl_get<1>(c.temp,sizeof(c.temp),0x25080,c)),c);
P_d7c0_11:;
sl_put<1>(c.temp,sizeof(c.temp),0x25200,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) == SlU(0x1ULL)),c);
P_d7c0_12:;
sl_put<1>(c.temp,sizeof(c.temp),0x25280,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d7c0_13:;
sl_put<1>(c.temp,sizeof(c.temp),0x25380,(sl_get<1>(c.reg,sizeof(c.reg),0x200,c) ^ sl_get<1>(c.temp,sizeof(c.temp),0x25280,c)),c);
P_d7c0_14:;
sl_put<1>(c.temp,sizeof(c.temp),0x25400,(!sl_get<1>(c.temp,sizeof(c.temp),0x25200,c)),c);
P_d7c0_15:;
sl_put<1>(c.temp,sizeof(c.temp),0x25480,(sl_get<1>(c.temp,sizeof(c.temp),0x25400,c) & sl_get<1>(c.reg,sizeof(c.reg),0x20b,c)),c);
P_d7c0_16:;
sl_put<1>(c.temp,sizeof(c.temp),0x25500,(sl_get<1>(c.temp,sizeof(c.temp),0x25200,c) & sl_get<1>(c.temp,sizeof(c.temp),0x25380,c)),c);
P_d7c0_17:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(sl_get<1>(c.temp,sizeof(c.temp),0x25480,c) | sl_get<1>(c.temp,sizeof(c.temp),0x25500,c)),c);
P_d7c0_18:;
sl_put<1>(c.temp,sizeof(c.temp),0x22b80,(sl_get<4>(c.temp,sizeof(c.temp),0x50e00,c) != SlU(0x0ULL)),c);
P_d7c0_19:;
sl_put<1>(c.temp,sizeof(c.temp),0x22c80,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d7c0_20:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d00,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d7c0_21:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d80,(sl_get<1>(c.temp,sizeof(c.temp),0x22d00,c) & sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d7c0_22:;
sl_put<1>(c.temp,sizeof(c.temp),0x22e00,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22c80,c)),c);
P_d7c0_23:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_get<1>(c.temp,sizeof(c.temp),0x22d80,c) | sl_get<1>(c.temp,sizeof(c.temp),0x22e00,c)),c);
P_d7c0_24:;
sl_put<1>(c.temp,sizeof(c.temp),0x22f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_d7c0_25:;
sl_put<1>(c.temp,sizeof(c.temp),0x23000,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d7c0_26:;
sl_put<1>(c.temp,sizeof(c.temp),0x23080,(sl_get<1>(c.temp,sizeof(c.temp),0x23000,c) & sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d7c0_27:;
sl_put<1>(c.temp,sizeof(c.temp),0x23100,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22f80,c)),c);
P_d7c0_28:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x23080,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23100,c)),c);
P_d7c0_29:;
sl_put<4>(c.temp,sizeof(c.temp),0x23200,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_d7c0_30:;
sl_put<1>(c.temp,sizeof(c.temp),0x23280,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x23200,c)),c);
P_d7c0_31:;
sl_put<1>(c.temp,sizeof(c.temp),0x23300,(sl_get<1>(c.temp,sizeof(c.temp),0x23280,c) & SlU(0x1ULL)),c);
P_d7c0_32:;
sl_put<1>(c.temp,sizeof(c.temp),0x23400,(sl_get<1>(c.temp,sizeof(c.temp),0x23300,c) == SlU(0x0ULL)),c);
P_d7c0_33:;
sl_put<1>(c.temp,sizeof(c.temp),0x23480,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d7c0_34:;
sl_put<1>(c.temp,sizeof(c.temp),0x23500,(sl_get<1>(c.temp,sizeof(c.temp),0x23480,c) & sl_get<1>(c.reg,sizeof(c.reg),0x202,c)),c);
P_d7c0_35:;
sl_put<1>(c.temp,sizeof(c.temp),0x23580,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x23400,c)),c);
P_d7c0_36:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x23500,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23580,c)),c);
P_d7c0_37:;
goto L_d7c3;
}
L_d7c3:{ // JMP 0x0000d787
c.pc=0xd7c3;if(!sl_tick(c))return int(c.fault);
P_d7c3_0:;
goto L_d787;
P_d7c3_1:;
goto L_d7c5;
}
L_d7c5:{ // MOV dword ptr [ESI + 0x134],0x0
c.pc=0xd7c5;if(!sl_tick(c))return int(c.fault);
P_d7c5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x134ULL)),c);
P_d7c5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_d7c5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_d7c5_3:;
goto L_d7cf;
}
L_d7cf:{ // JMP 0x0000d67d
c.pc=0xd7cf;if(!sl_tick(c))return int(c.fault);
P_d7cf_0:;
goto L_d67d;
P_d7cf_1:;
goto L_d7d4;
}
L_d7d4:{ // PUSH EBP
c.pc=0xd7d4;if(!sl_tick(c))return int(c.fault);
P_d7d4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_d7d4_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d7d4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d7d4_3:;
goto L_d7d5;
}
L_d7d5:{ // MOV EBP,ESP
c.pc=0xd7d5;if(!sl_tick(c))return int(c.fault);
P_d7d5_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_d7d5_1:;
goto L_d7d7;
}
L_d7d7:{ // PUSH ESI
c.pc=0xd7d7;if(!sl_tick(c))return int(c.fault);
P_d7d7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_d7d7_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d7d7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d7d7_3:;
goto L_d7d8;
}
L_d7d8:{ // PUSH EBX
c.pc=0xd7d8;if(!sl_tick(c))return int(c.fault);
P_d7d8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_d7d8_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d7d8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_d7d8_3:;
goto L_d7d9;
}
L_d7d9:{ // CALL 0x000c086c
c.pc=0xd7d9;if(!sl_tick(c))return int(c.fault);
P_d7d9_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_d7d9_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xd7deULL),c);
P_d7d9_2:;
c.pc=0xc086c;goto dispatch;
P_d7d9_3:;
goto L_d7de;
}
L_d7de:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0xd7de;if(!sl_tick(c))return int(c.fault);
P_d7de_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_d7de_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d7de_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d7de_3:;
goto L_d7e1;
}
L_d7e1:{ // MOV ECX,dword ptr [EBP + 0xc]
c.pc=0xd7e1;if(!sl_tick(c))return int(c.fault);
P_d7e1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_d7e1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d7e1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_d7e1_3:;
goto L_d7e4;
}
L_d7e4:{ // MOV EAX,ECX
c.pc=0xd7e4;if(!sl_tick(c))return int(c.fault);
P_d7e4_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_d7e4_1:;
goto L_d7e6;
}
L_d7e6:{ // TEST ECX,ECX
c.pc=0xd7e6;if(!sl_tick(c))return int(c.fault);
P_d7e6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d7e6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d7e6_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_d7e6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d7e6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_d7e6_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_d7e6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d7e6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d7e6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d7e6_9:;
goto L_d7e8;
}
L_d7e8:{ // JS 0x0000d9eb
c.pc=0xd7e8;if(!sl_tick(c))return int(c.fault);
P_d7e8_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x207,c)){c.pc=0xd9eb;goto dispatch;}
P_d7e8_1:;
goto L_d7ee;
}
L_d7ee:{ // MOV EDX,EAX
c.pc=0xd7ee;if(!sl_tick(c))return int(c.fault);
P_d7ee_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d7ee_1:;
goto L_d7f0;
}
L_d7f0:{ // SAR EDX,0x6
c.pc=0xd7f0;if(!sl_tick(c))return int(c.fault);
P_d7f0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x4f800,(SlU(0x6ULL) & SlU(0x1fULL)),c);
P_d7f0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x4f880,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d7f0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_sright(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),sl_get<4>(c.temp,sizeof(c.temp),0x4f800,c),32),c);
P_d7f0_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x25680,(sl_get<4>(c.temp,sizeof(c.temp),0x4f800,c) != SlU(0x0ULL)),c);
P_d7f0_4:;
sl_put<4>(c.temp,sizeof(c.temp),0x25700,(sl_get<4>(c.temp,sizeof(c.temp),0x4f800,c) - SlU(0x1ULL)),c);
P_d7f0_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x25780,sl_sright(sl_get<4>(c.temp,sizeof(c.temp),0x4f880,c),sl_get<4>(c.temp,sizeof(c.temp),0x25700,c),32),c);
P_d7f0_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x25800,(sl_get<4>(c.temp,sizeof(c.temp),0x25780,c) & SlU(0x1ULL)),c);
P_d7f0_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x25900,(sl_get<4>(c.temp,sizeof(c.temp),0x25800,c) != SlU(0x0ULL)),c);
P_d7f0_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x25980,(!sl_get<1>(c.temp,sizeof(c.temp),0x25680,c)),c);
P_d7f0_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x25a00,(sl_get<1>(c.temp,sizeof(c.temp),0x25980,c) & sl_get<1>(c.reg,sizeof(c.reg),0x200,c)),c);
P_d7f0_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x25a80,(sl_get<1>(c.temp,sizeof(c.temp),0x25680,c) & sl_get<1>(c.temp,sizeof(c.temp),0x25900,c)),c);
P_d7f0_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x25a00,c) | sl_get<1>(c.temp,sizeof(c.temp),0x25a80,c)),c);
P_d7f0_12:;
sl_put<1>(c.temp,sizeof(c.temp),0x25c00,(sl_get<4>(c.temp,sizeof(c.temp),0x4f800,c) == SlU(0x1ULL)),c);
P_d7f0_13:;
sl_put<1>(c.temp,sizeof(c.temp),0x25c80,(!sl_get<1>(c.temp,sizeof(c.temp),0x25c00,c)),c);
P_d7f0_14:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(sl_get<1>(c.temp,sizeof(c.temp),0x25c80,c) & sl_get<1>(c.reg,sizeof(c.reg),0x20b,c)),c);
P_d7f0_15:;
sl_put<1>(c.temp,sizeof(c.temp),0x22b80,(sl_get<4>(c.temp,sizeof(c.temp),0x4f800,c) != SlU(0x0ULL)),c);
P_d7f0_16:;
sl_put<1>(c.temp,sizeof(c.temp),0x22c80,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d7f0_17:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d00,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d7f0_18:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d80,(sl_get<1>(c.temp,sizeof(c.temp),0x22d00,c) & sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d7f0_19:;
sl_put<1>(c.temp,sizeof(c.temp),0x22e00,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22c80,c)),c);
P_d7f0_20:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_get<1>(c.temp,sizeof(c.temp),0x22d80,c) | sl_get<1>(c.temp,sizeof(c.temp),0x22e00,c)),c);
P_d7f0_21:;
sl_put<1>(c.temp,sizeof(c.temp),0x22f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_d7f0_22:;
sl_put<1>(c.temp,sizeof(c.temp),0x23000,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d7f0_23:;
sl_put<1>(c.temp,sizeof(c.temp),0x23080,(sl_get<1>(c.temp,sizeof(c.temp),0x23000,c) & sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d7f0_24:;
sl_put<1>(c.temp,sizeof(c.temp),0x23100,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22f80,c)),c);
P_d7f0_25:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x23080,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23100,c)),c);
P_d7f0_26:;
sl_put<4>(c.temp,sizeof(c.temp),0x23200,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_d7f0_27:;
sl_put<1>(c.temp,sizeof(c.temp),0x23280,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x23200,c)),c);
P_d7f0_28:;
sl_put<1>(c.temp,sizeof(c.temp),0x23300,(sl_get<1>(c.temp,sizeof(c.temp),0x23280,c) & SlU(0x1ULL)),c);
P_d7f0_29:;
sl_put<1>(c.temp,sizeof(c.temp),0x23400,(sl_get<1>(c.temp,sizeof(c.temp),0x23300,c) == SlU(0x0ULL)),c);
P_d7f0_30:;
sl_put<1>(c.temp,sizeof(c.temp),0x23480,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_d7f0_31:;
sl_put<1>(c.temp,sizeof(c.temp),0x23500,(sl_get<1>(c.temp,sizeof(c.temp),0x23480,c) & sl_get<1>(c.reg,sizeof(c.reg),0x202,c)),c);
P_d7f0_32:;
sl_put<1>(c.temp,sizeof(c.temp),0x23580,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x23400,c)),c);
P_d7f0_33:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x23500,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23580,c)),c);
P_d7f0_34:;
goto L_d7f3;
}
L_d7f3:{ // LEA EAX,[EDX + 0x1]
c.pc=0xd7f3;if(!sl_tick(c))return int(c.fault);
P_d7f3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x1ULL)),c);
P_d7f3_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_d7f3_2:;
goto L_d7f6;
}
L_d7f6:{ // AND CL,0x3f
c.pc=0xd7f6;if(!sl_tick(c))return int(c.fault);
P_d7f6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_d7f6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d7f6_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x4,(sl_get<1>(c.reg,sizeof(c.reg),0x4,c) & SlU(0x3fULL)),c);
P_d7f6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.reg,sizeof(c.reg),0x4,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d7f6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.reg,sizeof(c.reg),0x4,c) == SlU(0x0ULL)),c);
P_d7f6_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.reg,sizeof(c.reg),0x4,c) & SlU(0xffULL)),c);
P_d7f6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d7f6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d7f6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d7f6_9:;
goto L_d7f9;
}
L_d7f9:{ // CMOVNZ EDX,EAX
c.pc=0xd7f9;if(!sl_tick(c))return int(c.fault);
P_d7f9_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_d7f9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x30380,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_d7f9_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30400,(!sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)),c);
P_d7f9_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x30400,c)){goto L_d7fc;}
P_d7f9_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x30380,c),c);
P_d7f9_5:;
goto L_d7fc;
}
L_d7fc:{ // CMP byte ptr [ESI + 0x150],0x0
c.pc=0xd7fc;if(!sl_tick(c))return int(c.fault);
P_d7fc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x150ULL)),c);
P_d7fc_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d7fc_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_d7fc_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_d7fc_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_d7fc_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_d7fc_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_d7fc_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_d7fc_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_d7fc_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d7fc_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d7fc_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d7fc_12:;
goto L_d803;
}
L_d803:{ // JZ 0x0000d97b
c.pc=0xd803;if(!sl_tick(c))return int(c.fault);
P_d803_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){c.pc=0xd97b;goto dispatch;}
P_d803_1:;
goto L_d809;
}
L_d809:{ // MOVSS XMM2,dword ptr [EBX + 0xbb2a6]
c.pc=0xd809;if(!sl_tick(c))return int(c.fault);
P_d809_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xbb2a6ULL)),c);
P_d809_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d809_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1280,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d809_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1284,SlU(0x0ULL),c);
P_d809_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1288,SlU(0x0ULL),c);
P_d809_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x128c,SlU(0x0ULL),c);
P_d809_6:;
goto L_d811;
}
L_d811:{ // MULSS XMM2,dword ptr [ESI + 0x10]
c.pc=0xd811;if(!sl_tick(c))return int(c.fault);
P_d811_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x10ULL)),c);
P_d811_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_d811_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1280,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d811_3:;
goto L_d816;
}
L_d816:{ // UCOMISS XMM2,dword ptr [EBX + 0xbb2aa]
c.pc=0xd816;if(!sl_tick(c))return int(c.fault);
P_d816_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xbb2aaULL)),c);
P_d816_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x27f80,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_d816_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d816_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x28000,__builtin_isnan(sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d816_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(bool(sl_get<1>(c.temp,sizeof(c.temp),0x27f80,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0x28000,c))),c);
P_d816_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d816_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x28100,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c)) == sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d816_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28100,c)),c);
P_d816_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d816_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x28200,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c)) < sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d816_10:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28200,c)),c);
P_d816_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_d816_12:;
sl_put<1>(c.reg,sizeof(c.reg),0x204,SlU(0x0ULL),c);
P_d816_13:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,SlU(0x0ULL),c);
P_d816_14:;
goto L_d81d;
}
L_d81d:{ // JNC 0x0000d9cd
c.pc=0xd81d;if(!sl_tick(c))return int(c.fault);
P_d81d_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9b00,(!sl_get<1>(c.reg,sizeof(c.reg),0x200,c)),c);
P_d81d_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9b00,c)){c.pc=0xd9cd;goto dispatch;}
P_d81d_2:;
goto L_d823;
}
L_d823:{ // JP 0x0000d9cd
c.pc=0xd823;if(!sl_tick(c))return int(c.fault);
P_d823_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x202,c)){c.pc=0xd9cd;goto dispatch;}
P_d823_1:;
goto L_d829;
}
L_d829:{ // MOVSS XMM2,dword ptr [EBX + 0xbb2aa]
c.pc=0xd829;if(!sl_tick(c))return int(c.fault);
P_d829_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xbb2aaULL)),c);
P_d829_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d829_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1280,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d829_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1284,SlU(0x0ULL),c);
P_d829_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1288,SlU(0x0ULL),c);
P_d829_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x128c,SlU(0x0ULL),c);
P_d829_6:;
goto L_d831;
}
L_d831:{ // MOVSS XMM1,dword ptr [EBX + 0xbb2ae]
c.pc=0xd831;if(!sl_tick(c))return int(c.fault);
P_d831_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xbb2aeULL)),c);
P_d831_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d831_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d831_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_d831_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_d831_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_d831_6:;
goto L_d839;
}
L_d839:{ // MOVAPS XMM0,XMM1
c.pc=0xd839;if(!sl_tick(c))return int(c.fault);
P_d839_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_d839_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x1244,c),c);
P_d839_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x1248,c),c);
P_d839_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x124c,c),c);
P_d839_4:;
goto L_d83c;
}
L_d83c:{ // MULSS XMM0,dword ptr [ESI + 0x11c]
c.pc=0xd83c;if(!sl_tick(c))return int(c.fault);
P_d83c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x11cULL)),c);
P_d83c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d83c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d83c_3:;
goto L_d844;
}
L_d844:{ // MOVAPS XMM6,XMM2
c.pc=0xd844;if(!sl_tick(c))return int(c.fault);
P_d844_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1380,sl_get<4>(c.reg,sizeof(c.reg),0x1280,c),c);
P_d844_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1384,sl_get<4>(c.reg,sizeof(c.reg),0x1284,c),c);
P_d844_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1388,sl_get<4>(c.reg,sizeof(c.reg),0x1288,c),c);
P_d844_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x138c,sl_get<4>(c.reg,sizeof(c.reg),0x128c,c),c);
P_d844_4:;
goto L_d847;
}
L_d847:{ // MULSS XMM6,dword ptr [ESI + 0x1ad8]
c.pc=0xd847;if(!sl_tick(c))return int(c.fault);
P_d847_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ad8ULL)),c);
P_d847_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d847_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1380,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1380,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d847_3:;
goto L_d84f;
}
L_d84f:{ // ADDSS XMM0,XMM6
c.pc=0xd84f;if(!sl_tick(c))return int(c.fault);
P_d84f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1380,c))),c);
P_d84f_1:;
goto L_d853;
}
L_d853:{ // MOVSS dword ptr [ESI + 0x1aec],XMM0
c.pc=0xd853;if(!sl_tick(c))return int(c.fault);
P_d853_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1aecULL)),c);
P_d853_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_d853_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d853_3:;
goto L_d85b;
}
L_d85b:{ // MOVAPS XMM0,XMM1
c.pc=0xd85b;if(!sl_tick(c))return int(c.fault);
P_d85b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_d85b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x1244,c),c);
P_d85b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x1248,c),c);
P_d85b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x124c,c),c);
P_d85b_4:;
goto L_d85e;
}
L_d85e:{ // MULSS XMM0,dword ptr [ESI + 0x120]
c.pc=0xd85e;if(!sl_tick(c))return int(c.fault);
P_d85e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x120ULL)),c);
P_d85e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d85e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d85e_3:;
goto L_d866;
}
L_d866:{ // MOVAPS XMM5,XMM2
c.pc=0xd866;if(!sl_tick(c))return int(c.fault);
P_d866_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1340,sl_get<4>(c.reg,sizeof(c.reg),0x1280,c),c);
P_d866_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1344,sl_get<4>(c.reg,sizeof(c.reg),0x1284,c),c);
P_d866_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1348,sl_get<4>(c.reg,sizeof(c.reg),0x1288,c),c);
P_d866_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x134c,sl_get<4>(c.reg,sizeof(c.reg),0x128c,c),c);
P_d866_4:;
goto L_d869;
}
L_d869:{ // MULSS XMM5,dword ptr [ESI + 0x1adc]
c.pc=0xd869;if(!sl_tick(c))return int(c.fault);
P_d869_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1adcULL)),c);
P_d869_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d869_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1340,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1340,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d869_3:;
goto L_d871;
}
L_d871:{ // ADDSS XMM0,XMM5
c.pc=0xd871;if(!sl_tick(c))return int(c.fault);
P_d871_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1340,c))),c);
P_d871_1:;
goto L_d875;
}
L_d875:{ // MOVSS dword ptr [ESI + 0x1b00],XMM0
c.pc=0xd875;if(!sl_tick(c))return int(c.fault);
P_d875_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1b00ULL)),c);
P_d875_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_d875_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d875_3:;
goto L_d87d;
}
L_d87d:{ // MOVAPS XMM0,XMM1
c.pc=0xd87d;if(!sl_tick(c))return int(c.fault);
P_d87d_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_d87d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x1244,c),c);
P_d87d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x1248,c),c);
P_d87d_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x124c,c),c);
P_d87d_4:;
goto L_d880;
}
L_d880:{ // MULSS XMM0,dword ptr [ESI + 0x124]
c.pc=0xd880;if(!sl_tick(c))return int(c.fault);
P_d880_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x124ULL)),c);
P_d880_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d880_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d880_3:;
goto L_d888;
}
L_d888:{ // MOVAPS XMM4,XMM2
c.pc=0xd888;if(!sl_tick(c))return int(c.fault);
P_d888_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1300,sl_get<4>(c.reg,sizeof(c.reg),0x1280,c),c);
P_d888_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1304,sl_get<4>(c.reg,sizeof(c.reg),0x1284,c),c);
P_d888_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1308,sl_get<4>(c.reg,sizeof(c.reg),0x1288,c),c);
P_d888_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x130c,sl_get<4>(c.reg,sizeof(c.reg),0x128c,c),c);
P_d888_4:;
goto L_d88b;
}
L_d88b:{ // MULSS XMM4,dword ptr [ESI + 0x1ae0]
c.pc=0xd88b;if(!sl_tick(c))return int(c.fault);
P_d88b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ae0ULL)),c);
P_d88b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d88b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1300,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1300,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d88b_3:;
goto L_d893;
}
L_d893:{ // ADDSS XMM0,XMM4
c.pc=0xd893;if(!sl_tick(c))return int(c.fault);
P_d893_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1300,c))),c);
P_d893_1:;
goto L_d897;
}
L_d897:{ // MOVSS dword ptr [ESI + 0x1b14],XMM0
c.pc=0xd897;if(!sl_tick(c))return int(c.fault);
P_d897_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1b14ULL)),c);
P_d897_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_d897_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d897_3:;
goto L_d89f;
}
L_d89f:{ // MOVAPS XMM0,XMM1
c.pc=0xd89f;if(!sl_tick(c))return int(c.fault);
P_d89f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_d89f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x1244,c),c);
P_d89f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x1248,c),c);
P_d89f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x124c,c),c);
P_d89f_4:;
goto L_d8a2;
}
L_d8a2:{ // MULSS XMM0,dword ptr [ESI + 0x128]
c.pc=0xd8a2;if(!sl_tick(c))return int(c.fault);
P_d8a2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x128ULL)),c);
P_d8a2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d8a2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d8a2_3:;
goto L_d8aa;
}
L_d8aa:{ // MOVAPS XMM3,XMM2
c.pc=0xd8aa;if(!sl_tick(c))return int(c.fault);
P_d8aa_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c0,sl_get<4>(c.reg,sizeof(c.reg),0x1280,c),c);
P_d8aa_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c4,sl_get<4>(c.reg,sizeof(c.reg),0x1284,c),c);
P_d8aa_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c8,sl_get<4>(c.reg,sizeof(c.reg),0x1288,c),c);
P_d8aa_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x12cc,sl_get<4>(c.reg,sizeof(c.reg),0x128c,c),c);
P_d8aa_4:;
goto L_d8ad;
}
L_d8ad:{ // MULSS XMM3,dword ptr [ESI + 0x1ae4]
c.pc=0xd8ad;if(!sl_tick(c))return int(c.fault);
P_d8ad_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ae4ULL)),c);
P_d8ad_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d8ad_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c0,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x12c0,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d8ad_3:;
goto L_d8b5;
}
L_d8b5:{ // ADDSS XMM0,XMM3
c.pc=0xd8b5;if(!sl_tick(c))return int(c.fault);
P_d8b5_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x12c0,c))),c);
P_d8b5_1:;
goto L_d8b9;
}
L_d8b9:{ // MOVSS dword ptr [ESI + 0x1b28],XMM0
c.pc=0xd8b9;if(!sl_tick(c))return int(c.fault);
P_d8b9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1b28ULL)),c);
P_d8b9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_d8b9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d8b9_3:;
goto L_d8c1;
}
L_d8c1:{ // MOVAPS XMM0,XMM1
c.pc=0xd8c1;if(!sl_tick(c))return int(c.fault);
P_d8c1_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_d8c1_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x1244,c),c);
P_d8c1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x1248,c),c);
P_d8c1_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x124c,c),c);
P_d8c1_4:;
goto L_d8c4;
}
L_d8c4:{ // MULSS XMM0,dword ptr [ESI + 0x12c]
c.pc=0xd8c4;if(!sl_tick(c))return int(c.fault);
P_d8c4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x12cULL)),c);
P_d8c4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d8c4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d8c4_3:;
goto L_d8cc;
}
L_d8cc:{ // MULSS XMM2,dword ptr [ESI + 0x1ae8]
c.pc=0xd8cc;if(!sl_tick(c))return int(c.fault);
P_d8cc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ae8ULL)),c);
P_d8cc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_d8cc_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1280,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_d8cc_3:;
goto L_d8d4;
}
L_d8d4:{ // ADDSS XMM0,XMM2
c.pc=0xd8d4;if(!sl_tick(c))return int(c.fault);
P_d8d4_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_d8d4_1:;
goto L_d8d8;
}
L_d8d8:{ // MOVSS dword ptr [ESI + 0x1b3c],XMM0
c.pc=0xd8d8;if(!sl_tick(c))return int(c.fault);
P_d8d8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1b3cULL)),c);
P_d8d8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_d8d8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_d8d8_3:;
goto L_d8e0;
}
L_d8e0:{ // CMP EDX,0x1
c.pc=0xd8e0;if(!sl_tick(c))return int(c.fault);
P_d8e0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_d8e0_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x1ULL)),c);
P_d8e0_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x1ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_d8e0_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x1ULL)),c);
P_d8e0_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_d8e0_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_d8e0_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_d8e0_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_d8e0_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_d8e0_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_d8e0_10:;
goto L_d8e3;
}
L_d8e3:{ // JLE 0x0000d9bf
c.pc=0xd8e3;if(!sl_tick(c))return int(c.fault);
P_d8e3_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_d8e3_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_d8e3_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){c.pc=0xd9bf;goto dispatch;}
P_d8e3_3:;
c.pc=0xd8e9;goto dispatch;
}
}
