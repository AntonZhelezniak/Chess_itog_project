#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Figure
{
protected:
	char symbol;//—имвол на шахматной доске
	//int index;//номер фигуры (к примеру у пешек 0-7)
	int price;//ценность фигуры
	bool color; //0-белые,1-черные
	//vector<int> strokeDirections;//направлени€ хода (0-вверх)
	int numberOfDirections;
public:
	Figure(char symbol,	int price,	bool color, int numberOfDirections);
	virtual ~Figure();
	
	char getSymbol() const;//инкапсул€ци€
	virtual string type() const = 0;
	virtual bool nextStroke(int _numberOfDirections, int& _x, int& _y) = 0; //принимает координаты точки, эти координаты мен€ет и возвращает true?
	
	bool getColor() const;
	int getPrice() const;
	int getNumberOfDirections() const;
};

