#include "Peshka.h"

Peshka::Peshka(bool color, bool _playerColor)
    : Figure('P', 1, color, 4)
{
	firstStroke = true;
	playerColor = _playerColor;
}

Peshka::~Peshka()
{
}

string Peshka::type() const
{
    return "Peshka";
}

void Peshka::setFirstStroke()
{
	firstStroke = false;
}

bool Peshka::nextStroke(int _numberOfDirections, int& _x, int& _y)
{
	if (color == playerColor)
	{
		if (_numberOfDirections == 0)//вверх
		{
			_y--;
		}
		else if (_numberOfDirections == 1)//вверх
		{
			if (firstStroke == true)
			{
				_y -= 2;
			}
			else
			{
				_y--;
			}
		}
		else if (_numberOfDirections == 2)//влево-вверх
		{
			_y--;
			_x--;
		}
		else if (_numberOfDirections == 3)//вправо-вверх
		{
			_y--;
			_x++;
		}
	}
	else
	{
		if (_numberOfDirections == 0)//вверх
		{
			_y++;
		}
		else if (_numberOfDirections == 1)//вверх
		{
			if (firstStroke == true)
			{
				_y += 2;
			}
			else
			{
				_y++;
			}
		}
		else if (_numberOfDirections == 2)//влево-вниз
		{
			_y++;
			_x--;
		}
		else if (_numberOfDirections == 3)//вправо-вниз
		{
			_y++;
			_x++;
		}
	}
	return false; //всегда возвращает false так как длины ходов единичны
}