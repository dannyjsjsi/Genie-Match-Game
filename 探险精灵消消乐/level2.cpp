#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include<vector>
#include"level2.h"
#include"homepage.h"
#include"level3.h"
#include"map.h"

namespace LEVEL_2 {
#define Width 900
#define Height 100
#define LEFT 140//第一个边框的x值
#define TOP 200//第一个方框的y值
#define SIZE 60//每一个方框的大小
#define X 5  //二维数组的x值
#define Y 5	//二维数组的y值

	int blood2 = 50;/*blood2表示精灵血量*/
	int u1 = 2;/*u表示关卡数*/
	double blood1 = 100 ;/*blood1为boss血量*/
	int  timer0, timer1, timer2, timer3, timer4, timer5;

	int map[Y][X] = { 0 };//定义一个二维数组
	int x_choose, y_choose;//定义全局变量
	IMAGE _010, _020, _030, _040, _050, _060, _070, _080;//引用图片
	IMAGE _0, _1, _2, _3, _4, _5;//定义图片变量
	IMAGE _6, _7, _8, _9, _10, _11;//定义图片变量
	IMAGE  _12, _13, _14, _15;

	struct Pair {
		double x;
		double y;
	};   //结构数组

	struct Drop {
		int num;
		double speed = 0;
		Pair begin;
		Pair end;
	};

	std::vector<Drop> drop;

	void button(int x, int y, int w, int h, const char* text)
	{
		setbkmode(0);
		setfillcolor(BROWN);
		fillroundrect(x, y, x + w, y + h, 10, 10);
		settextstyle(30, 0, "黑体");
		int tx = x + (w - textwidth(text)) / 2;
		int ty = y + (h - textheight(text)) / 2;
		outtextxy(tx, ty, text);
	}
	void success()
	{
		printf("-----------\n");
		BeginBatchDraw();
		cleardevice();
		button(50, 50, 550, 50, "成功,点击进入下一关");
		EndBatchDraw();
		ExMessage m;
		while (1) {
			m = getmessage(EX_MOUSE);
			switch (m.message) {
			case WM_LBUTTONDOWN:
				if (m.x >= 50 && m.x <= 50 + 550 && m.y >= 50 && m.y <= 50 + 50)
				{
					LEVEL_3::level3();
				}
			}
		}
	}

	void fail()
	{
		printf("-----------\n");
		BeginBatchDraw();
		cleardevice();
		button(50, 50, 550, 50, "失败，点击返回主页");
		EndBatchDraw();
		ExMessage m;
		while (1) {
			m = getmessage(EX_MOUSE);
			switch (m.message) {
			case WM_LBUTTONDOWN:
				if (m.x >= 50 && m.x <= 50 + 550 && m.y >= 50 && m.y <= 50 + 50)
				{
					print_Homepage();
				}
			}
		}
	}


	bool isDelete() {
		int x = 0;
		Pair arr[100] = { 0 };
		int length = 0;
		for (int i = 0; i < Y; ++i) {//竖着消除
			int temp = map[i][0];
			int count = 1;
			for (int j = 1; j < X; ++j) {
				if (temp == map[i][j]) {
					count++;
				}
				else {
					if (count >= 3 && temp != -1) {
						while (count--) {
							arr[length].x = j - count - 1;
							arr[length++].y = i;
							blood1 -= 1.5;//每消除一个boss就减少一滴血
							x = 1;
						}
						count = 1;
						temp = map[i][j];
					}
					else {
						temp = map[i][j];
						count = 1;
					}
				}
			}
			if (count >= 3 && temp != -1) {
				while (count--) {
					arr[length].x = X - count - 1;
					arr[length++].y = i;
					blood1 -= 1.5;//每消除一个boss就减少一滴血

					x = 1;

				}
			}
		}
		for (int j = 0; j < X; ++j) {
			int temp = map[0][j];
			int count = 1;
			for (int i = 1; i < Y; ++i) {
				if (temp == map[i][j]) {
					count++;
				}
				else {
					if (count >= 3 && temp != -1) {
						while (count--) {
							arr[length].x = j;
							arr[length++].y = i - count - 1;
							blood1 -= 1.5;//每消除一个boss就减少一滴血
							x = 1;

						}
						count = 1;
						temp = map[i][j];
					}
					else {
						temp = map[i][j];
						count = 1;
					}
				}
			}
			if (count >= 3 && temp != -1) {
				while (count--) {
					arr[length].x = j;
					arr[length++].y = Y - count - 1;
					blood1 -= 1.5;//每消除一个boss就减少一滴血

					x = 1;

				}
			}
		}
		if (x) {
			mciSendString("stop ../music/消除.mp3", NULL, 0, NULL);
			mciSendString("play ../music/消除.mp3", NULL, 0, NULL);
		}
		if (length == 0)
			return false;
		for (int i = 0; i < length; ++i) {
			map[int(arr[i].y)][int(arr[i].x)] = -1;

		}
		return true;
	}
	void initMap() {//遍历给每一个数组坐标利用1-9随机数赋值
		for (int i = 0; i < Y; ++i) {
			for (int j = 0; j < X; ++j) {
				map[i][j] = rand() % 4;
			}
		}
	}
	void print() {//打印游戏初始化界面
		cleardevice();

		putimage(0, 0, &_0);//背景
		putimage(50, 175, &_1);//消除框
		putimage(600, 175, &_2, SRCAND);//boss
		putimage(600, 175, &_3, SRCPAINT);//boss
		putimage(10, 600, &_4, SRCAND);//精灵
		putimage(10, 600, &_5, SRCPAINT); //精灵 
		putimage(0, 0, &_14, SRCAND);
		putimage(0, 0, &_15, SRCPAINT);
		if (timer1 > 50000) {
			putimage(600, 600, &_6, SRCAND);//血瓶透明
			putimage(600, 600, &_8, SRCPAINT);//血瓶
		}
		if (timer2 > 50000)
		{
			putimage(700, 600, &_6, SRCAND);//蓝瓶；透明
			putimage(700, 600, &_7, SRCPAINT);//蓝瓶
		}
		if (timer3 > 50000)
		{
			putimage(800, 600, &_6, SRCAND);//紫瓶透明
			putimage(800, 600, &_9, SRCPAINT);//紫瓶
		}
		/*输出技能*/
		if (timer4 > 50000)
		{
			putimage(210, 600, &_10, SRCAND);//输出技能1
			putimage(210, 600, &_11, SRCPAINT);//输出技能1
		}
		if (timer5 > 50000)
		{
			putimage(310, 600, &_12, SRCAND);//输出技能2
			putimage(310, 600, &_13, SRCPAINT);//输出技能2
		}
		/*画boss血条*/
		setlinecolor(BLACK);				//设置当前画线颜色
		rectangle(200, 60, Width, Height);//空心矩形
		setfillcolor(RED);					//设置当前填充颜色。
		if (blood1 < 0)
			blood1 = 0;
		solidrectangle(200 + (100 - blood1) * 7, 60, Width, Height);//实心矩形
		/*画精灵血量*/
		// 设置字体样式
		settextstyle(50, 0, "小楷");
		settextcolor(WHITE);
		// 输出精灵血量
		char cblood[10];
		_itoa_s(blood2, cblood, 10);
		outtextxy(130, 600, cblood);

		for (int i = 0; i < Y; ++i) {
			for (int j = 0; j < X; ++j) {
				switch (map[i][j]) {
				case 0:
					putimage(LEFT + j * SIZE, TOP + i * SIZE, &_020, SRCAND);
					putimage(LEFT + j * SIZE, TOP + i * SIZE, &_010, SRCPAINT);
					break;
				case 1:
					putimage(LEFT + j * SIZE, TOP + i * SIZE, &_040, SRCAND);
					putimage(LEFT + j * SIZE, TOP + i * SIZE, &_030, SRCPAINT);
					break;
				case 2:
					putimage(LEFT + j * SIZE, TOP + i * SIZE, &_060, SRCAND);
					putimage(LEFT + j * SIZE, TOP + i * SIZE, &_050, SRCPAINT);
					break;
				case 3:
					putimage(LEFT + j * SIZE, TOP + i * SIZE, &_080, SRCAND);
					putimage(LEFT + j * SIZE, TOP + i * SIZE, &_070, SRCPAINT);
					break;
				}
			}
		}
		for (int i = 0; i < drop.size(); ++i) {
			if (drop[i].begin.y > 0) {
				switch (drop[i].num) {
				case 0:
					putimage(LEFT + drop[i].begin.x * SIZE, TOP + drop[i].begin.y * SIZE, &_020, SRCAND);
					putimage(LEFT + drop[i].begin.x * SIZE, TOP + drop[i].begin.y * SIZE, &_010, SRCPAINT);
					break;
				case 1:
					putimage(LEFT + drop[i].begin.x * SIZE, TOP + drop[i].begin.y * SIZE, &_040, SRCAND);
					putimage(LEFT + drop[i].begin.x * SIZE, TOP + drop[i].begin.y * SIZE, &_030, SRCPAINT);
					break;
				case 2:
					putimage(LEFT + drop[i].begin.x * SIZE, TOP + drop[i].begin.y * SIZE, &_060, SRCAND);
					putimage(LEFT + drop[i].begin.x * SIZE, TOP + drop[i].begin.y * SIZE, &_050, SRCPAINT);
					break;
				case 3:
					putimage(LEFT + drop[i].begin.x * SIZE, TOP + drop[i].begin.y * SIZE, &_080, SRCAND);
					putimage(LEFT + drop[i].begin.x * SIZE, TOP + drop[i].begin.y * SIZE, &_070, SRCPAINT);
					break;
				}
			}
		}
		FlushBatchDraw();
	}
	void input() {
		ExMessage m;
		peekmessage(&m, EX_MOUSE);//获取鼠标信息
		switch (m.message)
		{
		case WM_LBUTTONDOWN://如果鼠标左键点击
			/*血瓶*/
			if (m.x >= 600 && m.x <= 700 && m.y >= 600 && m.y <= 700)
			{

				if (timer1 > 50000) {
					mciSendString("stop ../music/治疗音效.wav", NULL, 0, NULL);
					mciSendString("play ../music/治疗音效.wav", NULL, 0, NULL);
					timer1 = 0;
					blood2 += 5;
				}
			}
			/*蓝瓶*/
			if (m.x >= 700 && m.x <= 800 && m.y >= 600 && m.y <= 700)
			{

				if (timer2 > 50000) {
					mciSendString("stop ../music/治疗音效.wav", NULL, 0, NULL);
					mciSendString("play ../music/治疗音效.wav", NULL, 0, NULL);
					timer2 = 0;
					timer4 = timer5 = 1000000;
				}
			}
			/*紫瓶*/
			if (m.x >= 800 && m.x <= 900 && m.y >= 600 && m.y <= 700)
			{

				if (timer3 > 50000) {
					mciSendString("stop ../music/治疗音效.wav", NULL, 0, NULL);
					mciSendString("play ../music/治疗音效.wav", NULL, 0, NULL);
					timer3 = 0;
					blood2 += 5;
					timer4 = timer5 = 1000000;
				}
			}
			/*技能1*/
			if (m.x >= 210 && m.x <= 310 && m.y >= 600 && m.y <= 700)
			{

				if (timer4 > 50000) {
					mciSendString("stop ../music/攻击音效.wav", NULL, 0, NULL);
					mciSendString("play ../music/攻击音效.wav", NULL, 0, NULL);
					timer4 = 0;
					blood1 -= 5 * u1;
				}
			}
			/*技能2*/
			if (m.x >= 310 && m.x <= 410 && m.y >= 600 && m.y <= 700)
			{

				if (timer5 > 50000) {
					mciSendString("stop ../music/治疗音效.wav", NULL, 0, NULL);
					mciSendString("play ../music/治疗音效.wav", NULL, 0, NULL);
					timer5 = 0;
					blood2 += 5;
				}
			}
			if (m.x > 0 && m.x < 40 && m.y < 40 && m.y>0) 	//判断鼠标点击间距
			{
				printf("返回\n");		//控制台测试用
				print_Homepage();

			}

			int x = (m.x - LEFT) / SIZE, y = (m.y - TOP) / SIZE;//判断点击的是哪一个格子
			if (y >= 0 && y < Y && x >= 0 && x < X) {
				if (abs(x - x_choose) + abs(y - y_choose) == 1) {
					printf("2 %d %d\n", y, x);
					int temp = map[y_choose][x_choose];
					map[y_choose][x_choose] = map[y][x];
					map[y][x] = temp;
					if (!isDelete()) {
						print();
						Sleep(200);
						int temp = map[y_choose][x_choose];
						map[y_choose][x_choose] = map[y][x];
						map[y][x] = temp;
					}
					x_choose = y_choose = -1;
				}
				else {
					printf("1 %d %d\n", y, x);
					x_choose = x;
					y_choose = y;
				}

			}
			break;
		}
	}
	int move() {
		blood2 = blood2 - timer0 / 500;


		if (++timer0 > 500)timer0 = 0;
		if (++timer1 > 1000000)timer1 = 1000000;
		if (++timer2 > 1000000)timer2 = 1000000;
		if (++timer3 > 1000000)timer3 = 1000000;
		if (++timer4 > 1000000)timer4 = 1000000;
		if (++timer5 > 1000000)timer5 = 1000000;
		if (!drop.empty()) {
			for (int i = 0; i < drop.size(); ++i) {
				drop[i].speed += 0.0001;
				drop[i].begin.y += drop[i].speed;
				if (drop[i].begin.y > drop[i].end.y) {
					map[int(drop[i].end.y)][int(drop[i].end.x)] = drop[i].num;
					drop.erase(drop.begin() + i--);
				}
			}
			return 1;//成功下落
		}
		for (int j = 0; j < X; ++j) {
			int count = 0;
			for (int i = Y - 1; i >= 0; --i) {
				if (map[i][j] == -1) {
					count++;
					for (int k = i - 1; k >= 0; --k) {
						if (map[k][j] != -1) {
							Drop d;
							d.num = map[k][j];
							d.end.x = d.begin.x = j;
							d.begin.y = k;
							d.end.y = i;
							drop.push_back(d);
							count--;
							map[k][j] = -1;
							break;
						}
					}
					if (count) {
						Drop d;
						d.num = rand() % 4;
						d.end.x = d.begin.x = j;
						d.begin.y = -count;
						d.end.y = i;
						drop.push_back(d);
					}
				}
			}
		}
		isDelete();
		return 0;
	}

	int movedelete() {
		u1 = 1;
		timer0 = 0;
		timer1 = timer2 = timer3 = timer4 = timer5 = 1000000;
		/*初始化boss、方框、精灵*/
		loadimage(&_0, "第二张背景.jpg", 1000, 700);//背景
		loadimage(&_1, "q2.png", 500, 400);//加载消除框
		loadimage(&_2, "第二张boss白底.png", 500, 400);//加载boss白底
		loadimage(&_3, "第二张boss黑底.png", 500, 400);//加载boss黑底
		loadimage(&_4, "精灵白底.png", 100, 100);//加载人物白底
		loadimage(&_5, "精灵彩色.png", 100, 100); //加载人物黑底
		loadimage(&_14, "透明图.png");
		loadimage(&_15, "返回.png");
		/*加载道具*/
		loadimage(&_6, "蓝瓶透明图.png", 100, 100);
		loadimage(&_7, "蓝瓶.png", 100, 100);
		loadimage(&_8, "血瓶.png", 100, 100);
		loadimage(&_9, "紫瓶.png", 100, 100);
		/*加载技能*/
		loadimage(&_10, "血透明图.png", 100, 100);//透明
		loadimage(&_11, "血.png", 100, 100);//技能1：加血
		loadimage(&_12, "十字透明图.png", 100, 100);//透明
		loadimage(&_13, "加血.png", 100, 100);//技能2：扣血

		loadimage(&_010, "琥珀.png", 38, 0);
		loadimage(&_020, "琥珀透明图.png", 38, 0);
		loadimage(&_030, "火石.png");
		loadimage(&_040, "火石透明图.png");
		loadimage(&_050, "蓝宝石.png");
		loadimage(&_060, "蓝宝石透明图.png");
		loadimage(&_070, "石头.png");
		loadimage(&_080, "石头透明图.png");

		initMap();//定义一个二维数组
		x_choose = y_choose = -1;
		BeginBatchDraw();
		while (1) {
			print();//游戏初始化
			if (move()) {
				continue;
			}
			input();
			if (blood1 < 0) {
				success();
			}
			if (blood2 < 0) {
				fail();
			}
		}
		EndBatchDraw();
		return 0;
	}

	int  level2()
	{
		blood1 = 100; 
		blood2 = 50;
		movedelete();
		return 0;
	}
}



