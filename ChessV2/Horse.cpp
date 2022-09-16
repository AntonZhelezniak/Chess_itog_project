#include "Horse.h"

Horse::Horse(bool color)
    : Figure('H', 10, color, 8)
{    
}

Horse::~Horse()
{
}

string Horse::type() const
{
    return "Horse";
}

bool Horse::nextStroke(int _numberOfDirections, int& _x, int& _y)
{
	if (_numberOfDirections == 0)//вверх-вправо
	{
		_y-=2;
		_x++;
	}
	else if (_numberOfDirections == 1)//вправо-вверх
	{
		_y--;
		_x+=2;
	}
	else if (_numberOfDirections == 2)//вправо-вниз
	{
		_y++;
		_x+=2;
	}
	else if (_numberOfDirections == 3)//вниз-вправо
	{
		_y+=2;
		_x++;
	}
	else if (_numberOfDirections == 4)//вниз-влево
	{
		_y+=2;
		_x--;
	}
	else if (_numberOfDirections == 5)//влево-вниз
	{
		_y++;
		_x-=2;
	}
	else if (_numberOfDirections == 6)//влево-вверх
	{
		_y--;
		_x-=2;
	}
	else if (_numberOfDirections == 7)//вверх-влево
	{
		_y-=2;
		_x--;
	}
	return false; //всегда возвращает false так как длины ходов одиночны
}
