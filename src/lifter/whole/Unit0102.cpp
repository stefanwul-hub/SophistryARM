// Generated static p-code lift; original i386 SHA-256: 17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12
#include "LifterRuntime.h"
int sl_unit_0102(SlCpu& c){
goto dispatch;
dispatch:
if(c.fault||c.pc==c.stop)return int(c.fault);
switch(c.pc){
case 0x31bfb:goto L_31bfb;
case 0x31bfd:goto L_31bfd;
case 0x31c00:goto L_31c00;
case 0x31c03:goto L_31c03;
case 0x31c07:goto L_31c07;
case 0x31c0a:goto L_31c0a;
case 0x31c0d:goto L_31c0d;
case 0x31c11:goto L_31c11;
case 0x31c14:goto L_31c14;
case 0x31c17:goto L_31c17;
case 0x31c1a:goto L_31c1a;
case 0x31c1c:goto L_31c1c;
case 0x31c22:goto L_31c22;
case 0x31c25:goto L_31c25;
case 0x31c28:goto L_31c28;
case 0x31c2b:goto L_31c2b;
case 0x31c2e:goto L_31c2e;
case 0x31c30:goto L_31c30;
case 0x31c33:goto L_31c33;
case 0x31c35:goto L_31c35;
case 0x31c38:goto L_31c38;
case 0x31c3b:goto L_31c3b;
case 0x31c3d:goto L_31c3d;
case 0x31c3f:goto L_31c3f;
case 0x31c42:goto L_31c42;
case 0x31c46:goto L_31c46;
case 0x31c4b:goto L_31c4b;
case 0x31c4e:goto L_31c4e;
case 0x31c51:goto L_31c51;
case 0x31c54:goto L_31c54;
case 0x31c58:goto L_31c58;
case 0x31c60:goto L_31c60;
case 0x31c65:goto L_31c65;
case 0x31c6d:goto L_31c6d;
case 0x31c70:goto L_31c70;
case 0x31c74:goto L_31c74;
case 0x31c77:goto L_31c77;
case 0x31c7b:goto L_31c7b;
case 0x31c83:goto L_31c83;
case 0x31c8b:goto L_31c8b;
case 0x31c8f:goto L_31c8f;
case 0x31c93:goto L_31c93;
case 0x31c96:goto L_31c96;
case 0x31c99:goto L_31c99;
case 0x31c9f:goto L_31c9f;
case 0x31ca3:goto L_31ca3;
case 0x31ca6:goto L_31ca6;
case 0x31ca8:goto L_31ca8;
case 0x31cae:goto L_31cae;
case 0x31cb2:goto L_31cb2;
case 0x31cb6:goto L_31cb6;
case 0x31cb9:goto L_31cb9;
case 0x31cbd:goto L_31cbd;
case 0x31cc2:goto L_31cc2;
case 0x31cc5:goto L_31cc5;
case 0x31cc9:goto L_31cc9;
case 0x31ccd:goto L_31ccd;
case 0x31ccf:goto L_31ccf;
case 0x31cd3:goto L_31cd3;
case 0x31cd7:goto L_31cd7;
case 0x31cda:goto L_31cda;
case 0x31cde:goto L_31cde;
case 0x31ce6:goto L_31ce6;
case 0x31cea:goto L_31cea;
case 0x31cee:goto L_31cee;
case 0x31cf2:goto L_31cf2;
case 0x31cf8:goto L_31cf8;
case 0x31cfb:goto L_31cfb;
case 0x31cff:goto L_31cff;
case 0x31d02:goto L_31d02;
case 0x31d08:goto L_31d08;
case 0x31d0a:goto L_31d0a;
case 0x31d0d:goto L_31d0d;
case 0x31d11:goto L_31d11;
case 0x31d14:goto L_31d14;
case 0x31d18:goto L_31d18;
case 0x31d1b:goto L_31d1b;
case 0x31d1f:goto L_31d1f;
case 0x31d25:goto L_31d25;
case 0x31d28:goto L_31d28;
case 0x31d2c:goto L_31d2c;
case 0x31d2f:goto L_31d2f;
case 0x31d35:goto L_31d35;
case 0x31d38:goto L_31d38;
case 0x31d3b:goto L_31d3b;
case 0x31d3d:goto L_31d3d;
case 0x31d40:goto L_31d40;
case 0x31d43:goto L_31d43;
case 0x31d49:goto L_31d49;
case 0x31d4f:goto L_31d4f;
case 0x31d51:goto L_31d51;
case 0x31d54:goto L_31d54;
case 0x31d57:goto L_31d57;
case 0x31d5a:goto L_31d5a;
case 0x31d5b:goto L_31d5b;
case 0x31d5c:goto L_31d5c;
case 0x31d5d:goto L_31d5d;
case 0x31d5e:goto L_31d5e;
case 0x31d60:goto L_31d60;
case 0x31d61:goto L_31d61;
case 0x31d63:goto L_31d63;
case 0x31d64:goto L_31d64;
case 0x31d67:goto L_31d67;
case 0x31d6a:goto L_31d6a;
case 0x31d6d:goto L_31d6d;
case 0x31d6f:goto L_31d6f;
case 0x31d71:goto L_31d71;
case 0x31d73:goto L_31d73;
case 0x31d76:goto L_31d76;
case 0x31d7a:goto L_31d7a;
case 0x31d7d:goto L_31d7d;
case 0x31d7f:goto L_31d7f;
case 0x31d82:goto L_31d82;
case 0x31d85:goto L_31d85;
case 0x31d89:goto L_31d89;
case 0x31d8c:goto L_31d8c;
case 0x31d92:goto L_31d92;
case 0x31d95:goto L_31d95;
case 0x31d96:goto L_31d96;
case 0x31d97:goto L_31d97;
case 0x31d98:goto L_31d98;
case 0x31d99:goto L_31d99;
case 0x31d9b:goto L_31d9b;
case 0x31d9c:goto L_31d9c;
case 0x31d9d:goto L_31d9d;
case 0x31da0:goto L_31da0;
case 0x31da5:goto L_31da5;
case 0x31da8:goto L_31da8;
case 0x31dab:goto L_31dab;
case 0x31db1:goto L_31db1;
case 0x31db4:goto L_31db4;
case 0x31db7:goto L_31db7;
case 0x31dbb:goto L_31dbb;
case 0x31dbe:goto L_31dbe;
case 0x31dc1:goto L_31dc1;
case 0x31dc4:goto L_31dc4;
case 0x31dc7:goto L_31dc7;
case 0x31dca:goto L_31dca;
case 0x31dce:goto L_31dce;
case 0x31dd2:goto L_31dd2;
case 0x31dd5:goto L_31dd5;
case 0x31dd9:goto L_31dd9;
case 0x31ddc:goto L_31ddc;
case 0x31de0:goto L_31de0;
case 0x31de3:goto L_31de3;
case 0x31de8:goto L_31de8;
case 0x31dee:goto L_31dee;
case 0x31df1:goto L_31df1;
case 0x31df4:goto L_31df4;
case 0x31df6:goto L_31df6;
case 0x31dfe:goto L_31dfe;
case 0x31e01:goto L_31e01;
case 0x31e04:goto L_31e04;
case 0x31e07:goto L_31e07;
case 0x31e08:goto L_31e08;
case 0x31e09:goto L_31e09;
case 0x31e0a:goto L_31e0a;
case 0x31e14:goto L_31e14;
case 0x31e15:goto L_31e15;
case 0x31e17:goto L_31e17;
case 0x31e18:goto L_31e18;
case 0x31e19:goto L_31e19;
case 0x31e1c:goto L_31e1c;
case 0x31e21:goto L_31e21;
case 0x31e24:goto L_31e24;
case 0x31e27:goto L_31e27;
case 0x31e2d:goto L_31e2d;
case 0x31e30:goto L_31e30;
case 0x31e33:goto L_31e33;
case 0x31e37:goto L_31e37;
case 0x31e3a:goto L_31e3a;
case 0x31e3d:goto L_31e3d;
case 0x31e40:goto L_31e40;
case 0x31e43:goto L_31e43;
case 0x31e46:goto L_31e46;
case 0x31e4a:goto L_31e4a;
case 0x31e4e:goto L_31e4e;
case 0x31e52:goto L_31e52;
case 0x31e56:goto L_31e56;
case 0x31e59:goto L_31e59;
case 0x31e5d:goto L_31e5d;
case 0x31e60:goto L_31e60;
case 0x31e64:goto L_31e64;
case 0x31e67:goto L_31e67;
case 0x31e6c:goto L_31e6c;
case 0x31e72:goto L_31e72;
case 0x31e75:goto L_31e75;
case 0x31e78:goto L_31e78;
case 0x31e7a:goto L_31e7a;
case 0x31e82:goto L_31e82;
case 0x31e85:goto L_31e85;
case 0x31e88:goto L_31e88;
case 0x31e8b:goto L_31e8b;
case 0x31e8c:goto L_31e8c;
case 0x31e8d:goto L_31e8d;
case 0x31e8e:goto L_31e8e;
case 0x31e98:goto L_31e98;
case 0x31e99:goto L_31e99;
case 0x31e9b:goto L_31e9b;
case 0x31e9c:goto L_31e9c;
case 0x31e9d:goto L_31e9d;
case 0x31ea0:goto L_31ea0;
case 0x31ea5:goto L_31ea5;
case 0x31ea8:goto L_31ea8;
case 0x31eab:goto L_31eab;
case 0x31eb0:goto L_31eb0;
case 0x31eb7:goto L_31eb7;
case 0x31ec1:goto L_31ec1;
case 0x31ecb:goto L_31ecb;
case 0x31ed1:goto L_31ed1;
case 0x31ed3:goto L_31ed3;
case 0x31ed6:goto L_31ed6;
case 0x31ed7:goto L_31ed7;
case 0x31ed8:goto L_31ed8;
case 0x31ed9:goto L_31ed9;
case 0x31edc:goto L_31edc;
case 0x31edd:goto L_31edd;
case 0x31edf:goto L_31edf;
case 0x31ee4:goto L_31ee4;
case 0x31ee7:goto L_31ee7;
case 0x31eed:goto L_31eed;
case 0x31eef:goto L_31eef;
case 0x31ef2:goto L_31ef2;
case 0x31ef3:goto L_31ef3;
case 0x31ef8:goto L_31ef8;
case 0x31ef9:goto L_31ef9;
case 0x31efb:goto L_31efb;
case 0x31f00:goto L_31f00;
case 0x31f03:goto L_31f03;
case 0x31f09:goto L_31f09;
case 0x31f0b:goto L_31f0b;
case 0x31f0e:goto L_31f0e;
case 0x31f0f:goto L_31f0f;
case 0x31f14:goto L_31f14;
case 0x31f15:goto L_31f15;
case 0x31f17:goto L_31f17;
case 0x31f18:goto L_31f18;
case 0x31f19:goto L_31f19;
case 0x31f1c:goto L_31f1c;
case 0x31f21:goto L_31f21;
case 0x31f24:goto L_31f24;
case 0x31f2a:goto L_31f2a;
case 0x31f2c:goto L_31f2c;
case 0x31f2f:goto L_31f2f;
case 0x31f34:goto L_31f34;
case 0x31f37:goto L_31f37;
case 0x31f3a:goto L_31f3a;
case 0x31f3b:goto L_31f3b;
case 0x31f3c:goto L_31f3c;
case 0x31f3d:goto L_31f3d;
case 0x31f42:goto L_31f42;
case 0x31f43:goto L_31f43;
case 0x31f45:goto L_31f45;
case 0x31f46:goto L_31f46;
case 0x31f47:goto L_31f47;
case 0x31f4a:goto L_31f4a;
case 0x31f4f:goto L_31f4f;
case 0x31f52:goto L_31f52;
case 0x31f55:goto L_31f55;
case 0x31f5a:goto L_31f5a;
case 0x31f61:goto L_31f61;
case 0x31f6b:goto L_31f6b;
case 0x31f75:goto L_31f75;
case 0x31f7b:goto L_31f7b;
case 0x31f7d:goto L_31f7d;
case 0x31f80:goto L_31f80;
case 0x31f81:goto L_31f81;
case 0x31f82:goto L_31f82;
case 0x31f83:goto L_31f83;
case 0x31f86:goto L_31f86;
case 0x31f87:goto L_31f87;
case 0x31f89:goto L_31f89;
case 0x31f8e:goto L_31f8e;
case 0x31f91:goto L_31f91;
case 0x31f97:goto L_31f97;
case 0x31f99:goto L_31f99;
case 0x31f9c:goto L_31f9c;
case 0x31f9d:goto L_31f9d;
case 0x31fa2:goto L_31fa2;
case 0x31fa3:goto L_31fa3;
case 0x31fa5:goto L_31fa5;
case 0x31faa:goto L_31faa;
case 0x31fad:goto L_31fad;
case 0x31fb3:goto L_31fb3;
case 0x31fb5:goto L_31fb5;
case 0x31fb8:goto L_31fb8;
case 0x31fb9:goto L_31fb9;
case 0x31fbe:goto L_31fbe;
case 0x31fbf:goto L_31fbf;
case 0x31fc1:goto L_31fc1;
case 0x31fc2:goto L_31fc2;
case 0x31fc3:goto L_31fc3;
case 0x31fc6:goto L_31fc6;
case 0x31fcb:goto L_31fcb;
case 0x31fce:goto L_31fce;
case 0x31fd4:goto L_31fd4;
case 0x31fd6:goto L_31fd6;
case 0x31fd9:goto L_31fd9;
case 0x31fde:goto L_31fde;
case 0x31fe1:goto L_31fe1;
case 0x31fe4:goto L_31fe4;
case 0x31fe5:goto L_31fe5;
case 0x31fe6:goto L_31fe6;
case 0x31fe7:goto L_31fe7;
case 0x31fec:goto L_31fec;
case 0x31fed:goto L_31fed;
case 0x31fef:goto L_31fef;
case 0x31ff0:goto L_31ff0;
case 0x31ff1:goto L_31ff1;
case 0x31ff4:goto L_31ff4;
case 0x31ff9:goto L_31ff9;
case 0x31ffc:goto L_31ffc;
case 0x31fff:goto L_31fff;
case 0x32004:goto L_32004;
case 0x3200a:goto L_3200a;
case 0x3200c:goto L_3200c;
case 0x3200f:goto L_3200f;
case 0x32010:goto L_32010;
case 0x32011:goto L_32011;
case 0x32012:goto L_32012;
case 0x32014:goto L_32014;
case 0x32015:goto L_32015;
case 0x32017:goto L_32017;
case 0x3201c:goto L_3201c;
case 0x3201f:goto L_3201f;
case 0x32025:goto L_32025;
case 0x32027:goto L_32027;
case 0x3202a:goto L_3202a;
case 0x3202b:goto L_3202b;
case 0x32030:goto L_32030;
case 0x32031:goto L_32031;
case 0x32033:goto L_32033;
case 0x32038:goto L_32038;
case 0x3203b:goto L_3203b;
case 0x32041:goto L_32041;
case 0x32043:goto L_32043;
case 0x32046:goto L_32046;
case 0x32047:goto L_32047;
case 0x3204c:goto L_3204c;
case 0x3204d:goto L_3204d;
case 0x3204f:goto L_3204f;
case 0x32050:goto L_32050;
case 0x32051:goto L_32051;
case 0x32054:goto L_32054;
case 0x32059:goto L_32059;
case 0x3205c:goto L_3205c;
case 0x32062:goto L_32062;
case 0x32064:goto L_32064;
case 0x32067:goto L_32067;
case 0x3206c:goto L_3206c;
case 0x3206f:goto L_3206f;
case 0x32072:goto L_32072;
case 0x32073:goto L_32073;
case 0x32074:goto L_32074;
case 0x32075:goto L_32075;
case 0x3207a:goto L_3207a;
case 0x3207b:goto L_3207b;
case 0x3207d:goto L_3207d;
case 0x3207e:goto L_3207e;
case 0x3207f:goto L_3207f;
case 0x32080:goto L_32080;
case 0x32083:goto L_32083;
case 0x32088:goto L_32088;
case 0x3208b:goto L_3208b;
case 0x32090:goto L_32090;
case 0x32096:goto L_32096;
case 0x3209c:goto L_3209c;
case 0x320a2:goto L_320a2;
case 0x320a8:goto L_320a8;
case 0x320ab:goto L_320ab;
case 0x320b1:goto L_320b1;
case 0x320b9:goto L_320b9;
case 0x320bc:goto L_320bc;
case 0x320be:goto L_320be;
case 0x320c4:goto L_320c4;
case 0x320c7:goto L_320c7;
case 0x320cd:goto L_320cd;
case 0x320d1:goto L_320d1;
case 0x320d5:goto L_320d5;
case 0x320dd:goto L_320dd;
case 0x320e1:goto L_320e1;
case 0x320e3:goto L_320e3;
case 0x320e9:goto L_320e9;
case 0x320ec:goto L_320ec;
case 0x320ef:goto L_320ef;
case 0x320f1:goto L_320f1;
case 0x320f3:goto L_320f3;
case 0x320f6:goto L_320f6;
case 0x320fa:goto L_320fa;
case 0x320fe:goto L_320fe;
case 0x32102:goto L_32102;
case 0x32105:goto L_32105;
case 0x3210c:goto L_3210c;
case 0x32114:goto L_32114;
case 0x32118:goto L_32118;
case 0x3211e:goto L_3211e;
case 0x32123:goto L_32123;
case 0x32128:goto L_32128;
case 0x3212d:goto L_3212d;
case 0x32130:goto L_32130;
case 0x32135:goto L_32135;
case 0x3213a:goto L_3213a;
case 0x32142:goto L_32142;
case 0x32146:goto L_32146;
case 0x3214a:goto L_3214a;
case 0x3214c:goto L_3214c;
case 0x32151:goto L_32151;
case 0x32157:goto L_32157;
case 0x32159:goto L_32159;
case 0x3215c:goto L_3215c;
case 0x3215e:goto L_3215e;
case 0x32161:goto L_32161;
case 0x32164:goto L_32164;
case 0x32166:goto L_32166;
case 0x32169:goto L_32169;
case 0x3216b:goto L_3216b;
case 0x3216f:goto L_3216f;
case 0x32173:goto L_32173;
case 0x32177:goto L_32177;
case 0x3217b:goto L_3217b;
case 0x3217e:goto L_3217e;
case 0x32181:goto L_32181;
case 0x32183:goto L_32183;
case 0x32185:goto L_32185;
case 0x32187:goto L_32187;
case 0x32189:goto L_32189;
case 0x3218b:goto L_3218b;
case 0x3218f:goto L_3218f;
case 0x32193:goto L_32193;
case 0x32195:goto L_32195;
case 0x32198:goto L_32198;
case 0x3219b:goto L_3219b;
case 0x3219e:goto L_3219e;
case 0x321a0:goto L_321a0;
case 0x321a2:goto L_321a2;
case 0x321a4:goto L_321a4;
case 0x321a8:goto L_321a8;
case 0x321ac:goto L_321ac;
case 0x321b0:goto L_321b0;
case 0x321b4:goto L_321b4;
case 0x321b8:goto L_321b8;
case 0x321bc:goto L_321bc;
case 0x321c0:goto L_321c0;
case 0x321c4:goto L_321c4;
case 0x321c8:goto L_321c8;
case 0x321cc:goto L_321cc;
case 0x321d0:goto L_321d0;
case 0x321d3:goto L_321d3;
case 0x321d6:goto L_321d6;
case 0x321d9:goto L_321d9;
case 0x321db:goto L_321db;
case 0x321dd:goto L_321dd;
case 0x321e0:goto L_321e0;
case 0x321e1:goto L_321e1;
case 0x321e2:goto L_321e2;
case 0x321e3:goto L_321e3;
case 0x321e4:goto L_321e4;
case 0x321e5:goto L_321e5;
case 0x321ed:goto L_321ed;
case 0x321f2:goto L_321f2;
case 0x321f6:goto L_321f6;
case 0x321fa:goto L_321fa;
case 0x321fc:goto L_321fc;
case 0x321ff:goto L_321ff;
case 0x32203:goto L_32203;
case 0x32207:goto L_32207;
case 0x3220b:goto L_3220b;
case 0x3220f:goto L_3220f;
case 0x32213:goto L_32213;
case 0x32217:goto L_32217;
case 0x3221b:goto L_3221b;
case 0x3221f:goto L_3221f;
case 0x32222:goto L_32222;
case 0x32225:goto L_32225;
case 0x32227:goto L_32227;
case 0x32229:goto L_32229;
case 0x3222e:goto L_3222e;
case 0x32233:goto L_32233;
case 0x3223a:goto L_3223a;
case 0x3223f:goto L_3223f;
case 0x32247:goto L_32247;
case 0x3224c:goto L_3224c;
case 0x32254:goto L_32254;
case 0x3225a:goto L_3225a;
case 0x3225b:goto L_3225b;
case 0x3225d:goto L_3225d;
case 0x3225e:goto L_3225e;
case 0x3225f:goto L_3225f;
case 0x32260:goto L_32260;
case 0x32263:goto L_32263;
case 0x32266:goto L_32266;
case 0x32269:goto L_32269;
case 0x3226b:goto L_3226b;
case 0x3226e:goto L_3226e;
case 0x32270:goto L_32270;
case 0x32273:goto L_32273;
case 0x32277:goto L_32277;
case 0x32279:goto L_32279;
case 0x3227b:goto L_3227b;
case 0x3227f:goto L_3227f;
case 0x32283:goto L_32283;
case 0x32286:goto L_32286;
case 0x32289:goto L_32289;
case 0x3228b:goto L_3228b;
case 0x3228d:goto L_3228d;
case 0x32293:goto L_32293;
case 0x32297:goto L_32297;
case 0x3229b:goto L_3229b;
case 0x3229e:goto L_3229e;
case 0x322a1:goto L_322a1;
case 0x322a6:goto L_322a6;
case 0x322a9:goto L_322a9;
default:return 0;}
L_31bfb:{ // MOV EDX,dword ptr [EAX]
c.pc=0x31bfb;if(!sl_tick(c))return int(c.fault);
P_31bfb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_31bfb_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31bfb_2:;
goto L_31bfd;
}
L_31bfd:{ // LEA ECX,[EBP + -0x24]
c.pc=0x31bfd;if(!sl_tick(c))return int(c.fault);
P_31bfd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_31bfd_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_31bfd_2:;
goto L_31c00;
}
L_31c00:{ // MOV dword ptr [EBP + -0x3c],ECX
c.pc=0x31c00;if(!sl_tick(c))return int(c.fault);
P_31c00_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc4ULL)),c);
P_31c00_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_31c00_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c00_3:;
goto L_31c03;
}
L_31c03:{ // MOV dword ptr [ESP + 0x8],ECX
c.pc=0x31c03;if(!sl_tick(c))return int(c.fault);
P_31c03_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31c03_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_31c03_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c03_3:;
goto L_31c07;
}
L_31c07:{ // LEA ECX,[EBP + -0x20]
c.pc=0x31c07;if(!sl_tick(c))return int(c.fault);
P_31c07_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_31c07_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_31c07_2:;
goto L_31c0a;
}
L_31c0a:{ // MOV dword ptr [EBP + -0x38],ECX
c.pc=0x31c0a;if(!sl_tick(c))return int(c.fault);
P_31c0a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc8ULL)),c);
P_31c0a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_31c0a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c0a_3:;
goto L_31c0d;
}
L_31c0d:{ // MOV dword ptr [ESP + 0x4],ECX
c.pc=0x31c0d;if(!sl_tick(c))return int(c.fault);
P_31c0d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31c0d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_31c0d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c0d_3:;
goto L_31c11;
}
L_31c11:{ // MOV dword ptr [ESP],EAX
c.pc=0x31c11;if(!sl_tick(c))return int(c.fault);
P_31c11_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31c11_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c11_2:;
goto L_31c14;
}
L_31c14:{ // CALL dword ptr [EDX + 0x2c]
c.pc=0x31c14;if(!sl_tick(c))return int(c.fault);
P_31c14_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x2cULL)),c);
P_31c14_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31c14_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31c14_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31c14_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31c17ULL),c);
P_31c14_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_31c14_6:;
goto L_31c17;
}
L_31c17:{ // MOV ECX,dword ptr [EBP + 0xc]
c.pc=0x31c17;if(!sl_tick(c))return int(c.fault);
P_31c17_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_31c17_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31c17_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31c17_3:;
goto L_31c1a;
}
L_31c1a:{ // TEST ECX,ECX
c.pc=0x31c1a;if(!sl_tick(c))return int(c.fault);
P_31c1a_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_31c1a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_31c1a_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_31c1a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31c1a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_31c1a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_31c1a_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31c1a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31c1a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31c1a_9:;
goto L_31c1c;
}
L_31c1c:{ // JLE 0x00031d49
c.pc=0x31c1c;if(!sl_tick(c))return int(c.fault);
P_31c1c_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_31c1c_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_31c1c_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_31d49;}
P_31c1c_3:;
goto L_31c22;
}
L_31c22:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0x31c22;if(!sl_tick(c))return int(c.fault);
P_31c22_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_31c22_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31c22_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31c22_3:;
goto L_31c25;
}
L_31c25:{ // MOV dword ptr [EBP + -0x34],EAX
c.pc=0x31c25;if(!sl_tick(c))return int(c.fault);
P_31c25_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffccULL)),c);
P_31c25_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31c25_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c25_3:;
goto L_31c28;
}
L_31c28:{ // MOV EDX,dword ptr [EBP + 0x14]
c.pc=0x31c28;if(!sl_tick(c))return int(c.fault);
P_31c28_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_31c28_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31c28_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31c28_3:;
goto L_31c2b;
}
L_31c2b:{ // MOV dword ptr [EBP + -0x30],EDX
c.pc=0x31c2b;if(!sl_tick(c))return int(c.fault);
P_31c2b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd0ULL)),c);
P_31c2b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_31c2b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c2b_3:;
goto L_31c2e;
}
L_31c2e:{ // XOR EDI,EDI
c.pc=0x31c2e;if(!sl_tick(c))return int(c.fault);
P_31c2e_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_31c2e_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_31c2e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c);
P_31c2e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31c2e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) == SlU(0x0ULL)),c);
P_31c2e_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) & SlU(0xffULL)),c);
P_31c2e_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31c2e_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31c2e_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31c2e_9:;
goto L_31c30;
}
L_31c30:{ // MOV EDX,dword ptr [EBP + -0x1c]
c.pc=0x31c30;if(!sl_tick(c))return int(c.fault);
P_31c30_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_31c30_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31c30_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31c30_3:;
goto L_31c33;
}
L_31c33:{ // MOV EAX,EDI
c.pc=0x31c33;if(!sl_tick(c))return int(c.fault);
P_31c33_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_31c33_1:;
goto L_31c35;
}
L_31c35:{ // AND EAX,0x7
c.pc=0x31c35;if(!sl_tick(c))return int(c.fault);
P_31c35_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_31c35_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_31c35_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0x7ULL)),c);
P_31c35_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31c35_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_31c35_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_31c35_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31c35_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31c35_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31c35_9:;
goto L_31c38;
}
L_31c38:{ // ADD EDI,0x1
c.pc=0x31c38;if(!sl_tick(c))return int(c.fault);
P_31c38_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c);
P_31c38_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_31c38_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1ULL)),c);
P_31c38_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31c38_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) == SlU(0x0ULL)),c);
P_31c38_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) & SlU(0xffULL)),c);
P_31c38_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31c38_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31c38_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31c38_9:;
goto L_31c3b;
}
L_31c3b:{ // TEST EAX,EAX
c.pc=0x31c3b;if(!sl_tick(c))return int(c.fault);
P_31c3b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_31c3b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_31c3b_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_31c3b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31c3b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_31c3b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_31c3b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31c3b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31c3b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31c3b_9:;
goto L_31c3d;
}
L_31c3d:{ // JNZ 0x00031cbd
c.pc=0x31c3d;if(!sl_tick(c))return int(c.fault);
P_31c3d_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_31c3d_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_31cbd;}
P_31c3d_2:;
goto L_31c3f;
}
L_31c3f:{ // MOV ECX,dword ptr [EBP + -0x34]
c.pc=0x31c3f;if(!sl_tick(c))return int(c.fault);
P_31c3f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffccULL)),c);
P_31c3f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31c3f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31c3f_3:;
goto L_31c42;
}
L_31c42:{ // MOVSS XMM0,dword ptr [ECX]
c.pc=0x31c42;if(!sl_tick(c))return int(c.fault);
P_31c42_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c),c);
P_31c42_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c42_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,SlU(0x0ULL),c);
P_31c42_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_31c42_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,SlU(0x0ULL),c);
P_31c42_5:;
goto L_31c46;
}
L_31c46:{ // MOVSS dword ptr [EBP + -0x2c],XMM0
c.pc=0x31c46;if(!sl_tick(c))return int(c.fault);
P_31c46_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_31c46_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_31c46_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c46_3:;
goto L_31c4b;
}
L_31c4b:{ // ADD ECX,0x4
c.pc=0x31c4b;if(!sl_tick(c))return int(c.fault);
P_31c4b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x4,c)+SlU(0x4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_31c4b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x4,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)+SlU(0x4ULL)))&(SlU(0x4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)+SlU(0x4ULL)))&(SlU(1)<<31))!=0),c);
P_31c4b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x4ULL)),c);
P_31c4b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x4,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31c4b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) == SlU(0x0ULL)),c);
P_31c4b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & SlU(0xffULL)),c);
P_31c4b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31c4b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31c4b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31c4b_9:;
goto L_31c4e;
}
L_31c4e:{ // MOV dword ptr [EBP + -0x34],ECX
c.pc=0x31c4e;if(!sl_tick(c))return int(c.fault);
P_31c4e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffccULL)),c);
P_31c4e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_31c4e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c4e_3:;
goto L_31c51;
}
L_31c51:{ // MOV EAX,dword ptr [EBP + 0x18]
c.pc=0x31c51;if(!sl_tick(c))return int(c.fault);
P_31c51_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x18ULL)),c);
P_31c51_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31c51_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31c51_3:;
goto L_31c54;
}
L_31c54:{ // SUBSS XMM0,dword ptr [EAX]
c.pc=0x31c54;if(!sl_tick(c))return int(c.fault);
P_31c54_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_31c54_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) - sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_31c54_2:;
goto L_31c58;
}
L_31c58:{ // MULSS XMM0,dword ptr [EBX + 0x96edc]
c.pc=0x31c58;if(!sl_tick(c))return int(c.fault);
P_31c58_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x96edcULL)),c);
P_31c58_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_31c58_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_31c58_3:;
goto L_31c60;
}
L_31c60:{ // MOVSS dword ptr [EBP + -0x2c],XMM0
c.pc=0x31c60;if(!sl_tick(c))return int(c.fault);
P_31c60_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_31c60_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_31c60_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c60_3:;
goto L_31c65;
}
L_31c65:{ // MOVSS XMM1,dword ptr [EBX + 0x96ebc]
c.pc=0x31c65;if(!sl_tick(c))return int(c.fault);
P_31c65_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x96ebcULL)),c);
P_31c65_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_31c65_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c65_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_31c65_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_31c65_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_31c65_6:;
goto L_31c6d;
}
L_31c6d:{ // MOV ECX,dword ptr [EBP + 0x1c]
c.pc=0x31c6d;if(!sl_tick(c))return int(c.fault);
P_31c6d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x1cULL)),c);
P_31c6d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31c6d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31c6d_3:;
goto L_31c70;
}
L_31c70:{ // MULSS XMM1,dword ptr [ECX]
c.pc=0x31c70;if(!sl_tick(c))return int(c.fault);
P_31c70_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c),c);
P_31c70_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_31c70_2:;
goto L_31c74;
}
L_31c74:{ // MOV EAX,dword ptr [EBP + -0x30]
c.pc=0x31c74;if(!sl_tick(c))return int(c.fault);
P_31c74_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd0ULL)),c);
P_31c74_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31c74_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31c74_3:;
goto L_31c77;
}
L_31c77:{ // MOVSS XMM0,dword ptr [EAX]
c.pc=0x31c77;if(!sl_tick(c))return int(c.fault);
P_31c77_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_31c77_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c77_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,SlU(0x0ULL),c);
P_31c77_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_31c77_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,SlU(0x0ULL),c);
P_31c77_5:;
goto L_31c7b;
}
L_31c7b:{ // ADDSS XMM0,dword ptr [EBX + 0x96e4c]
c.pc=0x31c7b;if(!sl_tick(c))return int(c.fault);
P_31c7b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x96e4cULL)),c);
P_31c7b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_31c7b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) + sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_31c7b_3:;
goto L_31c83;
}
L_31c83:{ // MULSS XMM0,dword ptr [EBX + 0x96eb8]
c.pc=0x31c83;if(!sl_tick(c))return int(c.fault);
P_31c83_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x96eb8ULL)),c);
P_31c83_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_31c83_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_31c83_3:;
goto L_31c8b;
}
L_31c8b:{ // ADDSS XMM1,XMM0
c.pc=0x31c8b;if(!sl_tick(c))return int(c.fault);
P_31c8b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_31c8b_1:;
goto L_31c8f;
}
L_31c8f:{ // MOVSS dword ptr [ECX],XMM1
c.pc=0x31c8f;if(!sl_tick(c))return int(c.fault);
P_31c8f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_31c8f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c8f_2:;
goto L_31c93;
}
L_31c93:{ // ADD EAX,0x4
c.pc=0x31c93;if(!sl_tick(c))return int(c.fault);
P_31c93_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_31c93_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL)))&(SlU(0x4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL)))&(SlU(1)<<31))!=0),c);
P_31c93_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_31c93_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31c93_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_31c93_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_31c93_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31c93_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31c93_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31c93_9:;
goto L_31c96;
}
L_31c96:{ // MOV dword ptr [EBP + -0x30],EAX
c.pc=0x31c96;if(!sl_tick(c))return int(c.fault);
P_31c96_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd0ULL)),c);
P_31c96_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31c96_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c96_3:;
goto L_31c99;
}
L_31c99:{ // LEA ECX,[EBX + 0x97040]
c.pc=0x31c99;if(!sl_tick(c))return int(c.fault);
P_31c99_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x97040ULL)),c);
P_31c99_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_31c99_2:;
goto L_31c9f;
}
L_31c9f:{ // MOVSS XMM0,dword ptr [ECX]
c.pc=0x31c9f;if(!sl_tick(c))return int(c.fault);
P_31c9f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c),c);
P_31c9f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31c9f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,SlU(0x0ULL),c);
P_31c9f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_31c9f_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,SlU(0x0ULL),c);
P_31c9f_5:;
goto L_31ca3;
}
L_31ca3:{ // UCOMISS XMM0,XMM1
c.pc=0x31ca3;if(!sl_tick(c))return int(c.fault);
P_31ca3_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x27f80,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_31ca3_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x28000,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_31ca3_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(bool(sl_get<1>(c.temp,sizeof(c.temp),0x27f80,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0x28000,c))),c);
P_31ca3_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x28100,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) == sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_31ca3_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28100,c)),c);
P_31ca3_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x28200,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) < sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_31ca3_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28200,c)),c);
P_31ca3_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_31ca3_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x204,SlU(0x0ULL),c);
P_31ca3_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,SlU(0x0ULL),c);
P_31ca3_10:;
goto L_31ca6;
}
L_31ca6:{ // JA 0x00031cb6
c.pc=0x31ca6;if(!sl_tick(c))return int(c.fault);
P_31ca6_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9d80,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x200,c)) || bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c))),c);
P_31ca6_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9e80,(!sl_get<1>(c.temp,sizeof(c.temp),0x9d80,c)),c);
P_31ca6_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9e80,c)){goto L_31cb6;}
P_31ca6_3:;
goto L_31ca8;
}
L_31ca8:{ // LEA ECX,[EBX + 0x97044]
c.pc=0x31ca8;if(!sl_tick(c))return int(c.fault);
P_31ca8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x97044ULL)),c);
P_31ca8_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_31ca8_2:;
goto L_31cae;
}
L_31cae:{ // MOVSS XMM0,dword ptr [ECX]
c.pc=0x31cae;if(!sl_tick(c))return int(c.fault);
P_31cae_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c),c);
P_31cae_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31cae_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,SlU(0x0ULL),c);
P_31cae_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_31cae_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,SlU(0x0ULL),c);
P_31cae_5:;
goto L_31cb2;
}
L_31cb2:{ // MINSS XMM0,XMM1
c.pc=0x31cb2;if(!sl_tick(c))return int(c.fault);
P_31cb2_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x72180,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) < sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_31cb2_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x72180,c)){goto L_31cb6;}
P_31cb2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_31cb2_3:;
goto L_31cb6;
}
L_31cb6:{ // MOV EAX,dword ptr [EBP + 0x1c]
c.pc=0x31cb6;if(!sl_tick(c))return int(c.fault);
P_31cb6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x1cULL)),c);
P_31cb6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31cb6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31cb6_3:;
goto L_31cb9;
}
L_31cb9:{ // MOVSS dword ptr [EAX],XMM0
c.pc=0x31cb9;if(!sl_tick(c))return int(c.fault);
P_31cb9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_31cb9_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31cb9_2:;
goto L_31cbd;
}
L_31cbd:{ // MOVSS XMM1,dword ptr [EBP + -0x2c]
c.pc=0x31cbd;if(!sl_tick(c))return int(c.fault);
P_31cbd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd4ULL)),c);
P_31cbd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31cbd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31cbd_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_31cbd_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_31cbd_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_31cbd_6:;
goto L_31cc2;
}
L_31cc2:{ // MOV ECX,dword ptr [EBP + 0x18]
c.pc=0x31cc2;if(!sl_tick(c))return int(c.fault);
P_31cc2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x18ULL)),c);
P_31cc2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31cc2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31cc2_3:;
goto L_31cc5;
}
L_31cc5:{ // ADDSS XMM1,dword ptr [ECX]
c.pc=0x31cc5;if(!sl_tick(c))return int(c.fault);
P_31cc5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c),c);
P_31cc5_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) + sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_31cc5_2:;
goto L_31cc9;
}
L_31cc9:{ // MOVSS dword ptr [ECX],XMM1
c.pc=0x31cc9;if(!sl_tick(c))return int(c.fault);
P_31cc9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_31cc9_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31cc9_2:;
goto L_31ccd;
}
L_31ccd:{ // MOV EAX,dword ptr [ESI]
c.pc=0x31ccd;if(!sl_tick(c))return int(c.fault);
P_31ccd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_31ccd_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31ccd_2:;
goto L_31ccf;
}
L_31ccf:{ // MULSS XMM1,dword ptr [EDX]
c.pc=0x31ccf;if(!sl_tick(c))return int(c.fault);
P_31ccf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_31ccf_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_31ccf_2:;
goto L_31cd3;
}
L_31cd3:{ // CVTSS2SD XMM1,XMM1
c.pc=0x31cd3;if(!sl_tick(c))return int(c.fault);
P_31cd3_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1240,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)))),c);
P_31cd3_1:;
goto L_31cd7;
}
L_31cd7:{ // MOV EDX,dword ptr [EBP + 0x1c]
c.pc=0x31cd7;if(!sl_tick(c))return int(c.fault);
P_31cd7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x1cULL)),c);
P_31cd7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31cd7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31cd7_3:;
goto L_31cda;
}
L_31cda:{ // CVTSS2SD XMM2,dword ptr [EDX]
c.pc=0x31cda;if(!sl_tick(c))return int(c.fault);
P_31cda_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_31cda_1:;
sl_put<8>(c.reg,sizeof(c.reg),0x1280,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)))),c);
P_31cda_2:;
goto L_31cde;
}
L_31cde:{ // MOVSD XMM0,qword ptr [EBX + 0x96bb0]
c.pc=0x31cde;if(!sl_tick(c))return int(c.fault);
P_31cde_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x96bb0ULL)),c);
P_31cde_1:;
sl_put<8>(c.temp,sizeof(c.temp),0x5280,sl_get<8>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_31cde_2:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_get<8>(c.temp,sizeof(c.temp),0x5280,c),c);
P_31cde_3:;
sl_put<8>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_31cde_4:;
goto L_31ce6;
}
L_31ce6:{ // SUBSD XMM0,XMM2
c.pc=0x31ce6;if(!sl_tick(c))return int(c.fault);
P_31ce6_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c)) - sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_31ce6_1:;
goto L_31cea;
}
L_31cea:{ // MULSD XMM1,XMM0
c.pc=0x31cea;if(!sl_tick(c))return int(c.fault);
P_31cea_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_31cea_1:;
goto L_31cee;
}
L_31cee:{ // CVTSD2SS XMM1,XMM1
c.pc=0x31cee;if(!sl_tick(c))return int(c.fault);
P_31cee_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(static_cast<float>(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1240,c)))),c);
P_31cee_1:;
goto L_31cf2;
}
L_31cf2:{ // MOVSS dword ptr [ESP + 0x8],XMM1
c.pc=0x31cf2;if(!sl_tick(c))return int(c.fault);
P_31cf2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31cf2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_31cf2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31cf2_3:;
goto L_31cf8;
}
L_31cf8:{ // MOV ECX,dword ptr [EBP + -0x38]
c.pc=0x31cf8;if(!sl_tick(c))return int(c.fault);
P_31cf8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc8ULL)),c);
P_31cf8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31cf8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31cf8_3:;
goto L_31cfb;
}
L_31cfb:{ // MOV dword ptr [ESP + 0x4],ECX
c.pc=0x31cfb;if(!sl_tick(c))return int(c.fault);
P_31cfb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31cfb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_31cfb_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31cfb_3:;
goto L_31cff;
}
L_31cff:{ // MOV dword ptr [ESP],ESI
c.pc=0x31cff;if(!sl_tick(c))return int(c.fault);
P_31cff_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31cff_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31cff_2:;
goto L_31d02;
}
L_31d02:{ // CALL dword ptr [EAX + 0xcc]
c.pc=0x31d02;if(!sl_tick(c))return int(c.fault);
P_31d02_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xccULL)),c);
P_31d02_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_31d02_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d02_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31d02_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31d08ULL),c);
P_31d02_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_31d02_6:;
goto L_31d08;
}
L_31d08:{ // MOV EDX,dword ptr [ESI]
c.pc=0x31d08;if(!sl_tick(c))return int(c.fault);
P_31d08_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_31d08_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d08_2:;
goto L_31d0a;
}
L_31d0a:{ // MOV EAX,dword ptr [EBP + -0x1c]
c.pc=0x31d0a;if(!sl_tick(c))return int(c.fault);
P_31d0a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_31d0a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31d0a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d0a_3:;
goto L_31d0d;
}
L_31d0d:{ // MOVSS XMM0,dword ptr [EAX]
c.pc=0x31d0d;if(!sl_tick(c))return int(c.fault);
P_31d0d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_31d0d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31d0d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,SlU(0x0ULL),c);
P_31d0d_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_31d0d_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,SlU(0x0ULL),c);
P_31d0d_5:;
goto L_31d11;
}
L_31d11:{ // MOV EAX,dword ptr [EBP + 0x18]
c.pc=0x31d11;if(!sl_tick(c))return int(c.fault);
P_31d11_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x18ULL)),c);
P_31d11_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31d11_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d11_3:;
goto L_31d14;
}
L_31d14:{ // MULSS XMM0,dword ptr [EAX]
c.pc=0x31d14;if(!sl_tick(c))return int(c.fault);
P_31d14_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_31d14_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_31d14_2:;
goto L_31d18;
}
L_31d18:{ // MOV ECX,dword ptr [EBP + 0x1c]
c.pc=0x31d18;if(!sl_tick(c))return int(c.fault);
P_31d18_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x1cULL)),c);
P_31d18_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31d18_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d18_3:;
goto L_31d1b;
}
L_31d1b:{ // MULSS XMM0,dword ptr [ECX]
c.pc=0x31d1b;if(!sl_tick(c))return int(c.fault);
P_31d1b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c),c);
P_31d1b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_31d1b_2:;
goto L_31d1f;
}
L_31d1f:{ // MOVSS dword ptr [ESP + 0x8],XMM0
c.pc=0x31d1f;if(!sl_tick(c))return int(c.fault);
P_31d1f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31d1f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_31d1f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31d1f_3:;
goto L_31d25;
}
L_31d25:{ // MOV EAX,dword ptr [EBP + -0x3c]
c.pc=0x31d25;if(!sl_tick(c))return int(c.fault);
P_31d25_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc4ULL)),c);
P_31d25_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31d25_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d25_3:;
goto L_31d28;
}
L_31d28:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x31d28;if(!sl_tick(c))return int(c.fault);
P_31d28_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31d28_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31d28_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31d28_3:;
goto L_31d2c;
}
L_31d2c:{ // MOV dword ptr [ESP],ESI
c.pc=0x31d2c;if(!sl_tick(c))return int(c.fault);
P_31d2c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31d2c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31d2c_2:;
goto L_31d2f;
}
L_31d2f:{ // CALL dword ptr [EDX + 0xcc]
c.pc=0x31d2f;if(!sl_tick(c))return int(c.fault);
P_31d2f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0xccULL)),c);
P_31d2f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_31d2f_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d2f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31d2f_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31d35ULL),c);
P_31d2f_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_31d2f_6:;
goto L_31d35;
}
L_31d35:{ // MOV EAX,dword ptr [EBP + -0x1c]
c.pc=0x31d35;if(!sl_tick(c))return int(c.fault);
P_31d35_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_31d35_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31d35_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d35_3:;
goto L_31d38;
}
L_31d38:{ // ADD EAX,0x4
c.pc=0x31d38;if(!sl_tick(c))return int(c.fault);
P_31d38_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_31d38_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL)))&(SlU(0x4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL)))&(SlU(1)<<31))!=0),c);
P_31d38_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_31d38_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31d38_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_31d38_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_31d38_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31d38_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31d38_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31d38_9:;
goto L_31d3b;
}
L_31d3b:{ // MOV EDX,EAX
c.pc=0x31d3b;if(!sl_tick(c))return int(c.fault);
P_31d3b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31d3b_1:;
goto L_31d3d;
}
L_31d3d:{ // MOV dword ptr [EBP + -0x1c],EAX
c.pc=0x31d3d;if(!sl_tick(c))return int(c.fault);
P_31d3d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_31d3d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31d3d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31d3d_3:;
goto L_31d40;
}
L_31d40:{ // CMP EDI,dword ptr [EBP + 0xc]
c.pc=0x31d40;if(!sl_tick(c))return int(c.fault);
P_31d40_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_31d40_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31d40_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31d40_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_31d40_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_31d40_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_31d40_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31d40_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_31d40_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_31d40_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31d40_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31d40_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31d40_12:;
goto L_31d43;
}
L_31d43:{ // JNZ 0x00031c33
c.pc=0x31d43;if(!sl_tick(c))return int(c.fault);
P_31d43_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_31d43_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_31c33;}
P_31d43_2:;
goto L_31d49;
}
L_31d49:{ // MOV EAX,dword ptr [ESI + 0x118]
c.pc=0x31d49;if(!sl_tick(c))return int(c.fault);
P_31d49_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x118ULL)),c);
P_31d49_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_31d49_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d49_3:;
goto L_31d4f;
}
L_31d4f:{ // MOV EDX,dword ptr [EAX]
c.pc=0x31d4f;if(!sl_tick(c))return int(c.fault);
P_31d4f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_31d4f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d4f_2:;
goto L_31d51;
}
L_31d51:{ // MOV dword ptr [ESP],EAX
c.pc=0x31d51;if(!sl_tick(c))return int(c.fault);
P_31d51_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31d51_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31d51_2:;
goto L_31d54;
}
L_31d54:{ // CALL dword ptr [EDX + 0x44]
c.pc=0x31d54;if(!sl_tick(c))return int(c.fault);
P_31d54_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x44ULL)),c);
P_31d54_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31d54_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d54_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31d54_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31d57ULL),c);
P_31d54_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_31d54_6:;
goto L_31d57;
}
L_31d57:{ // ADD ESP,0x4c
c.pc=0x31d57;if(!sl_tick(c))return int(c.fault);
P_31d57_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31d57_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4cULL)))&(SlU(0x4cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4cULL)))&(SlU(1)<<31))!=0),c);
P_31d57_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4cULL)),c);
P_31d57_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31d57_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31d57_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31d57_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31d57_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31d57_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31d57_9:;
goto L_31d5a;
}
L_31d5a:{ // POP EBX
c.pc=0x31d5a;if(!sl_tick(c))return int(c.fault);
P_31d5a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31d5a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31d5a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31d5a_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31d5a_4:;
goto L_31d5b;
}
L_31d5b:{ // POP ESI
c.pc=0x31d5b;if(!sl_tick(c))return int(c.fault);
P_31d5b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31d5b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31d5b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31d5b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31d5b_4:;
goto L_31d5c;
}
L_31d5c:{ // POP EDI
c.pc=0x31d5c;if(!sl_tick(c))return int(c.fault);
P_31d5c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31d5c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31d5c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31d5c_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31d5c_4:;
goto L_31d5d;
}
L_31d5d:{ // POP EBP
c.pc=0x31d5d;if(!sl_tick(c))return int(c.fault);
P_31d5d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31d5d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31d5d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31d5d_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31d5d_4:;
goto L_31d5e;
}
L_31d5e:{ // RET
c.pc=0x31d5e;if(!sl_tick(c))return int(c.fault);
P_31d5e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31d5e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31d5e_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_31d5e_3:;
c.pc=0x31d5f;goto dispatch;
}
L_31d60:{ // PUSH EBP
c.pc=0x31d60;if(!sl_tick(c))return int(c.fault);
P_31d60_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_31d60_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31d60_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31d60_3:;
goto L_31d61;
}
L_31d61:{ // MOV EBP,ESP
c.pc=0x31d61;if(!sl_tick(c))return int(c.fault);
P_31d61_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_31d61_1:;
goto L_31d63;
}
L_31d63:{ // PUSH ESI
c.pc=0x31d63;if(!sl_tick(c))return int(c.fault);
P_31d63_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31d63_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31d63_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31d63_3:;
goto L_31d64;
}
L_31d64:{ // SUB ESP,0x14
c.pc=0x31d64;if(!sl_tick(c))return int(c.fault);
P_31d64_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x14ULL)),c);
P_31d64_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x14ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x14ULL)))&(SlU(1)<<31))!=0),c);
P_31d64_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x14ULL)),c);
P_31d64_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31d64_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31d64_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31d64_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31d64_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31d64_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31d64_9:;
goto L_31d67;
}
L_31d67:{ // MOV ECX,dword ptr [EBP + 0x8]
c.pc=0x31d67;if(!sl_tick(c))return int(c.fault);
P_31d67_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31d67_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31d67_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d67_3:;
goto L_31d6a;
}
L_31d6a:{ // MOV EAX,dword ptr [ECX + 0x10]
c.pc=0x31d6a;if(!sl_tick(c))return int(c.fault);
P_31d6a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x10ULL)),c);
P_31d6a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31d6a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d6a_3:;
goto L_31d6d;
}
L_31d6d:{ // TEST EAX,EAX
c.pc=0x31d6d;if(!sl_tick(c))return int(c.fault);
P_31d6d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_31d6d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_31d6d_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_31d6d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31d6d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_31d6d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_31d6d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31d6d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31d6d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31d6d_9:;
goto L_31d6f;
}
L_31d6f:{ // JZ 0x00031d92
c.pc=0x31d6f;if(!sl_tick(c))return int(c.fault);
P_31d6f_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_31d92;}
P_31d6f_1:;
goto L_31d71;
}
L_31d71:{ // MOV EDX,dword ptr [ECX]
c.pc=0x31d71;if(!sl_tick(c))return int(c.fault);
P_31d71_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c),c);
P_31d71_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d71_2:;
goto L_31d73;
}
L_31d73:{ // MOV ESI,dword ptr [EBP + 0xc]
c.pc=0x31d73;if(!sl_tick(c))return int(c.fault);
P_31d73_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_31d73_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31d73_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d73_3:;
goto L_31d76;
}
L_31d76:{ // MOV dword ptr [ESP + 0x8],ESI
c.pc=0x31d76;if(!sl_tick(c))return int(c.fault);
P_31d76_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31d76_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31d76_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31d76_3:;
goto L_31d7a;
}
L_31d7a:{ // MOV ESI,dword ptr [EAX + 0x20]
c.pc=0x31d7a;if(!sl_tick(c))return int(c.fault);
P_31d7a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x20ULL)),c);
P_31d7a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31d7a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d7a_3:;
goto L_31d7d;
}
L_31d7d:{ // TEST ESI,ESI
c.pc=0x31d7d;if(!sl_tick(c))return int(c.fault);
P_31d7d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_31d7d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_31d7d_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_31d7d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31d7d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_31d7d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_31d7d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31d7d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31d7d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31d7d_9:;
goto L_31d7f;
}
L_31d7f:{ // SETNZ AL
c.pc=0x31d7f;if(!sl_tick(c))return int(c.fault);
P_31d7f_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_31d7f_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c),c);
P_31d7f_2:;
goto L_31d82;
}
L_31d82:{ // MOVZX EAX,AL
c.pc=0x31d82;if(!sl_tick(c))return int(c.fault);
P_31d82_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.reg,sizeof(c.reg),0x0,c),c);
P_31d82_1:;
goto L_31d85;
}
L_31d85:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x31d85;if(!sl_tick(c))return int(c.fault);
P_31d85_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31d85_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31d85_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31d85_3:;
goto L_31d89;
}
L_31d89:{ // MOV dword ptr [ESP],ECX
c.pc=0x31d89;if(!sl_tick(c))return int(c.fault);
P_31d89_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_31d89_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31d89_2:;
goto L_31d8c;
}
L_31d8c:{ // CALL dword ptr [EDX + 0xec]
c.pc=0x31d8c;if(!sl_tick(c))return int(c.fault);
P_31d8c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0xecULL)),c);
P_31d8c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_31d8c_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31d8c_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31d8c_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31d92ULL),c);
P_31d8c_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_31d8c_6:;
goto L_31d92;
}
L_31d92:{ // ADD ESP,0x14
c.pc=0x31d92;if(!sl_tick(c))return int(c.fault);
P_31d92_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x14ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31d92_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x14ULL)))&(SlU(0x14ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x14ULL)))&(SlU(1)<<31))!=0),c);
P_31d92_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x14ULL)),c);
P_31d92_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31d92_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31d92_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31d92_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31d92_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31d92_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31d92_9:;
goto L_31d95;
}
L_31d95:{ // POP ESI
c.pc=0x31d95;if(!sl_tick(c))return int(c.fault);
P_31d95_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31d95_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31d95_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31d95_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31d95_4:;
goto L_31d96;
}
L_31d96:{ // POP EBP
c.pc=0x31d96;if(!sl_tick(c))return int(c.fault);
P_31d96_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31d96_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31d96_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31d96_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31d96_4:;
goto L_31d97;
}
L_31d97:{ // RET
c.pc=0x31d97;if(!sl_tick(c))return int(c.fault);
P_31d97_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31d97_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31d97_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_31d97_3:;
goto L_31d98;
}
L_31d98:{ // PUSH EBP
c.pc=0x31d98;if(!sl_tick(c))return int(c.fault);
P_31d98_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_31d98_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31d98_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31d98_3:;
goto L_31d99;
}
L_31d99:{ // MOV EBP,ESP
c.pc=0x31d99;if(!sl_tick(c))return int(c.fault);
P_31d99_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_31d99_1:;
goto L_31d9b;
}
L_31d9b:{ // PUSH ESI
c.pc=0x31d9b;if(!sl_tick(c))return int(c.fault);
P_31d9b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31d9b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31d9b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31d9b_3:;
goto L_31d9c;
}
L_31d9c:{ // PUSH EBX
c.pc=0x31d9c;if(!sl_tick(c))return int(c.fault);
P_31d9c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_31d9c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31d9c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31d9c_3:;
goto L_31d9d;
}
L_31d9d:{ // SUB ESP,0x20
c.pc=0x31d9d;if(!sl_tick(c))return int(c.fault);
P_31d9d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x20ULL)),c);
P_31d9d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x20ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_31d9d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x20ULL)),c);
P_31d9d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31d9d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31d9d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31d9d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31d9d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31d9d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31d9d_9:;
goto L_31da0;
}
L_31da0:{ // CALL 0x000c086c
c.pc=0x31da0;if(!sl_tick(c))return int(c.fault);
P_31da0_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31da0_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31da5ULL),c);
P_31da0_2:;
c.pc=0xc086c;goto dispatch;
P_31da0_3:;
goto L_31da5;
}
L_31da5:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0x31da5;if(!sl_tick(c))return int(c.fault);
P_31da5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31da5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31da5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31da5_3:;
goto L_31da8;
}
L_31da8:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0x31da8;if(!sl_tick(c))return int(c.fault);
P_31da8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_31da8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31da8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31da8_3:;
goto L_31dab;
}
L_31dab:{ // MOV EAX,dword ptr [EBX + 0xd1a63]
c.pc=0x31dab;if(!sl_tick(c))return int(c.fault);
P_31dab_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xd1a63ULL)),c);
P_31dab_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_31dab_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31dab_3:;
goto L_31db1;
}
L_31db1:{ // ADD EAX,0x8
c.pc=0x31db1;if(!sl_tick(c))return int(c.fault);
P_31db1_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_31db1_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_31db1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_31db1_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31db1_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_31db1_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_31db1_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31db1_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31db1_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31db1_9:;
goto L_31db4;
}
L_31db4:{ // MOV dword ptr [EBP + -0x18],EAX
c.pc=0x31db4;if(!sl_tick(c))return int(c.fault);
P_31db4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_31db4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31db4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31db4_3:;
goto L_31db7;
}
L_31db7:{ // MOVZX EAX,byte ptr [EDX + 0x4]
c.pc=0x31db7;if(!sl_tick(c))return int(c.fault);
P_31db7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x4ULL)),c);
P_31db7_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31db7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_31db7_3:;
goto L_31dbb;
}
L_31dbb:{ // MOV byte ptr [EBP + -0x14],AL
c.pc=0x31dbb;if(!sl_tick(c))return int(c.fault);
P_31dbb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_31dbb_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,sl_get<1>(c.reg,sizeof(c.reg),0x0,c),c);
P_31dbb_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5100,c),c);
P_31dbb_3:;
goto L_31dbe;
}
L_31dbe:{ // MOV EAX,dword ptr [EDX + 0x8]
c.pc=0x31dbe;if(!sl_tick(c))return int(c.fault);
P_31dbe_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x8ULL)),c);
P_31dbe_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31dbe_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31dbe_3:;
goto L_31dc1;
}
L_31dc1:{ // MOV dword ptr [EBP + -0x10],EAX
c.pc=0x31dc1;if(!sl_tick(c))return int(c.fault);
P_31dc1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_31dc1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31dc1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31dc1_3:;
goto L_31dc4;
}
L_31dc4:{ // MOV EAX,dword ptr [EDX + 0xc]
c.pc=0x31dc4;if(!sl_tick(c))return int(c.fault);
P_31dc4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0xcULL)),c);
P_31dc4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31dc4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31dc4_3:;
goto L_31dc7;
}
L_31dc7:{ // MOV dword ptr [EBP + -0xc],EAX
c.pc=0x31dc7;if(!sl_tick(c))return int(c.fault);
P_31dc7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_31dc7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31dc7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31dc7_3:;
goto L_31dca;
}
L_31dca:{ // MOVZX EAX,byte ptr [EBP + 0x14]
c.pc=0x31dca;if(!sl_tick(c))return int(c.fault);
P_31dca_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_31dca_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31dca_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_31dca_3:;
goto L_31dce;
}
L_31dce:{ // MOV dword ptr [ESP + 0xc],EAX
c.pc=0x31dce;if(!sl_tick(c))return int(c.fault);
P_31dce_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31dce_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31dce_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31dce_3:;
goto L_31dd2;
}
L_31dd2:{ // LEA EAX,[EBP + -0x18]
c.pc=0x31dd2;if(!sl_tick(c))return int(c.fault);
P_31dd2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_31dd2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_31dd2_2:;
goto L_31dd5;
}
L_31dd5:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x31dd5;if(!sl_tick(c))return int(c.fault);
P_31dd5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31dd5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31dd5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31dd5_3:;
goto L_31dd9;
}
L_31dd9:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0x31dd9;if(!sl_tick(c))return int(c.fault);
P_31dd9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_31dd9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31dd9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31dd9_3:;
goto L_31ddc;
}
L_31ddc:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x31ddc;if(!sl_tick(c))return int(c.fault);
P_31ddc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31ddc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31ddc_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31ddc_3:;
goto L_31de0;
}
L_31de0:{ // MOV dword ptr [ESP],ESI
c.pc=0x31de0;if(!sl_tick(c))return int(c.fault);
P_31de0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31de0_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31de0_2:;
goto L_31de3;
}
L_31de3:{ // CALL 0x00013c66
c.pc=0x31de3;if(!sl_tick(c))return int(c.fault);
P_31de3_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31de3_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31de8ULL),c);
P_31de3_2:;
c.pc=0x13c66;goto dispatch;
P_31de3_3:;
goto L_31de8;
}
L_31de8:{ // MOV EAX,dword ptr [EBX + 0xd1a63]
c.pc=0x31de8;if(!sl_tick(c))return int(c.fault);
P_31de8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xd1a63ULL)),c);
P_31de8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_31de8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31de8_3:;
goto L_31dee;
}
L_31dee:{ // ADD EAX,0x8
c.pc=0x31dee;if(!sl_tick(c))return int(c.fault);
P_31dee_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_31dee_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_31dee_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_31dee_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31dee_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_31dee_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_31dee_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31dee_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31dee_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31dee_9:;
goto L_31df1;
}
L_31df1:{ // MOV dword ptr [EBP + -0x18],EAX
c.pc=0x31df1;if(!sl_tick(c))return int(c.fault);
P_31df1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_31df1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31df1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31df1_3:;
goto L_31df4;
}
L_31df4:{ // MOV EAX,dword ptr [ESI]
c.pc=0x31df4;if(!sl_tick(c))return int(c.fault);
P_31df4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_31df4_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31df4_2:;
goto L_31df6;
}
L_31df6:{ // MOV dword ptr [ESP + 0x4],0xffffffff
c.pc=0x31df6;if(!sl_tick(c))return int(c.fault);
P_31df6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31df6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xffffffffULL),c);
P_31df6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_31df6_3:;
goto L_31dfe;
}
L_31dfe:{ // MOV dword ptr [ESP],ESI
c.pc=0x31dfe;if(!sl_tick(c))return int(c.fault);
P_31dfe_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31dfe_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31dfe_2:;
goto L_31e01;
}
L_31e01:{ // CALL dword ptr [EAX + 0x7c]
c.pc=0x31e01;if(!sl_tick(c))return int(c.fault);
P_31e01_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x7cULL)),c);
P_31e01_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31e01_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31e01_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31e01_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31e04ULL),c);
P_31e01_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_31e01_6:;
goto L_31e04;
}
L_31e04:{ // ADD ESP,0x20
c.pc=0x31e04;if(!sl_tick(c))return int(c.fault);
P_31e04_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31e04_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(0x20ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_31e04_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x20ULL)),c);
P_31e04_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31e04_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31e04_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31e04_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31e04_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31e04_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31e04_9:;
goto L_31e07;
}
L_31e07:{ // POP EBX
c.pc=0x31e07;if(!sl_tick(c))return int(c.fault);
P_31e07_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31e07_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31e07_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31e07_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31e07_4:;
goto L_31e08;
}
L_31e08:{ // POP ESI
c.pc=0x31e08;if(!sl_tick(c))return int(c.fault);
P_31e08_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31e08_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31e08_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31e08_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31e08_4:;
goto L_31e09;
}
L_31e09:{ // POP EBP
c.pc=0x31e09;if(!sl_tick(c))return int(c.fault);
P_31e09_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31e09_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31e09_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31e09_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31e09_4:;
goto L_31e0a;
}
L_31e0a:{ // RET
c.pc=0x31e0a;if(!sl_tick(c))return int(c.fault);
P_31e0a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31e0a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31e0a_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_31e0a_3:;
c.pc=0x31e0b;goto dispatch;
}
L_31e14:{ // PUSH EBP
c.pc=0x31e14;if(!sl_tick(c))return int(c.fault);
P_31e14_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_31e14_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31e14_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31e14_3:;
goto L_31e15;
}
L_31e15:{ // MOV EBP,ESP
c.pc=0x31e15;if(!sl_tick(c))return int(c.fault);
P_31e15_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_31e15_1:;
goto L_31e17;
}
L_31e17:{ // PUSH ESI
c.pc=0x31e17;if(!sl_tick(c))return int(c.fault);
P_31e17_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31e17_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31e17_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31e17_3:;
goto L_31e18;
}
L_31e18:{ // PUSH EBX
c.pc=0x31e18;if(!sl_tick(c))return int(c.fault);
P_31e18_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_31e18_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31e18_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31e18_3:;
goto L_31e19;
}
L_31e19:{ // SUB ESP,0x30
c.pc=0x31e19;if(!sl_tick(c))return int(c.fault);
P_31e19_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x30ULL)),c);
P_31e19_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x30ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x30ULL)))&(SlU(1)<<31))!=0),c);
P_31e19_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x30ULL)),c);
P_31e19_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31e19_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31e19_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31e19_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31e19_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31e19_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31e19_9:;
goto L_31e1c;
}
L_31e1c:{ // CALL 0x000c086c
c.pc=0x31e1c;if(!sl_tick(c))return int(c.fault);
P_31e1c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31e1c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31e21ULL),c);
P_31e1c_2:;
c.pc=0xc086c;goto dispatch;
P_31e1c_3:;
goto L_31e21;
}
L_31e21:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0x31e21;if(!sl_tick(c))return int(c.fault);
P_31e21_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31e21_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31e21_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31e21_3:;
goto L_31e24;
}
L_31e24:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0x31e24;if(!sl_tick(c))return int(c.fault);
P_31e24_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_31e24_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31e24_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31e24_3:;
goto L_31e27;
}
L_31e27:{ // MOV EAX,dword ptr [EBX + 0xd19e7]
c.pc=0x31e27;if(!sl_tick(c))return int(c.fault);
P_31e27_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xd19e7ULL)),c);
P_31e27_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_31e27_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31e27_3:;
goto L_31e2d;
}
L_31e2d:{ // ADD EAX,0x8
c.pc=0x31e2d;if(!sl_tick(c))return int(c.fault);
P_31e2d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_31e2d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_31e2d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_31e2d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31e2d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_31e2d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_31e2d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31e2d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31e2d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31e2d_9:;
goto L_31e30;
}
L_31e30:{ // MOV dword ptr [EBP + -0x18],EAX
c.pc=0x31e30;if(!sl_tick(c))return int(c.fault);
P_31e30_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_31e30_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31e30_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31e30_3:;
goto L_31e33;
}
L_31e33:{ // MOVZX EAX,byte ptr [EDX + 0x4]
c.pc=0x31e33;if(!sl_tick(c))return int(c.fault);
P_31e33_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x4ULL)),c);
P_31e33_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31e33_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_31e33_3:;
goto L_31e37;
}
L_31e37:{ // MOV byte ptr [EBP + -0x14],AL
c.pc=0x31e37;if(!sl_tick(c))return int(c.fault);
P_31e37_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_31e37_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,sl_get<1>(c.reg,sizeof(c.reg),0x0,c),c);
P_31e37_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5100,c),c);
P_31e37_3:;
goto L_31e3a;
}
L_31e3a:{ // MOV EAX,dword ptr [EDX + 0x8]
c.pc=0x31e3a;if(!sl_tick(c))return int(c.fault);
P_31e3a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x8ULL)),c);
P_31e3a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31e3a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31e3a_3:;
goto L_31e3d;
}
L_31e3d:{ // MOV dword ptr [EBP + -0x10],EAX
c.pc=0x31e3d;if(!sl_tick(c))return int(c.fault);
P_31e3d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_31e3d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31e3d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31e3d_3:;
goto L_31e40;
}
L_31e40:{ // MOV EAX,dword ptr [EDX + 0xc]
c.pc=0x31e40;if(!sl_tick(c))return int(c.fault);
P_31e40_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0xcULL)),c);
P_31e40_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31e40_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31e40_3:;
goto L_31e43;
}
L_31e43:{ // MOV dword ptr [EBP + -0xc],EAX
c.pc=0x31e43;if(!sl_tick(c))return int(c.fault);
P_31e43_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_31e43_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31e43_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31e43_3:;
goto L_31e46;
}
L_31e46:{ // MOVZX EAX,byte ptr [EBP + 0x18]
c.pc=0x31e46;if(!sl_tick(c))return int(c.fault);
P_31e46_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x18ULL)),c);
P_31e46_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31e46_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_31e46_3:;
goto L_31e4a;
}
L_31e4a:{ // MOV dword ptr [ESP + 0x10],EAX
c.pc=0x31e4a;if(!sl_tick(c))return int(c.fault);
P_31e4a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x10ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31e4a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31e4a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31e4a_3:;
goto L_31e4e;
}
L_31e4e:{ // MOVZX EAX,byte ptr [EBP + 0x14]
c.pc=0x31e4e;if(!sl_tick(c))return int(c.fault);
P_31e4e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_31e4e_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31e4e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_31e4e_3:;
goto L_31e52;
}
L_31e52:{ // MOV dword ptr [ESP + 0xc],EAX
c.pc=0x31e52;if(!sl_tick(c))return int(c.fault);
P_31e52_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31e52_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31e52_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31e52_3:;
goto L_31e56;
}
L_31e56:{ // LEA EAX,[EBP + -0x18]
c.pc=0x31e56;if(!sl_tick(c))return int(c.fault);
P_31e56_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_31e56_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_31e56_2:;
goto L_31e59;
}
L_31e59:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0x31e59;if(!sl_tick(c))return int(c.fault);
P_31e59_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31e59_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31e59_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31e59_3:;
goto L_31e5d;
}
L_31e5d:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0x31e5d;if(!sl_tick(c))return int(c.fault);
P_31e5d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_31e5d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31e5d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31e5d_3:;
goto L_31e60;
}
L_31e60:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x31e60;if(!sl_tick(c))return int(c.fault);
P_31e60_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31e60_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31e60_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31e60_3:;
goto L_31e64;
}
L_31e64:{ // MOV dword ptr [ESP],ESI
c.pc=0x31e64;if(!sl_tick(c))return int(c.fault);
P_31e64_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31e64_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31e64_2:;
goto L_31e67;
}
L_31e67:{ // CALL 0x000141b4
c.pc=0x31e67;if(!sl_tick(c))return int(c.fault);
P_31e67_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31e67_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31e6cULL),c);
P_31e67_2:;
c.pc=0x141b4;goto dispatch;
P_31e67_3:;
goto L_31e6c;
}
L_31e6c:{ // MOV EAX,dword ptr [EBX + 0xd19e7]
c.pc=0x31e6c;if(!sl_tick(c))return int(c.fault);
P_31e6c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xd19e7ULL)),c);
P_31e6c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_31e6c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31e6c_3:;
goto L_31e72;
}
L_31e72:{ // ADD EAX,0x8
c.pc=0x31e72;if(!sl_tick(c))return int(c.fault);
P_31e72_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_31e72_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(0x8ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x8ULL)))&(SlU(1)<<31))!=0),c);
P_31e72_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_31e72_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31e72_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_31e72_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_31e72_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31e72_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31e72_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31e72_9:;
goto L_31e75;
}
L_31e75:{ // MOV dword ptr [EBP + -0x18],EAX
c.pc=0x31e75;if(!sl_tick(c))return int(c.fault);
P_31e75_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_31e75_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31e75_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31e75_3:;
goto L_31e78;
}
L_31e78:{ // MOV EAX,dword ptr [ESI]
c.pc=0x31e78;if(!sl_tick(c))return int(c.fault);
P_31e78_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_31e78_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31e78_2:;
goto L_31e7a;
}
L_31e7a:{ // MOV dword ptr [ESP + 0x4],0xffffffff
c.pc=0x31e7a;if(!sl_tick(c))return int(c.fault);
P_31e7a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31e7a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xffffffffULL),c);
P_31e7a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_31e7a_3:;
goto L_31e82;
}
L_31e82:{ // MOV dword ptr [ESP],ESI
c.pc=0x31e82;if(!sl_tick(c))return int(c.fault);
P_31e82_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31e82_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31e82_2:;
goto L_31e85;
}
L_31e85:{ // CALL dword ptr [EAX + 0x7c]
c.pc=0x31e85;if(!sl_tick(c))return int(c.fault);
P_31e85_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x7cULL)),c);
P_31e85_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31e85_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31e85_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31e85_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31e88ULL),c);
P_31e85_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_31e85_6:;
goto L_31e88;
}
L_31e88:{ // ADD ESP,0x30
c.pc=0x31e88;if(!sl_tick(c))return int(c.fault);
P_31e88_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31e88_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL)))&(SlU(0x30ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL)))&(SlU(1)<<31))!=0),c);
P_31e88_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x30ULL)),c);
P_31e88_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31e88_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31e88_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31e88_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31e88_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31e88_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31e88_9:;
goto L_31e8b;
}
L_31e8b:{ // POP EBX
c.pc=0x31e8b;if(!sl_tick(c))return int(c.fault);
P_31e8b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31e8b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31e8b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31e8b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31e8b_4:;
goto L_31e8c;
}
L_31e8c:{ // POP ESI
c.pc=0x31e8c;if(!sl_tick(c))return int(c.fault);
P_31e8c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31e8c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31e8c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31e8c_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31e8c_4:;
goto L_31e8d;
}
L_31e8d:{ // POP EBP
c.pc=0x31e8d;if(!sl_tick(c))return int(c.fault);
P_31e8d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31e8d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31e8d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31e8d_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31e8d_4:;
goto L_31e8e;
}
L_31e8e:{ // RET
c.pc=0x31e8e;if(!sl_tick(c))return int(c.fault);
P_31e8e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31e8e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31e8e_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_31e8e_3:;
c.pc=0x31e8f;goto dispatch;
}
L_31e98:{ // PUSH EBP
c.pc=0x31e98;if(!sl_tick(c))return int(c.fault);
P_31e98_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_31e98_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31e98_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31e98_3:;
goto L_31e99;
}
L_31e99:{ // MOV EBP,ESP
c.pc=0x31e99;if(!sl_tick(c))return int(c.fault);
P_31e99_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_31e99_1:;
goto L_31e9b;
}
L_31e9b:{ // PUSH ESI
c.pc=0x31e9b;if(!sl_tick(c))return int(c.fault);
P_31e9b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31e9b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31e9b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31e9b_3:;
goto L_31e9c;
}
L_31e9c:{ // PUSH EBX
c.pc=0x31e9c;if(!sl_tick(c))return int(c.fault);
P_31e9c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_31e9c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31e9c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31e9c_3:;
goto L_31e9d;
}
L_31e9d:{ // SUB ESP,0x10
c.pc=0x31e9d;if(!sl_tick(c))return int(c.fault);
P_31e9d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x10ULL)),c);
P_31e9d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x10ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_31e9d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x10ULL)),c);
P_31e9d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31e9d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31e9d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31e9d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31e9d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31e9d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31e9d_9:;
goto L_31ea0;
}
L_31ea0:{ // CALL 0x000c086c
c.pc=0x31ea0;if(!sl_tick(c))return int(c.fault);
P_31ea0_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31ea0_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31ea5ULL),c);
P_31ea0_2:;
c.pc=0xc086c;goto dispatch;
P_31ea0_3:;
goto L_31ea5;
}
L_31ea5:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0x31ea5;if(!sl_tick(c))return int(c.fault);
P_31ea5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31ea5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31ea5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31ea5_3:;
goto L_31ea8;
}
L_31ea8:{ // MOV dword ptr [ESP],ESI
c.pc=0x31ea8;if(!sl_tick(c))return int(c.fault);
P_31ea8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31ea8_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31ea8_2:;
goto L_31eab;
}
L_31eab:{ // CALL 0x00013e4c
c.pc=0x31eab;if(!sl_tick(c))return int(c.fault);
P_31eab_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31eab_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31eb0ULL),c);
P_31eab_2:;
c.pc=0x13e4c;goto dispatch;
P_31eab_3:;
goto L_31eb0;
}
L_31eb0:{ // MOV byte ptr [ESI + 0x1d4],0x0
c.pc=0x31eb0;if(!sl_tick(c))return int(c.fault);
P_31eb0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1d4ULL)),c);
P_31eb0_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_31eb0_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_31eb0_3:;
goto L_31eb7;
}
L_31eb7:{ // MOV dword ptr [ESI + 0x1d8],0x0
c.pc=0x31eb7;if(!sl_tick(c))return int(c.fault);
P_31eb7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1d8ULL)),c);
P_31eb7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_31eb7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_31eb7_3:;
goto L_31ec1;
}
L_31ec1:{ // MOV dword ptr [ESI + 0x1dc],0x0
c.pc=0x31ec1;if(!sl_tick(c))return int(c.fault);
P_31ec1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1dcULL)),c);
P_31ec1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_31ec1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_31ec1_3:;
goto L_31ecb;
}
L_31ecb:{ // LEA EAX,[EBX + 0xb5f23]
c.pc=0x31ecb;if(!sl_tick(c))return int(c.fault);
P_31ecb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xb5f23ULL)),c);
P_31ecb_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_31ecb_2:;
goto L_31ed1;
}
L_31ed1:{ // MOV dword ptr [ESI],EAX
c.pc=0x31ed1;if(!sl_tick(c))return int(c.fault);
P_31ed1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31ed1_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31ed1_2:;
goto L_31ed3;
}
L_31ed3:{ // ADD ESP,0x10
c.pc=0x31ed3;if(!sl_tick(c))return int(c.fault);
P_31ed3_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31ed3_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_31ed3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_31ed3_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31ed3_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31ed3_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31ed3_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31ed3_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31ed3_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31ed3_9:;
goto L_31ed6;
}
L_31ed6:{ // POP EBX
c.pc=0x31ed6;if(!sl_tick(c))return int(c.fault);
P_31ed6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31ed6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31ed6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31ed6_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31ed6_4:;
goto L_31ed7;
}
L_31ed7:{ // POP ESI
c.pc=0x31ed7;if(!sl_tick(c))return int(c.fault);
P_31ed7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31ed7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31ed7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31ed7_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31ed7_4:;
goto L_31ed8;
}
L_31ed8:{ // POP EBP
c.pc=0x31ed8;if(!sl_tick(c))return int(c.fault);
P_31ed8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31ed8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31ed8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31ed8_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31ed8_4:;
goto L_31ed9;
}
L_31ed9:{ // RET
c.pc=0x31ed9;if(!sl_tick(c))return int(c.fault);
P_31ed9_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31ed9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31ed9_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_31ed9_3:;
c.pc=0x31eda;goto dispatch;
}
L_31edc:{ // PUSH EBP
c.pc=0x31edc;if(!sl_tick(c))return int(c.fault);
P_31edc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_31edc_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31edc_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31edc_3:;
goto L_31edd;
}
L_31edd:{ // MOV EBP,ESP
c.pc=0x31edd;if(!sl_tick(c))return int(c.fault);
P_31edd_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_31edd_1:;
goto L_31edf;
}
L_31edf:{ // CALL 0x000c0b42
c.pc=0x31edf;if(!sl_tick(c))return int(c.fault);
P_31edf_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31edf_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31ee4ULL),c);
P_31edf_2:;
c.pc=0xc0b42;goto dispatch;
P_31edf_3:;
goto L_31ee4;
}
L_31ee4:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0x31ee4;if(!sl_tick(c))return int(c.fault);
P_31ee4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31ee4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31ee4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31ee4_3:;
goto L_31ee7;
}
L_31ee7:{ // LEA EAX,[ECX + 0xb5de4]
c.pc=0x31ee7;if(!sl_tick(c))return int(c.fault);
P_31ee7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0xb5de4ULL)),c);
P_31ee7_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_31ee7_2:;
goto L_31eed;
}
L_31eed:{ // MOV dword ptr [EDX],EAX
c.pc=0x31eed;if(!sl_tick(c))return int(c.fault);
P_31eed_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31eed_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31eed_2:;
goto L_31eef;
}
L_31eef:{ // MOV dword ptr [EBP + 0x8],EDX
c.pc=0x31eef;if(!sl_tick(c))return int(c.fault);
P_31eef_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31eef_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_31eef_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31eef_3:;
goto L_31ef2;
}
L_31ef2:{ // POP EBP
c.pc=0x31ef2;if(!sl_tick(c))return int(c.fault);
P_31ef2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31ef2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31ef2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31ef2_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31ef2_4:;
goto L_31ef3;
}
L_31ef3:{ // JMP 0x00013fc0
c.pc=0x31ef3;if(!sl_tick(c))return int(c.fault);
P_31ef3_0:;
c.pc=0x13fc0;goto dispatch;
P_31ef3_1:;
goto L_31ef8;
}
L_31ef8:{ // PUSH EBP
c.pc=0x31ef8;if(!sl_tick(c))return int(c.fault);
P_31ef8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_31ef8_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31ef8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31ef8_3:;
goto L_31ef9;
}
L_31ef9:{ // MOV EBP,ESP
c.pc=0x31ef9;if(!sl_tick(c))return int(c.fault);
P_31ef9_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_31ef9_1:;
goto L_31efb;
}
L_31efb:{ // CALL 0x000c0b42
c.pc=0x31efb;if(!sl_tick(c))return int(c.fault);
P_31efb_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31efb_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31f00ULL),c);
P_31efb_2:;
c.pc=0xc0b42;goto dispatch;
P_31efb_3:;
goto L_31f00;
}
L_31f00:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0x31f00;if(!sl_tick(c))return int(c.fault);
P_31f00_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31f00_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31f00_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31f00_3:;
goto L_31f03;
}
L_31f03:{ // LEA EAX,[ECX + 0xb5dc8]
c.pc=0x31f03;if(!sl_tick(c))return int(c.fault);
P_31f03_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0xb5dc8ULL)),c);
P_31f03_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_31f03_2:;
goto L_31f09;
}
L_31f09:{ // MOV dword ptr [EDX],EAX
c.pc=0x31f09;if(!sl_tick(c))return int(c.fault);
P_31f09_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31f09_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31f09_2:;
goto L_31f0b;
}
L_31f0b:{ // MOV dword ptr [EBP + 0x8],EDX
c.pc=0x31f0b;if(!sl_tick(c))return int(c.fault);
P_31f0b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31f0b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_31f0b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31f0b_3:;
goto L_31f0e;
}
L_31f0e:{ // POP EBP
c.pc=0x31f0e;if(!sl_tick(c))return int(c.fault);
P_31f0e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31f0e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31f0e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31f0e_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31f0e_4:;
goto L_31f0f;
}
L_31f0f:{ // JMP 0x00013fc0
c.pc=0x31f0f;if(!sl_tick(c))return int(c.fault);
P_31f0f_0:;
c.pc=0x13fc0;goto dispatch;
P_31f0f_1:;
goto L_31f14;
}
L_31f14:{ // PUSH EBP
c.pc=0x31f14;if(!sl_tick(c))return int(c.fault);
P_31f14_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_31f14_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31f14_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31f14_3:;
goto L_31f15;
}
L_31f15:{ // MOV EBP,ESP
c.pc=0x31f15;if(!sl_tick(c))return int(c.fault);
P_31f15_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_31f15_1:;
goto L_31f17;
}
L_31f17:{ // PUSH ESI
c.pc=0x31f17;if(!sl_tick(c))return int(c.fault);
P_31f17_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31f17_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31f17_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31f17_3:;
goto L_31f18;
}
L_31f18:{ // PUSH EBX
c.pc=0x31f18;if(!sl_tick(c))return int(c.fault);
P_31f18_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_31f18_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31f18_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31f18_3:;
goto L_31f19;
}
L_31f19:{ // SUB ESP,0x10
c.pc=0x31f19;if(!sl_tick(c))return int(c.fault);
P_31f19_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x10ULL)),c);
P_31f19_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x10ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_31f19_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x10ULL)),c);
P_31f19_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31f19_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31f19_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31f19_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31f19_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31f19_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31f19_9:;
goto L_31f1c;
}
L_31f1c:{ // CALL 0x000c086c
c.pc=0x31f1c;if(!sl_tick(c))return int(c.fault);
P_31f1c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31f1c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31f21ULL),c);
P_31f1c_2:;
c.pc=0xc086c;goto dispatch;
P_31f1c_3:;
goto L_31f21;
}
L_31f21:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0x31f21;if(!sl_tick(c))return int(c.fault);
P_31f21_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31f21_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31f21_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31f21_3:;
goto L_31f24;
}
L_31f24:{ // LEA EAX,[EBX + 0xb5da7]
c.pc=0x31f24;if(!sl_tick(c))return int(c.fault);
P_31f24_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xb5da7ULL)),c);
P_31f24_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_31f24_2:;
goto L_31f2a;
}
L_31f2a:{ // MOV dword ptr [ESI],EAX
c.pc=0x31f2a;if(!sl_tick(c))return int(c.fault);
P_31f2a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31f2a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31f2a_2:;
goto L_31f2c;
}
L_31f2c:{ // MOV dword ptr [ESP],ESI
c.pc=0x31f2c;if(!sl_tick(c))return int(c.fault);
P_31f2c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31f2c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31f2c_2:;
goto L_31f2f;
}
L_31f2f:{ // CALL 0x00013fc0
c.pc=0x31f2f;if(!sl_tick(c))return int(c.fault);
P_31f2f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31f2f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31f34ULL),c);
P_31f2f_2:;
c.pc=0x13fc0;goto dispatch;
P_31f2f_3:;
goto L_31f34;
}
L_31f34:{ // MOV dword ptr [EBP + 0x8],ESI
c.pc=0x31f34;if(!sl_tick(c))return int(c.fault);
P_31f34_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31f34_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31f34_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31f34_3:;
goto L_31f37;
}
L_31f37:{ // ADD ESP,0x10
c.pc=0x31f37;if(!sl_tick(c))return int(c.fault);
P_31f37_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31f37_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_31f37_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_31f37_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31f37_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31f37_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31f37_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31f37_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31f37_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31f37_9:;
goto L_31f3a;
}
L_31f3a:{ // POP EBX
c.pc=0x31f3a;if(!sl_tick(c))return int(c.fault);
P_31f3a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31f3a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31f3a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31f3a_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31f3a_4:;
goto L_31f3b;
}
L_31f3b:{ // POP ESI
c.pc=0x31f3b;if(!sl_tick(c))return int(c.fault);
P_31f3b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31f3b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31f3b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31f3b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31f3b_4:;
goto L_31f3c;
}
L_31f3c:{ // POP EBP
c.pc=0x31f3c;if(!sl_tick(c))return int(c.fault);
P_31f3c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31f3c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31f3c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31f3c_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31f3c_4:;
goto L_31f3d;
}
L_31f3d:{ // JMP 0x00103032
c.pc=0x31f3d;if(!sl_tick(c))return int(c.fault);
P_31f3d_0:;
c.pc=0x103032;goto dispatch;
P_31f3d_1:;
goto L_31f42;
}
L_31f42:{ // PUSH EBP
c.pc=0x31f42;if(!sl_tick(c))return int(c.fault);
P_31f42_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_31f42_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31f42_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31f42_3:;
goto L_31f43;
}
L_31f43:{ // MOV EBP,ESP
c.pc=0x31f43;if(!sl_tick(c))return int(c.fault);
P_31f43_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_31f43_1:;
goto L_31f45;
}
L_31f45:{ // PUSH ESI
c.pc=0x31f45;if(!sl_tick(c))return int(c.fault);
P_31f45_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31f45_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31f45_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31f45_3:;
goto L_31f46;
}
L_31f46:{ // PUSH EBX
c.pc=0x31f46;if(!sl_tick(c))return int(c.fault);
P_31f46_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_31f46_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31f46_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31f46_3:;
goto L_31f47;
}
L_31f47:{ // SUB ESP,0x10
c.pc=0x31f47;if(!sl_tick(c))return int(c.fault);
P_31f47_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x10ULL)),c);
P_31f47_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x10ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_31f47_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x10ULL)),c);
P_31f47_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31f47_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31f47_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31f47_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31f47_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31f47_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31f47_9:;
goto L_31f4a;
}
L_31f4a:{ // CALL 0x000c086c
c.pc=0x31f4a;if(!sl_tick(c))return int(c.fault);
P_31f4a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31f4a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31f4fULL),c);
P_31f4a_2:;
c.pc=0xc086c;goto dispatch;
P_31f4a_3:;
goto L_31f4f;
}
L_31f4f:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0x31f4f;if(!sl_tick(c))return int(c.fault);
P_31f4f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31f4f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31f4f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31f4f_3:;
goto L_31f52;
}
L_31f52:{ // MOV dword ptr [ESP],ESI
c.pc=0x31f52;if(!sl_tick(c))return int(c.fault);
P_31f52_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31f52_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31f52_2:;
goto L_31f55;
}
L_31f55:{ // CALL 0x00013e4c
c.pc=0x31f55;if(!sl_tick(c))return int(c.fault);
P_31f55_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31f55_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31f5aULL),c);
P_31f55_2:;
c.pc=0x13e4c;goto dispatch;
P_31f55_3:;
goto L_31f5a;
}
L_31f5a:{ // MOV byte ptr [ESI + 0x1d4],0x0
c.pc=0x31f5a;if(!sl_tick(c))return int(c.fault);
P_31f5a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1d4ULL)),c);
P_31f5a_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_31f5a_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_31f5a_3:;
goto L_31f61;
}
L_31f61:{ // MOV dword ptr [ESI + 0x1d8],0x0
c.pc=0x31f61;if(!sl_tick(c))return int(c.fault);
P_31f61_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1d8ULL)),c);
P_31f61_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_31f61_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_31f61_3:;
goto L_31f6b;
}
L_31f6b:{ // MOV dword ptr [ESI + 0x1dc],0x0
c.pc=0x31f6b;if(!sl_tick(c))return int(c.fault);
P_31f6b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1dcULL)),c);
P_31f6b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_31f6b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_31f6b_3:;
goto L_31f75;
}
L_31f75:{ // LEA EAX,[EBX + 0xb5f79]
c.pc=0x31f75;if(!sl_tick(c))return int(c.fault);
P_31f75_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xb5f79ULL)),c);
P_31f75_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_31f75_2:;
goto L_31f7b;
}
L_31f7b:{ // MOV dword ptr [ESI],EAX
c.pc=0x31f7b;if(!sl_tick(c))return int(c.fault);
P_31f7b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31f7b_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31f7b_2:;
goto L_31f7d;
}
L_31f7d:{ // ADD ESP,0x10
c.pc=0x31f7d;if(!sl_tick(c))return int(c.fault);
P_31f7d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31f7d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_31f7d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_31f7d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31f7d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31f7d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31f7d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31f7d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31f7d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31f7d_9:;
goto L_31f80;
}
L_31f80:{ // POP EBX
c.pc=0x31f80;if(!sl_tick(c))return int(c.fault);
P_31f80_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31f80_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31f80_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31f80_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31f80_4:;
goto L_31f81;
}
L_31f81:{ // POP ESI
c.pc=0x31f81;if(!sl_tick(c))return int(c.fault);
P_31f81_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31f81_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31f81_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31f81_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31f81_4:;
goto L_31f82;
}
L_31f82:{ // POP EBP
c.pc=0x31f82;if(!sl_tick(c))return int(c.fault);
P_31f82_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31f82_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31f82_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31f82_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31f82_4:;
goto L_31f83;
}
L_31f83:{ // RET
c.pc=0x31f83;if(!sl_tick(c))return int(c.fault);
P_31f83_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31f83_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31f83_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_31f83_3:;
c.pc=0x31f84;goto dispatch;
}
L_31f86:{ // PUSH EBP
c.pc=0x31f86;if(!sl_tick(c))return int(c.fault);
P_31f86_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_31f86_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31f86_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31f86_3:;
goto L_31f87;
}
L_31f87:{ // MOV EBP,ESP
c.pc=0x31f87;if(!sl_tick(c))return int(c.fault);
P_31f87_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_31f87_1:;
goto L_31f89;
}
L_31f89:{ // CALL 0x000c0b42
c.pc=0x31f89;if(!sl_tick(c))return int(c.fault);
P_31f89_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31f89_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31f8eULL),c);
P_31f89_2:;
c.pc=0xc0b42;goto dispatch;
P_31f89_3:;
goto L_31f8e;
}
L_31f8e:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0x31f8e;if(!sl_tick(c))return int(c.fault);
P_31f8e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31f8e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31f8e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31f8e_3:;
goto L_31f91;
}
L_31f91:{ // LEA EAX,[ECX + 0xb5d3a]
c.pc=0x31f91;if(!sl_tick(c))return int(c.fault);
P_31f91_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0xb5d3aULL)),c);
P_31f91_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_31f91_2:;
goto L_31f97;
}
L_31f97:{ // MOV dword ptr [EDX],EAX
c.pc=0x31f97;if(!sl_tick(c))return int(c.fault);
P_31f97_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31f97_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31f97_2:;
goto L_31f99;
}
L_31f99:{ // MOV dword ptr [EBP + 0x8],EDX
c.pc=0x31f99;if(!sl_tick(c))return int(c.fault);
P_31f99_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31f99_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_31f99_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31f99_3:;
goto L_31f9c;
}
L_31f9c:{ // POP EBP
c.pc=0x31f9c;if(!sl_tick(c))return int(c.fault);
P_31f9c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31f9c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31f9c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31f9c_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31f9c_4:;
goto L_31f9d;
}
L_31f9d:{ // JMP 0x00013fc0
c.pc=0x31f9d;if(!sl_tick(c))return int(c.fault);
P_31f9d_0:;
c.pc=0x13fc0;goto dispatch;
P_31f9d_1:;
goto L_31fa2;
}
L_31fa2:{ // PUSH EBP
c.pc=0x31fa2;if(!sl_tick(c))return int(c.fault);
P_31fa2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_31fa2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31fa2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31fa2_3:;
goto L_31fa3;
}
L_31fa3:{ // MOV EBP,ESP
c.pc=0x31fa3;if(!sl_tick(c))return int(c.fault);
P_31fa3_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_31fa3_1:;
goto L_31fa5;
}
L_31fa5:{ // CALL 0x000c0b42
c.pc=0x31fa5;if(!sl_tick(c))return int(c.fault);
P_31fa5_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31fa5_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31faaULL),c);
P_31fa5_2:;
c.pc=0xc0b42;goto dispatch;
P_31fa5_3:;
goto L_31faa;
}
L_31faa:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0x31faa;if(!sl_tick(c))return int(c.fault);
P_31faa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31faa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31faa_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31faa_3:;
goto L_31fad;
}
L_31fad:{ // LEA EAX,[ECX + 0xb5d1e]
c.pc=0x31fad;if(!sl_tick(c))return int(c.fault);
P_31fad_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0xb5d1eULL)),c);
P_31fad_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_31fad_2:;
goto L_31fb3;
}
L_31fb3:{ // MOV dword ptr [EDX],EAX
c.pc=0x31fb3;if(!sl_tick(c))return int(c.fault);
P_31fb3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31fb3_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31fb3_2:;
goto L_31fb5;
}
L_31fb5:{ // MOV dword ptr [EBP + 0x8],EDX
c.pc=0x31fb5;if(!sl_tick(c))return int(c.fault);
P_31fb5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31fb5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_31fb5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31fb5_3:;
goto L_31fb8;
}
L_31fb8:{ // POP EBP
c.pc=0x31fb8;if(!sl_tick(c))return int(c.fault);
P_31fb8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31fb8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31fb8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31fb8_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31fb8_4:;
goto L_31fb9;
}
L_31fb9:{ // JMP 0x00013fc0
c.pc=0x31fb9;if(!sl_tick(c))return int(c.fault);
P_31fb9_0:;
c.pc=0x13fc0;goto dispatch;
P_31fb9_1:;
goto L_31fbe;
}
L_31fbe:{ // PUSH EBP
c.pc=0x31fbe;if(!sl_tick(c))return int(c.fault);
P_31fbe_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_31fbe_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31fbe_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31fbe_3:;
goto L_31fbf;
}
L_31fbf:{ // MOV EBP,ESP
c.pc=0x31fbf;if(!sl_tick(c))return int(c.fault);
P_31fbf_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_31fbf_1:;
goto L_31fc1;
}
L_31fc1:{ // PUSH ESI
c.pc=0x31fc1;if(!sl_tick(c))return int(c.fault);
P_31fc1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31fc1_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31fc1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31fc1_3:;
goto L_31fc2;
}
L_31fc2:{ // PUSH EBX
c.pc=0x31fc2;if(!sl_tick(c))return int(c.fault);
P_31fc2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_31fc2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31fc2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31fc2_3:;
goto L_31fc3;
}
L_31fc3:{ // SUB ESP,0x10
c.pc=0x31fc3;if(!sl_tick(c))return int(c.fault);
P_31fc3_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x10ULL)),c);
P_31fc3_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x10ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_31fc3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x10ULL)),c);
P_31fc3_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31fc3_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31fc3_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31fc3_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31fc3_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31fc3_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31fc3_9:;
goto L_31fc6;
}
L_31fc6:{ // CALL 0x000c086c
c.pc=0x31fc6;if(!sl_tick(c))return int(c.fault);
P_31fc6_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31fc6_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31fcbULL),c);
P_31fc6_2:;
c.pc=0xc086c;goto dispatch;
P_31fc6_3:;
goto L_31fcb;
}
L_31fcb:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0x31fcb;if(!sl_tick(c))return int(c.fault);
P_31fcb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31fcb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31fcb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31fcb_3:;
goto L_31fce;
}
L_31fce:{ // LEA EAX,[EBX + 0xb5cfd]
c.pc=0x31fce;if(!sl_tick(c))return int(c.fault);
P_31fce_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xb5cfdULL)),c);
P_31fce_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_31fce_2:;
goto L_31fd4;
}
L_31fd4:{ // MOV dword ptr [ESI],EAX
c.pc=0x31fd4;if(!sl_tick(c))return int(c.fault);
P_31fd4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_31fd4_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31fd4_2:;
goto L_31fd6;
}
L_31fd6:{ // MOV dword ptr [ESP],ESI
c.pc=0x31fd6;if(!sl_tick(c))return int(c.fault);
P_31fd6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31fd6_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31fd6_2:;
goto L_31fd9;
}
L_31fd9:{ // CALL 0x00013fc0
c.pc=0x31fd9;if(!sl_tick(c))return int(c.fault);
P_31fd9_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31fd9_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31fdeULL),c);
P_31fd9_2:;
c.pc=0x13fc0;goto dispatch;
P_31fd9_3:;
goto L_31fde;
}
L_31fde:{ // MOV dword ptr [EBP + 0x8],ESI
c.pc=0x31fde;if(!sl_tick(c))return int(c.fault);
P_31fde_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31fde_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31fde_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31fde_3:;
goto L_31fe1;
}
L_31fe1:{ // ADD ESP,0x10
c.pc=0x31fe1;if(!sl_tick(c))return int(c.fault);
P_31fe1_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_31fe1_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_31fe1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_31fe1_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31fe1_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31fe1_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31fe1_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31fe1_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31fe1_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31fe1_9:;
goto L_31fe4;
}
L_31fe4:{ // POP EBX
c.pc=0x31fe4;if(!sl_tick(c))return int(c.fault);
P_31fe4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31fe4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31fe4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31fe4_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31fe4_4:;
goto L_31fe5;
}
L_31fe5:{ // POP ESI
c.pc=0x31fe5;if(!sl_tick(c))return int(c.fault);
P_31fe5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31fe5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31fe5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31fe5_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31fe5_4:;
goto L_31fe6;
}
L_31fe6:{ // POP EBP
c.pc=0x31fe6;if(!sl_tick(c))return int(c.fault);
P_31fe6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_31fe6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_31fe6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_31fe6_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_31fe6_4:;
goto L_31fe7;
}
L_31fe7:{ // JMP 0x00103032
c.pc=0x31fe7;if(!sl_tick(c))return int(c.fault);
P_31fe7_0:;
c.pc=0x103032;goto dispatch;
P_31fe7_1:;
goto L_31fec;
}
L_31fec:{ // PUSH EBP
c.pc=0x31fec;if(!sl_tick(c))return int(c.fault);
P_31fec_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_31fec_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31fec_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31fec_3:;
goto L_31fed;
}
L_31fed:{ // MOV EBP,ESP
c.pc=0x31fed;if(!sl_tick(c))return int(c.fault);
P_31fed_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_31fed_1:;
goto L_31fef;
}
L_31fef:{ // PUSH ESI
c.pc=0x31fef;if(!sl_tick(c))return int(c.fault);
P_31fef_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31fef_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31fef_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31fef_3:;
goto L_31ff0;
}
L_31ff0:{ // PUSH EBX
c.pc=0x31ff0;if(!sl_tick(c))return int(c.fault);
P_31ff0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_31ff0_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31ff0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_31ff0_3:;
goto L_31ff1;
}
L_31ff1:{ // SUB ESP,0x10
c.pc=0x31ff1;if(!sl_tick(c))return int(c.fault);
P_31ff1_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x10ULL)),c);
P_31ff1_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x10ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_31ff1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x10ULL)),c);
P_31ff1_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_31ff1_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_31ff1_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_31ff1_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_31ff1_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_31ff1_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_31ff1_9:;
goto L_31ff4;
}
L_31ff4:{ // CALL 0x000c086c
c.pc=0x31ff4;if(!sl_tick(c))return int(c.fault);
P_31ff4_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31ff4_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x31ff9ULL),c);
P_31ff4_2:;
c.pc=0xc086c;goto dispatch;
P_31ff4_3:;
goto L_31ff9;
}
L_31ff9:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0x31ff9;if(!sl_tick(c))return int(c.fault);
P_31ff9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_31ff9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_31ff9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_31ff9_3:;
goto L_31ffc;
}
L_31ffc:{ // MOV dword ptr [ESP],ESI
c.pc=0x31ffc;if(!sl_tick(c))return int(c.fault);
P_31ffc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_31ffc_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_31ffc_2:;
goto L_31fff;
}
L_31fff:{ // CALL 0x00013e4c
c.pc=0x31fff;if(!sl_tick(c))return int(c.fault);
P_31fff_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_31fff_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x32004ULL),c);
P_31fff_2:;
c.pc=0x13e4c;goto dispatch;
P_31fff_3:;
goto L_32004;
}
L_32004:{ // LEA EAX,[EBX + 0xb5fef]
c.pc=0x32004;if(!sl_tick(c))return int(c.fault);
P_32004_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xb5fefULL)),c);
P_32004_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_32004_2:;
goto L_3200a;
}
L_3200a:{ // MOV dword ptr [ESI],EAX
c.pc=0x3200a;if(!sl_tick(c))return int(c.fault);
P_3200a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_3200a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_3200a_2:;
goto L_3200c;
}
L_3200c:{ // ADD ESP,0x10
c.pc=0x3200c;if(!sl_tick(c))return int(c.fault);
P_3200c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_3200c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_3200c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_3200c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_3200c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_3200c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_3200c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_3200c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_3200c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_3200c_9:;
goto L_3200f;
}
L_3200f:{ // POP EBX
c.pc=0x3200f;if(!sl_tick(c))return int(c.fault);
P_3200f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_3200f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_3200f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_3200f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_3200f_4:;
goto L_32010;
}
L_32010:{ // POP ESI
c.pc=0x32010;if(!sl_tick(c))return int(c.fault);
P_32010_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_32010_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_32010_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_32010_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_32010_4:;
goto L_32011;
}
L_32011:{ // POP EBP
c.pc=0x32011;if(!sl_tick(c))return int(c.fault);
P_32011_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_32011_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_32011_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_32011_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_32011_4:;
goto L_32012;
}
L_32012:{ // RET
c.pc=0x32012;if(!sl_tick(c))return int(c.fault);
P_32012_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_32012_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_32012_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_32012_3:;
c.pc=0x32013;goto dispatch;
}
L_32014:{ // PUSH EBP
c.pc=0x32014;if(!sl_tick(c))return int(c.fault);
P_32014_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_32014_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_32014_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_32014_3:;
goto L_32015;
}
L_32015:{ // MOV EBP,ESP
c.pc=0x32015;if(!sl_tick(c))return int(c.fault);
P_32015_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_32015_1:;
goto L_32017;
}
L_32017:{ // CALL 0x000c0b42
c.pc=0x32017;if(!sl_tick(c))return int(c.fault);
P_32017_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_32017_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x3201cULL),c);
P_32017_2:;
c.pc=0xc0b42;goto dispatch;
P_32017_3:;
goto L_3201c;
}
L_3201c:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0x3201c;if(!sl_tick(c))return int(c.fault);
P_3201c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_3201c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_3201c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_3201c_3:;
goto L_3201f;
}
L_3201f:{ // LEA EAX,[ECX + 0xb5fcc]
c.pc=0x3201f;if(!sl_tick(c))return int(c.fault);
P_3201f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0xb5fccULL)),c);
P_3201f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_3201f_2:;
goto L_32025;
}
L_32025:{ // MOV dword ptr [EDX],EAX
c.pc=0x32025;if(!sl_tick(c))return int(c.fault);
P_32025_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_32025_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_32025_2:;
goto L_32027;
}
L_32027:{ // MOV dword ptr [EBP + 0x8],EDX
c.pc=0x32027;if(!sl_tick(c))return int(c.fault);
P_32027_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_32027_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_32027_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_32027_3:;
goto L_3202a;
}
L_3202a:{ // POP EBP
c.pc=0x3202a;if(!sl_tick(c))return int(c.fault);
P_3202a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_3202a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_3202a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_3202a_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_3202a_4:;
goto L_3202b;
}
L_3202b:{ // JMP 0x00013fc0
c.pc=0x3202b;if(!sl_tick(c))return int(c.fault);
P_3202b_0:;
c.pc=0x13fc0;goto dispatch;
P_3202b_1:;
goto L_32030;
}
L_32030:{ // PUSH EBP
c.pc=0x32030;if(!sl_tick(c))return int(c.fault);
P_32030_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_32030_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_32030_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_32030_3:;
goto L_32031;
}
L_32031:{ // MOV EBP,ESP
c.pc=0x32031;if(!sl_tick(c))return int(c.fault);
P_32031_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_32031_1:;
goto L_32033;
}
L_32033:{ // CALL 0x000c0b42
c.pc=0x32033;if(!sl_tick(c))return int(c.fault);
P_32033_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_32033_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x32038ULL),c);
P_32033_2:;
c.pc=0xc0b42;goto dispatch;
P_32033_3:;
goto L_32038;
}
L_32038:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0x32038;if(!sl_tick(c))return int(c.fault);
P_32038_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_32038_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_32038_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_32038_3:;
goto L_3203b;
}
L_3203b:{ // LEA EAX,[ECX + 0xb5fb0]
c.pc=0x3203b;if(!sl_tick(c))return int(c.fault);
P_3203b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0xb5fb0ULL)),c);
P_3203b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_3203b_2:;
goto L_32041;
}
L_32041:{ // MOV dword ptr [EDX],EAX
c.pc=0x32041;if(!sl_tick(c))return int(c.fault);
P_32041_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_32041_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_32041_2:;
goto L_32043;
}
L_32043:{ // MOV dword ptr [EBP + 0x8],EDX
c.pc=0x32043;if(!sl_tick(c))return int(c.fault);
P_32043_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_32043_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_32043_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_32043_3:;
goto L_32046;
}
L_32046:{ // POP EBP
c.pc=0x32046;if(!sl_tick(c))return int(c.fault);
P_32046_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_32046_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_32046_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_32046_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_32046_4:;
goto L_32047;
}
L_32047:{ // JMP 0x00013fc0
c.pc=0x32047;if(!sl_tick(c))return int(c.fault);
P_32047_0:;
c.pc=0x13fc0;goto dispatch;
P_32047_1:;
goto L_3204c;
}
L_3204c:{ // PUSH EBP
c.pc=0x3204c;if(!sl_tick(c))return int(c.fault);
P_3204c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_3204c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_3204c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_3204c_3:;
goto L_3204d;
}
L_3204d:{ // MOV EBP,ESP
c.pc=0x3204d;if(!sl_tick(c))return int(c.fault);
P_3204d_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_3204d_1:;
goto L_3204f;
}
L_3204f:{ // PUSH ESI
c.pc=0x3204f;if(!sl_tick(c))return int(c.fault);
P_3204f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_3204f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_3204f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_3204f_3:;
goto L_32050;
}
L_32050:{ // PUSH EBX
c.pc=0x32050;if(!sl_tick(c))return int(c.fault);
P_32050_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_32050_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_32050_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_32050_3:;
goto L_32051;
}
L_32051:{ // SUB ESP,0x10
c.pc=0x32051;if(!sl_tick(c))return int(c.fault);
P_32051_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x10ULL)),c);
P_32051_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x10ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_32051_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x10ULL)),c);
P_32051_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32051_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_32051_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_32051_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32051_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32051_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32051_9:;
goto L_32054;
}
L_32054:{ // CALL 0x000c086c
c.pc=0x32054;if(!sl_tick(c))return int(c.fault);
P_32054_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_32054_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x32059ULL),c);
P_32054_2:;
c.pc=0xc086c;goto dispatch;
P_32054_3:;
goto L_32059;
}
L_32059:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0x32059;if(!sl_tick(c))return int(c.fault);
P_32059_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_32059_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_32059_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_32059_3:;
goto L_3205c;
}
L_3205c:{ // LEA EAX,[EBX + 0xb5f8f]
c.pc=0x3205c;if(!sl_tick(c))return int(c.fault);
P_3205c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xb5f8fULL)),c);
P_3205c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_3205c_2:;
goto L_32062;
}
L_32062:{ // MOV dword ptr [ESI],EAX
c.pc=0x32062;if(!sl_tick(c))return int(c.fault);
P_32062_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_32062_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_32062_2:;
goto L_32064;
}
L_32064:{ // MOV dword ptr [ESP],ESI
c.pc=0x32064;if(!sl_tick(c))return int(c.fault);
P_32064_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_32064_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_32064_2:;
goto L_32067;
}
L_32067:{ // CALL 0x00013fc0
c.pc=0x32067;if(!sl_tick(c))return int(c.fault);
P_32067_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_32067_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x3206cULL),c);
P_32067_2:;
c.pc=0x13fc0;goto dispatch;
P_32067_3:;
goto L_3206c;
}
L_3206c:{ // MOV dword ptr [EBP + 0x8],ESI
c.pc=0x3206c;if(!sl_tick(c))return int(c.fault);
P_3206c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_3206c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_3206c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_3206c_3:;
goto L_3206f;
}
L_3206f:{ // ADD ESP,0x10
c.pc=0x3206f;if(!sl_tick(c))return int(c.fault);
P_3206f_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_3206f_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_3206f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_3206f_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_3206f_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_3206f_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_3206f_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_3206f_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_3206f_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_3206f_9:;
goto L_32072;
}
L_32072:{ // POP EBX
c.pc=0x32072;if(!sl_tick(c))return int(c.fault);
P_32072_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_32072_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_32072_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_32072_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_32072_4:;
goto L_32073;
}
L_32073:{ // POP ESI
c.pc=0x32073;if(!sl_tick(c))return int(c.fault);
P_32073_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_32073_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_32073_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_32073_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_32073_4:;
goto L_32074;
}
L_32074:{ // POP EBP
c.pc=0x32074;if(!sl_tick(c))return int(c.fault);
P_32074_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_32074_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_32074_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_32074_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_32074_4:;
goto L_32075;
}
L_32075:{ // JMP 0x00103032
c.pc=0x32075;if(!sl_tick(c))return int(c.fault);
P_32075_0:;
c.pc=0x103032;goto dispatch;
P_32075_1:;
goto L_3207a;
}
L_3207a:{ // PUSH EBP
c.pc=0x3207a;if(!sl_tick(c))return int(c.fault);
P_3207a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_3207a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_3207a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_3207a_3:;
goto L_3207b;
}
L_3207b:{ // MOV EBP,ESP
c.pc=0x3207b;if(!sl_tick(c))return int(c.fault);
P_3207b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_3207b_1:;
goto L_3207d;
}
L_3207d:{ // PUSH EDI
c.pc=0x3207d;if(!sl_tick(c))return int(c.fault);
P_3207d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_3207d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_3207d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_3207d_3:;
goto L_3207e;
}
L_3207e:{ // PUSH ESI
c.pc=0x3207e;if(!sl_tick(c))return int(c.fault);
P_3207e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_3207e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_3207e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_3207e_3:;
goto L_3207f;
}
L_3207f:{ // PUSH EBX
c.pc=0x3207f;if(!sl_tick(c))return int(c.fault);
P_3207f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_3207f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_3207f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_3207f_3:;
goto L_32080;
}
L_32080:{ // SUB ESP,0x4c
c.pc=0x32080;if(!sl_tick(c))return int(c.fault);
P_32080_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x4cULL)),c);
P_32080_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x4cULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x4cULL)))&(SlU(1)<<31))!=0),c);
P_32080_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4cULL)),c);
P_32080_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32080_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_32080_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_32080_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32080_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32080_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32080_9:;
goto L_32083;
}
L_32083:{ // CALL 0x000c086c
c.pc=0x32083;if(!sl_tick(c))return int(c.fault);
P_32083_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_32083_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x32088ULL),c);
P_32083_2:;
c.pc=0xc086c;goto dispatch;
P_32083_3:;
goto L_32088;
}
L_32088:{ // MOV EDI,dword ptr [EBP + 0x10]
c.pc=0x32088;if(!sl_tick(c))return int(c.fault);
P_32088_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_32088_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_32088_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_32088_3:;
goto L_3208b;
}
L_3208b:{ // MOVSD XMM2,qword ptr [EBP + 0x14]
c.pc=0x3208b;if(!sl_tick(c))return int(c.fault);
P_3208b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_3208b_1:;
sl_put<8>(c.temp,sizeof(c.temp),0x5280,sl_get<8>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_3208b_2:;
sl_put<8>(c.reg,sizeof(c.reg),0x1280,sl_get<8>(c.temp,sizeof(c.temp),0x5280,c),c);
P_3208b_3:;
sl_put<8>(c.reg,sizeof(c.reg),0x1288,SlU(0x0ULL),c);
P_3208b_4:;
goto L_32090;
}
L_32090:{ // CMP EDI,0x3ff
c.pc=0x32090;if(!sl_tick(c))return int(c.fault);
P_32090_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30a80,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_32090_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) < SlU(0x3ffULL)),c);
P_32090_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^SlU(0x3ffULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)-SlU(0x3ffULL)))&(SlU(1)<<31))!=0),c);
P_32090_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30b80,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) - SlU(0x3ffULL)),c);
P_32090_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32090_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) == SlU(0x0ULL)),c);
P_32090_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) & SlU(0xffULL)),c);
P_32090_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32090_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32090_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32090_10:;
goto L_32096;
}
L_32096:{ // JG 0x000321e5
c.pc=0x32096;if(!sl_tick(c))return int(c.fault);
P_32096_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_32096_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_32096_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_32096_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_321e5;}
P_32096_4:;
goto L_3209c;
}
L_3209c:{ // CMP EDI,0xff
c.pc=0x3209c;if(!sl_tick(c))return int(c.fault);
P_3209c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30a80,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_3209c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) < SlU(0xffULL)),c);
P_3209c_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^SlU(0xffULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)-SlU(0xffULL)))&(SlU(1)<<31))!=0),c);
P_3209c_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30b80,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) - SlU(0xffULL)),c);
P_3209c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_3209c_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) == SlU(0x0ULL)),c);
P_3209c_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) & SlU(0xffULL)),c);
P_3209c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_3209c_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_3209c_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_3209c_10:;
goto L_320a2;
}
L_320a2:{ // JG 0x0003224c
c.pc=0x320a2;if(!sl_tick(c))return int(c.fault);
P_320a2_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_320a2_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_320a2_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_320a2_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_3224c;}
P_320a2_4:;
goto L_320a8;
}
L_320a8:{ // CMP EDI,0x7f
c.pc=0x320a8;if(!sl_tick(c))return int(c.fault);
P_320a8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_320a8_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x7fULL)),c);
P_320a8_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x7fULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x7fULL)))&(SlU(1)<<31))!=0),c);
P_320a8_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x7fULL)),c);
P_320a8_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_320a8_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_320a8_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_320a8_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_320a8_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_320a8_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_320a8_10:;
goto L_320ab;
}
L_320ab:{ // JG 0x0003223f
c.pc=0x320ab;if(!sl_tick(c))return int(c.fault);
P_320ab_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_320ab_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_320ab_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_320ab_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_3223f;}
P_320ab_4:;
goto L_320b1;
}
L_320b1:{ // MOVSS XMM1,dword ptr [EBX + 0x96a08]
c.pc=0x320b1;if(!sl_tick(c))return int(c.fault);
P_320b1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x96a08ULL)),c);
P_320b1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_320b1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_320b1_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_320b1_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_320b1_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_320b1_6:;
goto L_320b9;
}
L_320b9:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0x320b9;if(!sl_tick(c))return int(c.fault);
P_320b9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_320b9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_320b9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_320b9_3:;
goto L_320bc;
}
L_320bc:{ // TEST EAX,EAX
c.pc=0x320bc;if(!sl_tick(c))return int(c.fault);
P_320bc_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_320bc_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_320bc_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_320bc_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_320bc_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_320bc_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_320bc_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_320bc_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_320bc_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_320bc_9:;
goto L_320be;
}
L_320be:{ // JZ 0x000321dd
c.pc=0x320be;if(!sl_tick(c))return int(c.fault);
P_320be_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_321dd;}
P_320be_1:;
goto L_320c4;
}
L_320c4:{ // CMP EDI,0x28
c.pc=0x320c4;if(!sl_tick(c))return int(c.fault);
P_320c4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_320c4_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x28ULL)),c);
P_320c4_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x28ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x28ULL)))&(SlU(1)<<31))!=0),c);
P_320c4_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x28ULL)),c);
P_320c4_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_320c4_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_320c4_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_320c4_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_320c4_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_320c4_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_320c4_10:;
goto L_320c7;
}
L_320c7:{ // JLE 0x000321dd
c.pc=0x320c7;if(!sl_tick(c))return int(c.fault);
P_320c7_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_320c7_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_320c7_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_321dd;}
P_320c7_3:;
goto L_320cd;
}
L_320cd:{ // CVTSI2SS XMM0,EDI
c.pc=0x320cd;if(!sl_tick(c))return int(c.fault);
P_320cd_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<float>(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),32))),c);
P_320cd_1:;
goto L_320d1;
}
L_320d1:{ // MULSS XMM1,XMM0
c.pc=0x320d1;if(!sl_tick(c))return int(c.fault);
P_320d1_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_320d1_1:;
goto L_320d5;
}
L_320d5:{ // ADDSS XMM1,dword ptr [EBX + 0x969a4]
c.pc=0x320d5;if(!sl_tick(c))return int(c.fault);
P_320d5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x969a4ULL)),c);
P_320d5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_320d5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) + sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_320d5_3:;
goto L_320dd;
}
L_320dd:{ // CVTTSS2SI ESI,XMM1
c.pc=0x320dd;if(!sl_tick(c))return int(c.fault);
P_320dd_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_trunc_fp(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),4,32),c);
P_320dd_1:;
goto L_320e1;
}
L_320e1:{ // TEST ESI,ESI
c.pc=0x320e1;if(!sl_tick(c))return int(c.fault);
P_320e1_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_320e1_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_320e1_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_320e1_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_320e1_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_320e1_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_320e1_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_320e1_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_320e1_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_320e1_9:;
goto L_320e3;
}
L_320e3:{ // JLE 0x0003222e
c.pc=0x320e3;if(!sl_tick(c))return int(c.fault);
P_320e3_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_320e3_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_320e3_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_3222e;}
P_320e3_3:;
goto L_320e9;
}
L_320e9:{ // LEA EAX,[ESI + -0x1]
c.pc=0x320e9;if(!sl_tick(c))return int(c.fault);
P_320e9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0xffffffffULL)),c);
P_320e9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_320e9_2:;
goto L_320ec;
}
L_320ec:{ // MOV dword ptr [EBP + -0x1c],EAX
c.pc=0x320ec;if(!sl_tick(c))return int(c.fault);
P_320ec_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_320ec_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_320ec_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_320ec_3:;
goto L_320ef;
}
L_320ef:{ // MOV EDX,EDI
c.pc=0x320ef;if(!sl_tick(c))return int(c.fault);
P_320ef_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_320ef_1:;
goto L_320f1;
}
L_320f1:{ // SUB EDX,ESI
c.pc=0x320f1;if(!sl_tick(c))return int(c.fault);
P_320f1_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) < sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_320f1_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^sl_get<4>(c.reg,sizeof(c.reg),0x18,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)-sl_get<4>(c.reg,sizeof(c.reg),0x18,c)))&(SlU(1)<<31))!=0),c);
P_320f1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) - sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_320f1_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_320f1_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_320f1_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_320f1_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_320f1_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_320f1_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_320f1_9:;
goto L_320f3;
}
L_320f3:{ // MOV dword ptr [EBP + -0x20],EDX
c.pc=0x320f3;if(!sl_tick(c))return int(c.fault);
P_320f3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_320f3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_320f3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_320f3_3:;
goto L_320f6;
}
L_320f6:{ // CVTSI2SD XMM0,EDX
c.pc=0x320f6;if(!sl_tick(c))return int(c.fault);
P_320f6_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<double>(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32))),c);
P_320f6_1:;
goto L_320fa;
}
L_320fa:{ // DIVSD XMM2,XMM0
c.pc=0x320fa;if(!sl_tick(c))return int(c.fault);
P_320fa_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1280,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1280,c)) / sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_320fa_1:;
goto L_320fe;
}
L_320fe:{ // CVTSD2SS XMM5,XMM2
c.pc=0x320fe;if(!sl_tick(c))return int(c.fault);
P_320fe_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1340,sl_bits(static_cast<float>(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1280,c)))),c);
P_320fe_1:;
goto L_32102;
}
L_32102:{ // MOVAPS XMM0,XMM5
c.pc=0x32102;if(!sl_tick(c))return int(c.fault);
P_32102_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x1340,c),c);
P_32102_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x1344,c),c);
P_32102_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x1348,c),c);
P_32102_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x134c,c),c);
P_32102_4:;
goto L_32105;
}
L_32105:{ // ANDPS XMM0,xmmword ptr [EBX + 0xaf938]
c.pc=0x32105;if(!sl_tick(c))return int(c.fault);
P_32105_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0xaf938ULL)),c);
P_32105_1:;
sl_put<16>(c.temp,sizeof(c.temp),0x5300,sl_get<16>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_32105_2:;
sl_put<16>(c.temp,sizeof(c.temp),0x61680,sl_get<16>(c.temp,sizeof(c.temp),0x5300,c),c);
P_32105_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x61700,sl_rshift(sl_get<16>(c.temp,sizeof(c.temp),0x61680,c),8*SlU(0x0ULL)),c);
P_32105_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c) & sl_get<4>(c.temp,sizeof(c.temp),0x61700,c)),c);
P_32105_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x61800,sl_rshift(sl_get<16>(c.temp,sizeof(c.temp),0x61680,c),8*SlU(0x4ULL)),c);
P_32105_6:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,(sl_get<4>(c.reg,sizeof(c.reg),0x1204,c) & sl_get<4>(c.temp,sizeof(c.temp),0x61800,c)),c);
P_32105_7:;
sl_put<4>(c.temp,sizeof(c.temp),0x61900,sl_rshift(sl_get<16>(c.temp,sizeof(c.temp),0x61680,c),8*SlU(0x8ULL)),c);
P_32105_8:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,(sl_get<4>(c.reg,sizeof(c.reg),0x1208,c) & sl_get<4>(c.temp,sizeof(c.temp),0x61900,c)),c);
P_32105_9:;
sl_put<4>(c.temp,sizeof(c.temp),0x61a00,sl_rshift(sl_get<16>(c.temp,sizeof(c.temp),0x61680,c),8*SlU(0xcULL)),c);
P_32105_10:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,(sl_get<4>(c.reg,sizeof(c.reg),0x120c,c) & sl_get<4>(c.temp,sizeof(c.temp),0x61a00,c)),c);
P_32105_11:;
goto L_3210c;
}
L_3210c:{ // MOVSS XMM1,dword ptr [EBX + 0x9699c]
c.pc=0x3210c;if(!sl_tick(c))return int(c.fault);
P_3210c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x9699cULL)),c);
P_3210c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_3210c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_3210c_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_3210c_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_3210c_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_3210c_6:;
goto L_32114;
}
L_32114:{ // ADDSS XMM0,XMM1
c.pc=0x32114;if(!sl_tick(c))return int(c.fault);
P_32114_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_32114_1:;
goto L_32118;
}
L_32118:{ // MOVSS dword ptr [ESP + 0x4],XMM0
c.pc=0x32118;if(!sl_tick(c))return int(c.fault);
P_32118_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_32118_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_32118_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_32118_3:;
goto L_3211e;
}
L_3211e:{ // MOVSS dword ptr [ESP],XMM1
c.pc=0x3211e;if(!sl_tick(c))return int(c.fault);
P_3211e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_3211e_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_3211e_2:;
goto L_32123;
}
L_32123:{ // MOVSS dword ptr [EBP + -0x38],XMM5
c.pc=0x32123;if(!sl_tick(c))return int(c.fault);
P_32123_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc8ULL)),c);
P_32123_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1340,c),c);
P_32123_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_32123_3:;
goto L_32128;
}
L_32128:{ // CALL 0x000152c0
c.pc=0x32128;if(!sl_tick(c))return int(c.fault);
P_32128_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_32128_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x3212dULL),c);
P_32128_2:;
c.pc=0x152c0;goto dispatch;
P_32128_3:;
goto L_3212d;
}
L_3212d:{ // FSTP dword ptr [EBP + -0x3c]
c.pc=0x3212d;if(!sl_tick(c))return int(c.fault);
P_3212d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc4ULL)),c);
P_3212d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_ext80_to_f32(sl_get<10>(c.reg,sizeof(c.reg),0x1100,c)),c);
P_3212d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_3212d_3:;
sl_put<10>(c.reg,sizeof(c.reg),0x1100,sl_get<10>(c.reg,sizeof(c.reg),0x1110,c),c);
P_3212d_4:;
sl_put<10>(c.reg,sizeof(c.reg),0x1110,sl_get<10>(c.reg,sizeof(c.reg),0x1120,c),c);
P_3212d_5:;
sl_put<10>(c.reg,sizeof(c.reg),0x1120,sl_get<10>(c.reg,sizeof(c.reg),0x1130,c),c);
P_3212d_6:;
sl_put<10>(c.reg,sizeof(c.reg),0x1130,sl_get<10>(c.reg,sizeof(c.reg),0x1140,c),c);
P_3212d_7:;
sl_put<10>(c.reg,sizeof(c.reg),0x1140,sl_get<10>(c.reg,sizeof(c.reg),0x1150,c),c);
P_3212d_8:;
sl_put<10>(c.reg,sizeof(c.reg),0x1150,sl_get<10>(c.reg,sizeof(c.reg),0x1160,c),c);
P_3212d_9:;
sl_put<10>(c.reg,sizeof(c.reg),0x1160,sl_get<10>(c.reg,sizeof(c.reg),0x1170,c),c);
P_3212d_10:;
goto L_32130;
}
L_32130:{ // MOVSS XMM6,dword ptr [EBP + -0x3c]
c.pc=0x32130;if(!sl_tick(c))return int(c.fault);
P_32130_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc4ULL)),c);
P_32130_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_32130_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1380,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_32130_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1384,SlU(0x0ULL),c);
P_32130_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1388,SlU(0x0ULL),c);
P_32130_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x138c,SlU(0x0ULL),c);
P_32130_6:;
goto L_32135;
}
L_32135:{ // CVTSI2SD XMM0,dword ptr [EBP + -0x1c]
c.pc=0x32135;if(!sl_tick(c))return int(c.fault);
P_32135_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_32135_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_32135_2:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<double>(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),32))),c);
P_32135_3:;
goto L_3213a;
}
L_3213a:{ // MOVSD XMM7,qword ptr [EBX + 0x96580]
c.pc=0x3213a;if(!sl_tick(c))return int(c.fault);
P_3213a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x96580ULL)),c);
P_3213a_1:;
sl_put<8>(c.temp,sizeof(c.temp),0x5280,sl_get<8>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_3213a_2:;
sl_put<8>(c.reg,sizeof(c.reg),0x13c0,sl_get<8>(c.temp,sizeof(c.temp),0x5280,c),c);
P_3213a_3:;
sl_put<8>(c.reg,sizeof(c.reg),0x13c8,SlU(0x0ULL),c);
P_3213a_4:;
goto L_32142;
}
L_32142:{ // MOVAPD XMM4,XMM7
c.pc=0x32142;if(!sl_tick(c))return int(c.fault);
P_32142_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1300,sl_get<8>(c.reg,sizeof(c.reg),0x13c0,c),c);
P_32142_1:;
sl_put<8>(c.reg,sizeof(c.reg),0x1308,sl_get<8>(c.reg,sizeof(c.reg),0x13c8,c),c);
P_32142_2:;
goto L_32146;
}
L_32146:{ // DIVSD XMM4,XMM0
c.pc=0x32146;if(!sl_tick(c))return int(c.fault);
P_32146_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1300,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1300,c)) / sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_32146_1:;
goto L_3214a;
}
L_3214a:{ // TEST ESI,ESI
c.pc=0x3214a;if(!sl_tick(c))return int(c.fault);
P_3214a_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_3214a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_3214a_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_3214a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_3214a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_3214a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_3214a_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_3214a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_3214a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_3214a_9:;
goto L_3214c;
}
L_3214c:{ // MOVSS XMM5,dword ptr [EBP + -0x38]
c.pc=0x3214c;if(!sl_tick(c))return int(c.fault);
P_3214c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc8ULL)),c);
P_3214c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_3214c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1340,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_3214c_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1344,SlU(0x0ULL),c);
P_3214c_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1348,SlU(0x0ULL),c);
P_3214c_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x134c,SlU(0x0ULL),c);
P_3214c_6:;
goto L_32151;
}
L_32151:{ // JG 0x000321f2
c.pc=0x32151;if(!sl_tick(c))return int(c.fault);
P_32151_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_32151_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_32151_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_32151_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_321f2;}
P_32151_4:;
goto L_32157;
}
L_32157:{ // XOR ESI,ESI
c.pc=0x32157;if(!sl_tick(c))return int(c.fault);
P_32157_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_32157_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_32157_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_32157_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32157_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_32157_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_32157_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32157_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32157_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32157_9:;
goto L_32159;
}
L_32159:{ // CMP dword ptr [EBP + -0x20],ESI
c.pc=0x32159;if(!sl_tick(c))return int(c.fault);
P_32159_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_32159_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_32159_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_32159_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_32159_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x18,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x18,c)))&(SlU(1)<<31))!=0),c);
P_32159_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_32159_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32159_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_32159_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_32159_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32159_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32159_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32159_12:;
goto L_3215c;
}
L_3215c:{ // JLE 0x00032187
c.pc=0x3215c;if(!sl_tick(c))return int(c.fault);
P_3215c_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_3215c_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_3215c_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_32187;}
P_3215c_3:;
goto L_3215e;
}
L_3215e:{ // MOV ECX,dword ptr [EBP + 0xc]
c.pc=0x3215e;if(!sl_tick(c))return int(c.fault);
P_3215e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_3215e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_3215e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_3215e_3:;
goto L_32161;
}
L_32161:{ // LEA EAX,[ECX + ESI*0x4]
c.pc=0x32161;if(!sl_tick(c))return int(c.fault);
P_32161_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) * SlU(0x4ULL)),c);
P_32161_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_32161_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3580,c),c);
P_32161_3:;
goto L_32164;
}
L_32164:{ // XOR EDX,EDX
c.pc=0x32164;if(!sl_tick(c))return int(c.fault);
P_32164_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_32164_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_32164_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_32164_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32164_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_32164_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_32164_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32164_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32164_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32164_9:;
goto L_32166;
}
L_32166:{ // MOV ECX,dword ptr [EBP + -0x20]
c.pc=0x32166;if(!sl_tick(c))return int(c.fault);
P_32166_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_32166_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_32166_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_32166_3:;
goto L_32169;
}
L_32169:{ // SUB ECX,ESI
c.pc=0x32169;if(!sl_tick(c))return int(c.fault);
P_32169_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) < sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_32169_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x4,c)^sl_get<4>(c.reg,sizeof(c.reg),0x18,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)-sl_get<4>(c.reg,sizeof(c.reg),0x18,c)))&(SlU(1)<<31))!=0),c);
P_32169_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) - sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_32169_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x4,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32169_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) == SlU(0x0ULL)),c);
P_32169_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & SlU(0xffULL)),c);
P_32169_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32169_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32169_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32169_9:;
goto L_3216b;
}
L_3216b:{ // MOVSS XMM0,dword ptr [EAX]
c.pc=0x3216b;if(!sl_tick(c))return int(c.fault);
P_3216b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_3216b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_3216b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,SlU(0x0ULL),c);
P_3216b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_3216b_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,SlU(0x0ULL),c);
P_3216b_5:;
goto L_3216f;
}
L_3216f:{ // SUBSS XMM0,XMM5
c.pc=0x3216f;if(!sl_tick(c))return int(c.fault);
P_3216f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) - sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1340,c))),c);
P_3216f_1:;
goto L_32173;
}
L_32173:{ // MULSS XMM0,XMM6
c.pc=0x32173;if(!sl_tick(c))return int(c.fault);
P_32173_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1380,c))),c);
P_32173_1:;
goto L_32177;
}
L_32177:{ // MOVSS dword ptr [EAX],XMM0
c.pc=0x32177;if(!sl_tick(c))return int(c.fault);
P_32177_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_32177_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_32177_2:;
goto L_3217b;
}
L_3217b:{ // ADD EDX,0x1
c.pc=0x3217b;if(!sl_tick(c))return int(c.fault);
P_3217b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_3217b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_3217b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x1ULL)),c);
P_3217b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_3217b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_3217b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_3217b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_3217b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_3217b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_3217b_9:;
goto L_3217e;
}
L_3217e:{ // ADD EAX,0x4
c.pc=0x3217e;if(!sl_tick(c))return int(c.fault);
P_3217e_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_3217e_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL)))&(SlU(0x4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL)))&(SlU(1)<<31))!=0),c);
P_3217e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_3217e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_3217e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_3217e_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_3217e_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_3217e_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_3217e_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_3217e_9:;
goto L_32181;
}
L_32181:{ // CMP EDX,ECX
c.pc=0x32181;if(!sl_tick(c))return int(c.fault);
P_32181_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_32181_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_32181_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x4,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x4,c)))&(SlU(1)<<31))!=0),c);
P_32181_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_32181_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32181_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_32181_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_32181_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32181_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32181_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32181_10:;
goto L_32183;
}
L_32183:{ // JNZ 0x0003216b
c.pc=0x32183;if(!sl_tick(c))return int(c.fault);
P_32183_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_32183_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_3216b;}
P_32183_2:;
goto L_32185;
}
L_32185:{ // ADD ESI,EDX
c.pc=0x32185;if(!sl_tick(c))return int(c.fault);
P_32185_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+sl_get<4>(c.reg,sizeof(c.reg),0x8,c))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_32185_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+sl_get<4>(c.reg,sizeof(c.reg),0x8,c)))&(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+sl_get<4>(c.reg,sizeof(c.reg),0x8,c)))&(SlU(1)<<31))!=0),c);
P_32185_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_32185_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32185_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_32185_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_32185_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32185_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32185_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32185_9:;
goto L_32187;
}
L_32187:{ // CMP EDI,ESI
c.pc=0x32187;if(!sl_tick(c))return int(c.fault);
P_32187_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_32187_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_32187_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x18,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x18,c)))&(SlU(1)<<31))!=0),c);
P_32187_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_32187_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32187_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_32187_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_32187_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32187_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32187_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32187_10:;
goto L_32189;
}
L_32189:{ // JLE 0x000321dd
c.pc=0x32189;if(!sl_tick(c))return int(c.fault);
P_32189_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_32189_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_32189_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_321dd;}
P_32189_3:;
goto L_3218b;
}
L_3218b:{ // CVTSS2SD XMM3,XMM5
c.pc=0x3218b;if(!sl_tick(c))return int(c.fault);
P_3218b_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x12c0,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1340,c)))),c);
P_3218b_1:;
goto L_3218f;
}
L_3218f:{ // CVTSS2SD XMM2,XMM6
c.pc=0x3218f;if(!sl_tick(c))return int(c.fault);
P_3218f_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1280,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1380,c)))),c);
P_3218f_1:;
goto L_32193;
}
L_32193:{ // MOV EDX,ESI
c.pc=0x32193;if(!sl_tick(c))return int(c.fault);
P_32193_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_32193_1:;
goto L_32195;
}
L_32195:{ // SUB EDX,dword ptr [EBP + -0x20]
c.pc=0x32195;if(!sl_tick(c))return int(c.fault);
P_32195_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_32195_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_32195_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) < sl_get<4>(c.temp,sizeof(c.temp),0x9680,c)),c);
P_32195_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_32195_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^sl_get<4>(c.temp,sizeof(c.temp),0x9680,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)-sl_get<4>(c.temp,sizeof(c.temp),0x9680,c)))&(SlU(1)<<31))!=0),c);
P_32195_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_32195_6:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) - sl_get<4>(c.temp,sizeof(c.temp),0x9680,c)),c);
P_32195_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32195_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_32195_9:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_32195_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32195_11:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32195_12:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32195_13:;
goto L_32198;
}
L_32198:{ // MOV ECX,dword ptr [EBP + 0xc]
c.pc=0x32198;if(!sl_tick(c))return int(c.fault);
P_32198_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_32198_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_32198_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_32198_3:;
goto L_3219b;
}
L_3219b:{ // LEA EAX,[ECX + ESI*0x4]
c.pc=0x3219b;if(!sl_tick(c))return int(c.fault);
P_3219b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) * SlU(0x4ULL)),c);
P_3219b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_3219b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3580,c),c);
P_3219b_3:;
goto L_3219e;
}
L_3219e:{ // XOR ECX,ECX
c.pc=0x3219e;if(!sl_tick(c))return int(c.fault);
P_3219e_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_3219e_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_3219e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_3219e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x4,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_3219e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) == SlU(0x0ULL)),c);
P_3219e_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & SlU(0xffULL)),c);
P_3219e_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_3219e_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_3219e_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_3219e_9:;
goto L_321a0;
}
L_321a0:{ // SUB EDI,ESI
c.pc=0x321a0;if(!sl_tick(c))return int(c.fault);
P_321a0_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) < sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_321a0_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)^sl_get<4>(c.reg,sizeof(c.reg),0x18,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)-sl_get<4>(c.reg,sizeof(c.reg),0x18,c)))&(SlU(1)<<31))!=0),c);
P_321a0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) - sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_321a0_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_321a0_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) == SlU(0x0ULL)),c);
P_321a0_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) & SlU(0xffULL)),c);
P_321a0_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_321a0_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_321a0_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_321a0_9:;
goto L_321a2;
}
L_321a2:{ // MOV ESI,EDI
c.pc=0x321a2;if(!sl_tick(c))return int(c.fault);
P_321a2_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_321a2_1:;
goto L_321a4;
}
L_321a4:{ // CVTSS2SD XMM0,dword ptr [EAX]
c.pc=0x321a4;if(!sl_tick(c))return int(c.fault);
P_321a4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_321a4_1:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)))),c);
P_321a4_2:;
goto L_321a8;
}
L_321a8:{ // CVTSI2SD XMM1,EDX
c.pc=0x321a8;if(!sl_tick(c))return int(c.fault);
P_321a8_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1240,sl_bits(static_cast<double>(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32))),c);
P_321a8_1:;
goto L_321ac;
}
L_321ac:{ // MULSD XMM1,XMM4
c.pc=0x321ac;if(!sl_tick(c))return int(c.fault);
P_321ac_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1300,c))),c);
P_321ac_1:;
goto L_321b0;
}
L_321b0:{ // MOVAPD XMM5,XMM7
c.pc=0x321b0;if(!sl_tick(c))return int(c.fault);
P_321b0_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1340,sl_get<8>(c.reg,sizeof(c.reg),0x13c0,c),c);
P_321b0_1:;
sl_put<8>(c.reg,sizeof(c.reg),0x1348,sl_get<8>(c.reg,sizeof(c.reg),0x13c8,c),c);
P_321b0_2:;
goto L_321b4;
}
L_321b4:{ // SUBSD XMM5,XMM1
c.pc=0x321b4;if(!sl_tick(c))return int(c.fault);
P_321b4_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1340,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1340,c)) - sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_321b4_1:;
goto L_321b8;
}
L_321b8:{ // MOVAPD XMM1,XMM5
c.pc=0x321b8;if(!sl_tick(c))return int(c.fault);
P_321b8_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1240,sl_get<8>(c.reg,sizeof(c.reg),0x1340,c),c);
P_321b8_1:;
sl_put<8>(c.reg,sizeof(c.reg),0x1248,sl_get<8>(c.reg,sizeof(c.reg),0x1348,c),c);
P_321b8_2:;
goto L_321bc;
}
L_321bc:{ // MULSD XMM1,XMM3
c.pc=0x321bc;if(!sl_tick(c))return int(c.fault);
P_321bc_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x12c0,c))),c);
P_321bc_1:;
goto L_321c0;
}
L_321c0:{ // SUBSD XMM0,XMM1
c.pc=0x321c0;if(!sl_tick(c))return int(c.fault);
P_321c0_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c)) - sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_321c0_1:;
goto L_321c4;
}
L_321c4:{ // MULSD XMM0,XMM2
c.pc=0x321c4;if(!sl_tick(c))return int(c.fault);
P_321c4_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_321c4_1:;
goto L_321c8;
}
L_321c8:{ // CVTSD2SS XMM0,XMM0
c.pc=0x321c8;if(!sl_tick(c))return int(c.fault);
P_321c8_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<float>(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c)))),c);
P_321c8_1:;
goto L_321cc;
}
L_321cc:{ // MOVSS dword ptr [EAX],XMM0
c.pc=0x321cc;if(!sl_tick(c))return int(c.fault);
P_321cc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_321cc_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_321cc_2:;
goto L_321d0;
}
L_321d0:{ // ADD ECX,0x1
c.pc=0x321d0;if(!sl_tick(c))return int(c.fault);
P_321d0_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x4,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_321d0_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x4,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_321d0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x1ULL)),c);
P_321d0_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x4,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_321d0_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) == SlU(0x0ULL)),c);
P_321d0_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & SlU(0xffULL)),c);
P_321d0_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_321d0_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_321d0_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_321d0_9:;
goto L_321d3;
}
L_321d3:{ // ADD EDX,0x1
c.pc=0x321d3;if(!sl_tick(c))return int(c.fault);
P_321d3_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_321d3_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_321d3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x1ULL)),c);
P_321d3_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_321d3_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_321d3_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_321d3_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_321d3_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_321d3_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_321d3_9:;
goto L_321d6;
}
L_321d6:{ // ADD EAX,0x4
c.pc=0x321d6;if(!sl_tick(c))return int(c.fault);
P_321d6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_321d6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL)))&(SlU(0x4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL)))&(SlU(1)<<31))!=0),c);
P_321d6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_321d6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_321d6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_321d6_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_321d6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_321d6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_321d6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_321d6_9:;
goto L_321d9;
}
L_321d9:{ // CMP ECX,ESI
c.pc=0x321d9;if(!sl_tick(c))return int(c.fault);
P_321d9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_321d9_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_321d9_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x18,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x18,c)))&(SlU(1)<<31))!=0),c);
P_321d9_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_321d9_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_321d9_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_321d9_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_321d9_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_321d9_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_321d9_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_321d9_10:;
goto L_321db;
}
L_321db:{ // JNZ 0x000321a4
c.pc=0x321db;if(!sl_tick(c))return int(c.fault);
P_321db_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_321db_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_321a4;}
P_321db_2:;
goto L_321dd;
}
L_321dd:{ // ADD ESP,0x4c
c.pc=0x321dd;if(!sl_tick(c))return int(c.fault);
P_321dd_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_321dd_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4cULL)))&(SlU(0x4cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4cULL)))&(SlU(1)<<31))!=0),c);
P_321dd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4cULL)),c);
P_321dd_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_321dd_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_321dd_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_321dd_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_321dd_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_321dd_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_321dd_9:;
goto L_321e0;
}
L_321e0:{ // POP EBX
c.pc=0x321e0;if(!sl_tick(c))return int(c.fault);
P_321e0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_321e0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_321e0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_321e0_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_321e0_4:;
goto L_321e1;
}
L_321e1:{ // POP ESI
c.pc=0x321e1;if(!sl_tick(c))return int(c.fault);
P_321e1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_321e1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_321e1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_321e1_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_321e1_4:;
goto L_321e2;
}
L_321e2:{ // POP EDI
c.pc=0x321e2;if(!sl_tick(c))return int(c.fault);
P_321e2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_321e2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_321e2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_321e2_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_321e2_4:;
goto L_321e3;
}
L_321e3:{ // POP EBP
c.pc=0x321e3;if(!sl_tick(c))return int(c.fault);
P_321e3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_321e3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_321e3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_321e3_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_321e3_4:;
goto L_321e4;
}
L_321e4:{ // RET
c.pc=0x321e4;if(!sl_tick(c))return int(c.fault);
P_321e4_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_321e4_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_321e4_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_321e4_3:;
goto L_321e5;
}
L_321e5:{ // MOVSS XMM1,dword ptr [EBX + 0x969b4]
c.pc=0x321e5;if(!sl_tick(c))return int(c.fault);
P_321e5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x969b4ULL)),c);
P_321e5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_321e5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_321e5_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_321e5_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_321e5_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_321e5_6:;
goto L_321ed;
}
L_321ed:{ // JMP 0x000320b9
c.pc=0x321ed;if(!sl_tick(c))return int(c.fault);
P_321ed_0:;
goto L_320b9;
P_321ed_1:;
goto L_321f2;
}
L_321f2:{ // CVTSS2SD XMM3,XMM5
c.pc=0x321f2;if(!sl_tick(c))return int(c.fault);
P_321f2_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x12c0,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1340,c)))),c);
P_321f2_1:;
goto L_321f6;
}
L_321f6:{ // CVTSS2SD XMM2,XMM6
c.pc=0x321f6;if(!sl_tick(c))return int(c.fault);
P_321f6_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1280,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1380,c)))),c);
P_321f6_1:;
goto L_321fa;
}
L_321fa:{ // XOR EDX,EDX
c.pc=0x321fa;if(!sl_tick(c))return int(c.fault);
P_321fa_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_321fa_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_321fa_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_321fa_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_321fa_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_321fa_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_321fa_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_321fa_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_321fa_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_321fa_9:;
goto L_321fc;
}
L_321fc:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0x321fc;if(!sl_tick(c))return int(c.fault);
P_321fc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_321fc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_321fc_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_321fc_3:;
goto L_321ff;
}
L_321ff:{ // CVTSS2SD XMM1,dword ptr [EAX]
c.pc=0x321ff;if(!sl_tick(c))return int(c.fault);
P_321ff_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_321ff_1:;
sl_put<8>(c.reg,sizeof(c.reg),0x1240,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)))),c);
P_321ff_2:;
goto L_32203;
}
L_32203:{ // CVTSI2SD XMM0,EDX
c.pc=0x32203;if(!sl_tick(c))return int(c.fault);
P_32203_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<double>(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32))),c);
P_32203_1:;
goto L_32207;
}
L_32207:{ // MULSD XMM0,XMM4
c.pc=0x32207;if(!sl_tick(c))return int(c.fault);
P_32207_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1300,c))),c);
P_32207_1:;
goto L_3220b;
}
L_3220b:{ // MULSD XMM0,XMM3
c.pc=0x3220b;if(!sl_tick(c))return int(c.fault);
P_3220b_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x12c0,c))),c);
P_3220b_1:;
goto L_3220f;
}
L_3220f:{ // SUBSD XMM1,XMM0
c.pc=0x3220f;if(!sl_tick(c))return int(c.fault);
P_3220f_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1240,c)) - sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_3220f_1:;
goto L_32213;
}
L_32213:{ // MULSD XMM1,XMM2
c.pc=0x32213;if(!sl_tick(c))return int(c.fault);
P_32213_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_32213_1:;
goto L_32217;
}
L_32217:{ // CVTSD2SS XMM1,XMM1
c.pc=0x32217;if(!sl_tick(c))return int(c.fault);
P_32217_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(static_cast<float>(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1240,c)))),c);
P_32217_1:;
goto L_3221b;
}
L_3221b:{ // MOVSS dword ptr [EAX],XMM1
c.pc=0x3221b;if(!sl_tick(c))return int(c.fault);
P_3221b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_3221b_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_3221b_2:;
goto L_3221f;
}
L_3221f:{ // ADD EDX,0x1
c.pc=0x3221f;if(!sl_tick(c))return int(c.fault);
P_3221f_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_3221f_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_3221f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x1ULL)),c);
P_3221f_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_3221f_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_3221f_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_3221f_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_3221f_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_3221f_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_3221f_9:;
goto L_32222;
}
L_32222:{ // ADD EAX,0x4
c.pc=0x32222;if(!sl_tick(c))return int(c.fault);
P_32222_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_32222_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL)))&(SlU(0x4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x4ULL)))&(SlU(1)<<31))!=0),c);
P_32222_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_32222_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32222_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_32222_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_32222_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32222_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32222_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32222_9:;
goto L_32225;
}
L_32225:{ // CMP ESI,EDX
c.pc=0x32225;if(!sl_tick(c))return int(c.fault);
P_32225_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_32225_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_32225_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x8,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x8,c)))&(SlU(1)<<31))!=0),c);
P_32225_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_32225_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32225_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_32225_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_32225_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32225_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32225_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32225_10:;
goto L_32227;
}
L_32227:{ // JNZ 0x000321ff
c.pc=0x32227;if(!sl_tick(c))return int(c.fault);
P_32227_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_32227_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_321ff;}
P_32227_2:;
goto L_32229;
}
L_32229:{ // JMP 0x00032159
c.pc=0x32229;if(!sl_tick(c))return int(c.fault);
P_32229_0:;
goto L_32159;
P_32229_1:;
goto L_3222e;
}
L_3222e:{ // MOV ESI,0x1
c.pc=0x3222e;if(!sl_tick(c))return int(c.fault);
P_3222e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,SlU(0x1ULL),c);
P_3222e_1:;
goto L_32233;
}
L_32233:{ // MOV dword ptr [EBP + -0x1c],0x0
c.pc=0x32233;if(!sl_tick(c))return int(c.fault);
P_32233_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_32233_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_32233_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_32233_3:;
goto L_3223a;
}
L_3223a:{ // JMP 0x000320ef
c.pc=0x3223a;if(!sl_tick(c))return int(c.fault);
P_3223a_0:;
goto L_320ef;
P_3223a_1:;
goto L_3223f;
}
L_3223f:{ // MOVSS XMM1,dword ptr [EBX + 0x969cc]
c.pc=0x3223f;if(!sl_tick(c))return int(c.fault);
P_3223f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x969ccULL)),c);
P_3223f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_3223f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_3223f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_3223f_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_3223f_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_3223f_6:;
goto L_32247;
}
L_32247:{ // JMP 0x000320b9
c.pc=0x32247;if(!sl_tick(c))return int(c.fault);
P_32247_0:;
goto L_320b9;
P_32247_1:;
goto L_3224c;
}
L_3224c:{ // MOVSS XMM1,dword ptr [EBX + 0x96a34]
c.pc=0x3224c;if(!sl_tick(c))return int(c.fault);
P_3224c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x96a34ULL)),c);
P_3224c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_3224c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_3224c_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_3224c_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_3224c_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_3224c_6:;
goto L_32254;
}
L_32254:{ // JMP 0x000320b9
c.pc=0x32254;if(!sl_tick(c))return int(c.fault);
P_32254_0:;
goto L_320b9;
P_32254_1:;
c.pc=0x32259;goto dispatch;
}
L_3225a:{ // PUSH EBP
c.pc=0x3225a;if(!sl_tick(c))return int(c.fault);
P_3225a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_3225a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_3225a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_3225a_3:;
goto L_3225b;
}
L_3225b:{ // MOV EBP,ESP
c.pc=0x3225b;if(!sl_tick(c))return int(c.fault);
P_3225b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_3225b_1:;
goto L_3225d;
}
L_3225d:{ // PUSH EDI
c.pc=0x3225d;if(!sl_tick(c))return int(c.fault);
P_3225d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_3225d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_3225d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_3225d_3:;
goto L_3225e;
}
L_3225e:{ // PUSH ESI
c.pc=0x3225e;if(!sl_tick(c))return int(c.fault);
P_3225e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_3225e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_3225e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_3225e_3:;
goto L_3225f;
}
L_3225f:{ // PUSH EBX
c.pc=0x3225f;if(!sl_tick(c))return int(c.fault);
P_3225f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_3225f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_3225f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_3225f_3:;
goto L_32260;
}
L_32260:{ // SUB ESP,0x2c
c.pc=0x32260;if(!sl_tick(c))return int(c.fault);
P_32260_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x2cULL)),c);
P_32260_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x2cULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x2cULL)))&(SlU(1)<<31))!=0),c);
P_32260_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x2cULL)),c);
P_32260_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32260_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_32260_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_32260_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32260_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32260_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32260_9:;
goto L_32263;
}
L_32263:{ // MOV EDI,dword ptr [EBP + 0xc]
c.pc=0x32263;if(!sl_tick(c))return int(c.fault);
P_32263_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_32263_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_32263_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_32263_3:;
goto L_32266;
}
L_32266:{ // MOV ESI,dword ptr [EBP + 0x10]
c.pc=0x32266;if(!sl_tick(c))return int(c.fault);
P_32266_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_32266_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_32266_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_32266_3:;
goto L_32269;
}
L_32269:{ // MOV EAX,ESI
c.pc=0x32269;if(!sl_tick(c))return int(c.fault);
P_32269_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_32269_1:;
goto L_3226b;
}
L_3226b:{ // SUB EAX,0x1
c.pc=0x3226b;if(!sl_tick(c))return int(c.fault);
P_3226b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < SlU(0x1ULL)),c);
P_3226b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^SlU(0x1ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_3226b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - SlU(0x1ULL)),c);
P_3226b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_3226b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_3226b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_3226b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_3226b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_3226b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_3226b_9:;
goto L_3226e;
}
L_3226e:{ // JS 0x000322ae
c.pc=0x3226e;if(!sl_tick(c))return int(c.fault);
P_3226e_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x207,c)){c.pc=0x322ae;goto dispatch;}
P_3226e_1:;
goto L_32270;
}
L_32270:{ // LEA EAX,[EDI + EAX*0x4]
c.pc=0x32270;if(!sl_tick(c))return int(c.fault);
P_32270_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x4ULL)),c);
P_32270_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_32270_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3580,c),c);
P_32270_3:;
goto L_32273;
}
L_32273:{ // PXOR XMM1,XMM1
c.pc=0x32273;if(!sl_tick(c))return int(c.fault);
P_32273_0:;
sl_put<16>(c.reg,sizeof(c.reg),0x1240,(sl_get<16>(c.reg,sizeof(c.reg),0x1240,c) ^ sl_get<16>(c.reg,sizeof(c.reg),0x1240,c)),c);
P_32273_1:;
goto L_32277;
}
L_32277:{ // XOR EDX,EDX
c.pc=0x32277;if(!sl_tick(c))return int(c.fault);
P_32277_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_32277_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_32277_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_32277_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32277_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_32277_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_32277_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32277_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32277_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32277_9:;
goto L_32279;
}
L_32279:{ // MOV ECX,ESI
c.pc=0x32279;if(!sl_tick(c))return int(c.fault);
P_32279_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_32279_1:;
goto L_3227b;
}
L_3227b:{ // CVTSS2SD XMM0,dword ptr [EAX]
c.pc=0x3227b;if(!sl_tick(c))return int(c.fault);
P_3227b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_3227b_1:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)))),c);
P_3227b_2:;
goto L_3227f;
}
L_3227f:{ // ADDSD XMM1,XMM0
c.pc=0x3227f;if(!sl_tick(c))return int(c.fault);
P_3227f_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1240,c)) + sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_3227f_1:;
goto L_32283;
}
L_32283:{ // ADD EDX,0x1
c.pc=0x32283;if(!sl_tick(c))return int(c.fault);
P_32283_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_32283_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_32283_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x1ULL)),c);
P_32283_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32283_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_32283_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_32283_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32283_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32283_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32283_9:;
goto L_32286;
}
L_32286:{ // SUB EAX,0x4
c.pc=0x32286;if(!sl_tick(c))return int(c.fault);
P_32286_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < SlU(0x4ULL)),c);
P_32286_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^SlU(0x4ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-SlU(0x4ULL)))&(SlU(1)<<31))!=0),c);
P_32286_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - SlU(0x4ULL)),c);
P_32286_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32286_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_32286_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_32286_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32286_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32286_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32286_9:;
goto L_32289;
}
L_32289:{ // CMP EDX,ECX
c.pc=0x32289;if(!sl_tick(c))return int(c.fault);
P_32289_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_32289_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_32289_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x4,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x4,c)))&(SlU(1)<<31))!=0),c);
P_32289_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_32289_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_32289_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_32289_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_32289_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_32289_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_32289_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_32289_10:;
goto L_3228b;
}
L_3228b:{ // JNZ 0x0003227b
c.pc=0x3228b;if(!sl_tick(c))return int(c.fault);
P_3228b_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_3228b_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_3227b;}
P_3228b_2:;
goto L_3228d;
}
L_3228d:{ // MOVSD qword ptr [ESP + 0xc],XMM1
c.pc=0x3228d;if(!sl_tick(c))return int(c.fault);
P_3228d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_3228d_1:;
sl_put<8>(c.temp,sizeof(c.temp),0x5280,sl_get<8>(c.reg,sizeof(c.reg),0x1240,c),c);
P_3228d_2:;
sl_put<8>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<8>(c.temp,sizeof(c.temp),0x5280,c),c);
P_3228d_3:;
goto L_32293;
}
L_32293:{ // MOV dword ptr [ESP + 0x8],ESI
c.pc=0x32293;if(!sl_tick(c))return int(c.fault);
P_32293_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_32293_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_32293_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_32293_3:;
goto L_32297;
}
L_32297:{ // MOV dword ptr [ESP + 0x4],EDI
c.pc=0x32297;if(!sl_tick(c))return int(c.fault);
P_32297_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_32297_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_32297_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_32297_3:;
goto L_3229b;
}
L_3229b:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x3229b;if(!sl_tick(c))return int(c.fault);
P_3229b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_3229b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_3229b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_3229b_3:;
goto L_3229e;
}
L_3229e:{ // MOV dword ptr [ESP],EAX
c.pc=0x3229e;if(!sl_tick(c))return int(c.fault);
P_3229e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_3229e_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_3229e_2:;
goto L_322a1;
}
L_322a1:{ // CALL 0x0003207a
c.pc=0x322a1;if(!sl_tick(c))return int(c.fault);
P_322a1_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_322a1_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x322a6ULL),c);
P_322a1_2:;
goto L_3207a;
P_322a1_3:;
goto L_322a6;
}
L_322a6:{ // ADD ESP,0x2c
c.pc=0x322a6;if(!sl_tick(c))return int(c.fault);
P_322a6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_322a6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL)))&(SlU(0x2cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL)))&(SlU(1)<<31))!=0),c);
P_322a6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x2cULL)),c);
P_322a6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_322a6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_322a6_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_322a6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_322a6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_322a6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_322a6_9:;
goto L_322a9;
}
L_322a9:{ // POP EBX
c.pc=0x322a9;if(!sl_tick(c))return int(c.fault);
P_322a9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_322a9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_322a9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_322a9_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_322a9_4:;
c.pc=0x322aa;goto dispatch;
}
}
