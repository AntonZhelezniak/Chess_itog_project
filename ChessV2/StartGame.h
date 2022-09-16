#pragma once
#include"Map.h"
#include<conio.h>
#include<ctime>

class StartGame
{
	Map* foo;//создание указателя поля с расставленными фигурами

	
public:
	StartGame(bool color);
	//StartGame(string x);

	void Logic(); //основной процесс игры
	char yourStroke();//ход игрока
	void save() const;
	void load();
};

