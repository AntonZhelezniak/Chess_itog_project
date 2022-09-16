#include "Slon.h"

Slon::Slon(bool color)
    : Figure('S', 8, color, 4)
{
}

Slon::~Slon()
{
}

string Slon::type() const
{
    return "Slon";
}

bool Slon::nextStroke(int _numberOfDirections, int& _x, int& _y)
{
	if (_numberOfDirections == 0)//�����-������
	{
		_y--;
		_x++;
	}
	else if (_numberOfDirections == 1)//����-������
	{
		_y++;
		_x++;
	}
	else if (_numberOfDirections == 2)//����-�����
	{
		_y++;
		_x--;
	}
	else if (_numberOfDirections == 3)//�����-�����
	{
		_x--;
		_y--;
	}
	return true; //������ ���������� true ��� ��� ����� ����� ����������
}
