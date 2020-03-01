#include<iostream>
#include"wall.h"
#include"snnke.h"
#include"food.h"
#include<ctime>
#include<conio.h>
#include<Windows.h>
using namespace std;


int main() {
	srand((unsigned int) time(NULL));

	Wall wall;
	wall.initWall();

	Food food(wall);
	food.setFood();

	Snake snake(wall,food);
	snake.initsnake();
	//snake.deletePoint();
	/*snake.move('w');
	snake.move('w');
	snake.move('a');*/

	wall.drawWall();
	
	//接受用户输入
	while (true) {
		char key = _getch();
		if (snake.move(key))
		{
			system("cls");
			wall.drawWall();
			Sleep(300);
		}
	}
}