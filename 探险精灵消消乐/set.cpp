//�������� ����ֵ�� 0 ��������
//					1 ��С����
//					2 �رձ�������
//					3 ������������
//					4 ������ҳ






//���ܣ��ھ��Σ������ɵ���������������������0
//		�ھ��Σ������ɵ���������С����������1
//		�ھ��Σ������ɵ��������رձ������֣�����2������ͼ
//		�ھ��Σ������ɵ������������������֣�����3������ͼ
//		�ھ��Σ������ɵ�������������ҳ��    ����4������ͼ

#include<stdio.h>
#include<easyx.h>
#include<graphics.h>
#include <conio.h>
#include<string.h>
#include<mmsystem.h>//������ý���豸ͷ�ļ�
#pragma comment(lib,"winmm.lib")
#include<stdlib.h>
#include"set.h"
#include"homepage.h"
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

//��ť����
void button(int x, int y, int w, int h, const char* text) {
	setbkmode(0);
	setfillcolor(BROWN);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	settextstyle(30, 0, "����");

	char text_[50] = "button";
	strcpy_s(text_, text);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);




}
//BGM���ź���
void BGM() {

	mciSendString("open ./mc.mp3", 0, 0, 0);
	mciSendString("play ./mc.mp3", 0, 0, 0);
}
//BGM��������
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
//BGM������С
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

//������õ�����ֵ
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
//�����ǵ��Ե�main
int print_set() {

	initgraph(1000, 700);
	setbkcolor(WHITE);
	cleardevice();
	//��������
	initgraph(500, 600, SHOWCONSOLE);

	//����ͼƬ
	IMAGE img;
	loadimage(&img, "./back.jpg", 500, 600);
	putimage(0, 0, &img);

	//��ӡ��ť
	button(50, 50, 150, 50, "��ʼ����");
	button(300, 50, 150, 50, "ֹͣ����");
	button(50, 250, 150, 50, "����+");
	button(300, 250, 150, 50, "����-");
	button(200, 400, 100, 50, "����");
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