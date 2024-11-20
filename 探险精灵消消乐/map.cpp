#include"map.h"
#include <graphics.h>				
#include <conio.h>
#include<stdio.h>
#include"homepage.h"
#include"level1.h"
#include"level2.h"
#include"level3.h"
#include"level4.h"


//参数：无 返回值： 1第一关
//					2第二关
//					3第三关
//					4第四关
//					5返回首页
//功能：打印背景图
//	在矩形（）处可点击，点击进入第一关，返回1，有贴图
//	在矩形（)处可点击，点击进入第二关，返回2，有贴图
//	在矩形（）处可点击，点击进入第三关，返回3，有贴图
//	在矩形（）处可点击，点击进入第四关，返回4，有贴图
//  在矩形（）处可点击，点击返回首页，返回5


int loadmap() {			//介入函数
	IMAGE img;		//定义一张背景图的变量名称
	loadimage(&img, "背景图1.jpg", 1000, 700);		//加载出地图背景图
	IMAGE img1, img2, img3, img4, img5, img6, img7, img8, img9, img10;	//img1-img8尺寸都是85
	loadimage(&img1, "一.png");			//加载黑色彩图
	loadimage(&img2, "透明图1.png");		//加载白底黑图
	loadimage(&img4, "二.png");			//加载黑色彩图
	loadimage(&img3, "透明图2.png");		//加载白底黑图
	loadimage(&img5, "三.png");			//加载黑色彩图
	loadimage(&img6, "透明图3.png");		//加载白底黑图
	loadimage(&img8, "四.png");			//加载黑色彩图
	loadimage(&img7, "透明图4.png");		//加载白底黑图
	loadimage(&img9, "透明图.png");		//加载黑色彩图
	loadimage(&img10, "返回.png");		//加载白底黑图
	while (1)		//让程序处于一直循环状态,
	{
		BeginBatchDraw();		//双缓冲绘图的开始处

		//画出地图选择的模样
		//透明图的合成:黑色彩图用SRCPAINT白底黑图用SRCAND

		putimage(0, 0, &img);										//打印出地图背景图
		//打印第一关的图片

		putimage(100, 355, &img2, SRCAND);				//打印图片
		putimage(100, 355, &img1, SRCPAINT);				//左上角位置是(100,355)
		//打印第二关的图片

		putimage(260, 200, &img3, SRCAND);				//打印图片
		putimage(260, 200, &img4, SRCPAINT);			//左上角位置是(260,200)
		//打印第三关的图片

		putimage(430, 465, &img6, SRCAND);				//打印图片
		putimage(430, 465, &img5, SRCPAINT);			//左上角位置是(430,465)
		//打印第四关的图片

		putimage(700, 280, &img7, SRCAND);				//打印图片
		putimage(700, 280, &img8, SRCPAINT);			//左上角位置是(700,280)
		//打印返回键

		putimage(0, 0, &img9, SRCAND);
		putimage(0, 0, &img10, SRCPAINT);//左上角位置在(960,0),尺寸(40,40)	

		EndBatchDraw();		//双缓冲绘图结尾处

		//FlushBatchDraw();		//双缓冲绘图

		//获取鼠标信息
		//switch case里面case后的定义名或函数名要不同,如果需要连续判断可以写在同一个if{}里面
		if (MouseHit)		//判断鼠标是否点击
		{
			MOUSEMSG msg = GetMouseMsg();		//获取鼠标信息
			switch (msg.uMsg)					//switch case函数
			{
			case WM_LBUTTONDOWN:				//判断左键的信息
				if (msg.x > 100 && msg.x < 175 && msg.y < 640 && msg.y>355)	//判断鼠标点击间距
				{
					printf("第一关\n");		//控制台测试用
					LEVEL_1::level1();
					return 1;				//返回值1，接入战斗
				}
				if (msg.x > 260 && msg.x < 345 && msg.y < 495 && msg.y>200) 	//判断鼠标点击间距
				{
					printf("第二关\n");		//控制台测试用
					LEVEL_2::level2();
					return 2;				//返回值2，接入战斗
				}
				if (msg.x > 430 && msg.x < 515 && msg.y < 550 && msg.y>465) 	//判断鼠标点击间距
				{
					printf("第三关\n");		//控制台测试用
					LEVEL_3::level3();
					return 3;				//返回值3，接入战斗
				}
				if (msg.x > 700 && msg.x < 785 && msg.y < 335 && msg.y>280) 	//判断鼠标点击间距
				{
					printf("第四关\n");		//控制台测试用
					LEVEL_4::level4();
					return 4;				//返回值4，接入战斗
				}
				if (msg.x > 0 && msg.x < 40 && msg.y < 40 && msg.y>0) 	//判断鼠标点击间距
				{
					printf("返回\n");		//控制台测试用
					print_Homepage();
					return 5;				//返回值5，返回页面
				}
			}
		}

	}
	//程序结束
}

int print_map() {
	//initgraph(1000, 700, SHOWCONSOLE);
	loadmap();
	return 0;
}
