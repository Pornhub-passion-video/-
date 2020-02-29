#pragma once
#include<iostream>
#include"wall.h"
#include"snnke.h"
#include"food.h"

using namespace std;

class Snake {
public:
	Snake(Wall& tempWall,Food &tempFood);
	struct Point
	{
		//数据域
		int x;
		int y;

		//指针域
		Point* next;
	};

	//创建蛇 
	void initsnake();

	//销毁节点
	void destroyPoint();
	
	//添加节点
	void addPoint(int x, int y);

	void deletePoint();
	//

	bool move(char key);
	Point* pHead;

	Wall& wall;
	Food& food;
};