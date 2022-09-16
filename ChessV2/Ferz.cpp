#include "Ferz.h"

Ferz::Ferz(bool color)
	: Figure('F', 10, color, 8)
{

}

Ferz::~Ferz(){}


string Ferz::type() const
{
	return "Ferz";
}

bool Ferz::nextStroke(int _numberOfDirections, int& _x, int& _y)
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
	return true; //всегда возвращает true так как длины ходов бесконечны
}
