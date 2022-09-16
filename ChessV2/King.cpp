#include "King.h"

King::King(bool color)
    : Figure('K', 100, color, 8)
{
}

King::~King()
{
}

string King::type() const
{
    return "King";
}

bool King::nextStroke(int _numberOfDirections, int& _x, int& _y)
{
	if (_numberOfDirections == 0)//вверх
	{
		_y--;
	}
	else if (_numberOfDirections == 1)//вверх-вправо
	{
		_y--;
		_x++;
	}
	else if (_numberOfDirections == 2)//вправо
	{
		_x++;
	}
	else if (_numberOfDirections == 3)//вниз-вправо
	{
		_y++;
		_x++;
	}
	else if (_numberOfDirections == 4)//вниз
	{
		_y++;
	}
	else if (_numberOfDirections == 5)//вниз-влево
	{
		_y++;
		_x--;
	}
	else if (_numberOfDirections == 6)//влево
	{
		_x--;
	}
	else if (_numberOfDirections == 7)//вверх-влево
	{
		_x--;
		_y--;
	}
	return false; //всегда возвращает false так как длины ходов ограничены
}
