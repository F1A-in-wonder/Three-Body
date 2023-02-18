
#include<iostream>
#include <easyx.h>
#include <time.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
using namespace std;
// 窗口宽高
int nWindowWidth = 1280;
int nWindowHeight = 480;

int font_h = 200;					// 文字高
int font_w = 20;					// 文字宽
short nStartLightness = 255;		// 初始亮度
short nEndLightness = 60;			// 最终亮度
float fEndWidthRatio = (float)0.65;	// 宽度缩放比例
float fEndHeightRatio = (float)0.3;	// 高度缩放比例

int fps = 96;		// 帧率
int nAmount = 2;	// 文字单次位移         2
string pszText;
int yy;
int sss=-4;//kai shi

string jin(int den);



/*
// 文本
wchar_t pszText[] =
L"Irish Song\n"
L"The star may dissolve, and the fountain of light\n"
L"May sink intoe'er ending chao's and night,\n"
L"Our mansions must fall and earth vanish away;\n"
L"But thy courage, O Erin! may never decay.\n"
L"See! the wide wasting ruin extends all around,\n"
L"Our ancestors' dwellings lie sunk on the ground,\n"
L"Our foes ride in triumph throughout our domains,\n"
L"And our mightiest horoes streched on the plains.\n"
L"Ah! dead is the harp which was wont to give pleasure,\n"
L"Ah! sunk in our sweet country's rapturous measure,\n"
L"But the war note is weaked, and the clangour of spears,\n"
L"The dread yell of Slogan yet sounds in our ears.\n"
L"Ah! where are the heroes! triumphant in death,\n"
L"Convulsed they recline on the blood-sprinkled heath,\n"
L"Or the yelling ghosts ride on the blast that sweeps by,\n"
L"And my countrymen! vengeance! incessantly cry.\n";
//L"张若虚《春江花月夜》\n"
//L"春江潮水连海平，海上明月共潮生。\n"
//L"滟滟随波千万里，何处春江无月明。\n"
//L"江流宛转绕芳甸，月照花林皆似霰。\n"
//L"空里流霜不觉飞，汀上白沙看不见。\n"
//L"江天一色无纤尘，皎皎空中孤月轮。\n"
//L"江畔何人初见月？江月何年初照人？\n"
//L"人生代代无穷已，江月年年只相似。\n"
//L"不知江月待何人，但见长江送流水。\n"
//L"白云一片去悠悠，青枫浦上不胜愁。\n"
//L"谁家今夜扁舟子，何处相思明月楼？\n"
//L"可怜楼上月徘徊，应照离人妆镜台。\n"
//L"玉户帘中卷不去，捣衣砧上拂还来。\n"
//L"此时相望不相闻，愿逐月华流照君。\n"
//L"鸿雁长飞光不度，鱼龙潜跃水成文。\n"
//L"昨夜闲潭梦落花，可怜春半不还家。\n"
//L"江水流春去欲尽，江潭落月复西斜。\n"
//L"斜月沉沉藏海雾，碣石潇湘无限路。\n"
//L"不知乘月几人归，落月摇情满江树。\n";
这一夜持续了四十八年，第137号文明在严寒中毁灭了，该文明进化至战国层次。文明的种子仍在，它将重新启动，再次开始在三体世界中命运莫测的进化，欢迎您再次登录。
第141号文明在烈焰中毁灭了，该文明进化至东汉层次。文明的种子仍在，她将重新启动，再次开始在三体世界中命运莫测地进化，欢迎您再次登录。
183号文明在“三日凌空”中毁灭了，该文明进化至中世纪层次。漫长的时间后，生命和文明将重新启动，再次开始在三体世界中命运莫测的进化。但在这次文明中，哥白尼成功地揭示了宇宙的基本结构，三体文明将产生第一次飞跃，游戏进入第二级。欢迎您登录第二级《三体》。
第184号文明在“三日连珠”的引力叠加中毁灭了，该文明进化至科学革命和工业革命。这次文明中，牛顿建立了低速状态下的经典力学体系，同时，由于微积分和冯·诺伊曼结构计算机的发明，奠定了对三体运动进行定量数学分析的基础。漫长的时间后，生命和文明将重新启动，再次开始在三体世界中命运莫测的进化。欢迎再次登录。
四百五十一年后，192号文明在双日凌空的烈焰中毁灭，它进化到原子和信息时代。

        192号文明是三体文明的里程碑，它最终证明了三体问题的不可解，放弃了已延续191轮文明的徒劳努力，确定了今后文明全新的走向。至此，《三体》游戏的最终目标发生变化，新的目标是：

        飞向宇宙，寻找新的家园。

        欢迎再次登录。
三体文明对新世界的远征开始了，舰队正在航程中……

        《三体》游戏结束了，当您回到现实时，如果忠于自己曾做出的承诺，请按随后发给您的电子邮件中的地址，参加地球三体组织的聚会。

    启动游戏后，汪淼置身于一片黎明之际的荒原，荒原呈暗褐色，细节看不清楚，远方地平线上有一小片白色的曙光，其余的天空则群星闪烁。一声巨响，两座发着红光的山峰砸落到远方的大地上，整个荒原笼罩在红色光芒之中。被激起的遮天蔽日的尘埃散去后，汪淼看清了那两个顶天立地的大字：三体。

        随后出现了一个注册界面，汪淼用“海人”这个ID注册，然后成功登录。
*/
void world(int tim){
	for(int i=0;i<20;i++){
		pszText=" ";
	}
  switch(tim){
  case 137:{
  	//
  	pszText+="一夜持续了四十八年，\n";
  	pszText+="第137号文明在严寒中毁灭了，\n";
  	pszText+="这该文明进化至战国层次。\n";
  	pszText+="文明的种子仍在，它将重新启动，\n";
  	pszText+="再次开始在三体世界中命运莫测的进化，\n";
  	pszText+="欢迎您再次登录。";
	break;
  }
  case 141:{
  	//
  	pszText+="第141号文明在烈焰中毁灭了，\n";
  	pszText+="文明进化至东汉层次。\n";
  	pszText+="该文明的种子仍在，她将重新启动，\n";
  	pszText+="次开始在三体世界中命运莫测地进化，\n";
  	pszText+="再欢迎您再次登录。";
	break;
  }
  case 183:{
  	//
	pszText+="183号文明在“三日凌空”中毁灭了，\n";
	pszText+="该文明进化至中世纪层次。\n";
	pszText+="漫长的时间后，生命和文明将重新启动，\n";
	pszText+="再次开始在三体世界中命运莫测的进化。\n";
	pszText+="但在这次文明中，哥白尼成功地揭示了宇宙的基本结构，\n";
	pszText+="三体文明将产生第一次飞跃，游戏进入第二级。\n";
	pszText+="欢迎您登录第二级《三体》。";
	break;
  }
  case 184:{
  	//
	pszText+="第184号文明在“三日连珠”的引力叠加中毁灭了，\n";
	pszText+="该文明进化至科学革命和工业革命。\n";
	pszText+="这次文明中，牛顿建立了低速状态下的经典力学体系，\n";
	pszText+="同时，由于微积分和冯·诺伊曼结构计算机的发明，\n";
	pszText+="奠定了对三体运动进行定量数学分析的基础。\n";
	pszText+="漫长的时间后，生命和文明将重新启动，\n";
	pszText+="再次开始在三体世界中命运莫测的进化。欢迎再次登录。";
	break;
  }
  case 192:{
  	//

        //

        //

        //
        pszText+="四百五十一年后，192号文明在双日凌空的烈焰中毁灭，\n";
        pszText+="它进化到原子和信息时代。\n";
        pszText+="192号文明是三体文明的里程碑，它最终证明了三体问题的不可解，\n";
        pszText+="放弃了已延续191轮文明的徒劳努力，确定了今后文明全新的走向。\n";
        pszText+="至此，《三体》游戏的最终目标发生变化，新的目标是：\n";
        pszText+="飞向宇宙，寻找新的家园。\n";
        pszText+="欢迎再次登录。";
	break;
  }
  case 193:{
  	//
  	pszText+="三体文明对新世界的远征开始了，舰队正在航程中……\n";
	pszText+="《三体》游戏结束了，当您回到现实时，\n";
	pszText+="如果忠于自己曾做出的承诺，\n";
	pszText+="请按随后发给您的电子邮件中的地址，\n";
	pszText+="参加地球三体组织的聚会。";
	break;
  }
  }
  if(pszText==" "){
  	srand( time(0));
  	yy=rand()%7;
  	//pszText+=('0'+tim/100)+('0'+tim/10%10)+('0'+tim%10);
  	char aa[3];
  	aa[0]=('0'+tim/100);
  	aa[1]=('0'+tim/10%10);
  	aa[2]=('0'+tim%10);
  	pszText+=aa;
  	switch (yy){//chong xie
  		case 0:{
  			pszText+="号文明在“三日连珠”的引力叠加中毁灭了，\n";
			break;
		  }
		  case 2:{
  			pszText+="号文明在漫长的寒夜中毁灭了，\n";
			break;
		  }
		  case 3:{
  			pszText+="号文明在“双日连珠”的引力叠加中毁灭了，\n";
			break;
		  }
		  case 4:{
  			pszText+="号文明在烈焰中毁灭了，\n";
			break;
		  }
		  case 5:{
			
		  
  			pszText+="号文明在大撕裂中毁灭了，\n";
			break;
		  }
		  case 6:{
  			pszText+="号文明的行星坠入太阳而毁灭，\n";
			break;
		  }
		  case 1:{
  			pszText+="号文明在太阳吞噬中毁灭了，\n";
			break;
		  }
	  }
	  yy=rand()%6;
	  switch (yy){//chong xie
  		case 0:{
  			pszText+="该文明进化至石器时代\n";
			break;
		  }
		  case 2:{
  			pszText+="该文明进化至信息时代\n";
			break;
		  }
		  case 3:{
  			pszText+="该文明进化至东汉时代\n";
			break;
		  }
		  case 4:{
  			pszText+="该文明进化至曲率驱动时代\n";
			break;
		  }
		  case 5:{
  			pszText+="该文明进化至核能时代\n";
			break;
		  }
		  case 6:{
  			pszText+="此号文明在光粒中毁灭了，\n";
			break;
		  }
		  case 1:{
  			pszText+="该文明进化至中世纪时代\n";
			break;
		  }
	  }
	  pszText+=jin(tim);
	  pszText+="在漫长的时间后，文明和生命将重新启动\n";
	  pszText+="再次开始在三体世界中命运莫测的进化。欢迎再次登录。";
	  
	  
	  
	  if(tim<1){
	  	/*
	  	全民制作人们 大家好\n我是练习时长两年半的个人练习生 蔡徐坤\n喜欢唱 跳 rap 篮球\nmusic\n鸡你太美 bebe\n鸡你太美 bebe\n鸡你实在是太美 bebe\n鸡你太美 bebe\n迎面走来的你让我如此蠢蠢欲动\n这种感觉我从未有\nCause I got a crush on you who you\n在今后的节目中 我还准备了很多\n我自己作词 作曲 编舞的原创作品\n期待的话 请多多为我投票吧 \n	  	*/
	  	if(tim==-3){
	  		pszText="全民制作人们 大家好\n我是练习时长两年半的个人练习生 蔡徐坤\n喜欢唱 跳 rap 篮球\nmusic\n鸡你太美 bebe\n鸡你太美 bebe\n鸡你实在是太美 bebe\n鸡你太美 bebe\n迎面走来的你让我如此蠢蠢欲动\n这种感觉我从未有\nCause I got a crush on you who you\n在今后的节目中 我还准备了很多\n我自己作词 作曲 编舞的原创作品\n期待的话 请多多为我投票吧 \n	";
		  }
		if(tim==-1){
			pszText="|\n|\n=\n<>\n=<o>=\n>O<\n===#===\n|| ||\n";
		}
		if(tim==-2){
			pszText="===   / +\n===   | ^\n===   | +";
		}
		if(tim==0){
			pszText="三体\nThreebody\n制作：\nF1A";
		}
		if(tim==-4){
			pszText="朋友们好啊我是浑元形意太极门掌门人马保国。\n刚才有个朋友问我马老师发生什么事了，\n我说怎么回事，给我发了一几张截图，\n我一看!嗷!原来是昨天，\n有两个年轻人，三十多岁，一个体重，九十多公斤，\n一个体重八十多公斤，他们说，唉…\n有一个说是我在健身房练功颈椎练坏了，马老师你能不能教教我浑元功法，\n哎…帮助治疗一下，我的颈椎病。\n我说可以。我说你在健身房练死劲儿，不好用，他不服气。\n我说小朋友：你两个手来找我一个手指头，他找不动。\n他说你这也没用。我说我这个有用，\n这是化劲儿，传统功夫是讲化劲儿的四两拨千金。\n二百多斤的英国大力士，动我不动我这一个手指头。\n啊…哈!他非和我试试，\n我说可以。诶…我一说的啪就站起来了，很快嗷!\n然后上来就是一个左正蹬一个右鞭腿一个左刺拳，\n我全部防区防出去了啊防出去以后自然是传统功夫以点到为止，\n右拳放到他鼻子上没打他，我笑一下准备收拳，由这时间，\n欸传统功夫的点到为止他已经输了，\n如果这一拳发力，一拳就把他鼻子打骨折了，\n放在鼻子上没有打他，\n他也承认，我先打到他面部。\n他不知道拳放在他鼻子上，他承认我先打到他面部，\n啊，我收拳的时间不打了，他突然袭击左刺拳来打我脸，\n啊，我大意了啊，没有闪，\n矮…他的左拳给我眼，啊，右眼，蹭了一下，但没关系啊!\n他也说，啊他截图也说了，两分多钟以后，\n当时流眼泪了，捂着眼，我说停停。\n然后两分钟钟以后，两分多钟以后诶就好了，\n我说小伙子你不讲武德你不懂，\n他说马老师对不起，\n对不起，我不懂规矩。啊，我是…\n他说他是乱打的，他可不是乱打的啊，\n正蹬，鞭腿，左刺拳，训练有素，\n后来他说他练过三四年泰拳，\n啊，看来是有备而来!\n这两个年轻人不讲武德，\n来骗!来偷袭!\n我六十九岁的老同志，这好吗?\n这不好，\n我劝这位年轻人好自为之，\n好好反思，\n以后不要再犯这样的聪明，\n小聪明啊，武林要以和为贵，\n要讲武德，不要搞窝里斗，谢谢朋友们!";
		}
	  }
  }
}
//pszText[1]=L"";
string jin(int den){
	string list[99];
	list[0]="但是在这次文明中，孔子提出了儒家学说，为思想统治发展奠定基础\n";
	list[1]="但在此次文明中，后羿射下了七颗太阳，为后期三体世界的物理奠定了基础\n";
	list[2]="但在此次文明中，希特勒提出了纳粹主义，为后期三体文明的政治制度奠定了基础\n";
	list[3]="但在此次文明中，神农发现了水稻，为后期三体文明奠定了物质基础\n";
	list[4]="但在此次文明中，诸葛亮发明了诸葛连弩，为后期三体文明的战争奠定基础\n";
	list[5]="但在此次文明中，屈原写下《离骚》为后期三体文明奠定文化基础\n";
	list[6]="但在此次文明中，神户小德发明了三体重开模拟器，为后期三体文明未来预测奠定基础\n";
	list[7]="但在此次文明中，马保国发明混元形意太极，为后期三体文明武术奠定基础\n";
	list[8]="但在此次文明中，奥本海默发明核弹，为后期三体文明战争奠定基础\n";
	list[9]="但在此次文明中，欧拉发现e，为后期三体文明数学奠定基础\n";
	list[10]="但在此次文明中，祖冲之计算出π的近似值，为后期三体文明数学奠定基础\n";
	list[11]="但在此次文明中，华佗发明五禽戏，为后期三体文明医疗奠定基础\n";
	list[12]="但在此次文明中，亚里士缺德发现重的铁球先落地，为后期三体文明物理奠定基础\n";
	list[13]="但在此次文明中，伽利略发现两个铁球同时落地，为后期三体文明物理奠定基础\n";
	list[14]="但在此次文明中，三体发现了火，为后期三体文明发展奠定基础\n";
	list[15]="但在此次文明中，诺内尔发明了TNT，为后期三体文明火药学奠定基础\n";
	list[16]="但在此次文明中，Notch发明了Minecraft，为后期三体文明奠定物理基础\n";
	list[17]="但在此次文明中，日本出现了武士道，为后期三体文明文化奠定基础\n";
	list[18]="但在此次文明中，三体文明出现了佛教，为后期三体文明文化奠定基础\n";
	list[19]="但在此次文明中，毕达哥斯拉（doge写下了他的猜想，为后期三体文明数学奠定基础\n";
	list[20]="但在此次文明中，苏东坡发明了东坡肉（秘制配方：需要6只新鲜的三体人……），为后期三体文明美食奠定基础\n";
	list[21]="但在此次文明中，欧几里得写下几何原本，为后期三体文明数学奠定基础\n";
	list[22]="但在此次文明中，马克思提出《共产党宣言》，为后期三体文明政治奠定基础\n";
	list[23]="但在此次文明中，奥斯特做了奥斯特实验，为后期三体文明物理奠定基础\n";
	list[24]="但在此次文明中，刘慈欣写下《三体》，为后期三体文明历史奠定基础\n";
	list[25]="但在此次文明中，F1A写下三体游戏，为后期三体文明数学奠定基础\n";
	list[26]="但在此次文明中，图灵宣布了图灵测试，为后期三体文明计算机学奠定基础\n";
	list[27]="但在此次文明中，三体人证明了四色定理，为后期三体文明数学奠定基础\n";
	list[28]="但在此次文明中，三体人证明毕达哥拉斯定理，为后期三体文明数学奠定基础\n";
	list[29]="但在此次文明中，三体人证明了费马大定理，为后期三体文明数学奠定基础\n";
	list[30]="但在此次文明中，三体人证否了黎曼猜想，为后期三体文明数学奠定基础\n";
	list[31]="但在此次文明中，三体人提出了N=NP？，为后期三体文明数学奠定基础\n";
	list[32]="但在此次文明中，三体人发现并证明了费马小定理，为后期三体文明数学奠定基础\n";
	list[33]="但在此次文明中，Ignoloxi7写下了Mc but 2d，为后期三体文明无聊闲的学奠定基础\n";
	list[34]="但在此次文明中，三体人发现了量子纠缠，为后期三体文明物理奠定基础\n";
	list[35]="但在此次文明中，三体人在爱因斯坦的领导下掌握了量子技术，为后期三体文明物理奠定基础\n";
	list[36]="但在此次文明中，爱迪生发明了4090W节能电灯泡，为后期三体文明物理奠定基础\n";
	list[37]="但在此次文明中，三体人制作了MOSS，通过了图灵测试，为后期三体文明AI奠定基础\n";
	list[38]="但在此次文明中，第一台每秒2500京的计算机出世，为后期三体文明计算奠定基础\n";
	int seed=den;
	seed*=rand()%20;
	seed+=12;
	seed+rand()%7;
	if(rand()%7==0){
		seed%=39;
		return list[seed];
	}
	return " ";
}

int main()
{
	initgraph(nWindowWidth, nWindowHeight);
   char as[9999];
	for(int a=sss;a<194;a++){
		world(a);
		RECT rct = { 0 };
	settextstyle(font_h, font_w,_T("Consolas"));
	
	strcpy(as,pszText.c_str());
	drawtext(as, &rct, DT_CALCRECT);

	IMAGE imgText(rct.right, rct.bottom);
	DWORD* pBufImg = GetImageBuffer(&imgText);
	SetWorkingImage(&imgText);
	settextstyle(font_h, font_w,_T("Consolas"));
	drawtext(as, &rct, DT_CENTER);
	SetWorkingImage();
	DWORD* pBuf = GetImageBuffer();

	// 将文本宽度压缩为窗口宽度
	float fWindowWidthRatio = (float)nWindowWidth / rct.right;

	BeginBatchDraw();

	clock_t t;

	float f_kLightness = (float)(nStartLightness - nEndLightness) / nWindowHeight;
	float f_kWidth = (1 - fEndWidthRatio) / nWindowHeight;
	float f_kHeight = (1 - fEndHeightRatio) / nWindowHeight;

	// 图片输出偏移
	for (int pos = nWindowHeight; pos > -rct.bottom; pos -= nAmount)
	{
		t = clock();
		cleardevice();

		float y = (float)pos;	// 当前文字像素行映射在屏幕上的坐标
		for (int i = 0; i < (int)(rct.bottom /** fWindowWidthRatio*/); i++)
		{
			y += f_kHeight * y + fEndHeightRatio;

			if (y >= nWindowHeight)
			{
				break;
			}
			else if (y < 0)
			{
				i = -pos - 1;
				y = 0;
				continue;
			}

			short nLightness = (int)(f_kLightness * (int)y) + nEndLightness;
			float fWidthRatio = (f_kWidth * (int)y + fEndWidthRatio) * fWindowWidthRatio;
			int nWidth = (int)(rct.right * fWidthRatio);
			int nHalfWhite = (nWindowWidth - nWidth) / 2;
			for (int j = 0; j < rct.right; j++)
			{
				if (pBufImg[(int)(i /*/ fWindowWidthRatio*/)*rct.right + j] == WHITE)
				{
					//putpixel(nHalfWhite + fWidthRatio * j, y, RGB(nLightness, nLightness, nLightness));
					pBuf[(int)y * nWindowWidth + (int)(nHalfWhite + fWidthRatio * j)] = RGB(nLightness, nLightness, nLightness);
				}
			}
		}

		FlushBatchDraw();

		// 帧率均衡
		int delay = 1000 / fps - (clock() - t);
		if (delay > 0)
		{
			Sleep(delay);
		}
	}

	//_gettch();
	EndBatchDraw();
	/*free(&rct);
	free(&imgText);
	free(&pBufImg);
	free(&pBuf);
	free(&f_kLightness);
	free(&f_kWidth);
	free(&f_kHeight);
	*/
	}
	//IMAGE 
	closegraph();
	return 0;
}

