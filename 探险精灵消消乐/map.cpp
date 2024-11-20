#include"map.h"
#include <graphics.h>				
#include <conio.h>
#include<stdio.h>
#include"homepage.h"
#include"level1.h"
#include"level2.h"
#include"level3.h"
#include"level4.h"


//�������� ����ֵ�� 1��һ��
//					2�ڶ���
//					3������
//					4���Ĺ�
//					5������ҳ
//���ܣ���ӡ����ͼ
//	�ھ��Σ������ɵ������������һ�أ�����1������ͼ
//	�ھ��Σ�)���ɵ�����������ڶ��أ�����2������ͼ
//	�ھ��Σ������ɵ���������������أ�����3������ͼ
//	�ھ��Σ������ɵ�������������Ĺأ�����4������ͼ
//  �ھ��Σ������ɵ�������������ҳ������5


int loadmap() {			//���뺯��
	IMAGE img;		//����һ�ű���ͼ�ı�������
	loadimage(&img, "����ͼ1.jpg", 1000, 700);		//���س���ͼ����ͼ
	IMAGE img1, img2, img3, img4, img5, img6, img7, img8, img9, img10;	//img1-img8�ߴ綼��85
	loadimage(&img1, "һ.png");			//���غ�ɫ��ͼ
	loadimage(&img2, "͸��ͼ1.png");		//���ذ׵׺�ͼ
	loadimage(&img4, "��.png");			//���غ�ɫ��ͼ
	loadimage(&img3, "͸��ͼ2.png");		//���ذ׵׺�ͼ
	loadimage(&img5, "��.png");			//���غ�ɫ��ͼ
	loadimage(&img6, "͸��ͼ3.png");		//���ذ׵׺�ͼ
	loadimage(&img8, "��.png");			//���غ�ɫ��ͼ
	loadimage(&img7, "͸��ͼ4.png");		//���ذ׵׺�ͼ
	loadimage(&img9, "͸��ͼ.png");		//���غ�ɫ��ͼ
	loadimage(&img10, "����.png");		//���ذ׵׺�ͼ
	while (1)		//�ó�����һֱѭ��״̬,
	{
		BeginBatchDraw();		//˫�����ͼ�Ŀ�ʼ��

		//������ͼѡ���ģ��
		//͸��ͼ�ĺϳ�:��ɫ��ͼ��SRCPAINT�׵׺�ͼ��SRCAND

		putimage(0, 0, &img);										//��ӡ����ͼ����ͼ
		//��ӡ��һ�ص�ͼƬ

		putimage(100, 355, &img2, SRCAND);				//��ӡͼƬ
		putimage(100, 355, &img1, SRCPAINT);				//���Ͻ�λ����(100,355)
		//��ӡ�ڶ��ص�ͼƬ

		putimage(260, 200, &img3, SRCAND);				//��ӡͼƬ
		putimage(260, 200, &img4, SRCPAINT);			//���Ͻ�λ����(260,200)
		//��ӡ�����ص�ͼƬ

		putimage(430, 465, &img6, SRCAND);				//��ӡͼƬ
		putimage(430, 465, &img5, SRCPAINT);			//���Ͻ�λ����(430,465)
		//��ӡ���Ĺص�ͼƬ

		putimage(700, 280, &img7, SRCAND);				//��ӡͼƬ
		putimage(700, 280, &img8, SRCPAINT);			//���Ͻ�λ����(700,280)
		//��ӡ���ؼ�

		putimage(0, 0, &img9, SRCAND);
		putimage(0, 0, &img10, SRCPAINT);//���Ͻ�λ����(960,0),�ߴ�(40,40)	

		EndBatchDraw();		//˫�����ͼ��β��

		//FlushBatchDraw();		//˫�����ͼ

		//��ȡ�����Ϣ
		//switch case����case��Ķ�����������Ҫ��ͬ,�����Ҫ�����жϿ���д��ͬһ��if{}����
		if (MouseHit)		//�ж�����Ƿ���
		{
			MOUSEMSG msg = GetMouseMsg();		//��ȡ�����Ϣ
			switch (msg.uMsg)					//switch case����
			{
			case WM_LBUTTONDOWN:				//�ж��������Ϣ
				if (msg.x > 100 && msg.x < 175 && msg.y < 640 && msg.y>355)	//�ж���������
				{
					printf("��һ��\n");		//����̨������
					LEVEL_1::level1();
					return 1;				//����ֵ1������ս��
				}
				if (msg.x > 260 && msg.x < 345 && msg.y < 495 && msg.y>200) 	//�ж���������
				{
					printf("�ڶ���\n");		//����̨������
					LEVEL_2::level2();
					return 2;				//����ֵ2������ս��
				}
				if (msg.x > 430 && msg.x < 515 && msg.y < 550 && msg.y>465) 	//�ж���������
				{
					printf("������\n");		//����̨������
					LEVEL_3::level3();
					return 3;				//����ֵ3������ս��
				}
				if (msg.x > 700 && msg.x < 785 && msg.y < 335 && msg.y>280) 	//�ж���������
				{
					printf("���Ĺ�\n");		//����̨������
					LEVEL_4::level4();
					return 4;				//����ֵ4������ս��
				}
				if (msg.x > 0 && msg.x < 40 && msg.y < 40 && msg.y>0) 	//�ж���������
				{
					printf("����\n");		//����̨������
					print_Homepage();
					return 5;				//����ֵ5������ҳ��
				}
			}
		}

	}
	//�������
}

int print_map() {
	//initgraph(1000, 700, SHOWCONSOLE);
	loadmap();
	return 0;
}
