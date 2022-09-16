#include "Tura.h"

Tura::Tura(bool color)
    : Figure('T', 9, color, 4)
{
}

Tura::~Tura()
{
}

string Tura::type() const
{
    return "Tura";
}

bool Tura::nextStroke(int _numberOfDirections, int& _x, int& _y)
{
	if (_numberOfDirections == 0)//вверх
	{
		_y--;
	}
	else if (_numberOfDirections == 1)//вправо
	{
		_x++;
	}
	else if (_numberOfDirections == 2)//вниз
	{
		_y++;
	}
	else if (_numberOfDirections == 3)//влево
	{
		_x--;
	}
	return true; //всегда возвращает true так как длины ходов бесконечны
}
