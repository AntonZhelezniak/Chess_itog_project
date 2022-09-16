#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Figure
{
protected:
	char symbol;//������ �� ��������� �����
	//int index;//����� ������ (� ������� � ����� 0-7)
	int price;//�������� ������
	bool color; //0-�����,1-������
	//vector<int> strokeDirections;//����������� ���� (0-�����)
	int numberOfDirections;
public:
	Figure(char symbol,	int price,	bool color, int numberOfDirections);
	virtual ~Figure();
	
	char getSymbol() const;//������������
	virtual string type() const = 0;
	virtual bool nextStroke(int _numberOfDirections, int& _x, int& _y) = 0; //��������� ���������� �����, ��� ���������� ������ � ���������� true?
	
	bool getColor() const;
	int getPrice() const;
	int getNumberOfDirections() const;
};

