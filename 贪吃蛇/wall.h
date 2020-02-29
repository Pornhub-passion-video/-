
#ifndef _WALL_HEAD
#define _WALL_HEAD
#include<iostream>

using namespace std;


class Wall
{
public:
	enum
	{
		ROW = 20,
	COL = 20
	};
	//初始化墙
	void initWall();

	//画出墙
	void drawWall();

	//根据索引设置当前位置
	void setWall(int x, int y, char c);

	//根据索引获取当前位置
	char getWall(int x ,int y);

private:
	char gameArray[ROW][COL];
};
#endif // 