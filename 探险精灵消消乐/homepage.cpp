#include <stdio.h>
#include <graphics.h>
#include <easyx.h>
#include"homepage.h"
#include"set.h"
#include"map.h"
int a, b;
/*���ư�ť�ĺ���*/
void button1(int x, int y, int w, int h, const char* text)
{
	setbkmode(TRANSPARENT);
	//setfillcolor(WHITE);

	settextcolor(BLACK);
	setlinecolor(GREEN);
	roundrect(x, y, x + w, y + h, 10, 10);

	settextstyle(25, 0, "����");
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	char text_[50] = "button";
	strcpy_s(text_, text);
	outtextxy(tx, ty, text);


}

int print_Homepage()

{
	initgraph(1000, 700);//����һ������

	IMAGE img;
	loadimage(&img, "�󱳾�.jpg", 1000, 700);
	IMAGE _1, _2;
	loadimage(&_1, "����z.png", 50, 50);
	loadimage(&_2, "����.png", 50, 50);
	while (1)
	{
		BeginBatchDraw();
		cleardevice();//����//���ñ�����ɫ����������������
		//����
		/*������*/

		putimage(0, 0, &img);
		/*����ť*/
		button1(80, 435, 250, 50, "��ʼ��Ϸ");
		button1(80, 525, 250, 50, "������Ϸ");
		button1(80, 610, 250, 50, "�˳���Ϸ");
		//button1(100, 500, 250, 50, "�̵�");
		//button1(100, 575, 250, 50, "����");
		/*�����õ�ͼ��*/

		putimage(0, 0, &_1, SRCAND);
		putimage(0, 0, &_2, SRCPAINT);
		/*д��*/
		//settextcolor(BLACK);
		//settextstyle(70, 0, "���Ŀ���");
		//char s[] = "̽�վ���������";
		//outtextxy(550, 300, s);
		EndBatchDraw();

		/*�����ת*/
		ExMessage msg;


		msg = getmessage(EX_MOUSE);
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			if (msg.x >= 100 && msg.x <= 350 && msg.y >= 425 && msg.y <= 475)//��д������λ��
			{
				print_map();//��ӡ��ͼ
				//��ת��ͼҳ��ĺ���
				break;

			}
			if (msg.x >= 100 && msg.x <= 350 && msg.y >= 525 && msg.y <= 575)//��д������λ��
			{
				print_set();//��ӡ����

			}
			if (msg.x >= 100 && msg.x <= 350 && msg.y >= 625 && msg.y <= 675)//��д������λ��
			{
				
				exit(0);//�˳���Ϸ
				break;

			}

			//if (msg.x >= 100 && msg.x <= 350 && msg.y >= 500 && msg.y <= 550)//��д������λ��
			//{
			//	printf("2");
			//	//��ת�̵�ҳ��ĺ���
			//	break;
			//}
			//if (msg.x >= 100 && msg.x <= 350 && msg.y >= 575 && msg.y <= 625)//��д������λ��
			//{
			//	printf("3");
			//	//��ת����ҳ��ĺ���
			//	break;
			//}

			if (msg.x >= 0 && msg.x <= 50 && msg.y >= 0 && msg.y <= 50)//��д������λ��
			{
				//��ת����ҳ��ĺ���
				print_set();
				printf("-------");
				break;
			}
		}

	}
}

