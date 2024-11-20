#include <stdio.h>
#include <graphics.h>
#include <easyx.h>
#include"homepage.h"
#include"set.h"
#include"map.h"
int a, b;
/*绘制按钮的函数*/
void button1(int x, int y, int w, int h, const char* text)
{
	setbkmode(TRANSPARENT);
	//setfillcolor(WHITE);

	settextcolor(BLACK);
	setlinecolor(GREEN);
	roundrect(x, y, x + w, y + h, 10, 10);

	settextstyle(25, 0, "黑体");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	char text_[50] = "button";
	strcpy_s(text_, text);
	outtextxy(tx, ty, text);


}

int print_Homepage()

{
	initgraph(1000, 700);//设置一个窗口

	IMAGE img;
	loadimage(&img, "大背景.jpg", 1000, 700);
	IMAGE _1, _2;
	loadimage(&_1, "设置z.png", 50, 50);
	loadimage(&_2, "设置.png", 50, 50);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();//清屏//设置背景颜色（填充必须先清屏）
		//清屏
		/*画背景*/

		putimage(0, 0, &img);
		/*画按钮*/
		button1(80, 435, 250, 50, "开始游戏");
		button1(80, 525, 250, 50, "设置游戏");
		button1(80, 610, 250, 50, "退出游戏");
		//button1(100, 500, 250, 50, "商店");
		//button1(100, 575, 250, 50, "背包");
		/*画设置的图表*/

		putimage(0, 0, &_1, SRCAND);
		putimage(0, 0, &_2, SRCPAINT);
		/*写字*/
		//settextcolor(BLACK);
		//settextstyle(70, 0, "华文楷体");
		//char s[] = "探险精灵消消乐";
		//outtextxy(550, 300, s);
		EndBatchDraw();

		/*点击跳转*/
		ExMessage msg;


		msg = getmessage(EX_MOUSE);
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			if (msg.x >= 100 && msg.x <= 350 && msg.y >= 425 && msg.y <= 475)//填写按键的位置
			{
				print_map();//打印地图
				//跳转地图页面的函数
				break;

			}
			if (msg.x >= 100 && msg.x <= 350 && msg.y >= 525 && msg.y <= 575)//填写按键的位置
			{
				print_set();//打印设置

			}
			if (msg.x >= 100 && msg.x <= 350 && msg.y >= 625 && msg.y <= 675)//填写按键的位置
			{
				
				exit(0);//退出游戏
				break;

			}

			//if (msg.x >= 100 && msg.x <= 350 && msg.y >= 500 && msg.y <= 550)//填写按键的位置
			//{
			//	printf("2");
			//	//跳转商店页面的函数
			//	break;
			//}
			//if (msg.x >= 100 && msg.x <= 350 && msg.y >= 575 && msg.y <= 625)//填写按键的位置
			//{
			//	printf("3");
			//	//跳转背包页面的函数
			//	break;
			//}

			if (msg.x >= 0 && msg.x <= 50 && msg.y >= 0 && msg.y <= 50)//填写按键的位置
			{
				//跳转设置页面的函数
				print_set();
				printf("-------");
				break;
			}
		}

	}
}

