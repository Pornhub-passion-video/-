#include "snnke.h"


enum { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };
Snake::Snake(Wall& tempWall,Food &tempFood ):wall(tempWall),food(tempFood)//构造函数参数初始化
{
	pHead = NULL;
}

void Snake::initsnake()
{
	destroyPoint();
	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}

void Snake::destroyPoint()
{
	//所有节点都销毁掉
	Point* pVur = pHead;
	while (pHead != NULL)
	{
		pVur = pHead->next;
		delete pHead;
		pHead = pVur;
	}
}

void Snake::addPoint(int x, int y)
{
	//创建新节点
	Point* newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;

	//如果原来的头不为空，则将头改为身子
	if (pHead != 0)
	{
		wall.setWall(pHead->x, pHead->y, '=');
	}
	newPoint->next = pHead;
	pHead = newPoint;
	wall.setWall(pHead->x, pHead->y, '@');
}

void Snake::deletePoint()
{
	if (pHead == NULL || pHead->next == NULL)
	{
		return;
	}
	Point* pCur = pHead->next;
	Point* pPre = pHead;
	//循环找到尾节点
	while (pCur->next != NULL)
	{
		pPre = pPre->next ;
		pCur = pCur->next ;
	}
	//删除尾节点
	wall.setWall(pCur->x, pCur->y, ' ');
	delete pCur;
	pCur = NULL;
	pPre->next = NULL;
}

bool Snake::move(char key)
{ 
	int x = pHead->x;
	int y = pHead->y;
	switch (key)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}

	//判断是否移动成功
	if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=')
	{
		cout << "game over" << endl;
		return false;
	}

	//移动成功吃到食物
	if (wall.getWall(x, y) == '#')
	{
		addPoint(x, y);
		//重新设置食物
		food.setFood();
	}
	else//未吃到食物
	{
		addPoint(x, y);//这步很关键
		deletePoint();
	}
	
	return true;
}
