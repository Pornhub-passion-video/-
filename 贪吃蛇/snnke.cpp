#include "snnke.h"


enum { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };
Snake::Snake(Wall& tempWall,Food &tempFood ):wall(tempWall),food(tempFood)//���캯��������ʼ��
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
	//���нڵ㶼���ٵ�
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
	//�����½ڵ�
	Point* newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;

	//���ԭ����ͷ��Ϊ�գ���ͷ��Ϊ����
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
	//ѭ���ҵ�β�ڵ�
	while (pCur->next != NULL)
	{
		pPre = pPre->next ;
		pCur = pCur->next ;
	}
	//ɾ��β�ڵ�
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

	//�ж��Ƿ��ƶ��ɹ�
	if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '=')
	{
		cout << "game over" << endl;
		return false;
	}

	//�ƶ��ɹ��Ե�ʳ��
	if (wall.getWall(x, y) == '#')
	{
		addPoint(x, y);
		//��������ʳ��
		food.setFood();
	}
	else//δ�Ե�ʳ��
	{
		addPoint(x, y);//�ⲽ�ܹؼ�
		deletePoint();
	}
	
	return true;
}
