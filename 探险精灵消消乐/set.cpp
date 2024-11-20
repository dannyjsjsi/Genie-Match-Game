//参数：无 返回值： 0 增大音量
//					1 减小音量
//					2 关闭背景音乐
//					3 开启背景音乐
//					4 返回首页






//功能：在矩形（）处可点击，点击增大音量，返回0
//		在矩形（）处可点击，点击减小音量，返回1
//		在矩形（）处可点击，点击关闭背景音乐，返回2，有贴图
//		在矩形（）处可点击，点击开启背景音乐，返回3，有贴图
//		在矩形（）处可点击，点击返回首页，    返回4，有贴图

#include<stdio.h>
#include<easyx.h>
#include<graphics.h>
#include <conio.h>
#include<string.h>
#include<mmsystem.h>//包含多媒体设备头文件
#pragma comment(lib,"winmm.lib")
#include<stdlib.h>
#include"set.h"
#include"homepage.h"
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

//按钮函数
void button(int x, int y, int w, int h, const char* text) {
	setbkmode(0);
	setfillcolor(BROWN);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(30, 0, "黑体");

	char text_[50] = "button";
	strcpy_s(text_, text);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);




}
//BGM播放函数
void BGM() {

	mciSendString("open ./mc.mp3", 0, 0, 0);
	mciSendString("play ./mc.mp3", 0, 0, 0);
}
//BGM音量增加
void VoiceUp() {
	char file[50] = "setaudio ./mc.mp3 volume to ";
	char chVolume[256];
	int volume;
	mciSendString("status ./mc.mp3 volume", chVolume, 255, 0);
	volume = atoi(chVolume);
	volume += 200;
	_itoa_s(volume, chVolume, 10);
	strcat_s(file, chVolume);
	mciSendString(file, 0, 0, 0);
}
//BGM音量减小
void VoiceDown() {
	char file[50] = "setaudio ./mc.mp3 volume to ";
	char chVolume[256];
	int volume;
	mciSendString("status ./mc.mp3 volume", chVolume, 255, 0);
	volume = atoi(chVolume);
	volume -= 200;
	_itoa_s(volume, chVolume, 10);
	strcat_s(file, chVolume);
	mciSendString(file, 0, 0, 0);
}

//鼠标点击得到返回值
int back() {
	ExMessage msg;
	while (1) {
		msg = getmessage(EX_MOUSE);
		switch (msg.message) {
		case WM_LBUTTONDOWN:
			if (msg.x >= 50 && msg.x <= 50 + 150 && msg.y >= 50 && msg.y <= 50 + 50)
			{
				return 3;
			}

			if (msg.x >= 300 && msg.x <= 300 + 150 && msg.y >= 50 && msg.y <= 50 + 50)
			{
				return 2;
			}

			if (msg.x >= 50 && msg.x <= 50 + 150 && msg.y >= 250 && msg.y <= 250 + 50)
			{
				return 1;
			}

			if (msg.x >= 300 && msg.x <= 300 + 150 && msg.y >= 250 && msg.y <= 250 + 50)
			{
				return 0;
			}

			if (msg.x >= 200 && msg.x <= 200 + 100 && msg.y >= 400 && msg.y <= 400+50)
				return 4;
		}

	}
}
//这里是调试的main
int print_set() {

	initgraph(1000, 700);
	setbkcolor(WHITE);
	cleardevice();
	//创建窗口
	initgraph(500, 600, SHOWCONSOLE);

	//背景图片
	IMAGE img;
	loadimage(&img, "./back.jpg", 500, 600);
	putimage(0, 0, &img);

	//打印按钮
	button(50, 50, 150, 50, "开始播放");
	button(300, 50, 150, 50, "停止播放");
	button(50, 250, 150, 50, "音量+");
	button(300, 250, 150, 50, "音量-");
	button(200, 400, 100, 50, "返回");
	while (1)
	{
		int a = back();
		switch (a) {
		case 3: {
			mciSendString("open ./mc.mp3", 0, 0, 0);
			mciSendString("play ./mc.mp3 repeat", 0, 0, 0); 
		}
			  printf("----------");
			  break;
		case 2:
			mciSendString("pause ./mc.mp3", 0, 0, 0);
			printf("----------");
			break;
		case 4:
			printf("----------");
			print_Homepage();
			

			break;
		case 0:
			VoiceDown();
			printf("----------");

			break;
		case 1:
			printf("----------");
			VoiceUp();
		default:break;

		}

	}

	getchar();

	return 0;

}