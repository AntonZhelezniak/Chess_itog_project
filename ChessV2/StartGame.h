#pragma once
#include"Map.h"
#include<conio.h>
#include<ctime>

class StartGame
{
	Map* foo;//�������� ��������� ���� � �������������� ��������

	
public:
	StartGame(bool color);
	//StartGame(string x);

	void Logic(); //�������� ������� ����
	char yourStroke();//��� ������
	void save() const;
	void load();
};

