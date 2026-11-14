// Generated static p-code lift; original i386 SHA-256: 17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12
#include "LifterRuntime.h"
int sl_unit_0320(SlCpu& c){
goto dispatch;
dispatch:
if(c.fault||c.pc==c.stop)return int(c.fault);
switch(c.pc){
case 0xadc7a:goto L_adc7a;
case 0xadc7b:goto L_adc7b;
case 0xadc7c:goto L_adc7c;
case 0xadc7d:goto L_adc7d;
case 0xadc80:goto L_adc80;
case 0xadc82:goto L_adc82;
case 0xadc84:goto L_adc84;
case 0xadc87:goto L_adc87;
case 0xadc8d:goto L_adc8d;
case 0xadc90:goto L_adc90;
case 0xadc92:goto L_adc92;
case 0xadc95:goto L_adc95;
case 0xadc96:goto L_adc96;
case 0xadc97:goto L_adc97;
case 0xadc98:goto L_adc98;
case 0xadc99:goto L_adc99;
case 0xadc9e:goto L_adc9e;
case 0xadca0:goto L_adca0;
case 0xadca3:goto L_adca3;
case 0xadca6:goto L_adca6;
case 0xadca9:goto L_adca9;
case 0xadcac:goto L_adcac;
case 0xadcaf:goto L_adcaf;
case 0xadcb2:goto L_adcb2;
case 0xadcb5:goto L_adcb5;
case 0xadcb8:goto L_adcb8;
case 0xadcbb:goto L_adcbb;
case 0xadcc0:goto L_adcc0;
case 0xadcc3:goto L_adcc3;
case 0xadcc6:goto L_adcc6;
case 0xadcc7:goto L_adcc7;
case 0xadcc8:goto L_adcc8;
case 0xadcc9:goto L_adcc9;
case 0xadcce:goto L_adcce;
case 0xadccf:goto L_adccf;
case 0xadcd1:goto L_adcd1;
case 0xadcd2:goto L_adcd2;
case 0xadcd3:goto L_adcd3;
case 0xadcd4:goto L_adcd4;
case 0xadcd7:goto L_adcd7;
case 0xadcdc:goto L_adcdc;
case 0xadcdf:goto L_adcdf;
case 0xadce2:goto L_adce2;
case 0xadce5:goto L_adce5;
case 0xadce8:goto L_adce8;
case 0xadceb:goto L_adceb;
case 0xadcee:goto L_adcee;
case 0xadcf1:goto L_adcf1;
case 0xadcf4:goto L_adcf4;
case 0xadcf7:goto L_adcf7;
case 0xadcf9:goto L_adcf9;
case 0xadcff:goto L_adcff;
case 0xadd01:goto L_add01;
case 0xadd05:goto L_add05;
case 0xadd09:goto L_add09;
case 0xadd0d:goto L_add0d;
case 0xadd11:goto L_add11;
case 0xadd14:goto L_add14;
case 0xadd17:goto L_add17;
case 0xadd1c:goto L_add1c;
case 0xadd21:goto L_add21;
case 0xadd23:goto L_add23;
case 0xadd26:goto L_add26;
case 0xadd27:goto L_add27;
case 0xadd28:goto L_add28;
case 0xadd29:goto L_add29;
case 0xadd2a:goto L_add2a;
case 0xadd2b:goto L_add2b;
case 0xadd31:goto L_add31;
case 0xadd33:goto L_add33;
case 0xadd38:goto L_add38;
case 0xadd3b:goto L_add3b;
case 0xadd3c:goto L_add3c;
case 0xadd3d:goto L_add3d;
case 0xadd3e:goto L_add3e;
case 0xadd3f:goto L_add3f;
case 0xadd40:goto L_add40;
case 0xadd43:goto L_add43;
case 0xadd45:goto L_add45;
case 0xadd47:goto L_add47;
case 0xadd4c:goto L_add4c;
case 0xadd4f:goto L_add4f;
case 0xadd50:goto L_add50;
case 0xadd51:goto L_add51;
case 0xadd52:goto L_add52;
case 0xadd53:goto L_add53;
case 0xadd54:goto L_add54;
case 0xadd57:goto L_add57;
case 0xadd5a:goto L_add5a;
case 0xadd5d:goto L_add5d;
case 0xadd60:goto L_add60;
case 0xadd63:goto L_add63;
case 0xadd66:goto L_add66;
case 0xadd69:goto L_add69;
case 0xadd6e:goto L_add6e;
case 0xadd71:goto L_add71;
case 0xadd74:goto L_add74;
case 0xadd75:goto L_add75;
case 0xadd76:goto L_add76;
case 0xadd77:goto L_add77;
case 0xadd78:goto L_add78;
case 0xadd7d:goto L_add7d;
case 0xadd83:goto L_add83;
case 0xadd86:goto L_add86;
case 0xadd88:goto L_add88;
case 0xadd8a:goto L_add8a;
case 0xadd8d:goto L_add8d;
case 0xadd8e:goto L_add8e;
case 0xadd8f:goto L_add8f;
case 0xadd90:goto L_add90;
case 0xadd91:goto L_add91;
case 0xadd92:goto L_add92;
case 0xadd95:goto L_add95;
case 0xadd97:goto L_add97;
case 0xadd9a:goto L_add9a;
case 0xadd9d:goto L_add9d;
case 0xadda0:goto L_adda0;
case 0xadda3:goto L_adda3;
case 0xadda9:goto L_adda9;
case 0xaddac:goto L_addac;
case 0xaddad:goto L_addad;
case 0xaddae:goto L_addae;
case 0xaddaf:goto L_addaf;
case 0xaddb0:goto L_addb0;
case 0xaddb2:goto L_addb2;
case 0xaddb3:goto L_addb3;
case 0xaddb5:goto L_addb5;
case 0xaddb6:goto L_addb6;
case 0xaddb7:goto L_addb7;
case 0xaddba:goto L_addba;
case 0xaddbd:goto L_addbd;
case 0xaddc0:goto L_addc0;
case 0xaddc3:goto L_addc3;
case 0xaddc6:goto L_addc6;
case 0xaddc9:goto L_addc9;
case 0xaddcc:goto L_addcc;
case 0xaddcf:goto L_addcf;
case 0xaddd2:goto L_addd2;
case 0xaddd5:goto L_addd5;
case 0xaddd8:goto L_addd8;
case 0xadddc:goto L_adddc;
case 0xadde0:goto L_adde0;
case 0xadde4:goto L_adde4;
case 0xadde7:goto L_adde7;
case 0xaddeb:goto L_addeb;
case 0xaddee:goto L_addee;
case 0xaddf2:goto L_addf2;
case 0xaddf5:goto L_addf5;
case 0xaddf8:goto L_addf8;
case 0xaddfd:goto L_addfd;
case 0xade02:goto L_ade02;
case 0xade04:goto L_ade04;
case 0xade07:goto L_ade07;
case 0xade08:goto L_ade08;
case 0xade09:goto L_ade09;
case 0xade0a:goto L_ade0a;
case 0xade0b:goto L_ade0b;
case 0xade0e:goto L_ade0e;
case 0xade11:goto L_ade11;
case 0xade14:goto L_ade14;
case 0xade17:goto L_ade17;
case 0xade1a:goto L_ade1a;
case 0xade1d:goto L_ade1d;
case 0xade20:goto L_ade20;
case 0xade23:goto L_ade23;
case 0xade26:goto L_ade26;
case 0xade2b:goto L_ade2b;
case 0xade2e:goto L_ade2e;
case 0xade31:goto L_ade31;
case 0xade32:goto L_ade32;
case 0xade33:goto L_ade33;
case 0xade34:goto L_ade34;
case 0xade3a:goto L_ade3a;
case 0xade3b:goto L_ade3b;
case 0xade3d:goto L_ade3d;
case 0xade40:goto L_ade40;
case 0xade46:goto L_ade46;
case 0xade48:goto L_ade48;
case 0xade49:goto L_ade49;
case 0xade4a:goto L_ade4a;
case 0xade4b:goto L_ade4b;
case 0xade4d:goto L_ade4d;
case 0xade50:goto L_ade50;
case 0xade53:goto L_ade53;
case 0xade5a:goto L_ade5a;
case 0xade5e:goto L_ade5e;
case 0xade62:goto L_ade62;
case 0xade67:goto L_ade67;
case 0xade6b:goto L_ade6b;
case 0xade6f:goto L_ade6f;
case 0xade74:goto L_ade74;
case 0xade76:goto L_ade76;
case 0xade79:goto L_ade79;
case 0xade7d:goto L_ade7d;
case 0xade80:goto L_ade80;
case 0xade84:goto L_ade84;
case 0xade87:goto L_ade87;
case 0xade8b:goto L_ade8b;
case 0xade8e:goto L_ade8e;
case 0xade92:goto L_ade92;
case 0xade9a:goto L_ade9a;
case 0xade9d:goto L_ade9d;
case 0xadea3:goto L_adea3;
case 0xadea4:goto L_adea4;
case 0xadea6:goto L_adea6;
case 0xadea7:goto L_adea7;
case 0xadea9:goto L_adea9;
case 0xadeac:goto L_adeac;
case 0xadeaf:goto L_adeaf;
case 0xadeb1:goto L_adeb1;
case 0xadeb4:goto L_adeb4;
case 0xadeb8:goto L_adeb8;
case 0xadebc:goto L_adebc;
case 0xadec0:goto L_adec0;
case 0xadec3:goto L_adec3;
case 0xadec7:goto L_adec7;
case 0xadeca:goto L_adeca;
case 0xaded0:goto L_aded0;
case 0xaded1:goto L_aded1;
case 0xaded2:goto L_aded2;
case 0xaded3:goto L_aded3;
case 0xaded5:goto L_aded5;
case 0xaded6:goto L_aded6;
case 0xaded9:goto L_aded9;
case 0xadede:goto L_adede;
case 0xadee1:goto L_adee1;
case 0xadee3:goto L_adee3;
case 0xadee5:goto L_adee5;
case 0xadeea:goto L_adeea;
case 0xadeec:goto L_adeec;
case 0xadeef:goto L_adeef;
case 0xadef0:goto L_adef0;
case 0xadef1:goto L_adef1;
case 0xadef2:goto L_adef2;
case 0xadef5:goto L_adef5;
case 0xadef9:goto L_adef9;
case 0xadeff:goto L_adeff;
case 0xadf03:goto L_adf03;
case 0xadf07:goto L_adf07;
case 0xadf09:goto L_adf09;
case 0xadf0b:goto L_adf0b;
case 0xadf0e:goto L_adf0e;
case 0xadf10:goto L_adf10;
case 0xadf14:goto L_adf14;
case 0xadf17:goto L_adf17;
case 0xadf1b:goto L_adf1b;
case 0xadf1e:goto L_adf1e;
case 0xadf22:goto L_adf22;
case 0xadf25:goto L_adf25;
case 0xadf29:goto L_adf29;
case 0xadf2c:goto L_adf2c;
case 0xadf30:goto L_adf30;
case 0xadf33:goto L_adf33;
case 0xadf36:goto L_adf36;
case 0xadf3c:goto L_adf3c;
case 0xadf3e:goto L_adf3e;
case 0xadf40:goto L_adf40;
case 0xadf42:goto L_adf42;
case 0xadf45:goto L_adf45;
case 0xadf47:goto L_adf47;
case 0xadf49:goto L_adf49;
case 0xadf4c:goto L_adf4c;
case 0xadf4f:goto L_adf4f;
case 0xadf51:goto L_adf51;
case 0xadf53:goto L_adf53;
case 0xadf58:goto L_adf58;
case 0xadf5b:goto L_adf5b;
case 0xadf5f:goto L_adf5f;
case 0xadf67:goto L_adf67;
case 0xadf6a:goto L_adf6a;
case 0xadf6f:goto L_adf6f;
case 0xadf77:goto L_adf77;
case 0xadf7c:goto L_adf7c;
case 0xadf7f:goto L_adf7f;
case 0xadf84:goto L_adf84;
case 0xadf87:goto L_adf87;
case 0xadf8b:goto L_adf8b;
case 0xadf8f:goto L_adf8f;
case 0xadf93:goto L_adf93;
case 0xadf98:goto L_adf98;
case 0xadf9b:goto L_adf9b;
case 0xadf9e:goto L_adf9e;
case 0xadfa1:goto L_adfa1;
case 0xadfa3:goto L_adfa3;
case 0xadfa6:goto L_adfa6;
case 0xadfaa:goto L_adfaa;
case 0xadfad:goto L_adfad;
case 0xadfb1:goto L_adfb1;
case 0xadfb4:goto L_adfb4;
case 0xadfb8:goto L_adfb8;
case 0xadfbb:goto L_adfbb;
case 0xadfbe:goto L_adfbe;
case 0xadfc4:goto L_adfc4;
case 0xadfc6:goto L_adfc6;
case 0xadfcb:goto L_adfcb;
case 0xadfd0:goto L_adfd0;
case 0xadfd6:goto L_adfd6;
case 0xadfd7:goto L_adfd7;
case 0xadfd9:goto L_adfd9;
case 0xadfda:goto L_adfda;
case 0xadfdb:goto L_adfdb;
case 0xadfde:goto L_adfde;
case 0xadfe3:goto L_adfe3;
case 0xadfe6:goto L_adfe6;
case 0xadfe9:goto L_adfe9;
case 0xadfeb:goto L_adfeb;
case 0xadff1:goto L_adff1;
case 0xadff5:goto L_adff5;
case 0xadffa:goto L_adffa;
case 0xadffd:goto L_adffd;
case 0xadfff:goto L_adfff;
case 0xae002:goto L_ae002;
case 0xae005:goto L_ae005;
case 0xae008:goto L_ae008;
case 0xae009:goto L_ae009;
case 0xae00a:goto L_ae00a;
case 0xae00b:goto L_ae00b;
case 0xae010:goto L_ae010;
case 0xae017:goto L_ae017;
case 0xae019:goto L_ae019;
case 0xae034:goto L_ae034;
case 0xae03a:goto L_ae03a;
case 0xae03d:goto L_ae03d;
case 0xae040:goto L_ae040;
case 0xae043:goto L_ae043;
case 0xae044:goto L_ae044;
case 0xae045:goto L_ae045;
case 0xae046:goto L_ae046;
case 0xae04b:goto L_ae04b;
case 0xae04d:goto L_ae04d;
case 0xae050:goto L_ae050;
case 0xae053:goto L_ae053;
case 0xae056:goto L_ae056;
case 0xae05c:goto L_ae05c;
case 0xae05f:goto L_ae05f;
case 0xae060:goto L_ae060;
case 0xae061:goto L_ae061;
case 0xae062:goto L_ae062;
case 0xae064:goto L_ae064;
case 0xae066:goto L_ae066;
case 0xae069:goto L_ae069;
case 0xae06c:goto L_ae06c;
case 0xae06f:goto L_ae06f;
case 0xae075:goto L_ae075;
case 0xae077:goto L_ae077;
case 0xae079:goto L_ae079;
case 0xae07c:goto L_ae07c;
case 0xae080:goto L_ae080;
case 0xae083:goto L_ae083;
case 0xae087:goto L_ae087;
case 0xae08a:goto L_ae08a;
case 0xae08e:goto L_ae08e;
case 0xae091:goto L_ae091;
case 0xae095:goto L_ae095;
case 0xae098:goto L_ae098;
case 0xae09c:goto L_ae09c;
case 0xae09f:goto L_ae09f;
case 0xae0a5:goto L_ae0a5;
case 0xae0a8:goto L_ae0a8;
case 0xae0a9:goto L_ae0a9;
case 0xae0aa:goto L_ae0aa;
case 0xae0ab:goto L_ae0ab;
case 0xae0ac:goto L_ae0ac;
case 0xae0ae:goto L_ae0ae;
case 0xae0b1:goto L_ae0b1;
case 0xae0b5:goto L_ae0b5;
case 0xae0b8:goto L_ae0b8;
case 0xae0bc:goto L_ae0bc;
case 0xae0bf:goto L_ae0bf;
case 0xae0c3:goto L_ae0c3;
case 0xae0c6:goto L_ae0c6;
case 0xae0cc:goto L_ae0cc;
case 0xae0ce:goto L_ae0ce;
case 0xae0d3:goto L_ae0d3;
case 0xae0d6:goto L_ae0d6;
case 0xae0d7:goto L_ae0d7;
case 0xae0d8:goto L_ae0d8;
case 0xae0d9:goto L_ae0d9;
case 0xae0da:goto L_ae0da;
case 0xae0db:goto L_ae0db;
case 0xae0dd:goto L_ae0dd;
case 0xae0de:goto L_ae0de;
case 0xae0e1:goto L_ae0e1;
case 0xae0e4:goto L_ae0e4;
case 0xae0e7:goto L_ae0e7;
case 0xae0e9:goto L_ae0e9;
case 0xae0eb:goto L_ae0eb;
case 0xae0f1:goto L_ae0f1;
case 0xae0f7:goto L_ae0f7;
case 0xae0fa:goto L_ae0fa;
case 0xae0fe:goto L_ae0fe;
case 0xae102:goto L_ae102;
case 0xae106:goto L_ae106;
case 0xae10a:goto L_ae10a;
case 0xae10e:goto L_ae10e;
case 0xae110:goto L_ae110;
case 0xae113:goto L_ae113;
case 0xae117:goto L_ae117;
case 0xae11d:goto L_ae11d;
case 0xae121:goto L_ae121;
case 0xae124:goto L_ae124;
case 0xae127:goto L_ae127;
case 0xae129:goto L_ae129;
case 0xae12b:goto L_ae12b;
case 0xae12e:goto L_ae12e;
case 0xae12f:goto L_ae12f;
case 0xae130:goto L_ae130;
case 0xae131:goto L_ae131;
case 0xae136:goto L_ae136;
case 0xae138:goto L_ae138;
case 0xae13b:goto L_ae13b;
case 0xae13c:goto L_ae13c;
case 0xae13d:goto L_ae13d;
case 0xae198:goto L_ae198;
case 0xae199:goto L_ae199;
case 0xae19b:goto L_ae19b;
case 0xae19c:goto L_ae19c;
case 0xae19f:goto L_ae19f;
case 0xae1a2:goto L_ae1a2;
case 0xae1a9:goto L_ae1a9;
case 0xae1b0:goto L_ae1b0;
case 0xae1b7:goto L_ae1b7;
case 0xae1ba:goto L_ae1ba;
case 0xae1bc:goto L_ae1bc;
case 0xae1be:goto L_ae1be;
case 0xae1c2:goto L_ae1c2;
case 0xae1c4:goto L_ae1c4;
case 0xae1c8:goto L_ae1c8;
case 0xae1cf:goto L_ae1cf;
case 0xae1d5:goto L_ae1d5;
case 0xae1d8:goto L_ae1d8;
case 0xae1d9:goto L_ae1d9;
case 0xae1da:goto L_ae1da;
case 0xae1db:goto L_ae1db;
case 0xae1de:goto L_ae1de;
case 0xae1e3:goto L_ae1e3;
case 0xae1e6:goto L_ae1e6;
case 0xae1e7:goto L_ae1e7;
case 0xae1e9:goto L_ae1e9;
case 0xae1ea:goto L_ae1ea;
case 0xae1eb:goto L_ae1eb;
case 0xae1ee:goto L_ae1ee;
case 0xae1f1:goto L_ae1f1;
case 0xae1f4:goto L_ae1f4;
case 0xae1f7:goto L_ae1f7;
case 0xae1fa:goto L_ae1fa;
case 0xae1fd:goto L_ae1fd;
case 0xae200:goto L_ae200;
case 0xae202:goto L_ae202;
case 0xae204:goto L_ae204;
case 0xae207:goto L_ae207;
case 0xae209:goto L_ae209;
case 0xae20b:goto L_ae20b;
case 0xae20e:goto L_ae20e;
case 0xae211:goto L_ae211;
case 0xae218:goto L_ae218;
case 0xae21a:goto L_ae21a;
case 0xae221:goto L_ae221;
case 0xae224:goto L_ae224;
case 0xae228:goto L_ae228;
case 0xae22b:goto L_ae22b;
case 0xae22d:goto L_ae22d;
case 0xae22f:goto L_ae22f;
case 0xae232:goto L_ae232;
case 0xae235:goto L_ae235;
case 0xae239:goto L_ae239;
case 0xae23c:goto L_ae23c;
case 0xae23f:goto L_ae23f;
case 0xae240:goto L_ae240;
case 0xae241:goto L_ae241;
case 0xae242:goto L_ae242;
case 0xae247:goto L_ae247;
case 0xae24a:goto L_ae24a;
case 0xae24b:goto L_ae24b;
case 0xae24c:goto L_ae24c;
case 0xae24d:goto L_ae24d;
case 0xae24e:goto L_ae24e;
case 0xae252:goto L_ae252;
case 0xae254:goto L_ae254;
case 0xae257:goto L_ae257;
case 0xae25a:goto L_ae25a;
case 0xae25c:goto L_ae25c;
case 0xae25d:goto L_ae25d;
case 0xae25f:goto L_ae25f;
case 0xae260:goto L_ae260;
case 0xae261:goto L_ae261;
case 0xae264:goto L_ae264;
case 0xae267:goto L_ae267;
case 0xae26a:goto L_ae26a;
case 0xae271:goto L_ae271;
case 0xae273:goto L_ae273;
case 0xae278:goto L_ae278;
case 0xae27b:goto L_ae27b;
case 0xae27d:goto L_ae27d;
case 0xae280:goto L_ae280;
case 0xae283:goto L_ae283;
case 0xae287:goto L_ae287;
case 0xae28a:goto L_ae28a;
case 0xae28d:goto L_ae28d;
case 0xae290:goto L_ae290;
case 0xae293:goto L_ae293;
case 0xae295:goto L_ae295;
case 0xae299:goto L_ae299;
case 0xae29b:goto L_ae29b;
case 0xae29f:goto L_ae29f;
case 0xae2a2:goto L_ae2a2;
case 0xae2a5:goto L_ae2a5;
case 0xae2aa:goto L_ae2aa;
case 0xae2ad:goto L_ae2ad;
case 0xae2b0:goto L_ae2b0;
case 0xae2b3:goto L_ae2b3;
case 0xae2b6:goto L_ae2b6;
case 0xae2bc:goto L_ae2bc;
case 0xae2bf:goto L_ae2bf;
case 0xae2c0:goto L_ae2c0;
case 0xae2c1:goto L_ae2c1;
case 0xae2c2:goto L_ae2c2;
case 0xae2c3:goto L_ae2c3;
case 0xae2c7:goto L_ae2c7;
case 0xae2ce:goto L_ae2ce;
case 0xae2d0:goto L_ae2d0;
case 0xae2d4:goto L_ae2d4;
case 0xae2d6:goto L_ae2d6;
case 0xae2d9:goto L_ae2d9;
case 0xae2dc:goto L_ae2dc;
case 0xae2df:goto L_ae2df;
case 0xae2e1:goto L_ae2e1;
case 0xae2e4:goto L_ae2e4;
case 0xae2eb:goto L_ae2eb;
case 0xae2ef:goto L_ae2ef;
case 0xae2f2:goto L_ae2f2;
case 0xae2f5:goto L_ae2f5;
case 0xae2fa:goto L_ae2fa;
case 0xae2fd:goto L_ae2fd;
case 0xae300:goto L_ae300;
case 0xae306:goto L_ae306;
case 0xae307:goto L_ae307;
case 0xae309:goto L_ae309;
case 0xae30a:goto L_ae30a;
case 0xae30b:goto L_ae30b;
case 0xae30c:goto L_ae30c;
case 0xae30f:goto L_ae30f;
case 0xae314:goto L_ae314;
case 0xae317:goto L_ae317;
case 0xae31e:goto L_ae31e;
case 0xae324:goto L_ae324;
case 0xae327:goto L_ae327;
case 0xae32a:goto L_ae32a;
case 0xae32f:goto L_ae32f;
case 0xae336:goto L_ae336;
case 0xae339:goto L_ae339;
case 0xae33c:goto L_ae33c;
case 0xae33e:goto L_ae33e;
case 0xae341:goto L_ae341;
case 0xae344:goto L_ae344;
case 0xae347:goto L_ae347;
case 0xae34a:goto L_ae34a;
case 0xae34c:goto L_ae34c;
case 0xae34f:goto L_ae34f;
case 0xae351:goto L_ae351;
case 0xae354:goto L_ae354;
case 0xae358:goto L_ae358;
case 0xae35b:goto L_ae35b;
case 0xae35e:goto L_ae35e;
default:return 0;}
L_adc7a:{ // POP EDI
c.pc=0xadc7a;if(!sl_tick(c))return int(c.fault);
P_adc7a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_adc7a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adc7a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adc7a_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_adc7a_4:;
goto L_adc7b;
}
L_adc7b:{ // POP EBP
c.pc=0xadc7b;if(!sl_tick(c))return int(c.fault);
P_adc7b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_adc7b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adc7b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adc7b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_adc7b_4:;
goto L_adc7c;
}
L_adc7c:{ // RET
c.pc=0xadc7c;if(!sl_tick(c))return int(c.fault);
P_adc7c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adc7c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adc7c_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_adc7c_3:;
goto L_adc7d;
}
L_adc7d:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0xadc7d;if(!sl_tick(c))return int(c.fault);
P_adc7d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_adc7d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adc7d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adc7d_3:;
goto L_adc80;
}
L_adc80:{ // TEST EAX,EAX
c.pc=0xadc80;if(!sl_tick(c))return int(c.fault);
P_adc80_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_adc80_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_adc80_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_adc80_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adc80_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_adc80_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_adc80_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adc80_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adc80_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adc80_9:;
goto L_adc82;
}
L_adc82:{ // JNZ 0x000adc99
c.pc=0xadc82;if(!sl_tick(c))return int(c.fault);
P_adc82_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_adc82_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_adc99;}
P_adc82_2:;
goto L_adc84;
}
L_adc84:{ // MOV EAX,dword ptr [EBP + -0x18]
c.pc=0xadc84;if(!sl_tick(c))return int(c.fault);
P_adc84_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_adc84_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adc84_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adc84_3:;
goto L_adc87;
}
L_adc87:{ // MOV dword ptr [EAX],0x4
c.pc=0xadc87;if(!sl_tick(c))return int(c.fault);
P_adc87_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x4ULL),c);
P_adc87_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_adc87_2:;
goto L_adc8d;
}
L_adc8d:{ // MOV byte ptr [EDI],0x0
c.pc=0xadc8d;if(!sl_tick(c))return int(c.fault);
P_adc8d_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_adc8d_1:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_adc8d_2:;
goto L_adc90;
}
L_adc90:{ // XOR EAX,EAX
c.pc=0xadc90;if(!sl_tick(c))return int(c.fault);
P_adc90_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_adc90_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_adc90_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_adc90_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adc90_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_adc90_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_adc90_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adc90_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adc90_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adc90_9:;
goto L_adc92;
}
L_adc92:{ // ADD ESP,0x30
c.pc=0xadc92;if(!sl_tick(c))return int(c.fault);
P_adc92_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adc92_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL)))&(SlU(0x30ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL)))&(SlU(1)<<31))!=0),c);
P_adc92_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x30ULL)),c);
P_adc92_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adc92_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_adc92_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_adc92_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adc92_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adc92_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adc92_9:;
goto L_adc95;
}
L_adc95:{ // POP ESI
c.pc=0xadc95;if(!sl_tick(c))return int(c.fault);
P_adc95_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_adc95_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adc95_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adc95_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_adc95_4:;
goto L_adc96;
}
L_adc96:{ // POP EDI
c.pc=0xadc96;if(!sl_tick(c))return int(c.fault);
P_adc96_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_adc96_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adc96_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adc96_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_adc96_4:;
goto L_adc97;
}
L_adc97:{ // POP EBP
c.pc=0xadc97;if(!sl_tick(c))return int(c.fault);
P_adc97_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_adc97_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adc97_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adc97_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_adc97_4:;
goto L_adc98;
}
L_adc98:{ // RET
c.pc=0xadc98;if(!sl_tick(c))return int(c.fault);
P_adc98_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adc98_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adc98_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_adc98_3:;
goto L_adc99;
}
L_adc99:{ // MOV EAX,0xffffd58e
c.pc=0xadc99;if(!sl_tick(c))return int(c.fault);
P_adc99_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,SlU(0xffffd58eULL),c);
P_adc99_1:;
goto L_adc9e;
}
L_adc9e:{ // JMP 0x000adc76
c.pc=0xadc9e;if(!sl_tick(c))return int(c.fault);
P_adc9e_0:;
c.pc=0xadc76;goto dispatch;
P_adc9e_1:;
goto L_adca0;
}
L_adca0:{ // MOV dword ptr [EBP + 0x1c],EDI
c.pc=0xadca0;if(!sl_tick(c))return int(c.fault);
P_adca0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x1cULL)),c);
P_adca0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_adca0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adca0_3:;
goto L_adca3;
}
L_adca3:{ // MOV EAX,dword ptr [EBP + -0x18]
c.pc=0xadca3;if(!sl_tick(c))return int(c.fault);
P_adca3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_adca3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adca3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adca3_3:;
goto L_adca6;
}
L_adca6:{ // MOV dword ptr [EBP + 0x18],EAX
c.pc=0xadca6;if(!sl_tick(c))return int(c.fault);
P_adca6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x18ULL)),c);
P_adca6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adca6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adca6_3:;
goto L_adca9;
}
L_adca9:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0xadca9;if(!sl_tick(c))return int(c.fault);
P_adca9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_adca9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adca9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adca9_3:;
goto L_adcac;
}
L_adcac:{ // MOV dword ptr [EBP + 0x14],EAX
c.pc=0xadcac;if(!sl_tick(c))return int(c.fault);
P_adcac_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_adcac_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adcac_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adcac_3:;
goto L_adcaf;
}
L_adcaf:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0xadcaf;if(!sl_tick(c))return int(c.fault);
P_adcaf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_adcaf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adcaf_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adcaf_3:;
goto L_adcb2;
}
L_adcb2:{ // MOV dword ptr [EBP + 0x10],EAX
c.pc=0xadcb2;if(!sl_tick(c))return int(c.fault);
P_adcb2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_adcb2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adcb2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adcb2_3:;
goto L_adcb5;
}
L_adcb5:{ // MOV dword ptr [EBP + 0xc],ESI
c.pc=0xadcb5;if(!sl_tick(c))return int(c.fault);
P_adcb5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_adcb5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_adcb5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adcb5_3:;
goto L_adcb8;
}
L_adcb8:{ // MOV EAX,dword ptr [EBP + -0xc]
c.pc=0xadcb8;if(!sl_tick(c))return int(c.fault);
P_adcb8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_adcb8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adcb8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adcb8_3:;
goto L_adcbb;
}
L_adcbb:{ // ADD EAX,0xe4
c.pc=0xadcbb;if(!sl_tick(c))return int(c.fault);
P_adcbb_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0xe4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_adcbb_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0xe4ULL)))&(SlU(0xe4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0xe4ULL)))&(SlU(1)<<31))!=0),c);
P_adcbb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xe4ULL)),c);
P_adcbb_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adcbb_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_adcbb_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_adcbb_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adcbb_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adcbb_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adcbb_9:;
goto L_adcc0;
}
L_adcc0:{ // MOV dword ptr [EBP + 0x8],EAX
c.pc=0xadcc0;if(!sl_tick(c))return int(c.fault);
P_adcc0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_adcc0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adcc0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adcc0_3:;
goto L_adcc3;
}
L_adcc3:{ // ADD ESP,0x30
c.pc=0xadcc3;if(!sl_tick(c))return int(c.fault);
P_adcc3_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adcc3_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL)))&(SlU(0x30ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL)))&(SlU(1)<<31))!=0),c);
P_adcc3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x30ULL)),c);
P_adcc3_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adcc3_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_adcc3_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_adcc3_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adcc3_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adcc3_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adcc3_9:;
goto L_adcc6;
}
L_adcc6:{ // POP ESI
c.pc=0xadcc6;if(!sl_tick(c))return int(c.fault);
P_adcc6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_adcc6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adcc6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adcc6_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_adcc6_4:;
goto L_adcc7;
}
L_adcc7:{ // POP EDI
c.pc=0xadcc7;if(!sl_tick(c))return int(c.fault);
P_adcc7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_adcc7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adcc7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adcc7_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_adcc7_4:;
goto L_adcc8;
}
L_adcc8:{ // POP EBP
c.pc=0xadcc8;if(!sl_tick(c))return int(c.fault);
P_adcc8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_adcc8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adcc8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adcc8_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_adcc8_4:;
goto L_adcc9;
}
L_adcc9:{ // JMP 0x000ad7b4
c.pc=0xadcc9;if(!sl_tick(c))return int(c.fault);
P_adcc9_0:;
c.pc=0xad7b4;goto dispatch;
P_adcc9_1:;
goto L_adcce;
}
L_adcce:{ // PUSH EBP
c.pc=0xadcce;if(!sl_tick(c))return int(c.fault);
P_adcce_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_adcce_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_adcce_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_adcce_3:;
goto L_adccf;
}
L_adccf:{ // MOV EBP,ESP
c.pc=0xadccf;if(!sl_tick(c))return int(c.fault);
P_adccf_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_adccf_1:;
goto L_adcd1;
}
L_adcd1:{ // PUSH EDI
c.pc=0xadcd1;if(!sl_tick(c))return int(c.fault);
P_adcd1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_adcd1_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_adcd1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_adcd1_3:;
goto L_adcd2;
}
L_adcd2:{ // PUSH ESI
c.pc=0xadcd2;if(!sl_tick(c))return int(c.fault);
P_adcd2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_adcd2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_adcd2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_adcd2_3:;
goto L_adcd3;
}
L_adcd3:{ // PUSH EBX
c.pc=0xadcd3;if(!sl_tick(c))return int(c.fault);
P_adcd3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_adcd3_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_adcd3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_adcd3_3:;
goto L_adcd4;
}
L_adcd4:{ // SUB ESP,0x3c
c.pc=0xadcd4;if(!sl_tick(c))return int(c.fault);
P_adcd4_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x3cULL)),c);
P_adcd4_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x3cULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x3cULL)))&(SlU(1)<<31))!=0),c);
P_adcd4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x3cULL)),c);
P_adcd4_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adcd4_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_adcd4_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_adcd4_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adcd4_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adcd4_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adcd4_9:;
goto L_adcd7;
}
L_adcd7:{ // CALL 0x000c086c
c.pc=0xadcd7;if(!sl_tick(c))return int(c.fault);
P_adcd7_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_adcd7_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xadcdcULL),c);
P_adcd7_2:;
c.pc=0xc086c;goto dispatch;
P_adcd7_3:;
goto L_adcdc;
}
L_adcdc:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0xadcdc;if(!sl_tick(c))return int(c.fault);
P_adcdc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_adcdc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adcdc_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adcdc_3:;
goto L_adcdf;
}
L_adcdf:{ // MOV dword ptr [EBP + -0x1c],EAX
c.pc=0xadcdf;if(!sl_tick(c))return int(c.fault);
P_adcdf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_adcdf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adcdf_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adcdf_3:;
goto L_adce2;
}
L_adce2:{ // MOV ESI,dword ptr [EBP + 0xc]
c.pc=0xadce2;if(!sl_tick(c))return int(c.fault);
P_adce2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_adce2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adce2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adce2_3:;
goto L_adce5;
}
L_adce5:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xadce5;if(!sl_tick(c))return int(c.fault);
P_adce5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_adce5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adce5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adce5_3:;
goto L_adce8;
}
L_adce8:{ // MOV dword ptr [EBP + -0x20],EDX
c.pc=0xadce8;if(!sl_tick(c))return int(c.fault);
P_adce8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_adce8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_adce8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adce8_3:;
goto L_adceb;
}
L_adceb:{ // MOV EDI,dword ptr [EBP + 0x14]
c.pc=0xadceb;if(!sl_tick(c))return int(c.fault);
P_adceb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_adceb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adceb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adceb_3:;
goto L_adcee;
}
L_adcee:{ // MOV EAX,dword ptr [EBP + 0x18]
c.pc=0xadcee;if(!sl_tick(c))return int(c.fault);
P_adcee_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x18ULL)),c);
P_adcee_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adcee_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adcee_3:;
goto L_adcf1;
}
L_adcf1:{ // MOV dword ptr [EBP + -0x24],EAX
c.pc=0xadcf1;if(!sl_tick(c))return int(c.fault);
P_adcf1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_adcf1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adcf1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adcf1_3:;
goto L_adcf4;
}
L_adcf4:{ // CMP ESI,0x5
c.pc=0xadcf4;if(!sl_tick(c))return int(c.fault);
P_adcf4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_adcf4_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x5ULL)),c);
P_adcf4_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x5ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x5ULL)))&(SlU(1)<<31))!=0),c);
P_adcf4_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x5ULL)),c);
P_adcf4_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adcf4_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_adcf4_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_adcf4_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adcf4_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adcf4_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adcf4_10:;
goto L_adcf7;
}
L_adcf7:{ // JZ 0x000add2b
c.pc=0xadcf7;if(!sl_tick(c))return int(c.fault);
P_adcf7_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_add2b;}
P_adcf7_1:;
goto L_adcf9;
}
L_adcf9:{ // CMP ESI,0x3e8
c.pc=0xadcf9;if(!sl_tick(c))return int(c.fault);
P_adcf9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30a80,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_adcf9_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) < SlU(0x3e8ULL)),c);
P_adcf9_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^SlU(0x3e8ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)-SlU(0x3e8ULL)))&(SlU(1)<<31))!=0),c);
P_adcf9_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30b80,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) - SlU(0x3e8ULL)),c);
P_adcf9_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adcf9_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) == SlU(0x0ULL)),c);
P_adcf9_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) & SlU(0xffULL)),c);
P_adcf9_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adcf9_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adcf9_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adcf9_10:;
goto L_adcff;
}
L_adcff:{ // JZ 0x000add40
c.pc=0xadcff;if(!sl_tick(c))return int(c.fault);
P_adcff_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_add40;}
P_adcff_1:;
goto L_add01;
}
L_add01:{ // MOV dword ptr [ESP + 0x10],EAX
c.pc=0xadd01;if(!sl_tick(c))return int(c.fault);
P_add01_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x10ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_add01_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_add01_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_add01_3:;
goto L_add05;
}
L_add05:{ // MOV dword ptr [ESP + 0xc],EDI
c.pc=0xadd05;if(!sl_tick(c))return int(c.fault);
P_add05_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_add05_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_add05_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_add05_3:;
goto L_add09;
}
L_add09:{ // MOV dword ptr [ESP + 0x8],EDX
c.pc=0xadd09;if(!sl_tick(c))return int(c.fault);
P_add09_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_add09_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_add09_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_add09_3:;
goto L_add0d;
}
L_add0d:{ // MOV dword ptr [ESP + 0x4],ESI
c.pc=0xadd0d;if(!sl_tick(c))return int(c.fault);
P_add0d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_add0d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_add0d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_add0d_3:;
goto L_add11;
}
L_add11:{ // MOV EDX,dword ptr [EBP + -0x1c]
c.pc=0xadd11;if(!sl_tick(c))return int(c.fault);
P_add11_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_add11_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_add11_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_add11_3:;
goto L_add14;
}
L_add14:{ // MOV dword ptr [ESP],EDX
c.pc=0xadd14;if(!sl_tick(c))return int(c.fault);
P_add14_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_add14_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_add14_2:;
goto L_add17;
}
L_add17:{ // CALL 0x000a666e
c.pc=0xadd17;if(!sl_tick(c))return int(c.fault);
P_add17_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_add17_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xadd1cULL),c);
P_add17_2:;
c.pc=0xa666e;goto dispatch;
P_add17_3:;
goto L_add1c;
}
L_add1c:{ // CMP EAX,0xffffd581
c.pc=0xadd1c;if(!sl_tick(c))return int(c.fault);
P_add1c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < SlU(0xffffd581ULL)),c);
P_add1c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^SlU(0xffffd581ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-SlU(0xffffd581ULL)))&(SlU(1)<<31))!=0),c);
P_add1c_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30700,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - SlU(0xffffd581ULL)),c);
P_add1c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30700,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_add1c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30700,c) == SlU(0x0ULL)),c);
P_add1c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30700,c) & SlU(0xffULL)),c);
P_add1c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_add1c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_add1c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_add1c_9:;
goto L_add21;
}
L_add21:{ // JZ 0x000add54
c.pc=0xadd21;if(!sl_tick(c))return int(c.fault);
P_add21_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_add54;}
P_add21_1:;
goto L_add23;
}
L_add23:{ // ADD ESP,0x3c
c.pc=0xadd23;if(!sl_tick(c))return int(c.fault);
P_add23_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_add23_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(0x3cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(1)<<31))!=0),c);
P_add23_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x3cULL)),c);
P_add23_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_add23_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_add23_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_add23_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_add23_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_add23_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_add23_9:;
goto L_add26;
}
L_add26:{ // POP EBX
c.pc=0xadd26;if(!sl_tick(c))return int(c.fault);
P_add26_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add26_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add26_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add26_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add26_4:;
goto L_add27;
}
L_add27:{ // POP ESI
c.pc=0xadd27;if(!sl_tick(c))return int(c.fault);
P_add27_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add27_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add27_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add27_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add27_4:;
goto L_add28;
}
L_add28:{ // POP EDI
c.pc=0xadd28;if(!sl_tick(c))return int(c.fault);
P_add28_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add28_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add28_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add28_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add28_4:;
goto L_add29;
}
L_add29:{ // POP EBP
c.pc=0xadd29;if(!sl_tick(c))return int(c.fault);
P_add29_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add29_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add29_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add29_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add29_4:;
goto L_add2a;
}
L_add2a:{ // RET
c.pc=0xadd2a;if(!sl_tick(c))return int(c.fault);
P_add2a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add2a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add2a_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_add2a_3:;
goto L_add2b;
}
L_add2b:{ // CMP EDI,0x101
c.pc=0xadd2b;if(!sl_tick(c))return int(c.fault);
P_add2b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30a80,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_add2b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) < SlU(0x101ULL)),c);
P_add2b_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^SlU(0x101ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)-SlU(0x101ULL)))&(SlU(1)<<31))!=0),c);
P_add2b_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30b80,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) - SlU(0x101ULL)),c);
P_add2b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_add2b_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) == SlU(0x0ULL)),c);
P_add2b_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) & SlU(0xffULL)),c);
P_add2b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_add2b_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_add2b_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_add2b_10:;
goto L_add31;
}
L_add31:{ // JZ 0x000add7d
c.pc=0xadd31;if(!sl_tick(c))return int(c.fault);
P_add31_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_add7d;}
P_add31_1:;
goto L_add33;
}
L_add33:{ // MOV EAX,0xffffd583
c.pc=0xadd33;if(!sl_tick(c))return int(c.fault);
P_add33_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,SlU(0xffffd583ULL),c);
P_add33_1:;
goto L_add38;
}
L_add38:{ // ADD ESP,0x3c
c.pc=0xadd38;if(!sl_tick(c))return int(c.fault);
P_add38_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_add38_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(0x3cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(1)<<31))!=0),c);
P_add38_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x3cULL)),c);
P_add38_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_add38_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_add38_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_add38_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_add38_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_add38_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_add38_9:;
goto L_add3b;
}
L_add3b:{ // POP EBX
c.pc=0xadd3b;if(!sl_tick(c))return int(c.fault);
P_add3b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add3b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add3b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add3b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add3b_4:;
goto L_add3c;
}
L_add3c:{ // POP ESI
c.pc=0xadd3c;if(!sl_tick(c))return int(c.fault);
P_add3c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add3c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add3c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add3c_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add3c_4:;
goto L_add3d;
}
L_add3d:{ // POP EDI
c.pc=0xadd3d;if(!sl_tick(c))return int(c.fault);
P_add3d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add3d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add3d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add3d_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add3d_4:;
goto L_add3e;
}
L_add3e:{ // POP EBP
c.pc=0xadd3e;if(!sl_tick(c))return int(c.fault);
P_add3e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add3e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add3e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add3e_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add3e_4:;
goto L_add3f;
}
L_add3f:{ // RET
c.pc=0xadd3f;if(!sl_tick(c))return int(c.fault);
P_add3f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add3f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add3f_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_add3f_3:;
goto L_add40;
}
L_add40:{ // MOV EDX,dword ptr [EBP + -0x20]
c.pc=0xadd40;if(!sl_tick(c))return int(c.fault);
P_add40_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_add40_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_add40_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_add40_3:;
goto L_add43;
}
L_add43:{ // TEST EDX,EDX
c.pc=0xadd43;if(!sl_tick(c))return int(c.fault);
P_add43_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_add43_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_add43_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_add43_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_add43_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_add43_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_add43_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_add43_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_add43_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_add43_9:;
goto L_add45;
}
L_add45:{ // JZ 0x000add92
c.pc=0xadd45;if(!sl_tick(c))return int(c.fault);
P_add45_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_add92;}
P_add45_1:;
goto L_add47;
}
L_add47:{ // MOV EAX,0xffffd58e
c.pc=0xadd47;if(!sl_tick(c))return int(c.fault);
P_add47_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,SlU(0xffffd58eULL),c);
P_add47_1:;
goto L_add4c;
}
L_add4c:{ // ADD ESP,0x3c
c.pc=0xadd4c;if(!sl_tick(c))return int(c.fault);
P_add4c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_add4c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(0x3cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(1)<<31))!=0),c);
P_add4c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x3cULL)),c);
P_add4c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_add4c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_add4c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_add4c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_add4c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_add4c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_add4c_9:;
goto L_add4f;
}
L_add4f:{ // POP EBX
c.pc=0xadd4f;if(!sl_tick(c))return int(c.fault);
P_add4f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add4f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add4f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add4f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add4f_4:;
goto L_add50;
}
L_add50:{ // POP ESI
c.pc=0xadd50;if(!sl_tick(c))return int(c.fault);
P_add50_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add50_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add50_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add50_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add50_4:;
goto L_add51;
}
L_add51:{ // POP EDI
c.pc=0xadd51;if(!sl_tick(c))return int(c.fault);
P_add51_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add51_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add51_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add51_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add51_4:;
goto L_add52;
}
L_add52:{ // POP EBP
c.pc=0xadd52;if(!sl_tick(c))return int(c.fault);
P_add52_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add52_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add52_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add52_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add52_4:;
goto L_add53;
}
L_add53:{ // RET
c.pc=0xadd53;if(!sl_tick(c))return int(c.fault);
P_add53_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add53_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add53_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_add53_3:;
goto L_add54;
}
L_add54:{ // MOV EAX,dword ptr [EBP + -0x24]
c.pc=0xadd54;if(!sl_tick(c))return int(c.fault);
P_add54_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_add54_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_add54_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_add54_3:;
goto L_add57;
}
L_add57:{ // MOV dword ptr [EBP + 0x18],EAX
c.pc=0xadd57;if(!sl_tick(c))return int(c.fault);
P_add57_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x18ULL)),c);
P_add57_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_add57_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_add57_3:;
goto L_add5a;
}
L_add5a:{ // MOV dword ptr [EBP + 0x14],EDI
c.pc=0xadd5a;if(!sl_tick(c))return int(c.fault);
P_add5a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_add5a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_add5a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_add5a_3:;
goto L_add5d;
}
L_add5d:{ // MOV EDX,dword ptr [EBP + -0x20]
c.pc=0xadd5d;if(!sl_tick(c))return int(c.fault);
P_add5d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_add5d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_add5d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_add5d_3:;
goto L_add60;
}
L_add60:{ // MOV dword ptr [EBP + 0x10],EDX
c.pc=0xadd60;if(!sl_tick(c))return int(c.fault);
P_add60_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_add60_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_add60_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_add60_3:;
goto L_add63;
}
L_add63:{ // MOV dword ptr [EBP + 0xc],ESI
c.pc=0xadd63;if(!sl_tick(c))return int(c.fault);
P_add63_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_add63_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_add63_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_add63_3:;
goto L_add66;
}
L_add66:{ // MOV EAX,dword ptr [EBP + -0x1c]
c.pc=0xadd66;if(!sl_tick(c))return int(c.fault);
P_add66_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_add66_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_add66_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_add66_3:;
goto L_add69;
}
L_add69:{ // ADD EAX,0xe4
c.pc=0xadd69;if(!sl_tick(c))return int(c.fault);
P_add69_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0xe4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_add69_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0xe4ULL)))&(SlU(0xe4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0xe4ULL)))&(SlU(1)<<31))!=0),c);
P_add69_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xe4ULL)),c);
P_add69_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_add69_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_add69_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_add69_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_add69_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_add69_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_add69_9:;
goto L_add6e;
}
L_add6e:{ // MOV dword ptr [EBP + 0x8],EAX
c.pc=0xadd6e;if(!sl_tick(c))return int(c.fault);
P_add6e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_add6e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_add6e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_add6e_3:;
goto L_add71;
}
L_add71:{ // ADD ESP,0x3c
c.pc=0xadd71;if(!sl_tick(c))return int(c.fault);
P_add71_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_add71_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(0x3cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(1)<<31))!=0),c);
P_add71_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x3cULL)),c);
P_add71_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_add71_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_add71_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_add71_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_add71_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_add71_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_add71_9:;
goto L_add74;
}
L_add74:{ // POP EBX
c.pc=0xadd74;if(!sl_tick(c))return int(c.fault);
P_add74_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add74_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add74_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add74_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add74_4:;
goto L_add75;
}
L_add75:{ // POP ESI
c.pc=0xadd75;if(!sl_tick(c))return int(c.fault);
P_add75_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add75_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add75_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add75_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add75_4:;
goto L_add76;
}
L_add76:{ // POP EDI
c.pc=0xadd76;if(!sl_tick(c))return int(c.fault);
P_add76_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add76_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add76_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add76_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add76_4:;
goto L_add77;
}
L_add77:{ // POP EBP
c.pc=0xadd77;if(!sl_tick(c))return int(c.fault);
P_add77_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add77_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add77_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add77_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add77_4:;
goto L_add78;
}
L_add78:{ // JMP 0x000ad810
c.pc=0xadd78;if(!sl_tick(c))return int(c.fault);
P_add78_0:;
c.pc=0xad810;goto dispatch;
P_add78_1:;
goto L_add7d;
}
L_add7d:{ // LEA EAX,[EBX + 0x3fe]
c.pc=0xadd7d;if(!sl_tick(c))return int(c.fault);
P_add7d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x3feULL)),c);
P_add7d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_add7d_2:;
goto L_add83;
}
L_add83:{ // MOV EDX,dword ptr [EBP + -0x24]
c.pc=0xadd83;if(!sl_tick(c))return int(c.fault);
P_add83_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_add83_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_add83_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_add83_3:;
goto L_add86;
}
L_add86:{ // MOV dword ptr [EDX],EAX
c.pc=0xadd86;if(!sl_tick(c))return int(c.fault);
P_add86_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_add86_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_add86_2:;
goto L_add88;
}
L_add88:{ // XOR EAX,EAX
c.pc=0xadd88;if(!sl_tick(c))return int(c.fault);
P_add88_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_add88_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_add88_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_add88_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_add88_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_add88_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_add88_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_add88_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_add88_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_add88_9:;
goto L_add8a;
}
L_add8a:{ // ADD ESP,0x3c
c.pc=0xadd8a;if(!sl_tick(c))return int(c.fault);
P_add8a_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_add8a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(0x3cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(1)<<31))!=0),c);
P_add8a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x3cULL)),c);
P_add8a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_add8a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_add8a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_add8a_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_add8a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_add8a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_add8a_9:;
goto L_add8d;
}
L_add8d:{ // POP EBX
c.pc=0xadd8d;if(!sl_tick(c))return int(c.fault);
P_add8d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add8d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add8d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add8d_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add8d_4:;
goto L_add8e;
}
L_add8e:{ // POP ESI
c.pc=0xadd8e;if(!sl_tick(c))return int(c.fault);
P_add8e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add8e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add8e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add8e_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add8e_4:;
goto L_add8f;
}
L_add8f:{ // POP EDI
c.pc=0xadd8f;if(!sl_tick(c))return int(c.fault);
P_add8f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add8f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add8f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add8f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add8f_4:;
goto L_add90;
}
L_add90:{ // POP EBP
c.pc=0xadd90;if(!sl_tick(c))return int(c.fault);
P_add90_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_add90_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add90_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add90_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_add90_4:;
goto L_add91;
}
L_add91:{ // RET
c.pc=0xadd91;if(!sl_tick(c))return int(c.fault);
P_add91_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_add91_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_add91_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_add91_3:;
goto L_add92;
}
L_add92:{ // MOV EDX,dword ptr [EBP + -0x1c]
c.pc=0xadd92;if(!sl_tick(c))return int(c.fault);
P_add92_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_add92_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_add92_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_add92_3:;
goto L_add95;
}
L_add95:{ // MOV EAX,dword ptr [EDX]
c.pc=0xadd95;if(!sl_tick(c))return int(c.fault);
P_add95_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_add95_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_add95_2:;
goto L_add97;
}
L_add97:{ // MOV EDX,dword ptr [EBP + -0x24]
c.pc=0xadd97;if(!sl_tick(c))return int(c.fault);
P_add97_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_add97_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_add97_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_add97_3:;
goto L_add9a;
}
L_add9a:{ // MOV dword ptr [EBP + 0xc],EDX
c.pc=0xadd9a;if(!sl_tick(c))return int(c.fault);
P_add9a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_add9a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_add9a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_add9a_3:;
goto L_add9d;
}
L_add9d:{ // MOV EDX,dword ptr [EBP + -0x1c]
c.pc=0xadd9d;if(!sl_tick(c))return int(c.fault);
P_add9d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_add9d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_add9d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_add9d_3:;
goto L_adda0;
}
L_adda0:{ // MOV dword ptr [EBP + 0x8],EDX
c.pc=0xadda0;if(!sl_tick(c))return int(c.fault);
P_adda0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_adda0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_adda0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adda0_3:;
goto L_adda3;
}
L_adda3:{ // MOV ECX,dword ptr [EAX + 0xf4]
c.pc=0xadda3;if(!sl_tick(c))return int(c.fault);
P_adda3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xf4ULL)),c);
P_adda3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_adda3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adda3_3:;
goto L_adda9;
}
L_adda9:{ // ADD ESP,0x3c
c.pc=0xadda9;if(!sl_tick(c))return int(c.fault);
P_adda9_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adda9_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(0x3cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(1)<<31))!=0),c);
P_adda9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x3cULL)),c);
P_adda9_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adda9_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_adda9_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_adda9_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adda9_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adda9_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adda9_9:;
goto L_addac;
}
L_addac:{ // POP EBX
c.pc=0xaddac;if(!sl_tick(c))return int(c.fault);
P_addac_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_addac_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_addac_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_addac_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_addac_4:;
goto L_addad;
}
L_addad:{ // POP ESI
c.pc=0xaddad;if(!sl_tick(c))return int(c.fault);
P_addad_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_addad_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_addad_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_addad_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_addad_4:;
goto L_addae;
}
L_addae:{ // POP EDI
c.pc=0xaddae;if(!sl_tick(c))return int(c.fault);
P_addae_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_addae_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_addae_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_addae_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_addae_4:;
goto L_addaf;
}
L_addaf:{ // POP EBP
c.pc=0xaddaf;if(!sl_tick(c))return int(c.fault);
P_addaf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_addaf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_addaf_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_addaf_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_addaf_4:;
goto L_addb0;
}
L_addb0:{ // JMP ECX
c.pc=0xaddb0;if(!sl_tick(c))return int(c.fault);
P_addb0_0:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c));goto dispatch;
P_addb0_1:;
goto L_addb2;
}
L_addb2:{ // PUSH EBP
c.pc=0xaddb2;if(!sl_tick(c))return int(c.fault);
P_addb2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_addb2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_addb2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_addb2_3:;
goto L_addb3;
}
L_addb3:{ // MOV EBP,ESP
c.pc=0xaddb3;if(!sl_tick(c))return int(c.fault);
P_addb3_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_addb3_1:;
goto L_addb5;
}
L_addb5:{ // PUSH EDI
c.pc=0xaddb5;if(!sl_tick(c))return int(c.fault);
P_addb5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_addb5_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_addb5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_addb5_3:;
goto L_addb6;
}
L_addb6:{ // PUSH ESI
c.pc=0xaddb6;if(!sl_tick(c))return int(c.fault);
P_addb6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_addb6_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_addb6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_addb6_3:;
goto L_addb7;
}
L_addb7:{ // SUB ESP,0x30
c.pc=0xaddb7;if(!sl_tick(c))return int(c.fault);
P_addb7_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x30ULL)),c);
P_addb7_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x30ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x30ULL)))&(SlU(1)<<31))!=0),c);
P_addb7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x30ULL)),c);
P_addb7_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_addb7_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_addb7_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_addb7_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_addb7_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_addb7_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_addb7_9:;
goto L_addba;
}
L_addba:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0xaddba;if(!sl_tick(c))return int(c.fault);
P_addba_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_addba_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_addba_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_addba_3:;
goto L_addbd;
}
L_addbd:{ // MOV dword ptr [EBP + -0xc],EAX
c.pc=0xaddbd;if(!sl_tick(c))return int(c.fault);
P_addbd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_addbd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_addbd_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_addbd_3:;
goto L_addc0;
}
L_addc0:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0xaddc0;if(!sl_tick(c))return int(c.fault);
P_addc0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_addc0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_addc0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_addc0_3:;
goto L_addc3;
}
L_addc3:{ // MOV dword ptr [EBP + -0x10],EAX
c.pc=0xaddc3;if(!sl_tick(c))return int(c.fault);
P_addc3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_addc3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_addc3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_addc3_3:;
goto L_addc6;
}
L_addc6:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xaddc6;if(!sl_tick(c))return int(c.fault);
P_addc6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_addc6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_addc6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_addc6_3:;
goto L_addc9;
}
L_addc9:{ // MOV dword ptr [EBP + -0x14],EAX
c.pc=0xaddc9;if(!sl_tick(c))return int(c.fault);
P_addc9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_addc9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_addc9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_addc9_3:;
goto L_addcc;
}
L_addcc:{ // MOV EAX,dword ptr [EBP + 0x14]
c.pc=0xaddcc;if(!sl_tick(c))return int(c.fault);
P_addcc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_addcc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_addcc_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_addcc_3:;
goto L_addcf;
}
L_addcf:{ // MOV dword ptr [EBP + -0x18],EAX
c.pc=0xaddcf;if(!sl_tick(c))return int(c.fault);
P_addcf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_addcf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_addcf_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_addcf_3:;
goto L_addd2;
}
L_addd2:{ // MOV EDI,dword ptr [EBP + 0x18]
c.pc=0xaddd2;if(!sl_tick(c))return int(c.fault);
P_addd2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x18ULL)),c);
P_addd2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_addd2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_addd2_3:;
goto L_addd5;
}
L_addd5:{ // MOV ESI,dword ptr [EBP + 0x1c]
c.pc=0xaddd5;if(!sl_tick(c))return int(c.fault);
P_addd5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x1cULL)),c);
P_addd5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_addd5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_addd5_3:;
goto L_addd8;
}
L_addd8:{ // MOV dword ptr [ESP + 0x14],ESI
c.pc=0xaddd8;if(!sl_tick(c))return int(c.fault);
P_addd8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x14ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_addd8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_addd8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_addd8_3:;
goto L_adddc;
}
L_adddc:{ // MOV dword ptr [ESP + 0x10],EDI
c.pc=0xadddc;if(!sl_tick(c))return int(c.fault);
P_adddc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x10ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adddc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_adddc_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adddc_3:;
goto L_adde0;
}
L_adde0:{ // MOV dword ptr [ESP + 0xc],EAX
c.pc=0xadde0;if(!sl_tick(c))return int(c.fault);
P_adde0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adde0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adde0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adde0_3:;
goto L_adde4;
}
L_adde4:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0xadde4;if(!sl_tick(c))return int(c.fault);
P_adde4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_adde4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adde4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adde4_3:;
goto L_adde7;
}
L_adde7:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0xadde7;if(!sl_tick(c))return int(c.fault);
P_adde7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adde7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adde7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adde7_3:;
goto L_addeb;
}
L_addeb:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0xaddeb;if(!sl_tick(c))return int(c.fault);
P_addeb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_addeb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_addeb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_addeb_3:;
goto L_addee;
}
L_addee:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xaddee;if(!sl_tick(c))return int(c.fault);
P_addee_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_addee_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_addee_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_addee_3:;
goto L_addf2;
}
L_addf2:{ // MOV EAX,dword ptr [EBP + -0xc]
c.pc=0xaddf2;if(!sl_tick(c))return int(c.fault);
P_addf2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_addf2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_addf2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_addf2_3:;
goto L_addf5;
}
L_addf5:{ // MOV dword ptr [ESP],EAX
c.pc=0xaddf5;if(!sl_tick(c))return int(c.fault);
P_addf5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_addf5_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_addf5_2:;
goto L_addf8;
}
L_addf8:{ // CALL 0x000a6678
c.pc=0xaddf8;if(!sl_tick(c))return int(c.fault);
P_addf8_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_addf8_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xaddfdULL),c);
P_addf8_2:;
c.pc=0xa6678;goto dispatch;
P_addf8_3:;
goto L_addfd;
}
L_addfd:{ // CMP EAX,0xffffd581
c.pc=0xaddfd;if(!sl_tick(c))return int(c.fault);
P_addfd_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < SlU(0xffffd581ULL)),c);
P_addfd_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^SlU(0xffffd581ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-SlU(0xffffd581ULL)))&(SlU(1)<<31))!=0),c);
P_addfd_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30700,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - SlU(0xffffd581ULL)),c);
P_addfd_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30700,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_addfd_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30700,c) == SlU(0x0ULL)),c);
P_addfd_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30700,c) & SlU(0xffULL)),c);
P_addfd_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_addfd_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_addfd_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_addfd_9:;
goto L_ade02;
}
L_ade02:{ // JZ 0x000ade0b
c.pc=0xade02;if(!sl_tick(c))return int(c.fault);
P_ade02_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_ade0b;}
P_ade02_1:;
goto L_ade04;
}
L_ade04:{ // ADD ESP,0x30
c.pc=0xade04;if(!sl_tick(c))return int(c.fault);
P_ade04_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ade04_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL)))&(SlU(0x30ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL)))&(SlU(1)<<31))!=0),c);
P_ade04_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x30ULL)),c);
P_ade04_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ade04_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ade04_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ade04_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ade04_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ade04_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ade04_9:;
goto L_ade07;
}
L_ade07:{ // POP ESI
c.pc=0xade07;if(!sl_tick(c))return int(c.fault);
P_ade07_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ade07_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ade07_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ade07_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ade07_4:;
goto L_ade08;
}
L_ade08:{ // POP EDI
c.pc=0xade08;if(!sl_tick(c))return int(c.fault);
P_ade08_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ade08_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ade08_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ade08_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ade08_4:;
goto L_ade09;
}
L_ade09:{ // POP EBP
c.pc=0xade09;if(!sl_tick(c))return int(c.fault);
P_ade09_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ade09_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ade09_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ade09_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ade09_4:;
goto L_ade0a;
}
L_ade0a:{ // RET
c.pc=0xade0a;if(!sl_tick(c))return int(c.fault);
P_ade0a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ade0a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ade0a_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_ade0a_3:;
goto L_ade0b;
}
L_ade0b:{ // MOV dword ptr [EBP + 0x1c],ESI
c.pc=0xade0b;if(!sl_tick(c))return int(c.fault);
P_ade0b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x1cULL)),c);
P_ade0b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ade0b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ade0b_3:;
goto L_ade0e;
}
L_ade0e:{ // MOV dword ptr [EBP + 0x18],EDI
c.pc=0xade0e;if(!sl_tick(c))return int(c.fault);
P_ade0e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x18ULL)),c);
P_ade0e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_ade0e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ade0e_3:;
goto L_ade11;
}
L_ade11:{ // MOV EAX,dword ptr [EBP + -0x18]
c.pc=0xade11;if(!sl_tick(c))return int(c.fault);
P_ade11_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_ade11_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ade11_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ade11_3:;
goto L_ade14;
}
L_ade14:{ // MOV dword ptr [EBP + 0x14],EAX
c.pc=0xade14;if(!sl_tick(c))return int(c.fault);
P_ade14_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_ade14_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ade14_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ade14_3:;
goto L_ade17;
}
L_ade17:{ // MOV EAX,dword ptr [EBP + -0x14]
c.pc=0xade17;if(!sl_tick(c))return int(c.fault);
P_ade17_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_ade17_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ade17_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ade17_3:;
goto L_ade1a;
}
L_ade1a:{ // MOV dword ptr [EBP + 0x10],EAX
c.pc=0xade1a;if(!sl_tick(c))return int(c.fault);
P_ade1a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_ade1a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ade1a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ade1a_3:;
goto L_ade1d;
}
L_ade1d:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0xade1d;if(!sl_tick(c))return int(c.fault);
P_ade1d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_ade1d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ade1d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ade1d_3:;
goto L_ade20;
}
L_ade20:{ // MOV dword ptr [EBP + 0xc],EAX
c.pc=0xade20;if(!sl_tick(c))return int(c.fault);
P_ade20_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_ade20_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ade20_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ade20_3:;
goto L_ade23;
}
L_ade23:{ // MOV EAX,dword ptr [EBP + -0xc]
c.pc=0xade23;if(!sl_tick(c))return int(c.fault);
P_ade23_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_ade23_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ade23_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ade23_3:;
goto L_ade26;
}
L_ade26:{ // ADD EAX,0xe4
c.pc=0xade26;if(!sl_tick(c))return int(c.fault);
P_ade26_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0xe4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_ade26_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0xe4ULL)))&(SlU(0xe4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0xe4ULL)))&(SlU(1)<<31))!=0),c);
P_ade26_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xe4ULL)),c);
P_ade26_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ade26_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_ade26_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_ade26_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ade26_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ade26_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ade26_9:;
goto L_ade2b;
}
L_ade2b:{ // MOV dword ptr [EBP + 0x8],EAX
c.pc=0xade2b;if(!sl_tick(c))return int(c.fault);
P_ade2b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_ade2b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ade2b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ade2b_3:;
goto L_ade2e;
}
L_ade2e:{ // ADD ESP,0x30
c.pc=0xade2e;if(!sl_tick(c))return int(c.fault);
P_ade2e_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ade2e_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL)))&(SlU(0x30ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x30ULL)))&(SlU(1)<<31))!=0),c);
P_ade2e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x30ULL)),c);
P_ade2e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ade2e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ade2e_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ade2e_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ade2e_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ade2e_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ade2e_9:;
goto L_ade31;
}
L_ade31:{ // POP ESI
c.pc=0xade31;if(!sl_tick(c))return int(c.fault);
P_ade31_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ade31_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ade31_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ade31_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ade31_4:;
goto L_ade32;
}
L_ade32:{ // POP EDI
c.pc=0xade32;if(!sl_tick(c))return int(c.fault);
P_ade32_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ade32_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ade32_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ade32_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ade32_4:;
goto L_ade33;
}
L_ade33:{ // POP EBP
c.pc=0xade33;if(!sl_tick(c))return int(c.fault);
P_ade33_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ade33_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ade33_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ade33_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ade33_4:;
goto L_ade34;
}
L_ade34:{ // JMP 0x000ad85a
c.pc=0xade34;if(!sl_tick(c))return int(c.fault);
P_ade34_0:;
c.pc=0xad85a;goto dispatch;
P_ade34_1:;
c.pc=0xade39;goto dispatch;
}
L_ade3a:{ // PUSH EBP
c.pc=0xade3a;if(!sl_tick(c))return int(c.fault);
P_ade3a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_ade3a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ade3a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ade3a_3:;
goto L_ade3b;
}
L_ade3b:{ // MOV EBP,ESP
c.pc=0xade3b;if(!sl_tick(c))return int(c.fault);
P_ade3b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_ade3b_1:;
goto L_ade3d;
}
L_ade3d:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0xade3d;if(!sl_tick(c))return int(c.fault);
P_ade3d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_ade3d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ade3d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ade3d_3:;
goto L_ade40;
}
L_ade40:{ // MOV dword ptr [EAX],0x0
c.pc=0xade40;if(!sl_tick(c))return int(c.fault);
P_ade40_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_ade40_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ade40_2:;
goto L_ade46;
}
L_ade46:{ // XOR EAX,EAX
c.pc=0xade46;if(!sl_tick(c))return int(c.fault);
P_ade46_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_ade46_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_ade46_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_ade46_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ade46_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_ade46_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_ade46_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ade46_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ade46_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ade46_9:;
goto L_ade48;
}
L_ade48:{ // POP EBP
c.pc=0xade48;if(!sl_tick(c))return int(c.fault);
P_ade48_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ade48_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ade48_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ade48_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ade48_4:;
goto L_ade49;
}
L_ade49:{ // RET
c.pc=0xade49;if(!sl_tick(c))return int(c.fault);
P_ade49_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ade49_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ade49_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_ade49_3:;
goto L_ade4a;
}
L_ade4a:{ // PUSH EBP
c.pc=0xade4a;if(!sl_tick(c))return int(c.fault);
P_ade4a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_ade4a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ade4a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ade4a_3:;
goto L_ade4b;
}
L_ade4b:{ // MOV EBP,ESP
c.pc=0xade4b;if(!sl_tick(c))return int(c.fault);
P_ade4b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_ade4b_1:;
goto L_ade4d;
}
L_ade4d:{ // SUB ESP,0x48
c.pc=0xade4d;if(!sl_tick(c))return int(c.fault);
P_ade4d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x48ULL)),c);
P_ade4d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x48ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x48ULL)))&(SlU(1)<<31))!=0),c);
P_ade4d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x48ULL)),c);
P_ade4d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ade4d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ade4d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ade4d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ade4d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ade4d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ade4d_9:;
goto L_ade50;
}
L_ade50:{ // MOV ECX,dword ptr [EBP + 0x8]
c.pc=0xade50;if(!sl_tick(c))return int(c.fault);
P_ade50_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_ade50_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ade50_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ade50_3:;
goto L_ade53;
}
L_ade53:{ // MOV dword ptr [EBP + -0x20],0x2
c.pc=0xade53;if(!sl_tick(c))return int(c.fault);
P_ade53_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_ade53_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x2ULL),c);
P_ade53_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ade53_3:;
goto L_ade5a;
}
L_ade5a:{ // MOVZX EAX,byte ptr [EBP + 0x10]
c.pc=0xade5a;if(!sl_tick(c))return int(c.fault);
P_ade5a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_ade5a_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ade5a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_ade5a_3:;
goto L_ade5e;
}
L_ade5e:{ // CVTSI2SS XMM0,EAX
c.pc=0xade5e;if(!sl_tick(c))return int(c.fault);
P_ade5e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<float>(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32))),c);
P_ade5e_1:;
goto L_ade62;
}
L_ade62:{ // MOVSS dword ptr [EBP + -0x1c],XMM0
c.pc=0xade62;if(!sl_tick(c))return int(c.fault);
P_ade62_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_ade62_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_ade62_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ade62_3:;
goto L_ade67;
}
L_ade67:{ // MOVZX EAX,byte ptr [EBP + 0x14]
c.pc=0xade67;if(!sl_tick(c))return int(c.fault);
P_ade67_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_ade67_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ade67_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_ade67_3:;
goto L_ade6b;
}
L_ade6b:{ // CVTSI2SS XMM0,EAX
c.pc=0xade6b;if(!sl_tick(c))return int(c.fault);
P_ade6b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<float>(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32))),c);
P_ade6b_1:;
goto L_ade6f;
}
L_ade6f:{ // MOVSS dword ptr [EBP + -0x18],XMM0
c.pc=0xade6f;if(!sl_tick(c))return int(c.fault);
P_ade6f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_ade6f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_ade6f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ade6f_3:;
goto L_ade74;
}
L_ade74:{ // MOV EDX,dword ptr [ECX]
c.pc=0xade74;if(!sl_tick(c))return int(c.fault);
P_ade74_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c),c);
P_ade74_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ade74_2:;
goto L_ade76;
}
L_ade76:{ // LEA EAX,[EBP + -0x20]
c.pc=0xade76;if(!sl_tick(c))return int(c.fault);
P_ade76_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_ade76_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_ade76_2:;
goto L_ade79;
}
L_ade79:{ // MOV dword ptr [ESP + 0x14],EAX
c.pc=0xade79;if(!sl_tick(c))return int(c.fault);
P_ade79_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x14ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ade79_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ade79_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ade79_3:;
goto L_ade7d;
}
L_ade7d:{ // MOV EAX,dword ptr [EBP + 0x18]
c.pc=0xade7d;if(!sl_tick(c))return int(c.fault);
P_ade7d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x18ULL)),c);
P_ade7d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ade7d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ade7d_3:;
goto L_ade80;
}
L_ade80:{ // MOV dword ptr [ESP + 0x10],EAX
c.pc=0xade80;if(!sl_tick(c))return int(c.fault);
P_ade80_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x10ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ade80_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ade80_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ade80_3:;
goto L_ade84;
}
L_ade84:{ // LEA EAX,[EBP + -0xc]
c.pc=0xade84;if(!sl_tick(c))return int(c.fault);
P_ade84_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_ade84_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_ade84_2:;
goto L_ade87;
}
L_ade87:{ // MOV dword ptr [ESP + 0xc],EAX
c.pc=0xade87;if(!sl_tick(c))return int(c.fault);
P_ade87_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ade87_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ade87_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ade87_3:;
goto L_ade8b;
}
L_ade8b:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0xade8b;if(!sl_tick(c))return int(c.fault);
P_ade8b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_ade8b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ade8b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ade8b_3:;
goto L_ade8e;
}
L_ade8e:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0xade8e;if(!sl_tick(c))return int(c.fault);
P_ade8e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ade8e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ade8e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ade8e_3:;
goto L_ade92;
}
L_ade92:{ // MOV dword ptr [ESP + 0x4],0xffffffff
c.pc=0xade92;if(!sl_tick(c))return int(c.fault);
P_ade92_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ade92_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0xffffffffULL),c);
P_ade92_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ade92_3:;
goto L_ade9a;
}
L_ade9a:{ // MOV dword ptr [ESP],ECX
c.pc=0xade9a;if(!sl_tick(c))return int(c.fault);
P_ade9a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_ade9a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ade9a_2:;
goto L_ade9d;
}
L_ade9d:{ // CALL dword ptr [EDX + 0xe4]
c.pc=0xade9d;if(!sl_tick(c))return int(c.fault);
P_ade9d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0xe4ULL)),c);
P_ade9d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_ade9d_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ade9d_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ade9d_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xadea3ULL),c);
P_ade9d_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_ade9d_6:;
goto L_adea3;
}
L_adea3:{ // LEAVE
c.pc=0xadea3;if(!sl_tick(c))return int(c.fault);
P_adea3_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_adea3_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adea3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adea3_3:;
goto L_adea4;
}
L_adea4:{ // RET
c.pc=0xadea4;if(!sl_tick(c))return int(c.fault);
P_adea4_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adea4_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adea4_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_adea4_3:;
c.pc=0xadea5;goto dispatch;
}
L_adea6:{ // PUSH EBP
c.pc=0xadea6;if(!sl_tick(c))return int(c.fault);
P_adea6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_adea6_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_adea6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_adea6_3:;
goto L_adea7;
}
L_adea7:{ // MOV EBP,ESP
c.pc=0xadea7;if(!sl_tick(c))return int(c.fault);
P_adea7_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_adea7_1:;
goto L_adea9;
}
L_adea9:{ // SUB ESP,0x18
c.pc=0xadea9;if(!sl_tick(c))return int(c.fault);
P_adea9_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x18ULL)),c);
P_adea9_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x18ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x18ULL)))&(SlU(1)<<31))!=0),c);
P_adea9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x18ULL)),c);
P_adea9_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adea9_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_adea9_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_adea9_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adea9_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adea9_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adea9_9:;
goto L_adeac;
}
L_adeac:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0xadeac;if(!sl_tick(c))return int(c.fault);
P_adeac_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_adeac_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adeac_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adeac_3:;
goto L_adeaf;
}
L_adeaf:{ // MOV ECX,dword ptr [EDX]
c.pc=0xadeaf;if(!sl_tick(c))return int(c.fault);
P_adeaf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_adeaf_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adeaf_2:;
goto L_adeb1;
}
L_adeb1:{ // MOV EAX,dword ptr [EBP + 0x18]
c.pc=0xadeb1;if(!sl_tick(c))return int(c.fault);
P_adeb1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x18ULL)),c);
P_adeb1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adeb1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adeb1_3:;
goto L_adeb4;
}
L_adeb4:{ // MOV dword ptr [ESP + 0xc],EAX
c.pc=0xadeb4;if(!sl_tick(c))return int(c.fault);
P_adeb4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adeb4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adeb4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adeb4_3:;
goto L_adeb8;
}
L_adeb8:{ // MOVZX EAX,byte ptr [EBP + 0x10]
c.pc=0xadeb8;if(!sl_tick(c))return int(c.fault);
P_adeb8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_adeb8_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adeb8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_adeb8_3:;
goto L_adebc;
}
L_adebc:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0xadebc;if(!sl_tick(c))return int(c.fault);
P_adebc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adebc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adebc_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adebc_3:;
goto L_adec0;
}
L_adec0:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0xadec0;if(!sl_tick(c))return int(c.fault);
P_adec0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_adec0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adec0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adec0_3:;
goto L_adec3;
}
L_adec3:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xadec3;if(!sl_tick(c))return int(c.fault);
P_adec3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adec3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adec3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adec3_3:;
goto L_adec7;
}
L_adec7:{ // MOV dword ptr [ESP],EDX
c.pc=0xadec7;if(!sl_tick(c))return int(c.fault);
P_adec7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_adec7_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adec7_2:;
goto L_adeca;
}
L_adeca:{ // CALL dword ptr [ECX + 0xe8]
c.pc=0xadeca;if(!sl_tick(c))return int(c.fault);
P_adeca_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0xe8ULL)),c);
P_adeca_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_adeca_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adeca_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_adeca_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xaded0ULL),c);
P_adeca_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_adeca_6:;
goto L_aded0;
}
L_aded0:{ // LEAVE
c.pc=0xaded0;if(!sl_tick(c))return int(c.fault);
P_aded0_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_aded0_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_aded0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_aded0_3:;
goto L_aded1;
}
L_aded1:{ // RET
c.pc=0xaded1;if(!sl_tick(c))return int(c.fault);
P_aded1_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_aded1_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_aded1_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_aded1_3:;
goto L_aded2;
}
L_aded2:{ // PUSH EBP
c.pc=0xaded2;if(!sl_tick(c))return int(c.fault);
P_aded2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_aded2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_aded2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_aded2_3:;
goto L_aded3;
}
L_aded3:{ // MOV EBP,ESP
c.pc=0xaded3;if(!sl_tick(c))return int(c.fault);
P_aded3_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_aded3_1:;
goto L_aded5;
}
L_aded5:{ // PUSH EBX
c.pc=0xaded5;if(!sl_tick(c))return int(c.fault);
P_aded5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_aded5_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_aded5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_aded5_3:;
goto L_aded6;
}
L_aded6:{ // SUB ESP,0x44
c.pc=0xaded6;if(!sl_tick(c))return int(c.fault);
P_aded6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x44ULL)),c);
P_aded6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x44ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x44ULL)))&(SlU(1)<<31))!=0),c);
P_aded6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x44ULL)),c);
P_aded6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_aded6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_aded6_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_aded6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_aded6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_aded6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_aded6_9:;
goto L_aded9;
}
L_aded9:{ // CALL 0x000c086c
c.pc=0xaded9;if(!sl_tick(c))return int(c.fault);
P_aded9_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_aded9_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xadedeULL),c);
P_aded9_2:;
c.pc=0xc086c;goto dispatch;
P_aded9_3:;
goto L_adede;
}
L_adede:{ // MOV EAX,dword ptr [EBP + 0x1c]
c.pc=0xadede;if(!sl_tick(c))return int(c.fault);
P_adede_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x1cULL)),c);
P_adede_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adede_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adede_3:;
goto L_adee1;
}
L_adee1:{ // TEST EAX,EAX
c.pc=0xadee1;if(!sl_tick(c))return int(c.fault);
P_adee1_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_adee1_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_adee1_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_adee1_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adee1_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_adee1_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_adee1_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adee1_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adee1_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adee1_9:;
goto L_adee3;
}
L_adee3:{ // JNZ 0x000adef2
c.pc=0xadee3;if(!sl_tick(c))return int(c.fault);
P_adee3_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_adee3_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_adef2;}
P_adee3_2:;
goto L_adee5;
}
L_adee5:{ // MOV EDX,0xffffffce
c.pc=0xadee5;if(!sl_tick(c))return int(c.fault);
P_adee5_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,SlU(0xffffffceULL),c);
P_adee5_1:;
goto L_adeea;
}
L_adeea:{ // MOV EAX,EDX
c.pc=0xadeea;if(!sl_tick(c))return int(c.fault);
P_adeea_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_adeea_1:;
goto L_adeec;
}
L_adeec:{ // ADD ESP,0x44
c.pc=0xadeec;if(!sl_tick(c))return int(c.fault);
P_adeec_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x44ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adeec_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x44ULL)))&(SlU(0x44ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x44ULL)))&(SlU(1)<<31))!=0),c);
P_adeec_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x44ULL)),c);
P_adeec_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adeec_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_adeec_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_adeec_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adeec_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adeec_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adeec_9:;
goto L_adeef;
}
L_adeef:{ // POP EBX
c.pc=0xadeef;if(!sl_tick(c))return int(c.fault);
P_adeef_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_adeef_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adeef_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adeef_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_adeef_4:;
goto L_adef0;
}
L_adef0:{ // POP EBP
c.pc=0xadef0;if(!sl_tick(c))return int(c.fault);
P_adef0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_adef0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adef0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adef0_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_adef0_4:;
goto L_adef1;
}
L_adef1:{ // RET
c.pc=0xadef1;if(!sl_tick(c))return int(c.fault);
P_adef1_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_adef1_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_adef1_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_adef1_3:;
goto L_adef2;
}
L_adef2:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0xadef2;if(!sl_tick(c))return int(c.fault);
P_adef2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_adef2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adef2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adef2_3:;
goto L_adef5;
}
L_adef5:{ // CMP byte ptr [EDX + 0xd],0x0
c.pc=0xadef5;if(!sl_tick(c))return int(c.fault);
P_adef5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0xdULL)),c);
P_adef5_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adef5_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_adef5_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_adef5_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_adef5_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_adef5_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_adef5_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_adef5_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_adef5_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adef5_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adef5_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adef5_12:;
goto L_adef9;
}
L_adef9:{ // JZ 0x000adfcb
c.pc=0xadef9;if(!sl_tick(c))return int(c.fault);
P_adef9_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_adfcb;}
P_adef9_1:;
goto L_adeff;
}
L_adeff:{ // PXOR XMM0,XMM0
c.pc=0xadeff;if(!sl_tick(c))return int(c.fault);
P_adeff_0:;
sl_put<16>(c.reg,sizeof(c.reg),0x1200,(sl_get<16>(c.reg,sizeof(c.reg),0x1200,c) ^ sl_get<16>(c.reg,sizeof(c.reg),0x1200,c)),c);
P_adeff_1:;
goto L_adf03;
}
L_adf03:{ // UCOMISS XMM0,dword ptr [EAX + 0x8]
c.pc=0xadf03;if(!sl_tick(c))return int(c.fault);
P_adf03_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_adf03_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x27f80,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_adf03_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adf03_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x28000,__builtin_isnan(sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_adf03_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(bool(sl_get<1>(c.temp,sizeof(c.temp),0x27f80,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0x28000,c))),c);
P_adf03_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adf03_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x28100,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) == sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_adf03_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28100,c)),c);
P_adf03_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adf03_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x28200,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) < sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_adf03_10:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28200,c)),c);
P_adf03_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_adf03_12:;
sl_put<1>(c.reg,sizeof(c.reg),0x204,SlU(0x0ULL),c);
P_adf03_13:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,SlU(0x0ULL),c);
P_adf03_14:;
goto L_adf07;
}
L_adf07:{ // JP 0x000adf0b
c.pc=0xadf07;if(!sl_tick(c))return int(c.fault);
P_adf07_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x202,c)){goto L_adf0b;}
P_adf07_1:;
goto L_adf09;
}
L_adf09:{ // JZ 0x000adf53
c.pc=0xadf09;if(!sl_tick(c))return int(c.fault);
P_adf09_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_adf53;}
P_adf09_1:;
goto L_adf0b;
}
L_adf0b:{ // MOV ECX,dword ptr [EBP + 0x8]
c.pc=0xadf0b;if(!sl_tick(c))return int(c.fault);
P_adf0b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_adf0b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adf0b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adf0b_3:;
goto L_adf0e;
}
L_adf0e:{ // MOV EDX,dword ptr [ECX]
c.pc=0xadf0e;if(!sl_tick(c))return int(c.fault);
P_adf0e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c),c);
P_adf0e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adf0e_2:;
goto L_adf10;
}
L_adf10:{ // MOV dword ptr [ESP + 0x14],EAX
c.pc=0xadf10;if(!sl_tick(c))return int(c.fault);
P_adf10_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x14ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adf10_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adf10_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adf10_3:;
goto L_adf14;
}
L_adf14:{ // MOV EAX,dword ptr [EBP + 0x18]
c.pc=0xadf14;if(!sl_tick(c))return int(c.fault);
P_adf14_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x18ULL)),c);
P_adf14_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adf14_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adf14_3:;
goto L_adf17;
}
L_adf17:{ // MOV dword ptr [ESP + 0x10],EAX
c.pc=0xadf17;if(!sl_tick(c))return int(c.fault);
P_adf17_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x10ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adf17_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adf17_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adf17_3:;
goto L_adf1b;
}
L_adf1b:{ // LEA EAX,[EBP + -0xc]
c.pc=0xadf1b;if(!sl_tick(c))return int(c.fault);
P_adf1b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_adf1b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_adf1b_2:;
goto L_adf1e;
}
L_adf1e:{ // MOV dword ptr [ESP + 0xc],EAX
c.pc=0xadf1e;if(!sl_tick(c))return int(c.fault);
P_adf1e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adf1e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adf1e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adf1e_3:;
goto L_adf22;
}
L_adf22:{ // MOV ECX,dword ptr [EBP + 0x10]
c.pc=0xadf22;if(!sl_tick(c))return int(c.fault);
P_adf22_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_adf22_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adf22_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adf22_3:;
goto L_adf25;
}
L_adf25:{ // MOV dword ptr [ESP + 0x8],ECX
c.pc=0xadf25;if(!sl_tick(c))return int(c.fault);
P_adf25_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adf25_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_adf25_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adf25_3:;
goto L_adf29;
}
L_adf29:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0xadf29;if(!sl_tick(c))return int(c.fault);
P_adf29_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_adf29_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adf29_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adf29_3:;
goto L_adf2c;
}
L_adf2c:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xadf2c;if(!sl_tick(c))return int(c.fault);
P_adf2c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adf2c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adf2c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adf2c_3:;
goto L_adf30;
}
L_adf30:{ // MOV ECX,dword ptr [EBP + 0x8]
c.pc=0xadf30;if(!sl_tick(c))return int(c.fault);
P_adf30_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_adf30_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adf30_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adf30_3:;
goto L_adf33;
}
L_adf33:{ // MOV dword ptr [ESP],ECX
c.pc=0xadf33;if(!sl_tick(c))return int(c.fault);
P_adf33_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_adf33_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adf33_2:;
goto L_adf36;
}
L_adf36:{ // CALL dword ptr [EDX + 0xe4]
c.pc=0xadf36;if(!sl_tick(c))return int(c.fault);
P_adf36_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0xe4ULL)),c);
P_adf36_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_adf36_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adf36_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_adf36_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xadf3cULL),c);
P_adf36_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_adf36_6:;
goto L_adf3c;
}
L_adf3c:{ // MOV EDX,EAX
c.pc=0xadf3c;if(!sl_tick(c))return int(c.fault);
P_adf3c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adf3c_1:;
goto L_adf3e;
}
L_adf3e:{ // TEST EAX,EAX
c.pc=0xadf3e;if(!sl_tick(c))return int(c.fault);
P_adf3e_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_adf3e_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_adf3e_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_adf3e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adf3e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_adf3e_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_adf3e_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adf3e_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adf3e_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adf3e_9:;
goto L_adf40;
}
L_adf40:{ // JNZ 0x000adeea
c.pc=0xadf40;if(!sl_tick(c))return int(c.fault);
P_adf40_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_adf40_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_adeea;}
P_adf40_2:;
goto L_adf42;
}
L_adf42:{ // MOV ECX,dword ptr [EBP + 0x14]
c.pc=0xadf42;if(!sl_tick(c))return int(c.fault);
P_adf42_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_adf42_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adf42_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adf42_3:;
goto L_adf45;
}
L_adf45:{ // TEST ECX,ECX
c.pc=0xadf45;if(!sl_tick(c))return int(c.fault);
P_adf45_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_adf45_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_adf45_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_adf45_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adf45_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_adf45_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_adf45_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adf45_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adf45_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adf45_9:;
goto L_adf47;
}
L_adf47:{ // JZ 0x000adeea
c.pc=0xadf47;if(!sl_tick(c))return int(c.fault);
P_adf47_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_adeea;}
P_adf47_1:;
goto L_adf49;
}
L_adf49:{ // MOV EAX,dword ptr [EBP + -0xc]
c.pc=0xadf49;if(!sl_tick(c))return int(c.fault);
P_adf49_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_adf49_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adf49_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adf49_3:;
goto L_adf4c;
}
L_adf4c:{ // MOV ECX,dword ptr [EBP + 0x14]
c.pc=0xadf4c;if(!sl_tick(c))return int(c.fault);
P_adf4c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_adf4c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adf4c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adf4c_3:;
goto L_adf4f;
}
L_adf4f:{ // MOV dword ptr [ECX],EAX
c.pc=0xadf4f;if(!sl_tick(c))return int(c.fault);
P_adf4f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adf4f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adf4f_2:;
goto L_adf51;
}
L_adf51:{ // JMP 0x000adeea
c.pc=0xadf51;if(!sl_tick(c))return int(c.fault);
P_adf51_0:;
goto L_adeea;
P_adf51_1:;
goto L_adf53;
}
L_adf53:{ // MOVSS XMM0,dword ptr [EAX + 0x4]
c.pc=0xadf53;if(!sl_tick(c))return int(c.fault);
P_adf53_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_adf53_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adf53_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adf53_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,SlU(0x0ULL),c);
P_adf53_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_adf53_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,SlU(0x0ULL),c);
P_adf53_6:;
goto L_adf58;
}
L_adf58:{ // XORPS XMM1,XMM1
c.pc=0xadf58;if(!sl_tick(c))return int(c.fault);
P_adf58_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)),c);
P_adf58_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,(sl_get<4>(c.reg,sizeof(c.reg),0x1244,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x1244,c)),c);
P_adf58_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,(sl_get<4>(c.reg,sizeof(c.reg),0x1248,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x1248,c)),c);
P_adf58_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,(sl_get<4>(c.reg,sizeof(c.reg),0x124c,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x124c,c)),c);
P_adf58_4:;
goto L_adf5b;
}
L_adf5b:{ // MAXSS XMM0,XMM1
c.pc=0xadf5b;if(!sl_tick(c))return int(c.fault);
P_adf5b_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x71c80,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) < sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_adf5b_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x71c80,c)){goto L_adf5f;}
P_adf5b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_adf5b_3:;
goto L_adf5f;
}
L_adf5f:{ // MOVSS XMM1,dword ptr [EBX + 0x34082]
c.pc=0xadf5f;if(!sl_tick(c))return int(c.fault);
P_adf5f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x34082ULL)),c);
P_adf5f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_adf5f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adf5f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_adf5f_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_adf5f_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_adf5f_6:;
goto L_adf67;
}
L_adf67:{ // MOVAPS XMM2,XMM1
c.pc=0xadf67;if(!sl_tick(c))return int(c.fault);
P_adf67_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1280,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_adf67_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1284,sl_get<4>(c.reg,sizeof(c.reg),0x1244,c),c);
P_adf67_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1288,sl_get<4>(c.reg,sizeof(c.reg),0x1248,c),c);
P_adf67_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x128c,sl_get<4>(c.reg,sizeof(c.reg),0x124c,c),c);
P_adf67_4:;
goto L_adf6a;
}
L_adf6a:{ // CMPLESS XMM2,XMM0
c.pc=0xadf6a;if(!sl_tick(c))return int(c.fault);
P_adf6a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1180,sl_get<4>(c.reg,sizeof(c.reg),0x1280,c),c);
P_adf6a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1190,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_adf6a_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x6a400,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1180,c)) <= sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1190,c))),c);
P_adf6a_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x6a480,sl_get<1>(c.temp,sizeof(c.temp),0x6a400,c),c);
P_adf6a_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1180,(sl_get<4>(c.temp,sizeof(c.temp),0x6a480,c) * SlU(0xffffffffULL)),c);
P_adf6a_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x1280,sl_get<4>(c.reg,sizeof(c.reg),0x1180,c),c);
P_adf6a_6:;
goto L_adf6f;
}
L_adf6f:{ // MOVSS XMM3,dword ptr [EBX + 0x34092]
c.pc=0xadf6f;if(!sl_tick(c))return int(c.fault);
P_adf6f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x34092ULL)),c);
P_adf6f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_adf6f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c0,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adf6f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c4,SlU(0x0ULL),c);
P_adf6f_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c8,SlU(0x0ULL),c);
P_adf6f_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x12cc,SlU(0x0ULL),c);
P_adf6f_6:;
goto L_adf77;
}
L_adf77:{ // CMPLESS XMM3,XMM0
c.pc=0xadf77;if(!sl_tick(c))return int(c.fault);
P_adf77_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1180,sl_get<4>(c.reg,sizeof(c.reg),0x12c0,c),c);
P_adf77_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1190,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_adf77_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x6a400,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1180,c)) <= sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1190,c))),c);
P_adf77_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x6a480,sl_get<1>(c.temp,sizeof(c.temp),0x6a400,c),c);
P_adf77_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1180,(sl_get<4>(c.temp,sizeof(c.temp),0x6a480,c) * SlU(0xffffffffULL)),c);
P_adf77_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c0,sl_get<4>(c.reg,sizeof(c.reg),0x1180,c),c);
P_adf77_6:;
goto L_adf7c;
}
L_adf7c:{ // ANDPS XMM1,XMM2
c.pc=0xadf7c;if(!sl_tick(c))return int(c.fault);
P_adf7c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c) & sl_get<4>(c.reg,sizeof(c.reg),0x1280,c)),c);
P_adf7c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,(sl_get<4>(c.reg,sizeof(c.reg),0x1244,c) & sl_get<4>(c.reg,sizeof(c.reg),0x1284,c)),c);
P_adf7c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,(sl_get<4>(c.reg,sizeof(c.reg),0x1248,c) & sl_get<4>(c.reg,sizeof(c.reg),0x1288,c)),c);
P_adf7c_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,(sl_get<4>(c.reg,sizeof(c.reg),0x124c,c) & sl_get<4>(c.reg,sizeof(c.reg),0x128c,c)),c);
P_adf7c_4:;
goto L_adf7f;
}
L_adf7f:{ // PSLLD XMM2,0x1f
c.pc=0xadf7f;if(!sl_tick(c))return int(c.fault);
P_adf7f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1280,sl_lshift(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c),SlU(0x1fULL)),c);
P_adf7f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1284,sl_lshift(sl_get<4>(c.reg,sizeof(c.reg),0x1284,c),SlU(0x1fULL)),c);
P_adf7f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1288,sl_lshift(sl_get<4>(c.reg,sizeof(c.reg),0x1288,c),SlU(0x1fULL)),c);
P_adf7f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x128c,sl_lshift(sl_get<4>(c.reg,sizeof(c.reg),0x128c,c),SlU(0x1fULL)),c);
P_adf7f_4:;
goto L_adf84;
}
L_adf84:{ // SUBPS XMM0,XMM1
c.pc=0xadf84;if(!sl_tick(c))return int(c.fault);
P_adf84_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) - sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_adf84_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1204,c)) - sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1244,c))),c);
P_adf84_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1208,c)) - sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1248,c))),c);
P_adf84_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x120c,c)) - sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x124c,c))),c);
P_adf84_4:;
goto L_adf87;
}
L_adf87:{ // CVTTPS2DQ XMM0,XMM0
c.pc=0xadf87;if(!sl_tick(c))return int(c.fault);
P_adf87_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_trunc_fp(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),4,32),c);
P_adf87_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_trunc_fp(sl_get<4>(c.reg,sizeof(c.reg),0x1204,c),4,32),c);
P_adf87_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_trunc_fp(sl_get<4>(c.reg,sizeof(c.reg),0x1208,c),4,32),c);
P_adf87_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_trunc_fp(sl_get<4>(c.reg,sizeof(c.reg),0x120c,c),4,32),c);
P_adf87_4:;
goto L_adf8b;
}
L_adf8b:{ // PADDD XMM0,XMM2
c.pc=0xadf8b;if(!sl_tick(c))return int(c.fault);
P_adf8b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c) + sl_get<4>(c.reg,sizeof(c.reg),0x1280,c)),c);
P_adf8b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,(sl_get<4>(c.reg,sizeof(c.reg),0x1204,c) + sl_get<4>(c.reg,sizeof(c.reg),0x1284,c)),c);
P_adf8b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,(sl_get<4>(c.reg,sizeof(c.reg),0x1208,c) + sl_get<4>(c.reg,sizeof(c.reg),0x1288,c)),c);
P_adf8b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,(sl_get<4>(c.reg,sizeof(c.reg),0x120c,c) + sl_get<4>(c.reg,sizeof(c.reg),0x128c,c)),c);
P_adf8b_4:;
goto L_adf8f;
}
L_adf8f:{ // POR XMM0,XMM3
c.pc=0xadf8f;if(!sl_tick(c))return int(c.fault);
P_adf8f_0:;
sl_put<16>(c.reg,sizeof(c.reg),0x1200,(sl_get<16>(c.reg,sizeof(c.reg),0x1200,c) | sl_get<16>(c.reg,sizeof(c.reg),0x12c0,c)),c);
P_adf8f_1:;
goto L_adf93;
}
L_adf93:{ // MOVDQA xmmword ptr [EBP + -0x28],XMM0
c.pc=0xadf93;if(!sl_tick(c))return int(c.fault);
P_adf93_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd8ULL)),c);
P_adf93_1:;
sl_put<16>(c.temp,sizeof(c.temp),0x5300,sl_get<16>(c.reg,sizeof(c.reg),0x1200,c),c);
P_adf93_2:;
sl_put<16>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<16>(c.temp,sizeof(c.temp),0x5300,c),c);
P_adf93_3:;
goto L_adf98;
}
L_adf98:{ // MOV EAX,dword ptr [EBP + -0x28]
c.pc=0xadf98;if(!sl_tick(c))return int(c.fault);
P_adf98_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd8ULL)),c);
P_adf98_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adf98_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adf98_3:;
goto L_adf9b;
}
L_adf9b:{ // MOV dword ptr [EBP + -0xc],EAX
c.pc=0xadf9b;if(!sl_tick(c))return int(c.fault);
P_adf9b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_adf9b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adf9b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adf9b_3:;
goto L_adf9e;
}
L_adf9e:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0xadf9e;if(!sl_tick(c))return int(c.fault);
P_adf9e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_adf9e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adf9e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adf9e_3:;
goto L_adfa1;
}
L_adfa1:{ // MOV EAX,dword ptr [EDX]
c.pc=0xadfa1;if(!sl_tick(c))return int(c.fault);
P_adfa1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_adfa1_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adfa1_2:;
goto L_adfa3;
}
L_adfa3:{ // MOV ECX,dword ptr [EBP + 0x18]
c.pc=0xadfa3;if(!sl_tick(c))return int(c.fault);
P_adfa3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x18ULL)),c);
P_adfa3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adfa3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adfa3_3:;
goto L_adfa6;
}
L_adfa6:{ // MOV dword ptr [ESP + 0xc],ECX
c.pc=0xadfa6;if(!sl_tick(c))return int(c.fault);
P_adfa6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adfa6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_adfa6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adfa6_3:;
goto L_adfaa;
}
L_adfaa:{ // MOV EDX,dword ptr [EBP + -0x28]
c.pc=0xadfaa;if(!sl_tick(c))return int(c.fault);
P_adfaa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd8ULL)),c);
P_adfaa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adfaa_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adfaa_3:;
goto L_adfad;
}
L_adfad:{ // MOV dword ptr [ESP + 0x8],EDX
c.pc=0xadfad;if(!sl_tick(c))return int(c.fault);
P_adfad_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adfad_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_adfad_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adfad_3:;
goto L_adfb1;
}
L_adfb1:{ // MOV ECX,dword ptr [EBP + 0x10]
c.pc=0xadfb1;if(!sl_tick(c))return int(c.fault);
P_adfb1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_adfb1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adfb1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adfb1_3:;
goto L_adfb4;
}
L_adfb4:{ // MOV dword ptr [ESP + 0x4],ECX
c.pc=0xadfb4;if(!sl_tick(c))return int(c.fault);
P_adfb4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_adfb4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_adfb4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adfb4_3:;
goto L_adfb8;
}
L_adfb8:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0xadfb8;if(!sl_tick(c))return int(c.fault);
P_adfb8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_adfb8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adfb8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adfb8_3:;
goto L_adfbb;
}
L_adfbb:{ // MOV dword ptr [ESP],EDX
c.pc=0xadfbb;if(!sl_tick(c))return int(c.fault);
P_adfbb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_adfbb_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adfbb_2:;
goto L_adfbe;
}
L_adfbe:{ // CALL dword ptr [EAX + 0xe8]
c.pc=0xadfbe;if(!sl_tick(c))return int(c.fault);
P_adfbe_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xe8ULL)),c);
P_adfbe_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_adfbe_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adfbe_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_adfbe_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xadfc4ULL),c);
P_adfbe_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_adfbe_6:;
goto L_adfc4;
}
L_adfc4:{ // MOV EDX,EAX
c.pc=0xadfc4;if(!sl_tick(c))return int(c.fault);
P_adfc4_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adfc4_1:;
goto L_adfc6;
}
L_adfc6:{ // JMP 0x000adeea
c.pc=0xadfc6;if(!sl_tick(c))return int(c.fault);
P_adfc6_0:;
goto L_adeea;
P_adfc6_1:;
goto L_adfcb;
}
L_adfcb:{ // MOV EDX,0xffffd58d
c.pc=0xadfcb;if(!sl_tick(c))return int(c.fault);
P_adfcb_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,SlU(0xffffd58dULL),c);
P_adfcb_1:;
goto L_adfd0;
}
L_adfd0:{ // JMP 0x000adeea
c.pc=0xadfd0;if(!sl_tick(c))return int(c.fault);
P_adfd0_0:;
goto L_adeea;
P_adfd0_1:;
c.pc=0xadfd5;goto dispatch;
}
L_adfd6:{ // PUSH EBP
c.pc=0xadfd6;if(!sl_tick(c))return int(c.fault);
P_adfd6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_adfd6_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_adfd6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_adfd6_3:;
goto L_adfd7;
}
L_adfd7:{ // MOV EBP,ESP
c.pc=0xadfd7;if(!sl_tick(c))return int(c.fault);
P_adfd7_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_adfd7_1:;
goto L_adfd9;
}
L_adfd9:{ // PUSH ESI
c.pc=0xadfd9;if(!sl_tick(c))return int(c.fault);
P_adfd9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_adfd9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_adfd9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_adfd9_3:;
goto L_adfda;
}
L_adfda:{ // PUSH EBX
c.pc=0xadfda;if(!sl_tick(c))return int(c.fault);
P_adfda_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_adfda_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_adfda_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_adfda_3:;
goto L_adfdb;
}
L_adfdb:{ // SUB ESP,0x20
c.pc=0xadfdb;if(!sl_tick(c))return int(c.fault);
P_adfdb_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x20ULL)),c);
P_adfdb_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x20ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_adfdb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x20ULL)),c);
P_adfdb_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adfdb_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_adfdb_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_adfdb_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adfdb_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adfdb_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adfdb_9:;
goto L_adfde;
}
L_adfde:{ // CALL 0x000c086c
c.pc=0xadfde;if(!sl_tick(c))return int(c.fault);
P_adfde_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_adfde_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xadfe3ULL),c);
P_adfde_2:;
c.pc=0xc086c;goto dispatch;
P_adfde_3:;
goto L_adfe3;
}
L_adfe3:{ // MOV ECX,dword ptr [EBP + 0x8]
c.pc=0xadfe3;if(!sl_tick(c))return int(c.fault);
P_adfe3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_adfe3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adfe3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adfe3_3:;
goto L_adfe6;
}
L_adfe6:{ // MOV ESI,dword ptr [EBP + 0xc]
c.pc=0xadfe6;if(!sl_tick(c))return int(c.fault);
P_adfe6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_adfe6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adfe6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_adfe6_3:;
goto L_adfe9;
}
L_adfe9:{ // TEST ESI,ESI
c.pc=0xadfe9;if(!sl_tick(c))return int(c.fault);
P_adfe9_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_adfe9_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_adfe9_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_adfe9_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adfe9_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_adfe9_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_adfe9_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adfe9_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adfe9_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adfe9_9:;
goto L_adfeb;
}
L_adfeb:{ // JZ 0x000ae0ce
c.pc=0xadfeb;if(!sl_tick(c))return int(c.fault);
P_adfeb_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_ae0ce;}
P_adfeb_1:;
goto L_adff1;
}
L_adff1:{ // MOVSX EAX,word ptr [ECX + 0x2]
c.pc=0xadff1;if(!sl_tick(c))return int(c.fault);
P_adff1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x2ULL)),c);
P_adff1_1:;
sl_put<2>(c.temp,sizeof(c.temp),0x9600,sl_get<2>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_adff1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,SlU(sl_signed(sl_get<2>(c.temp,sizeof(c.temp),0x9600,c),16)),c);
P_adff1_3:;
goto L_adff5;
}
L_adff5:{ // SUB EAX,0x101
c.pc=0xadff5;if(!sl_tick(c))return int(c.fault);
P_adff5_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < SlU(0x101ULL)),c);
P_adff5_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^SlU(0x101ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-SlU(0x101ULL)))&(SlU(1)<<31))!=0),c);
P_adff5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - SlU(0x101ULL)),c);
P_adff5_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adff5_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_adff5_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_adff5_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adff5_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adff5_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adff5_9:;
goto L_adffa;
}
L_adffa:{ // CMP EAX,0x5
c.pc=0xadffa;if(!sl_tick(c))return int(c.fault);
P_adffa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_adffa_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x5ULL)),c);
P_adffa_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x5ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x5ULL)))&(SlU(1)<<31))!=0),c);
P_adffa_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x5ULL)),c);
P_adffa_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_adffa_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_adffa_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_adffa_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_adffa_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_adffa_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_adffa_10:;
goto L_adffd;
}
L_adffd:{ // JBE 0x000ae010
c.pc=0xadffd;if(!sl_tick(c))return int(c.fault);
P_adffd_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9d00,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x200,c)) || bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c))),c);
P_adffd_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9d00,c)){goto L_ae010;}
P_adffd_2:;
goto L_adfff;
}
L_adfff:{ // MOV dword ptr [EBP + 0xc],ESI
c.pc=0xadfff;if(!sl_tick(c))return int(c.fault);
P_adfff_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_adfff_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_adfff_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_adfff_3:;
goto L_ae002;
}
L_ae002:{ // MOV dword ptr [EBP + 0x8],ECX
c.pc=0xae002;if(!sl_tick(c))return int(c.fault);
P_ae002_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_ae002_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_ae002_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae002_3:;
goto L_ae005;
}
L_ae005:{ // ADD ESP,0x20
c.pc=0xae005;if(!sl_tick(c))return int(c.fault);
P_ae005_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae005_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(0x20ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_ae005_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x20ULL)),c);
P_ae005_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae005_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae005_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae005_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae005_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae005_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae005_9:;
goto L_ae008;
}
L_ae008:{ // POP EBX
c.pc=0xae008;if(!sl_tick(c))return int(c.fault);
P_ae008_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae008_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae008_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae008_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae008_4:;
goto L_ae009;
}
L_ae009:{ // POP ESI
c.pc=0xae009;if(!sl_tick(c))return int(c.fault);
P_ae009_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae009_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae009_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae009_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae009_4:;
goto L_ae00a;
}
L_ae00a:{ // POP EBP
c.pc=0xae00a;if(!sl_tick(c))return int(c.fault);
P_ae00a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae00a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae00a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae00a_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae00a_4:;
goto L_ae00b;
}
L_ae00b:{ // JMP 0x000aabb6
c.pc=0xae00b;if(!sl_tick(c))return int(c.fault);
P_ae00b_0:;
c.pc=0xaabb6;goto dispatch;
P_ae00b_1:;
goto L_ae010;
}
L_ae010:{ // MOV EAX,dword ptr [EBX + EAX*0x4 + 0x39]
c.pc=0xae010;if(!sl_tick(c))return int(c.fault);
P_ae010_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x39ULL) + sl_get<4>(c.reg,sizeof(c.reg),0xc,c)),c);
P_ae010_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x4ULL)),c);
P_ae010_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_ae010_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c)),c),c);
P_ae010_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae010_5:;
goto L_ae017;
}
L_ae017:{ // ADD EAX,EBX
c.pc=0xae017;if(!sl_tick(c))return int(c.fault);
P_ae017_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+sl_get<4>(c.reg,sizeof(c.reg),0xc,c))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_ae017_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+sl_get<4>(c.reg,sizeof(c.reg),0xc,c)))&(sl_get<4>(c.reg,sizeof(c.reg),0xc,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+sl_get<4>(c.reg,sizeof(c.reg),0xc,c)))&(SlU(1)<<31))!=0),c);
P_ae017_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.reg,sizeof(c.reg),0xc,c)),c);
P_ae017_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae017_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_ae017_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_ae017_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae017_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae017_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae017_9:;
goto L_ae019;
}
L_ae019:{ // JMP EAX
c.pc=0xae019;if(!sl_tick(c))return int(c.fault);
P_ae019_0:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c));goto dispatch;
P_ae019_1:;
c.pc=0xae01b;goto dispatch;
}
L_ae034:{ // LEA EAX,[ESI + 0xe4]
c.pc=0xae034;if(!sl_tick(c))return int(c.fault);
P_ae034_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0xe4ULL)),c);
P_ae034_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_ae034_2:;
goto L_ae03a;
}
L_ae03a:{ // MOV dword ptr [EBP + 0xc],EAX
c.pc=0xae03a;if(!sl_tick(c))return int(c.fault);
P_ae03a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_ae03a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae03a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae03a_3:;
goto L_ae03d;
}
L_ae03d:{ // MOV dword ptr [EBP + 0x8],ECX
c.pc=0xae03d;if(!sl_tick(c))return int(c.fault);
P_ae03d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_ae03d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_ae03d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae03d_3:;
goto L_ae040;
}
L_ae040:{ // ADD ESP,0x20
c.pc=0xae040;if(!sl_tick(c))return int(c.fault);
P_ae040_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae040_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(0x20ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_ae040_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x20ULL)),c);
P_ae040_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae040_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae040_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae040_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae040_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae040_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae040_9:;
goto L_ae043;
}
L_ae043:{ // POP EBX
c.pc=0xae043;if(!sl_tick(c))return int(c.fault);
P_ae043_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae043_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae043_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae043_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae043_4:;
goto L_ae044;
}
L_ae044:{ // POP ESI
c.pc=0xae044;if(!sl_tick(c))return int(c.fault);
P_ae044_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae044_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae044_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae044_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae044_4:;
goto L_ae045;
}
L_ae045:{ // POP EBP
c.pc=0xae045;if(!sl_tick(c))return int(c.fault);
P_ae045_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae045_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae045_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae045_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae045_4:;
goto L_ae046;
}
L_ae046:{ // JMP 0x000adaf4
c.pc=0xae046;if(!sl_tick(c))return int(c.fault);
P_ae046_0:;
c.pc=0xadaf4;goto dispatch;
P_ae046_1:;
goto L_ae04b;
}
L_ae04b:{ // MOV EAX,dword ptr [ESI]
c.pc=0xae04b;if(!sl_tick(c))return int(c.fault);
P_ae04b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_ae04b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae04b_2:;
goto L_ae04d;
}
L_ae04d:{ // MOV EDX,dword ptr [ECX + 0x4]
c.pc=0xae04d;if(!sl_tick(c))return int(c.fault);
P_ae04d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x4ULL)),c);
P_ae04d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae04d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae04d_3:;
goto L_ae050;
}
L_ae050:{ // MOV dword ptr [EBP + 0xc],EDX
c.pc=0xae050;if(!sl_tick(c))return int(c.fault);
P_ae050_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_ae050_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_ae050_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae050_3:;
goto L_ae053;
}
L_ae053:{ // MOV dword ptr [EBP + 0x8],ESI
c.pc=0xae053;if(!sl_tick(c))return int(c.fault);
P_ae053_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_ae053_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae053_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae053_3:;
goto L_ae056;
}
L_ae056:{ // MOV ECX,dword ptr [EAX + 0xdc]
c.pc=0xae056;if(!sl_tick(c))return int(c.fault);
P_ae056_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xdcULL)),c);
P_ae056_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_ae056_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae056_3:;
goto L_ae05c;
}
L_ae05c:{ // ADD ESP,0x20
c.pc=0xae05c;if(!sl_tick(c))return int(c.fault);
P_ae05c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae05c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(0x20ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_ae05c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x20ULL)),c);
P_ae05c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae05c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae05c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae05c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae05c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae05c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae05c_9:;
goto L_ae05f;
}
L_ae05f:{ // POP EBX
c.pc=0xae05f;if(!sl_tick(c))return int(c.fault);
P_ae05f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae05f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae05f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae05f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae05f_4:;
goto L_ae060;
}
L_ae060:{ // POP ESI
c.pc=0xae060;if(!sl_tick(c))return int(c.fault);
P_ae060_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae060_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae060_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae060_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae060_4:;
goto L_ae061;
}
L_ae061:{ // POP EBP
c.pc=0xae061;if(!sl_tick(c))return int(c.fault);
P_ae061_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae061_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae061_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae061_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae061_4:;
goto L_ae062;
}
L_ae062:{ // JMP ECX
c.pc=0xae062;if(!sl_tick(c))return int(c.fault);
P_ae062_0:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c));goto dispatch;
P_ae062_1:;
goto L_ae064;
}
L_ae064:{ // MOV EAX,dword ptr [ESI]
c.pc=0xae064;if(!sl_tick(c))return int(c.fault);
P_ae064_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_ae064_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae064_2:;
goto L_ae066;
}
L_ae066:{ // MOV EDX,dword ptr [ECX + 0x4]
c.pc=0xae066;if(!sl_tick(c))return int(c.fault);
P_ae066_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x4ULL)),c);
P_ae066_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae066_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae066_3:;
goto L_ae069;
}
L_ae069:{ // MOV dword ptr [EBP + 0xc],EDX
c.pc=0xae069;if(!sl_tick(c))return int(c.fault);
P_ae069_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_ae069_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_ae069_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae069_3:;
goto L_ae06c;
}
L_ae06c:{ // MOV dword ptr [EBP + 0x8],ESI
c.pc=0xae06c;if(!sl_tick(c))return int(c.fault);
P_ae06c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_ae06c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae06c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae06c_3:;
goto L_ae06f;
}
L_ae06f:{ // MOV ECX,dword ptr [EAX + 0xe0]
c.pc=0xae06f;if(!sl_tick(c))return int(c.fault);
P_ae06f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xe0ULL)),c);
P_ae06f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_ae06f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae06f_3:;
goto L_ae075;
}
L_ae075:{ // JMP 0x000ae05c
c.pc=0xae075;if(!sl_tick(c))return int(c.fault);
P_ae075_0:;
goto L_ae05c;
P_ae075_1:;
goto L_ae077;
}
L_ae077:{ // MOV EDX,dword ptr [ESI]
c.pc=0xae077;if(!sl_tick(c))return int(c.fault);
P_ae077_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_ae077_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae077_2:;
goto L_ae079;
}
L_ae079:{ // MOV EAX,dword ptr [ECX + 0x4]
c.pc=0xae079;if(!sl_tick(c))return int(c.fault);
P_ae079_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x4ULL)),c);
P_ae079_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae079_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae079_3:;
goto L_ae07c;
}
L_ae07c:{ // MOV dword ptr [ESP + 0x14],EAX
c.pc=0xae07c;if(!sl_tick(c))return int(c.fault);
P_ae07c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x14ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae07c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae07c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae07c_3:;
goto L_ae080;
}
L_ae080:{ // MOV EAX,dword ptr [ECX + 0x8]
c.pc=0xae080;if(!sl_tick(c))return int(c.fault);
P_ae080_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x8ULL)),c);
P_ae080_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae080_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae080_3:;
goto L_ae083;
}
L_ae083:{ // MOV dword ptr [ESP + 0x10],EAX
c.pc=0xae083;if(!sl_tick(c))return int(c.fault);
P_ae083_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x10ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae083_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae083_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae083_3:;
goto L_ae087;
}
L_ae087:{ // MOV EAX,dword ptr [ECX + 0xc]
c.pc=0xae087;if(!sl_tick(c))return int(c.fault);
P_ae087_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0xcULL)),c);
P_ae087_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae087_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae087_3:;
goto L_ae08a;
}
L_ae08a:{ // MOV dword ptr [ESP + 0xc],EAX
c.pc=0xae08a;if(!sl_tick(c))return int(c.fault);
P_ae08a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae08a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae08a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae08a_3:;
goto L_ae08e;
}
L_ae08e:{ // MOV EAX,dword ptr [ECX + 0x10]
c.pc=0xae08e;if(!sl_tick(c))return int(c.fault);
P_ae08e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x10ULL)),c);
P_ae08e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae08e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae08e_3:;
goto L_ae091;
}
L_ae091:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0xae091;if(!sl_tick(c))return int(c.fault);
P_ae091_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae091_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae091_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae091_3:;
goto L_ae095;
}
L_ae095:{ // MOV EAX,dword ptr [ECX + 0x14]
c.pc=0xae095;if(!sl_tick(c))return int(c.fault);
P_ae095_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x14ULL)),c);
P_ae095_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae095_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae095_3:;
goto L_ae098;
}
L_ae098:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xae098;if(!sl_tick(c))return int(c.fault);
P_ae098_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae098_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae098_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae098_3:;
goto L_ae09c;
}
L_ae09c:{ // MOV dword ptr [ESP],ESI
c.pc=0xae09c;if(!sl_tick(c))return int(c.fault);
P_ae09c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae09c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae09c_2:;
goto L_ae09f;
}
L_ae09f:{ // CALL dword ptr [EDX + 0xf8]
c.pc=0xae09f;if(!sl_tick(c))return int(c.fault);
P_ae09f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0xf8ULL)),c);
P_ae09f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_ae09f_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae09f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae09f_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xae0a5ULL),c);
P_ae09f_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_ae09f_6:;
goto L_ae0a5;
}
L_ae0a5:{ // ADD ESP,0x20
c.pc=0xae0a5;if(!sl_tick(c))return int(c.fault);
P_ae0a5_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae0a5_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(0x20ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_ae0a5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x20ULL)),c);
P_ae0a5_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae0a5_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae0a5_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae0a5_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae0a5_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae0a5_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae0a5_9:;
goto L_ae0a8;
}
L_ae0a8:{ // POP EBX
c.pc=0xae0a8;if(!sl_tick(c))return int(c.fault);
P_ae0a8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae0a8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae0a8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae0a8_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae0a8_4:;
goto L_ae0a9;
}
L_ae0a9:{ // POP ESI
c.pc=0xae0a9;if(!sl_tick(c))return int(c.fault);
P_ae0a9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae0a9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae0a9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae0a9_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae0a9_4:;
goto L_ae0aa;
}
L_ae0aa:{ // POP EBP
c.pc=0xae0aa;if(!sl_tick(c))return int(c.fault);
P_ae0aa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae0aa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae0aa_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae0aa_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae0aa_4:;
goto L_ae0ab;
}
L_ae0ab:{ // RET
c.pc=0xae0ab;if(!sl_tick(c))return int(c.fault);
P_ae0ab_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae0ab_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae0ab_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_ae0ab_3:;
goto L_ae0ac;
}
L_ae0ac:{ // MOV EDX,dword ptr [ESI]
c.pc=0xae0ac;if(!sl_tick(c))return int(c.fault);
P_ae0ac_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_ae0ac_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae0ac_2:;
goto L_ae0ae;
}
L_ae0ae:{ // MOV EAX,dword ptr [ECX + 0x4]
c.pc=0xae0ae;if(!sl_tick(c))return int(c.fault);
P_ae0ae_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x4ULL)),c);
P_ae0ae_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae0ae_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae0ae_3:;
goto L_ae0b1;
}
L_ae0b1:{ // MOV dword ptr [ESP + 0xc],EAX
c.pc=0xae0b1;if(!sl_tick(c))return int(c.fault);
P_ae0b1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae0b1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae0b1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae0b1_3:;
goto L_ae0b5;
}
L_ae0b5:{ // MOV EAX,dword ptr [ECX + 0x8]
c.pc=0xae0b5;if(!sl_tick(c))return int(c.fault);
P_ae0b5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x8ULL)),c);
P_ae0b5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae0b5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae0b5_3:;
goto L_ae0b8;
}
L_ae0b8:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0xae0b8;if(!sl_tick(c))return int(c.fault);
P_ae0b8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae0b8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae0b8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae0b8_3:;
goto L_ae0bc;
}
L_ae0bc:{ // MOV EAX,dword ptr [ECX + 0xc]
c.pc=0xae0bc;if(!sl_tick(c))return int(c.fault);
P_ae0bc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0xcULL)),c);
P_ae0bc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae0bc_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae0bc_3:;
goto L_ae0bf;
}
L_ae0bf:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xae0bf;if(!sl_tick(c))return int(c.fault);
P_ae0bf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae0bf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae0bf_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae0bf_3:;
goto L_ae0c3;
}
L_ae0c3:{ // MOV dword ptr [ESP],ESI
c.pc=0xae0c3;if(!sl_tick(c))return int(c.fault);
P_ae0c3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae0c3_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae0c3_2:;
goto L_ae0c6;
}
L_ae0c6:{ // CALL dword ptr [EDX + 0xe8]
c.pc=0xae0c6;if(!sl_tick(c))return int(c.fault);
P_ae0c6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0xe8ULL)),c);
P_ae0c6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_ae0c6_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae0c6_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae0c6_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xae0ccULL),c);
P_ae0c6_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_ae0c6_6:;
goto L_ae0cc;
}
L_ae0cc:{ // JMP 0x000ae0a5
c.pc=0xae0cc;if(!sl_tick(c))return int(c.fault);
P_ae0cc_0:;
goto L_ae0a5;
P_ae0cc_1:;
goto L_ae0ce;
}
L_ae0ce:{ // MOV EAX,0xffffffce
c.pc=0xae0ce;if(!sl_tick(c))return int(c.fault);
P_ae0ce_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,SlU(0xffffffceULL),c);
P_ae0ce_1:;
goto L_ae0d3;
}
L_ae0d3:{ // ADD ESP,0x20
c.pc=0xae0d3;if(!sl_tick(c))return int(c.fault);
P_ae0d3_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae0d3_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(0x20ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_ae0d3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x20ULL)),c);
P_ae0d3_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae0d3_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae0d3_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae0d3_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae0d3_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae0d3_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae0d3_9:;
goto L_ae0d6;
}
L_ae0d6:{ // POP EBX
c.pc=0xae0d6;if(!sl_tick(c))return int(c.fault);
P_ae0d6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae0d6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae0d6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae0d6_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae0d6_4:;
goto L_ae0d7;
}
L_ae0d7:{ // POP ESI
c.pc=0xae0d7;if(!sl_tick(c))return int(c.fault);
P_ae0d7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae0d7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae0d7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae0d7_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae0d7_4:;
goto L_ae0d8;
}
L_ae0d8:{ // POP EBP
c.pc=0xae0d8;if(!sl_tick(c))return int(c.fault);
P_ae0d8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae0d8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae0d8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae0d8_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae0d8_4:;
goto L_ae0d9;
}
L_ae0d9:{ // RET
c.pc=0xae0d9;if(!sl_tick(c))return int(c.fault);
P_ae0d9_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae0d9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae0d9_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_ae0d9_3:;
goto L_ae0da;
}
L_ae0da:{ // PUSH EBP
c.pc=0xae0da;if(!sl_tick(c))return int(c.fault);
P_ae0da_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_ae0da_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae0da_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ae0da_3:;
goto L_ae0db;
}
L_ae0db:{ // MOV EBP,ESP
c.pc=0xae0db;if(!sl_tick(c))return int(c.fault);
P_ae0db_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_ae0db_1:;
goto L_ae0dd;
}
L_ae0dd:{ // PUSH ESI
c.pc=0xae0dd;if(!sl_tick(c))return int(c.fault);
P_ae0dd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae0dd_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae0dd_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ae0dd_3:;
goto L_ae0de;
}
L_ae0de:{ // SUB ESP,0x24
c.pc=0xae0de;if(!sl_tick(c))return int(c.fault);
P_ae0de_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x24ULL)),c);
P_ae0de_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x24ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x24ULL)))&(SlU(1)<<31))!=0),c);
P_ae0de_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x24ULL)),c);
P_ae0de_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae0de_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae0de_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae0de_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae0de_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae0de_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae0de_9:;
goto L_ae0e1;
}
L_ae0e1:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0xae0e1;if(!sl_tick(c))return int(c.fault);
P_ae0e1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_ae0e1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae0e1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae0e1_3:;
goto L_ae0e4;
}
L_ae0e4:{ // MOV ESI,dword ptr [EBP + 0xc]
c.pc=0xae0e4;if(!sl_tick(c))return int(c.fault);
P_ae0e4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_ae0e4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae0e4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae0e4_3:;
goto L_ae0e7;
}
L_ae0e7:{ // TEST EAX,EAX
c.pc=0xae0e7;if(!sl_tick(c))return int(c.fault);
P_ae0e7_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_ae0e7_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_ae0e7_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_ae0e7_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae0e7_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_ae0e7_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_ae0e7_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae0e7_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae0e7_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae0e7_9:;
goto L_ae0e9;
}
L_ae0e9:{ // JZ 0x000ae131
c.pc=0xae0e9;if(!sl_tick(c))return int(c.fault);
P_ae0e9_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_ae131;}
P_ae0e9_1:;
goto L_ae0eb;
}
L_ae0eb:{ // LEA EDX,[EAX + 0xe4]
c.pc=0xae0eb;if(!sl_tick(c))return int(c.fault);
P_ae0eb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xe4ULL)),c);
P_ae0eb_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_ae0eb_2:;
goto L_ae0f1;
}
L_ae0f1:{ // MOV ECX,dword ptr [EAX + 0xe4]
c.pc=0xae0f1;if(!sl_tick(c))return int(c.fault);
P_ae0f1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xe4ULL)),c);
P_ae0f1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_ae0f1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae0f1_3:;
goto L_ae0f7;
}
L_ae0f7:{ // MOV EAX,dword ptr [EBP + 0x18]
c.pc=0xae0f7;if(!sl_tick(c))return int(c.fault);
P_ae0f7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x18ULL)),c);
P_ae0f7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae0f7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae0f7_3:;
goto L_ae0fa;
}
L_ae0fa:{ // MOV dword ptr [ESP + 0x14],EAX
c.pc=0xae0fa;if(!sl_tick(c))return int(c.fault);
P_ae0fa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x14ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae0fa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae0fa_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae0fa_3:;
goto L_ae0fe;
}
L_ae0fe:{ // MOVZX EAX,byte ptr [EBP + 0x14]
c.pc=0xae0fe;if(!sl_tick(c))return int(c.fault);
P_ae0fe_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_ae0fe_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae0fe_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_ae0fe_3:;
goto L_ae102;
}
L_ae102:{ // MOV dword ptr [ESP + 0x10],EAX
c.pc=0xae102;if(!sl_tick(c))return int(c.fault);
P_ae102_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x10ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae102_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae102_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae102_3:;
goto L_ae106;
}
L_ae106:{ // MOVZX EAX,byte ptr [EBP + 0x10]
c.pc=0xae106;if(!sl_tick(c))return int(c.fault);
P_ae106_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_ae106_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae106_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_ae106_3:;
goto L_ae10a;
}
L_ae10a:{ // MOV dword ptr [ESP + 0xc],EAX
c.pc=0xae10a;if(!sl_tick(c))return int(c.fault);
P_ae10a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae10a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae10a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae10a_3:;
goto L_ae10e;
}
L_ae10e:{ // MOV EAX,ESI
c.pc=0xae10e;if(!sl_tick(c))return int(c.fault);
P_ae10e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae10e_1:;
goto L_ae110;
}
L_ae110:{ // AND EAX,0xf
c.pc=0xae110;if(!sl_tick(c))return int(c.fault);
P_ae110_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_ae110_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_ae110_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xfULL)),c);
P_ae110_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae110_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_ae110_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_ae110_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae110_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae110_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae110_9:;
goto L_ae113;
}
L_ae113:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0xae113;if(!sl_tick(c))return int(c.fault);
P_ae113_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae113_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae113_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae113_3:;
goto L_ae117;
}
L_ae117:{ // AND ESI,0xf0
c.pc=0xae117;if(!sl_tick(c))return int(c.fault);
P_ae117_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_ae117_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_ae117_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xf0ULL)),c);
P_ae117_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae117_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_ae117_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_ae117_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae117_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae117_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae117_9:;
goto L_ae11d;
}
L_ae11d:{ // MOV dword ptr [ESP + 0x4],ESI
c.pc=0xae11d;if(!sl_tick(c))return int(c.fault);
P_ae11d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae11d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae11d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae11d_3:;
goto L_ae121;
}
L_ae121:{ // MOV dword ptr [ESP],EDX
c.pc=0xae121;if(!sl_tick(c))return int(c.fault);
P_ae121_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_ae121_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae121_2:;
goto L_ae124;
}
L_ae124:{ // CALL dword ptr [ECX + 0x14]
c.pc=0xae124;if(!sl_tick(c))return int(c.fault);
P_ae124_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x14ULL)),c);
P_ae124_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae124_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae124_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae124_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xae127ULL),c);
P_ae124_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_ae124_6:;
goto L_ae127;
}
L_ae127:{ // MOV ESI,EAX
c.pc=0xae127;if(!sl_tick(c))return int(c.fault);
P_ae127_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae127_1:;
goto L_ae129;
}
L_ae129:{ // MOV EAX,ESI
c.pc=0xae129;if(!sl_tick(c))return int(c.fault);
P_ae129_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae129_1:;
goto L_ae12b;
}
L_ae12b:{ // ADD ESP,0x24
c.pc=0xae12b;if(!sl_tick(c))return int(c.fault);
P_ae12b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x24ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae12b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x24ULL)))&(SlU(0x24ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x24ULL)))&(SlU(1)<<31))!=0),c);
P_ae12b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x24ULL)),c);
P_ae12b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae12b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae12b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae12b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae12b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae12b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae12b_9:;
goto L_ae12e;
}
L_ae12e:{ // POP ESI
c.pc=0xae12e;if(!sl_tick(c))return int(c.fault);
P_ae12e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae12e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae12e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae12e_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae12e_4:;
goto L_ae12f;
}
L_ae12f:{ // POP EBP
c.pc=0xae12f;if(!sl_tick(c))return int(c.fault);
P_ae12f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae12f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae12f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae12f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae12f_4:;
goto L_ae130;
}
L_ae130:{ // RET
c.pc=0xae130;if(!sl_tick(c))return int(c.fault);
P_ae130_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae130_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae130_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_ae130_3:;
goto L_ae131;
}
L_ae131:{ // MOV ESI,0xffffffce
c.pc=0xae131;if(!sl_tick(c))return int(c.fault);
P_ae131_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,SlU(0xffffffceULL),c);
P_ae131_1:;
goto L_ae136;
}
L_ae136:{ // MOV EAX,ESI
c.pc=0xae136;if(!sl_tick(c))return int(c.fault);
P_ae136_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae136_1:;
goto L_ae138;
}
L_ae138:{ // ADD ESP,0x24
c.pc=0xae138;if(!sl_tick(c))return int(c.fault);
P_ae138_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x24ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae138_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x24ULL)))&(SlU(0x24ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x24ULL)))&(SlU(1)<<31))!=0),c);
P_ae138_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x24ULL)),c);
P_ae138_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae138_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae138_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae138_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae138_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae138_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae138_9:;
goto L_ae13b;
}
L_ae13b:{ // POP ESI
c.pc=0xae13b;if(!sl_tick(c))return int(c.fault);
P_ae13b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae13b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae13b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae13b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae13b_4:;
goto L_ae13c;
}
L_ae13c:{ // POP EBP
c.pc=0xae13c;if(!sl_tick(c))return int(c.fault);
P_ae13c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae13c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae13c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae13c_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae13c_4:;
goto L_ae13d;
}
L_ae13d:{ // RET
c.pc=0xae13d;if(!sl_tick(c))return int(c.fault);
P_ae13d_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae13d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae13d_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_ae13d_3:;
c.pc=0xae13e;goto dispatch;
}
L_ae198:{ // PUSH EBP
c.pc=0xae198;if(!sl_tick(c))return int(c.fault);
P_ae198_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_ae198_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae198_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ae198_3:;
goto L_ae199;
}
L_ae199:{ // MOV EBP,ESP
c.pc=0xae199;if(!sl_tick(c))return int(c.fault);
P_ae199_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_ae199_1:;
goto L_ae19b;
}
L_ae19b:{ // PUSH ESI
c.pc=0xae19b;if(!sl_tick(c))return int(c.fault);
P_ae19b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae19b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae19b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ae19b_3:;
goto L_ae19c;
}
L_ae19c:{ // SUB ESP,0x14
c.pc=0xae19c;if(!sl_tick(c))return int(c.fault);
P_ae19c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x14ULL)),c);
P_ae19c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x14ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x14ULL)))&(SlU(1)<<31))!=0),c);
P_ae19c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x14ULL)),c);
P_ae19c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae19c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae19c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae19c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae19c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae19c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae19c_9:;
goto L_ae19f;
}
L_ae19f:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0xae19f;if(!sl_tick(c))return int(c.fault);
P_ae19f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_ae19f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae19f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae19f_3:;
goto L_ae1a2;
}
L_ae1a2:{ // MOV dword ptr [ESI + 0x10],0x0
c.pc=0xae1a2;if(!sl_tick(c))return int(c.fault);
P_ae1a2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x10ULL)),c);
P_ae1a2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_ae1a2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ae1a2_3:;
goto L_ae1a9;
}
L_ae1a9:{ // MOV dword ptr [ESI + 0x14],0x0
c.pc=0xae1a9;if(!sl_tick(c))return int(c.fault);
P_ae1a9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x14ULL)),c);
P_ae1a9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_ae1a9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ae1a9_3:;
goto L_ae1b0;
}
L_ae1b0:{ // MOV dword ptr [ESI + 0x18],0x0
c.pc=0xae1b0;if(!sl_tick(c))return int(c.fault);
P_ae1b0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x18ULL)),c);
P_ae1b0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_ae1b0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ae1b0_3:;
goto L_ae1b7;
}
L_ae1b7:{ // MOV EAX,dword ptr [ESI + 0xc]
c.pc=0xae1b7;if(!sl_tick(c))return int(c.fault);
P_ae1b7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0xcULL)),c);
P_ae1b7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae1b7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae1b7_3:;
goto L_ae1ba;
}
L_ae1ba:{ // TEST EAX,EAX
c.pc=0xae1ba;if(!sl_tick(c))return int(c.fault);
P_ae1ba_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_ae1ba_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_ae1ba_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_ae1ba_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae1ba_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_ae1ba_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_ae1ba_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae1ba_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae1ba_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae1ba_9:;
goto L_ae1bc;
}
L_ae1bc:{ // JZ 0x000ae1cf
c.pc=0xae1bc;if(!sl_tick(c))return int(c.fault);
P_ae1bc_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_ae1cf;}
P_ae1bc_1:;
goto L_ae1be;
}
L_ae1be:{ // CMP byte ptr [ESI + 0x4],0x0
c.pc=0xae1be;if(!sl_tick(c))return int(c.fault);
P_ae1be_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x4ULL)),c);
P_ae1be_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae1be_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_ae1be_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_ae1be_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_ae1be_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_ae1be_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_ae1be_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_ae1be_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_ae1be_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae1be_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae1be_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae1be_12:;
goto L_ae1c2;
}
L_ae1c2:{ // JZ 0x000ae1db
c.pc=0xae1c2;if(!sl_tick(c))return int(c.fault);
P_ae1c2_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_ae1db;}
P_ae1c2_1:;
goto L_ae1c4;
}
L_ae1c4:{ // MOV byte ptr [ESI + 0x4],0x0
c.pc=0xae1c4;if(!sl_tick(c))return int(c.fault);
P_ae1c4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x4ULL)),c);
P_ae1c4_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_ae1c4_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_ae1c4_3:;
goto L_ae1c8;
}
L_ae1c8:{ // MOV dword ptr [ESI + 0xc],0x0
c.pc=0xae1c8;if(!sl_tick(c))return int(c.fault);
P_ae1c8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0xcULL)),c);
P_ae1c8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_ae1c8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ae1c8_3:;
goto L_ae1cf;
}
L_ae1cf:{ // MOV dword ptr [ESI],0x0
c.pc=0xae1cf;if(!sl_tick(c))return int(c.fault);
P_ae1cf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_ae1cf_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ae1cf_2:;
goto L_ae1d5;
}
L_ae1d5:{ // ADD ESP,0x14
c.pc=0xae1d5;if(!sl_tick(c))return int(c.fault);
P_ae1d5_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x14ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae1d5_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x14ULL)))&(SlU(0x14ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x14ULL)))&(SlU(1)<<31))!=0),c);
P_ae1d5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x14ULL)),c);
P_ae1d5_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae1d5_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae1d5_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae1d5_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae1d5_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae1d5_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae1d5_9:;
goto L_ae1d8;
}
L_ae1d8:{ // POP ESI
c.pc=0xae1d8;if(!sl_tick(c))return int(c.fault);
P_ae1d8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae1d8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae1d8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae1d8_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae1d8_4:;
goto L_ae1d9;
}
L_ae1d9:{ // POP EBP
c.pc=0xae1d9;if(!sl_tick(c))return int(c.fault);
P_ae1d9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae1d9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae1d9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae1d9_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae1d9_4:;
goto L_ae1da;
}
L_ae1da:{ // RET
c.pc=0xae1da;if(!sl_tick(c))return int(c.fault);
P_ae1da_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae1da_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae1da_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_ae1da_3:;
goto L_ae1db;
}
L_ae1db:{ // MOV dword ptr [ESP],EAX
c.pc=0xae1db;if(!sl_tick(c))return int(c.fault);
P_ae1db_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae1db_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae1db_2:;
goto L_ae1de;
}
L_ae1de:{ // CALL 0x0010300a
c.pc=0xae1de;if(!sl_tick(c))return int(c.fault);
P_ae1de_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae1de_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xae1e3ULL),c);
P_ae1de_2:;
c.pc=0x10300a;goto dispatch;
P_ae1de_3:;
goto L_ae1e3;
}
L_ae1e3:{ // JMP 0x000ae1c8
c.pc=0xae1e3;if(!sl_tick(c))return int(c.fault);
P_ae1e3_0:;
goto L_ae1c8;
P_ae1e3_1:;
c.pc=0xae1e5;goto dispatch;
}
L_ae1e6:{ // PUSH EBP
c.pc=0xae1e6;if(!sl_tick(c))return int(c.fault);
P_ae1e6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_ae1e6_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae1e6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ae1e6_3:;
goto L_ae1e7;
}
L_ae1e7:{ // MOV EBP,ESP
c.pc=0xae1e7;if(!sl_tick(c))return int(c.fault);
P_ae1e7_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_ae1e7_1:;
goto L_ae1e9;
}
L_ae1e9:{ // PUSH EDI
c.pc=0xae1e9;if(!sl_tick(c))return int(c.fault);
P_ae1e9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_ae1e9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae1e9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ae1e9_3:;
goto L_ae1ea;
}
L_ae1ea:{ // PUSH ESI
c.pc=0xae1ea;if(!sl_tick(c))return int(c.fault);
P_ae1ea_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae1ea_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae1ea_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ae1ea_3:;
goto L_ae1eb;
}
L_ae1eb:{ // SUB ESP,0x4
c.pc=0xae1eb;if(!sl_tick(c))return int(c.fault);
P_ae1eb_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x4ULL)),c);
P_ae1eb_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x4ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x4ULL)))&(SlU(1)<<31))!=0),c);
P_ae1eb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae1eb_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae1eb_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae1eb_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae1eb_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae1eb_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae1eb_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae1eb_9:;
goto L_ae1ee;
}
L_ae1ee:{ // MOV ECX,dword ptr [EBP + 0x8]
c.pc=0xae1ee;if(!sl_tick(c))return int(c.fault);
P_ae1ee_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_ae1ee_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae1ee_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae1ee_3:;
goto L_ae1f1;
}
L_ae1f1:{ // MOV ESI,dword ptr [EBP + 0xc]
c.pc=0xae1f1;if(!sl_tick(c))return int(c.fault);
P_ae1f1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_ae1f1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae1f1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae1f1_3:;
goto L_ae1f4;
}
L_ae1f4:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xae1f4;if(!sl_tick(c))return int(c.fault);
P_ae1f4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_ae1f4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae1f4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae1f4_3:;
goto L_ae1f7;
}
L_ae1f7:{ // MOV EDX,dword ptr [EAX + 0x4]
c.pc=0xae1f7;if(!sl_tick(c))return int(c.fault);
P_ae1f7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_ae1f7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae1f7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae1f7_3:;
goto L_ae1fa;
}
L_ae1fa:{ // AND EDX,0xfffffff0
c.pc=0xae1fa;if(!sl_tick(c))return int(c.fault);
P_ae1fa_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_ae1fa_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_ae1fa_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xfffffff0ULL)),c);
P_ae1fa_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae1fa_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_ae1fa_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_ae1fa_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae1fa_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae1fa_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae1fa_9:;
goto L_ae1fd;
}
L_ae1fd:{ // MOV EDI,dword ptr [ECX + 0xc]
c.pc=0xae1fd;if(!sl_tick(c))return int(c.fault);
P_ae1fd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0xcULL)),c);
P_ae1fd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae1fd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae1fd_3:;
goto L_ae200;
}
L_ae200:{ // TEST EDI,EDI
c.pc=0xae200;if(!sl_tick(c))return int(c.fault);
P_ae200_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_ae200_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_ae200_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) & sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c);
P_ae200_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae200_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_ae200_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_ae200_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae200_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae200_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae200_9:;
goto L_ae202;
}
L_ae202:{ // JZ 0x000ae247
c.pc=0xae202;if(!sl_tick(c))return int(c.fault);
P_ae202_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_ae247;}
P_ae202_1:;
goto L_ae204;
}
L_ae204:{ // CMP EDX,dword ptr [ECX + 0x18]
c.pc=0xae204;if(!sl_tick(c))return int(c.fault);
P_ae204_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x18ULL)),c);
P_ae204_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae204_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae204_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_ae204_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_ae204_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_ae204_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae204_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_ae204_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_ae204_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae204_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae204_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae204_12:;
goto L_ae207;
}
L_ae207:{ // JC 0x000ae247
c.pc=0xae207;if(!sl_tick(c))return int(c.fault);
P_ae207_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x200,c)){goto L_ae247;}
P_ae207_1:;
goto L_ae209;
}
L_ae209:{ // MOV EAX,dword ptr [EAX]
c.pc=0xae209;if(!sl_tick(c))return int(c.fault);
P_ae209_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_ae209_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae209_2:;
goto L_ae20b;
}
L_ae20b:{ // MOV dword ptr [ECX + 0xc],EAX
c.pc=0xae20b;if(!sl_tick(c))return int(c.fault);
P_ae20b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0xcULL)),c);
P_ae20b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae20b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae20b_3:;
goto L_ae20e;
}
L_ae20e:{ // MOV dword ptr [ECX + 0x18],EDX
c.pc=0xae20e;if(!sl_tick(c))return int(c.fault);
P_ae20e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x18ULL)),c);
P_ae20e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_ae20e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae20e_3:;
goto L_ae211;
}
L_ae211:{ // CMP dword ptr [ESI + 0x8],0x6c70636d
c.pc=0xae211;if(!sl_tick(c))return int(c.fault);
P_ae211_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x8ULL)),c);
P_ae211_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae211_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30a80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_ae211_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) < SlU(0x6c70636dULL)),c);
P_ae211_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^SlU(0x6c70636dULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)-SlU(0x6c70636dULL)))&(SlU(1)<<31))!=0),c);
P_ae211_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30b80,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) - SlU(0x6c70636dULL)),c);
P_ae211_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae211_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) == SlU(0x0ULL)),c);
P_ae211_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) & SlU(0xffULL)),c);
P_ae211_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae211_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae211_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae211_12:;
goto L_ae218;
}
L_ae218:{ // JZ 0x000ae24e
c.pc=0xae218;if(!sl_tick(c))return int(c.fault);
P_ae218_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_ae24e;}
P_ae218_1:;
goto L_ae21a;
}
L_ae21a:{ // MOV dword ptr [EBP + -0xc],0x1
c.pc=0xae21a;if(!sl_tick(c))return int(c.fault);
P_ae21a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_ae21a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x1ULL),c);
P_ae21a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ae21a_3:;
goto L_ae221;
}
L_ae221:{ // MOV EAX,dword ptr [EBP + -0xc]
c.pc=0xae221;if(!sl_tick(c))return int(c.fault);
P_ae221_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_ae221_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae221_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae221_3:;
goto L_ae224;
}
L_ae224:{ // IMUL EAX,dword ptr [ESI + 0x18]
c.pc=0xae224;if(!sl_tick(c))return int(c.fault);
P_ae224_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x18ULL)),c);
P_ae224_1:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a480,SlU(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32)),c);
P_ae224_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae224_3:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a500,SlU(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),32)),c);
P_ae224_4:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a600,(sl_get<8>(c.temp,sizeof(c.temp),0x3a480,c) * sl_get<8>(c.temp,sizeof(c.temp),0x3a500,c)),c);
P_ae224_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c),8*SlU(0x0ULL)),c);
P_ae224_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a780,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c),8*SlU(0x4ULL)),c);
P_ae224_7:;
sl_put<8>(c.temp,sizeof(c.temp),0x23880,SlU(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32)),c);
P_ae224_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<8>(c.temp,sizeof(c.temp),0x23880,c) != sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c)),c);
P_ae224_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,sl_get<1>(c.reg,sizeof(c.reg),0x200,c),c);
P_ae224_10:;
goto L_ae228;
}
L_ae228:{ // MOV dword ptr [EBP + -0xc],EAX
c.pc=0xae228;if(!sl_tick(c))return int(c.fault);
P_ae228_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_ae228_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae228_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae228_3:;
goto L_ae22b;
}
L_ae22b:{ // MOV EAX,EDX
c.pc=0xae22b;if(!sl_tick(c))return int(c.fault);
P_ae22b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_ae22b_1:;
goto L_ae22d;
}
L_ae22d:{ // XOR EDX,EDX
c.pc=0xae22d;if(!sl_tick(c))return int(c.fault);
P_ae22d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_ae22d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_ae22d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_ae22d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae22d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_ae22d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_ae22d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae22d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae22d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae22d_9:;
goto L_ae22f;
}
L_ae22f:{ // DIV dword ptr [EBP + -0xc]
c.pc=0xae22f;if(!sl_tick(c))return int(c.fault);
P_ae22f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_ae22f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae22f_2:;
sl_put<8>(c.temp,sizeof(c.temp),0x35680,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae22f_3:;
sl_put<8>(c.temp,sizeof(c.temp),0x35700,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_ae22f_4:;
sl_put<8>(c.temp,sizeof(c.temp),0x35780,sl_lshift(sl_get<8>(c.temp,sizeof(c.temp),0x35700,c),SlU(0x20ULL)),c);
P_ae22f_5:;
sl_put<8>(c.temp,sizeof(c.temp),0x35800,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae22f_6:;
sl_put<8>(c.temp,sizeof(c.temp),0x35900,(sl_get<8>(c.temp,sizeof(c.temp),0x35780,c) | sl_get<8>(c.temp,sizeof(c.temp),0x35800,c)),c);
P_ae22f_7:;
{const SlU result=sl_divide(c,sl_get<8>(c.temp,sizeof(c.temp),0x35900,c),sl_get<8>(c.temp,sizeof(c.temp),0x35680,c),64,32,false,false);if(c.fault)return int(c.fault);sl_put<8>(c.temp,sizeof(c.temp),0x35a00,result,c);}
P_ae22f_8:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x35a00,c),8*SlU(0x0ULL)),c);
P_ae22f_9:;
{const SlU result=sl_divide(c,sl_get<8>(c.temp,sizeof(c.temp),0x35900,c),sl_get<8>(c.temp,sizeof(c.temp),0x35680,c),64,32,false,true);if(c.fault)return int(c.fault);sl_put<8>(c.temp,sizeof(c.temp),0x35b80,result,c);}
P_ae22f_10:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x35b80,c),8*SlU(0x0ULL)),c);
P_ae22f_11:;
goto L_ae232;
}
L_ae232:{ // MOV dword ptr [ECX + 0x14],EAX
c.pc=0xae232;if(!sl_tick(c))return int(c.fault);
P_ae232_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x14ULL)),c);
P_ae232_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae232_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae232_3:;
goto L_ae235;
}
L_ae235:{ // MOV byte ptr [ECX + 0x4],0x1
c.pc=0xae235;if(!sl_tick(c))return int(c.fault);
P_ae235_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x4ULL)),c);
P_ae235_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x1ULL),c);
P_ae235_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_ae235_3:;
goto L_ae239;
}
L_ae239:{ // MOV dword ptr [EBP + 0x8],EDI
c.pc=0xae239;if(!sl_tick(c))return int(c.fault);
P_ae239_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_ae239_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_ae239_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae239_3:;
goto L_ae23c;
}
L_ae23c:{ // ADD ESP,0x4
c.pc=0xae23c;if(!sl_tick(c))return int(c.fault);
P_ae23c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae23c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4ULL)))&(SlU(0x4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4ULL)))&(SlU(1)<<31))!=0),c);
P_ae23c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae23c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae23c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae23c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae23c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae23c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae23c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae23c_9:;
goto L_ae23f;
}
L_ae23f:{ // POP ESI
c.pc=0xae23f;if(!sl_tick(c))return int(c.fault);
P_ae23f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae23f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae23f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae23f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae23f_4:;
goto L_ae240;
}
L_ae240:{ // POP EDI
c.pc=0xae240;if(!sl_tick(c))return int(c.fault);
P_ae240_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae240_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae240_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae240_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae240_4:;
goto L_ae241;
}
L_ae241:{ // POP EBP
c.pc=0xae241;if(!sl_tick(c))return int(c.fault);
P_ae241_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae241_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae241_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae241_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae241_4:;
goto L_ae242;
}
L_ae242:{ // JMP 0x0010300a
c.pc=0xae242;if(!sl_tick(c))return int(c.fault);
P_ae242_0:;
c.pc=0x10300a;goto dispatch;
P_ae242_1:;
goto L_ae247;
}
L_ae247:{ // ADD ESP,0x4
c.pc=0xae247;if(!sl_tick(c))return int(c.fault);
P_ae247_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae247_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4ULL)))&(SlU(0x4ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4ULL)))&(SlU(1)<<31))!=0),c);
P_ae247_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae247_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae247_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae247_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae247_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae247_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae247_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae247_9:;
goto L_ae24a;
}
L_ae24a:{ // POP ESI
c.pc=0xae24a;if(!sl_tick(c))return int(c.fault);
P_ae24a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae24a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae24a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae24a_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae24a_4:;
goto L_ae24b;
}
L_ae24b:{ // POP EDI
c.pc=0xae24b;if(!sl_tick(c))return int(c.fault);
P_ae24b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae24b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae24b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae24b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae24b_4:;
goto L_ae24c;
}
L_ae24c:{ // POP EBP
c.pc=0xae24c;if(!sl_tick(c))return int(c.fault);
P_ae24c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae24c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae24c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae24c_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae24c_4:;
goto L_ae24d;
}
L_ae24d:{ // RET
c.pc=0xae24d;if(!sl_tick(c))return int(c.fault);
P_ae24d_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae24d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae24d_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_ae24d_3:;
goto L_ae24e;
}
L_ae24e:{ // TEST byte ptr [ESI + 0xc],0x20
c.pc=0xae24e;if(!sl_tick(c))return int(c.fault);
P_ae24e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0xcULL)),c);
P_ae24e_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_ae24e_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_ae24e_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae24e_4:;
sl_put<1>(c.temp,sizeof(c.temp),0x54a80,(sl_get<1>(c.temp,sizeof(c.temp),0x9500,c) & SlU(0x20ULL)),c);
P_ae24e_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x54a80,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_ae24e_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x54a80,c) == SlU(0x0ULL)),c);
P_ae24e_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x54a80,c) & SlU(0xffULL)),c);
P_ae24e_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae24e_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae24e_10:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae24e_11:;
goto L_ae252;
}
L_ae252:{ // JZ 0x000ae21a
c.pc=0xae252;if(!sl_tick(c))return int(c.fault);
P_ae252_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_ae21a;}
P_ae252_1:;
goto L_ae254;
}
L_ae254:{ // MOV EAX,dword ptr [ESI + 0x1c]
c.pc=0xae254;if(!sl_tick(c))return int(c.fault);
P_ae254_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1cULL)),c);
P_ae254_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae254_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae254_3:;
goto L_ae257;
}
L_ae257:{ // MOV dword ptr [EBP + -0xc],EAX
c.pc=0xae257;if(!sl_tick(c))return int(c.fault);
P_ae257_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_ae257_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae257_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae257_3:;
goto L_ae25a;
}
L_ae25a:{ // JMP 0x000ae224
c.pc=0xae25a;if(!sl_tick(c))return int(c.fault);
P_ae25a_0:;
goto L_ae224;
P_ae25a_1:;
goto L_ae25c;
}
L_ae25c:{ // PUSH EBP
c.pc=0xae25c;if(!sl_tick(c))return int(c.fault);
P_ae25c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_ae25c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae25c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ae25c_3:;
goto L_ae25d;
}
L_ae25d:{ // MOV EBP,ESP
c.pc=0xae25d;if(!sl_tick(c))return int(c.fault);
P_ae25d_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_ae25d_1:;
goto L_ae25f;
}
L_ae25f:{ // PUSH EDI
c.pc=0xae25f;if(!sl_tick(c))return int(c.fault);
P_ae25f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_ae25f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae25f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ae25f_3:;
goto L_ae260;
}
L_ae260:{ // PUSH ESI
c.pc=0xae260;if(!sl_tick(c))return int(c.fault);
P_ae260_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae260_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae260_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ae260_3:;
goto L_ae261;
}
L_ae261:{ // SUB ESP,0x10
c.pc=0xae261;if(!sl_tick(c))return int(c.fault);
P_ae261_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x10ULL)),c);
P_ae261_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x10ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_ae261_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x10ULL)),c);
P_ae261_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae261_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae261_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae261_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae261_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae261_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae261_9:;
goto L_ae264;
}
L_ae264:{ // MOV EDI,dword ptr [EBP + 0x8]
c.pc=0xae264;if(!sl_tick(c))return int(c.fault);
P_ae264_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_ae264_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae264_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae264_3:;
goto L_ae267;
}
L_ae267:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0xae267;if(!sl_tick(c))return int(c.fault);
P_ae267_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_ae267_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae267_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae267_3:;
goto L_ae26a;
}
L_ae26a:{ // CMP dword ptr [EAX + 0x8],0x6c70636d
c.pc=0xae26a;if(!sl_tick(c))return int(c.fault);
P_ae26a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_ae26a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae26a_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30a80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_ae26a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) < SlU(0x6c70636dULL)),c);
P_ae26a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^SlU(0x6c70636dULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)-SlU(0x6c70636dULL)))&(SlU(1)<<31))!=0),c);
P_ae26a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30b80,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) - SlU(0x6c70636dULL)),c);
P_ae26a_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae26a_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) == SlU(0x0ULL)),c);
P_ae26a_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) & SlU(0xffULL)),c);
P_ae26a_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae26a_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae26a_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae26a_12:;
goto L_ae271;
}
L_ae271:{ // JZ 0x000ae2d0
c.pc=0xae271;if(!sl_tick(c))return int(c.fault);
P_ae271_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_ae2d0;}
P_ae271_1:;
goto L_ae273;
}
L_ae273:{ // MOV ESI,0x1
c.pc=0xae273;if(!sl_tick(c))return int(c.fault);
P_ae273_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,SlU(0x1ULL),c);
P_ae273_1:;
goto L_ae278;
}
L_ae278:{ // CMP ESI,dword ptr [EDI + 0x10]
c.pc=0xae278;if(!sl_tick(c))return int(c.fault);
P_ae278_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x10ULL)),c);
P_ae278_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae278_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae278_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_ae278_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_ae278_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_ae278_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae278_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_ae278_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_ae278_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae278_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae278_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae278_12:;
goto L_ae27b;
}
L_ae27b:{ // JA 0x000ae2e1
c.pc=0xae27b;if(!sl_tick(c))return int(c.fault);
P_ae27b_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9d80,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x200,c)) || bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c))),c);
P_ae27b_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9e80,(!sl_get<1>(c.temp,sizeof(c.temp),0x9d80,c)),c);
P_ae27b_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9e80,c)){goto L_ae2e1;}
P_ae27b_3:;
goto L_ae27d;
}
L_ae27d:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xae27d;if(!sl_tick(c))return int(c.fault);
P_ae27d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_ae27d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae27d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae27d_3:;
goto L_ae280;
}
L_ae280:{ // MOV EDX,dword ptr [EBP + 0xc]
c.pc=0xae280;if(!sl_tick(c))return int(c.fault);
P_ae280_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_ae280_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae280_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae280_3:;
goto L_ae283;
}
L_ae283:{ // IMUL EAX,dword ptr [EDX + 0x18]
c.pc=0xae283;if(!sl_tick(c))return int(c.fault);
P_ae283_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x18ULL)),c);
P_ae283_1:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a480,SlU(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32)),c);
P_ae283_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae283_3:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a500,SlU(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),32)),c);
P_ae283_4:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a600,(sl_get<8>(c.temp,sizeof(c.temp),0x3a480,c) * sl_get<8>(c.temp,sizeof(c.temp),0x3a500,c)),c);
P_ae283_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c),8*SlU(0x0ULL)),c);
P_ae283_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a780,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c),8*SlU(0x4ULL)),c);
P_ae283_7:;
sl_put<8>(c.temp,sizeof(c.temp),0x23880,SlU(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32)),c);
P_ae283_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<8>(c.temp,sizeof(c.temp),0x23880,c) != sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c)),c);
P_ae283_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,sl_get<1>(c.reg,sizeof(c.reg),0x200,c),c);
P_ae283_10:;
goto L_ae287;
}
L_ae287:{ // ADD EAX,0xf
c.pc=0xae287;if(!sl_tick(c))return int(c.fault);
P_ae287_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0xfULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_ae287_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0xfULL)))&(SlU(0xfULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0xfULL)))&(SlU(1)<<31))!=0),c);
P_ae287_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xfULL)),c);
P_ae287_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae287_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_ae287_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_ae287_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae287_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae287_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae287_9:;
goto L_ae28a;
}
L_ae28a:{ // AND EAX,0xfffffff0
c.pc=0xae28a;if(!sl_tick(c))return int(c.fault);
P_ae28a_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_ae28a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_ae28a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xfffffff0ULL)),c);
P_ae28a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae28a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_ae28a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_ae28a_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae28a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae28a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae28a_9:;
goto L_ae28d;
}
L_ae28d:{ // IMUL ESI,EAX
c.pc=0xae28d;if(!sl_tick(c))return int(c.fault);
P_ae28d_0:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a480,SlU(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32)),c);
P_ae28d_1:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a500,SlU(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32)),c);
P_ae28d_2:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a600,(sl_get<8>(c.temp,sizeof(c.temp),0x3a480,c) * sl_get<8>(c.temp,sizeof(c.temp),0x3a500,c)),c);
P_ae28d_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c),8*SlU(0x0ULL)),c);
P_ae28d_4:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a780,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c),8*SlU(0x4ULL)),c);
P_ae28d_5:;
sl_put<8>(c.temp,sizeof(c.temp),0x23880,SlU(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32)),c);
P_ae28d_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<8>(c.temp,sizeof(c.temp),0x23880,c) != sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c)),c);
P_ae28d_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,sl_get<1>(c.reg,sizeof(c.reg),0x200,c),c);
P_ae28d_8:;
goto L_ae290;
}
L_ae290:{ // CMP ESI,dword ptr [EDI + 0x18]
c.pc=0xae290;if(!sl_tick(c))return int(c.fault);
P_ae290_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x18ULL)),c);
P_ae290_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae290_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae290_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_ae290_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_ae290_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_ae290_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae290_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_ae290_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_ae290_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae290_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae290_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae290_12:;
goto L_ae293;
}
L_ae293:{ // JBE 0x000ae2b0
c.pc=0xae293;if(!sl_tick(c))return int(c.fault);
P_ae293_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9d00,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x200,c)) || bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c))),c);
P_ae293_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9d00,c)){goto L_ae2b0;}
P_ae293_2:;
goto L_ae295;
}
L_ae295:{ // CMP byte ptr [EDI + 0x4],0x0
c.pc=0xae295;if(!sl_tick(c))return int(c.fault);
P_ae295_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x4ULL)),c);
P_ae295_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae295_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_ae295_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_ae295_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_ae295_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_ae295_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_ae295_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_ae295_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_ae295_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae295_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae295_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae295_12:;
goto L_ae299;
}
L_ae299:{ // JNZ 0x000ae2c3
c.pc=0xae299;if(!sl_tick(c))return int(c.fault);
P_ae299_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_ae299_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_ae2c3;}
P_ae299_2:;
goto L_ae29b;
}
L_ae29b:{ // MOV dword ptr [ESP + 0x4],ESI
c.pc=0xae29b;if(!sl_tick(c))return int(c.fault);
P_ae29b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae29b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae29b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae29b_3:;
goto L_ae29f;
}
L_ae29f:{ // MOV EAX,dword ptr [EDI + 0xc]
c.pc=0xae29f;if(!sl_tick(c))return int(c.fault);
P_ae29f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xcULL)),c);
P_ae29f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae29f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae29f_3:;
goto L_ae2a2;
}
L_ae2a2:{ // MOV dword ptr [ESP],EAX
c.pc=0xae2a2;if(!sl_tick(c))return int(c.fault);
P_ae2a2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae2a2_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae2a2_2:;
goto L_ae2a5;
}
L_ae2a5:{ // CALL 0x00103406
c.pc=0xae2a5;if(!sl_tick(c))return int(c.fault);
P_ae2a5_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae2a5_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xae2aaULL),c);
P_ae2a5_2:;
c.pc=0x103406;goto dispatch;
P_ae2a5_3:;
goto L_ae2aa;
}
L_ae2aa:{ // MOV dword ptr [EDI + 0xc],EAX
c.pc=0xae2aa;if(!sl_tick(c))return int(c.fault);
P_ae2aa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xcULL)),c);
P_ae2aa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae2aa_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae2aa_3:;
goto L_ae2ad;
}
L_ae2ad:{ // MOV dword ptr [EDI + 0x18],ESI
c.pc=0xae2ad;if(!sl_tick(c))return int(c.fault);
P_ae2ad_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x18ULL)),c);
P_ae2ad_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae2ad_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae2ad_3:;
goto L_ae2b0;
}
L_ae2b0:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xae2b0;if(!sl_tick(c))return int(c.fault);
P_ae2b0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_ae2b0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae2b0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae2b0_3:;
goto L_ae2b3;
}
L_ae2b3:{ // MOV dword ptr [EDI + 0x14],EAX
c.pc=0xae2b3;if(!sl_tick(c))return int(c.fault);
P_ae2b3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x14ULL)),c);
P_ae2b3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae2b3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae2b3_3:;
goto L_ae2b6;
}
L_ae2b6:{ // MOV dword ptr [EDI],0x0
c.pc=0xae2b6;if(!sl_tick(c))return int(c.fault);
P_ae2b6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_ae2b6_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ae2b6_2:;
goto L_ae2bc;
}
L_ae2bc:{ // ADD ESP,0x10
c.pc=0xae2bc;if(!sl_tick(c))return int(c.fault);
P_ae2bc_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae2bc_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_ae2bc_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_ae2bc_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae2bc_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae2bc_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae2bc_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae2bc_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae2bc_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae2bc_9:;
goto L_ae2bf;
}
L_ae2bf:{ // POP ESI
c.pc=0xae2bf;if(!sl_tick(c))return int(c.fault);
P_ae2bf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae2bf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae2bf_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae2bf_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae2bf_4:;
goto L_ae2c0;
}
L_ae2c0:{ // POP EDI
c.pc=0xae2c0;if(!sl_tick(c))return int(c.fault);
P_ae2c0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae2c0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae2c0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae2c0_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae2c0_4:;
goto L_ae2c1;
}
L_ae2c1:{ // POP EBP
c.pc=0xae2c1;if(!sl_tick(c))return int(c.fault);
P_ae2c1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_ae2c1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae2c1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae2c1_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_ae2c1_4:;
goto L_ae2c2;
}
L_ae2c2:{ // RET
c.pc=0xae2c2;if(!sl_tick(c))return int(c.fault);
P_ae2c2_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_ae2c2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_ae2c2_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_ae2c2_3:;
goto L_ae2c3;
}
L_ae2c3:{ // MOV byte ptr [EDI + 0x4],0x0
c.pc=0xae2c3;if(!sl_tick(c))return int(c.fault);
P_ae2c3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x4ULL)),c);
P_ae2c3_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_ae2c3_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_ae2c3_3:;
goto L_ae2c7;
}
L_ae2c7:{ // MOV dword ptr [EDI + 0xc],0x0
c.pc=0xae2c7;if(!sl_tick(c))return int(c.fault);
P_ae2c7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xcULL)),c);
P_ae2c7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_ae2c7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ae2c7_3:;
goto L_ae2ce;
}
L_ae2ce:{ // JMP 0x000ae29b
c.pc=0xae2ce;if(!sl_tick(c))return int(c.fault);
P_ae2ce_0:;
goto L_ae29b;
P_ae2ce_1:;
goto L_ae2d0;
}
L_ae2d0:{ // TEST byte ptr [EAX + 0xc],0x20
c.pc=0xae2d0;if(!sl_tick(c))return int(c.fault);
P_ae2d0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xcULL)),c);
P_ae2d0_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_ae2d0_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_ae2d0_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae2d0_4:;
sl_put<1>(c.temp,sizeof(c.temp),0x54a80,(sl_get<1>(c.temp,sizeof(c.temp),0x9500,c) & SlU(0x20ULL)),c);
P_ae2d0_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x54a80,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_ae2d0_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x54a80,c) == SlU(0x0ULL)),c);
P_ae2d0_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x54a80,c) & SlU(0xffULL)),c);
P_ae2d0_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae2d0_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae2d0_10:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae2d0_11:;
goto L_ae2d4;
}
L_ae2d4:{ // JZ 0x000ae273
c.pc=0xae2d4;if(!sl_tick(c))return int(c.fault);
P_ae2d4_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_ae273;}
P_ae2d4_1:;
goto L_ae2d6;
}
L_ae2d6:{ // MOV EDX,dword ptr [EBP + 0xc]
c.pc=0xae2d6;if(!sl_tick(c))return int(c.fault);
P_ae2d6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_ae2d6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae2d6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae2d6_3:;
goto L_ae2d9;
}
L_ae2d9:{ // MOV ESI,dword ptr [EDX + 0x1c]
c.pc=0xae2d9;if(!sl_tick(c))return int(c.fault);
P_ae2d9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x1cULL)),c);
P_ae2d9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae2d9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae2d9_3:;
goto L_ae2dc;
}
L_ae2dc:{ // CMP ESI,dword ptr [EDI + 0x10]
c.pc=0xae2dc;if(!sl_tick(c))return int(c.fault);
P_ae2dc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x10ULL)),c);
P_ae2dc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae2dc_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae2dc_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_ae2dc_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_ae2dc_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_ae2dc_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae2dc_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_ae2dc_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_ae2dc_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae2dc_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae2dc_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae2dc_12:;
goto L_ae2df;
}
L_ae2df:{ // JBE 0x000ae27d
c.pc=0xae2df;if(!sl_tick(c))return int(c.fault);
P_ae2df_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9d00,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x200,c)) || bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c))),c);
P_ae2df_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9d00,c)){goto L_ae27d;}
P_ae2df_2:;
goto L_ae2e1;
}
L_ae2e1:{ // LEA EAX,[ESI + ESI*0x2]
c.pc=0xae2e1;if(!sl_tick(c))return int(c.fault);
P_ae2e1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) * SlU(0x2ULL)),c);
P_ae2e1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_ae2e1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3580,c),c);
P_ae2e1_3:;
goto L_ae2e4;
}
L_ae2e4:{ // LEA EAX,[EAX*0x4 + 0x4]
c.pc=0xae2e4;if(!sl_tick(c))return int(c.fault);
P_ae2e4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3600,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x4ULL)),c);
P_ae2e4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3700,(SlU(0x4ULL) + sl_get<4>(c.temp,sizeof(c.temp),0x3600,c)),c);
P_ae2e4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3700,c),c);
P_ae2e4_3:;
goto L_ae2eb;
}
L_ae2eb:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xae2eb;if(!sl_tick(c))return int(c.fault);
P_ae2eb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_ae2eb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae2eb_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae2eb_3:;
goto L_ae2ef;
}
L_ae2ef:{ // MOV EAX,dword ptr [EDI + 0x8]
c.pc=0xae2ef;if(!sl_tick(c))return int(c.fault);
P_ae2ef_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x8ULL)),c);
P_ae2ef_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae2ef_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae2ef_3:;
goto L_ae2f2;
}
L_ae2f2:{ // MOV dword ptr [ESP],EAX
c.pc=0xae2f2;if(!sl_tick(c))return int(c.fault);
P_ae2f2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae2f2_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae2f2_2:;
goto L_ae2f5;
}
L_ae2f5:{ // CALL 0x00103406
c.pc=0xae2f5;if(!sl_tick(c))return int(c.fault);
P_ae2f5_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae2f5_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xae2faULL),c);
P_ae2f5_2:;
c.pc=0x103406;goto dispatch;
P_ae2f5_3:;
goto L_ae2fa;
}
L_ae2fa:{ // MOV dword ptr [EDI + 0x8],EAX
c.pc=0xae2fa;if(!sl_tick(c))return int(c.fault);
P_ae2fa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x8ULL)),c);
P_ae2fa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae2fa_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae2fa_3:;
goto L_ae2fd;
}
L_ae2fd:{ // MOV dword ptr [EDI + 0x10],ESI
c.pc=0xae2fd;if(!sl_tick(c))return int(c.fault);
P_ae2fd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x10ULL)),c);
P_ae2fd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae2fd_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae2fd_3:;
goto L_ae300;
}
L_ae300:{ // JMP 0x000ae27d
c.pc=0xae300;if(!sl_tick(c))return int(c.fault);
P_ae300_0:;
goto L_ae27d;
P_ae300_1:;
c.pc=0xae305;goto dispatch;
}
L_ae306:{ // PUSH EBP
c.pc=0xae306;if(!sl_tick(c))return int(c.fault);
P_ae306_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_ae306_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae306_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ae306_3:;
goto L_ae307;
}
L_ae307:{ // MOV EBP,ESP
c.pc=0xae307;if(!sl_tick(c))return int(c.fault);
P_ae307_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_ae307_1:;
goto L_ae309;
}
L_ae309:{ // PUSH EDI
c.pc=0xae309;if(!sl_tick(c))return int(c.fault);
P_ae309_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_ae309_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae309_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ae309_3:;
goto L_ae30a;
}
L_ae30a:{ // PUSH ESI
c.pc=0xae30a;if(!sl_tick(c))return int(c.fault);
P_ae30a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_ae30a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae30a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ae30a_3:;
goto L_ae30b;
}
L_ae30b:{ // PUSH EBX
c.pc=0xae30b;if(!sl_tick(c))return int(c.fault);
P_ae30b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_ae30b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae30b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_ae30b_3:;
goto L_ae30c;
}
L_ae30c:{ // SUB ESP,0x3c
c.pc=0xae30c;if(!sl_tick(c))return int(c.fault);
P_ae30c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x3cULL)),c);
P_ae30c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x3cULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x3cULL)))&(SlU(1)<<31))!=0),c);
P_ae30c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x3cULL)),c);
P_ae30c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae30c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_ae30c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_ae30c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae30c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae30c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae30c_9:;
goto L_ae30f;
}
L_ae30f:{ // CALL 0x000c086c
c.pc=0xae30f;if(!sl_tick(c))return int(c.fault);
P_ae30f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_ae30f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xae314ULL),c);
P_ae30f_2:;
c.pc=0xc086c;goto dispatch;
P_ae30f_3:;
goto L_ae314;
}
L_ae314:{ // MOV EDI,dword ptr [EBP + 0xc]
c.pc=0xae314;if(!sl_tick(c))return int(c.fault);
P_ae314_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_ae314_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae314_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae314_3:;
goto L_ae317;
}
L_ae317:{ // CMP dword ptr [EDI + 0x8],0x6c70636d
c.pc=0xae317;if(!sl_tick(c))return int(c.fault);
P_ae317_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x8ULL)),c);
P_ae317_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae317_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30a80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_ae317_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) < SlU(0x6c70636dULL)),c);
P_ae317_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^SlU(0x6c70636dULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c)-SlU(0x6c70636dULL)))&(SlU(1)<<31))!=0),c);
P_ae317_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30b80,(sl_get<4>(c.temp,sizeof(c.temp),0x30a80,c) - SlU(0x6c70636dULL)),c);
P_ae317_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae317_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) == SlU(0x0ULL)),c);
P_ae317_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30b80,c) & SlU(0xffULL)),c);
P_ae317_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae317_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae317_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae317_12:;
goto L_ae31e;
}
L_ae31e:{ // JZ 0x000ae3b6
c.pc=0xae31e;if(!sl_tick(c))return int(c.fault);
P_ae31e_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){c.pc=0xae3b6;goto dispatch;}
P_ae31e_1:;
goto L_ae324;
}
L_ae324:{ // MOV EAX,dword ptr [EDI + 0x1c]
c.pc=0xae324;if(!sl_tick(c))return int(c.fault);
P_ae324_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x1cULL)),c);
P_ae324_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae324_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae324_3:;
goto L_ae327;
}
L_ae327:{ // MOV dword ptr [EBP + -0x24],EAX
c.pc=0xae327;if(!sl_tick(c))return int(c.fault);
P_ae327_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_ae327_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae327_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae327_3:;
goto L_ae32a;
}
L_ae32a:{ // MOV EDX,0x1
c.pc=0xae32a;if(!sl_tick(c))return int(c.fault);
P_ae32a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,SlU(0x1ULL),c);
P_ae32a_1:;
goto L_ae32f;
}
L_ae32f:{ // MOV dword ptr [EBP + -0x1c],0x0
c.pc=0xae32f;if(!sl_tick(c))return int(c.fault);
P_ae32f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_ae32f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_ae32f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_ae32f_3:;
goto L_ae336;
}
L_ae336:{ // MOV ECX,dword ptr [EBP + 0x8]
c.pc=0xae336;if(!sl_tick(c))return int(c.fault);
P_ae336_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_ae336_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae336_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae336_3:;
goto L_ae339;
}
L_ae339:{ // MOV EAX,dword ptr [ECX + 0x8]
c.pc=0xae339;if(!sl_tick(c))return int(c.fault);
P_ae339_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x8ULL)),c);
P_ae339_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae339_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae339_3:;
goto L_ae33c;
}
L_ae33c:{ // MOV dword ptr [EAX],EDX
c.pc=0xae33c;if(!sl_tick(c))return int(c.fault);
P_ae33c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_ae33c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae33c_2:;
goto L_ae33e;
}
L_ae33e:{ // LEA ECX,[EAX + 0x4]
c.pc=0xae33e;if(!sl_tick(c))return int(c.fault);
P_ae33e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_ae33e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_ae33e_2:;
goto L_ae341;
}
L_ae341:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0xae341;if(!sl_tick(c))return int(c.fault);
P_ae341_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_ae341_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae341_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae341_3:;
goto L_ae344;
}
L_ae344:{ // MOV EAX,dword ptr [EAX + 0xc]
c.pc=0xae344;if(!sl_tick(c))return int(c.fault);
P_ae344_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xcULL)),c);
P_ae344_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae344_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae344_3:;
goto L_ae347;
}
L_ae347:{ // MOV dword ptr [EBP + -0x28],EAX
c.pc=0xae347;if(!sl_tick(c))return int(c.fault);
P_ae347_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd8ULL)),c);
P_ae347_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae347_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_ae347_3:;
goto L_ae34a;
}
L_ae34a:{ // MOV ESI,EAX
c.pc=0xae34a;if(!sl_tick(c))return int(c.fault);
P_ae34a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_ae34a_1:;
goto L_ae34c;
}
L_ae34c:{ // MOV EDX,dword ptr [EDI + 0x18]
c.pc=0xae34c;if(!sl_tick(c))return int(c.fault);
P_ae34c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x18ULL)),c);
P_ae34c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae34c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae34c_3:;
goto L_ae34f;
}
L_ae34f:{ // MOV EAX,EDX
c.pc=0xae34f;if(!sl_tick(c))return int(c.fault);
P_ae34f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_ae34f_1:;
goto L_ae351;
}
L_ae351:{ // MOV EDI,dword ptr [EBP + 0x8]
c.pc=0xae351;if(!sl_tick(c))return int(c.fault);
P_ae351_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_ae351_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae351_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_ae351_3:;
goto L_ae354;
}
L_ae354:{ // IMUL EAX,dword ptr [EDI + 0x14]
c.pc=0xae354;if(!sl_tick(c))return int(c.fault);
P_ae354_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x14ULL)),c);
P_ae354_1:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a480,SlU(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32)),c);
P_ae354_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae354_3:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a500,SlU(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),32)),c);
P_ae354_4:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a600,(sl_get<8>(c.temp,sizeof(c.temp),0x3a480,c) * sl_get<8>(c.temp,sizeof(c.temp),0x3a500,c)),c);
P_ae354_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c),8*SlU(0x0ULL)),c);
P_ae354_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a780,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c),8*SlU(0x4ULL)),c);
P_ae354_7:;
sl_put<8>(c.temp,sizeof(c.temp),0x23880,SlU(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32)),c);
P_ae354_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<8>(c.temp,sizeof(c.temp),0x23880,c) != sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c)),c);
P_ae354_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,sl_get<1>(c.reg,sizeof(c.reg),0x200,c),c);
P_ae354_10:;
goto L_ae358;
}
L_ae358:{ // LEA EDI,[EAX + 0xf]
c.pc=0xae358;if(!sl_tick(c))return int(c.fault);
P_ae358_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xfULL)),c);
P_ae358_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_ae358_2:;
goto L_ae35b;
}
L_ae35b:{ // AND EDI,0xfffffff0
c.pc=0xae35b;if(!sl_tick(c))return int(c.fault);
P_ae35b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_ae35b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_ae35b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) & SlU(0xfffffff0ULL)),c);
P_ae35b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_ae35b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) == SlU(0x0ULL)),c);
P_ae35b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) & SlU(0xffULL)),c);
P_ae35b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_ae35b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_ae35b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_ae35b_9:;
goto L_ae35e;
}
L_ae35e:{ // IMUL EDX,dword ptr [EBP + 0x10]
c.pc=0xae35e;if(!sl_tick(c))return int(c.fault);
P_ae35e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_ae35e_1:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a480,SlU(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32)),c);
P_ae35e_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_ae35e_3:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a500,SlU(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),32)),c);
P_ae35e_4:;
sl_put<8>(c.temp,sizeof(c.temp),0x3a600,(sl_get<8>(c.temp,sizeof(c.temp),0x3a480,c) * sl_get<8>(c.temp,sizeof(c.temp),0x3a500,c)),c);
P_ae35e_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c),8*SlU(0x0ULL)),c);
P_ae35e_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a780,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c),8*SlU(0x4ULL)),c);
P_ae35e_7:;
sl_put<8>(c.temp,sizeof(c.temp),0x23880,SlU(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32)),c);
P_ae35e_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<8>(c.temp,sizeof(c.temp),0x23880,c) != sl_get<8>(c.temp,sizeof(c.temp),0x3a600,c)),c);
P_ae35e_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,sl_get<1>(c.reg,sizeof(c.reg),0x200,c),c);
P_ae35e_10:;
c.pc=0xae362;goto dispatch;
}
}
