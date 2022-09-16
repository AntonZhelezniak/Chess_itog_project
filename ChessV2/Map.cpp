#include "Map.h"
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

Map::Map()
{
	playerColor = 0;

}

Map::Map(bool color)
{
	playerColor = color;
	for (int i = 0; i < 8; i++)
	{
		vector<Figure*> tmp;
		for (int j = 0; j < 8; j++)
		{
			tmp.push_back(nullptr);
		}
		Pole.push_back(tmp);
	}
	//====my figures
	
	Pole[7][0] = new Tura(color);
	Pole[7][1] = new Horse(color);
	Pole[7][2] = new Slon(color);
	Pole[7][3] = new Ferz(color);
	Pole[7][4] = new King(color);
	Pole[7][5] = new Slon(color);
	Pole[7][6] = new Horse(color);
	Pole[7][7] = new Tura(color);

	Pole[6][0] = new Peshka(color, color);
	Pole[6][1] = new Peshka(color, color);
	Pole[6][2] = new Peshka(color, color);
	Pole[6][3] = new Peshka(color, color);
	Pole[6][4] = new Peshka(color, color);
	Pole[6][5] = new Peshka(color, color);
	Pole[6][6] = new Peshka(color, color);
	Pole[6][7] = new Peshka(color, color);
	//===enemy figures
	Pole[0][0] = new Tura(!color);
	Pole[0][1] = new Horse(!color);
	Pole[0][2] = new Slon(!color);
	Pole[0][3] = new Ferz(!color);
	Pole[0][4] = new King(!color);
	Pole[0][5] = new Slon(!color);
	Pole[0][6] = new Horse(!color);
	Pole[0][7] = new Tura(!color);

	Pole[1][0] = new Peshka(!color, color);
	Pole[1][1] = new Peshka(!color, color);
	Pole[1][2] = new Peshka(!color, color);
	Pole[1][3] = new Peshka(!color, color);
	Pole[1][4] = new Peshka(!color, color);
	Pole[1][5] = new Peshka(!color, color);
	Pole[1][6] = new Peshka(!color, color);
	Pole[1][7] = new Peshka(!color, color);

	

	for (int i = 0; i < 8; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < 8; j++)
		{
			tmp.push_back(0);
		}
		Cursor.push_back(tmp);
	}
	*((*(Cursor.end()-1)).begin()) = 1; //alternative Cursor[7][0] = 1;  but more safety

	for (int i = 0; i < 8; i++)
	{
		vector<int> tmp;
		for (int j = 0; j < 8; j++)
		{
			tmp.push_back(0);
		}
		PosStroke.push_back(tmp);
	}
}

Map::~Map()
{
}

void Map::coutPole() const
{
	system("cls");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char tmp = ' ';
			bool tmpColor = 0;
			if (Pole[i][j] != nullptr)
			{
				tmp = Pole[i][j]->getSymbol();
				tmpColor = Pole[i][j]->getColor();
			}
			if (Cursor[i][j]==1) //если там курсор
			{
				if (tmpColor == 0)//белая фигура
				{
					SetConsoleTextAttribute(console, 225); cout << tmp; SetConsoleTextAttribute(console, 7);//жельый фон белая фигура
				}
				else//черная фигура
				{
					SetConsoleTextAttribute(console, 228); cout << tmp; SetConsoleTextAttribute(console, 7);//жельый фон черная фигура
				}
			}
			else if (PosStroke[i][j] == 2) //если там можно бить
			{
				if (tmpColor == 0)//белая фигура
				{
					SetConsoleTextAttribute(console, 97); cout << tmp; SetConsoleTextAttribute(console, 7);//жельый фон белая фигура
				}
				else//черная фигура
				{
					SetConsoleTextAttribute(console, 100); cout << tmp; SetConsoleTextAttribute(console, 7);//жельый фон черная фигура
				}
			}
			else if ((i + j)%2!=0 ) //черная клетка
			{
				if (tmpColor == 0)//белая фигура
				{
					SetConsoleTextAttribute(console, 129); cout << tmp; SetConsoleTextAttribute(console, 7);//черный фон белая фигура
				}
				else//черная фигура
				{
					SetConsoleTextAttribute(console, 132); cout << tmp; SetConsoleTextAttribute(console, 7);//черный фон черная фигура
				}
				
			}
			else //белая клетка
			{
				if (tmpColor == 0)//белая фигура
				{
					SetConsoleTextAttribute(console, 113); cout << tmp; SetConsoleTextAttribute(console, 7);//белый фон белая фигура
				}
				else//черная фигура
				{
					SetConsoleTextAttribute(console, 116); cout << tmp; SetConsoleTextAttribute(console, 7);//белый фон черная фигура
				}
			}
		}
		cout << endl;
	}
	//for (int i = 0;i < 256;i++) { SetConsoleTextAttribute(console, i); cout << i <<endl; } //вывод всех цветов
}

bool Map::getPlayerColor() const
{
	return playerColor;
}


void Map::cursorUp()
{
	vector<vector<int>>::iterator it;
	vector<int>::iterator jt;

	for (it = Cursor.begin(); it < Cursor.end(); it++)
	{
		jt = find((*it).begin(), (*it).end(), 1);
		if (jt != (*it).end())//если нашел курсор то выход
		{
			break;
		}
	}
	if (it != Cursor.begin())//если не верхняя ячейка
	{
		//int count = jt - (*it).begin(); //кол-во ячеек  от начала до текущей
		// ячейка над текущей (* (it - 1)).begin() + count
		//полная формула (* (it - 1)).begin() + (jt - (*it).begin());
		iter_swap(jt, (*(it - 1)).begin() + (jt - (*it).begin()));
	}
	else
	{
		iter_swap(jt, (*(Cursor.end()-1)).begin() + (jt - (*it).begin()));
	}
}
void Map::cursorDown()
{
	vector<vector<int>>::iterator it;
	vector<int>::iterator jt;

	for (it = Cursor.begin(); it < Cursor.end(); it++)
	{
		jt = find((*it).begin(), (*it).end(), 1);
		if (jt != (*it).end())//если нашел курсор то выход
		{
			break;
		}
	}
	if (it != Cursor.end()-1)//если не нижняя ячейка
	{
		iter_swap(jt, (*(it + 1)).begin() + (jt - (*it).begin()));
	}
	else
	{
		iter_swap(jt, (*(Cursor.begin())).begin() + (jt - (*it).begin()));
	}
}
void Map::cursorLeft()
{
	vector<vector<int>>::iterator it;
	vector<int>::iterator jt;

	for (it = Cursor.begin(); it < Cursor.end(); it++)
	{
		jt = find((*it).begin(), (*it).end(), 1);
		if (jt != (*it).end())//если нашел курсор то выход
		{
			break;
		}
	}
	if ((jt) != (*it).begin())
	{
		iter_swap(jt, jt - 1);
	}
	else
	{
		iter_swap(jt, (*it).end()-1);
	}
}
void Map::cursorRight()
{
	vector<vector<int>>::iterator it;
	vector<int>::iterator jt;

	for (it = Cursor.begin(); it < Cursor.end(); it++)
	{
		jt = find((*it).begin(), (*it).end(), 1);
		if (jt != (*it).end())//если нашел курсор то выход
		{
			break;
		}
	}
	if ((jt+1) != (*it).end())
	{
		iter_swap(jt, jt + 1);
	}
	else
	{
		iter_swap(jt, (*it).begin());
	}
}

void Map::coordinatesOfCursor(int& i, int& j)
{
	vector<vector<int>>::iterator it;
	vector<int>::iterator jt;

	for (it = Cursor.begin(); it < Cursor.end(); it++)
	{
		jt = find((*it).begin(), (*it).end(), 1);
		if (jt != (*it).end())//если нашел курсор то выход
		{
			break;
		}
	}
	i = it - Cursor.begin();
	j = jt - (*it).begin(); 
}



bool Map::isThereFigure(int i, int j, bool color)
{
	if (Pole[i][j] != nullptr)
	{
		bool _color = Pole[i][j]->getColor();
		if (_color == color) return true;
		else return false;
	}
	return false;
}



bool Map::isPossibleSrike(int i, int j, bool color)
{
	if (Pole[i][j] != nullptr)
	{
		if (Pole[i][j]->type() == "Peshka")
		{
			for (int k = 0; k < Pole[i][j]->getNumberOfDirections(); k++)
			{
				int tempi = i;
				int tempj = j;
				Pole[i][j]->nextStroke(k, tempj, tempi);
				if (k <= 1)
				{
					if (tempi >= 0 && tempi <= 7 && tempj >= 0 && tempj <= 7 && !isThereFigure(tempi, tempj, color) && !isThereFigure(tempi, tempj, color))
					{
						return true;//если нашло хоть один возможный ход
					}
				}
				if (k > 1)
				{
					if (tempi >= 0 && tempi <= 7 && tempj >= 0 && tempj <= 7 && isThereFigure(tempi, tempj, !color))//если там есть фигура противника
					{
						return true;//если нашло хоть один возможный ход
					}
				}
				
			}
			return false; //если дошло до сюда то не найдены возможные ходы
		}
		else
		{
			for (int k = 0; k < Pole[i][j]->getNumberOfDirections(); k++)
			{
				int tempi = i;
				int tempj = j;
				Pole[i][j]->nextStroke(k, tempj, tempi);
				if (tempi >= 0 && tempi <= 7 && tempj >= 0 && tempj <= 7 && !isThereFigure(tempi, tempj, color))
				{
					return true;//если нашло хоть один возможный ход
				}
			}
			return false; //если дошло до сюда то не найдены возможные ходы
		}
		
	}
	else;//для exception
}

void Map::allPossibleStrikes(int i, int j, bool color)
{
	if (Pole[i][j] != nullptr)
	{
		if (Pole[i][j]->type() == "Peshka")
		{
			for (int k = 0; k < Pole[i][j]->getNumberOfDirections(); k++)
			{
				int tempi = i;
				int tempj = j;
				bool R = false; //если true то можно дальше продолжать в этом направлении
				R = Pole[i][j]->nextStroke(k, tempj, tempi);
				if (k <= 1)
				{
					
					if (tempi >= 0 && tempi <= 7 && tempj >= 0 && tempj <= 7 && !isThereFigure(tempi, tempj, !color) && !isThereFigure(tempi, tempj, !color))//если там нет фигур (своей и противника)
					{
						setPosStrokeBy2(tempi, tempj);
					}
				}
				else
				{
					if (tempi >= 0 && tempi <= 7 && tempj >= 0 && tempj <= 7 && isThereFigure(tempi, tempj, !color))//если там фигура противника
					{
						setPosStrokeBy2(tempi, tempj);
					}
				}
				
			}
		}
		else
		{
			for (int k = 0; k < Pole[i][j]->getNumberOfDirections(); k++)
			{
				int tempi = i;
				int tempj = j;
				bool R = false; //если true то можно дальше продолжать в этом направлении
				for (;;)
				{
					R = Pole[i][j]->nextStroke(k, tempj, tempi);
					if (tempi >= 0 && tempi <= 7 && tempj >= 0 && tempj <= 7 && !isThereFigure(tempi, tempj, color))
					{
						setPosStrokeBy2(tempi, tempj);
						if (isThereFigure(tempi, tempj, !playerColor) == true || R == false)
						{
							break;//выход из внутреннего цикла
						}
					}
					else //если за диапазоном карты или своя фигура
					{
						break;
					}
				}
			}
		}
		
	}
	else;//для exception
}

void Map::setPosStrokeBy2(int i, int j)
{
	PosStroke[i][j] = 2;
}
void Map::delPosStrokeBy2()
{
	vector<vector<int>>::iterator it;

	for (it = PosStroke.begin(); it < PosStroke.end(); it++)
	{
		replace((*it).begin(), (*it).end(), 2, 0);
	}
}

bool Map::matchedStrike(int i, int j)
{
	if (PosStroke[i][j] == 2)
	{
		return true;
	}
	return false;
}

void Map::dislocate(int i, int j, int new_i, int new_j)
{
	if (Pole[new_i][new_j] != nullptr)
	{
		Pole[new_i][new_j]->~Figure(); //полиморфизм
	}
	Pole[new_i][new_j] = Pole[i][j];
	Pole[i][j] = nullptr;
}

bool Map::allCanStrikes(int i, int j, bool _color)
{
	vector<vector<Figure*>>::iterator it;
	vector<Figure*>::iterator jt;

	for (it = Pole.begin(); it < Pole.end(); it++)
	{
		for (jt = (*it).begin(); jt < (*it).end(); jt++)
		{
			if ((*jt)->getColor() == _color)
			{
				int a = it - Pole.begin();
				int b = jt - (*it).begin();
				allPossibleStrikes(a, b, _color); //наполняем вектор 3 всеми возможными ударами всех фигур
			}
		}
	}
	if (matchedStrike(i, j) == true)
	{
		delPosStrokeBy2();
		return true;
	}
	else
	{
		delPosStrokeBy2();
		return false;
	}
}

bool Map::findKing(int& i, int& j, bool color)
{
	vector<vector<Figure*>>::iterator it;
	vector<Figure*>::iterator jt;

	bool Exit = false;
	for (it = Pole.begin(); it < Pole.end(); it++)
	{
		for (jt = (*it).begin(); jt < (*it).end(); jt++)
		{
			if (*jt != nullptr)
			{
				if ((*jt)->type() == "King" && (*jt)->getColor() == color)
				{
					Exit = true;
					break;
				}
			}
		}
		if (Exit == true)
		{
			break;
		}
	}
	if (Exit == false)
	{
		return true;
	}
	i = it - Pole.begin();
	j = jt - (*it).begin();
	return false;
}

void Map::allEnemyStrikes()
{
	vector<vector<Figure*>>::iterator it;
	vector<Figure*>::iterator jt;

	for (it = Pole.begin(); it < Pole.end(); it++)
	{
		for (jt = (*it).begin(); jt < (*it).end(); jt++)
		{
			int i = it - Pole.begin();
			int j = jt - (*it).begin();
			if (isThereFigure(i,j, !playerColor)==true)
			{
				allPossibleStrikes(i, j, !playerColor); //наполняем вектор 3 всеми возможными ударами всех фигур игрока
				
			}
		}
	}

}

void Map::theMostPriceStrike()
{
	vector<vector<Figure*>>::iterator it;
	vector<Figure*>::iterator jt;
	vector<vector<int>>::iterator item;
	vector<int>::iterator jtem;
	
	for (it = Pole.begin(), item = PosStroke.begin(); it < Pole.end(); it++, item++)
	{
		for (jt = (*it).begin(), jtem = (*item).begin(); jt < (*it).end(); jt++, jtem++)
		{
			if (*jtem == 2 && *jt != nullptr)//если на слое 3 находится 2 и там есть фигура (может быть только фигура игрока)
			{
				price.push_back((*jt)->getPrice());//набор ценности всех возможных ударов
			}
		}
	}
	if (price.empty() != true)
	{
		sort(price.begin(), price.end());
	}
}

vector<int> Map::getPrice() const
{

	return price;
}

void Map::delPrice()
{
	price.clear();
}

void Map::FindCoordinates(int& i1, int& j1, int& i2, int& j2, int _price)
{
	vector<vector<Figure*>>::iterator it;
	vector<Figure*>::iterator jt;

	bool ex = false;
	for (it = Pole.begin(); it < Pole.end(); it++)
	{
		for (jt = (*it).begin(); jt < (*it).end(); jt++)
		{
			int i = it - Pole.begin();
			int j = jt - (*it).begin();
			if (isThereFigure(i, j, !playerColor) == true)
			{
				
				allPossibleStrikes(i, j, !playerColor);

				vector<vector<Figure*>>::iterator ait;
				vector<Figure*>::iterator ajt;
				vector<vector<int>>::iterator item;
				vector<int>::iterator jtem;

				for (ait = Pole.begin(), item = PosStroke.begin(); ait < Pole.end(); ait++, item++)
				{
					for (ajt = (*ait).begin(), jtem = (*item).begin(); ajt < (*ait).end(); ajt++, jtem++)
					{
						if (*jtem == 2 && *ajt != nullptr)//если на слое 3 находится 2 и там есть фигура (может быть только фигура игрока)
						{
							if ((*ajt)->getPrice() == _price)
							{
								i2 = ait - Pole.begin();
								j2 = ajt - (*ait).begin();
								i1 = i;
								j1 = j;
								ex = true;
								delPosStrokeBy2();
							}
						}
						if (ex) break;
					}
					if (ex) break;
				}
			}
			if (ex) break;
		}
		if (ex) break;
	}
}

bool Map::isTherePeshka(int i, int j) const
{
	if (Pole[i][j]->type() == "Peshka")
	{
		return true;
	}
	return false;
}

void Map::setForPeshka(int i, int j)
{
	((Peshka*)(Pole[i][j]))->setFirstStroke();
}

void Map::saveGame() const
{
	ofstream file("Chess.txt");
	if (file.is_open())
	{
		file << playerColor << endl;
		for (int i=0;i<8;i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (Pole[i][j] != nullptr)
				{
					file << Pole[i][j]->type() << endl<< Pole[i][j]->getColor()<<endl;
				}
				else
				{
					file << "nullptr" << endl;
				}
			}
		}
		cout << "Data saved to file!" << endl;
		file.close();
	}
	else cout << "Error saving file!" << endl;
}

void Map::loadGame()
{
	ifstream file("Chess.txt");
	if (file.is_open())
	{
		file >> playerColor;
		string line;
		for (int i = 0; i < 8; i++)
		{
			vector<Figure*> tmp;
			for (int j = 0; j < 8; j++)
			{
				getline(file, line);
				//tmp.push_back(nullptr);
				if (line == "nullptr")
				{
					tmp.push_back(nullptr);
				}
				else if (line == "Peshka")
				{
					bool c;
					file >> c;
					tmp.push_back(new Peshka(c,playerColor));
				}
				else if (line == "Tura")
				{
					bool c;
					file >> c;
					tmp.push_back(new Tura(c));
				}
				else if (line == "Horse")
				{
					bool c;
					file >> c;
					tmp.push_back(new Horse(c));
				}
				else if (line == "Slon")
				{
					bool c;
					file >> c;
					tmp.push_back(new Slon(c));
				}
				else if (line == "Ferz")
				{
					bool c;
					file >> c;
					tmp.push_back(new Ferz(c));
				}
				else if (line == "King")
				{
					bool c;
					file >> c;
					tmp.push_back(new King(c));
				}
			}
			Pole.push_back(tmp);
		}
	}
			
			
}
