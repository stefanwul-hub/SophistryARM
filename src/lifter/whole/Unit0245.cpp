// Generated static p-code lift; original i386 SHA-256: 17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12
#include "LifterRuntime.h"
int sl_unit_0245(SlCpu& c){
goto dispatch;
dispatch:
if(c.fault||c.pc==c.stop)return int(c.fault);
switch(c.pc){
case 0x886ca:goto L_886ca;
case 0x886d0:goto L_886d0;
case 0x886d2:goto L_886d2;
case 0x886dc:goto L_886dc;
case 0x886e2:goto L_886e2;
case 0x886e5:goto L_886e5;
case 0x886eb:goto L_886eb;
case 0x886f1:goto L_886f1;
case 0x886f7:goto L_886f7;
case 0x88701:goto L_88701;
case 0x88704:goto L_88704;
case 0x88706:goto L_88706;
case 0x8870c:goto L_8870c;
case 0x88712:goto L_88712;
case 0x88714:goto L_88714;
case 0x88717:goto L_88717;
case 0x8871a:goto L_8871a;
case 0x8871d:goto L_8871d;
case 0x8871e:goto L_8871e;
case 0x8871f:goto L_8871f;
case 0x88720:goto L_88720;
case 0x88721:goto L_88721;
case 0x88724:goto L_88724;
case 0x88725:goto L_88725;
case 0x88727:goto L_88727;
case 0x88728:goto L_88728;
case 0x88729:goto L_88729;
case 0x8872c:goto L_8872c;
case 0x88731:goto L_88731;
case 0x88734:goto L_88734;
case 0x8873c:goto L_8873c;
case 0x88744:goto L_88744;
case 0x88748:goto L_88748;
case 0x8874e:goto L_8874e;
case 0x88754:goto L_88754;
case 0x88756:goto L_88756;
case 0x88758:goto L_88758;
case 0x8875b:goto L_8875b;
case 0x88760:goto L_88760;
case 0x8876a:goto L_8876a;
case 0x88770:goto L_88770;
case 0x88772:goto L_88772;
case 0x88774:goto L_88774;
case 0x88777:goto L_88777;
case 0x8877c:goto L_8877c;
case 0x88786:goto L_88786;
case 0x8878c:goto L_8878c;
case 0x8878e:goto L_8878e;
case 0x88790:goto L_88790;
case 0x88793:goto L_88793;
case 0x88798:goto L_88798;
case 0x887a2:goto L_887a2;
case 0x887a8:goto L_887a8;
case 0x887aa:goto L_887aa;
case 0x887ac:goto L_887ac;
case 0x887af:goto L_887af;
case 0x887b4:goto L_887b4;
case 0x887be:goto L_887be;
case 0x887c4:goto L_887c4;
case 0x887c6:goto L_887c6;
case 0x887c8:goto L_887c8;
case 0x887cb:goto L_887cb;
case 0x887d0:goto L_887d0;
case 0x887da:goto L_887da;
case 0x887e0:goto L_887e0;
case 0x887e2:goto L_887e2;
case 0x887e4:goto L_887e4;
case 0x887e7:goto L_887e7;
case 0x887ec:goto L_887ec;
case 0x887f6:goto L_887f6;
case 0x887fc:goto L_887fc;
case 0x88800:goto L_88800;
case 0x88803:goto L_88803;
case 0x88808:goto L_88808;
case 0x8880e:goto L_8880e;
case 0x88814:goto L_88814;
case 0x88818:goto L_88818;
case 0x8881b:goto L_8881b;
case 0x88820:goto L_88820;
case 0x88826:goto L_88826;
case 0x8882c:goto L_8882c;
case 0x88830:goto L_88830;
case 0x88833:goto L_88833;
case 0x88838:goto L_88838;
case 0x8883e:goto L_8883e;
case 0x88844:goto L_88844;
case 0x88848:goto L_88848;
case 0x8884b:goto L_8884b;
case 0x88850:goto L_88850;
case 0x88856:goto L_88856;
case 0x8885c:goto L_8885c;
case 0x88860:goto L_88860;
case 0x88863:goto L_88863;
case 0x88868:goto L_88868;
case 0x8886e:goto L_8886e;
case 0x88874:goto L_88874;
case 0x88878:goto L_88878;
case 0x8887b:goto L_8887b;
case 0x88880:goto L_88880;
case 0x88886:goto L_88886;
case 0x8888c:goto L_8888c;
case 0x8888e:goto L_8888e;
case 0x88894:goto L_88894;
case 0x8889a:goto L_8889a;
case 0x8889c:goto L_8889c;
case 0x888a2:goto L_888a2;
case 0x888a8:goto L_888a8;
case 0x888aa:goto L_888aa;
case 0x888b0:goto L_888b0;
case 0x888b6:goto L_888b6;
case 0x888b8:goto L_888b8;
case 0x888be:goto L_888be;
case 0x888c4:goto L_888c4;
case 0x888c6:goto L_888c6;
case 0x888cc:goto L_888cc;
case 0x888ce:goto L_888ce;
case 0x888d4:goto L_888d4;
case 0x888da:goto L_888da;
case 0x888dc:goto L_888dc;
case 0x888de:goto L_888de;
case 0x888e6:goto L_888e6;
case 0x888e8:goto L_888e8;
case 0x888f0:goto L_888f0;
case 0x888f7:goto L_888f7;
case 0x888fd:goto L_888fd;
case 0x88902:goto L_88902;
case 0x88908:goto L_88908;
case 0x8890d:goto L_8890d;
case 0x88913:goto L_88913;
case 0x88918:goto L_88918;
case 0x8891e:goto L_8891e;
case 0x88923:goto L_88923;
case 0x88929:goto L_88929;
case 0x8892e:goto L_8892e;
case 0x88934:goto L_88934;
case 0x88939:goto L_88939;
case 0x8893c:goto L_8893c;
case 0x8893f:goto L_8893f;
case 0x88945:goto L_88945;
case 0x88947:goto L_88947;
case 0x88951:goto L_88951;
case 0x8895b:goto L_8895b;
case 0x88965:goto L_88965;
case 0x8896f:goto L_8896f;
case 0x88979:goto L_88979;
case 0x88983:goto L_88983;
case 0x88985:goto L_88985;
case 0x88988:goto L_88988;
case 0x8898e:goto L_8898e;
case 0x88991:goto L_88991;
case 0x88992:goto L_88992;
case 0x88993:goto L_88993;
case 0x88994:goto L_88994;
case 0x88996:goto L_88996;
case 0x88999:goto L_88999;
case 0x8899a:goto L_8899a;
case 0x8899b:goto L_8899b;
case 0x8899c:goto L_8899c;
case 0x8899e:goto L_8899e;
case 0x8899f:goto L_8899f;
case 0x889a1:goto L_889a1;
case 0x889a2:goto L_889a2;
case 0x889a3:goto L_889a3;
case 0x889a6:goto L_889a6;
case 0x889a9:goto L_889a9;
case 0x889ac:goto L_889ac;
case 0x889b4:goto L_889b4;
case 0x889b9:goto L_889b9;
case 0x889bf:goto L_889bf;
case 0x889c2:goto L_889c2;
case 0x889c7:goto L_889c7;
case 0x889cc:goto L_889cc;
case 0x889d4:goto L_889d4;
case 0x889d7:goto L_889d7;
case 0x889da:goto L_889da;
case 0x889dd:goto L_889dd;
case 0x889de:goto L_889de;
case 0x889df:goto L_889df;
case 0x889e0:goto L_889e0;
case 0x889e6:goto L_889e6;
case 0x889e7:goto L_889e7;
case 0x889e9:goto L_889e9;
case 0x889ea:goto L_889ea;
case 0x889eb:goto L_889eb;
case 0x889f0:goto L_889f0;
case 0x889f3:goto L_889f3;
case 0x889f6:goto L_889f6;
case 0x889fe:goto L_889fe;
case 0x88a00:goto L_88a00;
case 0x88a06:goto L_88a06;
case 0x88a08:goto L_88a08;
case 0x88a09:goto L_88a09;
case 0x88a0a:goto L_88a0a;
case 0x88a0b:goto L_88a0b;
case 0x88a0c:goto L_88a0c;
case 0x88a13:goto L_88a13;
case 0x88a15:goto L_88a15;
case 0x88a1b:goto L_88a1b;
case 0x88a1d:goto L_88a1d;
case 0x88a1f:goto L_88a1f;
case 0x88a27:goto L_88a27;
case 0x88a29:goto L_88a29;
case 0x88a31:goto L_88a31;
case 0x88a38:goto L_88a38;
case 0x88a3e:goto L_88a3e;
case 0x88a43:goto L_88a43;
case 0x88a49:goto L_88a49;
case 0x88a4e:goto L_88a4e;
case 0x88a54:goto L_88a54;
case 0x88a59:goto L_88a59;
case 0x88a5f:goto L_88a5f;
case 0x88a64:goto L_88a64;
case 0x88a6a:goto L_88a6a;
case 0x88a6f:goto L_88a6f;
case 0x88a75:goto L_88a75;
case 0x88a7a:goto L_88a7a;
case 0x88a7d:goto L_88a7d;
case 0x88a80:goto L_88a80;
case 0x88a86:goto L_88a86;
case 0x88a88:goto L_88a88;
case 0x88a89:goto L_88a89;
case 0x88a8a:goto L_88a8a;
case 0x88a8b:goto L_88a8b;
case 0x88a8c:goto L_88a8c;
case 0x88a8d:goto L_88a8d;
case 0x88a8f:goto L_88a8f;
case 0x88a90:goto L_88a90;
case 0x88a91:goto L_88a91;
case 0x88a92:goto L_88a92;
case 0x88a95:goto L_88a95;
case 0x88a9a:goto L_88a9a;
case 0x88a9d:goto L_88a9d;
case 0x88aa4:goto L_88aa4;
case 0x88aaa:goto L_88aaa;
case 0x88ab0:goto L_88ab0;
case 0x88ab2:goto L_88ab2;
case 0x88ab8:goto L_88ab8;
case 0x88abf:goto L_88abf;
case 0x88ac5:goto L_88ac5;
case 0x88ac9:goto L_88ac9;
case 0x88acf:goto L_88acf;
case 0x88ad7:goto L_88ad7;
case 0x88adf:goto L_88adf;
case 0x88ae3:goto L_88ae3;
case 0x88ae7:goto L_88ae7;
case 0x88aec:goto L_88aec;
case 0x88aee:goto L_88aee;
case 0x88af1:goto L_88af1;
case 0x88af7:goto L_88af7;
case 0x88afa:goto L_88afa;
case 0x88b00:goto L_88b00;
case 0x88b02:goto L_88b02;
case 0x88b08:goto L_88b08;
case 0x88b0a:goto L_88b0a;
case 0x88b10:goto L_88b10;
case 0x88b17:goto L_88b17;
case 0x88b1d:goto L_88b1d;
case 0x88b25:goto L_88b25;
case 0x88b2d:goto L_88b2d;
case 0x88b33:goto L_88b33;
case 0x88b36:goto L_88b36;
case 0x88b39:goto L_88b39;
case 0x88b3f:goto L_88b3f;
case 0x88b47:goto L_88b47;
case 0x88b4a:goto L_88b4a;
case 0x88b4e:goto L_88b4e;
case 0x88b51:goto L_88b51;
case 0x88b55:goto L_88b55;
case 0x88b58:goto L_88b58;
case 0x88b5e:goto L_88b5e;
case 0x88b66:goto L_88b66;
case 0x88b6a:goto L_88b6a;
case 0x88b6e:goto L_88b6e;
case 0x88b74:goto L_88b74;
case 0x88b76:goto L_88b76;
case 0x88b7c:goto L_88b7c;
case 0x88b83:goto L_88b83;
case 0x88b89:goto L_88b89;
case 0x88b91:goto L_88b91;
case 0x88b99:goto L_88b99;
case 0x88b9f:goto L_88b9f;
case 0x88ba2:goto L_88ba2;
case 0x88ba5:goto L_88ba5;
case 0x88bab:goto L_88bab;
case 0x88bb3:goto L_88bb3;
case 0x88bb6:goto L_88bb6;
case 0x88bba:goto L_88bba;
case 0x88bbd:goto L_88bbd;
case 0x88bc1:goto L_88bc1;
case 0x88bc4:goto L_88bc4;
case 0x88bca:goto L_88bca;
case 0x88bd2:goto L_88bd2;
case 0x88bd6:goto L_88bd6;
case 0x88bda:goto L_88bda;
case 0x88be0:goto L_88be0;
case 0x88be6:goto L_88be6;
case 0x88be8:goto L_88be8;
case 0x88bee:goto L_88bee;
case 0x88bf1:goto L_88bf1;
case 0x88bf7:goto L_88bf7;
case 0x88bf9:goto L_88bf9;
case 0x88bff:goto L_88bff;
case 0x88c05:goto L_88c05;
case 0x88c07:goto L_88c07;
case 0x88c0d:goto L_88c0d;
case 0x88c13:goto L_88c13;
case 0x88c15:goto L_88c15;
case 0x88c1b:goto L_88c1b;
case 0x88c23:goto L_88c23;
case 0x88c26:goto L_88c26;
case 0x88c2e:goto L_88c2e;
case 0x88c36:goto L_88c36;
case 0x88c3e:goto L_88c3e;
case 0x88c46:goto L_88c46;
case 0x88c4a:goto L_88c4a;
case 0x88c4e:goto L_88c4e;
case 0x88c56:goto L_88c56;
case 0x88c5a:goto L_88c5a;
case 0x88c62:goto L_88c62;
case 0x88c66:goto L_88c66;
case 0x88c6a:goto L_88c6a;
case 0x88c6e:goto L_88c6e;
case 0x88c76:goto L_88c76;
case 0x88c7e:goto L_88c7e;
case 0x88c86:goto L_88c86;
case 0x88c8a:goto L_88c8a;
case 0x88c8e:goto L_88c8e;
case 0x88c96:goto L_88c96;
case 0x88c9a:goto L_88c9a;
case 0x88c9e:goto L_88c9e;
case 0x88ca2:goto L_88ca2;
case 0x88caa:goto L_88caa;
case 0x88cb2:goto L_88cb2;
case 0x88cba:goto L_88cba;
case 0x88cbe:goto L_88cbe;
case 0x88cc2:goto L_88cc2;
case 0x88cc6:goto L_88cc6;
case 0x88cca:goto L_88cca;
case 0x88cce:goto L_88cce;
case 0x88cd6:goto L_88cd6;
case 0x88cde:goto L_88cde;
case 0x88ce6:goto L_88ce6;
case 0x88cea:goto L_88cea;
case 0x88cee:goto L_88cee;
case 0x88cf2:goto L_88cf2;
case 0x88cf6:goto L_88cf6;
case 0x88cfa:goto L_88cfa;
case 0x88d02:goto L_88d02;
case 0x88d08:goto L_88d08;
case 0x88d0e:goto L_88d0e;
case 0x88d14:goto L_88d14;
case 0x88d1a:goto L_88d1a;
case 0x88d1d:goto L_88d1d;
case 0x88d1e:goto L_88d1e;
case 0x88d1f:goto L_88d1f;
case 0x88d20:goto L_88d20;
case 0x88d21:goto L_88d21;
case 0x88d22:goto L_88d22;
case 0x88d2a:goto L_88d2a;
case 0x88d2f:goto L_88d2f;
case 0x88d35:goto L_88d35;
case 0x88d38:goto L_88d38;
case 0x88d3b:goto L_88d3b;
case 0x88d41:goto L_88d41;
case 0x88d49:goto L_88d49;
case 0x88d4f:goto L_88d4f;
case 0x88d52:goto L_88d52;
case 0x88d56:goto L_88d56;
case 0x88d59:goto L_88d59;
case 0x88d5d:goto L_88d5d;
case 0x88d60:goto L_88d60;
case 0x88d66:goto L_88d66;
case 0x88d6e:goto L_88d6e;
case 0x88d72:goto L_88d72;
case 0x88d75:goto L_88d75;
case 0x88d79:goto L_88d79;
case 0x88d7c:goto L_88d7c;
case 0x88d7e:goto L_88d7e;
case 0x88d83:goto L_88d83;
case 0x88d87:goto L_88d87;
case 0x88d8f:goto L_88d8f;
case 0x88d93:goto L_88d93;
case 0x88d97:goto L_88d97;
case 0x88d9d:goto L_88d9d;
case 0x88da3:goto L_88da3;
case 0x88da5:goto L_88da5;
case 0x88dab:goto L_88dab;
case 0x88db5:goto L_88db5;
case 0x88dba:goto L_88dba;
case 0x88dbe:goto L_88dbe;
case 0x88dc3:goto L_88dc3;
case 0x88dc7:goto L_88dc7;
case 0x88dca:goto L_88dca;
case 0x88dce:goto L_88dce;
case 0x88dd1:goto L_88dd1;
case 0x88dd7:goto L_88dd7;
case 0x88ddb:goto L_88ddb;
case 0x88dde:goto L_88dde;
case 0x88de2:goto L_88de2;
case 0x88de5:goto L_88de5;
case 0x88de7:goto L_88de7;
case 0x88dec:goto L_88dec;
case 0x88df0:goto L_88df0;
case 0x88df3:goto L_88df3;
case 0x88df7:goto L_88df7;
case 0x88dfa:goto L_88dfa;
case 0x88e00:goto L_88e00;
case 0x88e04:goto L_88e04;
case 0x88e07:goto L_88e07;
case 0x88e0b:goto L_88e0b;
case 0x88e0e:goto L_88e0e;
case 0x88e10:goto L_88e10;
case 0x88e15:goto L_88e15;
case 0x88e19:goto L_88e19;
case 0x88e1c:goto L_88e1c;
case 0x88e21:goto L_88e21;
case 0x88e24:goto L_88e24;
case 0x88e29:goto L_88e29;
case 0x88e2f:goto L_88e2f;
case 0x88e35:goto L_88e35;
case 0x88e3d:goto L_88e3d;
case 0x88e42:goto L_88e42;
case 0x88e46:goto L_88e46;
case 0x88e49:goto L_88e49;
case 0x88e4e:goto L_88e4e;
case 0x88e51:goto L_88e51;
case 0x88e56:goto L_88e56;
case 0x88e5c:goto L_88e5c;
case 0x88e62:goto L_88e62;
case 0x88e6a:goto L_88e6a;
case 0x88e6f:goto L_88e6f;
case 0x88e79:goto L_88e79;
case 0x88e7e:goto L_88e7e;
case 0x88e82:goto L_88e82;
case 0x88e85:goto L_88e85;
case 0x88e8a:goto L_88e8a;
case 0x88e8d:goto L_88e8d;
case 0x88e92:goto L_88e92;
case 0x88e98:goto L_88e98;
case 0x88e9e:goto L_88e9e;
case 0x88e9f:goto L_88e9f;
case 0x88ea1:goto L_88ea1;
case 0x88ea2:goto L_88ea2;
case 0x88ea3:goto L_88ea3;
case 0x88ea6:goto L_88ea6;
case 0x88eab:goto L_88eab;
case 0x88eae:goto L_88eae;
case 0x88eb1:goto L_88eb1;
case 0x88eb6:goto L_88eb6;
case 0x88ebc:goto L_88ebc;
case 0x88ebe:goto L_88ebe;
case 0x88ec8:goto L_88ec8;
case 0x88ed2:goto L_88ed2;
case 0x88edc:goto L_88edc;
case 0x88edf:goto L_88edf;
case 0x88ee0:goto L_88ee0;
case 0x88ee1:goto L_88ee1;
case 0x88ee2:goto L_88ee2;
case 0x88ee4:goto L_88ee4;
case 0x88ee5:goto L_88ee5;
case 0x88ee7:goto L_88ee7;
case 0x88eec:goto L_88eec;
case 0x88eef:goto L_88eef;
case 0x88ef5:goto L_88ef5;
case 0x88ef7:goto L_88ef7;
case 0x88efa:goto L_88efa;
case 0x88efb:goto L_88efb;
case 0x88f00:goto L_88f00;
case 0x88f01:goto L_88f01;
case 0x88f03:goto L_88f03;
case 0x88f04:goto L_88f04;
case 0x88f05:goto L_88f05;
case 0x88f08:goto L_88f08;
case 0x88f0d:goto L_88f0d;
case 0x88f10:goto L_88f10;
case 0x88f16:goto L_88f16;
case 0x88f18:goto L_88f18;
case 0x88f1b:goto L_88f1b;
case 0x88f20:goto L_88f20;
case 0x88f23:goto L_88f23;
case 0x88f26:goto L_88f26;
case 0x88f27:goto L_88f27;
case 0x88f28:goto L_88f28;
case 0x88f29:goto L_88f29;
case 0x88f2e:goto L_88f2e;
case 0x88f2f:goto L_88f2f;
case 0x88f31:goto L_88f31;
case 0x88f32:goto L_88f32;
case 0x88f33:goto L_88f33;
case 0x88f34:goto L_88f34;
case 0x88f37:goto L_88f37;
case 0x88f3c:goto L_88f3c;
case 0x88f3f:goto L_88f3f;
case 0x88f42:goto L_88f42;
case 0x88f45:goto L_88f45;
case 0x88f48:goto L_88f48;
case 0x88f4b:goto L_88f4b;
case 0x88f4d:goto L_88f4d;
case 0x88f4f:goto L_88f4f;
case 0x88f55:goto L_88f55;
case 0x88f57:goto L_88f57;
case 0x88f59:goto L_88f59;
case 0x88f5f:goto L_88f5f;
case 0x88f61:goto L_88f61;
case 0x88f63:goto L_88f63;
case 0x88f66:goto L_88f66;
case 0x88f6b:goto L_88f6b;
case 0x88f6d:goto L_88f6d;
case 0x88f6f:goto L_88f6f;
case 0x88f72:goto L_88f72;
case 0x88f73:goto L_88f73;
case 0x88f74:goto L_88f74;
default:return 0;}
L_886ca:{ // CMP EAX,dword ptr [ESI + 0x21c]
c.pc=0x886ca;if(!sl_tick(c))return int(c.fault);
P_886ca_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x21cULL)),c);
P_886ca_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_886ca_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_886ca_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_886ca_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_886ca_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_886ca_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_886ca_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_886ca_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_886ca_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_886ca_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_886ca_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_886ca_12:;
goto L_886d0;
}
L_886d0:{ // JLE 0x000886dc
c.pc=0x886d0;if(!sl_tick(c))return int(c.fault);
P_886d0_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_886d0_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_886d0_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_886dc;}
P_886d0_3:;
goto L_886d2;
}
L_886d2:{ // MOV dword ptr [ESI + 0x1e4],0x0
c.pc=0x886d2;if(!sl_tick(c))return int(c.fault);
P_886d2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1e4ULL)),c);
P_886d2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_886d2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_886d2_3:;
goto L_886dc;
}
L_886dc:{ // MOV EAX,dword ptr [ESI + 0x1e8]
c.pc=0x886dc;if(!sl_tick(c))return int(c.fault);
P_886dc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1e8ULL)),c);
P_886dc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_886dc_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_886dc_3:;
goto L_886e2;
}
L_886e2:{ // ADD EAX,0x1
c.pc=0x886e2;if(!sl_tick(c))return int(c.fault);
P_886e2_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_886e2_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_886e2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x1ULL)),c);
P_886e2_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_886e2_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_886e2_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_886e2_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_886e2_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_886e2_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_886e2_9:;
goto L_886e5;
}
L_886e5:{ // MOV dword ptr [ESI + 0x1e8],EAX
c.pc=0x886e5;if(!sl_tick(c))return int(c.fault);
P_886e5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1e8ULL)),c);
P_886e5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_886e5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_886e5_3:;
goto L_886eb;
}
L_886eb:{ // CMP EAX,dword ptr [ESI + 0x220]
c.pc=0x886eb;if(!sl_tick(c))return int(c.fault);
P_886eb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x220ULL)),c);
P_886eb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_886eb_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_886eb_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_886eb_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_886eb_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_886eb_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_886eb_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_886eb_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_886eb_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_886eb_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_886eb_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_886eb_12:;
goto L_886f1;
}
L_886f1:{ // JLE 0x0008851b
c.pc=0x886f1;if(!sl_tick(c))return int(c.fault);
P_886f1_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_886f1_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_886f1_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){c.pc=0x8851b;goto dispatch;}
P_886f1_3:;
goto L_886f7;
}
L_886f7:{ // MOV dword ptr [ESI + 0x1e8],0x0
c.pc=0x886f7;if(!sl_tick(c))return int(c.fault);
P_886f7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1e8ULL)),c);
P_886f7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_886f7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_886f7_3:;
goto L_88701;
}
L_88701:{ // SUB EDI,0x1
c.pc=0x88701;if(!sl_tick(c))return int(c.fault);
P_88701_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) < SlU(0x1ULL)),c);
P_88701_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)^SlU(0x1ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)-SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_88701_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) - SlU(0x1ULL)),c);
P_88701_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88701_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) == SlU(0x0ULL)),c);
P_88701_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) & SlU(0xffULL)),c);
P_88701_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88701_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88701_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88701_9:;
goto L_88704;
}
L_88704:{ // TEST EDI,EDI
c.pc=0x88704;if(!sl_tick(c))return int(c.fault);
P_88704_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88704_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88704_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) & sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c);
P_88704_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88704_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_88704_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_88704_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88704_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88704_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88704_9:;
goto L_88706;
}
L_88706:{ // JG 0x00088526
c.pc=0x88706;if(!sl_tick(c))return int(c.fault);
P_88706_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_88706_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88706_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_88706_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){c.pc=0x88526;goto dispatch;}
P_88706_4:;
goto L_8870c;
}
L_8870c:{ // MOV EAX,dword ptr [ESI + 0x118]
c.pc=0x8870c;if(!sl_tick(c))return int(c.fault);
P_8870c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x118ULL)),c);
P_8870c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_8870c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_8870c_3:;
goto L_88712;
}
L_88712:{ // MOV EDX,dword ptr [EAX]
c.pc=0x88712;if(!sl_tick(c))return int(c.fault);
P_88712_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_88712_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88712_2:;
goto L_88714;
}
L_88714:{ // MOV dword ptr [EBP + 0x8],EAX
c.pc=0x88714;if(!sl_tick(c))return int(c.fault);
P_88714_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_88714_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88714_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88714_3:;
goto L_88717;
}
L_88717:{ // MOV ECX,dword ptr [EDX + 0x44]
c.pc=0x88717;if(!sl_tick(c))return int(c.fault);
P_88717_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x44ULL)),c);
P_88717_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88717_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88717_3:;
goto L_8871a;
}
L_8871a:{ // ADD ESP,0x6c
c.pc=0x8871a;if(!sl_tick(c))return int(c.fault);
P_8871a_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x6cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_8871a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x6cULL)))&(SlU(0x6cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x6cULL)))&(SlU(1)<<31))!=0),c);
P_8871a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x6cULL)),c);
P_8871a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_8871a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_8871a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_8871a_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_8871a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_8871a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_8871a_9:;
goto L_8871d;
}
L_8871d:{ // POP EBX
c.pc=0x8871d;if(!sl_tick(c))return int(c.fault);
P_8871d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_8871d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_8871d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_8871d_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_8871d_4:;
goto L_8871e;
}
L_8871e:{ // POP ESI
c.pc=0x8871e;if(!sl_tick(c))return int(c.fault);
P_8871e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_8871e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_8871e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_8871e_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_8871e_4:;
goto L_8871f;
}
L_8871f:{ // POP EDI
c.pc=0x8871f;if(!sl_tick(c))return int(c.fault);
P_8871f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_8871f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_8871f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_8871f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_8871f_4:;
goto L_88720;
}
L_88720:{ // POP EBP
c.pc=0x88720;if(!sl_tick(c))return int(c.fault);
P_88720_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88720_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88720_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88720_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88720_4:;
goto L_88721;
}
L_88721:{ // JMP ECX
c.pc=0x88721;if(!sl_tick(c))return int(c.fault);
P_88721_0:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c));goto dispatch;
P_88721_1:;
c.pc=0x88723;goto dispatch;
}
L_88724:{ // PUSH EBP
c.pc=0x88724;if(!sl_tick(c))return int(c.fault);
P_88724_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_88724_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88724_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88724_3:;
goto L_88725;
}
L_88725:{ // MOV EBP,ESP
c.pc=0x88725;if(!sl_tick(c))return int(c.fault);
P_88725_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_88725_1:;
goto L_88727;
}
L_88727:{ // PUSH ESI
c.pc=0x88727;if(!sl_tick(c))return int(c.fault);
P_88727_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88727_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88727_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88727_3:;
goto L_88728;
}
L_88728:{ // PUSH EBX
c.pc=0x88728;if(!sl_tick(c))return int(c.fault);
P_88728_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_88728_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88728_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88728_3:;
goto L_88729;
}
L_88729:{ // SUB ESP,0x10
c.pc=0x88729;if(!sl_tick(c))return int(c.fault);
P_88729_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x10ULL)),c);
P_88729_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x10ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_88729_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x10ULL)),c);
P_88729_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88729_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_88729_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_88729_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88729_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88729_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88729_9:;
goto L_8872c;
}
L_8872c:{ // CALL 0x000c086c
c.pc=0x8872c;if(!sl_tick(c))return int(c.fault);
P_8872c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_8872c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88731ULL),c);
P_8872c_2:;
c.pc=0xc086c;goto dispatch;
P_8872c_3:;
goto L_88731;
}
L_88731:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0x88731;if(!sl_tick(c))return int(c.fault);
P_88731_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_88731_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88731_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88731_3:;
goto L_88734;
}
L_88734:{ // CVTSS2SD XMM0,dword ptr [ESI + 0x140]
c.pc=0x88734;if(!sl_tick(c))return int(c.fault);
P_88734_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x140ULL)),c);
P_88734_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88734_2:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)))),c);
P_88734_3:;
goto L_8873c;
}
L_8873c:{ // MULSD XMM0,qword ptr [EBX + 0x40117]
c.pc=0x8873c;if(!sl_tick(c))return int(c.fault);
P_8873c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x40117ULL)),c);
P_8873c_1:;
sl_put<8>(c.temp,sizeof(c.temp),0x5280,sl_get<8>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_8873c_2:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<double>(sl_get<8>(c.temp,sizeof(c.temp),0x5280,c))),c);
P_8873c_3:;
goto L_88744;
}
L_88744:{ // CVTTSD2SI EAX,XMM0
c.pc=0x88744;if(!sl_tick(c))return int(c.fault);
P_88744_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_trunc_fp(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c),8,32),c);
P_88744_1:;
goto L_88748;
}
L_88748:{ // MOV dword ptr [ESI + 0x204],EAX
c.pc=0x88748;if(!sl_tick(c))return int(c.fault);
P_88748_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_88748_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88748_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88748_3:;
goto L_8874e;
}
L_8874e:{ // MOV EAX,dword ptr [ESI + 0x1ec]
c.pc=0x8874e;if(!sl_tick(c))return int(c.fault);
P_8874e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ecULL)),c);
P_8874e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_8874e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_8874e_3:;
goto L_88754;
}
L_88754:{ // TEST EAX,EAX
c.pc=0x88754;if(!sl_tick(c))return int(c.fault);
P_88754_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88754_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88754_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_88754_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88754_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_88754_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_88754_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88754_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88754_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88754_9:;
goto L_88756;
}
L_88756:{ // JZ 0x00088760
c.pc=0x88756;if(!sl_tick(c))return int(c.fault);
P_88756_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88760;}
P_88756_1:;
goto L_88758;
}
L_88758:{ // MOV dword ptr [ESP],EAX
c.pc=0x88758;if(!sl_tick(c))return int(c.fault);
P_88758_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88758_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88758_2:;
goto L_8875b;
}
L_8875b:{ // CALL 0x0010300a
c.pc=0x8875b;if(!sl_tick(c))return int(c.fault);
P_8875b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_8875b_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88760ULL),c);
P_8875b_2:;
c.pc=0x10300a;goto dispatch;
P_8875b_3:;
goto L_88760;
}
L_88760:{ // MOV dword ptr [ESI + 0x1ec],0x0
c.pc=0x88760;if(!sl_tick(c))return int(c.fault);
P_88760_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ecULL)),c);
P_88760_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_88760_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_88760_3:;
goto L_8876a;
}
L_8876a:{ // MOV EAX,dword ptr [ESI + 0x1f0]
c.pc=0x8876a;if(!sl_tick(c))return int(c.fault);
P_8876a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f0ULL)),c);
P_8876a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_8876a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_8876a_3:;
goto L_88770;
}
L_88770:{ // TEST EAX,EAX
c.pc=0x88770;if(!sl_tick(c))return int(c.fault);
P_88770_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88770_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88770_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_88770_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88770_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_88770_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_88770_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88770_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88770_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88770_9:;
goto L_88772;
}
L_88772:{ // JZ 0x0008877c
c.pc=0x88772;if(!sl_tick(c))return int(c.fault);
P_88772_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_8877c;}
P_88772_1:;
goto L_88774;
}
L_88774:{ // MOV dword ptr [ESP],EAX
c.pc=0x88774;if(!sl_tick(c))return int(c.fault);
P_88774_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88774_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88774_2:;
goto L_88777;
}
L_88777:{ // CALL 0x0010300a
c.pc=0x88777;if(!sl_tick(c))return int(c.fault);
P_88777_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88777_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x8877cULL),c);
P_88777_2:;
c.pc=0x10300a;goto dispatch;
P_88777_3:;
goto L_8877c;
}
L_8877c:{ // MOV dword ptr [ESI + 0x1f0],0x0
c.pc=0x8877c;if(!sl_tick(c))return int(c.fault);
P_8877c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f0ULL)),c);
P_8877c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_8877c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_8877c_3:;
goto L_88786;
}
L_88786:{ // MOV EAX,dword ptr [ESI + 0x1f4]
c.pc=0x88786;if(!sl_tick(c))return int(c.fault);
P_88786_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f4ULL)),c);
P_88786_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88786_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88786_3:;
goto L_8878c;
}
L_8878c:{ // TEST EAX,EAX
c.pc=0x8878c;if(!sl_tick(c))return int(c.fault);
P_8878c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_8878c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_8878c_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_8878c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_8878c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_8878c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_8878c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_8878c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_8878c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_8878c_9:;
goto L_8878e;
}
L_8878e:{ // JZ 0x00088798
c.pc=0x8878e;if(!sl_tick(c))return int(c.fault);
P_8878e_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88798;}
P_8878e_1:;
goto L_88790;
}
L_88790:{ // MOV dword ptr [ESP],EAX
c.pc=0x88790;if(!sl_tick(c))return int(c.fault);
P_88790_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88790_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88790_2:;
goto L_88793;
}
L_88793:{ // CALL 0x0010300a
c.pc=0x88793;if(!sl_tick(c))return int(c.fault);
P_88793_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88793_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88798ULL),c);
P_88793_2:;
c.pc=0x10300a;goto dispatch;
P_88793_3:;
goto L_88798;
}
L_88798:{ // MOV dword ptr [ESI + 0x1f4],0x0
c.pc=0x88798;if(!sl_tick(c))return int(c.fault);
P_88798_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f4ULL)),c);
P_88798_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_88798_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_88798_3:;
goto L_887a2;
}
L_887a2:{ // MOV EAX,dword ptr [ESI + 0x1f8]
c.pc=0x887a2;if(!sl_tick(c))return int(c.fault);
P_887a2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f8ULL)),c);
P_887a2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_887a2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_887a2_3:;
goto L_887a8;
}
L_887a8:{ // TEST EAX,EAX
c.pc=0x887a8;if(!sl_tick(c))return int(c.fault);
P_887a8_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_887a8_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_887a8_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_887a8_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_887a8_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_887a8_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_887a8_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_887a8_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_887a8_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_887a8_9:;
goto L_887aa;
}
L_887aa:{ // JZ 0x000887b4
c.pc=0x887aa;if(!sl_tick(c))return int(c.fault);
P_887aa_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_887b4;}
P_887aa_1:;
goto L_887ac;
}
L_887ac:{ // MOV dword ptr [ESP],EAX
c.pc=0x887ac;if(!sl_tick(c))return int(c.fault);
P_887ac_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_887ac_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_887ac_2:;
goto L_887af;
}
L_887af:{ // CALL 0x0010300a
c.pc=0x887af;if(!sl_tick(c))return int(c.fault);
P_887af_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_887af_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x887b4ULL),c);
P_887af_2:;
c.pc=0x10300a;goto dispatch;
P_887af_3:;
goto L_887b4;
}
L_887b4:{ // MOV dword ptr [ESI + 0x1f8],0x0
c.pc=0x887b4;if(!sl_tick(c))return int(c.fault);
P_887b4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f8ULL)),c);
P_887b4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_887b4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_887b4_3:;
goto L_887be;
}
L_887be:{ // MOV EAX,dword ptr [ESI + 0x1fc]
c.pc=0x887be;if(!sl_tick(c))return int(c.fault);
P_887be_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1fcULL)),c);
P_887be_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_887be_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_887be_3:;
goto L_887c4;
}
L_887c4:{ // TEST EAX,EAX
c.pc=0x887c4;if(!sl_tick(c))return int(c.fault);
P_887c4_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_887c4_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_887c4_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_887c4_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_887c4_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_887c4_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_887c4_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_887c4_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_887c4_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_887c4_9:;
goto L_887c6;
}
L_887c6:{ // JZ 0x000887d0
c.pc=0x887c6;if(!sl_tick(c))return int(c.fault);
P_887c6_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_887d0;}
P_887c6_1:;
goto L_887c8;
}
L_887c8:{ // MOV dword ptr [ESP],EAX
c.pc=0x887c8;if(!sl_tick(c))return int(c.fault);
P_887c8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_887c8_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_887c8_2:;
goto L_887cb;
}
L_887cb:{ // CALL 0x0010300a
c.pc=0x887cb;if(!sl_tick(c))return int(c.fault);
P_887cb_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_887cb_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x887d0ULL),c);
P_887cb_2:;
c.pc=0x10300a;goto dispatch;
P_887cb_3:;
goto L_887d0;
}
L_887d0:{ // MOV dword ptr [ESI + 0x1fc],0x0
c.pc=0x887d0;if(!sl_tick(c))return int(c.fault);
P_887d0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1fcULL)),c);
P_887d0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_887d0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_887d0_3:;
goto L_887da;
}
L_887da:{ // MOV EAX,dword ptr [ESI + 0x200]
c.pc=0x887da;if(!sl_tick(c))return int(c.fault);
P_887da_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x200ULL)),c);
P_887da_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_887da_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_887da_3:;
goto L_887e0;
}
L_887e0:{ // TEST EAX,EAX
c.pc=0x887e0;if(!sl_tick(c))return int(c.fault);
P_887e0_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_887e0_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_887e0_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_887e0_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_887e0_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_887e0_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_887e0_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_887e0_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_887e0_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_887e0_9:;
goto L_887e2;
}
L_887e2:{ // JZ 0x000887ec
c.pc=0x887e2;if(!sl_tick(c))return int(c.fault);
P_887e2_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_887ec;}
P_887e2_1:;
goto L_887e4;
}
L_887e4:{ // MOV dword ptr [ESP],EAX
c.pc=0x887e4;if(!sl_tick(c))return int(c.fault);
P_887e4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_887e4_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_887e4_2:;
goto L_887e7;
}
L_887e7:{ // CALL 0x0010300a
c.pc=0x887e7;if(!sl_tick(c))return int(c.fault);
P_887e7_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_887e7_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x887ecULL),c);
P_887e7_2:;
c.pc=0x10300a;goto dispatch;
P_887e7_3:;
goto L_887ec;
}
L_887ec:{ // MOV dword ptr [ESI + 0x200],0x0
c.pc=0x887ec;if(!sl_tick(c))return int(c.fault);
P_887ec_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x200ULL)),c);
P_887ec_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_887ec_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_887ec_3:;
goto L_887f6;
}
L_887f6:{ // MOV EAX,dword ptr [ESI + 0x204]
c.pc=0x887f6;if(!sl_tick(c))return int(c.fault);
P_887f6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_887f6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_887f6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_887f6_3:;
goto L_887fc;
}
L_887fc:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x887fc;if(!sl_tick(c))return int(c.fault);
P_887fc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_887fc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_887fc_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_887fc_3:;
goto L_88800;
}
L_88800:{ // MOV dword ptr [ESP],ESI
c.pc=0x88800;if(!sl_tick(c))return int(c.fault);
P_88800_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88800_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88800_2:;
goto L_88803;
}
L_88803:{ // CALL 0x00013124
c.pc=0x88803;if(!sl_tick(c))return int(c.fault);
P_88803_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88803_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88808ULL),c);
P_88803_2:;
c.pc=0x13124;goto dispatch;
P_88803_3:;
goto L_88808;
}
L_88808:{ // MOV dword ptr [ESI + 0x1ec],EAX
c.pc=0x88808;if(!sl_tick(c))return int(c.fault);
P_88808_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ecULL)),c);
P_88808_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88808_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88808_3:;
goto L_8880e;
}
L_8880e:{ // MOV EAX,dword ptr [ESI + 0x204]
c.pc=0x8880e;if(!sl_tick(c))return int(c.fault);
P_8880e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_8880e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_8880e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_8880e_3:;
goto L_88814;
}
L_88814:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x88814;if(!sl_tick(c))return int(c.fault);
P_88814_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_88814_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88814_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88814_3:;
goto L_88818;
}
L_88818:{ // MOV dword ptr [ESP],ESI
c.pc=0x88818;if(!sl_tick(c))return int(c.fault);
P_88818_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88818_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88818_2:;
goto L_8881b;
}
L_8881b:{ // CALL 0x00013124
c.pc=0x8881b;if(!sl_tick(c))return int(c.fault);
P_8881b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_8881b_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88820ULL),c);
P_8881b_2:;
c.pc=0x13124;goto dispatch;
P_8881b_3:;
goto L_88820;
}
L_88820:{ // MOV dword ptr [ESI + 0x1f0],EAX
c.pc=0x88820;if(!sl_tick(c))return int(c.fault);
P_88820_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f0ULL)),c);
P_88820_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88820_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88820_3:;
goto L_88826;
}
L_88826:{ // MOV EAX,dword ptr [ESI + 0x204]
c.pc=0x88826;if(!sl_tick(c))return int(c.fault);
P_88826_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_88826_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88826_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88826_3:;
goto L_8882c;
}
L_8882c:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x8882c;if(!sl_tick(c))return int(c.fault);
P_8882c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_8882c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_8882c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_8882c_3:;
goto L_88830;
}
L_88830:{ // MOV dword ptr [ESP],ESI
c.pc=0x88830;if(!sl_tick(c))return int(c.fault);
P_88830_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88830_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88830_2:;
goto L_88833;
}
L_88833:{ // CALL 0x00013124
c.pc=0x88833;if(!sl_tick(c))return int(c.fault);
P_88833_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88833_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88838ULL),c);
P_88833_2:;
c.pc=0x13124;goto dispatch;
P_88833_3:;
goto L_88838;
}
L_88838:{ // MOV dword ptr [ESI + 0x1f4],EAX
c.pc=0x88838;if(!sl_tick(c))return int(c.fault);
P_88838_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f4ULL)),c);
P_88838_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88838_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88838_3:;
goto L_8883e;
}
L_8883e:{ // MOV EAX,dword ptr [ESI + 0x204]
c.pc=0x8883e;if(!sl_tick(c))return int(c.fault);
P_8883e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_8883e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_8883e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_8883e_3:;
goto L_88844;
}
L_88844:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x88844;if(!sl_tick(c))return int(c.fault);
P_88844_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_88844_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88844_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88844_3:;
goto L_88848;
}
L_88848:{ // MOV dword ptr [ESP],ESI
c.pc=0x88848;if(!sl_tick(c))return int(c.fault);
P_88848_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88848_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88848_2:;
goto L_8884b;
}
L_8884b:{ // CALL 0x00013124
c.pc=0x8884b;if(!sl_tick(c))return int(c.fault);
P_8884b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_8884b_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88850ULL),c);
P_8884b_2:;
c.pc=0x13124;goto dispatch;
P_8884b_3:;
goto L_88850;
}
L_88850:{ // MOV dword ptr [ESI + 0x1f8],EAX
c.pc=0x88850;if(!sl_tick(c))return int(c.fault);
P_88850_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f8ULL)),c);
P_88850_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88850_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88850_3:;
goto L_88856;
}
L_88856:{ // MOV EAX,dword ptr [ESI + 0x204]
c.pc=0x88856;if(!sl_tick(c))return int(c.fault);
P_88856_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_88856_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88856_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88856_3:;
goto L_8885c;
}
L_8885c:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x8885c;if(!sl_tick(c))return int(c.fault);
P_8885c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_8885c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_8885c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_8885c_3:;
goto L_88860;
}
L_88860:{ // MOV dword ptr [ESP],ESI
c.pc=0x88860;if(!sl_tick(c))return int(c.fault);
P_88860_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88860_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88860_2:;
goto L_88863;
}
L_88863:{ // CALL 0x00013124
c.pc=0x88863;if(!sl_tick(c))return int(c.fault);
P_88863_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88863_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88868ULL),c);
P_88863_2:;
c.pc=0x13124;goto dispatch;
P_88863_3:;
goto L_88868;
}
L_88868:{ // MOV dword ptr [ESI + 0x1fc],EAX
c.pc=0x88868;if(!sl_tick(c))return int(c.fault);
P_88868_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1fcULL)),c);
P_88868_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88868_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88868_3:;
goto L_8886e;
}
L_8886e:{ // MOV EAX,dword ptr [ESI + 0x204]
c.pc=0x8886e;if(!sl_tick(c))return int(c.fault);
P_8886e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_8886e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_8886e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_8886e_3:;
goto L_88874;
}
L_88874:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0x88874;if(!sl_tick(c))return int(c.fault);
P_88874_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_88874_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88874_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88874_3:;
goto L_88878;
}
L_88878:{ // MOV dword ptr [ESP],ESI
c.pc=0x88878;if(!sl_tick(c))return int(c.fault);
P_88878_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88878_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88878_2:;
goto L_8887b;
}
L_8887b:{ // CALL 0x00013124
c.pc=0x8887b;if(!sl_tick(c))return int(c.fault);
P_8887b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_8887b_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88880ULL),c);
P_8887b_2:;
c.pc=0x13124;goto dispatch;
P_8887b_3:;
goto L_88880;
}
L_88880:{ // MOV dword ptr [ESI + 0x200],EAX
c.pc=0x88880;if(!sl_tick(c))return int(c.fault);
P_88880_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x200ULL)),c);
P_88880_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88880_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88880_3:;
goto L_88886;
}
L_88886:{ // MOV EDX,dword ptr [ESI + 0x1ec]
c.pc=0x88886;if(!sl_tick(c))return int(c.fault);
P_88886_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ecULL)),c);
P_88886_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88886_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88886_3:;
goto L_8888c;
}
L_8888c:{ // TEST EDX,EDX
c.pc=0x8888c;if(!sl_tick(c))return int(c.fault);
P_8888c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_8888c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_8888c_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_8888c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_8888c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_8888c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_8888c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_8888c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_8888c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_8888c_9:;
goto L_8888e;
}
L_8888e:{ // JZ 0x00088996
c.pc=0x8888e;if(!sl_tick(c))return int(c.fault);
P_8888e_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88996;}
P_8888e_1:;
goto L_88894;
}
L_88894:{ // MOV ECX,dword ptr [ESI + 0x1f0]
c.pc=0x88894;if(!sl_tick(c))return int(c.fault);
P_88894_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f0ULL)),c);
P_88894_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88894_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88894_3:;
goto L_8889a;
}
L_8889a:{ // TEST ECX,ECX
c.pc=0x8889a;if(!sl_tick(c))return int(c.fault);
P_8889a_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_8889a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_8889a_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_8889a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_8889a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_8889a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_8889a_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_8889a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_8889a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_8889a_9:;
goto L_8889c;
}
L_8889c:{ // JZ 0x00088996
c.pc=0x8889c;if(!sl_tick(c))return int(c.fault);
P_8889c_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88996;}
P_8889c_1:;
goto L_888a2;
}
L_888a2:{ // MOV EDX,dword ptr [ESI + 0x1f4]
c.pc=0x888a2;if(!sl_tick(c))return int(c.fault);
P_888a2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f4ULL)),c);
P_888a2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_888a2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_888a2_3:;
goto L_888a8;
}
L_888a8:{ // TEST EDX,EDX
c.pc=0x888a8;if(!sl_tick(c))return int(c.fault);
P_888a8_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_888a8_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_888a8_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_888a8_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_888a8_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_888a8_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_888a8_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_888a8_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_888a8_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_888a8_9:;
goto L_888aa;
}
L_888aa:{ // JZ 0x00088996
c.pc=0x888aa;if(!sl_tick(c))return int(c.fault);
P_888aa_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88996;}
P_888aa_1:;
goto L_888b0;
}
L_888b0:{ // MOV ECX,dword ptr [ESI + 0x1f8]
c.pc=0x888b0;if(!sl_tick(c))return int(c.fault);
P_888b0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f8ULL)),c);
P_888b0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_888b0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_888b0_3:;
goto L_888b6;
}
L_888b6:{ // TEST ECX,ECX
c.pc=0x888b6;if(!sl_tick(c))return int(c.fault);
P_888b6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_888b6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_888b6_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_888b6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_888b6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_888b6_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_888b6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_888b6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_888b6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_888b6_9:;
goto L_888b8;
}
L_888b8:{ // JZ 0x00088996
c.pc=0x888b8;if(!sl_tick(c))return int(c.fault);
P_888b8_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88996;}
P_888b8_1:;
goto L_888be;
}
L_888be:{ // MOV EDX,dword ptr [ESI + 0x1fc]
c.pc=0x888be;if(!sl_tick(c))return int(c.fault);
P_888be_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1fcULL)),c);
P_888be_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_888be_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_888be_3:;
goto L_888c4;
}
L_888c4:{ // TEST EDX,EDX
c.pc=0x888c4;if(!sl_tick(c))return int(c.fault);
P_888c4_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_888c4_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_888c4_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_888c4_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_888c4_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_888c4_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_888c4_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_888c4_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_888c4_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_888c4_9:;
goto L_888c6;
}
L_888c6:{ // JZ 0x00088996
c.pc=0x888c6;if(!sl_tick(c))return int(c.fault);
P_888c6_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88996;}
P_888c6_1:;
goto L_888cc;
}
L_888cc:{ // TEST EAX,EAX
c.pc=0x888cc;if(!sl_tick(c))return int(c.fault);
P_888cc_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_888cc_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_888cc_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_888cc_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_888cc_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_888cc_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_888cc_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_888cc_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_888cc_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_888cc_9:;
goto L_888ce;
}
L_888ce:{ // JZ 0x00088996
c.pc=0x888ce;if(!sl_tick(c))return int(c.fault);
P_888ce_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88996;}
P_888ce_1:;
goto L_888d4;
}
L_888d4:{ // MOV EAX,dword ptr [ESI + 0x204]
c.pc=0x888d4;if(!sl_tick(c))return int(c.fault);
P_888d4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_888d4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_888d4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_888d4_3:;
goto L_888da;
}
L_888da:{ // TEST EAX,EAX
c.pc=0x888da;if(!sl_tick(c))return int(c.fault);
P_888da_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_888da_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_888da_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_888da_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_888da_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_888da_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_888da_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_888da_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_888da_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_888da_9:;
goto L_888dc;
}
L_888dc:{ // JLE 0x00088947
c.pc=0x888dc;if(!sl_tick(c))return int(c.fault);
P_888dc_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_888dc_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_888dc_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_88947;}
P_888dc_3:;
goto L_888de;
}
L_888de:{ // MOVSS XMM0,dword ptr [EBX + 0x404ab]
c.pc=0x888de;if(!sl_tick(c))return int(c.fault);
P_888de_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x404abULL)),c);
P_888de_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_888de_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_888de_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,SlU(0x0ULL),c);
P_888de_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_888de_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,SlU(0x0ULL),c);
P_888de_6:;
goto L_888e6;
}
L_888e6:{ // XOR ECX,ECX
c.pc=0x888e6;if(!sl_tick(c))return int(c.fault);
P_888e6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_888e6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_888e6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_888e6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x4,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_888e6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) == SlU(0x0ULL)),c);
P_888e6_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & SlU(0xffULL)),c);
P_888e6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_888e6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_888e6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_888e6_9:;
goto L_888e8;
}
L_888e8:{ // MOVSS XMM1,dword ptr [EBX + 0x5969f]
c.pc=0x888e8;if(!sl_tick(c))return int(c.fault);
P_888e8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x5969fULL)),c);
P_888e8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_888e8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_888e8_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_888e8_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_888e8_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_888e8_6:;
goto L_888f0;
}
L_888f0:{ // LEA EDX,[ECX*0x4 + 0x0]
c.pc=0x888f0;if(!sl_tick(c))return int(c.fault);
P_888f0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3600,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) * SlU(0x4ULL)),c);
P_888f0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3700,(SlU(0x0ULL) + sl_get<4>(c.temp,sizeof(c.temp),0x3600,c)),c);
P_888f0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x3700,c),c);
P_888f0_3:;
goto L_888f7;
}
L_888f7:{ // MOV EAX,dword ptr [ESI + 0x1ec]
c.pc=0x888f7;if(!sl_tick(c))return int(c.fault);
P_888f7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ecULL)),c);
P_888f7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_888f7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_888f7_3:;
goto L_888fd;
}
L_888fd:{ // MOVSS dword ptr [EAX + EDX*0x1],XMM0
c.pc=0x888fd;if(!sl_tick(c))return int(c.fault);
P_888fd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x1ULL)),c);
P_888fd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_888fd_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_888fd_3:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_888fd_4:;
goto L_88902;
}
L_88902:{ // MOV EAX,dword ptr [ESI + 0x1f0]
c.pc=0x88902;if(!sl_tick(c))return int(c.fault);
P_88902_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f0ULL)),c);
P_88902_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88902_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88902_3:;
goto L_88908;
}
L_88908:{ // MOVSS dword ptr [EAX + EDX*0x1],XMM0
c.pc=0x88908;if(!sl_tick(c))return int(c.fault);
P_88908_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x1ULL)),c);
P_88908_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_88908_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_88908_3:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88908_4:;
goto L_8890d;
}
L_8890d:{ // MOV EAX,dword ptr [ESI + 0x1f4]
c.pc=0x8890d;if(!sl_tick(c))return int(c.fault);
P_8890d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f4ULL)),c);
P_8890d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_8890d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_8890d_3:;
goto L_88913;
}
L_88913:{ // MOVSS dword ptr [EAX + EDX*0x1],XMM0
c.pc=0x88913;if(!sl_tick(c))return int(c.fault);
P_88913_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x1ULL)),c);
P_88913_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_88913_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_88913_3:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88913_4:;
goto L_88918;
}
L_88918:{ // MOV EAX,dword ptr [ESI + 0x1f8]
c.pc=0x88918;if(!sl_tick(c))return int(c.fault);
P_88918_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f8ULL)),c);
P_88918_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88918_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88918_3:;
goto L_8891e;
}
L_8891e:{ // MOVSS dword ptr [EAX + EDX*0x1],XMM0
c.pc=0x8891e;if(!sl_tick(c))return int(c.fault);
P_8891e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x1ULL)),c);
P_8891e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_8891e_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_8891e_3:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_8891e_4:;
goto L_88923;
}
L_88923:{ // MOV EAX,dword ptr [ESI + 0x1fc]
c.pc=0x88923;if(!sl_tick(c))return int(c.fault);
P_88923_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1fcULL)),c);
P_88923_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88923_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88923_3:;
goto L_88929;
}
L_88929:{ // MOVSS dword ptr [EAX + EDX*0x1],XMM0
c.pc=0x88929;if(!sl_tick(c))return int(c.fault);
P_88929_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x1ULL)),c);
P_88929_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_88929_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_88929_3:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88929_4:;
goto L_8892e;
}
L_8892e:{ // MOV EAX,dword ptr [ESI + 0x200]
c.pc=0x8892e;if(!sl_tick(c))return int(c.fault);
P_8892e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x200ULL)),c);
P_8892e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_8892e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_8892e_3:;
goto L_88934;
}
L_88934:{ // MOVSS dword ptr [EDX + EAX*0x1],XMM0
c.pc=0x88934;if(!sl_tick(c))return int(c.fault);
P_88934_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x1ULL)),c);
P_88934_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_88934_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_88934_3:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88934_4:;
goto L_88939;
}
L_88939:{ // XORPS XMM0,XMM1
c.pc=0x88939;if(!sl_tick(c))return int(c.fault);
P_88939_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)),c);
P_88939_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,(sl_get<4>(c.reg,sizeof(c.reg),0x1204,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x1244,c)),c);
P_88939_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,(sl_get<4>(c.reg,sizeof(c.reg),0x1208,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x1248,c)),c);
P_88939_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,(sl_get<4>(c.reg,sizeof(c.reg),0x120c,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x124c,c)),c);
P_88939_4:;
goto L_8893c;
}
L_8893c:{ // ADD ECX,0x1
c.pc=0x8893c;if(!sl_tick(c))return int(c.fault);
P_8893c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x4,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_8893c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x4,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_8893c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x1ULL)),c);
P_8893c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x4,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_8893c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) == SlU(0x0ULL)),c);
P_8893c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & SlU(0xffULL)),c);
P_8893c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_8893c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_8893c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_8893c_9:;
goto L_8893f;
}
L_8893f:{ // CMP dword ptr [ESI + 0x204],ECX
c.pc=0x8893f;if(!sl_tick(c))return int(c.fault);
P_8893f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_8893f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_8893f_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_8893f_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_8893f_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x4,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x4,c)))&(SlU(1)<<31))!=0),c);
P_8893f_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_8893f_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_8893f_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_8893f_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_8893f_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_8893f_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_8893f_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_8893f_12:;
goto L_88945;
}
L_88945:{ // JG 0x000888f0
c.pc=0x88945;if(!sl_tick(c))return int(c.fault);
P_88945_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_88945_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88945_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_88945_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_888f0;}
P_88945_4:;
goto L_88947;
}
L_88947:{ // MOV dword ptr [ESI + 0x1e0],0x0
c.pc=0x88947;if(!sl_tick(c))return int(c.fault);
P_88947_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1e0ULL)),c);
P_88947_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_88947_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_88947_3:;
goto L_88951;
}
L_88951:{ // MOV dword ptr [ESI + 0x1e4],0x0
c.pc=0x88951;if(!sl_tick(c))return int(c.fault);
P_88951_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1e4ULL)),c);
P_88951_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_88951_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_88951_3:;
goto L_8895b;
}
L_8895b:{ // MOV dword ptr [ESI + 0x1e8],0x0
c.pc=0x8895b;if(!sl_tick(c))return int(c.fault);
P_8895b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1e8ULL)),c);
P_8895b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_8895b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_8895b_3:;
goto L_88965;
}
L_88965:{ // MOV dword ptr [ESI + 0x218],0x0
c.pc=0x88965;if(!sl_tick(c))return int(c.fault);
P_88965_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x218ULL)),c);
P_88965_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_88965_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_88965_3:;
goto L_8896f;
}
L_8896f:{ // MOV dword ptr [ESI + 0x21c],0x0
c.pc=0x8896f;if(!sl_tick(c))return int(c.fault);
P_8896f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x21cULL)),c);
P_8896f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_8896f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_8896f_3:;
goto L_88979;
}
L_88979:{ // MOV dword ptr [ESI + 0x220],0x0
c.pc=0x88979;if(!sl_tick(c))return int(c.fault);
P_88979_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x220ULL)),c);
P_88979_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_88979_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_88979_3:;
goto L_88983;
}
L_88983:{ // MOV EAX,dword ptr [ESI]
c.pc=0x88983;if(!sl_tick(c))return int(c.fault);
P_88983_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_88983_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88983_2:;
goto L_88985;
}
L_88985:{ // MOV dword ptr [EBP + 0x8],ESI
c.pc=0x88985;if(!sl_tick(c))return int(c.fault);
P_88985_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_88985_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88985_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88985_3:;
goto L_88988;
}
L_88988:{ // MOV ECX,dword ptr [EAX + 0xd8]
c.pc=0x88988;if(!sl_tick(c))return int(c.fault);
P_88988_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xd8ULL)),c);
P_88988_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88988_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88988_3:;
goto L_8898e;
}
L_8898e:{ // ADD ESP,0x10
c.pc=0x8898e;if(!sl_tick(c))return int(c.fault);
P_8898e_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_8898e_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_8898e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_8898e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_8898e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_8898e_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_8898e_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_8898e_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_8898e_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_8898e_9:;
goto L_88991;
}
L_88991:{ // POP EBX
c.pc=0x88991;if(!sl_tick(c))return int(c.fault);
P_88991_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88991_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88991_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88991_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88991_4:;
goto L_88992;
}
L_88992:{ // POP ESI
c.pc=0x88992;if(!sl_tick(c))return int(c.fault);
P_88992_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88992_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88992_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88992_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88992_4:;
goto L_88993;
}
L_88993:{ // POP EBP
c.pc=0x88993;if(!sl_tick(c))return int(c.fault);
P_88993_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88993_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88993_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88993_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88993_4:;
goto L_88994;
}
L_88994:{ // JMP ECX
c.pc=0x88994;if(!sl_tick(c))return int(c.fault);
P_88994_0:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x4,c));goto dispatch;
P_88994_1:;
goto L_88996;
}
L_88996:{ // ADD ESP,0x10
c.pc=0x88996;if(!sl_tick(c))return int(c.fault);
P_88996_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_88996_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_88996_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_88996_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88996_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_88996_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_88996_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88996_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88996_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88996_9:;
goto L_88999;
}
L_88999:{ // POP EBX
c.pc=0x88999;if(!sl_tick(c))return int(c.fault);
P_88999_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88999_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88999_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88999_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88999_4:;
goto L_8899a;
}
L_8899a:{ // POP ESI
c.pc=0x8899a;if(!sl_tick(c))return int(c.fault);
P_8899a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_8899a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_8899a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_8899a_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_8899a_4:;
goto L_8899b;
}
L_8899b:{ // POP EBP
c.pc=0x8899b;if(!sl_tick(c))return int(c.fault);
P_8899b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_8899b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_8899b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_8899b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_8899b_4:;
goto L_8899c;
}
L_8899c:{ // RET
c.pc=0x8899c;if(!sl_tick(c))return int(c.fault);
P_8899c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_8899c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_8899c_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_8899c_3:;
c.pc=0x8899d;goto dispatch;
}
L_8899e:{ // PUSH EBP
c.pc=0x8899e;if(!sl_tick(c))return int(c.fault);
P_8899e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_8899e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_8899e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_8899e_3:;
goto L_8899f;
}
L_8899f:{ // MOV EBP,ESP
c.pc=0x8899f;if(!sl_tick(c))return int(c.fault);
P_8899f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_8899f_1:;
goto L_889a1;
}
L_889a1:{ // PUSH EDI
c.pc=0x889a1;if(!sl_tick(c))return int(c.fault);
P_889a1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_889a1_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_889a1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_889a1_3:;
goto L_889a2;
}
L_889a2:{ // PUSH ESI
c.pc=0x889a2;if(!sl_tick(c))return int(c.fault);
P_889a2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_889a2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_889a2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_889a2_3:;
goto L_889a3;
}
L_889a3:{ // SUB ESP,0x20
c.pc=0x889a3;if(!sl_tick(c))return int(c.fault);
P_889a3_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x20ULL)),c);
P_889a3_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x20ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_889a3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x20ULL)),c);
P_889a3_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_889a3_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_889a3_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_889a3_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_889a3_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_889a3_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_889a3_9:;
goto L_889a6;
}
L_889a6:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0x889a6;if(!sl_tick(c))return int(c.fault);
P_889a6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_889a6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_889a6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_889a6_3:;
goto L_889a9;
}
L_889a9:{ // MOV EDI,dword ptr [EBP + 0xc]
c.pc=0x889a9;if(!sl_tick(c))return int(c.fault);
P_889a9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_889a9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_889a9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_889a9_3:;
goto L_889ac;
}
L_889ac:{ // MOVSS XMM0,dword ptr [ESI + 0x140]
c.pc=0x889ac;if(!sl_tick(c))return int(c.fault);
P_889ac_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x140ULL)),c);
P_889ac_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_889ac_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_889ac_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,SlU(0x0ULL),c);
P_889ac_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_889ac_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,SlU(0x0ULL),c);
P_889ac_6:;
goto L_889b4;
}
L_889b4:{ // MOVSS dword ptr [EBP + -0xc],XMM0
c.pc=0x889b4;if(!sl_tick(c))return int(c.fault);
P_889b4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_889b4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_889b4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_889b4_3:;
goto L_889b9;
}
L_889b9:{ // MOV dword ptr [ESI + 0x140],EDI
c.pc=0x889b9;if(!sl_tick(c))return int(c.fault);
P_889b9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x140ULL)),c);
P_889b9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_889b9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_889b9_3:;
goto L_889bf;
}
L_889bf:{ // MOV dword ptr [ESP],ESI
c.pc=0x889bf;if(!sl_tick(c))return int(c.fault);
P_889bf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_889bf_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_889bf_2:;
goto L_889c2;
}
L_889c2:{ // CALL 0x00088724
c.pc=0x889c2;if(!sl_tick(c))return int(c.fault);
P_889c2_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_889c2_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x889c7ULL),c);
P_889c2_2:;
goto L_88724;
P_889c2_3:;
goto L_889c7;
}
L_889c7:{ // MOVSS XMM0,dword ptr [EBP + -0xc]
c.pc=0x889c7;if(!sl_tick(c))return int(c.fault);
P_889c7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_889c7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_889c7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_889c7_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,SlU(0x0ULL),c);
P_889c7_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_889c7_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,SlU(0x0ULL),c);
P_889c7_6:;
goto L_889cc;
}
L_889cc:{ // MOVSS dword ptr [ESI + 0x140],XMM0
c.pc=0x889cc;if(!sl_tick(c))return int(c.fault);
P_889cc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x140ULL)),c);
P_889cc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_889cc_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_889cc_3:;
goto L_889d4;
}
L_889d4:{ // MOV dword ptr [EBP + 0xc],EDI
c.pc=0x889d4;if(!sl_tick(c))return int(c.fault);
P_889d4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_889d4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_889d4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_889d4_3:;
goto L_889d7;
}
L_889d7:{ // MOV dword ptr [EBP + 0x8],ESI
c.pc=0x889d7;if(!sl_tick(c))return int(c.fault);
P_889d7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_889d7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_889d7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_889d7_3:;
goto L_889da;
}
L_889da:{ // ADD ESP,0x20
c.pc=0x889da;if(!sl_tick(c))return int(c.fault);
P_889da_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_889da_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(0x20ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x20ULL)))&(SlU(1)<<31))!=0),c);
P_889da_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x20ULL)),c);
P_889da_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_889da_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_889da_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_889da_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_889da_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_889da_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_889da_9:;
goto L_889dd;
}
L_889dd:{ // POP ESI
c.pc=0x889dd;if(!sl_tick(c))return int(c.fault);
P_889dd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_889dd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_889dd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_889dd_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_889dd_4:;
goto L_889de;
}
L_889de:{ // POP EDI
c.pc=0x889de;if(!sl_tick(c))return int(c.fault);
P_889de_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_889de_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_889de_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_889de_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_889de_4:;
goto L_889df;
}
L_889df:{ // POP EBP
c.pc=0x889df;if(!sl_tick(c))return int(c.fault);
P_889df_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_889df_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_889df_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_889df_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_889df_4:;
goto L_889e0;
}
L_889e0:{ // JMP 0x000128a6
c.pc=0x889e0;if(!sl_tick(c))return int(c.fault);
P_889e0_0:;
c.pc=0x128a6;goto dispatch;
P_889e0_1:;
c.pc=0x889e5;goto dispatch;
}
L_889e6:{ // PUSH EBP
c.pc=0x889e6;if(!sl_tick(c))return int(c.fault);
P_889e6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_889e6_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_889e6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_889e6_3:;
goto L_889e7;
}
L_889e7:{ // MOV EBP,ESP
c.pc=0x889e7;if(!sl_tick(c))return int(c.fault);
P_889e7_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_889e7_1:;
goto L_889e9;
}
L_889e9:{ // PUSH ESI
c.pc=0x889e9;if(!sl_tick(c))return int(c.fault);
P_889e9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_889e9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_889e9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_889e9_3:;
goto L_889ea;
}
L_889ea:{ // PUSH EBX
c.pc=0x889ea;if(!sl_tick(c))return int(c.fault);
P_889ea_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_889ea_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_889ea_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_889ea_3:;
goto L_889eb;
}
L_889eb:{ // CALL 0x000c086c
c.pc=0x889eb;if(!sl_tick(c))return int(c.fault);
P_889eb_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_889eb_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x889f0ULL),c);
P_889eb_2:;
c.pc=0xc086c;goto dispatch;
P_889eb_3:;
goto L_889f0;
}
L_889f0:{ // MOV ECX,dword ptr [EBP + 0x8]
c.pc=0x889f0;if(!sl_tick(c))return int(c.fault);
P_889f0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_889f0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_889f0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_889f0_3:;
goto L_889f3;
}
L_889f3:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0x889f3;if(!sl_tick(c))return int(c.fault);
P_889f3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_889f3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_889f3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_889f3_3:;
goto L_889f6;
}
L_889f6:{ // CMP byte ptr [EAX + ECX*0x1 + 0x1b4],0x0
c.pc=0x889f6;if(!sl_tick(c))return int(c.fault);
P_889f6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3c80,(SlU(0x1b4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_889f6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3d00,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) * SlU(0x1ULL)),c);
P_889f6_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x3e00,(sl_get<4>(c.temp,sizeof(c.temp),0x3c80,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3d00,c)),c);
P_889f6_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3e00,c)),c),c);
P_889f6_4:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_889f6_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_889f6_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_889f6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_889f6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_889f6_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_889f6_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_889f6_11:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_889f6_12:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_889f6_13:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_889f6_14:;
goto L_889fe;
}
L_889fe:{ // JZ 0x00088a08
c.pc=0x889fe;if(!sl_tick(c))return int(c.fault);
P_889fe_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88a08;}
P_889fe_1:;
goto L_88a00;
}
L_88a00:{ // CMP EAX,dword ptr [ECX + 0x128]
c.pc=0x88a00;if(!sl_tick(c))return int(c.fault);
P_88a00_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x128ULL)),c);
P_88a00_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88a00_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88a00_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_88a00_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_88a00_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_88a00_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88a00_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_88a00_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_88a00_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88a00_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88a00_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88a00_12:;
goto L_88a06;
}
L_88a06:{ // JZ 0x00088a0c
c.pc=0x88a06;if(!sl_tick(c))return int(c.fault);
P_88a06_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88a0c;}
P_88a06_1:;
goto L_88a08;
}
L_88a08:{ // POP EBX
c.pc=0x88a08;if(!sl_tick(c))return int(c.fault);
P_88a08_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88a08_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88a08_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88a08_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88a08_4:;
goto L_88a09;
}
L_88a09:{ // POP ESI
c.pc=0x88a09;if(!sl_tick(c))return int(c.fault);
P_88a09_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88a09_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88a09_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88a09_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88a09_4:;
goto L_88a0a;
}
L_88a0a:{ // POP EBP
c.pc=0x88a0a;if(!sl_tick(c))return int(c.fault);
P_88a0a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88a0a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88a0a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88a0a_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88a0a_4:;
goto L_88a0b;
}
L_88a0b:{ // RET
c.pc=0x88a0b;if(!sl_tick(c))return int(c.fault);
P_88a0b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88a0b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88a0b_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_88a0b_3:;
goto L_88a0c;
}
L_88a0c:{ // CMP byte ptr [ECX + 0x15c],0x0
c.pc=0x88a0c;if(!sl_tick(c))return int(c.fault);
P_88a0c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x15cULL)),c);
P_88a0c_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88a0c_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_88a0c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_88a0c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_88a0c_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_88a0c_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_88a0c_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_88a0c_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_88a0c_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88a0c_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88a0c_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88a0c_12:;
goto L_88a13;
}
L_88a13:{ // JZ 0x00088a08
c.pc=0x88a13;if(!sl_tick(c))return int(c.fault);
P_88a13_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88a08;}
P_88a13_1:;
goto L_88a15;
}
L_88a15:{ // MOV ESI,dword ptr [ECX + 0x204]
c.pc=0x88a15;if(!sl_tick(c))return int(c.fault);
P_88a15_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x204ULL)),c);
P_88a15_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88a15_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88a15_3:;
goto L_88a1b;
}
L_88a1b:{ // TEST ESI,ESI
c.pc=0x88a1b;if(!sl_tick(c))return int(c.fault);
P_88a1b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88a1b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88a1b_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_88a1b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88a1b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_88a1b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_88a1b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88a1b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88a1b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88a1b_9:;
goto L_88a1d;
}
L_88a1d:{ // JLE 0x00088a08
c.pc=0x88a1d;if(!sl_tick(c))return int(c.fault);
P_88a1d_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88a1d_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_88a1d_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_88a08;}
P_88a1d_3:;
goto L_88a1f;
}
L_88a1f:{ // MOVSS XMM0,dword ptr [EBX + 0x401ec]
c.pc=0x88a1f;if(!sl_tick(c))return int(c.fault);
P_88a1f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x401ecULL)),c);
P_88a1f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88a1f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88a1f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,SlU(0x0ULL),c);
P_88a1f_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_88a1f_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,SlU(0x0ULL),c);
P_88a1f_6:;
goto L_88a27;
}
L_88a27:{ // XOR ESI,ESI
c.pc=0x88a27;if(!sl_tick(c))return int(c.fault);
P_88a27_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88a27_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88a27_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_88a27_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88a27_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_88a27_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_88a27_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88a27_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88a27_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88a27_9:;
goto L_88a29;
}
L_88a29:{ // MOVSS XMM1,dword ptr [EBX + 0x593f0]
c.pc=0x88a29;if(!sl_tick(c))return int(c.fault);
P_88a29_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x593f0ULL)),c);
P_88a29_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88a29_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88a29_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_88a29_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_88a29_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_88a29_6:;
goto L_88a31;
}
L_88a31:{ // LEA EDX,[ESI*0x4 + 0x0]
c.pc=0x88a31;if(!sl_tick(c))return int(c.fault);
P_88a31_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3600,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) * SlU(0x4ULL)),c);
P_88a31_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3700,(SlU(0x0ULL) + sl_get<4>(c.temp,sizeof(c.temp),0x3600,c)),c);
P_88a31_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x3700,c),c);
P_88a31_3:;
goto L_88a38;
}
L_88a38:{ // MOV EAX,dword ptr [ECX + 0x1ec]
c.pc=0x88a38;if(!sl_tick(c))return int(c.fault);
P_88a38_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x1ecULL)),c);
P_88a38_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88a38_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88a38_3:;
goto L_88a3e;
}
L_88a3e:{ // MOVSS dword ptr [EAX + EDX*0x1],XMM0
c.pc=0x88a3e;if(!sl_tick(c))return int(c.fault);
P_88a3e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x1ULL)),c);
P_88a3e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_88a3e_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_88a3e_3:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88a3e_4:;
goto L_88a43;
}
L_88a43:{ // MOV EAX,dword ptr [ECX + 0x1f0]
c.pc=0x88a43;if(!sl_tick(c))return int(c.fault);
P_88a43_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x1f0ULL)),c);
P_88a43_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88a43_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88a43_3:;
goto L_88a49;
}
L_88a49:{ // MOVSS dword ptr [EAX + EDX*0x1],XMM0
c.pc=0x88a49;if(!sl_tick(c))return int(c.fault);
P_88a49_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x1ULL)),c);
P_88a49_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_88a49_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_88a49_3:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88a49_4:;
goto L_88a4e;
}
L_88a4e:{ // MOV EAX,dword ptr [ECX + 0x1f4]
c.pc=0x88a4e;if(!sl_tick(c))return int(c.fault);
P_88a4e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x1f4ULL)),c);
P_88a4e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88a4e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88a4e_3:;
goto L_88a54;
}
L_88a54:{ // MOVSS dword ptr [EAX + EDX*0x1],XMM0
c.pc=0x88a54;if(!sl_tick(c))return int(c.fault);
P_88a54_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x1ULL)),c);
P_88a54_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_88a54_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_88a54_3:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88a54_4:;
goto L_88a59;
}
L_88a59:{ // MOV EAX,dword ptr [ECX + 0x1f8]
c.pc=0x88a59;if(!sl_tick(c))return int(c.fault);
P_88a59_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x1f8ULL)),c);
P_88a59_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88a59_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88a59_3:;
goto L_88a5f;
}
L_88a5f:{ // MOVSS dword ptr [EAX + EDX*0x1],XMM0
c.pc=0x88a5f;if(!sl_tick(c))return int(c.fault);
P_88a5f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x1ULL)),c);
P_88a5f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_88a5f_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_88a5f_3:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88a5f_4:;
goto L_88a64;
}
L_88a64:{ // MOV EAX,dword ptr [ECX + 0x1fc]
c.pc=0x88a64;if(!sl_tick(c))return int(c.fault);
P_88a64_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x1fcULL)),c);
P_88a64_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88a64_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88a64_3:;
goto L_88a6a;
}
L_88a6a:{ // MOVSS dword ptr [EAX + EDX*0x1],XMM0
c.pc=0x88a6a;if(!sl_tick(c))return int(c.fault);
P_88a6a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) * SlU(0x1ULL)),c);
P_88a6a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_88a6a_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_88a6a_3:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88a6a_4:;
goto L_88a6f;
}
L_88a6f:{ // MOV EAX,dword ptr [ECX + 0x200]
c.pc=0x88a6f;if(!sl_tick(c))return int(c.fault);
P_88a6f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x200ULL)),c);
P_88a6f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88a6f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88a6f_3:;
goto L_88a75;
}
L_88a75:{ // MOVSS dword ptr [EDX + EAX*0x1],XMM0
c.pc=0x88a75;if(!sl_tick(c))return int(c.fault);
P_88a75_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x1ULL)),c);
P_88a75_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_88a75_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_88a75_3:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3580,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88a75_4:;
goto L_88a7a;
}
L_88a7a:{ // XORPS XMM0,XMM1
c.pc=0x88a7a;if(!sl_tick(c))return int(c.fault);
P_88a7a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)),c);
P_88a7a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,(sl_get<4>(c.reg,sizeof(c.reg),0x1204,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x1244,c)),c);
P_88a7a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,(sl_get<4>(c.reg,sizeof(c.reg),0x1208,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x1248,c)),c);
P_88a7a_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,(sl_get<4>(c.reg,sizeof(c.reg),0x120c,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x124c,c)),c);
P_88a7a_4:;
goto L_88a7d;
}
L_88a7d:{ // ADD ESI,0x1
c.pc=0x88a7d;if(!sl_tick(c))return int(c.fault);
P_88a7d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_88a7d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(0x1ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)+SlU(0x1ULL)))&(SlU(1)<<31))!=0),c);
P_88a7d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1ULL)),c);
P_88a7d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x18,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88a7d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) == SlU(0x0ULL)),c);
P_88a7d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & SlU(0xffULL)),c);
P_88a7d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88a7d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88a7d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88a7d_9:;
goto L_88a80;
}
L_88a80:{ // CMP dword ptr [ECX + 0x204],ESI
c.pc=0x88a80;if(!sl_tick(c))return int(c.fault);
P_88a80_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x204ULL)),c);
P_88a80_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88a80_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88a80_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_88a80_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x18,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x18,c)))&(SlU(1)<<31))!=0),c);
P_88a80_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_88a80_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88a80_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_88a80_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_88a80_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88a80_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88a80_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88a80_12:;
goto L_88a86;
}
L_88a86:{ // JG 0x00088a31
c.pc=0x88a86;if(!sl_tick(c))return int(c.fault);
P_88a86_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_88a86_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88a86_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_88a86_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_88a31;}
P_88a86_4:;
goto L_88a88;
}
L_88a88:{ // POP EBX
c.pc=0x88a88;if(!sl_tick(c))return int(c.fault);
P_88a88_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88a88_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88a88_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88a88_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88a88_4:;
goto L_88a89;
}
L_88a89:{ // POP ESI
c.pc=0x88a89;if(!sl_tick(c))return int(c.fault);
P_88a89_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88a89_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88a89_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88a89_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88a89_4:;
goto L_88a8a;
}
L_88a8a:{ // POP EBP
c.pc=0x88a8a;if(!sl_tick(c))return int(c.fault);
P_88a8a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88a8a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88a8a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88a8a_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88a8a_4:;
goto L_88a8b;
}
L_88a8b:{ // RET
c.pc=0x88a8b;if(!sl_tick(c))return int(c.fault);
P_88a8b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88a8b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88a8b_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_88a8b_3:;
goto L_88a8c;
}
L_88a8c:{ // PUSH EBP
c.pc=0x88a8c;if(!sl_tick(c))return int(c.fault);
P_88a8c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_88a8c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88a8c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88a8c_3:;
goto L_88a8d;
}
L_88a8d:{ // MOV EBP,ESP
c.pc=0x88a8d;if(!sl_tick(c))return int(c.fault);
P_88a8d_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_88a8d_1:;
goto L_88a8f;
}
L_88a8f:{ // PUSH EDI
c.pc=0x88a8f;if(!sl_tick(c))return int(c.fault);
P_88a8f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_88a8f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88a8f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88a8f_3:;
goto L_88a90;
}
L_88a90:{ // PUSH ESI
c.pc=0x88a90;if(!sl_tick(c))return int(c.fault);
P_88a90_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88a90_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88a90_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88a90_3:;
goto L_88a91;
}
L_88a91:{ // PUSH EBX
c.pc=0x88a91;if(!sl_tick(c))return int(c.fault);
P_88a91_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_88a91_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88a91_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88a91_3:;
goto L_88a92;
}
L_88a92:{ // SUB ESP,0x2c
c.pc=0x88a92;if(!sl_tick(c))return int(c.fault);
P_88a92_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x2cULL)),c);
P_88a92_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x2cULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x2cULL)))&(SlU(1)<<31))!=0),c);
P_88a92_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x2cULL)),c);
P_88a92_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88a92_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_88a92_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_88a92_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88a92_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88a92_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88a92_9:;
goto L_88a95;
}
L_88a95:{ // CALL 0x000c086c
c.pc=0x88a95;if(!sl_tick(c))return int(c.fault);
P_88a95_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88a95_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88a9aULL),c);
P_88a95_2:;
c.pc=0xc086c;goto dispatch;
P_88a95_3:;
goto L_88a9a;
}
L_88a9a:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0x88a9a;if(!sl_tick(c))return int(c.fault);
P_88a9a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_88a9a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88a9a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88a9a_3:;
goto L_88a9d;
}
L_88a9d:{ // CMP byte ptr [ESI + 0x15c],0x0
c.pc=0x88a9d;if(!sl_tick(c))return int(c.fault);
P_88a9d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x15cULL)),c);
P_88a9d_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88a9d_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_88a9d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_88a9d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_88a9d_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_88a9d_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_88a9d_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_88a9d_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_88a9d_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88a9d_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88a9d_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88a9d_12:;
goto L_88aa4;
}
L_88aa4:{ // JZ 0x00088d1a
c.pc=0x88aa4;if(!sl_tick(c))return int(c.fault);
P_88aa4_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88d1a;}
P_88aa4_1:;
goto L_88aaa;
}
L_88aaa:{ // MOV ECX,dword ptr [ESI + 0x124]
c.pc=0x88aaa;if(!sl_tick(c))return int(c.fault);
P_88aaa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x124ULL)),c);
P_88aaa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88aaa_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88aaa_3:;
goto L_88ab0;
}
L_88ab0:{ // TEST ECX,ECX
c.pc=0x88ab0;if(!sl_tick(c))return int(c.fault);
P_88ab0_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88ab0_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88ab0_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_88ab0_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88ab0_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_88ab0_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_88ab0_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88ab0_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88ab0_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88ab0_9:;
goto L_88ab2;
}
L_88ab2:{ // JZ 0x00088d1a
c.pc=0x88ab2;if(!sl_tick(c))return int(c.fault);
P_88ab2_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88d1a;}
P_88ab2_1:;
goto L_88ab8;
}
L_88ab8:{ // CMP dword ptr [ESI + 0x204],0x10
c.pc=0x88ab8;if(!sl_tick(c))return int(c.fault);
P_88ab8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_88ab8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88ab8_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_88ab8_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x10ULL)),c);
P_88ab8_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x10ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_88ab8_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x10ULL)),c);
P_88ab8_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88ab8_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_88ab8_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_88ab8_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88ab8_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88ab8_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88ab8_12:;
goto L_88abf;
}
L_88abf:{ // JG 0x00088d22
c.pc=0x88abf;if(!sl_tick(c))return int(c.fault);
P_88abf_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_88abf_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88abf_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_88abf_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_88d22;}
P_88abf_4:;
goto L_88ac5;
}
L_88ac5:{ // PXOR XMM1,XMM1
c.pc=0x88ac5;if(!sl_tick(c))return int(c.fault);
P_88ac5_0:;
sl_put<16>(c.reg,sizeof(c.reg),0x1240,(sl_get<16>(c.reg,sizeof(c.reg),0x1240,c) ^ sl_get<16>(c.reg,sizeof(c.reg),0x1240,c)),c);
P_88ac5_1:;
goto L_88ac9;
}
L_88ac9:{ // MOV EDI,dword ptr [ESI + 0x204]
c.pc=0x88ac9;if(!sl_tick(c))return int(c.fault);
P_88ac9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_88ac9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88ac9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88ac9_3:;
goto L_88acf;
}
L_88acf:{ // MOVSS XMM4,dword ptr [EBX + 0x3ff92]
c.pc=0x88acf;if(!sl_tick(c))return int(c.fault);
P_88acf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x3ff92ULL)),c);
P_88acf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88acf_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1300,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88acf_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1304,SlU(0x0ULL),c);
P_88acf_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1308,SlU(0x0ULL),c);
P_88acf_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x130c,SlU(0x0ULL),c);
P_88acf_6:;
goto L_88ad7;
}
L_88ad7:{ // MULSS XMM1,dword ptr [ESI + 0x140]
c.pc=0x88ad7;if(!sl_tick(c))return int(c.fault);
P_88ad7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x140ULL)),c);
P_88ad7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88ad7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_88ad7_3:;
goto L_88adf;
}
L_88adf:{ // ADDSS XMM1,XMM4
c.pc=0x88adf;if(!sl_tick(c))return int(c.fault);
P_88adf_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1300,c))),c);
P_88adf_1:;
goto L_88ae3;
}
L_88ae3:{ // CVTTSS2SI EDX,XMM1
c.pc=0x88ae3;if(!sl_tick(c))return int(c.fault);
P_88ae3_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_trunc_fp(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),4,32),c);
P_88ae3_1:;
goto L_88ae7;
}
L_88ae7:{ // MOV EAX,0x1
c.pc=0x88ae7;if(!sl_tick(c))return int(c.fault);
P_88ae7_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,SlU(0x1ULL),c);
P_88ae7_1:;
goto L_88aec;
}
L_88aec:{ // TEST EDX,EDX
c.pc=0x88aec;if(!sl_tick(c))return int(c.fault);
P_88aec_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88aec_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88aec_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_88aec_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88aec_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_88aec_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_88aec_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88aec_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88aec_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88aec_9:;
goto L_88aee;
}
L_88aee:{ // CMOVG EAX,EDX
c.pc=0x88aee;if(!sl_tick(c))return int(c.fault);
P_88aee_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_88aee_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88aee_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_88aee_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30380,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_88aee_4:;
sl_put<1>(c.temp,sizeof(c.temp),0x30400,(!sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)),c);
P_88aee_5:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x30400,c)){goto L_88af1;}
P_88aee_6:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x30380,c),c);
P_88aee_7:;
goto L_88af1;
}
L_88af1:{ // MOV dword ptr [ESI + 0x218],EAX
c.pc=0x88af1;if(!sl_tick(c))return int(c.fault);
P_88af1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x218ULL)),c);
P_88af1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88af1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88af1_3:;
goto L_88af7;
}
L_88af7:{ // LEA EAX,[EDI + -0x1]
c.pc=0x88af7;if(!sl_tick(c))return int(c.fault);
P_88af7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xffffffffULL)),c);
P_88af7_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_88af7_2:;
goto L_88afa;
}
L_88afa:{ // CMP dword ptr [ESI + 0x218],EAX
c.pc=0x88afa;if(!sl_tick(c))return int(c.fault);
P_88afa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x218ULL)),c);
P_88afa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88afa_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88afa_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_88afa_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x0,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x0,c)))&(SlU(1)<<31))!=0),c);
P_88afa_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_88afa_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88afa_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_88afa_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_88afa_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88afa_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88afa_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88afa_12:;
goto L_88b00;
}
L_88b00:{ // JLE 0x00088b08
c.pc=0x88b00;if(!sl_tick(c))return int(c.fault);
P_88b00_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88b00_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_88b00_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_88b08;}
P_88b00_3:;
goto L_88b02;
}
L_88b02:{ // MOV dword ptr [ESI + 0x218],EAX
c.pc=0x88b02;if(!sl_tick(c))return int(c.fault);
P_88b02_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x218ULL)),c);
P_88b02_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88b02_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88b02_3:;
goto L_88b08;
}
L_88b08:{ // TEST ECX,ECX
c.pc=0x88b08;if(!sl_tick(c))return int(c.fault);
P_88b08_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88b08_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88b08_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_88b08_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88b08_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_88b08_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_88b08_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88b08_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88b08_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88b08_9:;
goto L_88b0a;
}
L_88b0a:{ // JZ 0x00088dba
c.pc=0x88b0a;if(!sl_tick(c))return int(c.fault);
P_88b0a_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88dba;}
P_88b0a_1:;
goto L_88b10;
}
L_88b10:{ // CMP dword ptr [ESI + 0x204],0x10
c.pc=0x88b10;if(!sl_tick(c))return int(c.fault);
P_88b10_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_88b10_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88b10_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_88b10_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x10ULL)),c);
P_88b10_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x10ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_88b10_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x10ULL)),c);
P_88b10_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88b10_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_88b10_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_88b10_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88b10_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88b10_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88b10_12:;
goto L_88b17;
}
L_88b17:{ // JLE 0x00088dba
c.pc=0x88b17;if(!sl_tick(c))return int(c.fault);
P_88b17_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88b17_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_88b17_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_88dba;}
P_88b17_3:;
goto L_88b1d;
}
L_88b1d:{ // MOVSS XMM1,dword ptr [EBX + 0x3ffca]
c.pc=0x88b1d;if(!sl_tick(c))return int(c.fault);
P_88b1d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x3ffcaULL)),c);
P_88b1d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88b1d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88b1d_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_88b1d_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_88b1d_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_88b1d_6:;
goto L_88b25;
}
L_88b25:{ // MULSS XMM1,dword ptr [ECX + 0x15c]
c.pc=0x88b25;if(!sl_tick(c))return int(c.fault);
P_88b25_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x15cULL)),c);
P_88b25_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88b25_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_88b25_3:;
goto L_88b2d;
}
L_88b2d:{ // LEA EAX,[ECX + 0x1c0]
c.pc=0x88b2d;if(!sl_tick(c))return int(c.fault);
P_88b2d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x1c0ULL)),c);
P_88b2d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_88b2d_2:;
goto L_88b33;
}
L_88b33:{ // MOV EDX,dword ptr [EAX + 0x8]
c.pc=0x88b33;if(!sl_tick(c))return int(c.fault);
P_88b33_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_88b33_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88b33_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88b33_3:;
goto L_88b36;
}
L_88b36:{ // CMP EDX,dword ptr [EAX + 0x24]
c.pc=0x88b36;if(!sl_tick(c))return int(c.fault);
P_88b36_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x24ULL)),c);
P_88b36_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88b36_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88b36_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_88b36_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_88b36_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_88b36_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88b36_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_88b36_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_88b36_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88b36_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88b36_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88b36_12:;
goto L_88b39;
}
L_88b39:{ // JG 0x00088e15
c.pc=0x88b39;if(!sl_tick(c))return int(c.fault);
P_88b39_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_88b39_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88b39_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_88b39_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_88e15;}
P_88b39_4:;
goto L_88b3f;
}
L_88b3f:{ // MOVSS XMM3,dword ptr [ESI + 0x140]
c.pc=0x88b3f;if(!sl_tick(c))return int(c.fault);
P_88b3f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x140ULL)),c);
P_88b3f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88b3f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c0,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88b3f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c4,SlU(0x0ULL),c);
P_88b3f_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c8,SlU(0x0ULL),c);
P_88b3f_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x12cc,SlU(0x0ULL),c);
P_88b3f_6:;
goto L_88b47;
}
L_88b47:{ // LEA EAX,[EDI + -0x10]
c.pc=0x88b47;if(!sl_tick(c))return int(c.fault);
P_88b47_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xfffffff0ULL)),c);
P_88b47_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_88b47_2:;
goto L_88b4a;
}
L_88b4a:{ // CVTSI2SS XMM2,EAX
c.pc=0x88b4a;if(!sl_tick(c))return int(c.fault);
P_88b4a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1280,sl_bits(static_cast<float>(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32))),c);
P_88b4a_1:;
goto L_88b4e;
}
L_88b4e:{ // MOVAPS XMM0,XMM3
c.pc=0x88b4e;if(!sl_tick(c))return int(c.fault);
P_88b4e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x12c0,c),c);
P_88b4e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x12c4,c),c);
P_88b4e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x12c8,c),c);
P_88b4e_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x12cc,c),c);
P_88b4e_4:;
goto L_88b51;
}
L_88b51:{ // MULSS XMM0,XMM1
c.pc=0x88b51;if(!sl_tick(c))return int(c.fault);
P_88b51_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_88b51_1:;
goto L_88b55;
}
L_88b55:{ // UCOMISS XMM0,XMM2
c.pc=0x88b55;if(!sl_tick(c))return int(c.fault);
P_88b55_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x27f80,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_88b55_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x28000,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88b55_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(bool(sl_get<1>(c.temp,sizeof(c.temp),0x27f80,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0x28000,c))),c);
P_88b55_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x28100,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) == sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88b55_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28100,c)),c);
P_88b55_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x28200,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) < sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88b55_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28200,c)),c);
P_88b55_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88b55_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x204,SlU(0x0ULL),c);
P_88b55_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,SlU(0x0ULL),c);
P_88b55_10:;
goto L_88b58;
}
L_88b58:{ // JNC 0x00088dc3
c.pc=0x88b58;if(!sl_tick(c))return int(c.fault);
P_88b58_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9b00,(!sl_get<1>(c.reg,sizeof(c.reg),0x200,c)),c);
P_88b58_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9b00,c)){goto L_88dc3;}
P_88b58_2:;
goto L_88b5e;
}
L_88b5e:{ // MULSS XMM1,dword ptr [ESI + 0x140]
c.pc=0x88b5e;if(!sl_tick(c))return int(c.fault);
P_88b5e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x140ULL)),c);
P_88b5e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88b5e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_88b5e_3:;
goto L_88b66;
}
L_88b66:{ // ADDSS XMM1,XMM4
c.pc=0x88b66;if(!sl_tick(c))return int(c.fault);
P_88b66_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1300,c))),c);
P_88b66_1:;
goto L_88b6a;
}
L_88b6a:{ // CVTTSS2SI EAX,XMM1
c.pc=0x88b6a;if(!sl_tick(c))return int(c.fault);
P_88b6a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_trunc_fp(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),4,32),c);
P_88b6a_1:;
goto L_88b6e;
}
L_88b6e:{ // MOV dword ptr [ESI + 0x21c],EAX
c.pc=0x88b6e;if(!sl_tick(c))return int(c.fault);
P_88b6e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x21cULL)),c);
P_88b6e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88b6e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88b6e_3:;
goto L_88b74;
}
L_88b74:{ // TEST ECX,ECX
c.pc=0x88b74;if(!sl_tick(c))return int(c.fault);
P_88b74_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88b74_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88b74_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) & sl_get<4>(c.reg,sizeof(c.reg),0x4,c)),c);
P_88b74_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88b74_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_88b74_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_88b74_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88b74_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88b74_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88b74_9:;
goto L_88b76;
}
L_88b76:{ // JZ 0x00088d83
c.pc=0x88b76;if(!sl_tick(c))return int(c.fault);
P_88b76_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88d83;}
P_88b76_1:;
goto L_88b7c;
}
L_88b7c:{ // CMP dword ptr [ESI + 0x204],0x10
c.pc=0x88b7c;if(!sl_tick(c))return int(c.fault);
P_88b7c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_88b7c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9700,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88b7c_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x30d80,sl_get<4>(c.temp,sizeof(c.temp),0x9700,c),c);
P_88b7c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) < SlU(0x10ULL)),c);
P_88b7c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^SlU(0x10ULL))&(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_88b7c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x30e80,(sl_get<4>(c.temp,sizeof(c.temp),0x30d80,c) - SlU(0x10ULL)),c);
P_88b7c_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88b7c_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) == SlU(0x0ULL)),c);
P_88b7c_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x30e80,c) & SlU(0xffULL)),c);
P_88b7c_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88b7c_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88b7c_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88b7c_12:;
goto L_88b83;
}
L_88b83:{ // JLE 0x00088d83
c.pc=0x88b83;if(!sl_tick(c))return int(c.fault);
P_88b83_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88b83_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_88b83_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_88d83;}
P_88b83_3:;
goto L_88b89;
}
L_88b89:{ // MOVSS XMM1,dword ptr [EBX + 0x3ffca]
c.pc=0x88b89;if(!sl_tick(c))return int(c.fault);
P_88b89_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x3ffcaULL)),c);
P_88b89_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88b89_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88b89_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_88b89_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_88b89_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_88b89_6:;
goto L_88b91;
}
L_88b91:{ // MULSS XMM1,dword ptr [ECX + 0x2ac]
c.pc=0x88b91;if(!sl_tick(c))return int(c.fault);
P_88b91_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x2acULL)),c);
P_88b91_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88b91_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_88b91_3:;
goto L_88b99;
}
L_88b99:{ // LEA EAX,[ECX + 0x310]
c.pc=0x88b99;if(!sl_tick(c))return int(c.fault);
P_88b99_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x310ULL)),c);
P_88b99_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_88b99_2:;
goto L_88b9f;
}
L_88b9f:{ // MOV EDX,dword ptr [EAX + 0x8]
c.pc=0x88b9f;if(!sl_tick(c))return int(c.fault);
P_88b9f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_88b9f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88b9f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88b9f_3:;
goto L_88ba2;
}
L_88ba2:{ // CMP EDX,dword ptr [EAX + 0x24]
c.pc=0x88ba2;if(!sl_tick(c))return int(c.fault);
P_88ba2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x24ULL)),c);
P_88ba2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88ba2_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88ba2_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_88ba2_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_88ba2_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_88ba2_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88ba2_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_88ba2_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_88ba2_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88ba2_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88ba2_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88ba2_12:;
goto L_88ba5;
}
L_88ba5:{ // JG 0x00088e42
c.pc=0x88ba5;if(!sl_tick(c))return int(c.fault);
P_88ba5_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_88ba5_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88ba5_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_88ba5_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_88e42;}
P_88ba5_4:;
goto L_88bab;
}
L_88bab:{ // MOVSS XMM3,dword ptr [ESI + 0x140]
c.pc=0x88bab;if(!sl_tick(c))return int(c.fault);
P_88bab_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x140ULL)),c);
P_88bab_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88bab_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c0,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88bab_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c4,SlU(0x0ULL),c);
P_88bab_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c8,SlU(0x0ULL),c);
P_88bab_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x12cc,SlU(0x0ULL),c);
P_88bab_6:;
goto L_88bb3;
}
L_88bb3:{ // LEA EAX,[EDI + -0x10]
c.pc=0x88bb3;if(!sl_tick(c))return int(c.fault);
P_88bb3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xfffffff0ULL)),c);
P_88bb3_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_88bb3_2:;
goto L_88bb6;
}
L_88bb6:{ // CVTSI2SS XMM2,EAX
c.pc=0x88bb6;if(!sl_tick(c))return int(c.fault);
P_88bb6_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1280,sl_bits(static_cast<float>(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32))),c);
P_88bb6_1:;
goto L_88bba;
}
L_88bba:{ // MOVAPS XMM0,XMM3
c.pc=0x88bba;if(!sl_tick(c))return int(c.fault);
P_88bba_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x12c0,c),c);
P_88bba_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x12c4,c),c);
P_88bba_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x12c8,c),c);
P_88bba_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x12cc,c),c);
P_88bba_4:;
goto L_88bbd;
}
L_88bbd:{ // MULSS XMM0,XMM1
c.pc=0x88bbd;if(!sl_tick(c))return int(c.fault);
P_88bbd_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_88bbd_1:;
goto L_88bc1;
}
L_88bc1:{ // UCOMISS XMM0,XMM2
c.pc=0x88bc1;if(!sl_tick(c))return int(c.fault);
P_88bc1_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x27f80,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_88bc1_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x28000,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88bc1_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(bool(sl_get<1>(c.temp,sizeof(c.temp),0x27f80,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0x28000,c))),c);
P_88bc1_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x28100,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) == sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88bc1_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28100,c)),c);
P_88bc1_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x28200,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) < sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88bc1_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28200,c)),c);
P_88bc1_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88bc1_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x204,SlU(0x0ULL),c);
P_88bc1_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,SlU(0x0ULL),c);
P_88bc1_10:;
goto L_88bc4;
}
L_88bc4:{ // JNC 0x00088dec
c.pc=0x88bc4;if(!sl_tick(c))return int(c.fault);
P_88bc4_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9b00,(!sl_get<1>(c.reg,sizeof(c.reg),0x200,c)),c);
P_88bc4_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9b00,c)){goto L_88dec;}
P_88bc4_2:;
goto L_88bca;
}
L_88bca:{ // MULSS XMM1,dword ptr [ESI + 0x140]
c.pc=0x88bca;if(!sl_tick(c))return int(c.fault);
P_88bca_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x140ULL)),c);
P_88bca_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88bca_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_88bca_3:;
goto L_88bd2;
}
L_88bd2:{ // ADDSS XMM4,XMM1
c.pc=0x88bd2;if(!sl_tick(c))return int(c.fault);
P_88bd2_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1300,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1300,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_88bd2_1:;
goto L_88bd6;
}
L_88bd6:{ // CVTTSS2SI EAX,XMM4
c.pc=0x88bd6;if(!sl_tick(c))return int(c.fault);
P_88bd6_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_trunc_fp(sl_get<4>(c.reg,sizeof(c.reg),0x1300,c),4,32),c);
P_88bd6_1:;
goto L_88bda;
}
L_88bda:{ // MOV dword ptr [ESI + 0x220],EAX
c.pc=0x88bda;if(!sl_tick(c))return int(c.fault);
P_88bda_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x220ULL)),c);
P_88bda_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88bda_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88bda_3:;
goto L_88be0;
}
L_88be0:{ // MOV EAX,dword ptr [ESI + 0x21c]
c.pc=0x88be0;if(!sl_tick(c))return int(c.fault);
P_88be0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x21cULL)),c);
P_88be0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88be0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88be0_3:;
goto L_88be6;
}
L_88be6:{ // TEST EAX,EAX
c.pc=0x88be6;if(!sl_tick(c))return int(c.fault);
P_88be6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88be6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88be6_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_88be6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88be6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_88be6_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_88be6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88be6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88be6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88be6_9:;
goto L_88be8;
}
L_88be8:{ // JLE 0x00088dab
c.pc=0x88be8;if(!sl_tick(c))return int(c.fault);
P_88be8_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88be8_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_88be8_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_88dab;}
P_88be8_3:;
goto L_88bee;
}
L_88bee:{ // LEA EAX,[EDI + -0x1]
c.pc=0x88bee;if(!sl_tick(c))return int(c.fault);
P_88bee_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xffffffffULL)),c);
P_88bee_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_88bee_2:;
goto L_88bf1;
}
L_88bf1:{ // CMP dword ptr [ESI + 0x21c],EAX
c.pc=0x88bf1;if(!sl_tick(c))return int(c.fault);
P_88bf1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x21cULL)),c);
P_88bf1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88bf1_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88bf1_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_88bf1_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x0,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x0,c)))&(SlU(1)<<31))!=0),c);
P_88bf1_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_88bf1_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88bf1_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_88bf1_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_88bf1_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88bf1_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88bf1_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88bf1_12:;
goto L_88bf7;
}
L_88bf7:{ // JLE 0x00088bff
c.pc=0x88bf7;if(!sl_tick(c))return int(c.fault);
P_88bf7_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88bf7_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_88bf7_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_88bff;}
P_88bf7_3:;
goto L_88bf9;
}
L_88bf9:{ // MOV dword ptr [ESI + 0x21c],EAX
c.pc=0x88bf9;if(!sl_tick(c))return int(c.fault);
P_88bf9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x21cULL)),c);
P_88bf9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88bf9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88bf9_3:;
goto L_88bff;
}
L_88bff:{ // MOV EDI,dword ptr [ESI + 0x220]
c.pc=0x88bff;if(!sl_tick(c))return int(c.fault);
P_88bff_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x220ULL)),c);
P_88bff_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88bff_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88bff_3:;
goto L_88c05;
}
L_88c05:{ // TEST EDI,EDI
c.pc=0x88c05;if(!sl_tick(c))return int(c.fault);
P_88c05_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88c05_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88c05_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) & sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c);
P_88c05_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88c05_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_88c05_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_88c05_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88c05_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88c05_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88c05_9:;
goto L_88c07;
}
L_88c07:{ // JLE 0x00088e6f
c.pc=0x88c07;if(!sl_tick(c))return int(c.fault);
P_88c07_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88c07_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_88c07_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_88e6f;}
P_88c07_3:;
goto L_88c0d;
}
L_88c0d:{ // CMP dword ptr [ESI + 0x220],EAX
c.pc=0x88c0d;if(!sl_tick(c))return int(c.fault);
P_88c0d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x220ULL)),c);
P_88c0d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88c0d_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88c0d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_88c0d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x0,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x0,c)))&(SlU(1)<<31))!=0),c);
P_88c0d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_88c0d_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88c0d_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_88c0d_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_88c0d_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88c0d_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88c0d_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88c0d_12:;
goto L_88c13;
}
L_88c13:{ // JLE 0x00088c1b
c.pc=0x88c13;if(!sl_tick(c))return int(c.fault);
P_88c13_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88c13_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_88c13_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_88c1b;}
P_88c13_3:;
goto L_88c15;
}
L_88c15:{ // MOV dword ptr [ESI + 0x220],EAX
c.pc=0x88c15;if(!sl_tick(c))return int(c.fault);
P_88c15_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x220ULL)),c);
P_88c15_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88c15_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88c15_3:;
goto L_88c1b;
}
L_88c1b:{ // MOVSS XMM1,dword ptr [EBX + 0x3ff8a]
c.pc=0x88c1b;if(!sl_tick(c))return int(c.fault);
P_88c1b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x3ff8aULL)),c);
P_88c1b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88c1b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88c1b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_88c1b_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_88c1b_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_88c1b_6:;
goto L_88c23;
}
L_88c23:{ // MOVAPS XMM0,XMM1
c.pc=0x88c23;if(!sl_tick(c))return int(c.fault);
P_88c23_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_88c23_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x1244,c),c);
P_88c23_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x1248,c),c);
P_88c23_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x124c,c),c);
P_88c23_4:;
goto L_88c26;
}
L_88c26:{ // SUBSS XMM0,dword ptr [ECX + 0x46c]
c.pc=0x88c26;if(!sl_tick(c))return int(c.fault);
P_88c26_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x46cULL)),c);
P_88c26_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88c26_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) - sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_88c26_3:;
goto L_88c2e;
}
L_88c2e:{ // MOVSS dword ptr [ESI + 0x224],XMM0
c.pc=0x88c2e;if(!sl_tick(c))return int(c.fault);
P_88c2e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x224ULL)),c);
P_88c2e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_88c2e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88c2e_3:;
goto L_88c36;
}
L_88c36:{ // CVTSS2SD XMM2,dword ptr [ECX + 0x46c]
c.pc=0x88c36;if(!sl_tick(c))return int(c.fault);
P_88c36_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x46cULL)),c);
P_88c36_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88c36_2:;
sl_put<8>(c.reg,sizeof(c.reg),0x1280,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)))),c);
P_88c36_3:;
goto L_88c3e;
}
L_88c3e:{ // MOVSS XMM0,dword ptr [ECX + 0x23c]
c.pc=0x88c3e;if(!sl_tick(c))return int(c.fault);
P_88c3e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x23cULL)),c);
P_88c3e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88c3e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88c3e_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,SlU(0x0ULL),c);
P_88c3e_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_88c3e_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,SlU(0x0ULL),c);
P_88c3e_6:;
goto L_88c46;
}
L_88c46:{ // ADDSS XMM0,XMM1
c.pc=0x88c46;if(!sl_tick(c))return int(c.fault);
P_88c46_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_88c46_1:;
goto L_88c4a;
}
L_88c4a:{ // CVTSS2SD XMM0,XMM0
c.pc=0x88c4a;if(!sl_tick(c))return int(c.fault);
P_88c4a_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)))),c);
P_88c4a_1:;
goto L_88c4e;
}
L_88c4e:{ // MOVSD XMM5,qword ptr [EBX + 0x3fc0e]
c.pc=0x88c4e;if(!sl_tick(c))return int(c.fault);
P_88c4e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x3fc0eULL)),c);
P_88c4e_1:;
sl_put<8>(c.temp,sizeof(c.temp),0x5280,sl_get<8>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88c4e_2:;
sl_put<8>(c.reg,sizeof(c.reg),0x1340,sl_get<8>(c.temp,sizeof(c.temp),0x5280,c),c);
P_88c4e_3:;
sl_put<8>(c.reg,sizeof(c.reg),0x1348,SlU(0x0ULL),c);
P_88c4e_4:;
goto L_88c56;
}
L_88c56:{ // MULSD XMM0,XMM5
c.pc=0x88c56;if(!sl_tick(c))return int(c.fault);
P_88c56_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1340,c))),c);
P_88c56_1:;
goto L_88c5a;
}
L_88c5a:{ // MOVSD XMM4,qword ptr [EBX + 0x3fb6e]
c.pc=0x88c5a;if(!sl_tick(c))return int(c.fault);
P_88c5a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x3fb6eULL)),c);
P_88c5a_1:;
sl_put<8>(c.temp,sizeof(c.temp),0x5280,sl_get<8>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88c5a_2:;
sl_put<8>(c.reg,sizeof(c.reg),0x1300,sl_get<8>(c.temp,sizeof(c.temp),0x5280,c),c);
P_88c5a_3:;
sl_put<8>(c.reg,sizeof(c.reg),0x1308,SlU(0x0ULL),c);
P_88c5a_4:;
goto L_88c62;
}
L_88c62:{ // ADDSD XMM0,XMM4
c.pc=0x88c62;if(!sl_tick(c))return int(c.fault);
P_88c62_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c)) + sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1300,c))),c);
P_88c62_1:;
goto L_88c66;
}
L_88c66:{ // MULSD XMM2,XMM0
c.pc=0x88c66;if(!sl_tick(c))return int(c.fault);
P_88c66_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1280,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1280,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_88c66_1:;
goto L_88c6a;
}
L_88c6a:{ // CVTSD2SS XMM2,XMM2
c.pc=0x88c6a;if(!sl_tick(c))return int(c.fault);
P_88c6a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1280,sl_bits(static_cast<float>(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1280,c)))),c);
P_88c6a_1:;
goto L_88c6e;
}
L_88c6e:{ // MOVSS dword ptr [ESI + 0x228],XMM2
c.pc=0x88c6e;if(!sl_tick(c))return int(c.fault);
P_88c6e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x228ULL)),c);
P_88c6e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1280,c),c);
P_88c6e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88c6e_3:;
goto L_88c76;
}
L_88c76:{ // CVTSS2SD XMM2,dword ptr [ECX + 0x46c]
c.pc=0x88c76;if(!sl_tick(c))return int(c.fault);
P_88c76_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x46cULL)),c);
P_88c76_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88c76_2:;
sl_put<8>(c.reg,sizeof(c.reg),0x1280,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)))),c);
P_88c76_3:;
goto L_88c7e;
}
L_88c7e:{ // MOVSS XMM0,dword ptr [ECX + 0x23c]
c.pc=0x88c7e;if(!sl_tick(c))return int(c.fault);
P_88c7e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x23cULL)),c);
P_88c7e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88c7e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88c7e_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,SlU(0x0ULL),c);
P_88c7e_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_88c7e_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,SlU(0x0ULL),c);
P_88c7e_6:;
goto L_88c86;
}
L_88c86:{ // ADDSS XMM0,XMM1
c.pc=0x88c86;if(!sl_tick(c))return int(c.fault);
P_88c86_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_88c86_1:;
goto L_88c8a;
}
L_88c8a:{ // CVTSS2SD XMM0,XMM0
c.pc=0x88c8a;if(!sl_tick(c))return int(c.fault);
P_88c8a_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)))),c);
P_88c8a_1:;
goto L_88c8e;
}
L_88c8e:{ // MOVSD XMM3,qword ptr [EBX + 0x3fbae]
c.pc=0x88c8e;if(!sl_tick(c))return int(c.fault);
P_88c8e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x3fbaeULL)),c);
P_88c8e_1:;
sl_put<8>(c.temp,sizeof(c.temp),0x5280,sl_get<8>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88c8e_2:;
sl_put<8>(c.reg,sizeof(c.reg),0x12c0,sl_get<8>(c.temp,sizeof(c.temp),0x5280,c),c);
P_88c8e_3:;
sl_put<8>(c.reg,sizeof(c.reg),0x12c8,SlU(0x0ULL),c);
P_88c8e_4:;
goto L_88c96;
}
L_88c96:{ // MULSD XMM0,XMM3
c.pc=0x88c96;if(!sl_tick(c))return int(c.fault);
P_88c96_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x12c0,c))),c);
P_88c96_1:;
goto L_88c9a;
}
L_88c9a:{ // MULSD XMM2,XMM0
c.pc=0x88c9a;if(!sl_tick(c))return int(c.fault);
P_88c9a_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1280,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1280,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_88c9a_1:;
goto L_88c9e;
}
L_88c9e:{ // CVTSD2SS XMM2,XMM2
c.pc=0x88c9e;if(!sl_tick(c))return int(c.fault);
P_88c9e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1280,sl_bits(static_cast<float>(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1280,c)))),c);
P_88c9e_1:;
goto L_88ca2;
}
L_88ca2:{ // MOVSS dword ptr [ESI + 0x22c],XMM2
c.pc=0x88ca2;if(!sl_tick(c))return int(c.fault);
P_88ca2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x22cULL)),c);
P_88ca2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1280,c),c);
P_88ca2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88ca2_3:;
goto L_88caa;
}
L_88caa:{ // CVTSS2SD XMM2,dword ptr [ECX + 0x46c]
c.pc=0x88caa;if(!sl_tick(c))return int(c.fault);
P_88caa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x46cULL)),c);
P_88caa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88caa_2:;
sl_put<8>(c.reg,sizeof(c.reg),0x1280,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)))),c);
P_88caa_3:;
goto L_88cb2;
}
L_88cb2:{ // MOVSS XMM0,dword ptr [ECX + 0x38c]
c.pc=0x88cb2;if(!sl_tick(c))return int(c.fault);
P_88cb2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x38cULL)),c);
P_88cb2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88cb2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88cb2_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,SlU(0x0ULL),c);
P_88cb2_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,SlU(0x0ULL),c);
P_88cb2_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,SlU(0x0ULL),c);
P_88cb2_6:;
goto L_88cba;
}
L_88cba:{ // ADDSS XMM0,XMM1
c.pc=0x88cba;if(!sl_tick(c))return int(c.fault);
P_88cba_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_88cba_1:;
goto L_88cbe;
}
L_88cbe:{ // CVTSS2SD XMM0,XMM0
c.pc=0x88cbe;if(!sl_tick(c))return int(c.fault);
P_88cbe_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)))),c);
P_88cbe_1:;
goto L_88cc2;
}
L_88cc2:{ // MULSD XMM0,XMM3
c.pc=0x88cc2;if(!sl_tick(c))return int(c.fault);
P_88cc2_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x12c0,c))),c);
P_88cc2_1:;
goto L_88cc6;
}
L_88cc6:{ // MULSD XMM2,XMM0
c.pc=0x88cc6;if(!sl_tick(c))return int(c.fault);
P_88cc6_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1280,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1280,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_88cc6_1:;
goto L_88cca;
}
L_88cca:{ // CVTSD2SS XMM2,XMM2
c.pc=0x88cca;if(!sl_tick(c))return int(c.fault);
P_88cca_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1280,sl_bits(static_cast<float>(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1280,c)))),c);
P_88cca_1:;
goto L_88cce;
}
L_88cce:{ // MOVSS dword ptr [ESI + 0x230],XMM2
c.pc=0x88cce;if(!sl_tick(c))return int(c.fault);
P_88cce_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x230ULL)),c);
P_88cce_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1280,c),c);
P_88cce_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88cce_3:;
goto L_88cd6;
}
L_88cd6:{ // CVTSS2SD XMM0,dword ptr [ECX + 0x46c]
c.pc=0x88cd6;if(!sl_tick(c))return int(c.fault);
P_88cd6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x46cULL)),c);
P_88cd6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88cd6_2:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c)))),c);
P_88cd6_3:;
goto L_88cde;
}
L_88cde:{ // ADDSS XMM1,dword ptr [ECX + 0x38c]
c.pc=0x88cde;if(!sl_tick(c))return int(c.fault);
P_88cde_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x38cULL)),c);
P_88cde_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88cde_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) + sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_88cde_3:;
goto L_88ce6;
}
L_88ce6:{ // CVTSS2SD XMM1,XMM1
c.pc=0x88ce6;if(!sl_tick(c))return int(c.fault);
P_88ce6_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1240,sl_bits(static_cast<double>(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)))),c);
P_88ce6_1:;
goto L_88cea;
}
L_88cea:{ // MULSD XMM1,XMM5
c.pc=0x88cea;if(!sl_tick(c))return int(c.fault);
P_88cea_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1340,c))),c);
P_88cea_1:;
goto L_88cee;
}
L_88cee:{ // ADDSD XMM1,XMM4
c.pc=0x88cee;if(!sl_tick(c))return int(c.fault);
P_88cee_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1240,c)) + sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1300,c))),c);
P_88cee_1:;
goto L_88cf2;
}
L_88cf2:{ // MULSD XMM0,XMM1
c.pc=0x88cf2;if(!sl_tick(c))return int(c.fault);
P_88cf2_0:;
sl_put<8>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_88cf2_1:;
goto L_88cf6;
}
L_88cf6:{ // CVTSD2SS XMM0,XMM0
c.pc=0x88cf6;if(!sl_tick(c))return int(c.fault);
P_88cf6_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(static_cast<float>(sl_float<double>(sl_get<8>(c.reg,sizeof(c.reg),0x1200,c)))),c);
P_88cf6_1:;
goto L_88cfa;
}
L_88cfa:{ // MOVSS dword ptr [ESI + 0x234],XMM0
c.pc=0x88cfa;if(!sl_tick(c))return int(c.fault);
P_88cfa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x234ULL)),c);
P_88cfa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1200,c),c);
P_88cfa_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88cfa_3:;
goto L_88d02;
}
L_88d02:{ // MOV EAX,dword ptr [ECX + 0x4dc]
c.pc=0x88d02;if(!sl_tick(c))return int(c.fault);
P_88d02_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x4dcULL)),c);
P_88d02_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88d02_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88d02_3:;
goto L_88d08;
}
L_88d08:{ // MOV dword ptr [ESI + 0x238],EAX
c.pc=0x88d08;if(!sl_tick(c))return int(c.fault);
P_88d08_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x238ULL)),c);
P_88d08_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88d08_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88d08_3:;
goto L_88d0e;
}
L_88d0e:{ // MOV EAX,dword ptr [ECX + 0x3fc]
c.pc=0x88d0e;if(!sl_tick(c))return int(c.fault);
P_88d0e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x3fcULL)),c);
P_88d0e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88d0e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88d0e_3:;
goto L_88d14;
}
L_88d14:{ // MOV dword ptr [ESI + 0x23c],EAX
c.pc=0x88d14;if(!sl_tick(c))return int(c.fault);
P_88d14_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x23cULL)),c);
P_88d14_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88d14_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88d14_3:;
goto L_88d1a;
}
L_88d1a:{ // ADD ESP,0x2c
c.pc=0x88d1a;if(!sl_tick(c))return int(c.fault);
P_88d1a_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_88d1a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL)))&(SlU(0x2cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL)))&(SlU(1)<<31))!=0),c);
P_88d1a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x2cULL)),c);
P_88d1a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88d1a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_88d1a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_88d1a_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88d1a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88d1a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88d1a_9:;
goto L_88d1d;
}
L_88d1d:{ // POP EBX
c.pc=0x88d1d;if(!sl_tick(c))return int(c.fault);
P_88d1d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88d1d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88d1d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88d1d_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88d1d_4:;
goto L_88d1e;
}
L_88d1e:{ // POP ESI
c.pc=0x88d1e;if(!sl_tick(c))return int(c.fault);
P_88d1e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88d1e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88d1e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88d1e_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88d1e_4:;
goto L_88d1f;
}
L_88d1f:{ // POP EDI
c.pc=0x88d1f;if(!sl_tick(c))return int(c.fault);
P_88d1f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88d1f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88d1f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88d1f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88d1f_4:;
goto L_88d20;
}
L_88d20:{ // POP EBP
c.pc=0x88d20;if(!sl_tick(c))return int(c.fault);
P_88d20_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88d20_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88d20_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88d20_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88d20_4:;
goto L_88d21;
}
L_88d21:{ // RET
c.pc=0x88d21;if(!sl_tick(c))return int(c.fault);
P_88d21_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88d21_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88d21_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_88d21_3:;
goto L_88d22;
}
L_88d22:{ // MOVSS XMM1,dword ptr [EBX + 0x3ffca]
c.pc=0x88d22;if(!sl_tick(c))return int(c.fault);
P_88d22_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x3ffcaULL)),c);
P_88d22_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88d22_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88d22_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_88d22_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_88d22_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_88d22_6:;
goto L_88d2a;
}
L_88d2a:{ // MULSS XMM1,dword ptr [ECX + 0x7c]
c.pc=0x88d2a;if(!sl_tick(c))return int(c.fault);
P_88d2a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x7cULL)),c);
P_88d2a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88d2a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_88d2a_3:;
goto L_88d2f;
}
L_88d2f:{ // LEA EAX,[ECX + 0xe0]
c.pc=0x88d2f;if(!sl_tick(c))return int(c.fault);
P_88d2f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0xe0ULL)),c);
P_88d2f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_88d2f_2:;
goto L_88d35;
}
L_88d35:{ // MOV EDX,dword ptr [EAX + 0x8]
c.pc=0x88d35;if(!sl_tick(c))return int(c.fault);
P_88d35_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_88d35_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88d35_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88d35_3:;
goto L_88d38;
}
L_88d38:{ // CMP EDX,dword ptr [EAX + 0x24]
c.pc=0x88d38;if(!sl_tick(c))return int(c.fault);
P_88d38_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x24ULL)),c);
P_88d38_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88d38_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88d38_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_88d38_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_88d38_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_88d38_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88d38_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_88d38_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_88d38_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88d38_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88d38_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88d38_12:;
goto L_88d3b;
}
L_88d3b:{ // JG 0x00088e7e
c.pc=0x88d3b;if(!sl_tick(c))return int(c.fault);
P_88d3b_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_88d3b_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88d3b_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_88d3b_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_88e7e;}
P_88d3b_4:;
goto L_88d41;
}
L_88d41:{ // MOVSS XMM3,dword ptr [ESI + 0x140]
c.pc=0x88d41;if(!sl_tick(c))return int(c.fault);
P_88d41_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x140ULL)),c);
P_88d41_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88d41_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c0,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88d41_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c4,SlU(0x0ULL),c);
P_88d41_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x12c8,SlU(0x0ULL),c);
P_88d41_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x12cc,SlU(0x0ULL),c);
P_88d41_6:;
goto L_88d49;
}
L_88d49:{ // MOV EDI,dword ptr [ESI + 0x204]
c.pc=0x88d49;if(!sl_tick(c))return int(c.fault);
P_88d49_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_88d49_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88d49_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88d49_3:;
goto L_88d4f;
}
L_88d4f:{ // LEA EAX,[EDI + -0x10]
c.pc=0x88d4f;if(!sl_tick(c))return int(c.fault);
P_88d4f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0xfffffff0ULL)),c);
P_88d4f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_88d4f_2:;
goto L_88d52;
}
L_88d52:{ // CVTSI2SS XMM2,EAX
c.pc=0x88d52;if(!sl_tick(c))return int(c.fault);
P_88d52_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1280,sl_bits(static_cast<float>(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32))),c);
P_88d52_1:;
goto L_88d56;
}
L_88d56:{ // MOVAPS XMM0,XMM1
c.pc=0x88d56;if(!sl_tick(c))return int(c.fault);
P_88d56_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x1240,c),c);
P_88d56_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x1244,c),c);
P_88d56_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x1248,c),c);
P_88d56_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x124c,c),c);
P_88d56_4:;
goto L_88d59;
}
L_88d59:{ // MULSS XMM0,XMM3
c.pc=0x88d59;if(!sl_tick(c))return int(c.fault);
P_88d59_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x12c0,c))),c);
P_88d59_1:;
goto L_88d5d;
}
L_88d5d:{ // UCOMISS XMM0,XMM2
c.pc=0x88d5d;if(!sl_tick(c))return int(c.fault);
P_88d5d_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x27f80,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_88d5d_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x28000,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88d5d_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(bool(sl_get<1>(c.temp,sizeof(c.temp),0x27f80,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0x28000,c))),c);
P_88d5d_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x28100,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) == sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88d5d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28100,c)),c);
P_88d5d_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x28200,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) < sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88d5d_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28200,c)),c);
P_88d5d_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88d5d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x204,SlU(0x0ULL),c);
P_88d5d_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,SlU(0x0ULL),c);
P_88d5d_10:;
goto L_88d60;
}
L_88d60:{ // JC 0x00088acf
c.pc=0x88d60;if(!sl_tick(c))return int(c.fault);
P_88d60_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x200,c)){goto L_88acf;}
P_88d60_1:;
goto L_88d66;
}
L_88d66:{ // MOVSS XMM4,dword ptr [EBX + 0x3ff92]
c.pc=0x88d66;if(!sl_tick(c))return int(c.fault);
P_88d66_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x3ff92ULL)),c);
P_88d66_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88d66_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1300,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88d66_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1304,SlU(0x0ULL),c);
P_88d66_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1308,SlU(0x0ULL),c);
P_88d66_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x130c,SlU(0x0ULL),c);
P_88d66_6:;
goto L_88d6e;
}
L_88d6e:{ // MULSS XMM1,XMM4
c.pc=0x88d6e;if(!sl_tick(c))return int(c.fault);
P_88d6e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1300,c))),c);
P_88d6e_1:;
goto L_88d72;
}
L_88d72:{ // MOVAPS XMM0,XMM3
c.pc=0x88d72;if(!sl_tick(c))return int(c.fault);
P_88d72_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x12c0,c),c);
P_88d72_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x12c4,c),c);
P_88d72_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x12c8,c),c);
P_88d72_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x12cc,c),c);
P_88d72_4:;
goto L_88d75;
}
L_88d75:{ // MULSS XMM0,XMM1
c.pc=0x88d75;if(!sl_tick(c))return int(c.fault);
P_88d75_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_88d75_1:;
goto L_88d79;
}
L_88d79:{ // UCOMISS XMM0,XMM2
c.pc=0x88d79;if(!sl_tick(c))return int(c.fault);
P_88d79_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x27f80,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_88d79_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x28000,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88d79_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(bool(sl_get<1>(c.temp,sizeof(c.temp),0x27f80,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0x28000,c))),c);
P_88d79_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x28100,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) == sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88d79_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28100,c)),c);
P_88d79_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x28200,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) < sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88d79_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28200,c)),c);
P_88d79_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88d79_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x204,SlU(0x0ULL),c);
P_88d79_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,SlU(0x0ULL),c);
P_88d79_10:;
goto L_88d7c;
}
L_88d7c:{ // JNC 0x00088d6e
c.pc=0x88d7c;if(!sl_tick(c))return int(c.fault);
P_88d7c_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9b00,(!sl_get<1>(c.reg,sizeof(c.reg),0x200,c)),c);
P_88d7c_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9b00,c)){goto L_88d6e;}
P_88d7c_2:;
goto L_88d7e;
}
L_88d7e:{ // JMP 0x00088ad7
c.pc=0x88d7e;if(!sl_tick(c))return int(c.fault);
P_88d7e_0:;
goto L_88ad7;
P_88d7e_1:;
goto L_88d83;
}
L_88d83:{ // PXOR XMM1,XMM1
c.pc=0x88d83;if(!sl_tick(c))return int(c.fault);
P_88d83_0:;
sl_put<16>(c.reg,sizeof(c.reg),0x1240,(sl_get<16>(c.reg,sizeof(c.reg),0x1240,c) ^ sl_get<16>(c.reg,sizeof(c.reg),0x1240,c)),c);
P_88d83_1:;
goto L_88d87;
}
L_88d87:{ // MULSS XMM1,dword ptr [ESI + 0x140]
c.pc=0x88d87;if(!sl_tick(c))return int(c.fault);
P_88d87_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x140ULL)),c);
P_88d87_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88d87_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.temp,sizeof(c.temp),0x5200,c))),c);
P_88d87_3:;
goto L_88d8f;
}
L_88d8f:{ // ADDSS XMM4,XMM1
c.pc=0x88d8f;if(!sl_tick(c))return int(c.fault);
P_88d8f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1300,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1300,c)) + sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_88d8f_1:;
goto L_88d93;
}
L_88d93:{ // CVTTSS2SI EAX,XMM4
c.pc=0x88d93;if(!sl_tick(c))return int(c.fault);
P_88d93_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_trunc_fp(sl_get<4>(c.reg,sizeof(c.reg),0x1300,c),4,32),c);
P_88d93_1:;
goto L_88d97;
}
L_88d97:{ // MOV dword ptr [ESI + 0x220],EAX
c.pc=0x88d97;if(!sl_tick(c))return int(c.fault);
P_88d97_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x220ULL)),c);
P_88d97_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88d97_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88d97_3:;
goto L_88d9d;
}
L_88d9d:{ // MOV EAX,dword ptr [ESI + 0x21c]
c.pc=0x88d9d;if(!sl_tick(c))return int(c.fault);
P_88d9d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x21cULL)),c);
P_88d9d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88d9d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88d9d_3:;
goto L_88da3;
}
L_88da3:{ // TEST EAX,EAX
c.pc=0x88da3;if(!sl_tick(c))return int(c.fault);
P_88da3_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88da3_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88da3_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_88da3_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88da3_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_88da3_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_88da3_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88da3_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88da3_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88da3_9:;
goto L_88da5;
}
L_88da5:{ // JG 0x00088bee
c.pc=0x88da5;if(!sl_tick(c))return int(c.fault);
P_88da5_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa480,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_88da5_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa500,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_88da5_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa600,(bool(sl_get<1>(c.temp,sizeof(c.temp),0xa480,c)) && bool(sl_get<1>(c.temp,sizeof(c.temp),0xa500,c))),c);
P_88da5_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa600,c)){goto L_88bee;}
P_88da5_4:;
goto L_88dab;
}
L_88dab:{ // MOV dword ptr [ESI + 0x21c],0x1
c.pc=0x88dab;if(!sl_tick(c))return int(c.fault);
P_88dab_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x21cULL)),c);
P_88dab_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x1ULL),c);
P_88dab_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_88dab_3:;
goto L_88db5;
}
L_88db5:{ // JMP 0x00088bee
c.pc=0x88db5;if(!sl_tick(c))return int(c.fault);
P_88db5_0:;
goto L_88bee;
P_88db5_1:;
goto L_88dba;
}
L_88dba:{ // PXOR XMM1,XMM1
c.pc=0x88dba;if(!sl_tick(c))return int(c.fault);
P_88dba_0:;
sl_put<16>(c.reg,sizeof(c.reg),0x1240,(sl_get<16>(c.reg,sizeof(c.reg),0x1240,c) ^ sl_get<16>(c.reg,sizeof(c.reg),0x1240,c)),c);
P_88dba_1:;
goto L_88dbe;
}
L_88dbe:{ // JMP 0x00088b5e
c.pc=0x88dbe;if(!sl_tick(c))return int(c.fault);
P_88dbe_0:;
goto L_88b5e;
P_88dbe_1:;
goto L_88dc3;
}
L_88dc3:{ // MULSS XMM1,XMM4
c.pc=0x88dc3;if(!sl_tick(c))return int(c.fault);
P_88dc3_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1300,c))),c);
P_88dc3_1:;
goto L_88dc7;
}
L_88dc7:{ // MOVAPS XMM0,XMM3
c.pc=0x88dc7;if(!sl_tick(c))return int(c.fault);
P_88dc7_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x12c0,c),c);
P_88dc7_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x12c4,c),c);
P_88dc7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x12c8,c),c);
P_88dc7_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x12cc,c),c);
P_88dc7_4:;
goto L_88dca;
}
L_88dca:{ // MULSS XMM0,XMM1
c.pc=0x88dca;if(!sl_tick(c))return int(c.fault);
P_88dca_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_88dca_1:;
goto L_88dce;
}
L_88dce:{ // UCOMISS XMM0,XMM2
c.pc=0x88dce;if(!sl_tick(c))return int(c.fault);
P_88dce_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x27f80,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_88dce_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x28000,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88dce_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(bool(sl_get<1>(c.temp,sizeof(c.temp),0x27f80,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0x28000,c))),c);
P_88dce_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x28100,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) == sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88dce_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28100,c)),c);
P_88dce_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x28200,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) < sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88dce_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28200,c)),c);
P_88dce_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88dce_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x204,SlU(0x0ULL),c);
P_88dce_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,SlU(0x0ULL),c);
P_88dce_10:;
goto L_88dd1;
}
L_88dd1:{ // JC 0x00088b5e
c.pc=0x88dd1;if(!sl_tick(c))return int(c.fault);
P_88dd1_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x200,c)){goto L_88b5e;}
P_88dd1_1:;
goto L_88dd7;
}
L_88dd7:{ // MULSS XMM1,XMM4
c.pc=0x88dd7;if(!sl_tick(c))return int(c.fault);
P_88dd7_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1300,c))),c);
P_88dd7_1:;
goto L_88ddb;
}
L_88ddb:{ // MOVAPS XMM0,XMM3
c.pc=0x88ddb;if(!sl_tick(c))return int(c.fault);
P_88ddb_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x12c0,c),c);
P_88ddb_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x12c4,c),c);
P_88ddb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x12c8,c),c);
P_88ddb_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x12cc,c),c);
P_88ddb_4:;
goto L_88dde;
}
L_88dde:{ // MULSS XMM0,XMM1
c.pc=0x88dde;if(!sl_tick(c))return int(c.fault);
P_88dde_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_88dde_1:;
goto L_88de2;
}
L_88de2:{ // UCOMISS XMM0,XMM2
c.pc=0x88de2;if(!sl_tick(c))return int(c.fault);
P_88de2_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x27f80,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_88de2_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x28000,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88de2_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(bool(sl_get<1>(c.temp,sizeof(c.temp),0x27f80,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0x28000,c))),c);
P_88de2_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x28100,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) == sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88de2_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28100,c)),c);
P_88de2_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x28200,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) < sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88de2_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28200,c)),c);
P_88de2_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88de2_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x204,SlU(0x0ULL),c);
P_88de2_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,SlU(0x0ULL),c);
P_88de2_10:;
goto L_88de5;
}
L_88de5:{ // JNC 0x00088dc3
c.pc=0x88de5;if(!sl_tick(c))return int(c.fault);
P_88de5_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9b00,(!sl_get<1>(c.reg,sizeof(c.reg),0x200,c)),c);
P_88de5_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9b00,c)){goto L_88dc3;}
P_88de5_2:;
goto L_88de7;
}
L_88de7:{ // JMP 0x00088b5e
c.pc=0x88de7;if(!sl_tick(c))return int(c.fault);
P_88de7_0:;
goto L_88b5e;
P_88de7_1:;
goto L_88dec;
}
L_88dec:{ // MULSS XMM1,XMM4
c.pc=0x88dec;if(!sl_tick(c))return int(c.fault);
P_88dec_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1300,c))),c);
P_88dec_1:;
goto L_88df0;
}
L_88df0:{ // MOVAPS XMM0,XMM3
c.pc=0x88df0;if(!sl_tick(c))return int(c.fault);
P_88df0_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x12c0,c),c);
P_88df0_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x12c4,c),c);
P_88df0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x12c8,c),c);
P_88df0_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x12cc,c),c);
P_88df0_4:;
goto L_88df3;
}
L_88df3:{ // MULSS XMM0,XMM1
c.pc=0x88df3;if(!sl_tick(c))return int(c.fault);
P_88df3_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_88df3_1:;
goto L_88df7;
}
L_88df7:{ // UCOMISS XMM0,XMM2
c.pc=0x88df7;if(!sl_tick(c))return int(c.fault);
P_88df7_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x27f80,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_88df7_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x28000,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88df7_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(bool(sl_get<1>(c.temp,sizeof(c.temp),0x27f80,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0x28000,c))),c);
P_88df7_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x28100,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) == sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88df7_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28100,c)),c);
P_88df7_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x28200,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) < sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88df7_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28200,c)),c);
P_88df7_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88df7_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x204,SlU(0x0ULL),c);
P_88df7_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,SlU(0x0ULL),c);
P_88df7_10:;
goto L_88dfa;
}
L_88dfa:{ // JC 0x00088bca
c.pc=0x88dfa;if(!sl_tick(c))return int(c.fault);
P_88dfa_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x200,c)){goto L_88bca;}
P_88dfa_1:;
goto L_88e00;
}
L_88e00:{ // MULSS XMM1,XMM4
c.pc=0x88e00;if(!sl_tick(c))return int(c.fault);
P_88e00_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1300,c))),c);
P_88e00_1:;
goto L_88e04;
}
L_88e04:{ // MOVAPS XMM0,XMM3
c.pc=0x88e04;if(!sl_tick(c))return int(c.fault);
P_88e04_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_get<4>(c.reg,sizeof(c.reg),0x12c0,c),c);
P_88e04_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x1204,sl_get<4>(c.reg,sizeof(c.reg),0x12c4,c),c);
P_88e04_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1208,sl_get<4>(c.reg,sizeof(c.reg),0x12c8,c),c);
P_88e04_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x120c,sl_get<4>(c.reg,sizeof(c.reg),0x12cc,c),c);
P_88e04_4:;
goto L_88e07;
}
L_88e07:{ // MULSS XMM0,XMM1
c.pc=0x88e07;if(!sl_tick(c))return int(c.fault);
P_88e07_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1200,sl_bits(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) * sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c))),c);
P_88e07_1:;
goto L_88e0b;
}
L_88e0b:{ // UCOMISS XMM0,XMM2
c.pc=0x88e0b;if(!sl_tick(c))return int(c.fault);
P_88e0b_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x27f80,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c))),c);
P_88e0b_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x28000,__builtin_isnan(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88e0b_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(bool(sl_get<1>(c.temp,sizeof(c.temp),0x27f80,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0x28000,c))),c);
P_88e0b_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x28100,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) == sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88e0b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28100,c)),c);
P_88e0b_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x28200,(sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1200,c)) < sl_float<float>(sl_get<4>(c.reg,sizeof(c.reg),0x1280,c))),c);
P_88e0b_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.reg,sizeof(c.reg),0x202,c) | sl_get<1>(c.temp,sizeof(c.temp),0x28200,c)),c);
P_88e0b_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88e0b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x204,SlU(0x0ULL),c);
P_88e0b_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,SlU(0x0ULL),c);
P_88e0b_10:;
goto L_88e0e;
}
L_88e0e:{ // JNC 0x00088dec
c.pc=0x88e0e;if(!sl_tick(c))return int(c.fault);
P_88e0e_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9b00,(!sl_get<1>(c.reg,sizeof(c.reg),0x200,c)),c);
P_88e0e_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9b00,c)){goto L_88dec;}
P_88e0e_2:;
goto L_88e10;
}
L_88e10:{ // JMP 0x00088bca
c.pc=0x88e10;if(!sl_tick(c))return int(c.fault);
P_88e10_0:;
goto L_88bca;
P_88e10_1:;
goto L_88e15;
}
L_88e15:{ // MOV dword ptr [ESP + 0x4],EDX
c.pc=0x88e15;if(!sl_tick(c))return int(c.fault);
P_88e15_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_88e15_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_88e15_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88e15_3:;
goto L_88e19;
}
L_88e19:{ // MOV dword ptr [ESP],ESI
c.pc=0x88e19;if(!sl_tick(c))return int(c.fault);
P_88e19_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88e19_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88e19_2:;
goto L_88e1c;
}
L_88e1c:{ // CALL 0x0001354c
c.pc=0x88e1c;if(!sl_tick(c))return int(c.fault);
P_88e1c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88e1c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88e21ULL),c);
P_88e1c_2:;
c.pc=0x1354c;goto dispatch;
P_88e1c_3:;
goto L_88e21;
}
L_88e21:{ // FSTP dword ptr [EBP + -0x1c]
c.pc=0x88e21;if(!sl_tick(c))return int(c.fault);
P_88e21_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_88e21_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_ext80_to_f32(sl_get<10>(c.reg,sizeof(c.reg),0x1100,c)),c);
P_88e21_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_88e21_3:;
sl_put<10>(c.reg,sizeof(c.reg),0x1100,sl_get<10>(c.reg,sizeof(c.reg),0x1110,c),c);
P_88e21_4:;
sl_put<10>(c.reg,sizeof(c.reg),0x1110,sl_get<10>(c.reg,sizeof(c.reg),0x1120,c),c);
P_88e21_5:;
sl_put<10>(c.reg,sizeof(c.reg),0x1120,sl_get<10>(c.reg,sizeof(c.reg),0x1130,c),c);
P_88e21_6:;
sl_put<10>(c.reg,sizeof(c.reg),0x1130,sl_get<10>(c.reg,sizeof(c.reg),0x1140,c),c);
P_88e21_7:;
sl_put<10>(c.reg,sizeof(c.reg),0x1140,sl_get<10>(c.reg,sizeof(c.reg),0x1150,c),c);
P_88e21_8:;
sl_put<10>(c.reg,sizeof(c.reg),0x1150,sl_get<10>(c.reg,sizeof(c.reg),0x1160,c),c);
P_88e21_9:;
sl_put<10>(c.reg,sizeof(c.reg),0x1160,sl_get<10>(c.reg,sizeof(c.reg),0x1170,c),c);
P_88e21_10:;
goto L_88e24;
}
L_88e24:{ // MOVSS XMM1,dword ptr [EBP + -0x1c]
c.pc=0x88e24;if(!sl_tick(c))return int(c.fault);
P_88e24_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_88e24_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88e24_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88e24_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_88e24_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_88e24_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_88e24_6:;
goto L_88e29;
}
L_88e29:{ // MOV ECX,dword ptr [ESI + 0x124]
c.pc=0x88e29;if(!sl_tick(c))return int(c.fault);
P_88e29_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x124ULL)),c);
P_88e29_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88e29_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88e29_3:;
goto L_88e2f;
}
L_88e2f:{ // MOV EDI,dword ptr [ESI + 0x204]
c.pc=0x88e2f;if(!sl_tick(c))return int(c.fault);
P_88e2f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_88e2f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88e2f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88e2f_3:;
goto L_88e35;
}
L_88e35:{ // MOVSS XMM4,dword ptr [EBX + 0x3ff92]
c.pc=0x88e35;if(!sl_tick(c))return int(c.fault);
P_88e35_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x3ff92ULL)),c);
P_88e35_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88e35_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1300,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88e35_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1304,SlU(0x0ULL),c);
P_88e35_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1308,SlU(0x0ULL),c);
P_88e35_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x130c,SlU(0x0ULL),c);
P_88e35_6:;
goto L_88e3d;
}
L_88e3d:{ // JMP 0x00088b3f
c.pc=0x88e3d;if(!sl_tick(c))return int(c.fault);
P_88e3d_0:;
goto L_88b3f;
P_88e3d_1:;
goto L_88e42;
}
L_88e42:{ // MOV dword ptr [ESP + 0x4],EDX
c.pc=0x88e42;if(!sl_tick(c))return int(c.fault);
P_88e42_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_88e42_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_88e42_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88e42_3:;
goto L_88e46;
}
L_88e46:{ // MOV dword ptr [ESP],ESI
c.pc=0x88e46;if(!sl_tick(c))return int(c.fault);
P_88e46_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88e46_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88e46_2:;
goto L_88e49;
}
L_88e49:{ // CALL 0x0001354c
c.pc=0x88e49;if(!sl_tick(c))return int(c.fault);
P_88e49_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88e49_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88e4eULL),c);
P_88e49_2:;
c.pc=0x1354c;goto dispatch;
P_88e49_3:;
goto L_88e4e;
}
L_88e4e:{ // FSTP dword ptr [EBP + -0x1c]
c.pc=0x88e4e;if(!sl_tick(c))return int(c.fault);
P_88e4e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_88e4e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_ext80_to_f32(sl_get<10>(c.reg,sizeof(c.reg),0x1100,c)),c);
P_88e4e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_88e4e_3:;
sl_put<10>(c.reg,sizeof(c.reg),0x1100,sl_get<10>(c.reg,sizeof(c.reg),0x1110,c),c);
P_88e4e_4:;
sl_put<10>(c.reg,sizeof(c.reg),0x1110,sl_get<10>(c.reg,sizeof(c.reg),0x1120,c),c);
P_88e4e_5:;
sl_put<10>(c.reg,sizeof(c.reg),0x1120,sl_get<10>(c.reg,sizeof(c.reg),0x1130,c),c);
P_88e4e_6:;
sl_put<10>(c.reg,sizeof(c.reg),0x1130,sl_get<10>(c.reg,sizeof(c.reg),0x1140,c),c);
P_88e4e_7:;
sl_put<10>(c.reg,sizeof(c.reg),0x1140,sl_get<10>(c.reg,sizeof(c.reg),0x1150,c),c);
P_88e4e_8:;
sl_put<10>(c.reg,sizeof(c.reg),0x1150,sl_get<10>(c.reg,sizeof(c.reg),0x1160,c),c);
P_88e4e_9:;
sl_put<10>(c.reg,sizeof(c.reg),0x1160,sl_get<10>(c.reg,sizeof(c.reg),0x1170,c),c);
P_88e4e_10:;
goto L_88e51;
}
L_88e51:{ // MOVSS XMM1,dword ptr [EBP + -0x1c]
c.pc=0x88e51;if(!sl_tick(c))return int(c.fault);
P_88e51_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_88e51_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88e51_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88e51_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_88e51_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_88e51_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_88e51_6:;
goto L_88e56;
}
L_88e56:{ // MOV ECX,dword ptr [ESI + 0x124]
c.pc=0x88e56;if(!sl_tick(c))return int(c.fault);
P_88e56_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x124ULL)),c);
P_88e56_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88e56_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88e56_3:;
goto L_88e5c;
}
L_88e5c:{ // MOV EDI,dword ptr [ESI + 0x204]
c.pc=0x88e5c;if(!sl_tick(c))return int(c.fault);
P_88e5c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x204ULL)),c);
P_88e5c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88e5c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88e5c_3:;
goto L_88e62;
}
L_88e62:{ // MOVSS XMM4,dword ptr [EBX + 0x3ff92]
c.pc=0x88e62;if(!sl_tick(c))return int(c.fault);
P_88e62_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x3ff92ULL)),c);
P_88e62_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88e62_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1300,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88e62_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1304,SlU(0x0ULL),c);
P_88e62_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1308,SlU(0x0ULL),c);
P_88e62_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x130c,SlU(0x0ULL),c);
P_88e62_6:;
goto L_88e6a;
}
L_88e6a:{ // JMP 0x00088bab
c.pc=0x88e6a;if(!sl_tick(c))return int(c.fault);
P_88e6a_0:;
goto L_88bab;
P_88e6a_1:;
goto L_88e6f;
}
L_88e6f:{ // MOV dword ptr [ESI + 0x220],0x1
c.pc=0x88e6f;if(!sl_tick(c))return int(c.fault);
P_88e6f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x220ULL)),c);
P_88e6f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x1ULL),c);
P_88e6f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_88e6f_3:;
goto L_88e79;
}
L_88e79:{ // JMP 0x00088c0d
c.pc=0x88e79;if(!sl_tick(c))return int(c.fault);
P_88e79_0:;
goto L_88c0d;
P_88e79_1:;
goto L_88e7e;
}
L_88e7e:{ // MOV dword ptr [ESP + 0x4],EDX
c.pc=0x88e7e;if(!sl_tick(c))return int(c.fault);
P_88e7e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_88e7e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_88e7e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88e7e_3:;
goto L_88e82;
}
L_88e82:{ // MOV dword ptr [ESP],ESI
c.pc=0x88e82;if(!sl_tick(c))return int(c.fault);
P_88e82_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88e82_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88e82_2:;
goto L_88e85;
}
L_88e85:{ // CALL 0x0001354c
c.pc=0x88e85;if(!sl_tick(c))return int(c.fault);
P_88e85_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88e85_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88e8aULL),c);
P_88e85_2:;
c.pc=0x1354c;goto dispatch;
P_88e85_3:;
goto L_88e8a;
}
L_88e8a:{ // FSTP dword ptr [EBP + -0x1c]
c.pc=0x88e8a;if(!sl_tick(c))return int(c.fault);
P_88e8a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_88e8a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,sl_ext80_to_f32(sl_get<10>(c.reg,sizeof(c.reg),0x1100,c)),c);
P_88e8a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_88e8a_3:;
sl_put<10>(c.reg,sizeof(c.reg),0x1100,sl_get<10>(c.reg,sizeof(c.reg),0x1110,c),c);
P_88e8a_4:;
sl_put<10>(c.reg,sizeof(c.reg),0x1110,sl_get<10>(c.reg,sizeof(c.reg),0x1120,c),c);
P_88e8a_5:;
sl_put<10>(c.reg,sizeof(c.reg),0x1120,sl_get<10>(c.reg,sizeof(c.reg),0x1130,c),c);
P_88e8a_6:;
sl_put<10>(c.reg,sizeof(c.reg),0x1130,sl_get<10>(c.reg,sizeof(c.reg),0x1140,c),c);
P_88e8a_7:;
sl_put<10>(c.reg,sizeof(c.reg),0x1140,sl_get<10>(c.reg,sizeof(c.reg),0x1150,c),c);
P_88e8a_8:;
sl_put<10>(c.reg,sizeof(c.reg),0x1150,sl_get<10>(c.reg,sizeof(c.reg),0x1160,c),c);
P_88e8a_9:;
sl_put<10>(c.reg,sizeof(c.reg),0x1160,sl_get<10>(c.reg,sizeof(c.reg),0x1170,c),c);
P_88e8a_10:;
goto L_88e8d;
}
L_88e8d:{ // MOVSS XMM1,dword ptr [EBP + -0x1c]
c.pc=0x88e8d;if(!sl_tick(c))return int(c.fault);
P_88e8d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_88e8d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88e8d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88e8d_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1244,SlU(0x0ULL),c);
P_88e8d_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x1248,SlU(0x0ULL),c);
P_88e8d_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x124c,SlU(0x0ULL),c);
P_88e8d_6:;
goto L_88e92;
}
L_88e92:{ // MOV ECX,dword ptr [ESI + 0x124]
c.pc=0x88e92;if(!sl_tick(c))return int(c.fault);
P_88e92_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x124ULL)),c);
P_88e92_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_88e92_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88e92_3:;
goto L_88e98;
}
L_88e98:{ // JMP 0x00088d41
c.pc=0x88e98;if(!sl_tick(c))return int(c.fault);
P_88e98_0:;
goto L_88d41;
P_88e98_1:;
c.pc=0x88e9d;goto dispatch;
}
L_88e9e:{ // PUSH EBP
c.pc=0x88e9e;if(!sl_tick(c))return int(c.fault);
P_88e9e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_88e9e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88e9e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88e9e_3:;
goto L_88e9f;
}
L_88e9f:{ // MOV EBP,ESP
c.pc=0x88e9f;if(!sl_tick(c))return int(c.fault);
P_88e9f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_88e9f_1:;
goto L_88ea1;
}
L_88ea1:{ // PUSH ESI
c.pc=0x88ea1;if(!sl_tick(c))return int(c.fault);
P_88ea1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88ea1_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88ea1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88ea1_3:;
goto L_88ea2;
}
L_88ea2:{ // PUSH EBX
c.pc=0x88ea2;if(!sl_tick(c))return int(c.fault);
P_88ea2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_88ea2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88ea2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88ea2_3:;
goto L_88ea3;
}
L_88ea3:{ // SUB ESP,0x10
c.pc=0x88ea3;if(!sl_tick(c))return int(c.fault);
P_88ea3_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x10ULL)),c);
P_88ea3_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x10ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_88ea3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x10ULL)),c);
P_88ea3_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88ea3_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_88ea3_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_88ea3_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88ea3_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88ea3_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88ea3_9:;
goto L_88ea6;
}
L_88ea6:{ // CALL 0x000c086c
c.pc=0x88ea6;if(!sl_tick(c))return int(c.fault);
P_88ea6_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88ea6_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88eabULL),c);
P_88ea6_2:;
c.pc=0xc086c;goto dispatch;
P_88ea6_3:;
goto L_88eab;
}
L_88eab:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0x88eab;if(!sl_tick(c))return int(c.fault);
P_88eab_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_88eab_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88eab_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88eab_3:;
goto L_88eae;
}
L_88eae:{ // MOV dword ptr [ESP],ESI
c.pc=0x88eae;if(!sl_tick(c))return int(c.fault);
P_88eae_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88eae_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88eae_2:;
goto L_88eb1;
}
L_88eb1:{ // CALL 0x00031e98
c.pc=0x88eb1;if(!sl_tick(c))return int(c.fault);
P_88eb1_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88eb1_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88eb6ULL),c);
P_88eb1_2:;
c.pc=0x31e98;goto dispatch;
P_88eb1_3:;
goto L_88eb6;
}
L_88eb6:{ // LEA EAX,[EBX + 0x69cbd]
c.pc=0x88eb6;if(!sl_tick(c))return int(c.fault);
P_88eb6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x69cbdULL)),c);
P_88eb6_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_88eb6_2:;
goto L_88ebc;
}
L_88ebc:{ // MOV dword ptr [ESI],EAX
c.pc=0x88ebc;if(!sl_tick(c))return int(c.fault);
P_88ebc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88ebc_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88ebc_2:;
goto L_88ebe;
}
L_88ebe:{ // MOV dword ptr [ESI + 0x1e4],0x0
c.pc=0x88ebe;if(!sl_tick(c))return int(c.fault);
P_88ebe_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1e4ULL)),c);
P_88ebe_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_88ebe_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_88ebe_3:;
goto L_88ec8;
}
L_88ec8:{ // MOV dword ptr [ESI + 0x1e0],0x0
c.pc=0x88ec8;if(!sl_tick(c))return int(c.fault);
P_88ec8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1e0ULL)),c);
P_88ec8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_88ec8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_88ec8_3:;
goto L_88ed2;
}
L_88ed2:{ // MOV dword ptr [ESI + 0x1f0],0x0
c.pc=0x88ed2;if(!sl_tick(c))return int(c.fault);
P_88ed2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x1f0ULL)),c);
P_88ed2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_88ed2_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_88ed2_3:;
goto L_88edc;
}
L_88edc:{ // ADD ESP,0x10
c.pc=0x88edc;if(!sl_tick(c))return int(c.fault);
P_88edc_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_88edc_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_88edc_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_88edc_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88edc_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_88edc_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_88edc_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88edc_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88edc_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88edc_9:;
goto L_88edf;
}
L_88edf:{ // POP EBX
c.pc=0x88edf;if(!sl_tick(c))return int(c.fault);
P_88edf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88edf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88edf_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88edf_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88edf_4:;
goto L_88ee0;
}
L_88ee0:{ // POP ESI
c.pc=0x88ee0;if(!sl_tick(c))return int(c.fault);
P_88ee0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88ee0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88ee0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88ee0_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88ee0_4:;
goto L_88ee1;
}
L_88ee1:{ // POP EBP
c.pc=0x88ee1;if(!sl_tick(c))return int(c.fault);
P_88ee1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88ee1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88ee1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88ee1_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88ee1_4:;
goto L_88ee2;
}
L_88ee2:{ // RET
c.pc=0x88ee2;if(!sl_tick(c))return int(c.fault);
P_88ee2_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88ee2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88ee2_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_88ee2_3:;
c.pc=0x88ee3;goto dispatch;
}
L_88ee4:{ // PUSH EBP
c.pc=0x88ee4;if(!sl_tick(c))return int(c.fault);
P_88ee4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_88ee4_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88ee4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88ee4_3:;
goto L_88ee5;
}
L_88ee5:{ // MOV EBP,ESP
c.pc=0x88ee5;if(!sl_tick(c))return int(c.fault);
P_88ee5_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_88ee5_1:;
goto L_88ee7;
}
L_88ee7:{ // CALL 0x000c0b42
c.pc=0x88ee7;if(!sl_tick(c))return int(c.fault);
P_88ee7_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88ee7_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88eecULL),c);
P_88ee7_2:;
c.pc=0xc0b42;goto dispatch;
P_88ee7_3:;
goto L_88eec;
}
L_88eec:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0x88eec;if(!sl_tick(c))return int(c.fault);
P_88eec_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_88eec_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88eec_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88eec_3:;
goto L_88eef;
}
L_88eef:{ // LEA EAX,[ECX + 0x69c7c]
c.pc=0x88eef;if(!sl_tick(c))return int(c.fault);
P_88eef_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) + SlU(0x69c7cULL)),c);
P_88eef_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_88eef_2:;
goto L_88ef5;
}
L_88ef5:{ // MOV dword ptr [EDX],EAX
c.pc=0x88ef5;if(!sl_tick(c))return int(c.fault);
P_88ef5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88ef5_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88ef5_2:;
goto L_88ef7;
}
L_88ef7:{ // MOV dword ptr [EBP + 0x8],EDX
c.pc=0x88ef7;if(!sl_tick(c))return int(c.fault);
P_88ef7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_88ef7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_88ef7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88ef7_3:;
goto L_88efa;
}
L_88efa:{ // POP EBP
c.pc=0x88efa;if(!sl_tick(c))return int(c.fault);
P_88efa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88efa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88efa_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88efa_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88efa_4:;
goto L_88efb;
}
L_88efb:{ // JMP 0x00031edc
c.pc=0x88efb;if(!sl_tick(c))return int(c.fault);
P_88efb_0:;
c.pc=0x31edc;goto dispatch;
P_88efb_1:;
goto L_88f00;
}
L_88f00:{ // PUSH EBP
c.pc=0x88f00;if(!sl_tick(c))return int(c.fault);
P_88f00_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_88f00_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88f00_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88f00_3:;
goto L_88f01;
}
L_88f01:{ // MOV EBP,ESP
c.pc=0x88f01;if(!sl_tick(c))return int(c.fault);
P_88f01_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_88f01_1:;
goto L_88f03;
}
L_88f03:{ // PUSH ESI
c.pc=0x88f03;if(!sl_tick(c))return int(c.fault);
P_88f03_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88f03_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88f03_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88f03_3:;
goto L_88f04;
}
L_88f04:{ // PUSH EBX
c.pc=0x88f04;if(!sl_tick(c))return int(c.fault);
P_88f04_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_88f04_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88f04_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88f04_3:;
goto L_88f05;
}
L_88f05:{ // SUB ESP,0x10
c.pc=0x88f05;if(!sl_tick(c))return int(c.fault);
P_88f05_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x10ULL)),c);
P_88f05_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x10ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_88f05_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x10ULL)),c);
P_88f05_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88f05_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_88f05_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_88f05_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88f05_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88f05_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88f05_9:;
goto L_88f08;
}
L_88f08:{ // CALL 0x000c086c
c.pc=0x88f08;if(!sl_tick(c))return int(c.fault);
P_88f08_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88f08_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88f0dULL),c);
P_88f08_2:;
c.pc=0xc086c;goto dispatch;
P_88f08_3:;
goto L_88f0d;
}
L_88f0d:{ // MOV ESI,dword ptr [EBP + 0x8]
c.pc=0x88f0d;if(!sl_tick(c))return int(c.fault);
P_88f0d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_88f0d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88f0d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88f0d_3:;
goto L_88f10;
}
L_88f10:{ // LEA EAX,[EBX + 0x69c5b]
c.pc=0x88f10;if(!sl_tick(c))return int(c.fault);
P_88f10_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x69c5bULL)),c);
P_88f10_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_88f10_2:;
goto L_88f16;
}
L_88f16:{ // MOV dword ptr [ESI],EAX
c.pc=0x88f16;if(!sl_tick(c))return int(c.fault);
P_88f16_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88f16_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88f16_2:;
goto L_88f18;
}
L_88f18:{ // MOV dword ptr [ESP],ESI
c.pc=0x88f18;if(!sl_tick(c))return int(c.fault);
P_88f18_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88f18_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88f18_2:;
goto L_88f1b;
}
L_88f1b:{ // CALL 0x00031edc
c.pc=0x88f1b;if(!sl_tick(c))return int(c.fault);
P_88f1b_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88f1b_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88f20ULL),c);
P_88f1b_2:;
c.pc=0x31edc;goto dispatch;
P_88f1b_3:;
goto L_88f20;
}
L_88f20:{ // MOV dword ptr [EBP + 0x8],ESI
c.pc=0x88f20;if(!sl_tick(c))return int(c.fault);
P_88f20_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_88f20_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88f20_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88f20_3:;
goto L_88f23;
}
L_88f23:{ // ADD ESP,0x10
c.pc=0x88f23;if(!sl_tick(c))return int(c.fault);
P_88f23_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_88f23_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(0x10ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x10ULL)))&(SlU(1)<<31))!=0),c);
P_88f23_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x10ULL)),c);
P_88f23_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88f23_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_88f23_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_88f23_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88f23_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88f23_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88f23_9:;
goto L_88f26;
}
L_88f26:{ // POP EBX
c.pc=0x88f26;if(!sl_tick(c))return int(c.fault);
P_88f26_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88f26_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88f26_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88f26_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88f26_4:;
goto L_88f27;
}
L_88f27:{ // POP ESI
c.pc=0x88f27;if(!sl_tick(c))return int(c.fault);
P_88f27_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88f27_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88f27_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88f27_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88f27_4:;
goto L_88f28;
}
L_88f28:{ // POP EBP
c.pc=0x88f28;if(!sl_tick(c))return int(c.fault);
P_88f28_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88f28_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88f28_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88f28_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88f28_4:;
goto L_88f29;
}
L_88f29:{ // JMP 0x00103032
c.pc=0x88f29;if(!sl_tick(c))return int(c.fault);
P_88f29_0:;
c.pc=0x103032;goto dispatch;
P_88f29_1:;
goto L_88f2e;
}
L_88f2e:{ // PUSH EBP
c.pc=0x88f2e;if(!sl_tick(c))return int(c.fault);
P_88f2e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_88f2e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88f2e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88f2e_3:;
goto L_88f2f;
}
L_88f2f:{ // MOV EBP,ESP
c.pc=0x88f2f;if(!sl_tick(c))return int(c.fault);
P_88f2f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_88f2f_1:;
goto L_88f31;
}
L_88f31:{ // PUSH EDI
c.pc=0x88f31;if(!sl_tick(c))return int(c.fault);
P_88f31_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_88f31_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88f31_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88f31_3:;
goto L_88f32;
}
L_88f32:{ // PUSH ESI
c.pc=0x88f32;if(!sl_tick(c))return int(c.fault);
P_88f32_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_88f32_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88f32_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88f32_3:;
goto L_88f33;
}
L_88f33:{ // PUSH EBX
c.pc=0x88f33;if(!sl_tick(c))return int(c.fault);
P_88f33_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_88f33_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88f33_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_88f33_3:;
goto L_88f34;
}
L_88f34:{ // SUB ESP,0x4c
c.pc=0x88f34;if(!sl_tick(c))return int(c.fault);
P_88f34_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x4cULL)),c);
P_88f34_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x4cULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x4cULL)))&(SlU(1)<<31))!=0),c);
P_88f34_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4cULL)),c);
P_88f34_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88f34_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_88f34_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_88f34_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88f34_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88f34_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88f34_9:;
goto L_88f37;
}
L_88f37:{ // CALL 0x000c086c
c.pc=0x88f37;if(!sl_tick(c))return int(c.fault);
P_88f37_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88f37_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88f3cULL),c);
P_88f37_2:;
c.pc=0xc086c;goto dispatch;
P_88f37_3:;
goto L_88f3c;
}
L_88f3c:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0x88f3c;if(!sl_tick(c))return int(c.fault);
P_88f3c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_88f3c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88f3c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88f3c_3:;
goto L_88f3f;
}
L_88f3f:{ // MOV dword ptr [EBP + -0x20],EAX
c.pc=0x88f3f;if(!sl_tick(c))return int(c.fault);
P_88f3f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_88f3f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88f3f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88f3f_3:;
goto L_88f42;
}
L_88f42:{ // MOV EDI,dword ptr [EBP + 0xc]
c.pc=0x88f42;if(!sl_tick(c))return int(c.fault);
P_88f42_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_88f42_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88f42_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88f42_3:;
goto L_88f45;
}
L_88f45:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0x88f45;if(!sl_tick(c))return int(c.fault);
P_88f45_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_88f45_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_88f45_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88f45_3:;
goto L_88f48;
}
L_88f48:{ // MOV dword ptr [EBP + -0x24],EDX
c.pc=0x88f48;if(!sl_tick(c))return int(c.fault);
P_88f48_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_88f48_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_88f48_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88f48_3:;
goto L_88f4b;
}
L_88f4b:{ // MOV EDX,dword ptr [EDI]
c.pc=0x88f4b;if(!sl_tick(c))return int(c.fault);
P_88f4b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_88f4b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88f4b_2:;
goto L_88f4d;
}
L_88f4d:{ // TEST EDX,EDX
c.pc=0x88f4d;if(!sl_tick(c))return int(c.fault);
P_88f4d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88f4d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88f4d_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_88f4d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88f4d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_88f4d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_88f4d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88f4d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88f4d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88f4d_9:;
goto L_88f4f;
}
L_88f4f:{ // JZ 0x000890a4
c.pc=0x88f4f;if(!sl_tick(c))return int(c.fault);
P_88f4f_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){c.pc=0x890a4;goto dispatch;}
P_88f4f_1:;
goto L_88f55;
}
L_88f55:{ // MOV EDX,EAX
c.pc=0x88f55;if(!sl_tick(c))return int(c.fault);
P_88f55_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88f55_1:;
goto L_88f57;
}
L_88f57:{ // MOV EAX,dword ptr [EDI]
c.pc=0x88f57;if(!sl_tick(c))return int(c.fault);
P_88f57_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_88f57_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_88f57_2:;
goto L_88f59;
}
L_88f59:{ // MOV dword ptr [EDX + 0x120],EAX
c.pc=0x88f59;if(!sl_tick(c))return int(c.fault);
P_88f59_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x120ULL)),c);
P_88f59_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88f59_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88f59_3:;
goto L_88f5f;
}
L_88f5f:{ // TEST EAX,EAX
c.pc=0x88f5f;if(!sl_tick(c))return int(c.fault);
P_88f5f_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88f5f_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88f5f_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_88f5f_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88f5f_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_88f5f_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_88f5f_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88f5f_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88f5f_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88f5f_9:;
goto L_88f61;
}
L_88f61:{ // JZ 0x00088f6f
c.pc=0x88f61;if(!sl_tick(c))return int(c.fault);
P_88f61_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_88f6f;}
P_88f61_1:;
goto L_88f63;
}
L_88f63:{ // MOV dword ptr [ESP],EAX
c.pc=0x88f63;if(!sl_tick(c))return int(c.fault);
P_88f63_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_88f63_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_88f63_2:;
goto L_88f66;
}
L_88f66:{ // CALL 0x00011c32
c.pc=0x88f66;if(!sl_tick(c))return int(c.fault);
P_88f66_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_88f66_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0x88f6bULL),c);
P_88f66_2:;
c.pc=0x11c32;goto dispatch;
P_88f66_3:;
goto L_88f6b;
}
L_88f6b:{ // TEST AL,AL
c.pc=0x88f6b;if(!sl_tick(c))return int(c.fault);
P_88f6b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_88f6b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_88f6b_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x54d80,(sl_get<1>(c.reg,sizeof(c.reg),0x0,c) & sl_get<1>(c.reg,sizeof(c.reg),0x0,c)),c);
P_88f6b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_88f6b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c) == SlU(0x0ULL)),c);
P_88f6b_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x54d80,c) & SlU(0xffULL)),c);
P_88f6b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88f6b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88f6b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88f6b_9:;
goto L_88f6d;
}
L_88f6d:{ // JZ 0x00088f77
c.pc=0x88f6d;if(!sl_tick(c))return int(c.fault);
P_88f6d_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){c.pc=0x88f77;goto dispatch;}
P_88f6d_1:;
goto L_88f6f;
}
L_88f6f:{ // ADD ESP,0x4c
c.pc=0x88f6f;if(!sl_tick(c))return int(c.fault);
P_88f6f_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_88f6f_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4cULL)))&(SlU(0x4cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x4cULL)))&(SlU(1)<<31))!=0),c);
P_88f6f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4cULL)),c);
P_88f6f_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_88f6f_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_88f6f_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_88f6f_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_88f6f_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_88f6f_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_88f6f_9:;
goto L_88f72;
}
L_88f72:{ // POP EBX
c.pc=0x88f72;if(!sl_tick(c))return int(c.fault);
P_88f72_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88f72_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88f72_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88f72_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88f72_4:;
goto L_88f73;
}
L_88f73:{ // POP ESI
c.pc=0x88f73;if(!sl_tick(c))return int(c.fault);
P_88f73_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88f73_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88f73_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88f73_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88f73_4:;
goto L_88f74;
}
L_88f74:{ // POP EDI
c.pc=0x88f74;if(!sl_tick(c))return int(c.fault);
P_88f74_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_88f74_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_88f74_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_88f74_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_88f74_4:;
c.pc=0x88f75;goto dispatch;
}
}
