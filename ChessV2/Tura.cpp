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
	if (_numberOfDirections == 0)//�����
	{
		_y--;
	}
	else if (_numberOfDirections == 1)//������
	{
		_x++;
	}
	else if (_numberOfDirections == 2)//����
	{
		_y++;
	}
	else if (_numberOfDirections == 3)//�����
	{
		_x--;
	}
	return true; //������ ���������� true ��� ��� ����� ����� ����������
}
