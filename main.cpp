

#include <easyx.h>
#include <time.h>
#include <stdio.h>

// 窗口宽高
int nWindowWidth = 1280;
int nWindowHeight = 480;

int font_h = 200;					// 文字高
int font_w = 20;					// 文字宽
short nStartLightness = 255;		// 初始亮度
short nEndLightness = 60;			// 最终亮度
float fEndWidthRatio = (float)0.65;	// 宽度缩放比例
float fEndHeightRatio = (float)0.3;	// 高度缩放比例

int fps = 24;		// 帧率
int nAmount = 2;	// 文字单次位移
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

*/
void world(int tim){
  
}



int main()
{
	initgraph(nWindowWidth, nWindowHeight);

	RECT rct = { 0 };
	settextstyle(font_h, font_w, L"system");
	drawtext(pszText, &rct, DT_CALCRECT);

	IMAGE imgText(rct.right, rct.bottom);
	DWORD* pBufImg = GetImageBuffer(&imgText);
	SetWorkingImage(&imgText);
	settextstyle(font_h, font_w, L"system");
	drawtext(pszText, &rct, DT_CENTER);
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

	_gettch();
	EndBatchDraw();
	closegraph();
	return 0;
}
