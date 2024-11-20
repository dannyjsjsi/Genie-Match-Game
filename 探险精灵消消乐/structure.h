#pragma once

struct Boss {
	char name[10];
	int Blood;
	int attack;


};

struct character {
	char name[10];
	int blood;
	int skill;
};

typedef  struct  position {

	int x;

	int y;

}posType;



//IMAGE _1, _2, _3, _4, _5, _6, _7, _8;
//int hupo() {
//	for (int x = 50, y = 50; x < 286 && y < 516; x += 30, y += 30) {
//		loadimage(&_1, "çúçê.png");
//		loadimage(&_2, "çúçêÍ¸Ã÷Í¼.png");
//		putimage(x, y, &_2, SRCAND);
//		putimage(x, y, &_1, SRCPAINT);
//	}
//	return 0;
//}
//int lanbaoshi() {
//	loadimage(&_1, "À¶±¦Ê¯.png");
//	loadimage(&_2, "À¶±¦Ê¯Í¸Ã÷Í¼.png");
//	putimage(150, 150, &_2, SRCAND);
//	putimage(150, 150, &_1, SRCPAINT);
//	return 0;
//}
//int shitou() {
//	loadimage(&_1, "Ê¯Í·.png");
//	loadimage(&_2, "Ê¯Í·Í¸Ã÷Í¼.png");
//	putimage(100, 100, &_2, SRCAND);
//	putimage(100, 100, &_1, SRCPAINT);
//	return 0;
//}
