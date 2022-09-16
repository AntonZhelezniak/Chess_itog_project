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
	if (_numberOfDirections == 0)//�����-������
	{
		_y-=2;
		_x++;
	}
	else if (_numberOfDirections == 1)//������-�����
	{
		_y--;
		_x+=2;
	}
	else if (_numberOfDirections == 2)//������-����
	{
		_y++;
		_x+=2;
	}
	else if (_numberOfDirections == 3)//����-������
	{
		_y+=2;
		_x++;
	}
	else if (_numberOfDirections == 4)//����-�����
	{
		_y+=2;
		_x--;
	}
	else if (_numberOfDirections == 5)//�����-����
	{
		_y++;
		_x-=2;
	}
	else if (_numberOfDirections == 6)//�����-�����
	{
		_y--;
		_x-=2;
	}
	else if (_numberOfDirections == 7)//�����-�����
	{
		_y-=2;
		_x--;
	}
	return false; //������ ���������� false ��� ��� ����� ����� ��������
}
