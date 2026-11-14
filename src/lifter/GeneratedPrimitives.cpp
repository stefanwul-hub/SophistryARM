// Generated from raw Ghidra instruction p-code; not decompiler pseudo-C.
// Source SHA-256: 17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12
#include "LifterRuntime.h"
int sl_execute(SlCpu& c,SlU32 entry,SlU32 stop,SlU64 limit){
c.pc=entry;c.stop=stop;c.steps=0;c.limit=limit;c.fault=0;goto dispatch;
dispatch:
if(c.pc==c.stop)return int(c.fault);
if(c.fault)return int(c.fault);
switch(c.pc){
case 0x1f63:goto L_1f63;
case 0x1f65:goto L_1f65;
case 0x6321:goto L_6321;
case 0x762f:goto L_762f;
case 0x12fb8:goto L_12fb8;
case 0x12fc8:goto L_12fc8;
case 0x23f4c:goto L_23f4c;
case 0x2dae4:goto L_2dae4;
case 0x4debc:goto L_4debc;
case 0x4dec0:goto L_4dec0;
case 0x7ec24:goto L_7ec24;
case 0xae22f:goto L_ae22f;
default:break;}
if(!sl_tick(c))return int(c.fault);
for(SlU32 h=0;h<c.hook_count;++h){if(c.hooks[h].address==c.pc){c.hooks[h].function(c.hooks[h].user,c.pc,&c);goto dispatch;}}
c.fault=3;return 3;
L_1f63: { // SAR EAX,0x1
c.pc=0x1f63;if(!sl_tick(c))return int(c.fault);
P_1f63_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x4f400,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0x1ULL)),c);
P_1f63_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x4f400,c) != SlU(0x0ULL)),c);
P_1f63_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_1f63_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_sright(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),SlU(0x1ULL),32),c);
P_1f63_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1f63_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_1f63_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_1f63_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1f63_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1f63_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1f63_10:;
goto L_1f65;
}
L_1f65: { // CMP dword ptr [EBP + -0x1c],EAX
c.pc=0x1f65;if(!sl_tick(c))return int(c.fault);
P_1f65_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_1f65_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_1f65_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_1f65_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_1f65_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x0,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x0,c)))&(SlU(1)<<31))!=0),c);
P_1f65_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_1f65_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_1f65_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_1f65_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_1f65_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_1f65_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_1f65_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_1f65_12:;
c.pc=0x1f68;goto dispatch;
}
L_6321: { // FLDZ
c.pc=0x6321;if(!sl_tick(c))return int(c.fault);
P_6321_0:;
sl_put<10>(c.temp,sizeof(c.temp),0x5aa00,sl_integer_to_ext80(SlU(0x0ULL),32),c);
P_6321_1:;
sl_put<10>(c.reg,sizeof(c.reg),0x1170,sl_get<10>(c.reg,sizeof(c.reg),0x1160,c),c);
P_6321_2:;
sl_put<10>(c.reg,sizeof(c.reg),0x1160,sl_get<10>(c.reg,sizeof(c.reg),0x1150,c),c);
P_6321_3:;
sl_put<10>(c.reg,sizeof(c.reg),0x1150,sl_get<10>(c.reg,sizeof(c.reg),0x1140,c),c);
P_6321_4:;
sl_put<10>(c.reg,sizeof(c.reg),0x1140,sl_get<10>(c.reg,sizeof(c.reg),0x1130,c),c);
P_6321_5:;
sl_put<10>(c.reg,sizeof(c.reg),0x1130,sl_get<10>(c.reg,sizeof(c.reg),0x1120,c),c);
P_6321_6:;
sl_put<10>(c.reg,sizeof(c.reg),0x1120,sl_get<10>(c.reg,sizeof(c.reg),0x1110,c),c);
P_6321_7:;
sl_put<10>(c.reg,sizeof(c.reg),0x1110,sl_get<10>(c.reg,sizeof(c.reg),0x1100,c),c);
P_6321_8:;
sl_put<10>(c.reg,sizeof(c.reg),0x1100,sl_get<10>(c.temp,sizeof(c.temp),0x5aa00,c),c);
P_6321_9:;
c.pc=0x6323;goto dispatch;
}
L_762f: { // IDIV dword ptr [EBP + -0x40]
c.pc=0x762f;if(!sl_tick(c))return int(c.fault);
P_762f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc0ULL)),c);
P_762f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_762f_2:;
sl_put<8>(c.temp,sizeof(c.temp),0x39380,SlU(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),32)),c);
P_762f_3:;
sl_put<8>(c.temp,sizeof(c.temp),0x39400,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_762f_4:;
sl_put<8>(c.temp,sizeof(c.temp),0x39480,sl_lshift(sl_get<8>(c.temp,sizeof(c.temp),0x39400,c),SlU(0x20ULL)),c);
P_762f_5:;
sl_put<8>(c.temp,sizeof(c.temp),0x39500,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_762f_6:;
sl_put<8>(c.temp,sizeof(c.temp),0x39600,(sl_get<8>(c.temp,sizeof(c.temp),0x39480,c) | sl_get<8>(c.temp,sizeof(c.temp),0x39500,c)),c);
P_762f_7:;
{const SlU result=sl_divide(c,sl_get<8>(c.temp,sizeof(c.temp),0x39600,c),sl_get<8>(c.temp,sizeof(c.temp),0x39380,c),64,32,true,false);if(c.fault)return int(c.fault);sl_put<8>(c.temp,sizeof(c.temp),0x39700,result,c);}
P_762f_8:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x39700,c),8*SlU(0x0ULL)),c);
P_762f_9:;
{const SlU result=sl_divide(c,sl_get<8>(c.temp,sizeof(c.temp),0x39600,c),sl_get<8>(c.temp,sizeof(c.temp),0x39380,c),64,32,true,true);if(c.fault)return int(c.fault);sl_put<8>(c.temp,sizeof(c.temp),0x39880,result,c);}
P_762f_10:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_rshift(sl_get<8>(c.temp,sizeof(c.temp),0x39880,c),8*SlU(0x0ULL)),c);
P_762f_11:;
c.pc=0x7632;goto dispatch;
}
L_12fb8: { // INT3
c.pc=0x12fb8;if(!sl_tick(c))return int(c.fault);
P_12fb8_0:;
c.fault=8;return 8; // explicit x86 trap / privileged I/O
P_12fb8_1:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3c400,c));goto dispatch;
P_12fb8_2:;
c.pc=SlU32(SlU(0x0ULL));goto dispatch;
P_12fb8_3:;
c.pc=0x12fb9;goto dispatch;
}
L_12fc8: { // FLD1
c.pc=0x12fc8;if(!sl_tick(c))return int(c.fault);
P_12fc8_0:;
sl_put<10>(c.temp,sizeof(c.temp),0x5a100,sl_integer_to_ext80(SlU(0x1ULL),32),c);
P_12fc8_1:;
sl_put<10>(c.reg,sizeof(c.reg),0x1170,sl_get<10>(c.reg,sizeof(c.reg),0x1160,c),c);
P_12fc8_2:;
sl_put<10>(c.reg,sizeof(c.reg),0x1160,sl_get<10>(c.reg,sizeof(c.reg),0x1150,c),c);
P_12fc8_3:;
sl_put<10>(c.reg,sizeof(c.reg),0x1150,sl_get<10>(c.reg,sizeof(c.reg),0x1140,c),c);
P_12fc8_4:;
sl_put<10>(c.reg,sizeof(c.reg),0x1140,sl_get<10>(c.reg,sizeof(c.reg),0x1130,c),c);
P_12fc8_5:;
sl_put<10>(c.reg,sizeof(c.reg),0x1130,sl_get<10>(c.reg,sizeof(c.reg),0x1120,c),c);
P_12fc8_6:;
sl_put<10>(c.reg,sizeof(c.reg),0x1120,sl_get<10>(c.reg,sizeof(c.reg),0x1110,c),c);
P_12fc8_7:;
sl_put<10>(c.reg,sizeof(c.reg),0x1110,sl_get<10>(c.reg,sizeof(c.reg),0x1100,c),c);
P_12fc8_8:;
sl_put<10>(c.reg,sizeof(c.reg),0x1100,sl_get<10>(c.temp,sizeof(c.temp),0x5a100,c),c);
P_12fc8_9:;
c.pc=0x12fca;goto dispatch;
}
L_23f4c: { // ADD.LOCK byte ptr [EAX],AL
c.pc=0x23f4c;if(!sl_tick(c))return int(c.fault);
P_23f4c_0:;
c.fault=10;return 10; // unsupported shared-memory atomic instruction
P_23f4c_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_23f4c_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<1>(c.temp,sizeof(c.temp),0x5100,c)+sl_get<1>(c.reg,sizeof(c.reg),0x0,c))&sl_mask(8))<sl_get<1>(c.temp,sizeof(c.temp),0x5100,c)),c);
P_23f4c_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_23f4c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x5100,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x5100,c)+sl_get<1>(c.reg,sizeof(c.reg),0x0,c)))&(sl_get<1>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x5100,c)+sl_get<1>(c.reg,sizeof(c.reg),0x0,c)))&(SlU(1)<<7))!=0),c);
P_23f4c_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_23f4c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,(sl_get<1>(c.temp,sizeof(c.temp),0x5100,c) + sl_get<1>(c.reg,sizeof(c.reg),0x0,c)),c);
P_23f4c_7:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5100,c),c);
P_23f4c_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_23f4c_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x5100,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_23f4c_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_23f4c_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x5100,c) == SlU(0x0ULL)),c);
P_23f4c_12:;
sl_put<1>(c.temp,sizeof(c.temp),0x5100,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_23f4c_13:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x5100,c) & SlU(0xffULL)),c);
P_23f4c_14:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_23f4c_15:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_23f4c_16:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_23f4c_17:;
c.fault=10;return 10; // unsupported shared-memory atomic instruction
P_23f4c_18:;
c.pc=0x23f4f;goto dispatch;
}
L_2dae4: { // SAR EAX,CL
c.pc=0x2dae4;if(!sl_tick(c))return int(c.fault);
P_2dae4_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x4f600,(sl_get<1>(c.reg,sizeof(c.reg),0x4,c) & SlU(0x1fULL)),c);
P_2dae4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x4f680,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_2dae4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_sright(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),sl_get<1>(c.temp,sizeof(c.temp),0x4f600,c),32),c);
P_2dae4_3:;
sl_put<1>(c.temp,sizeof(c.temp),0x25680,(sl_get<1>(c.temp,sizeof(c.temp),0x4f600,c) != SlU(0x0ULL)),c);
P_2dae4_4:;
sl_put<1>(c.temp,sizeof(c.temp),0x25700,(sl_get<1>(c.temp,sizeof(c.temp),0x4f600,c) - SlU(0x1ULL)),c);
P_2dae4_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x25780,sl_sright(sl_get<4>(c.temp,sizeof(c.temp),0x4f680,c),sl_get<1>(c.temp,sizeof(c.temp),0x25700,c),32),c);
P_2dae4_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x25800,(sl_get<4>(c.temp,sizeof(c.temp),0x25780,c) & SlU(0x1ULL)),c);
P_2dae4_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x25900,(sl_get<4>(c.temp,sizeof(c.temp),0x25800,c) != SlU(0x0ULL)),c);
P_2dae4_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x25980,(!sl_get<1>(c.temp,sizeof(c.temp),0x25680,c)),c);
P_2dae4_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x25a00,(sl_get<1>(c.temp,sizeof(c.temp),0x25980,c) & sl_get<1>(c.reg,sizeof(c.reg),0x200,c)),c);
P_2dae4_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x25a80,(sl_get<1>(c.temp,sizeof(c.temp),0x25680,c) & sl_get<1>(c.temp,sizeof(c.temp),0x25900,c)),c);
P_2dae4_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x25a00,c) | sl_get<1>(c.temp,sizeof(c.temp),0x25a80,c)),c);
P_2dae4_12:;
sl_put<1>(c.temp,sizeof(c.temp),0x25c00,(sl_get<1>(c.temp,sizeof(c.temp),0x4f600,c) == SlU(0x1ULL)),c);
P_2dae4_13:;
sl_put<1>(c.temp,sizeof(c.temp),0x25c80,(!sl_get<1>(c.temp,sizeof(c.temp),0x25c00,c)),c);
P_2dae4_14:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(sl_get<1>(c.temp,sizeof(c.temp),0x25c80,c) & sl_get<1>(c.reg,sizeof(c.reg),0x20b,c)),c);
P_2dae4_15:;
sl_put<1>(c.temp,sizeof(c.temp),0x22b80,(sl_get<1>(c.temp,sizeof(c.temp),0x4f600,c) != SlU(0x0ULL)),c);
P_2dae4_16:;
sl_put<1>(c.temp,sizeof(c.temp),0x22c80,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_2dae4_17:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d00,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_2dae4_18:;
sl_put<1>(c.temp,sizeof(c.temp),0x22d80,(sl_get<1>(c.temp,sizeof(c.temp),0x22d00,c) & sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_2dae4_19:;
sl_put<1>(c.temp,sizeof(c.temp),0x22e00,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22c80,c)),c);
P_2dae4_20:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_get<1>(c.temp,sizeof(c.temp),0x22d80,c) | sl_get<1>(c.temp,sizeof(c.temp),0x22e00,c)),c);
P_2dae4_21:;
sl_put<1>(c.temp,sizeof(c.temp),0x22f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_2dae4_22:;
sl_put<1>(c.temp,sizeof(c.temp),0x23000,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_2dae4_23:;
sl_put<1>(c.temp,sizeof(c.temp),0x23080,(sl_get<1>(c.temp,sizeof(c.temp),0x23000,c) & sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_2dae4_24:;
sl_put<1>(c.temp,sizeof(c.temp),0x23100,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x22f80,c)),c);
P_2dae4_25:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x23080,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23100,c)),c);
P_2dae4_26:;
sl_put<4>(c.temp,sizeof(c.temp),0x23200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_2dae4_27:;
sl_put<1>(c.temp,sizeof(c.temp),0x23280,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x23200,c)),c);
P_2dae4_28:;
sl_put<1>(c.temp,sizeof(c.temp),0x23300,(sl_get<1>(c.temp,sizeof(c.temp),0x23280,c) & SlU(0x1ULL)),c);
P_2dae4_29:;
sl_put<1>(c.temp,sizeof(c.temp),0x23400,(sl_get<1>(c.temp,sizeof(c.temp),0x23300,c) == SlU(0x0ULL)),c);
P_2dae4_30:;
sl_put<1>(c.temp,sizeof(c.temp),0x23480,(!sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c)),c);
P_2dae4_31:;
sl_put<1>(c.temp,sizeof(c.temp),0x23500,(sl_get<1>(c.temp,sizeof(c.temp),0x23480,c) & sl_get<1>(c.reg,sizeof(c.reg),0x202,c)),c);
P_2dae4_32:;
sl_put<1>(c.temp,sizeof(c.temp),0x23580,(sl_get<1>(c.temp,sizeof(c.temp),0x22b80,c) & sl_get<1>(c.temp,sizeof(c.temp),0x23400,c)),c);
P_2dae4_33:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x23500,c) | sl_get<1>(c.temp,sizeof(c.temp),0x23580,c)),c);
P_2dae4_34:;
c.pc=0x2dae6;goto dispatch;
}
L_4debc: { // OUT 0x1,AL
c.pc=0x4debc;if(!sl_tick(c))return int(c.fault);
P_4debc_0:;
c.fault=8;return 8; // explicit x86 trap / privileged I/O
P_4debc_1:;
c.pc=0x4debe;goto dispatch;
}
L_4dec0: { // OUT 0x1,AL
c.pc=0x4dec0;if(!sl_tick(c))return int(c.fault);
P_4dec0_0:;
c.fault=8;return 8; // explicit x86 trap / privileged I/O
P_4dec0_1:;
c.pc=0x4dec2;goto dispatch;
}
L_7ec24: { // SQRTSS XMM1,XMM1
c.pc=0x7ec24;if(!sl_tick(c))return int(c.fault);
P_7ec24_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1240,sl_sqrt_f32(sl_get<4>(c.reg,sizeof(c.reg),0x1240,c)),c);
P_7ec24_1:;
c.pc=0x7ec28;goto dispatch;
}
L_ae22f: { // DIV dword ptr [EBP + -0xc]
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
c.pc=0xae232;goto dispatch;
}
}
