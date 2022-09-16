#pragma once
#include"Figure.h"
#include"Ferz.h"
#include"Tura.h"
#include"Slon.h"
#include"King.h"
#include"Horse.h"
#include"Peshka.h"
#include<Windows.h>
#include<algorithm>
#include <fstream>
class Map
{
	vector<vector<Figure*>>Pole;
	vector<vector<int>>Cursor;//�������������� ���� ��� ��������� ������� ��� ������ (� ����� ��������� ������)
	vector<vector<int>>PosStroke;
	bool playerColor;
	vector<int>price;

public:
	Map();
	Map(bool color);//���������� �������� ����� ����� ������
	~Map();
	void coutPole() const;
	bool getPlayerColor() const;
	//=========���������� �������=======
	void cursorUp();
	void cursorDown();
	void cursorLeft();
	void cursorRight();

	//=========������ � ����� #2========
	void coordinatesOfCursor(int& i, int& j);

	//=========������ � ����� #3========
	void setPosStrokeBy2(int i, int j);
	void delPosStrokeBy2();
	bool matchedStrike(int i, int j);//��� ��������� ��������� �� ��� � ���������� �� ���� 3

	//=========������ � �������� �� ����=
	bool isThereFigure(int i, int j, bool color);
	bool isPossibleSrike(int i, int j, bool color);
	void allPossibleStrikes(int i, int j, bool color);

	void dislocate(int i, int j, int new_i, int new_j);

	//=========�������� ����=============
	bool allCanStrikes(int i, int j, bool _color);
	bool findKing(int& i, int& j, bool color);

	void allEnemyStrikes();
	void theMostPriceStrike();

	vector<int> getPrice() const;
	void delPrice();
	void FindCoordinates(int& i, int& j, int& i2, int& j2, int _price);

	bool isTherePeshka(int i, int j) const;
	void setForPeshka(int i, int j);

	void saveGame() const;
	void loadGame();
};

