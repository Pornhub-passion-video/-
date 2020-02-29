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
		//������
		int x;
		int y;

		//ָ����
		Point* next;
	};

	//������ 
	void initsnake();

	//���ٽڵ�
	void destroyPoint();
	
	//��ӽڵ�
	void addPoint(int x, int y);

	void deletePoint();
	//

	bool move(char key);
	Point* pHead;

	Wall& wall;
	Food& food;
};