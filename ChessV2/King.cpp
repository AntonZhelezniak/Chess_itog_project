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
	if (_numberOfDirections == 0)//�����
	{
		_y--;
	}
	else if (_numberOfDirections == 1)//�����-������
	{
		_y--;
		_x++;
	}
	else if (_numberOfDirections == 2)//������
	{
		_x++;
	}
	else if (_numberOfDirections == 3)//����-������
	{
		_y++;
		_x++;
	}
	else if (_numberOfDirections == 4)//����
	{
		_y++;
	}
	else if (_numberOfDirections == 5)//����-�����
	{
		_y++;
		_x--;
	}
	else if (_numberOfDirections == 6)//�����
	{
		_x--;
	}
	else if (_numberOfDirections == 7)//�����-�����
	{
		_x--;
		_y--;
	}
	return false; //������ ���������� false ��� ��� ����� ����� ����������
}
