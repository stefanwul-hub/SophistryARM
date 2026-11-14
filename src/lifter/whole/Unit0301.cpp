// Generated static p-code lift; original i386 SHA-256: 17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12
#include "LifterRuntime.h"
int sl_unit_0301(SlCpu& c){
goto dispatch;
dispatch:
if(c.fault||c.pc==c.stop)return int(c.fault);
switch(c.pc){
case 0xa405d:goto L_a405d;
case 0xa4060:goto L_a4060;
case 0xa4065:goto L_a4065;
case 0xa406b:goto L_a406b;
case 0xa406f:goto L_a406f;
case 0xa4076:goto L_a4076;
case 0xa407b:goto L_a407b;
case 0xa4085:goto L_a4085;
case 0xa4088:goto L_a4088;
case 0xa4089:goto L_a4089;
case 0xa408a:goto L_a408a;
case 0xa408b:goto L_a408b;
case 0xa408c:goto L_a408c;
case 0xa40a0:goto L_a40a0;
case 0xa40a1:goto L_a40a1;
case 0xa40a3:goto L_a40a3;
case 0xa40a4:goto L_a40a4;
case 0xa40a5:goto L_a40a5;
case 0xa40a6:goto L_a40a6;
case 0xa40a9:goto L_a40a9;
case 0xa40ae:goto L_a40ae;
case 0xa40b1:goto L_a40b1;
case 0xa40b4:goto L_a40b4;
case 0xa40ba:goto L_a40ba;
case 0xa40bd:goto L_a40bd;
case 0xa40bf:goto L_a40bf;
case 0xa40c2:goto L_a40c2;
case 0xa40c4:goto L_a40c4;
case 0xa40c6:goto L_a40c6;
case 0xa40c8:goto L_a40c8;
case 0xa40ca:goto L_a40ca;
case 0xa40cd:goto L_a40cd;
case 0xa40cf:goto L_a40cf;
case 0xa40d1:goto L_a40d1;
case 0xa40d3:goto L_a40d3;
case 0xa40d5:goto L_a40d5;
case 0xa40d8:goto L_a40d8;
case 0xa40dc:goto L_a40dc;
case 0xa40df:goto L_a40df;
case 0xa40e2:goto L_a40e2;
case 0xa40e4:goto L_a40e4;
case 0xa40e6:goto L_a40e6;
case 0xa40e9:goto L_a40e9;
case 0xa40ec:goto L_a40ec;
case 0xa40ee:goto L_a40ee;
case 0xa40f0:goto L_a40f0;
case 0xa40f2:goto L_a40f2;
case 0xa40f4:goto L_a40f4;
case 0xa40f7:goto L_a40f7;
case 0xa40fa:goto L_a40fa;
case 0xa40fd:goto L_a40fd;
case 0xa4102:goto L_a4102;
case 0xa4104:goto L_a4104;
case 0xa4106:goto L_a4106;
case 0xa4109:goto L_a4109;
case 0xa4110:goto L_a4110;
case 0xa4117:goto L_a4117;
case 0xa411a:goto L_a411a;
case 0xa411c:goto L_a411c;
case 0xa411e:goto L_a411e;
case 0xa4120:goto L_a4120;
case 0xa4123:goto L_a4123;
case 0xa4126:goto L_a4126;
case 0xa4129:goto L_a4129;
case 0xa4130:goto L_a4130;
case 0xa4133:goto L_a4133;
case 0xa4136:goto L_a4136;
case 0xa4137:goto L_a4137;
case 0xa4138:goto L_a4138;
case 0xa4139:goto L_a4139;
case 0xa413a:goto L_a413a;
case 0xa4154:goto L_a4154;
case 0xa4155:goto L_a4155;
case 0xa4157:goto L_a4157;
case 0xa4158:goto L_a4158;
case 0xa4159:goto L_a4159;
case 0xa415a:goto L_a415a;
case 0xa415d:goto L_a415d;
case 0xa4162:goto L_a4162;
case 0xa4165:goto L_a4165;
case 0xa416b:goto L_a416b;
case 0xa416d:goto L_a416d;
case 0xa4170:goto L_a4170;
case 0xa4172:goto L_a4172;
case 0xa4174:goto L_a4174;
case 0xa4176:goto L_a4176;
case 0xa4179:goto L_a4179;
case 0xa417c:goto L_a417c;
case 0xa417f:goto L_a417f;
case 0xa4181:goto L_a4181;
case 0xa4183:goto L_a4183;
case 0xa4185:goto L_a4185;
case 0xa4187:goto L_a4187;
case 0xa418b:goto L_a418b;
case 0xa418e:goto L_a418e;
case 0xa4191:goto L_a4191;
case 0xa4193:goto L_a4193;
case 0xa4195:goto L_a4195;
case 0xa4198:goto L_a4198;
case 0xa419b:goto L_a419b;
case 0xa419d:goto L_a419d;
case 0xa419f:goto L_a419f;
case 0xa41a1:goto L_a41a1;
case 0xa41a3:goto L_a41a3;
case 0xa41a6:goto L_a41a6;
case 0xa41a9:goto L_a41a9;
case 0xa41ac:goto L_a41ac;
case 0xa41b1:goto L_a41b1;
case 0xa41b4:goto L_a41b4;
case 0xa41b6:goto L_a41b6;
case 0xa41b8:goto L_a41b8;
case 0xa41bf:goto L_a41bf;
case 0xa41c6:goto L_a41c6;
case 0xa41c9:goto L_a41c9;
case 0xa41cb:goto L_a41cb;
case 0xa41cd:goto L_a41cd;
case 0xa41cf:goto L_a41cf;
case 0xa41d2:goto L_a41d2;
case 0xa41d5:goto L_a41d5;
case 0xa41dc:goto L_a41dc;
case 0xa41df:goto L_a41df;
case 0xa41e4:goto L_a41e4;
case 0xa41e7:goto L_a41e7;
case 0xa41ea:goto L_a41ea;
case 0xa41eb:goto L_a41eb;
case 0xa41ec:goto L_a41ec;
case 0xa41ed:goto L_a41ed;
case 0xa41ee:goto L_a41ee;
case 0xa4206:goto L_a4206;
case 0xa4207:goto L_a4207;
case 0xa4209:goto L_a4209;
case 0xa420a:goto L_a420a;
case 0xa420b:goto L_a420b;
case 0xa420c:goto L_a420c;
case 0xa420f:goto L_a420f;
case 0xa4214:goto L_a4214;
case 0xa421b:goto L_a421b;
case 0xa4221:goto L_a4221;
case 0xa4227:goto L_a4227;
case 0xa4229:goto L_a4229;
case 0xa422f:goto L_a422f;
case 0xa4232:goto L_a4232;
case 0xa4238:goto L_a4238;
case 0xa423a:goto L_a423a;
case 0xa4240:goto L_a4240;
case 0xa4242:goto L_a4242;
case 0xa4245:goto L_a4245;
case 0xa4248:goto L_a4248;
case 0xa424b:goto L_a424b;
case 0xa4251:goto L_a4251;
case 0xa4258:goto L_a4258;
case 0xa425f:goto L_a425f;
case 0xa4261:goto L_a4261;
case 0xa4264:goto L_a4264;
case 0xa4268:goto L_a4268;
case 0xa426c:goto L_a426c;
case 0xa426f:goto L_a426f;
case 0xa4275:goto L_a4275;
case 0xa4278:goto L_a4278;
case 0xa427a:goto L_a427a;
case 0xa427e:goto L_a427e;
case 0xa4284:goto L_a4284;
case 0xa4288:goto L_a4288;
case 0xa428c:goto L_a428c;
case 0xa428f:goto L_a428f;
case 0xa4292:goto L_a4292;
case 0xa4295:goto L_a4295;
case 0xa4298:goto L_a4298;
case 0xa429a:goto L_a429a;
case 0xa42a2:goto L_a42a2;
case 0xa42a5:goto L_a42a5;
case 0xa42ab:goto L_a42ab;
case 0xa42ad:goto L_a42ad;
case 0xa42b0:goto L_a42b0;
case 0xa42b3:goto L_a42b3;
case 0xa42b9:goto L_a42b9;
case 0xa42bb:goto L_a42bb;
case 0xa42be:goto L_a42be;
case 0xa42c1:goto L_a42c1;
case 0xa42cb:goto L_a42cb;
case 0xa42cd:goto L_a42cd;
case 0xa42d0:goto L_a42d0;
case 0xa42d1:goto L_a42d1;
case 0xa42d2:goto L_a42d2;
case 0xa42d3:goto L_a42d3;
case 0xa42d4:goto L_a42d4;
case 0xa42d5:goto L_a42d5;
case 0xa42d8:goto L_a42d8;
case 0xa42df:goto L_a42df;
case 0xa42e4:goto L_a42e4;
case 0xa42e6:goto L_a42e6;
case 0xa42ea:goto L_a42ea;
case 0xa42f2:goto L_a42f2;
case 0xa42f5:goto L_a42f5;
case 0xa42f9:goto L_a42f9;
case 0xa42fc:goto L_a42fc;
case 0xa4301:goto L_a4301;
case 0xa4304:goto L_a4304;
case 0xa431c:goto L_a431c;
case 0xa431d:goto L_a431d;
case 0xa431f:goto L_a431f;
case 0xa4320:goto L_a4320;
case 0xa4321:goto L_a4321;
case 0xa4322:goto L_a4322;
case 0xa4325:goto L_a4325;
case 0xa432a:goto L_a432a;
case 0xa432e:goto L_a432e;
case 0xa4335:goto L_a4335;
case 0xa4337:goto L_a4337;
case 0xa433b:goto L_a433b;
case 0xa433d:goto L_a433d;
case 0xa4341:goto L_a4341;
case 0xa4347:goto L_a4347;
case 0xa434b:goto L_a434b;
case 0xa4351:goto L_a4351;
case 0xa4353:goto L_a4353;
case 0xa4356:goto L_a4356;
case 0xa4357:goto L_a4357;
case 0xa4358:goto L_a4358;
case 0xa4359:goto L_a4359;
case 0xa435a:goto L_a435a;
case 0xa435b:goto L_a435b;
case 0xa435e:goto L_a435e;
case 0xa4364:goto L_a4364;
case 0xa4366:goto L_a4366;
case 0xa436c:goto L_a436c;
case 0xa436e:goto L_a436e;
case 0xa4371:goto L_a4371;
case 0xa4374:goto L_a4374;
case 0xa4377:goto L_a4377;
case 0xa437d:goto L_a437d;
case 0xa4384:goto L_a4384;
case 0xa438b:goto L_a438b;
case 0xa438d:goto L_a438d;
case 0xa4390:goto L_a4390;
case 0xa4394:goto L_a4394;
case 0xa4398:goto L_a4398;
case 0xa439b:goto L_a439b;
case 0xa43a1:goto L_a43a1;
case 0xa43a4:goto L_a43a4;
case 0xa43a6:goto L_a43a6;
case 0xa43aa:goto L_a43aa;
case 0xa43b0:goto L_a43b0;
case 0xa43b4:goto L_a43b4;
case 0xa43b8:goto L_a43b8;
case 0xa43bb:goto L_a43bb;
case 0xa43be:goto L_a43be;
case 0xa43c1:goto L_a43c1;
case 0xa43c3:goto L_a43c3;
case 0xa43c6:goto L_a43c6;
case 0xa43c9:goto L_a43c9;
case 0xa43cb:goto L_a43cb;
case 0xa43ce:goto L_a43ce;
case 0xa43cf:goto L_a43cf;
case 0xa43d0:goto L_a43d0;
case 0xa43d1:goto L_a43d1;
case 0xa43d2:goto L_a43d2;
case 0xa43d3:goto L_a43d3;
case 0xa43d9:goto L_a43d9;
case 0xa43db:goto L_a43db;
case 0xa43dd:goto L_a43dd;
case 0xa43df:goto L_a43df;
case 0xa43e2:goto L_a43e2;
case 0xa43e5:goto L_a43e5;
case 0xa43ec:goto L_a43ec;
case 0xa43f1:goto L_a43f1;
case 0xa43f3:goto L_a43f3;
case 0xa43fa:goto L_a43fa;
case 0xa4400:goto L_a4400;
case 0xa4402:goto L_a4402;
case 0xa4405:goto L_a4405;
case 0xa4408:goto L_a4408;
case 0xa440f:goto L_a440f;
case 0xa4416:goto L_a4416;
case 0xa441d:goto L_a441d;
case 0xa4420:goto L_a4420;
case 0xa4424:goto L_a4424;
case 0xa4427:goto L_a4427;
case 0xa442a:goto L_a442a;
case 0xa442f:goto L_a442f;
case 0xa4433:goto L_a4433;
case 0xa4436:goto L_a4436;
case 0xa443c:goto L_a443c;
case 0xa443f:goto L_a443f;
case 0xa4445:goto L_a4445;
case 0xa4447:goto L_a4447;
case 0xa444d:goto L_a444d;
case 0xa444f:goto L_a444f;
case 0xa4452:goto L_a4452;
case 0xa4455:goto L_a4455;
case 0xa4458:goto L_a4458;
case 0xa445e:goto L_a445e;
case 0xa4465:goto L_a4465;
case 0xa446c:goto L_a446c;
case 0xa446e:goto L_a446e;
case 0xa4476:goto L_a4476;
case 0xa4479:goto L_a4479;
case 0xa447f:goto L_a447f;
case 0xa4482:goto L_a4482;
case 0xa4484:goto L_a4484;
case 0xa4487:goto L_a4487;
case 0xa448b:goto L_a448b;
case 0xa448f:goto L_a448f;
case 0xa4492:goto L_a4492;
case 0xa4498:goto L_a4498;
case 0xa449b:goto L_a449b;
case 0xa449d:goto L_a449d;
case 0xa44a1:goto L_a44a1;
case 0xa44a7:goto L_a44a7;
case 0xa44ab:goto L_a44ab;
case 0xa44af:goto L_a44af;
case 0xa44b2:goto L_a44b2;
case 0xa44b5:goto L_a44b5;
case 0xa44b8:goto L_a44b8;
case 0xa44ba:goto L_a44ba;
case 0xa44bd:goto L_a44bd;
case 0xa44c0:goto L_a44c0;
case 0xa44c5:goto L_a44c5;
case 0xa44c8:goto L_a44c8;
case 0xa44ce:goto L_a44ce;
case 0xa44d0:goto L_a44d0;
case 0xa44d6:goto L_a44d6;
case 0xa44d8:goto L_a44d8;
case 0xa44db:goto L_a44db;
case 0xa44de:goto L_a44de;
case 0xa44e1:goto L_a44e1;
case 0xa44e7:goto L_a44e7;
case 0xa44ee:goto L_a44ee;
case 0xa44f5:goto L_a44f5;
case 0xa44f7:goto L_a44f7;
case 0xa44fa:goto L_a44fa;
case 0xa44fe:goto L_a44fe;
case 0xa4502:goto L_a4502;
case 0xa4505:goto L_a4505;
case 0xa450b:goto L_a450b;
case 0xa450e:goto L_a450e;
case 0xa4510:goto L_a4510;
case 0xa4514:goto L_a4514;
case 0xa451a:goto L_a451a;
case 0xa451e:goto L_a451e;
case 0xa4522:goto L_a4522;
case 0xa4525:goto L_a4525;
case 0xa4528:goto L_a4528;
case 0xa452b:goto L_a452b;
case 0xa452e:goto L_a452e;
case 0xa4530:goto L_a4530;
case 0xa4538:goto L_a4538;
case 0xa453b:goto L_a453b;
case 0xa4541:goto L_a4541;
case 0xa4543:goto L_a4543;
case 0xa4546:goto L_a4546;
case 0xa4549:goto L_a4549;
case 0xa454f:goto L_a454f;
case 0xa4551:goto L_a4551;
case 0xa4554:goto L_a4554;
case 0xa4557:goto L_a4557;
case 0xa4561:goto L_a4561;
case 0xa4563:goto L_a4563;
case 0xa4566:goto L_a4566;
case 0xa4567:goto L_a4567;
case 0xa4568:goto L_a4568;
case 0xa4569:goto L_a4569;
case 0xa456a:goto L_a456a;
case 0xa456b:goto L_a456b;
case 0xa456e:goto L_a456e;
case 0xa4575:goto L_a4575;
case 0xa457a:goto L_a457a;
case 0xa457c:goto L_a457c;
case 0xa4580:goto L_a4580;
case 0xa4588:goto L_a4588;
case 0xa458b:goto L_a458b;
case 0xa458f:goto L_a458f;
case 0xa4592:goto L_a4592;
case 0xa4597:goto L_a4597;
case 0xa459a:goto L_a459a;
case 0xa459f:goto L_a459f;
case 0xa45a2:goto L_a45a2;
case 0xa45a9:goto L_a45a9;
case 0xa45ae:goto L_a45ae;
case 0xa45b0:goto L_a45b0;
case 0xa45b4:goto L_a45b4;
case 0xa45bc:goto L_a45bc;
case 0xa45bf:goto L_a45bf;
case 0xa45c3:goto L_a45c3;
case 0xa45c6:goto L_a45c6;
case 0xa45cb:goto L_a45cb;
case 0xa45ce:goto L_a45ce;
case 0xa45d3:goto L_a45d3;
case 0xa45d6:goto L_a45d6;
case 0xa45dd:goto L_a45dd;
case 0xa45e2:goto L_a45e2;
case 0xa45e4:goto L_a45e4;
case 0xa45e8:goto L_a45e8;
case 0xa45f0:goto L_a45f0;
case 0xa45f3:goto L_a45f3;
case 0xa45f7:goto L_a45f7;
case 0xa45fa:goto L_a45fa;
case 0xa45ff:goto L_a45ff;
case 0xa4602:goto L_a4602;
case 0xa4654:goto L_a4654;
case 0xa4655:goto L_a4655;
case 0xa4657:goto L_a4657;
case 0xa4658:goto L_a4658;
case 0xa4659:goto L_a4659;
case 0xa465c:goto L_a465c;
case 0xa465f:goto L_a465f;
case 0xa4666:goto L_a4666;
case 0xa466c:goto L_a466c;
case 0xa4670:goto L_a4670;
case 0xa4676:goto L_a4676;
case 0xa4679:goto L_a4679;
case 0xa467d:goto L_a467d;
case 0xa4683:goto L_a4683;
case 0xa4686:goto L_a4686;
case 0xa4688:goto L_a4688;
case 0xa468e:goto L_a468e;
case 0xa4692:goto L_a4692;
case 0xa4695:goto L_a4695;
case 0xa469c:goto L_a469c;
case 0xa46a3:goto L_a46a3;
case 0xa46aa:goto L_a46aa;
case 0xa46b1:goto L_a46b1;
case 0xa46b4:goto L_a46b4;
case 0xa46b7:goto L_a46b7;
case 0xa46ba:goto L_a46ba;
case 0xa46bd:goto L_a46bd;
case 0xa46c0:goto L_a46c0;
case 0xa46c3:goto L_a46c3;
case 0xa46c6:goto L_a46c6;
case 0xa46c9:goto L_a46c9;
case 0xa46cc:goto L_a46cc;
case 0xa46cf:goto L_a46cf;
case 0xa46d2:goto L_a46d2;
case 0xa46d4:goto L_a46d4;
case 0xa46d7:goto L_a46d7;
case 0xa46d9:goto L_a46d9;
case 0xa46dc:goto L_a46dc;
case 0xa46df:goto L_a46df;
case 0xa46e1:goto L_a46e1;
case 0xa46e4:goto L_a46e4;
case 0xa46e7:goto L_a46e7;
case 0xa46ea:goto L_a46ea;
case 0xa46ed:goto L_a46ed;
case 0xa46f0:goto L_a46f0;
case 0xa46f3:goto L_a46f3;
case 0xa46f6:goto L_a46f6;
case 0xa46f9:goto L_a46f9;
case 0xa46fb:goto L_a46fb;
case 0xa46fe:goto L_a46fe;
case 0xa4701:goto L_a4701;
case 0xa4704:goto L_a4704;
case 0xa4707:goto L_a4707;
case 0xa470a:goto L_a470a;
case 0xa470d:goto L_a470d;
case 0xa4710:goto L_a4710;
case 0xa4713:goto L_a4713;
case 0xa4719:goto L_a4719;
case 0xa471c:goto L_a471c;
case 0xa471f:goto L_a471f;
case 0xa4723:goto L_a4723;
case 0xa4726:goto L_a4726;
case 0xa4729:goto L_a4729;
case 0xa472c:goto L_a472c;
case 0xa4730:goto L_a4730;
case 0xa4733:goto L_a4733;
case 0xa4736:goto L_a4736;
case 0xa4739:goto L_a4739;
case 0xa473c:goto L_a473c;
case 0xa473e:goto L_a473e;
case 0xa4741:goto L_a4741;
case 0xa4744:goto L_a4744;
case 0xa4747:goto L_a4747;
case 0xa474a:goto L_a474a;
case 0xa474e:goto L_a474e;
case 0xa4751:goto L_a4751;
case 0xa4754:goto L_a4754;
case 0xa4758:goto L_a4758;
case 0xa475b:goto L_a475b;
case 0xa475e:goto L_a475e;
case 0xa4763:goto L_a4763;
case 0xa4766:goto L_a4766;
case 0xa4769:goto L_a4769;
case 0xa476b:goto L_a476b;
case 0xa476d:goto L_a476d;
case 0xa476f:goto L_a476f;
case 0xa4772:goto L_a4772;
case 0xa4775:goto L_a4775;
case 0xa4777:goto L_a4777;
case 0xa4779:goto L_a4779;
case 0xa477d:goto L_a477d;
case 0xa4780:goto L_a4780;
case 0xa4784:goto L_a4784;
case 0xa4787:goto L_a4787;
case 0xa478a:goto L_a478a;
case 0xa478f:goto L_a478f;
case 0xa4792:goto L_a4792;
case 0xa4796:goto L_a4796;
case 0xa4799:goto L_a4799;
case 0xa479c:goto L_a479c;
case 0xa47a1:goto L_a47a1;
case 0xa47a5:goto L_a47a5;
case 0xa47a7:goto L_a47a7;
case 0xa47aa:goto L_a47aa;
case 0xa47ab:goto L_a47ab;
case 0xa47ac:goto L_a47ac;
case 0xa47ad:goto L_a47ad;
case 0xa47ae:goto L_a47ae;
case 0xa47b0:goto L_a47b0;
case 0xa47b4:goto L_a47b4;
case 0xa47ba:goto L_a47ba;
case 0xa47be:goto L_a47be;
case 0xa47c1:goto L_a47c1;
default:return 0;}
L_a405d:{ // MOV dword ptr [ESP],EDI
c.pc=0xa405d;if(!sl_tick(c))return int(c.fault);
P_a405d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a405d_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a405d_2:;
goto L_a4060;
}
L_a4060:{ // CALL 0x0009dff8
c.pc=0xa4060;if(!sl_tick(c))return int(c.fault);
P_a4060_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4060_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4065ULL),c);
P_a4060_2:;
c.pc=0x9dff8;goto dispatch;
P_a4060_3:;
goto L_a4065;
}
L_a4065:{ // LEA EAX,[EBX + 0x5e87e]
c.pc=0xa4065;if(!sl_tick(c))return int(c.fault);
P_a4065_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x5e87eULL)),c);
P_a4065_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_a4065_2:;
goto L_a406b;
}
L_a406b:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xa406b;if(!sl_tick(c))return int(c.fault);
P_a406b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a406b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a406b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a406b_3:;
goto L_a406f;
}
L_a406f:{ // MOV dword ptr [ESP],0x73797376
c.pc=0xa406f;if(!sl_tick(c))return int(c.fault);
P_a406f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x73797376ULL),c);
P_a406f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a406f_2:;
goto L_a4076;
}
L_a4076:{ // CALL 0x001034e7
c.pc=0xa4076;if(!sl_tick(c))return int(c.fault);
P_a4076_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4076_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa407bULL),c);
P_a4076_2:;
c.pc=0x1034e7;goto dispatch;
P_a4076_3:;
goto L_a407b;
}
L_a407b:{ // MOV dword ptr [EDI + 0x94],0x0
c.pc=0xa407b;if(!sl_tick(c))return int(c.fault);
P_a407b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x94ULL)),c);
P_a407b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a407b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a407b_3:;
goto L_a4085;
}
L_a4085:{ // ADD ESP,0x1c
c.pc=0xa4085;if(!sl_tick(c))return int(c.fault);
P_a4085_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x1cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4085_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x1cULL)))&(SlU(0x1cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x1cULL)))&(SlU(1)<<31))!=0),c);
P_a4085_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x1cULL)),c);
P_a4085_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4085_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_a4085_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_a4085_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4085_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4085_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4085_9:;
goto L_a4088;
}
L_a4088:{ // POP EBX
c.pc=0xa4088;if(!sl_tick(c))return int(c.fault);
P_a4088_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a4088_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a4088_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a4088_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a4088_4:;
goto L_a4089;
}
L_a4089:{ // POP ESI
c.pc=0xa4089;if(!sl_tick(c))return int(c.fault);
P_a4089_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a4089_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a4089_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a4089_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a4089_4:;
goto L_a408a;
}
L_a408a:{ // POP EDI
c.pc=0xa408a;if(!sl_tick(c))return int(c.fault);
P_a408a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a408a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a408a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a408a_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a408a_4:;
goto L_a408b;
}
L_a408b:{ // POP EBP
c.pc=0xa408b;if(!sl_tick(c))return int(c.fault);
P_a408b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a408b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a408b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a408b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a408b_4:;
goto L_a408c;
}
L_a408c:{ // RET
c.pc=0xa408c;if(!sl_tick(c))return int(c.fault);
P_a408c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a408c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a408c_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_a408c_3:;
c.pc=0xa408d;goto dispatch;
}
L_a40a0:{ // PUSH EBP
c.pc=0xa40a0;if(!sl_tick(c))return int(c.fault);
P_a40a0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_a40a0_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a40a0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a40a0_3:;
goto L_a40a1;
}
L_a40a1:{ // MOV EBP,ESP
c.pc=0xa40a1;if(!sl_tick(c))return int(c.fault);
P_a40a1_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_a40a1_1:;
goto L_a40a3;
}
L_a40a3:{ // PUSH EDI
c.pc=0xa40a3;if(!sl_tick(c))return int(c.fault);
P_a40a3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a40a3_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a40a3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a40a3_3:;
goto L_a40a4;
}
L_a40a4:{ // PUSH ESI
c.pc=0xa40a4;if(!sl_tick(c))return int(c.fault);
P_a40a4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a40a4_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a40a4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a40a4_3:;
goto L_a40a5;
}
L_a40a5:{ // PUSH EBX
c.pc=0xa40a5;if(!sl_tick(c))return int(c.fault);
P_a40a5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_a40a5_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a40a5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a40a5_3:;
goto L_a40a6;
}
L_a40a6:{ // SUB ESP,0x2c
c.pc=0xa40a6;if(!sl_tick(c))return int(c.fault);
P_a40a6_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x2cULL)),c);
P_a40a6_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x2cULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x2cULL)))&(SlU(1)<<31))!=0),c);
P_a40a6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x2cULL)),c);
P_a40a6_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a40a6_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_a40a6_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_a40a6_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a40a6_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a40a6_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a40a6_9:;
goto L_a40a9;
}
L_a40a9:{ // CALL 0x000c086c
c.pc=0xa40a9;if(!sl_tick(c))return int(c.fault);
P_a40a9_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a40a9_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa40aeULL),c);
P_a40a9_2:;
c.pc=0xc086c;goto dispatch;
P_a40a9_3:;
goto L_a40ae;
}
L_a40ae:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0xa40ae;if(!sl_tick(c))return int(c.fault);
P_a40ae_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_a40ae_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a40ae_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a40ae_3:;
goto L_a40b1;
}
L_a40b1:{ // MOV dword ptr [EBP + -0x1c],EAX
c.pc=0xa40b1;if(!sl_tick(c))return int(c.fault);
P_a40b1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_a40b1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a40b1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a40b1_3:;
goto L_a40b4;
}
L_a40b4:{ // LEA EAX,[EBX + 0x5021a]
c.pc=0xa40b4;if(!sl_tick(c))return int(c.fault);
P_a40b4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x5021aULL)),c);
P_a40b4_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_a40b4_2:;
goto L_a40ba;
}
L_a40ba:{ // MOV EDX,dword ptr [EBP + -0x1c]
c.pc=0xa40ba;if(!sl_tick(c))return int(c.fault);
P_a40ba_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_a40ba_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a40ba_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a40ba_3:;
goto L_a40bd;
}
L_a40bd:{ // MOV dword ptr [EDX],EAX
c.pc=0xa40bd;if(!sl_tick(c))return int(c.fault);
P_a40bd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a40bd_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a40bd_2:;
goto L_a40bf;
}
L_a40bf:{ // MOV ESI,dword ptr [EDX + 0x3c]
c.pc=0xa40bf;if(!sl_tick(c))return int(c.fault);
P_a40bf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x3cULL)),c);
P_a40bf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a40bf_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a40bf_3:;
goto L_a40c2;
}
L_a40c2:{ // TEST ESI,ESI
c.pc=0xa40c2;if(!sl_tick(c))return int(c.fault);
P_a40c2_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a40c2_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a40c2_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_a40c2_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a40c2_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a40c2_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a40c2_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a40c2_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a40c2_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a40c2_9:;
goto L_a40c4;
}
L_a40c4:{ // JNZ 0x000a40ca
c.pc=0xa40c4;if(!sl_tick(c))return int(c.fault);
P_a40c4_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_a40c4_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_a40ca;}
P_a40c4_2:;
goto L_a40c6;
}
L_a40c6:{ // JMP 0x000a4106
c.pc=0xa40c6;if(!sl_tick(c))return int(c.fault);
P_a40c6_0:;
goto L_a4106;
P_a40c6_1:;
goto L_a40c8;
}
L_a40c8:{ // MOV ESI,EDI
c.pc=0xa40c8;if(!sl_tick(c))return int(c.fault);
P_a40c8_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a40c8_1:;
goto L_a40ca;
}
L_a40ca:{ // MOV EDI,dword ptr [ESI + 0x4]
c.pc=0xa40ca;if(!sl_tick(c))return int(c.fault);
P_a40ca_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x4ULL)),c);
P_a40ca_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a40ca_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a40ca_3:;
goto L_a40cd;
}
L_a40cd:{ // MOV EDX,dword ptr [ESI]
c.pc=0xa40cd;if(!sl_tick(c))return int(c.fault);
P_a40cd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_a40cd_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a40cd_2:;
goto L_a40cf;
}
L_a40cf:{ // TEST EDX,EDX
c.pc=0xa40cf;if(!sl_tick(c))return int(c.fault);
P_a40cf_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a40cf_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a40cf_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a40cf_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a40cf_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a40cf_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a40cf_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a40cf_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a40cf_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a40cf_9:;
goto L_a40d1;
}
L_a40d1:{ // JZ 0x000a40fa
c.pc=0xa40d1;if(!sl_tick(c))return int(c.fault);
P_a40d1_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a40fa;}
P_a40d1_1:;
goto L_a40d3;
}
L_a40d3:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa40d3;if(!sl_tick(c))return int(c.fault);
P_a40d3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a40d3_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a40d3_2:;
goto L_a40d5;
}
L_a40d5:{ // MOV ECX,dword ptr [EBP + -0x1c]
c.pc=0xa40d5;if(!sl_tick(c))return int(c.fault);
P_a40d5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_a40d5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a40d5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a40d5_3:;
goto L_a40d8;
}
L_a40d8:{ // MOV dword ptr [ESP + 0x4],ECX
c.pc=0xa40d8;if(!sl_tick(c))return int(c.fault);
P_a40d8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a40d8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_a40d8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a40d8_3:;
goto L_a40dc;
}
L_a40dc:{ // MOV dword ptr [ESP],EDX
c.pc=0xa40dc;if(!sl_tick(c))return int(c.fault);
P_a40dc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a40dc_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a40dc_2:;
goto L_a40df;
}
L_a40df:{ // CALL dword ptr [EAX + 0x7c]
c.pc=0xa40df;if(!sl_tick(c))return int(c.fault);
P_a40df_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x7cULL)),c);
P_a40df_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a40df_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a40df_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a40df_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa40e2ULL),c);
P_a40df_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a40df_6:;
goto L_a40e2;
}
L_a40e2:{ // MOV EAX,dword ptr [ESI]
c.pc=0xa40e2;if(!sl_tick(c))return int(c.fault);
P_a40e2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_a40e2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a40e2_2:;
goto L_a40e4;
}
L_a40e4:{ // MOV EDX,dword ptr [EAX]
c.pc=0xa40e4;if(!sl_tick(c))return int(c.fault);
P_a40e4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_a40e4_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a40e4_2:;
goto L_a40e6;
}
L_a40e6:{ // MOV dword ptr [ESP],EAX
c.pc=0xa40e6;if(!sl_tick(c))return int(c.fault);
P_a40e6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a40e6_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a40e6_2:;
goto L_a40e9;
}
L_a40e9:{ // CALL dword ptr [EDX + 0x8]
c.pc=0xa40e9;if(!sl_tick(c))return int(c.fault);
P_a40e9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x8ULL)),c);
P_a40e9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a40e9_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a40e9_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a40e9_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa40ecULL),c);
P_a40e9_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a40e9_6:;
goto L_a40ec;
}
L_a40ec:{ // MOV EDX,dword ptr [ESI]
c.pc=0xa40ec;if(!sl_tick(c))return int(c.fault);
P_a40ec_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_a40ec_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a40ec_2:;
goto L_a40ee;
}
L_a40ee:{ // TEST EDX,EDX
c.pc=0xa40ee;if(!sl_tick(c))return int(c.fault);
P_a40ee_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a40ee_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a40ee_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a40ee_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a40ee_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a40ee_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a40ee_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a40ee_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a40ee_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a40ee_9:;
goto L_a40f0;
}
L_a40f0:{ // JZ 0x000a40fa
c.pc=0xa40f0;if(!sl_tick(c))return int(c.fault);
P_a40f0_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a40fa;}
P_a40f0_1:;
goto L_a40f2;
}
L_a40f2:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa40f2;if(!sl_tick(c))return int(c.fault);
P_a40f2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a40f2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a40f2_2:;
goto L_a40f4;
}
L_a40f4:{ // MOV dword ptr [ESP],EDX
c.pc=0xa40f4;if(!sl_tick(c))return int(c.fault);
P_a40f4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a40f4_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a40f4_2:;
goto L_a40f7;
}
L_a40f7:{ // CALL dword ptr [EAX + 0x8]
c.pc=0xa40f7;if(!sl_tick(c))return int(c.fault);
P_a40f7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_a40f7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a40f7_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a40f7_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a40f7_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa40faULL),c);
P_a40f7_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a40f7_6:;
goto L_a40fa;
}
L_a40fa:{ // MOV dword ptr [ESP],ESI
c.pc=0xa40fa;if(!sl_tick(c))return int(c.fault);
P_a40fa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a40fa_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a40fa_2:;
goto L_a40fd;
}
L_a40fd:{ // CALL 0x00103032
c.pc=0xa40fd;if(!sl_tick(c))return int(c.fault);
P_a40fd_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a40fd_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4102ULL),c);
P_a40fd_2:;
c.pc=0x103032;goto dispatch;
P_a40fd_3:;
goto L_a4102;
}
L_a4102:{ // TEST EDI,EDI
c.pc=0xa4102;if(!sl_tick(c))return int(c.fault);
P_a4102_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a4102_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a4102_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) & sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c);
P_a4102_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4102_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a4102_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a4102_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4102_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4102_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4102_9:;
goto L_a4104;
}
L_a4104:{ // JNZ 0x000a40c8
c.pc=0xa4104;if(!sl_tick(c))return int(c.fault);
P_a4104_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_a4104_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_a40c8;}
P_a4104_2:;
goto L_a4106;
}
L_a4106:{ // MOV EAX,dword ptr [EBP + -0x1c]
c.pc=0xa4106;if(!sl_tick(c))return int(c.fault);
P_a4106_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_a4106_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4106_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4106_3:;
goto L_a4109;
}
L_a4109:{ // MOV dword ptr [EAX + 0x3c],0x0
c.pc=0xa4109;if(!sl_tick(c))return int(c.fault);
P_a4109_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x3cULL)),c);
P_a4109_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a4109_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a4109_3:;
goto L_a4110;
}
L_a4110:{ // MOV dword ptr [EAX + 0x40],0x0
c.pc=0xa4110;if(!sl_tick(c))return int(c.fault);
P_a4110_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x40ULL)),c);
P_a4110_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a4110_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a4110_3:;
goto L_a4117;
}
L_a4117:{ // MOV EDX,dword ptr [EAX + 0x48]
c.pc=0xa4117;if(!sl_tick(c))return int(c.fault);
P_a4117_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x48ULL)),c);
P_a4117_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4117_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4117_3:;
goto L_a411a;
}
L_a411a:{ // TEST EDX,EDX
c.pc=0xa411a;if(!sl_tick(c))return int(c.fault);
P_a411a_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a411a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a411a_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a411a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a411a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a411a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a411a_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a411a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a411a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a411a_9:;
goto L_a411c;
}
L_a411c:{ // JZ 0x000a4126
c.pc=0xa411c;if(!sl_tick(c))return int(c.fault);
P_a411c_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a4126;}
P_a411c_1:;
goto L_a411e;
}
L_a411e:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa411e;if(!sl_tick(c))return int(c.fault);
P_a411e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a411e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a411e_2:;
goto L_a4120;
}
L_a4120:{ // MOV dword ptr [ESP],EDX
c.pc=0xa4120;if(!sl_tick(c))return int(c.fault);
P_a4120_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a4120_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4120_2:;
goto L_a4123;
}
L_a4123:{ // CALL dword ptr [EAX + 0x8]
c.pc=0xa4123;if(!sl_tick(c))return int(c.fault);
P_a4123_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_a4123_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4123_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4123_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4123_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4126ULL),c);
P_a4123_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a4123_6:;
goto L_a4126;
}
L_a4126:{ // MOV EDX,dword ptr [EBP + -0x1c]
c.pc=0xa4126;if(!sl_tick(c))return int(c.fault);
P_a4126_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_a4126_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4126_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4126_3:;
goto L_a4129;
}
L_a4129:{ // MOV dword ptr [EDX + 0x48],0x0
c.pc=0xa4129;if(!sl_tick(c))return int(c.fault);
P_a4129_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x48ULL)),c);
P_a4129_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a4129_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a4129_3:;
goto L_a4130;
}
L_a4130:{ // MOV dword ptr [EBP + 0x8],EDX
c.pc=0xa4130;if(!sl_tick(c))return int(c.fault);
P_a4130_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_a4130_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a4130_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4130_3:;
goto L_a4133;
}
L_a4133:{ // ADD ESP,0x2c
c.pc=0xa4133;if(!sl_tick(c))return int(c.fault);
P_a4133_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4133_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL)))&(SlU(0x2cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL)))&(SlU(1)<<31))!=0),c);
P_a4133_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x2cULL)),c);
P_a4133_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4133_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_a4133_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_a4133_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4133_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4133_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4133_9:;
goto L_a4136;
}
L_a4136:{ // POP EBX
c.pc=0xa4136;if(!sl_tick(c))return int(c.fault);
P_a4136_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a4136_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a4136_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a4136_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a4136_4:;
goto L_a4137;
}
L_a4137:{ // POP ESI
c.pc=0xa4137;if(!sl_tick(c))return int(c.fault);
P_a4137_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a4137_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a4137_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a4137_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a4137_4:;
goto L_a4138;
}
L_a4138:{ // POP EDI
c.pc=0xa4138;if(!sl_tick(c))return int(c.fault);
P_a4138_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a4138_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a4138_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a4138_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a4138_4:;
goto L_a4139;
}
L_a4139:{ // POP EBP
c.pc=0xa4139;if(!sl_tick(c))return int(c.fault);
P_a4139_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a4139_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a4139_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a4139_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a4139_4:;
goto L_a413a;
}
L_a413a:{ // JMP 0x000a34ec
c.pc=0xa413a;if(!sl_tick(c))return int(c.fault);
P_a413a_0:;
c.pc=0xa34ec;goto dispatch;
P_a413a_1:;
c.pc=0xa413f;goto dispatch;
}
L_a4154:{ // PUSH EBP
c.pc=0xa4154;if(!sl_tick(c))return int(c.fault);
P_a4154_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_a4154_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4154_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a4154_3:;
goto L_a4155;
}
L_a4155:{ // MOV EBP,ESP
c.pc=0xa4155;if(!sl_tick(c))return int(c.fault);
P_a4155_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_a4155_1:;
goto L_a4157;
}
L_a4157:{ // PUSH EDI
c.pc=0xa4157;if(!sl_tick(c))return int(c.fault);
P_a4157_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a4157_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4157_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a4157_3:;
goto L_a4158;
}
L_a4158:{ // PUSH ESI
c.pc=0xa4158;if(!sl_tick(c))return int(c.fault);
P_a4158_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a4158_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4158_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a4158_3:;
goto L_a4159;
}
L_a4159:{ // PUSH EBX
c.pc=0xa4159;if(!sl_tick(c))return int(c.fault);
P_a4159_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_a4159_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4159_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a4159_3:;
goto L_a415a;
}
L_a415a:{ // SUB ESP,0x2c
c.pc=0xa415a;if(!sl_tick(c))return int(c.fault);
P_a415a_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x2cULL)),c);
P_a415a_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x2cULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x2cULL)))&(SlU(1)<<31))!=0),c);
P_a415a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x2cULL)),c);
P_a415a_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a415a_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_a415a_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_a415a_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a415a_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a415a_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a415a_9:;
goto L_a415d;
}
L_a415d:{ // CALL 0x000c086c
c.pc=0xa415d;if(!sl_tick(c))return int(c.fault);
P_a415d_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a415d_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4162ULL),c);
P_a415d_2:;
c.pc=0xc086c;goto dispatch;
P_a415d_3:;
goto L_a4162;
}
L_a4162:{ // MOV EDI,dword ptr [EBP + 0x8]
c.pc=0xa4162;if(!sl_tick(c))return int(c.fault);
P_a4162_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_a4162_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4162_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4162_3:;
goto L_a4165;
}
L_a4165:{ // LEA EAX,[EBX + 0x50166]
c.pc=0xa4165;if(!sl_tick(c))return int(c.fault);
P_a4165_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x50166ULL)),c);
P_a4165_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_a4165_2:;
goto L_a416b;
}
L_a416b:{ // MOV dword ptr [EDI],EAX
c.pc=0xa416b;if(!sl_tick(c))return int(c.fault);
P_a416b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a416b_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a416b_2:;
goto L_a416d;
}
L_a416d:{ // MOV ESI,dword ptr [EDI + 0x3c]
c.pc=0xa416d;if(!sl_tick(c))return int(c.fault);
P_a416d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x3cULL)),c);
P_a416d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a416d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a416d_3:;
goto L_a4170;
}
L_a4170:{ // TEST ESI,ESI
c.pc=0xa4170;if(!sl_tick(c))return int(c.fault);
P_a4170_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a4170_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a4170_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) & sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_a4170_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4170_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a4170_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a4170_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4170_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4170_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4170_9:;
goto L_a4172;
}
L_a4172:{ // JNZ 0x000a4179
c.pc=0xa4172;if(!sl_tick(c))return int(c.fault);
P_a4172_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_a4172_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_a4179;}
P_a4172_2:;
goto L_a4174;
}
L_a4174:{ // JMP 0x000a41b8
c.pc=0xa4174;if(!sl_tick(c))return int(c.fault);
P_a4174_0:;
goto L_a41b8;
P_a4174_1:;
goto L_a4176;
}
L_a4176:{ // MOV ESI,dword ptr [EBP + -0x1c]
c.pc=0xa4176;if(!sl_tick(c))return int(c.fault);
P_a4176_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_a4176_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4176_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4176_3:;
goto L_a4179;
}
L_a4179:{ // MOV EAX,dword ptr [ESI + 0x4]
c.pc=0xa4179;if(!sl_tick(c))return int(c.fault);
P_a4179_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x4ULL)),c);
P_a4179_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4179_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4179_3:;
goto L_a417c;
}
L_a417c:{ // MOV dword ptr [EBP + -0x1c],EAX
c.pc=0xa417c;if(!sl_tick(c))return int(c.fault);
P_a417c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_a417c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a417c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a417c_3:;
goto L_a417f;
}
L_a417f:{ // MOV EDX,dword ptr [ESI]
c.pc=0xa417f;if(!sl_tick(c))return int(c.fault);
P_a417f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_a417f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a417f_2:;
goto L_a4181;
}
L_a4181:{ // TEST EDX,EDX
c.pc=0xa4181;if(!sl_tick(c))return int(c.fault);
P_a4181_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a4181_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a4181_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a4181_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4181_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a4181_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a4181_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4181_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4181_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4181_9:;
goto L_a4183;
}
L_a4183:{ // JZ 0x000a41a9
c.pc=0xa4183;if(!sl_tick(c))return int(c.fault);
P_a4183_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a41a9;}
P_a4183_1:;
goto L_a4185;
}
L_a4185:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa4185;if(!sl_tick(c))return int(c.fault);
P_a4185_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a4185_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4185_2:;
goto L_a4187;
}
L_a4187:{ // MOV dword ptr [ESP + 0x4],EDI
c.pc=0xa4187;if(!sl_tick(c))return int(c.fault);
P_a4187_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4187_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a4187_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4187_3:;
goto L_a418b;
}
L_a418b:{ // MOV dword ptr [ESP],EDX
c.pc=0xa418b;if(!sl_tick(c))return int(c.fault);
P_a418b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a418b_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a418b_2:;
goto L_a418e;
}
L_a418e:{ // CALL dword ptr [EAX + 0x7c]
c.pc=0xa418e;if(!sl_tick(c))return int(c.fault);
P_a418e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x7cULL)),c);
P_a418e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a418e_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a418e_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a418e_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4191ULL),c);
P_a418e_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a418e_6:;
goto L_a4191;
}
L_a4191:{ // MOV EAX,dword ptr [ESI]
c.pc=0xa4191;if(!sl_tick(c))return int(c.fault);
P_a4191_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_a4191_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4191_2:;
goto L_a4193;
}
L_a4193:{ // MOV EDX,dword ptr [EAX]
c.pc=0xa4193;if(!sl_tick(c))return int(c.fault);
P_a4193_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_a4193_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4193_2:;
goto L_a4195;
}
L_a4195:{ // MOV dword ptr [ESP],EAX
c.pc=0xa4195;if(!sl_tick(c))return int(c.fault);
P_a4195_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4195_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4195_2:;
goto L_a4198;
}
L_a4198:{ // CALL dword ptr [EDX + 0x8]
c.pc=0xa4198;if(!sl_tick(c))return int(c.fault);
P_a4198_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x8ULL)),c);
P_a4198_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4198_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4198_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4198_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa419bULL),c);
P_a4198_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a4198_6:;
goto L_a419b;
}
L_a419b:{ // MOV EDX,dword ptr [ESI]
c.pc=0xa419b;if(!sl_tick(c))return int(c.fault);
P_a419b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c),c);
P_a419b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a419b_2:;
goto L_a419d;
}
L_a419d:{ // TEST EDX,EDX
c.pc=0xa419d;if(!sl_tick(c))return int(c.fault);
P_a419d_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a419d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a419d_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a419d_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a419d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a419d_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a419d_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a419d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a419d_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a419d_9:;
goto L_a419f;
}
L_a419f:{ // JZ 0x000a41a9
c.pc=0xa419f;if(!sl_tick(c))return int(c.fault);
P_a419f_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a41a9;}
P_a419f_1:;
goto L_a41a1;
}
L_a41a1:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa41a1;if(!sl_tick(c))return int(c.fault);
P_a41a1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a41a1_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a41a1_2:;
goto L_a41a3;
}
L_a41a3:{ // MOV dword ptr [ESP],EDX
c.pc=0xa41a3;if(!sl_tick(c))return int(c.fault);
P_a41a3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a41a3_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a41a3_2:;
goto L_a41a6;
}
L_a41a6:{ // CALL dword ptr [EAX + 0x8]
c.pc=0xa41a6;if(!sl_tick(c))return int(c.fault);
P_a41a6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_a41a6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a41a6_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a41a6_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a41a6_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa41a9ULL),c);
P_a41a6_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a41a6_6:;
goto L_a41a9;
}
L_a41a9:{ // MOV dword ptr [ESP],ESI
c.pc=0xa41a9;if(!sl_tick(c))return int(c.fault);
P_a41a9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a41a9_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a41a9_2:;
goto L_a41ac;
}
L_a41ac:{ // CALL 0x00103032
c.pc=0xa41ac;if(!sl_tick(c))return int(c.fault);
P_a41ac_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a41ac_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa41b1ULL),c);
P_a41ac_2:;
c.pc=0x103032;goto dispatch;
P_a41ac_3:;
goto L_a41b1;
}
L_a41b1:{ // MOV EAX,dword ptr [EBP + -0x1c]
c.pc=0xa41b1;if(!sl_tick(c))return int(c.fault);
P_a41b1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_a41b1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a41b1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a41b1_3:;
goto L_a41b4;
}
L_a41b4:{ // TEST EAX,EAX
c.pc=0xa41b4;if(!sl_tick(c))return int(c.fault);
P_a41b4_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a41b4_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a41b4_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_a41b4_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a41b4_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a41b4_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a41b4_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a41b4_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a41b4_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a41b4_9:;
goto L_a41b6;
}
L_a41b6:{ // JNZ 0x000a4176
c.pc=0xa41b6;if(!sl_tick(c))return int(c.fault);
P_a41b6_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_a41b6_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_a4176;}
P_a41b6_2:;
goto L_a41b8;
}
L_a41b8:{ // MOV dword ptr [EDI + 0x3c],0x0
c.pc=0xa41b8;if(!sl_tick(c))return int(c.fault);
P_a41b8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x3cULL)),c);
P_a41b8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a41b8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a41b8_3:;
goto L_a41bf;
}
L_a41bf:{ // MOV dword ptr [EDI + 0x40],0x0
c.pc=0xa41bf;if(!sl_tick(c))return int(c.fault);
P_a41bf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x40ULL)),c);
P_a41bf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a41bf_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a41bf_3:;
goto L_a41c6;
}
L_a41c6:{ // MOV EDX,dword ptr [EDI + 0x48]
c.pc=0xa41c6;if(!sl_tick(c))return int(c.fault);
P_a41c6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x48ULL)),c);
P_a41c6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a41c6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a41c6_3:;
goto L_a41c9;
}
L_a41c9:{ // TEST EDX,EDX
c.pc=0xa41c9;if(!sl_tick(c))return int(c.fault);
P_a41c9_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a41c9_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a41c9_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a41c9_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a41c9_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a41c9_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a41c9_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a41c9_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a41c9_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a41c9_9:;
goto L_a41cb;
}
L_a41cb:{ // JZ 0x000a41d5
c.pc=0xa41cb;if(!sl_tick(c))return int(c.fault);
P_a41cb_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a41d5;}
P_a41cb_1:;
goto L_a41cd;
}
L_a41cd:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa41cd;if(!sl_tick(c))return int(c.fault);
P_a41cd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a41cd_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a41cd_2:;
goto L_a41cf;
}
L_a41cf:{ // MOV dword ptr [ESP],EDX
c.pc=0xa41cf;if(!sl_tick(c))return int(c.fault);
P_a41cf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a41cf_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a41cf_2:;
goto L_a41d2;
}
L_a41d2:{ // CALL dword ptr [EAX + 0x8]
c.pc=0xa41d2;if(!sl_tick(c))return int(c.fault);
P_a41d2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_a41d2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a41d2_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a41d2_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a41d2_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa41d5ULL),c);
P_a41d2_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a41d2_6:;
goto L_a41d5;
}
L_a41d5:{ // MOV dword ptr [EDI + 0x48],0x0
c.pc=0xa41d5;if(!sl_tick(c))return int(c.fault);
P_a41d5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) + SlU(0x48ULL)),c);
P_a41d5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a41d5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a41d5_3:;
goto L_a41dc;
}
L_a41dc:{ // MOV dword ptr [ESP],EDI
c.pc=0xa41dc;if(!sl_tick(c))return int(c.fault);
P_a41dc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a41dc_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a41dc_2:;
goto L_a41df;
}
L_a41df:{ // CALL 0x000a34ec
c.pc=0xa41df;if(!sl_tick(c))return int(c.fault);
P_a41df_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a41df_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa41e4ULL),c);
P_a41df_2:;
c.pc=0xa34ec;goto dispatch;
P_a41df_3:;
goto L_a41e4;
}
L_a41e4:{ // MOV dword ptr [EBP + 0x8],EDI
c.pc=0xa41e4;if(!sl_tick(c))return int(c.fault);
P_a41e4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_a41e4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a41e4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a41e4_3:;
goto L_a41e7;
}
L_a41e7:{ // ADD ESP,0x2c
c.pc=0xa41e7;if(!sl_tick(c))return int(c.fault);
P_a41e7_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a41e7_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL)))&(SlU(0x2cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL)))&(SlU(1)<<31))!=0),c);
P_a41e7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x2cULL)),c);
P_a41e7_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a41e7_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_a41e7_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_a41e7_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a41e7_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a41e7_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a41e7_9:;
goto L_a41ea;
}
L_a41ea:{ // POP EBX
c.pc=0xa41ea;if(!sl_tick(c))return int(c.fault);
P_a41ea_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a41ea_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a41ea_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a41ea_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a41ea_4:;
goto L_a41eb;
}
L_a41eb:{ // POP ESI
c.pc=0xa41eb;if(!sl_tick(c))return int(c.fault);
P_a41eb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a41eb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a41eb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a41eb_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a41eb_4:;
goto L_a41ec;
}
L_a41ec:{ // POP EDI
c.pc=0xa41ec;if(!sl_tick(c))return int(c.fault);
P_a41ec_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a41ec_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a41ec_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a41ec_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a41ec_4:;
goto L_a41ed;
}
L_a41ed:{ // POP EBP
c.pc=0xa41ed;if(!sl_tick(c))return int(c.fault);
P_a41ed_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a41ed_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a41ed_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a41ed_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a41ed_4:;
goto L_a41ee;
}
L_a41ee:{ // JMP 0x00103032
c.pc=0xa41ee;if(!sl_tick(c))return int(c.fault);
P_a41ee_0:;
c.pc=0x103032;goto dispatch;
P_a41ee_1:;
c.pc=0xa41f3;goto dispatch;
}
L_a4206:{ // PUSH EBP
c.pc=0xa4206;if(!sl_tick(c))return int(c.fault);
P_a4206_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_a4206_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4206_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a4206_3:;
goto L_a4207;
}
L_a4207:{ // MOV EBP,ESP
c.pc=0xa4207;if(!sl_tick(c))return int(c.fault);
P_a4207_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_a4207_1:;
goto L_a4209;
}
L_a4209:{ // PUSH EDI
c.pc=0xa4209;if(!sl_tick(c))return int(c.fault);
P_a4209_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a4209_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4209_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a4209_3:;
goto L_a420a;
}
L_a420a:{ // PUSH ESI
c.pc=0xa420a;if(!sl_tick(c))return int(c.fault);
P_a420a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a420a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a420a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a420a_3:;
goto L_a420b;
}
L_a420b:{ // PUSH EBX
c.pc=0xa420b;if(!sl_tick(c))return int(c.fault);
P_a420b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_a420b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a420b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a420b_3:;
goto L_a420c;
}
L_a420c:{ // SUB ESP,0x2c
c.pc=0xa420c;if(!sl_tick(c))return int(c.fault);
P_a420c_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x2cULL)),c);
P_a420c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x2cULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x2cULL)))&(SlU(1)<<31))!=0),c);
P_a420c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x2cULL)),c);
P_a420c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a420c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_a420c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_a420c_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a420c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a420c_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a420c_9:;
goto L_a420f;
}
L_a420f:{ // CALL 0x000c086c
c.pc=0xa420f;if(!sl_tick(c))return int(c.fault);
P_a420f_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a420f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4214ULL),c);
P_a420f_2:;
c.pc=0xc086c;goto dispatch;
P_a420f_3:;
goto L_a4214;
}
L_a4214:{ // CMP byte ptr [EBX + 0x5930c],0x0
c.pc=0xa4214;if(!sl_tick(c))return int(c.fault);
P_a4214_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x5930cULL)),c);
P_a4214_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a4214_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_a4214_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_a4214_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_a4214_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_a4214_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_a4214_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_a4214_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_a4214_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4214_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4214_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4214_12:;
goto L_a421b;
}
L_a421b:{ // JNZ 0x000a42cb
c.pc=0xa421b;if(!sl_tick(c))return int(c.fault);
P_a421b_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_a421b_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_a42cb;}
P_a421b_2:;
goto L_a4221;
}
L_a4221:{ // MOV EAX,dword ptr [EBX + 0x59308]
c.pc=0xa4221;if(!sl_tick(c))return int(c.fault);
P_a4221_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x59308ULL)),c);
P_a4221_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a4221_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4221_3:;
goto L_a4227;
}
L_a4227:{ // TEST EAX,EAX
c.pc=0xa4227;if(!sl_tick(c))return int(c.fault);
P_a4227_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a4227_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a4227_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_a4227_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4227_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a4227_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a4227_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4227_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4227_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4227_9:;
goto L_a4229;
}
L_a4229:{ // JZ 0x000a42cb
c.pc=0xa4229;if(!sl_tick(c))return int(c.fault);
P_a4229_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a42cb;}
P_a4229_1:;
goto L_a422f;
}
L_a422f:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0xa422f;if(!sl_tick(c))return int(c.fault);
P_a422f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_a422f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a422f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a422f_3:;
goto L_a4232;
}
L_a4232:{ // MOV EDX,dword ptr [EAX + 0x94]
c.pc=0xa4232;if(!sl_tick(c))return int(c.fault);
P_a4232_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x94ULL)),c);
P_a4232_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a4232_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4232_3:;
goto L_a4238;
}
L_a4238:{ // TEST EDX,EDX
c.pc=0xa4238;if(!sl_tick(c))return int(c.fault);
P_a4238_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a4238_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a4238_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a4238_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4238_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a4238_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a4238_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4238_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4238_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4238_9:;
goto L_a423a;
}
L_a423a:{ // JZ 0x000a42d5
c.pc=0xa423a;if(!sl_tick(c))return int(c.fault);
P_a423a_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a42d5;}
P_a423a_1:;
goto L_a4240;
}
L_a4240:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa4240;if(!sl_tick(c))return int(c.fault);
P_a4240_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a4240_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4240_2:;
goto L_a4242;
}
L_a4242:{ // MOV dword ptr [ESP],EDX
c.pc=0xa4242;if(!sl_tick(c))return int(c.fault);
P_a4242_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a4242_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4242_2:;
goto L_a4245;
}
L_a4245:{ // CALL dword ptr [EAX + 0xc]
c.pc=0xa4245;if(!sl_tick(c))return int(c.fault);
P_a4245_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xcULL)),c);
P_a4245_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4245_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4245_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4245_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4248ULL),c);
P_a4245_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a4245_6:;
goto L_a4248;
}
L_a4248:{ // MOV EDX,dword ptr [EBP + 0xc]
c.pc=0xa4248;if(!sl_tick(c))return int(c.fault);
P_a4248_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_a4248_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4248_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4248_3:;
goto L_a424b;
}
L_a424b:{ // MOV EDI,dword ptr [EDX + 0x94]
c.pc=0xa424b;if(!sl_tick(c))return int(c.fault);
P_a424b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x94ULL)),c);
P_a424b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a424b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a424b_3:;
goto L_a4251;
}
L_a4251:{ // MOV dword ptr [EBP + -0x20],0x0
c.pc=0xa4251;if(!sl_tick(c))return int(c.fault);
P_a4251_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_a4251_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a4251_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a4251_3:;
goto L_a4258;
}
L_a4258:{ // MOV dword ptr [EBP + -0x1c],0x0
c.pc=0xa4258;if(!sl_tick(c))return int(c.fault);
P_a4258_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_a4258_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a4258_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a4258_3:;
goto L_a425f;
}
L_a425f:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa425f;if(!sl_tick(c))return int(c.fault);
P_a425f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a425f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a425f_2:;
goto L_a4261;
}
L_a4261:{ // LEA ESI,[EBP + -0x20]
c.pc=0xa4261;if(!sl_tick(c))return int(c.fault);
P_a4261_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_a4261_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_a4261_2:;
goto L_a4264;
}
L_a4264:{ // MOV dword ptr [ESP + 0x8],ESI
c.pc=0xa4264;if(!sl_tick(c))return int(c.fault);
P_a4264_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4264_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a4264_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4264_3:;
goto L_a4268;
}
L_a4268:{ // MOV dword ptr [ESP + 0x4],EDI
c.pc=0xa4268;if(!sl_tick(c))return int(c.fault);
P_a4268_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4268_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a4268_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4268_3:;
goto L_a426c;
}
L_a426c:{ // MOV dword ptr [ESP],EDX
c.pc=0xa426c;if(!sl_tick(c))return int(c.fault);
P_a426c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a426c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a426c_2:;
goto L_a426f;
}
L_a426f:{ // CALL dword ptr [EAX + 0x84]
c.pc=0xa426f;if(!sl_tick(c))return int(c.fault);
P_a426f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x84ULL)),c);
P_a426f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a426f_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a426f_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a426f_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4275ULL),c);
P_a426f_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a426f_6:;
goto L_a4275;
}
L_a4275:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0xa4275;if(!sl_tick(c))return int(c.fault);
P_a4275_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_a4275_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4275_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4275_3:;
goto L_a4278;
}
L_a4278:{ // MOV EDX,dword ptr [EAX]
c.pc=0xa4278;if(!sl_tick(c))return int(c.fault);
P_a4278_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_a4278_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4278_2:;
goto L_a427a;
}
L_a427a:{ // MOV dword ptr [ESP + 0xc],ESI
c.pc=0xa427a;if(!sl_tick(c))return int(c.fault);
P_a427a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a427a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a427a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a427a_3:;
goto L_a427e;
}
L_a427e:{ // MOV EAX,dword ptr [EBX + 0x59308]
c.pc=0xa427e;if(!sl_tick(c))return int(c.fault);
P_a427e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x59308ULL)),c);
P_a427e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a427e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a427e_3:;
goto L_a4284;
}
L_a4284:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0xa4284;if(!sl_tick(c))return int(c.fault);
P_a4284_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4284_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4284_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4284_3:;
goto L_a4288;
}
L_a4288:{ // MOV dword ptr [ESP + 0x4],EDI
c.pc=0xa4288;if(!sl_tick(c))return int(c.fault);
P_a4288_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4288_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a4288_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4288_3:;
goto L_a428c;
}
L_a428c:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0xa428c;if(!sl_tick(c))return int(c.fault);
P_a428c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_a428c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a428c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a428c_3:;
goto L_a428f;
}
L_a428f:{ // MOV dword ptr [ESP],EAX
c.pc=0xa428f;if(!sl_tick(c))return int(c.fault);
P_a428f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a428f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a428f_2:;
goto L_a4292;
}
L_a4292:{ // CALL dword ptr [EDX + 0x38]
c.pc=0xa4292;if(!sl_tick(c))return int(c.fault);
P_a4292_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x38ULL)),c);
P_a4292_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4292_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4292_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4292_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4295ULL),c);
P_a4292_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a4292_6:;
goto L_a4295;
}
L_a4295:{ // MOV EDX,dword ptr [EBP + 0xc]
c.pc=0xa4295;if(!sl_tick(c))return int(c.fault);
P_a4295_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_a4295_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4295_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4295_3:;
goto L_a4298;
}
L_a4298:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa4298;if(!sl_tick(c))return int(c.fault);
P_a4298_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a4298_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4298_2:;
goto L_a429a;
}
L_a429a:{ // MOV dword ptr [ESP + 0x4],0x0
c.pc=0xa429a;if(!sl_tick(c))return int(c.fault);
P_a429a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a429a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a429a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a429a_3:;
goto L_a42a2;
}
L_a42a2:{ // MOV dword ptr [ESP],EDX
c.pc=0xa42a2;if(!sl_tick(c))return int(c.fault);
P_a42a2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a42a2_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a42a2_2:;
goto L_a42a5;
}
L_a42a5:{ // CALL dword ptr [EAX + 0x138]
c.pc=0xa42a5;if(!sl_tick(c))return int(c.fault);
P_a42a5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x138ULL)),c);
P_a42a5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a42a5_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a42a5_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a42a5_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa42abULL),c);
P_a42a5_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a42a5_6:;
goto L_a42ab;
}
L_a42ab:{ // MOV EAX,dword ptr [EDI]
c.pc=0xa42ab;if(!sl_tick(c))return int(c.fault);
P_a42ab_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_a42ab_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a42ab_2:;
goto L_a42ad;
}
L_a42ad:{ // MOV dword ptr [ESP],EDI
c.pc=0xa42ad;if(!sl_tick(c))return int(c.fault);
P_a42ad_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a42ad_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a42ad_2:;
goto L_a42b0;
}
L_a42b0:{ // CALL dword ptr [EAX + 0x8]
c.pc=0xa42b0;if(!sl_tick(c))return int(c.fault);
P_a42b0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_a42b0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a42b0_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a42b0_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a42b0_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa42b3ULL),c);
P_a42b0_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a42b0_6:;
goto L_a42b3;
}
L_a42b3:{ // MOV EAX,dword ptr [EBX + 0x59308]
c.pc=0xa42b3;if(!sl_tick(c))return int(c.fault);
P_a42b3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x59308ULL)),c);
P_a42b3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a42b3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a42b3_3:;
goto L_a42b9;
}
L_a42b9:{ // MOV EDX,dword ptr [EAX]
c.pc=0xa42b9;if(!sl_tick(c))return int(c.fault);
P_a42b9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_a42b9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a42b9_2:;
goto L_a42bb;
}
L_a42bb:{ // MOV dword ptr [ESP],EAX
c.pc=0xa42bb;if(!sl_tick(c))return int(c.fault);
P_a42bb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a42bb_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a42bb_2:;
goto L_a42be;
}
L_a42be:{ // CALL dword ptr [EDX + 0x8]
c.pc=0xa42be;if(!sl_tick(c))return int(c.fault);
P_a42be_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x8ULL)),c);
P_a42be_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a42be_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a42be_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a42be_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa42c1ULL),c);
P_a42be_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a42be_6:;
goto L_a42c1;
}
L_a42c1:{ // MOV dword ptr [EBX + 0x59308],0x0
c.pc=0xa42c1;if(!sl_tick(c))return int(c.fault);
P_a42c1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x59308ULL)),c);
P_a42c1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a42c1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a42c1_3:;
goto L_a42cb;
}
L_a42cb:{ // XOR EAX,EAX
c.pc=0xa42cb;if(!sl_tick(c))return int(c.fault);
P_a42cb_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a42cb_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a42cb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_a42cb_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a42cb_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_a42cb_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_a42cb_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a42cb_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a42cb_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a42cb_9:;
goto L_a42cd;
}
L_a42cd:{ // ADD ESP,0x2c
c.pc=0xa42cd;if(!sl_tick(c))return int(c.fault);
P_a42cd_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a42cd_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL)))&(SlU(0x2cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x2cULL)))&(SlU(1)<<31))!=0),c);
P_a42cd_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x2cULL)),c);
P_a42cd_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a42cd_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_a42cd_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_a42cd_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a42cd_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a42cd_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a42cd_9:;
goto L_a42d0;
}
L_a42d0:{ // POP EBX
c.pc=0xa42d0;if(!sl_tick(c))return int(c.fault);
P_a42d0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a42d0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a42d0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a42d0_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a42d0_4:;
goto L_a42d1;
}
L_a42d1:{ // POP ESI
c.pc=0xa42d1;if(!sl_tick(c))return int(c.fault);
P_a42d1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a42d1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a42d1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a42d1_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a42d1_4:;
goto L_a42d2;
}
L_a42d2:{ // POP EDI
c.pc=0xa42d2;if(!sl_tick(c))return int(c.fault);
P_a42d2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a42d2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a42d2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a42d2_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a42d2_4:;
goto L_a42d3;
}
L_a42d3:{ // POP EBP
c.pc=0xa42d3;if(!sl_tick(c))return int(c.fault);
P_a42d3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a42d3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a42d3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a42d3_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a42d3_4:;
goto L_a42d4;
}
L_a42d4:{ // RET
c.pc=0xa42d4;if(!sl_tick(c))return int(c.fault);
P_a42d4_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a42d4_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a42d4_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_a42d4_3:;
goto L_a42d5;
}
L_a42d5:{ // MOV ESI,dword ptr [EAX + 0x64]
c.pc=0xa42d5;if(!sl_tick(c))return int(c.fault);
P_a42d5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x64ULL)),c);
P_a42d5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a42d5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a42d5_3:;
goto L_a42d8;
}
L_a42d8:{ // MOV dword ptr [ESP],0x68
c.pc=0xa42d8;if(!sl_tick(c))return int(c.fault);
P_a42d8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x68ULL),c);
P_a42d8_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a42d8_2:;
goto L_a42df;
}
L_a42df:{ // CALL 0x00103064
c.pc=0xa42df;if(!sl_tick(c))return int(c.fault);
P_a42df_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a42df_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa42e4ULL),c);
P_a42df_2:;
c.pc=0x103064;goto dispatch;
P_a42df_3:;
goto L_a42e4;
}
L_a42e4:{ // MOV EDI,EAX
c.pc=0xa42e4;if(!sl_tick(c))return int(c.fault);
P_a42e4_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a42e4_1:;
goto L_a42e6;
}
L_a42e6:{ // MOV dword ptr [ESP + 0xc],ESI
c.pc=0xa42e6;if(!sl_tick(c))return int(c.fault);
P_a42e6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a42e6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a42e6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a42e6_3:;
goto L_a42ea;
}
L_a42ea:{ // MOV dword ptr [ESP + 0x8],0x0
c.pc=0xa42ea;if(!sl_tick(c))return int(c.fault);
P_a42ea_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a42ea_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a42ea_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a42ea_3:;
goto L_a42f2;
}
L_a42f2:{ // MOV EDX,dword ptr [EBP + 0xc]
c.pc=0xa42f2;if(!sl_tick(c))return int(c.fault);
P_a42f2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_a42f2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a42f2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a42f2_3:;
goto L_a42f5;
}
L_a42f5:{ // MOV dword ptr [ESP + 0x4],EDX
c.pc=0xa42f5;if(!sl_tick(c))return int(c.fault);
P_a42f5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a42f5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a42f5_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a42f5_3:;
goto L_a42f9;
}
L_a42f9:{ // MOV dword ptr [ESP],EAX
c.pc=0xa42f9;if(!sl_tick(c))return int(c.fault);
P_a42f9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a42f9_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a42f9_2:;
goto L_a42fc;
}
L_a42fc:{ // CALL 0x000a171a
c.pc=0xa42fc;if(!sl_tick(c))return int(c.fault);
P_a42fc_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a42fc_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4301ULL),c);
P_a42fc_2:;
c.pc=0xa171a;goto dispatch;
P_a42fc_3:;
goto L_a4301;
}
L_a4301:{ // MOV EDX,dword ptr [EBP + 0xc]
c.pc=0xa4301;if(!sl_tick(c))return int(c.fault);
P_a4301_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_a4301_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4301_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4301_3:;
goto L_a4304;
}
L_a4304:{ // JMP 0x000a4251
c.pc=0xa4304;if(!sl_tick(c))return int(c.fault);
P_a4304_0:;
goto L_a4251;
P_a4304_1:;
c.pc=0xa4309;goto dispatch;
}
L_a431c:{ // PUSH EBP
c.pc=0xa431c;if(!sl_tick(c))return int(c.fault);
P_a431c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_a431c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a431c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a431c_3:;
goto L_a431d;
}
L_a431d:{ // MOV EBP,ESP
c.pc=0xa431d;if(!sl_tick(c))return int(c.fault);
P_a431d_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_a431d_1:;
goto L_a431f;
}
L_a431f:{ // PUSH EDI
c.pc=0xa431f;if(!sl_tick(c))return int(c.fault);
P_a431f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a431f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a431f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a431f_3:;
goto L_a4320;
}
L_a4320:{ // PUSH ESI
c.pc=0xa4320;if(!sl_tick(c))return int(c.fault);
P_a4320_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a4320_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4320_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a4320_3:;
goto L_a4321;
}
L_a4321:{ // PUSH EBX
c.pc=0xa4321;if(!sl_tick(c))return int(c.fault);
P_a4321_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0xc,c),c);
P_a4321_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4321_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a4321_3:;
goto L_a4322;
}
L_a4322:{ // SUB ESP,0x3c
c.pc=0xa4322;if(!sl_tick(c))return int(c.fault);
P_a4322_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x3cULL)),c);
P_a4322_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x3cULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x3cULL)))&(SlU(1)<<31))!=0),c);
P_a4322_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x3cULL)),c);
P_a4322_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4322_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_a4322_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_a4322_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4322_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4322_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4322_9:;
goto L_a4325;
}
L_a4325:{ // CALL 0x000c086c
c.pc=0xa4325;if(!sl_tick(c))return int(c.fault);
P_a4325_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4325_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa432aULL),c);
P_a4325_2:;
c.pc=0xc086c;goto dispatch;
P_a4325_3:;
goto L_a432a;
}
L_a432a:{ // MOVZX EAX,word ptr [EBP + 0x8]
c.pc=0xa432a;if(!sl_tick(c))return int(c.fault);
P_a432a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_a432a_1:;
sl_put<2>(c.temp,sizeof(c.temp),0x9600,sl_get<2>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a432a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<2>(c.temp,sizeof(c.temp),0x9600,c),c);
P_a432a_3:;
goto L_a432e;
}
L_a432e:{ // CMP byte ptr [EBX + 0x591f6],0x0
c.pc=0xa432e;if(!sl_tick(c))return int(c.fault);
P_a432e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x591f6ULL)),c);
P_a432e_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a432e_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_a432e_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_a432e_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_a432e_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_a432e_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_a432e_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_a432e_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_a432e_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a432e_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a432e_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a432e_12:;
goto L_a4335;
}
L_a4335:{ // JNZ 0x000a4351
c.pc=0xa4335;if(!sl_tick(c))return int(c.fault);
P_a4335_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_a4335_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_a4351;}
P_a4335_2:;
goto L_a4337;
}
L_a4337:{ // CMP AX,0x3
c.pc=0xa4337;if(!sl_tick(c))return int(c.fault);
P_a4337_0:;
sl_put<2>(c.temp,sizeof(c.temp),0x30c00,sl_get<2>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4337_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c) < SlU(0x3ULL)),c);
P_a4337_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c)^SlU(0x3ULL))&(sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c)^(sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c)-SlU(0x3ULL)))&(SlU(1)<<15))!=0),c);
P_a4337_3:;
sl_put<2>(c.temp,sizeof(c.temp),0x30d00,(sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c) - SlU(0x3ULL)),c);
P_a4337_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<2>(c.temp,sizeof(c.temp),0x30d00,c),16) < sl_signed(SlU(0x0ULL),16)),c);
P_a4337_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<2>(c.temp,sizeof(c.temp),0x30d00,c) == SlU(0x0ULL)),c);
P_a4337_6:;
sl_put<2>(c.temp,sizeof(c.temp),0x22900,(sl_get<2>(c.temp,sizeof(c.temp),0x30d00,c) & SlU(0xffULL)),c);
P_a4337_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<2>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4337_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4337_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4337_10:;
goto L_a433b;
}
L_a433b:{ // JZ 0x000a435b
c.pc=0xa433b;if(!sl_tick(c))return int(c.fault);
P_a433b_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a435b;}
P_a433b_1:;
goto L_a433d;
}
L_a433d:{ // CMP AX,0x4
c.pc=0xa433d;if(!sl_tick(c))return int(c.fault);
P_a433d_0:;
sl_put<2>(c.temp,sizeof(c.temp),0x30c00,sl_get<2>(c.reg,sizeof(c.reg),0x0,c),c);
P_a433d_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c) < SlU(0x4ULL)),c);
P_a433d_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c)^SlU(0x4ULL))&(sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c)^(sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c)-SlU(0x4ULL)))&(SlU(1)<<15))!=0),c);
P_a433d_3:;
sl_put<2>(c.temp,sizeof(c.temp),0x30d00,(sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c) - SlU(0x4ULL)),c);
P_a433d_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<2>(c.temp,sizeof(c.temp),0x30d00,c),16) < sl_signed(SlU(0x0ULL),16)),c);
P_a433d_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<2>(c.temp,sizeof(c.temp),0x30d00,c) == SlU(0x0ULL)),c);
P_a433d_6:;
sl_put<2>(c.temp,sizeof(c.temp),0x22900,(sl_get<2>(c.temp,sizeof(c.temp),0x30d00,c) & SlU(0xffULL)),c);
P_a433d_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<2>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a433d_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a433d_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a433d_10:;
goto L_a4341;
}
L_a4341:{ // JZ 0x000a44c5
c.pc=0xa4341;if(!sl_tick(c))return int(c.fault);
P_a4341_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a44c5;}
P_a4341_1:;
goto L_a4347;
}
L_a4347:{ // CMP AX,0x2
c.pc=0xa4347;if(!sl_tick(c))return int(c.fault);
P_a4347_0:;
sl_put<2>(c.temp,sizeof(c.temp),0x30c00,sl_get<2>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4347_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c) < SlU(0x2ULL)),c);
P_a4347_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c)^SlU(0x2ULL))&(sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c)^(sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c)-SlU(0x2ULL)))&(SlU(1)<<15))!=0),c);
P_a4347_3:;
sl_put<2>(c.temp,sizeof(c.temp),0x30d00,(sl_get<2>(c.temp,sizeof(c.temp),0x30c00,c) - SlU(0x2ULL)),c);
P_a4347_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<2>(c.temp,sizeof(c.temp),0x30d00,c),16) < sl_signed(SlU(0x0ULL),16)),c);
P_a4347_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<2>(c.temp,sizeof(c.temp),0x30d00,c) == SlU(0x0ULL)),c);
P_a4347_6:;
sl_put<2>(c.temp,sizeof(c.temp),0x22900,(sl_get<2>(c.temp,sizeof(c.temp),0x30d00,c) & SlU(0xffULL)),c);
P_a4347_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<2>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4347_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4347_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4347_10:;
goto L_a434b;
}
L_a434b:{ // JZ 0x000a43d3
c.pc=0xa434b;if(!sl_tick(c))return int(c.fault);
P_a434b_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a43d3;}
P_a434b_1:;
goto L_a4351;
}
L_a4351:{ // XOR EAX,EAX
c.pc=0xa4351;if(!sl_tick(c))return int(c.fault);
P_a4351_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a4351_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a4351_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_a4351_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4351_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_a4351_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_a4351_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4351_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4351_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4351_9:;
goto L_a4353;
}
L_a4353:{ // ADD ESP,0x3c
c.pc=0xa4353;if(!sl_tick(c))return int(c.fault);
P_a4353_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4353_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(0x3cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(1)<<31))!=0),c);
P_a4353_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x3cULL)),c);
P_a4353_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4353_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_a4353_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_a4353_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4353_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4353_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4353_9:;
goto L_a4356;
}
L_a4356:{ // POP EBX
c.pc=0xa4356;if(!sl_tick(c))return int(c.fault);
P_a4356_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a4356_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a4356_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a4356_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a4356_4:;
goto L_a4357;
}
L_a4357:{ // POP ESI
c.pc=0xa4357;if(!sl_tick(c))return int(c.fault);
P_a4357_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a4357_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a4357_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a4357_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a4357_4:;
goto L_a4358;
}
L_a4358:{ // POP EDI
c.pc=0xa4358;if(!sl_tick(c))return int(c.fault);
P_a4358_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a4358_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a4358_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a4358_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a4358_4:;
goto L_a4359;
}
L_a4359:{ // POP EBP
c.pc=0xa4359;if(!sl_tick(c))return int(c.fault);
P_a4359_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a4359_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a4359_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a4359_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a4359_4:;
goto L_a435a;
}
L_a435a:{ // RET
c.pc=0xa435a;if(!sl_tick(c))return int(c.fault);
P_a435a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a435a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a435a_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_a435a_3:;
goto L_a435b;
}
L_a435b:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xa435b;if(!sl_tick(c))return int(c.fault);
P_a435b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a435b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a435b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a435b_3:;
goto L_a435e;
}
L_a435e:{ // MOV EDX,dword ptr [EAX + 0x94]
c.pc=0xa435e;if(!sl_tick(c))return int(c.fault);
P_a435e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x94ULL)),c);
P_a435e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a435e_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a435e_3:;
goto L_a4364;
}
L_a4364:{ // TEST EDX,EDX
c.pc=0xa4364;if(!sl_tick(c))return int(c.fault);
P_a4364_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a4364_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a4364_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a4364_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4364_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a4364_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a4364_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4364_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4364_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4364_9:;
goto L_a4366;
}
L_a4366:{ // JZ 0x000a456b
c.pc=0xa4366;if(!sl_tick(c))return int(c.fault);
P_a4366_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a456b;}
P_a4366_1:;
goto L_a436c;
}
L_a436c:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa436c;if(!sl_tick(c))return int(c.fault);
P_a436c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a436c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a436c_2:;
goto L_a436e;
}
L_a436e:{ // MOV dword ptr [ESP],EDX
c.pc=0xa436e;if(!sl_tick(c))return int(c.fault);
P_a436e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a436e_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a436e_2:;
goto L_a4371;
}
L_a4371:{ // CALL dword ptr [EAX + 0xc]
c.pc=0xa4371;if(!sl_tick(c))return int(c.fault);
P_a4371_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xcULL)),c);
P_a4371_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4371_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4371_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4371_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4374ULL),c);
P_a4371_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a4371_6:;
goto L_a4374;
}
L_a4374:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xa4374;if(!sl_tick(c))return int(c.fault);
P_a4374_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a4374_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4374_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4374_3:;
goto L_a4377;
}
L_a4377:{ // MOV EDI,dword ptr [EDX + 0x94]
c.pc=0xa4377;if(!sl_tick(c))return int(c.fault);
P_a4377_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x94ULL)),c);
P_a4377_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a4377_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4377_3:;
goto L_a437d;
}
L_a437d:{ // MOV dword ptr [EBP + -0x24],0x0
c.pc=0xa437d;if(!sl_tick(c))return int(c.fault);
P_a437d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_a437d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a437d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a437d_3:;
goto L_a4384;
}
L_a4384:{ // MOV dword ptr [EBP + -0x20],0x0
c.pc=0xa4384;if(!sl_tick(c))return int(c.fault);
P_a4384_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_a4384_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a4384_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a4384_3:;
goto L_a438b;
}
L_a438b:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa438b;if(!sl_tick(c))return int(c.fault);
P_a438b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a438b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a438b_2:;
goto L_a438d;
}
L_a438d:{ // LEA ESI,[EBP + -0x24]
c.pc=0xa438d;if(!sl_tick(c))return int(c.fault);
P_a438d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_a438d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_a438d_2:;
goto L_a4390;
}
L_a4390:{ // MOV dword ptr [ESP + 0x8],ESI
c.pc=0xa4390;if(!sl_tick(c))return int(c.fault);
P_a4390_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4390_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a4390_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4390_3:;
goto L_a4394;
}
L_a4394:{ // MOV dword ptr [ESP + 0x4],EDI
c.pc=0xa4394;if(!sl_tick(c))return int(c.fault);
P_a4394_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4394_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a4394_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4394_3:;
goto L_a4398;
}
L_a4398:{ // MOV dword ptr [ESP],EDX
c.pc=0xa4398;if(!sl_tick(c))return int(c.fault);
P_a4398_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a4398_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4398_2:;
goto L_a439b;
}
L_a439b:{ // CALL dword ptr [EAX + 0x84]
c.pc=0xa439b;if(!sl_tick(c))return int(c.fault);
P_a439b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x84ULL)),c);
P_a439b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a439b_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a439b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a439b_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa43a1ULL),c);
P_a439b_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a439b_6:;
goto L_a43a1;
}
L_a43a1:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xa43a1;if(!sl_tick(c))return int(c.fault);
P_a43a1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a43a1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a43a1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a43a1_3:;
goto L_a43a4;
}
L_a43a4:{ // MOV EDX,dword ptr [EAX]
c.pc=0xa43a4;if(!sl_tick(c))return int(c.fault);
P_a43a4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_a43a4_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a43a4_2:;
goto L_a43a6;
}
L_a43a6:{ // MOV dword ptr [ESP + 0xc],ESI
c.pc=0xa43a6;if(!sl_tick(c))return int(c.fault);
P_a43a6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a43a6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a43a6_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a43a6_3:;
goto L_a43aa;
}
L_a43aa:{ // MOV EAX,dword ptr [EBX + 0x591f2]
c.pc=0xa43aa;if(!sl_tick(c))return int(c.fault);
P_a43aa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x591f2ULL)),c);
P_a43aa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a43aa_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a43aa_3:;
goto L_a43b0;
}
L_a43b0:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0xa43b0;if(!sl_tick(c))return int(c.fault);
P_a43b0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a43b0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a43b0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a43b0_3:;
goto L_a43b4;
}
L_a43b4:{ // MOV dword ptr [ESP + 0x4],EDI
c.pc=0xa43b4;if(!sl_tick(c))return int(c.fault);
P_a43b4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a43b4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a43b4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a43b4_3:;
goto L_a43b8;
}
L_a43b8:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xa43b8;if(!sl_tick(c))return int(c.fault);
P_a43b8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a43b8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a43b8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a43b8_3:;
goto L_a43bb;
}
L_a43bb:{ // MOV dword ptr [ESP],EAX
c.pc=0xa43bb;if(!sl_tick(c))return int(c.fault);
P_a43bb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a43bb_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a43bb_2:;
goto L_a43be;
}
L_a43be:{ // CALL dword ptr [EDX + 0x44]
c.pc=0xa43be;if(!sl_tick(c))return int(c.fault);
P_a43be_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x44ULL)),c);
P_a43be_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a43be_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a43be_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a43be_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa43c1ULL),c);
P_a43be_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a43be_6:;
goto L_a43c1;
}
L_a43c1:{ // MOV EAX,dword ptr [EDI]
c.pc=0xa43c1;if(!sl_tick(c))return int(c.fault);
P_a43c1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_a43c1_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a43c1_2:;
goto L_a43c3;
}
L_a43c3:{ // MOV dword ptr [ESP],EDI
c.pc=0xa43c3;if(!sl_tick(c))return int(c.fault);
P_a43c3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a43c3_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a43c3_2:;
goto L_a43c6;
}
L_a43c6:{ // CALL dword ptr [EAX + 0x8]
c.pc=0xa43c6;if(!sl_tick(c))return int(c.fault);
P_a43c6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_a43c6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a43c6_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a43c6_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a43c6_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa43c9ULL),c);
P_a43c6_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a43c6_6:;
goto L_a43c9;
}
L_a43c9:{ // XOR EAX,EAX
c.pc=0xa43c9;if(!sl_tick(c))return int(c.fault);
P_a43c9_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a43c9_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a43c9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_a43c9_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a43c9_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_a43c9_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_a43c9_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a43c9_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a43c9_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a43c9_9:;
goto L_a43cb;
}
L_a43cb:{ // ADD ESP,0x3c
c.pc=0xa43cb;if(!sl_tick(c))return int(c.fault);
P_a43cb_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a43cb_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(0x3cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(1)<<31))!=0),c);
P_a43cb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x3cULL)),c);
P_a43cb_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a43cb_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_a43cb_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_a43cb_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a43cb_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a43cb_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a43cb_9:;
goto L_a43ce;
}
L_a43ce:{ // POP EBX
c.pc=0xa43ce;if(!sl_tick(c))return int(c.fault);
P_a43ce_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a43ce_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a43ce_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a43ce_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a43ce_4:;
goto L_a43cf;
}
L_a43cf:{ // POP ESI
c.pc=0xa43cf;if(!sl_tick(c))return int(c.fault);
P_a43cf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a43cf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a43cf_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a43cf_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a43cf_4:;
goto L_a43d0;
}
L_a43d0:{ // POP EDI
c.pc=0xa43d0;if(!sl_tick(c))return int(c.fault);
P_a43d0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a43d0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a43d0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a43d0_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a43d0_4:;
goto L_a43d1;
}
L_a43d1:{ // POP EBP
c.pc=0xa43d1;if(!sl_tick(c))return int(c.fault);
P_a43d1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a43d1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a43d1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a43d1_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a43d1_4:;
goto L_a43d2;
}
L_a43d2:{ // RET
c.pc=0xa43d2;if(!sl_tick(c))return int(c.fault);
P_a43d2_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a43d2_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a43d2_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_a43d2_3:;
goto L_a43d3;
}
L_a43d3:{ // MOV EDX,dword ptr [EBX + 0x591f2]
c.pc=0xa43d3;if(!sl_tick(c))return int(c.fault);
P_a43d3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x591f2ULL)),c);
P_a43d3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a43d3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a43d3_3:;
goto L_a43d9;
}
L_a43d9:{ // TEST EDX,EDX
c.pc=0xa43d9;if(!sl_tick(c))return int(c.fault);
P_a43d9_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a43d9_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a43d9_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a43d9_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a43d9_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a43d9_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a43d9_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a43d9_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a43d9_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a43d9_9:;
goto L_a43db;
}
L_a43db:{ // JZ 0x000a43e5
c.pc=0xa43db;if(!sl_tick(c))return int(c.fault);
P_a43db_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a43e5;}
P_a43db_1:;
goto L_a43dd;
}
L_a43dd:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa43dd;if(!sl_tick(c))return int(c.fault);
P_a43dd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a43dd_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a43dd_2:;
goto L_a43df;
}
L_a43df:{ // MOV dword ptr [ESP],EDX
c.pc=0xa43df;if(!sl_tick(c))return int(c.fault);
P_a43df_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a43df_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a43df_2:;
goto L_a43e2;
}
L_a43e2:{ // CALL dword ptr [EAX + 0x8]
c.pc=0xa43e2;if(!sl_tick(c))return int(c.fault);
P_a43e2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_a43e2_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a43e2_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a43e2_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a43e2_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa43e5ULL),c);
P_a43e2_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a43e2_6:;
goto L_a43e5;
}
L_a43e5:{ // MOV dword ptr [ESP],0x18
c.pc=0xa43e5;if(!sl_tick(c))return int(c.fault);
P_a43e5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x18ULL),c);
P_a43e5_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a43e5_2:;
goto L_a43ec;
}
L_a43ec:{ // CALL 0x00103064
c.pc=0xa43ec;if(!sl_tick(c))return int(c.fault);
P_a43ec_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a43ec_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa43f1ULL),c);
P_a43ec_2:;
c.pc=0x103064;goto dispatch;
P_a43ec_3:;
goto L_a43f1;
}
L_a43f1:{ // MOV ESI,EAX
c.pc=0xa43f1;if(!sl_tick(c))return int(c.fault);
P_a43f1_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a43f1_1:;
goto L_a43f3;
}
L_a43f3:{ // MOV dword ptr [EAX + 0x4],0x1
c.pc=0xa43f3;if(!sl_tick(c))return int(c.fault);
P_a43f3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x4ULL)),c);
P_a43f3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x1ULL),c);
P_a43f3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a43f3_3:;
goto L_a43fa;
}
L_a43fa:{ // LEA EAX,[EBX + 0x500d6]
c.pc=0xa43fa;if(!sl_tick(c))return int(c.fault);
P_a43fa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x500d6ULL)),c);
P_a43fa_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3380,c),c);
P_a43fa_2:;
goto L_a4400;
}
L_a4400:{ // MOV dword ptr [ESI],EAX
c.pc=0xa4400;if(!sl_tick(c))return int(c.fault);
P_a4400_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4400_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4400_2:;
goto L_a4402;
}
L_a4402:{ // MOV EAX,dword ptr [EBP + 0x14]
c.pc=0xa4402;if(!sl_tick(c))return int(c.fault);
P_a4402_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_a4402_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4402_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4402_3:;
goto L_a4405;
}
L_a4405:{ // MOV dword ptr [ESI + 0x8],EAX
c.pc=0xa4405;if(!sl_tick(c))return int(c.fault);
P_a4405_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x8ULL)),c);
P_a4405_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4405_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4405_3:;
goto L_a4408;
}
L_a4408:{ // MOV dword ptr [ESI + 0xc],0x0
c.pc=0xa4408;if(!sl_tick(c))return int(c.fault);
P_a4408_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0xcULL)),c);
P_a4408_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a4408_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a4408_3:;
goto L_a440f;
}
L_a440f:{ // MOV dword ptr [ESI + 0x10],0x0
c.pc=0xa440f;if(!sl_tick(c))return int(c.fault);
P_a440f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x10ULL)),c);
P_a440f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a440f_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a440f_3:;
goto L_a4416;
}
L_a4416:{ // MOV dword ptr [ESI + 0x14],0x0
c.pc=0xa4416;if(!sl_tick(c))return int(c.fault);
P_a4416_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0x14ULL)),c);
P_a4416_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a4416_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a4416_3:;
goto L_a441d;
}
L_a441d:{ // LEA EAX,[EBP + -0x1a]
c.pc=0xa441d;if(!sl_tick(c))return int(c.fault);
P_a441d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe6ULL)),c);
P_a441d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_a441d_2:;
goto L_a4420;
}
L_a4420:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xa4420;if(!sl_tick(c))return int(c.fault);
P_a4420_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4420_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4420_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4420_3:;
goto L_a4424;
}
L_a4424:{ // MOV EDX,dword ptr [EBP + 0x14]
c.pc=0xa4424;if(!sl_tick(c))return int(c.fault);
P_a4424_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x14ULL)),c);
P_a4424_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4424_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4424_3:;
goto L_a4427;
}
L_a4427:{ // MOV dword ptr [ESP],EDX
c.pc=0xa4427;if(!sl_tick(c))return int(c.fault);
P_a4427_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a4427_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4427_2:;
goto L_a442a;
}
L_a442a:{ // CALL 0x001036b3
c.pc=0xa442a;if(!sl_tick(c))return int(c.fault);
P_a442a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a442a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa442fULL),c);
P_a442a_2:;
c.pc=0x1036b3;goto dispatch;
P_a442a_3:;
goto L_a442f;
}
L_a442f:{ // MOVZX EAX,word ptr [EBP + -0x1a]
c.pc=0xa442f;if(!sl_tick(c))return int(c.fault);
P_a442f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe6ULL)),c);
P_a442f_1:;
sl_put<2>(c.temp,sizeof(c.temp),0x9600,sl_get<2>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a442f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<2>(c.temp,sizeof(c.temp),0x9600,c),c);
P_a442f_3:;
goto L_a4433;
}
L_a4433:{ // MOV dword ptr [ESI + 0xc],EAX
c.pc=0xa4433;if(!sl_tick(c))return int(c.fault);
P_a4433_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x18,c) + SlU(0xcULL)),c);
P_a4433_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4433_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4433_3:;
goto L_a4436;
}
L_a4436:{ // MOV dword ptr [EBX + 0x591f2],ESI
c.pc=0xa4436;if(!sl_tick(c))return int(c.fault);
P_a4436_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x591f2ULL)),c);
P_a4436_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a4436_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4436_3:;
goto L_a443c;
}
L_a443c:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xa443c;if(!sl_tick(c))return int(c.fault);
P_a443c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a443c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a443c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a443c_3:;
goto L_a443f;
}
L_a443f:{ // MOV EDX,dword ptr [EAX + 0x94]
c.pc=0xa443f;if(!sl_tick(c))return int(c.fault);
P_a443f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x94ULL)),c);
P_a443f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a443f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a443f_3:;
goto L_a4445;
}
L_a4445:{ // TEST EDX,EDX
c.pc=0xa4445;if(!sl_tick(c))return int(c.fault);
P_a4445_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a4445_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a4445_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a4445_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4445_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a4445_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a4445_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4445_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4445_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4445_9:;
goto L_a4447;
}
L_a4447:{ // JZ 0x000a45d3
c.pc=0xa4447;if(!sl_tick(c))return int(c.fault);
P_a4447_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a45d3;}
P_a4447_1:;
goto L_a444d;
}
L_a444d:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa444d;if(!sl_tick(c))return int(c.fault);
P_a444d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a444d_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a444d_2:;
goto L_a444f;
}
L_a444f:{ // MOV dword ptr [ESP],EDX
c.pc=0xa444f;if(!sl_tick(c))return int(c.fault);
P_a444f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a444f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a444f_2:;
goto L_a4452;
}
L_a4452:{ // CALL dword ptr [EAX + 0xc]
c.pc=0xa4452;if(!sl_tick(c))return int(c.fault);
P_a4452_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xcULL)),c);
P_a4452_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4452_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4452_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4452_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4455ULL),c);
P_a4452_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a4452_6:;
goto L_a4455;
}
L_a4455:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xa4455;if(!sl_tick(c))return int(c.fault);
P_a4455_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a4455_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4455_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4455_3:;
goto L_a4458;
}
L_a4458:{ // MOV EDI,dword ptr [EDX + 0x94]
c.pc=0xa4458;if(!sl_tick(c))return int(c.fault);
P_a4458_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x94ULL)),c);
P_a4458_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a4458_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4458_3:;
goto L_a445e;
}
L_a445e:{ // MOV dword ptr [EBP + -0x24],0x0
c.pc=0xa445e;if(!sl_tick(c))return int(c.fault);
P_a445e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_a445e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a445e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a445e_3:;
goto L_a4465;
}
L_a4465:{ // MOV dword ptr [EBP + -0x20],0x0
c.pc=0xa4465;if(!sl_tick(c))return int(c.fault);
P_a4465_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_a4465_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a4465_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a4465_3:;
goto L_a446c;
}
L_a446c:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa446c;if(!sl_tick(c))return int(c.fault);
P_a446c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a446c_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a446c_2:;
goto L_a446e;
}
L_a446e:{ // MOV dword ptr [ESP + 0x4],0x8
c.pc=0xa446e;if(!sl_tick(c))return int(c.fault);
P_a446e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a446e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x8ULL),c);
P_a446e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a446e_3:;
goto L_a4476;
}
L_a4476:{ // MOV dword ptr [ESP],EDX
c.pc=0xa4476;if(!sl_tick(c))return int(c.fault);
P_a4476_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a4476_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4476_2:;
goto L_a4479;
}
L_a4479:{ // CALL dword ptr [EAX + 0x138]
c.pc=0xa4479;if(!sl_tick(c))return int(c.fault);
P_a4479_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x138ULL)),c);
P_a4479_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a4479_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4479_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4479_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa447fULL),c);
P_a4479_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a4479_6:;
goto L_a447f;
}
L_a447f:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xa447f;if(!sl_tick(c))return int(c.fault);
P_a447f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a447f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a447f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a447f_3:;
goto L_a4482;
}
L_a4482:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa4482;if(!sl_tick(c))return int(c.fault);
P_a4482_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a4482_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4482_2:;
goto L_a4484;
}
L_a4484:{ // LEA ESI,[EBP + -0x24]
c.pc=0xa4484;if(!sl_tick(c))return int(c.fault);
P_a4484_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_a4484_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_a4484_2:;
goto L_a4487;
}
L_a4487:{ // MOV dword ptr [ESP + 0x8],ESI
c.pc=0xa4487;if(!sl_tick(c))return int(c.fault);
P_a4487_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4487_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a4487_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4487_3:;
goto L_a448b;
}
L_a448b:{ // MOV dword ptr [ESP + 0x4],EDI
c.pc=0xa448b;if(!sl_tick(c))return int(c.fault);
P_a448b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a448b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a448b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a448b_3:;
goto L_a448f;
}
L_a448f:{ // MOV dword ptr [ESP],EDX
c.pc=0xa448f;if(!sl_tick(c))return int(c.fault);
P_a448f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a448f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a448f_2:;
goto L_a4492;
}
L_a4492:{ // CALL dword ptr [EAX + 0x84]
c.pc=0xa4492;if(!sl_tick(c))return int(c.fault);
P_a4492_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x84ULL)),c);
P_a4492_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a4492_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4492_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4492_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4498ULL),c);
P_a4492_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a4492_6:;
goto L_a4498;
}
L_a4498:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xa4498;if(!sl_tick(c))return int(c.fault);
P_a4498_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a4498_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4498_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4498_3:;
goto L_a449b;
}
L_a449b:{ // MOV EDX,dword ptr [EAX]
c.pc=0xa449b;if(!sl_tick(c))return int(c.fault);
P_a449b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_a449b_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a449b_2:;
goto L_a449d;
}
L_a449d:{ // MOV dword ptr [ESP + 0xc],ESI
c.pc=0xa449d;if(!sl_tick(c))return int(c.fault);
P_a449d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a449d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a449d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a449d_3:;
goto L_a44a1;
}
L_a44a1:{ // MOV EAX,dword ptr [EBX + 0x591f2]
c.pc=0xa44a1;if(!sl_tick(c))return int(c.fault);
P_a44a1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x591f2ULL)),c);
P_a44a1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a44a1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a44a1_3:;
goto L_a44a7;
}
L_a44a7:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0xa44a7;if(!sl_tick(c))return int(c.fault);
P_a44a7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a44a7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a44a7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a44a7_3:;
goto L_a44ab;
}
L_a44ab:{ // MOV dword ptr [ESP + 0x4],EDI
c.pc=0xa44ab;if(!sl_tick(c))return int(c.fault);
P_a44ab_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a44ab_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a44ab_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a44ab_3:;
goto L_a44af;
}
L_a44af:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xa44af;if(!sl_tick(c))return int(c.fault);
P_a44af_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a44af_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a44af_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a44af_3:;
goto L_a44b2;
}
L_a44b2:{ // MOV dword ptr [ESP],EAX
c.pc=0xa44b2;if(!sl_tick(c))return int(c.fault);
P_a44b2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a44b2_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a44b2_2:;
goto L_a44b5;
}
L_a44b5:{ // CALL dword ptr [EDX + 0x3c]
c.pc=0xa44b5;if(!sl_tick(c))return int(c.fault);
P_a44b5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x3cULL)),c);
P_a44b5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a44b5_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a44b5_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a44b5_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa44b8ULL),c);
P_a44b5_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a44b5_6:;
goto L_a44b8;
}
L_a44b8:{ // MOV EAX,dword ptr [EDI]
c.pc=0xa44b8;if(!sl_tick(c))return int(c.fault);
P_a44b8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_a44b8_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a44b8_2:;
goto L_a44ba;
}
L_a44ba:{ // MOV dword ptr [ESP],EDI
c.pc=0xa44ba;if(!sl_tick(c))return int(c.fault);
P_a44ba_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a44ba_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a44ba_2:;
goto L_a44bd;
}
L_a44bd:{ // CALL dword ptr [EAX + 0x8]
c.pc=0xa44bd;if(!sl_tick(c))return int(c.fault);
P_a44bd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_a44bd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a44bd_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a44bd_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a44bd_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa44c0ULL),c);
P_a44bd_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a44bd_6:;
goto L_a44c0;
}
L_a44c0:{ // JMP 0x000a4351
c.pc=0xa44c0;if(!sl_tick(c))return int(c.fault);
P_a44c0_0:;
goto L_a4351;
P_a44c0_1:;
goto L_a44c5;
}
L_a44c5:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xa44c5;if(!sl_tick(c))return int(c.fault);
P_a44c5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a44c5_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a44c5_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a44c5_3:;
goto L_a44c8;
}
L_a44c8:{ // MOV EDX,dword ptr [EAX + 0x94]
c.pc=0xa44c8;if(!sl_tick(c))return int(c.fault);
P_a44c8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x94ULL)),c);
P_a44c8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a44c8_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a44c8_3:;
goto L_a44ce;
}
L_a44ce:{ // TEST EDX,EDX
c.pc=0xa44ce;if(!sl_tick(c))return int(c.fault);
P_a44ce_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a44ce_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a44ce_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a44ce_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a44ce_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a44ce_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a44ce_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a44ce_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a44ce_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a44ce_9:;
goto L_a44d0;
}
L_a44d0:{ // JZ 0x000a459f
c.pc=0xa44d0;if(!sl_tick(c))return int(c.fault);
P_a44d0_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a459f;}
P_a44d0_1:;
goto L_a44d6;
}
L_a44d6:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa44d6;if(!sl_tick(c))return int(c.fault);
P_a44d6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a44d6_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a44d6_2:;
goto L_a44d8;
}
L_a44d8:{ // MOV dword ptr [ESP],EDX
c.pc=0xa44d8;if(!sl_tick(c))return int(c.fault);
P_a44d8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a44d8_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a44d8_2:;
goto L_a44db;
}
L_a44db:{ // CALL dword ptr [EAX + 0xc]
c.pc=0xa44db;if(!sl_tick(c))return int(c.fault);
P_a44db_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0xcULL)),c);
P_a44db_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a44db_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a44db_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a44db_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa44deULL),c);
P_a44db_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a44db_6:;
goto L_a44de;
}
L_a44de:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xa44de;if(!sl_tick(c))return int(c.fault);
P_a44de_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a44de_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a44de_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a44de_3:;
goto L_a44e1;
}
L_a44e1:{ // MOV EDI,dword ptr [EDX + 0x94]
c.pc=0xa44e1;if(!sl_tick(c))return int(c.fault);
P_a44e1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x94ULL)),c);
P_a44e1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a44e1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a44e1_3:;
goto L_a44e7;
}
L_a44e7:{ // MOV dword ptr [EBP + -0x24],0x0
c.pc=0xa44e7;if(!sl_tick(c))return int(c.fault);
P_a44e7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_a44e7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a44e7_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a44e7_3:;
goto L_a44ee;
}
L_a44ee:{ // MOV dword ptr [EBP + -0x20],0x0
c.pc=0xa44ee;if(!sl_tick(c))return int(c.fault);
P_a44ee_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_a44ee_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a44ee_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a44ee_3:;
goto L_a44f5;
}
L_a44f5:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa44f5;if(!sl_tick(c))return int(c.fault);
P_a44f5_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a44f5_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a44f5_2:;
goto L_a44f7;
}
L_a44f7:{ // LEA ESI,[EBP + -0x24]
c.pc=0xa44f7;if(!sl_tick(c))return int(c.fault);
P_a44f7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_a44f7_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_a44f7_2:;
goto L_a44fa;
}
L_a44fa:{ // MOV dword ptr [ESP + 0x8],ESI
c.pc=0xa44fa;if(!sl_tick(c))return int(c.fault);
P_a44fa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a44fa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a44fa_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a44fa_3:;
goto L_a44fe;
}
L_a44fe:{ // MOV dword ptr [ESP + 0x4],EDI
c.pc=0xa44fe;if(!sl_tick(c))return int(c.fault);
P_a44fe_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a44fe_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a44fe_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a44fe_3:;
goto L_a4502;
}
L_a4502:{ // MOV dword ptr [ESP],EDX
c.pc=0xa4502;if(!sl_tick(c))return int(c.fault);
P_a4502_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a4502_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4502_2:;
goto L_a4505;
}
L_a4505:{ // CALL dword ptr [EAX + 0x84]
c.pc=0xa4505;if(!sl_tick(c))return int(c.fault);
P_a4505_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x84ULL)),c);
P_a4505_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a4505_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4505_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4505_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa450bULL),c);
P_a4505_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a4505_6:;
goto L_a450b;
}
L_a450b:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xa450b;if(!sl_tick(c))return int(c.fault);
P_a450b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a450b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a450b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a450b_3:;
goto L_a450e;
}
L_a450e:{ // MOV EDX,dword ptr [EAX]
c.pc=0xa450e;if(!sl_tick(c))return int(c.fault);
P_a450e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_a450e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a450e_2:;
goto L_a4510;
}
L_a4510:{ // MOV dword ptr [ESP + 0xc],ESI
c.pc=0xa4510;if(!sl_tick(c))return int(c.fault);
P_a4510_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4510_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a4510_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4510_3:;
goto L_a4514;
}
L_a4514:{ // MOV EAX,dword ptr [EBX + 0x591f2]
c.pc=0xa4514;if(!sl_tick(c))return int(c.fault);
P_a4514_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x591f2ULL)),c);
P_a4514_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a4514_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4514_3:;
goto L_a451a;
}
L_a451a:{ // MOV dword ptr [ESP + 0x8],EAX
c.pc=0xa451a;if(!sl_tick(c))return int(c.fault);
P_a451a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a451a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a451a_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a451a_3:;
goto L_a451e;
}
L_a451e:{ // MOV dword ptr [ESP + 0x4],EDI
c.pc=0xa451e;if(!sl_tick(c))return int(c.fault);
P_a451e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a451e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a451e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a451e_3:;
goto L_a4522;
}
L_a4522:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xa4522;if(!sl_tick(c))return int(c.fault);
P_a4522_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a4522_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4522_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4522_3:;
goto L_a4525;
}
L_a4525:{ // MOV dword ptr [ESP],EAX
c.pc=0xa4525;if(!sl_tick(c))return int(c.fault);
P_a4525_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4525_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4525_2:;
goto L_a4528;
}
L_a4528:{ // CALL dword ptr [EDX + 0x40]
c.pc=0xa4528;if(!sl_tick(c))return int(c.fault);
P_a4528_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x40ULL)),c);
P_a4528_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4528_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4528_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4528_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa452bULL),c);
P_a4528_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a4528_6:;
goto L_a452b;
}
L_a452b:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xa452b;if(!sl_tick(c))return int(c.fault);
P_a452b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a452b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a452b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a452b_3:;
goto L_a452e;
}
L_a452e:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa452e;if(!sl_tick(c))return int(c.fault);
P_a452e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a452e_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a452e_2:;
goto L_a4530;
}
L_a4530:{ // MOV dword ptr [ESP + 0x4],0x0
c.pc=0xa4530;if(!sl_tick(c))return int(c.fault);
P_a4530_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4530_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a4530_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a4530_3:;
goto L_a4538;
}
L_a4538:{ // MOV dword ptr [ESP],EDX
c.pc=0xa4538;if(!sl_tick(c))return int(c.fault);
P_a4538_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a4538_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4538_2:;
goto L_a453b;
}
L_a453b:{ // CALL dword ptr [EAX + 0x138]
c.pc=0xa453b;if(!sl_tick(c))return int(c.fault);
P_a453b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x138ULL)),c);
P_a453b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a453b_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a453b_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a453b_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4541ULL),c);
P_a453b_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a453b_6:;
goto L_a4541;
}
L_a4541:{ // MOV EAX,dword ptr [EDI]
c.pc=0xa4541;if(!sl_tick(c))return int(c.fault);
P_a4541_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c),c);
P_a4541_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4541_2:;
goto L_a4543;
}
L_a4543:{ // MOV dword ptr [ESP],EDI
c.pc=0xa4543;if(!sl_tick(c))return int(c.fault);
P_a4543_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a4543_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4543_2:;
goto L_a4546;
}
L_a4546:{ // CALL dword ptr [EAX + 0x8]
c.pc=0xa4546;if(!sl_tick(c))return int(c.fault);
P_a4546_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x8ULL)),c);
P_a4546_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4546_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4546_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4546_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4549ULL),c);
P_a4546_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a4546_6:;
goto L_a4549;
}
L_a4549:{ // MOV EAX,dword ptr [EBX + 0x591f2]
c.pc=0xa4549;if(!sl_tick(c))return int(c.fault);
P_a4549_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x591f2ULL)),c);
P_a4549_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a4549_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4549_3:;
goto L_a454f;
}
L_a454f:{ // MOV EDX,dword ptr [EAX]
c.pc=0xa454f;if(!sl_tick(c))return int(c.fault);
P_a454f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c),c);
P_a454f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a454f_2:;
goto L_a4551;
}
L_a4551:{ // MOV dword ptr [ESP],EAX
c.pc=0xa4551;if(!sl_tick(c))return int(c.fault);
P_a4551_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4551_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4551_2:;
goto L_a4554;
}
L_a4554:{ // CALL dword ptr [EDX + 0x8]
c.pc=0xa4554;if(!sl_tick(c))return int(c.fault);
P_a4554_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x8ULL)),c);
P_a4554_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4554_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x2f780,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4554_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4554_4:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4557ULL),c);
P_a4554_5:;
c.pc=SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x2f780,c));goto dispatch;
P_a4554_6:;
goto L_a4557;
}
L_a4557:{ // MOV dword ptr [EBX + 0x591f2],0x0
c.pc=0xa4557;if(!sl_tick(c))return int(c.fault);
P_a4557_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0xc,c) + SlU(0x591f2ULL)),c);
P_a4557_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a4557_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a4557_3:;
goto L_a4561;
}
L_a4561:{ // XOR EAX,EAX
c.pc=0xa4561;if(!sl_tick(c))return int(c.fault);
P_a4561_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a4561_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a4561_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) ^ sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_a4561_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4561_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_a4561_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_a4561_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4561_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4561_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4561_9:;
goto L_a4563;
}
L_a4563:{ // ADD ESP,0x3c
c.pc=0xa4563;if(!sl_tick(c))return int(c.fault);
P_a4563_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4563_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(0x3cULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x3cULL)))&(SlU(1)<<31))!=0),c);
P_a4563_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x3cULL)),c);
P_a4563_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4563_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_a4563_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_a4563_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4563_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4563_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4563_9:;
goto L_a4566;
}
L_a4566:{ // POP EBX
c.pc=0xa4566;if(!sl_tick(c))return int(c.fault);
P_a4566_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a4566_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a4566_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a4566_3:;
sl_put<4>(c.reg,sizeof(c.reg),0xc,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a4566_4:;
goto L_a4567;
}
L_a4567:{ // POP ESI
c.pc=0xa4567;if(!sl_tick(c))return int(c.fault);
P_a4567_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a4567_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a4567_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a4567_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a4567_4:;
goto L_a4568;
}
L_a4568:{ // POP EDI
c.pc=0xa4568;if(!sl_tick(c))return int(c.fault);
P_a4568_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a4568_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a4568_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a4568_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a4568_4:;
goto L_a4569;
}
L_a4569:{ // POP EBP
c.pc=0xa4569;if(!sl_tick(c))return int(c.fault);
P_a4569_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a4569_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a4569_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a4569_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a4569_4:;
goto L_a456a;
}
L_a456a:{ // RET
c.pc=0xa456a;if(!sl_tick(c))return int(c.fault);
P_a456a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a456a_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a456a_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_a456a_3:;
goto L_a456b;
}
L_a456b:{ // MOV ESI,dword ptr [EAX + 0x64]
c.pc=0xa456b;if(!sl_tick(c))return int(c.fault);
P_a456b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x64ULL)),c);
P_a456b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a456b_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a456b_3:;
goto L_a456e;
}
L_a456e:{ // MOV dword ptr [ESP],0x68
c.pc=0xa456e;if(!sl_tick(c))return int(c.fault);
P_a456e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x68ULL),c);
P_a456e_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a456e_2:;
goto L_a4575;
}
L_a4575:{ // CALL 0x00103064
c.pc=0xa4575;if(!sl_tick(c))return int(c.fault);
P_a4575_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4575_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa457aULL),c);
P_a4575_2:;
c.pc=0x103064;goto dispatch;
P_a4575_3:;
goto L_a457a;
}
L_a457a:{ // MOV EDI,EAX
c.pc=0xa457a;if(!sl_tick(c))return int(c.fault);
P_a457a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a457a_1:;
goto L_a457c;
}
L_a457c:{ // MOV dword ptr [ESP + 0xc],ESI
c.pc=0xa457c;if(!sl_tick(c))return int(c.fault);
P_a457c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a457c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a457c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a457c_3:;
goto L_a4580;
}
L_a4580:{ // MOV dword ptr [ESP + 0x8],0x0
c.pc=0xa4580;if(!sl_tick(c))return int(c.fault);
P_a4580_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4580_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a4580_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a4580_3:;
goto L_a4588;
}
L_a4588:{ // MOV EAX,dword ptr [EBP + 0x10]
c.pc=0xa4588;if(!sl_tick(c))return int(c.fault);
P_a4588_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a4588_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4588_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4588_3:;
goto L_a458b;
}
L_a458b:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xa458b;if(!sl_tick(c))return int(c.fault);
P_a458b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a458b_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a458b_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a458b_3:;
goto L_a458f;
}
L_a458f:{ // MOV dword ptr [ESP],EDI
c.pc=0xa458f;if(!sl_tick(c))return int(c.fault);
P_a458f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a458f_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a458f_2:;
goto L_a4592;
}
L_a4592:{ // CALL 0x000a171a
c.pc=0xa4592;if(!sl_tick(c))return int(c.fault);
P_a4592_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4592_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4597ULL),c);
P_a4592_2:;
c.pc=0xa171a;goto dispatch;
P_a4592_3:;
goto L_a4597;
}
L_a4597:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xa4597;if(!sl_tick(c))return int(c.fault);
P_a4597_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a4597_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4597_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4597_3:;
goto L_a459a;
}
L_a459a:{ // JMP 0x000a437d
c.pc=0xa459a;if(!sl_tick(c))return int(c.fault);
P_a459a_0:;
goto L_a437d;
P_a459a_1:;
goto L_a459f;
}
L_a459f:{ // MOV ESI,dword ptr [EAX + 0x64]
c.pc=0xa459f;if(!sl_tick(c))return int(c.fault);
P_a459f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x64ULL)),c);
P_a459f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a459f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a459f_3:;
goto L_a45a2;
}
L_a45a2:{ // MOV dword ptr [ESP],0x68
c.pc=0xa45a2;if(!sl_tick(c))return int(c.fault);
P_a45a2_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x68ULL),c);
P_a45a2_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a45a2_2:;
goto L_a45a9;
}
L_a45a9:{ // CALL 0x00103064
c.pc=0xa45a9;if(!sl_tick(c))return int(c.fault);
P_a45a9_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a45a9_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa45aeULL),c);
P_a45a9_2:;
c.pc=0x103064;goto dispatch;
P_a45a9_3:;
goto L_a45ae;
}
L_a45ae:{ // MOV EDI,EAX
c.pc=0xa45ae;if(!sl_tick(c))return int(c.fault);
P_a45ae_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a45ae_1:;
goto L_a45b0;
}
L_a45b0:{ // MOV dword ptr [ESP + 0xc],ESI
c.pc=0xa45b0;if(!sl_tick(c))return int(c.fault);
P_a45b0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a45b0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a45b0_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a45b0_3:;
goto L_a45b4;
}
L_a45b4:{ // MOV dword ptr [ESP + 0x8],0x0
c.pc=0xa45b4;if(!sl_tick(c))return int(c.fault);
P_a45b4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a45b4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a45b4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a45b4_3:;
goto L_a45bc;
}
L_a45bc:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xa45bc;if(!sl_tick(c))return int(c.fault);
P_a45bc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a45bc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a45bc_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a45bc_3:;
goto L_a45bf;
}
L_a45bf:{ // MOV dword ptr [ESP + 0x4],EDX
c.pc=0xa45bf;if(!sl_tick(c))return int(c.fault);
P_a45bf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a45bf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a45bf_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a45bf_3:;
goto L_a45c3;
}
L_a45c3:{ // MOV dword ptr [ESP],EAX
c.pc=0xa45c3;if(!sl_tick(c))return int(c.fault);
P_a45c3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a45c3_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a45c3_2:;
goto L_a45c6;
}
L_a45c6:{ // CALL 0x000a171a
c.pc=0xa45c6;if(!sl_tick(c))return int(c.fault);
P_a45c6_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a45c6_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa45cbULL),c);
P_a45c6_2:;
c.pc=0xa171a;goto dispatch;
P_a45c6_3:;
goto L_a45cb;
}
L_a45cb:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xa45cb;if(!sl_tick(c))return int(c.fault);
P_a45cb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a45cb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a45cb_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a45cb_3:;
goto L_a45ce;
}
L_a45ce:{ // JMP 0x000a44e7
c.pc=0xa45ce;if(!sl_tick(c))return int(c.fault);
P_a45ce_0:;
goto L_a44e7;
P_a45ce_1:;
goto L_a45d3;
}
L_a45d3:{ // MOV ESI,dword ptr [EAX + 0x64]
c.pc=0xa45d3;if(!sl_tick(c))return int(c.fault);
P_a45d3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x64ULL)),c);
P_a45d3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a45d3_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a45d3_3:;
goto L_a45d6;
}
L_a45d6:{ // MOV dword ptr [ESP],0x68
c.pc=0xa45d6;if(!sl_tick(c))return int(c.fault);
P_a45d6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x68ULL),c);
P_a45d6_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a45d6_2:;
goto L_a45dd;
}
L_a45dd:{ // CALL 0x00103064
c.pc=0xa45dd;if(!sl_tick(c))return int(c.fault);
P_a45dd_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a45dd_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa45e2ULL),c);
P_a45dd_2:;
c.pc=0x103064;goto dispatch;
P_a45dd_3:;
goto L_a45e2;
}
L_a45e2:{ // MOV EDI,EAX
c.pc=0xa45e2;if(!sl_tick(c))return int(c.fault);
P_a45e2_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a45e2_1:;
goto L_a45e4;
}
L_a45e4:{ // MOV dword ptr [ESP + 0xc],ESI
c.pc=0xa45e4;if(!sl_tick(c))return int(c.fault);
P_a45e4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0xcULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a45e4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a45e4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a45e4_3:;
goto L_a45e8;
}
L_a45e8:{ // MOV dword ptr [ESP + 0x8],0x0
c.pc=0xa45e8;if(!sl_tick(c))return int(c.fault);
P_a45e8_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a45e8_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a45e8_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a45e8_3:;
goto L_a45f0;
}
L_a45f0:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xa45f0;if(!sl_tick(c))return int(c.fault);
P_a45f0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a45f0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a45f0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a45f0_3:;
goto L_a45f3;
}
L_a45f3:{ // MOV dword ptr [ESP + 0x4],EDX
c.pc=0xa45f3;if(!sl_tick(c))return int(c.fault);
P_a45f3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a45f3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a45f3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a45f3_3:;
goto L_a45f7;
}
L_a45f7:{ // MOV dword ptr [ESP],EAX
c.pc=0xa45f7;if(!sl_tick(c))return int(c.fault);
P_a45f7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a45f7_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a45f7_2:;
goto L_a45fa;
}
L_a45fa:{ // CALL 0x000a171a
c.pc=0xa45fa;if(!sl_tick(c))return int(c.fault);
P_a45fa_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a45fa_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa45ffULL),c);
P_a45fa_2:;
c.pc=0xa171a;goto dispatch;
P_a45fa_3:;
goto L_a45ff;
}
L_a45ff:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xa45ff;if(!sl_tick(c))return int(c.fault);
P_a45ff_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a45ff_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a45ff_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a45ff_3:;
goto L_a4602;
}
L_a4602:{ // JMP 0x000a445e
c.pc=0xa4602;if(!sl_tick(c))return int(c.fault);
P_a4602_0:;
goto L_a445e;
P_a4602_1:;
c.pc=0xa4607;goto dispatch;
}
L_a4654:{ // PUSH EBP
c.pc=0xa4654;if(!sl_tick(c))return int(c.fault);
P_a4654_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x14,c),c);
P_a4654_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4654_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a4654_3:;
goto L_a4655;
}
L_a4655:{ // MOV EBP,ESP
c.pc=0xa4655;if(!sl_tick(c))return int(c.fault);
P_a4655_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.reg,sizeof(c.reg),0x10,c),c);
P_a4655_1:;
goto L_a4657;
}
L_a4657:{ // PUSH EDI
c.pc=0xa4657;if(!sl_tick(c))return int(c.fault);
P_a4657_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a4657_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4657_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a4657_3:;
goto L_a4658;
}
L_a4658:{ // PUSH ESI
c.pc=0xa4658;if(!sl_tick(c))return int(c.fault);
P_a4658_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x1e780,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a4658_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a4658_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x1e780,c),c);
P_a4658_3:;
goto L_a4659;
}
L_a4659:{ // SUB ESP,0x50
c.pc=0xa4659;if(!sl_tick(c))return int(c.fault);
P_a4659_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) < SlU(0x50ULL)),c);
P_a4659_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^SlU(0x50ULL))&(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)-SlU(0x50ULL)))&(SlU(1)<<31))!=0),c);
P_a4659_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x50ULL)),c);
P_a4659_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4659_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_a4659_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_a4659_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4659_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4659_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4659_9:;
goto L_a465c;
}
L_a465c:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0xa465c;if(!sl_tick(c))return int(c.fault);
P_a465c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_a465c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a465c_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a465c_3:;
goto L_a465f;
}
L_a465f:{ // CMP byte ptr [EAX + 0x88],0x0
c.pc=0xa465f;if(!sl_tick(c))return int(c.fault);
P_a465f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3380,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x88ULL)),c);
P_a465f_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3380,c)),c),c);
P_a465f_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_a465f_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_a465f_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_a465f_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_a465f_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_a465f_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_a465f_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_a465f_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a465f_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a465f_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a465f_12:;
goto L_a4666;
}
L_a4666:{ // JZ 0x000a47ae
c.pc=0xa4666;if(!sl_tick(c))return int(c.fault);
P_a4666_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a47ae;}
P_a4666_1:;
goto L_a466c;
}
L_a466c:{ // CMP byte ptr [EAX + 0x70],0x0
c.pc=0xa466c;if(!sl_tick(c))return int(c.fault);
P_a466c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x70ULL)),c);
P_a466c_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a466c_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_a466c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_a466c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_a466c_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_a466c_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_a466c_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_a466c_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_a466c_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a466c_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a466c_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a466c_12:;
goto L_a4670;
}
L_a4670:{ // JZ 0x000a47a7
c.pc=0xa4670;if(!sl_tick(c))return int(c.fault);
P_a4670_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a47a7;}
P_a4670_1:;
goto L_a4676;
}
L_a4676:{ // MOV EDX,dword ptr [EBP + 0x8]
c.pc=0xa4676;if(!sl_tick(c))return int(c.fault);
P_a4676_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_a4676_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4676_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4676_3:;
goto L_a4679;
}
L_a4679:{ // CMP byte ptr [EDX + 0x70],0x0
c.pc=0xa4679;if(!sl_tick(c))return int(c.fault);
P_a4679_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x70ULL)),c);
P_a4679_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4679_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_a4679_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_a4679_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_a4679_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_a4679_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_a4679_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_a4679_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_a4679_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4679_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4679_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4679_12:;
goto L_a467d;
}
L_a467d:{ // JNZ 0x000a47ba
c.pc=0xa467d;if(!sl_tick(c))return int(c.fault);
P_a467d_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_a467d_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){goto L_a47ba;}
P_a467d_2:;
goto L_a4683;
}
L_a4683:{ // MOV EDX,dword ptr [EBP + 0xc]
c.pc=0xa4683;if(!sl_tick(c))return int(c.fault);
P_a4683_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_a4683_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4683_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4683_3:;
goto L_a4686;
}
L_a4686:{ // TEST EDX,EDX
c.pc=0xa4686;if(!sl_tick(c))return int(c.fault);
P_a4686_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a4686_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a4686_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a4686_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4686_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a4686_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a4686_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4686_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4686_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4686_9:;
goto L_a4688;
}
L_a4688:{ // JZ 0x000a47c9
c.pc=0xa4688;if(!sl_tick(c))return int(c.fault);
P_a4688_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){c.pc=0xa47c9;goto dispatch;}
P_a4688_1:;
goto L_a468e;
}
L_a468e:{ // MOV byte ptr [EBP + -0x29],0x0
c.pc=0xa468e;if(!sl_tick(c))return int(c.fault);
P_a468e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd7ULL)),c);
P_a468e_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_a468e_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_a468e_3:;
goto L_a4692;
}
L_a4692:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0xa4692;if(!sl_tick(c))return int(c.fault);
P_a4692_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_a4692_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4692_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4692_3:;
goto L_a4695;
}
L_a4695:{ // MOV dword ptr [EBP + -0x18],0x0
c.pc=0xa4695;if(!sl_tick(c))return int(c.fault);
P_a4695_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_a4695_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a4695_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a4695_3:;
goto L_a469c;
}
L_a469c:{ // MOV dword ptr [EBP + -0x14],0x0
c.pc=0xa469c;if(!sl_tick(c))return int(c.fault);
P_a469c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_a469c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a469c_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a469c_3:;
goto L_a46a3;
}
L_a46a3:{ // MOV dword ptr [EBP + -0x10],0x0
c.pc=0xa46a3;if(!sl_tick(c))return int(c.fault);
P_a46a3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_a46a3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a46a3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a46a3_3:;
goto L_a46aa;
}
L_a46aa:{ // MOV dword ptr [EBP + -0xc],0x0
c.pc=0xa46aa;if(!sl_tick(c))return int(c.fault);
P_a46aa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_a46aa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5580,SlU(0x0ULL),c);
P_a46aa_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5580,c),c);
P_a46aa_3:;
goto L_a46b1;
}
L_a46b1:{ // MOV EDI,dword ptr [EAX + 0x50]
c.pc=0xa46b1;if(!sl_tick(c))return int(c.fault);
P_a46b1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x50ULL)),c);
P_a46b1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a46b1_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a46b1_3:;
goto L_a46b4;
}
L_a46b4:{ // MOV dword ptr [EBP + -0x18],EDI
c.pc=0xa46b4;if(!sl_tick(c))return int(c.fault);
P_a46b4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_a46b4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a46b4_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a46b4_3:;
goto L_a46b7;
}
L_a46b7:{ // MOV EDX,dword ptr [EAX + 0x54]
c.pc=0xa46b7;if(!sl_tick(c))return int(c.fault);
P_a46b7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x54ULL)),c);
P_a46b7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a46b7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a46b7_3:;
goto L_a46ba;
}
L_a46ba:{ // MOV dword ptr [EBP + -0x3c],EDX
c.pc=0xa46ba;if(!sl_tick(c))return int(c.fault);
P_a46ba_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc4ULL)),c);
P_a46ba_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a46ba_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a46ba_3:;
goto L_a46bd;
}
L_a46bd:{ // MOV dword ptr [EBP + -0x14],EDX
c.pc=0xa46bd;if(!sl_tick(c))return int(c.fault);
P_a46bd_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_a46bd_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a46bd_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a46bd_3:;
goto L_a46c0;
}
L_a46c0:{ // MOV ESI,dword ptr [EAX + 0x58]
c.pc=0xa46c0;if(!sl_tick(c))return int(c.fault);
P_a46c0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x58ULL)),c);
P_a46c0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a46c0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a46c0_3:;
goto L_a46c3;
}
L_a46c3:{ // MOV dword ptr [EBP + -0x10],ESI
c.pc=0xa46c3;if(!sl_tick(c))return int(c.fault);
P_a46c3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_a46c3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x18,c),c);
P_a46c3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a46c3_3:;
goto L_a46c6;
}
L_a46c6:{ // MOV ECX,dword ptr [EAX + 0x5c]
c.pc=0xa46c6;if(!sl_tick(c))return int(c.fault);
P_a46c6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x5cULL)),c);
P_a46c6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a46c6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a46c6_3:;
goto L_a46c9;
}
L_a46c9:{ // MOV dword ptr [EBP + -0x30],ECX
c.pc=0xa46c9;if(!sl_tick(c))return int(c.fault);
P_a46c9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd0ULL)),c);
P_a46c9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_a46c9_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a46c9_3:;
goto L_a46cc;
}
L_a46cc:{ // MOV dword ptr [EBP + -0xc],ECX
c.pc=0xa46cc;if(!sl_tick(c))return int(c.fault);
P_a46cc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_a46cc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_a46cc_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a46cc_3:;
goto L_a46cf;
}
L_a46cf:{ // MOV EDX,dword ptr [EAX + 0x14]
c.pc=0xa46cf;if(!sl_tick(c))return int(c.fault);
P_a46cf_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x14ULL)),c);
P_a46cf_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a46cf_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a46cf_3:;
goto L_a46d2;
}
L_a46d2:{ // NEG EDX
c.pc=0xa46d2;if(!sl_tick(c))return int(c.fault);
P_a46d2_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) != SlU(0x0ULL)),c);
P_a46d2_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((SlU(0x0ULL)^sl_get<4>(c.reg,sizeof(c.reg),0x8,c))&(SlU(0x0ULL)^(SlU(0x0ULL)-sl_get<4>(c.reg,sizeof(c.reg),0x8,c)))&(SlU(1)<<31))!=0),c);
P_a46d2_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,(SlU(0)-sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a46d2_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x8,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a46d2_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) == SlU(0x0ULL)),c);
P_a46d2_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & SlU(0xffULL)),c);
P_a46d2_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a46d2_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a46d2_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a46d2_9:;
goto L_a46d4;
}
L_a46d4:{ // MOV EAX,dword ptr [EAX + 0x10]
c.pc=0xa46d4;if(!sl_tick(c))return int(c.fault);
P_a46d4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + SlU(0x10ULL)),c);
P_a46d4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a46d4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a46d4_3:;
goto L_a46d7;
}
L_a46d7:{ // NEG EAX
c.pc=0xa46d7;if(!sl_tick(c))return int(c.fault);
P_a46d7_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) != SlU(0x0ULL)),c);
P_a46d7_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((SlU(0x0ULL)^sl_get<4>(c.reg,sizeof(c.reg),0x0,c))&(SlU(0x0ULL)^(SlU(0x0ULL)-sl_get<4>(c.reg,sizeof(c.reg),0x0,c)))&(SlU(1)<<31))!=0),c);
P_a46d7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(SlU(0)-sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_a46d7_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a46d7_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_a46d7_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_a46d7_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a46d7_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a46d7_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a46d7_9:;
goto L_a46d9;
}
L_a46d9:{ // LEA EDI,[EAX + EDI*0x1]
c.pc=0xa46d9;if(!sl_tick(c))return int(c.fault);
P_a46d9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x1c,c) * SlU(0x1ULL)),c);
P_a46d9_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_a46d9_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x3580,c),c);
P_a46d9_3:;
goto L_a46dc;
}
L_a46dc:{ // MOV dword ptr [EBP + -0x18],EDI
c.pc=0xa46dc;if(!sl_tick(c))return int(c.fault);
P_a46dc_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_a46dc_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x1c,c),c);
P_a46dc_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a46dc_3:;
goto L_a46df;
}
L_a46df:{ // ADD EAX,ESI
c.pc=0xa46df;if(!sl_tick(c))return int(c.fault);
P_a46df_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+sl_get<4>(c.reg,sizeof(c.reg),0x18,c))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_a46df_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+sl_get<4>(c.reg,sizeof(c.reg),0x18,c)))&(sl_get<4>(c.reg,sizeof(c.reg),0x18,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)+sl_get<4>(c.reg,sizeof(c.reg),0x18,c)))&(SlU(1)<<31))!=0),c);
P_a46df_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) + sl_get<4>(c.reg,sizeof(c.reg),0x18,c)),c);
P_a46df_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a46df_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_a46df_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_a46df_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a46df_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a46df_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a46df_9:;
goto L_a46e1;
}
L_a46e1:{ // MOV dword ptr [EBP + -0x10],EAX
c.pc=0xa46e1;if(!sl_tick(c))return int(c.fault);
P_a46e1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_a46e1_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a46e1_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a46e1_3:;
goto L_a46e4;
}
L_a46e4:{ // MOV EAX,dword ptr [EBP + -0x3c]
c.pc=0xa46e4;if(!sl_tick(c))return int(c.fault);
P_a46e4_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffc4ULL)),c);
P_a46e4_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a46e4_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a46e4_3:;
goto L_a46e7;
}
L_a46e7:{ // LEA ECX,[EDX + EAX*0x1]
c.pc=0xa46e7;if(!sl_tick(c))return int(c.fault);
P_a46e7_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x1ULL)),c);
P_a46e7_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_a46e7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x3580,c),c);
P_a46e7_3:;
goto L_a46ea;
}
L_a46ea:{ // MOV dword ptr [EBP + -0x14],ECX
c.pc=0xa46ea;if(!sl_tick(c))return int(c.fault);
P_a46ea_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_a46ea_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_a46ea_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a46ea_3:;
goto L_a46ed;
}
L_a46ed:{ // MOV EAX,dword ptr [EBP + -0x30]
c.pc=0xa46ed;if(!sl_tick(c))return int(c.fault);
P_a46ed_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd0ULL)),c);
P_a46ed_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a46ed_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a46ed_3:;
goto L_a46f0;
}
L_a46f0:{ // LEA ECX,[EDX + EAX*0x1]
c.pc=0xa46f0;if(!sl_tick(c))return int(c.fault);
P_a46f0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3480,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) * SlU(0x1ULL)),c);
P_a46f0_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x3580,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + sl_get<4>(c.temp,sizeof(c.temp),0x3480,c)),c);
P_a46f0_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x3580,c),c);
P_a46f0_3:;
goto L_a46f3;
}
L_a46f3:{ // MOV dword ptr [EBP + -0xc],ECX
c.pc=0xa46f3;if(!sl_tick(c))return int(c.fault);
P_a46f3_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff4ULL)),c);
P_a46f3_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_a46f3_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a46f3_3:;
goto L_a46f6;
}
L_a46f6:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xa46f6;if(!sl_tick(c))return int(c.fault);
P_a46f6_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a46f6_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a46f6_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a46f6_3:;
goto L_a46f9;
}
L_a46f9:{ // MOV EAX,dword ptr [EDX]
c.pc=0xa46f9;if(!sl_tick(c))return int(c.fault);
P_a46f9_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a46f9_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a46f9_2:;
goto L_a46fb;
}
L_a46fb:{ // MOV dword ptr [EBP + -0x28],EAX
c.pc=0xa46fb;if(!sl_tick(c))return int(c.fault);
P_a46fb_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd8ULL)),c);
P_a46fb_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a46fb_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a46fb_3:;
goto L_a46fe;
}
L_a46fe:{ // MOV EAX,dword ptr [EDX + 0x4]
c.pc=0xa46fe;if(!sl_tick(c))return int(c.fault);
P_a46fe_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x4ULL)),c);
P_a46fe_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a46fe_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a46fe_3:;
goto L_a4701;
}
L_a4701:{ // MOV dword ptr [EBP + -0x24],EAX
c.pc=0xa4701;if(!sl_tick(c))return int(c.fault);
P_a4701_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_a4701_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4701_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4701_3:;
goto L_a4704;
}
L_a4704:{ // MOV EAX,dword ptr [EDX + 0x8]
c.pc=0xa4704;if(!sl_tick(c))return int(c.fault);
P_a4704_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x8ULL)),c);
P_a4704_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4704_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4704_3:;
goto L_a4707;
}
L_a4707:{ // MOV dword ptr [EBP + -0x20],EAX
c.pc=0xa4707;if(!sl_tick(c))return int(c.fault);
P_a4707_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_a4707_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4707_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4707_3:;
goto L_a470a;
}
L_a470a:{ // MOV EAX,dword ptr [EDX + 0xc]
c.pc=0xa470a;if(!sl_tick(c))return int(c.fault);
P_a470a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0xcULL)),c);
P_a470a_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a470a_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a470a_3:;
goto L_a470d;
}
L_a470d:{ // MOV dword ptr [EBP + -0x1c],EAX
c.pc=0xa470d;if(!sl_tick(c))return int(c.fault);
P_a470d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_a470d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a470d_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a470d_3:;
goto L_a4710;
}
L_a4710:{ // CMP dword ptr [EBP + -0x28],EDI
c.pc=0xa4710;if(!sl_tick(c))return int(c.fault);
P_a4710_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd8ULL)),c);
P_a4710_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4710_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4710_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c);
P_a4710_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x1c,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)))&(SlU(1)<<31))!=0),c);
P_a4710_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x1c,c)),c);
P_a4710_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4710_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_a4710_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_a4710_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4710_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4710_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4710_12:;
goto L_a4713;
}
L_a4713:{ // JL 0x000a47f3
c.pc=0xa4713;if(!sl_tick(c))return int(c.fault);
P_a4713_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa180,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_a4713_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa180,c)){c.pc=0xa47f3;goto dispatch;}
P_a4713_2:;
goto L_a4719;
}
L_a4719:{ // MOV EDX,dword ptr [EBP + -0x14]
c.pc=0xa4719;if(!sl_tick(c))return int(c.fault);
P_a4719_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffecULL)),c);
P_a4719_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4719_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4719_3:;
goto L_a471c;
}
L_a471c:{ // CMP dword ptr [EBP + -0x24],EDX
c.pc=0xa471c;if(!sl_tick(c))return int(c.fault);
P_a471c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_a471c_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a471c_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a471c_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a471c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x8,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x8,c)))&(SlU(1)<<31))!=0),c);
P_a471c_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a471c_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a471c_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_a471c_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_a471c_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a471c_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a471c_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a471c_12:;
goto L_a471f;
}
L_a471f:{ // CMOVGE EDX,dword ptr [EBP + -0x24]
c.pc=0xa471f;if(!sl_tick(c))return int(c.fault);
P_a471f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_a471f_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa280,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_a471f_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a471f_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30380,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a471f_4:;
sl_put<1>(c.temp,sizeof(c.temp),0x30400,(!sl_get<1>(c.temp,sizeof(c.temp),0xa280,c)),c);
P_a471f_5:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x30400,c)){goto L_a4723;}
P_a471f_6:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x30380,c),c);
P_a471f_7:;
goto L_a4723;
}
L_a4723:{ // MOV dword ptr [EBP + -0x24],EDX
c.pc=0xa4723;if(!sl_tick(c))return int(c.fault);
P_a4723_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffdcULL)),c);
P_a4723_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a4723_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4723_3:;
goto L_a4726;
}
L_a4726:{ // MOV EAX,dword ptr [EBP + -0x10]
c.pc=0xa4726;if(!sl_tick(c))return int(c.fault);
P_a4726_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xfffffff0ULL)),c);
P_a4726_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4726_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4726_3:;
goto L_a4729;
}
L_a4729:{ // CMP dword ptr [EBP + -0x20],EAX
c.pc=0xa4729;if(!sl_tick(c))return int(c.fault);
P_a4729_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_a4729_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4729_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4729_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_a4729_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x0,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x0,c)))&(SlU(1)<<31))!=0),c);
P_a4729_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_a4729_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4729_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_a4729_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_a4729_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4729_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4729_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4729_12:;
goto L_a472c;
}
L_a472c:{ // CMOVLE EAX,dword ptr [EBP + -0x20]
c.pc=0xa472c;if(!sl_tick(c))return int(c.fault);
P_a472c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_a472c_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_a472c_2:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_a472c_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a472c_4:;
sl_put<4>(c.temp,sizeof(c.temp),0x30380,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a472c_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30400,(!sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)),c);
P_a472c_6:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x30400,c)){goto L_a4730;}
P_a472c_7:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x30380,c),c);
P_a472c_8:;
goto L_a4730;
}
L_a4730:{ // MOV dword ptr [EBP + -0x20],EAX
c.pc=0xa4730;if(!sl_tick(c))return int(c.fault);
P_a4730_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_a4730_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4730_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4730_3:;
goto L_a4733;
}
L_a4733:{ // CMP ECX,dword ptr [EBP + -0x1c]
c.pc=0xa4733;if(!sl_tick(c))return int(c.fault);
P_a4733_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_a4733_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4733_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31800,sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4733_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) < sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_a4733_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x4,c)^sl_get<4>(c.temp,sizeof(c.temp),0x31800,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x4,c)-sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)))&(SlU(1)<<31))!=0),c);
P_a4733_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31900,(sl_get<4>(c.reg,sizeof(c.reg),0x4,c) - sl_get<4>(c.temp,sizeof(c.temp),0x31800,c)),c);
P_a4733_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4733_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) == SlU(0x0ULL)),c);
P_a4733_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31900,c) & SlU(0xffULL)),c);
P_a4733_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4733_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4733_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4733_12:;
goto L_a4736;
}
L_a4736:{ // MOV EAX,dword ptr [EBP + -0x1c]
c.pc=0xa4736;if(!sl_tick(c))return int(c.fault);
P_a4736_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_a4736_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4736_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4736_3:;
goto L_a4739;
}
L_a4739:{ // CMOVL EAX,ECX
c.pc=0xa4739;if(!sl_tick(c))return int(c.fault);
P_a4739_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa180,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_a4739_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x30380,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_a4739_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30400,(!sl_get<1>(c.temp,sizeof(c.temp),0xa180,c)),c);
P_a4739_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x30400,c)){goto L_a473c;}
P_a4739_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x30380,c),c);
P_a4739_5:;
goto L_a473c;
}
L_a473c:{ // CMP EAX,EDX
c.pc=0xa473c;if(!sl_tick(c))return int(c.fault);
P_a473c_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a473c_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a473c_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x8,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x8,c)))&(SlU(1)<<31))!=0),c);
P_a473c_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a473c_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a473c_5:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_a473c_6:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_a473c_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a473c_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a473c_9:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a473c_10:;
goto L_a473e;
}
L_a473e:{ // CMOVGE EDX,EAX
c.pc=0xa473e;if(!sl_tick(c))return int(c.fault);
P_a473e_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa280,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_a473e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x30380,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a473e_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30400,(!sl_get<1>(c.temp,sizeof(c.temp),0xa280,c)),c);
P_a473e_3:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x30400,c)){goto L_a4741;}
P_a473e_4:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x30380,c),c);
P_a473e_5:;
goto L_a4741;
}
L_a4741:{ // MOV dword ptr [EBP + -0x1c],EDX
c.pc=0xa4741;if(!sl_tick(c))return int(c.fault);
P_a4741_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe4ULL)),c);
P_a4741_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a4741_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4741_3:;
goto L_a4744;
}
L_a4744:{ // MOV EAX,dword ptr [EBP + -0x28]
c.pc=0xa4744;if(!sl_tick(c))return int(c.fault);
P_a4744_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd8ULL)),c);
P_a4744_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4744_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4744_3:;
goto L_a4747;
}
L_a4747:{ // CMP dword ptr [EBP + -0x20],EAX
c.pc=0xa4747;if(!sl_tick(c))return int(c.fault);
P_a4747_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_a4747_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4747_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x31200,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4747_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) < sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_a4747_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^sl_get<4>(c.reg,sizeof(c.reg),0x0,c))&(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)^(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c)-sl_get<4>(c.reg,sizeof(c.reg),0x0,c)))&(SlU(1)<<31))!=0),c);
P_a4747_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x31300,(sl_get<4>(c.temp,sizeof(c.temp),0x31200,c) - sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_a4747_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4747_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) == SlU(0x0ULL)),c);
P_a4747_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x31300,c) & SlU(0xffULL)),c);
P_a4747_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4747_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4747_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4747_12:;
goto L_a474a;
}
L_a474a:{ // CMOVGE EAX,dword ptr [EBP + -0x20]
c.pc=0xa474a;if(!sl_tick(c))return int(c.fault);
P_a474a_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_a474a_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa280,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) == sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_a474a_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a474a_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x30380,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a474a_4:;
sl_put<1>(c.temp,sizeof(c.temp),0x30400,(!sl_get<1>(c.temp,sizeof(c.temp),0xa280,c)),c);
P_a474a_5:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x30400,c)){goto L_a474e;}
P_a474a_6:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x30380,c),c);
P_a474a_7:;
goto L_a474e;
}
L_a474e:{ // MOV dword ptr [EBP + -0x20],EAX
c.pc=0xa474e;if(!sl_tick(c))return int(c.fault);
P_a474e_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe0ULL)),c);
P_a474e_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a474e_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a474e_3:;
goto L_a4751;
}
L_a4751:{ // LEA EAX,[EBP + -0x28]
c.pc=0xa4751;if(!sl_tick(c))return int(c.fault);
P_a4751_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd8ULL)),c);
P_a4751_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_a4751_2:;
goto L_a4754;
}
L_a4754:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xa4754;if(!sl_tick(c))return int(c.fault);
P_a4754_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4754_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4754_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4754_3:;
goto L_a4758;
}
L_a4758:{ // MOV EAX,dword ptr [EBP + 0xc]
c.pc=0xa4758;if(!sl_tick(c))return int(c.fault);
P_a4758_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_a4758_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4758_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4758_3:;
goto L_a475b;
}
L_a475b:{ // MOV dword ptr [ESP],EAX
c.pc=0xa475b;if(!sl_tick(c))return int(c.fault);
P_a475b_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a475b_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a475b_2:;
goto L_a475e;
}
L_a475e:{ // CALL 0x000a08c2
c.pc=0xa475e;if(!sl_tick(c))return int(c.fault);
P_a475e_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a475e_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa4763ULL),c);
P_a475e_2:;
c.pc=0xa08c2;goto dispatch;
P_a475e_3:;
goto L_a4763;
}
L_a4763:{ // MOV EDX,dword ptr [EBP + 0x10]
c.pc=0xa4763;if(!sl_tick(c))return int(c.fault);
P_a4763_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x10ULL)),c);
P_a4763_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4763_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4763_3:;
goto L_a4766;
}
L_a4766:{ // MOV EAX,dword ptr [EDX + 0x8]
c.pc=0xa4766;if(!sl_tick(c))return int(c.fault);
P_a4766_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x8ULL)),c);
P_a4766_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4766_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4766_3:;
goto L_a4769;
}
L_a4769:{ // SUB EAX,dword ptr [EDX]
c.pc=0xa4769;if(!sl_tick(c))return int(c.fault);
P_a4769_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a4769_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < sl_get<4>(c.temp,sizeof(c.temp),0x9680,c)),c);
P_a4769_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a4769_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^sl_get<4>(c.temp,sizeof(c.temp),0x9680,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-sl_get<4>(c.temp,sizeof(c.temp),0x9680,c)))&(SlU(1)<<31))!=0),c);
P_a4769_4:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c),c);
P_a4769_5:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - sl_get<4>(c.temp,sizeof(c.temp),0x9680,c)),c);
P_a4769_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4769_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_a4769_8:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_a4769_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4769_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4769_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4769_12:;
goto L_a476b;
}
L_a476b:{ // TEST EAX,EAX
c.pc=0xa476b;if(!sl_tick(c))return int(c.fault);
P_a476b_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a476b_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a476b_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_a476b_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a476b_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a476b_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a476b_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a476b_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a476b_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a476b_9:;
goto L_a476d;
}
L_a476d:{ // JLE 0x000a478f
c.pc=0xa476d;if(!sl_tick(c))return int(c.fault);
P_a476d_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_a476d_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_a476d_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_a478f;}
P_a476d_3:;
goto L_a476f;
}
L_a476f:{ // MOV EAX,dword ptr [EDX + 0xc]
c.pc=0xa476f;if(!sl_tick(c))return int(c.fault);
P_a476f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0xcULL)),c);
P_a476f_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a476f_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a476f_3:;
goto L_a4772;
}
L_a4772:{ // SUB EAX,dword ptr [EDX + 0x4]
c.pc=0xa4772;if(!sl_tick(c))return int(c.fault);
P_a4772_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x4ULL)),c);
P_a4772_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4772_2:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) < sl_get<4>(c.temp,sizeof(c.temp),0x9680,c)),c);
P_a4772_3:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4772_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^sl_get<4>(c.temp,sizeof(c.temp),0x9680,c))&(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x0,c)-sl_get<4>(c.temp,sizeof(c.temp),0x9680,c)))&(SlU(1)<<31))!=0),c);
P_a4772_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4772_6:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) - sl_get<4>(c.temp,sizeof(c.temp),0x9680,c)),c);
P_a4772_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x0,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4772_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) == SlU(0x0ULL)),c);
P_a4772_9:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & SlU(0xffULL)),c);
P_a4772_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4772_11:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4772_12:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4772_13:;
goto L_a4775;
}
L_a4775:{ // TEST EAX,EAX
c.pc=0xa4775;if(!sl_tick(c))return int(c.fault);
P_a4775_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a4775_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a4775_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x0,c) & sl_get<4>(c.reg,sizeof(c.reg),0x0,c)),c);
P_a4775_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a4775_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a4775_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a4775_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a4775_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a4775_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a4775_9:;
goto L_a4777;
}
L_a4777:{ // JLE 0x000a478f
c.pc=0xa4777;if(!sl_tick(c))return int(c.fault);
P_a4777_0:;
sl_put<1>(c.temp,sizeof(c.temp),0xa300,(sl_get<1>(c.reg,sizeof(c.reg),0x20b,c) != sl_get<1>(c.reg,sizeof(c.reg),0x207,c)),c);
P_a4777_1:;
sl_put<1>(c.temp,sizeof(c.temp),0xa400,(bool(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)) || bool(sl_get<1>(c.temp,sizeof(c.temp),0xa300,c))),c);
P_a4777_2:;
if(sl_get<1>(c.temp,sizeof(c.temp),0xa400,c)){goto L_a478f;}
P_a4777_3:;
goto L_a4779;
}
L_a4779:{ // MOV dword ptr [ESP + 0x8],EDX
c.pc=0xa4779;if(!sl_tick(c))return int(c.fault);
P_a4779_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x8ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4779_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a4779_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4779_3:;
goto L_a477d;
}
L_a477d:{ // MOV ECX,dword ptr [EBP + 0xc]
c.pc=0xa477d;if(!sl_tick(c))return int(c.fault);
P_a477d_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_a477d_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a477d_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x4,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a477d_3:;
goto L_a4780;
}
L_a4780:{ // MOV dword ptr [ESP + 0x4],ECX
c.pc=0xa4780;if(!sl_tick(c))return int(c.fault);
P_a4780_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4780_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x4,c),c);
P_a4780_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4780_3:;
goto L_a4784;
}
L_a4784:{ // MOV EAX,dword ptr [EBP + 0x8]
c.pc=0xa4784;if(!sl_tick(c))return int(c.fault);
P_a4784_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0x8ULL)),c);
P_a4784_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4784_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4784_3:;
goto L_a4787;
}
L_a4787:{ // MOV dword ptr [ESP],EAX
c.pc=0xa4787;if(!sl_tick(c))return int(c.fault);
P_a4787_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4787_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4787_2:;
goto L_a478a;
}
L_a478a:{ // CALL 0x000a2390
c.pc=0xa478a;if(!sl_tick(c))return int(c.fault);
P_a478a_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a478a_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa478fULL),c);
P_a478a_2:;
c.pc=0xa2390;goto dispatch;
P_a478a_3:;
goto L_a478f;
}
L_a478f:{ // LEA EAX,[EBP + -0x18]
c.pc=0xa478f;if(!sl_tick(c))return int(c.fault);
P_a478f_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffe8ULL)),c);
P_a478f_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x0,sl_get<4>(c.temp,sizeof(c.temp),0x3280,c),c);
P_a478f_2:;
goto L_a4792;
}
L_a4792:{ // MOV dword ptr [ESP + 0x4],EAX
c.pc=0xa4792;if(!sl_tick(c))return int(c.fault);
P_a4792_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3a80,(SlU(0x4ULL) + sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a4792_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a4792_2:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3a80,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4792_3:;
goto L_a4796;
}
L_a4796:{ // MOV EDX,dword ptr [EBP + 0xc]
c.pc=0xa4796;if(!sl_tick(c))return int(c.fault);
P_a4796_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_a4796_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a4796_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a4796_3:;
goto L_a4799;
}
L_a4799:{ // MOV dword ptr [ESP],EDX
c.pc=0xa4799;if(!sl_tick(c))return int(c.fault);
P_a4799_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x5200,sl_get<4>(c.reg,sizeof(c.reg),0x8,c),c);
P_a4799_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),sl_get<4>(c.temp,sizeof(c.temp),0x5200,c),c);
P_a4799_2:;
goto L_a479c;
}
L_a479c:{ // CALL 0x000a08c2
c.pc=0xa479c;if(!sl_tick(c))return int(c.fault);
P_a479c_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) - SlU(0x4ULL)),c);
P_a479c_1:;
sl_put<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),SlU(0xa47a1ULL),c);
P_a479c_2:;
c.pc=0xa08c2;goto dispatch;
P_a479c_3:;
goto L_a47a1;
}
L_a47a1:{ // CMP byte ptr [EBP + -0x29],0x0
c.pc=0xa47a1;if(!sl_tick(c))return int(c.fault);
P_a47a1_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xffffffd7ULL)),c);
P_a47a1_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a47a1_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_a47a1_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_a47a1_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_a47a1_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_a47a1_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_a47a1_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_a47a1_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_a47a1_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a47a1_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a47a1_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a47a1_12:;
goto L_a47a5;
}
L_a47a5:{ // JNZ 0x000a47fb
c.pc=0xa47a5;if(!sl_tick(c))return int(c.fault);
P_a47a5_0:;
sl_put<1>(c.temp,sizeof(c.temp),0x9c00,(!sl_get<1>(c.reg,sizeof(c.reg),0x206,c)),c);
P_a47a5_1:;
if(sl_get<1>(c.temp,sizeof(c.temp),0x9c00,c)){c.pc=0xa47fb;goto dispatch;}
P_a47a5_2:;
goto L_a47a7;
}
L_a47a7:{ // ADD ESP,0x50
c.pc=0xa47a7;if(!sl_tick(c))return int(c.fault);
P_a47a7_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x50ULL))&sl_mask(32))<sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c);
P_a47a7_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<4>(c.reg,sizeof(c.reg),0x10,c)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x50ULL)))&(SlU(0x50ULL)^(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)+SlU(0x50ULL)))&(SlU(1)<<31))!=0),c);
P_a47a7_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x50ULL)),c);
P_a47a7_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.reg,sizeof(c.reg),0x10,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a47a7_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) == SlU(0x0ULL)),c);
P_a47a7_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) & SlU(0xffULL)),c);
P_a47a7_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a47a7_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a47a7_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a47a7_9:;
goto L_a47aa;
}
L_a47aa:{ // POP ESI
c.pc=0xa47aa;if(!sl_tick(c))return int(c.fault);
P_a47aa_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a47aa_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a47aa_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a47aa_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x18,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a47aa_4:;
goto L_a47ab;
}
L_a47ab:{ // POP EDI
c.pc=0xa47ab;if(!sl_tick(c))return int(c.fault);
P_a47ab_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a47ab_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a47ab_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a47ab_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x1c,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a47ab_4:;
goto L_a47ac;
}
L_a47ac:{ // POP EBP
c.pc=0xa47ac;if(!sl_tick(c))return int(c.fault);
P_a47ac_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,SlU(0x0ULL),c);
P_a47ac_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x41780,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a47ac_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a47ac_3:;
sl_put<4>(c.reg,sizeof(c.reg),0x14,sl_get<4>(c.temp,sizeof(c.temp),0x41780,c),c);
P_a47ac_4:;
goto L_a47ad;
}
L_a47ad:{ // RET
c.pc=0xa47ad;if(!sl_tick(c))return int(c.fault);
P_a47ad_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x284,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x10,c)),c),c);
P_a47ad_1:;
sl_put<4>(c.reg,sizeof(c.reg),0x10,(sl_get<4>(c.reg,sizeof(c.reg),0x10,c) + SlU(0x4ULL)),c);
P_a47ad_2:;
c.pc=SlU32(sl_get<4>(c.reg,sizeof(c.reg),0x284,c));goto dispatch;
P_a47ad_3:;
goto L_a47ae;
}
L_a47ae:{ // MOV EDX,EAX
c.pc=0xa47ae;if(!sl_tick(c))return int(c.fault);
P_a47ae_0:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.reg,sizeof(c.reg),0x0,c),c);
P_a47ae_1:;
goto L_a47b0;
}
L_a47b0:{ // CMP byte ptr [EDX + 0x70],0x0
c.pc=0xa47b0;if(!sl_tick(c))return int(c.fault);
P_a47b0_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x70ULL)),c);
P_a47b0_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x9500,sl_get<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a47b0_2:;
sl_put<1>(c.temp,sizeof(c.temp),0x30780,sl_get<1>(c.temp,sizeof(c.temp),0x9500,c),c);
P_a47b0_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) < SlU(0x0ULL)),c);
P_a47b0_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,(((sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^SlU(0x0ULL))&(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)^(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c)-SlU(0x0ULL)))&(SlU(1)<<7))!=0),c);
P_a47b0_5:;
sl_put<1>(c.temp,sizeof(c.temp),0x30880,(sl_get<1>(c.temp,sizeof(c.temp),0x30780,c) - SlU(0x0ULL)),c);
P_a47b0_6:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c),8) < sl_signed(SlU(0x0ULL),8)),c);
P_a47b0_7:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) == SlU(0x0ULL)),c);
P_a47b0_8:;
sl_put<1>(c.temp,sizeof(c.temp),0x22900,(sl_get<1>(c.temp,sizeof(c.temp),0x30880,c) & SlU(0xffULL)),c);
P_a47b0_9:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<1>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a47b0_10:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a47b0_11:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a47b0_12:;
goto L_a47b4;
}
L_a47b4:{ // JZ 0x000a4683
c.pc=0xa47b4;if(!sl_tick(c))return int(c.fault);
P_a47b4_0:;
if(sl_get<1>(c.reg,sizeof(c.reg),0x206,c)){goto L_a4683;}
P_a47b4_1:;
goto L_a47ba;
}
L_a47ba:{ // MOV byte ptr [EDX + 0x70],0x0
c.pc=0xa47ba;if(!sl_tick(c))return int(c.fault);
P_a47ba_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) + SlU(0x70ULL)),c);
P_a47ba_1:;
sl_put<1>(c.temp,sizeof(c.temp),0x5480,SlU(0x0ULL),c);
P_a47ba_2:;
sl_put<1>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),sl_get<1>(c.temp,sizeof(c.temp),0x5480,c),c);
P_a47ba_3:;
goto L_a47be;
}
L_a47be:{ // MOV EDX,dword ptr [EBP + 0xc]
c.pc=0xa47be;if(!sl_tick(c))return int(c.fault);
P_a47be_0:;
sl_put<4>(c.temp,sizeof(c.temp),0x3280,(sl_get<4>(c.reg,sizeof(c.reg),0x14,c) + SlU(0xcULL)),c);
P_a47be_1:;
sl_put<4>(c.temp,sizeof(c.temp),0x9680,sl_get<4>(c.memory,c.memory_size,SlU32(sl_get<4>(c.temp,sizeof(c.temp),0x3280,c)),c),c);
P_a47be_2:;
sl_put<4>(c.reg,sizeof(c.reg),0x8,sl_get<4>(c.temp,sizeof(c.temp),0x9680,c),c);
P_a47be_3:;
goto L_a47c1;
}
L_a47c1:{ // TEST EDX,EDX
c.pc=0xa47c1;if(!sl_tick(c))return int(c.fault);
P_a47c1_0:;
sl_put<1>(c.reg,sizeof(c.reg),0x200,SlU(0x0ULL),c);
P_a47c1_1:;
sl_put<1>(c.reg,sizeof(c.reg),0x20b,SlU(0x0ULL),c);
P_a47c1_2:;
sl_put<4>(c.temp,sizeof(c.temp),0x54f80,(sl_get<4>(c.reg,sizeof(c.reg),0x8,c) & sl_get<4>(c.reg,sizeof(c.reg),0x8,c)),c);
P_a47c1_3:;
sl_put<1>(c.reg,sizeof(c.reg),0x207,(sl_signed(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c),32) < sl_signed(SlU(0x0ULL),32)),c);
P_a47c1_4:;
sl_put<1>(c.reg,sizeof(c.reg),0x206,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) == SlU(0x0ULL)),c);
P_a47c1_5:;
sl_put<4>(c.temp,sizeof(c.temp),0x22900,(sl_get<4>(c.temp,sizeof(c.temp),0x54f80,c) & SlU(0xffULL)),c);
P_a47c1_6:;
sl_put<1>(c.temp,sizeof(c.temp),0x22980,sl_popcount(sl_get<4>(c.temp,sizeof(c.temp),0x22900,c)),c);
P_a47c1_7:;
sl_put<1>(c.temp,sizeof(c.temp),0x22a00,(sl_get<1>(c.temp,sizeof(c.temp),0x22980,c) & SlU(0x1ULL)),c);
P_a47c1_8:;
sl_put<1>(c.reg,sizeof(c.reg),0x202,(sl_get<1>(c.temp,sizeof(c.temp),0x22a00,c) == SlU(0x0ULL)),c);
P_a47c1_9:;
c.pc=0xa47c3;goto dispatch;
}
}
