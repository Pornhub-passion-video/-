#include"food.h"



Food::Food(Wall& tempWall):wall(tempWall)
{

}

void Food::setFood()
{
	while (true)
	{
		foodX = rand() % (Wall::ROW - 2) + 1;
		foodY = rand() % (Wall::COL - 2) + 1;
		//如果在蛇身上，就重新设置
		if (wall.getWall(foodX, foodY) == ' ')
		{
			wall.setWall(foodX, foodY, '#');
			break;
		}
	}
	
	
	

}
