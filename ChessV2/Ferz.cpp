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
	return true; //������ ���������� true ��� ��� ����� ����� ����������
}
