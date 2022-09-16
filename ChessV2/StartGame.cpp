#include "StartGame.h"

StartGame::StartGame(bool color)
{
	foo = new Map(color);//create pole
	srand(time(NULL));
}

//StartGame::StartGame(string x)
//{
//	foo = new Map();
//	srand(time(NULL));
//}

void StartGame::Logic()
{
	do
	{
		int King_i = 0, King_j = 0;
		bool FigureStrikes = false;
		if (foo->findKing(King_i, King_j, foo->getPlayerColor()))//если короля нет
		{
			throw (string)"Game over. Your king is empty!";
		}
		do
		{
			foo->coutPole();
			char Enter = yourStroke();
			int i=0, j=0;
			bool FigureIsActive = false;
			if (Enter == 13)//Enter
			{
				foo->coordinatesOfCursor(i, j);
				if (foo->isThereFigure(i, j, foo->getPlayerColor()) == true) //есть ли там фигура игрока?
				{
					if (foo->isPossibleSrike(i, j, foo->getPlayerColor()) == true) //может ли эта фигура ходить?
					{
						foo->allPossibleStrikes(i, j, foo->getPlayerColor());//заполняем поле возможными ходами
						FigureIsActive = true;//эта фигура готова бить
					}
				}
			}
			else if (Enter == 27)//Esc
			{
				cout << "Do you want save game? Enter/Esc" << endl;
				char g;
				g = _getch();
				if (g == 13)//Enter
				{
					foo->saveGame();
					
				}

			}
			if (FigureIsActive == false) continue;//начинаем новый цикл
			else
			{
				do //пока не нажмешь на реальный ход
				{
					int i1 = 0, j1 = 0;
					foo->coutPole();
					Enter = yourStroke();
					if (Enter == 13 || Enter == 27) //enter or esc
					{
						foo->coordinatesOfCursor(i1, j1);
						if ((i1 == i && j1 == j) || Enter == 27)//если следующий enter совпадает с предыдущим или нажата esc
						{
							foo->delPosStrokeBy2();//отмена фигуры
							break;
						}
						else
						{
							if (foo->matchedStrike(i1, j1) == true) //если ход возможен
							{
								foo->dislocate(i, j, i1, j1);
								foo->delPosStrokeBy2();
								if (foo->isTherePeshka(i1, j1) == true)
								{
									foo->setForPeshka(i1, j1);//указание пешке что первый ход был
								}
								FigureStrikes = true;
								break;
							}
							else //если ход невозможен. необязательный
							{
								continue;
							}
						}
					}
				} while (true);
			}
		} while (!FigureStrikes);
		//=======================ЛОГИКА ПРОТИВНИКА=======
		//Stage 1 поиск короля и проверка его безопасности
		
		//foo->findKing(King_i, King_j, !color);
		//if (foo->allCanStrikes(King_i, King_j, foo->getPlayerColor()) == true)//король в опасности,шах
		if(false)
		{
			//доделать логику
		}
		else //король в безопасности
		{
			if (foo->findKing(King_i, King_j, !foo->getPlayerColor()))//если короля нет
			{
				throw (string)"Game over. Enemy king is empty!";
			}
			foo->allEnemyStrikes(); //запронение слоя 3 всеми возможными ходами
			foo->theMostPriceStrike(); //заполнение массива самыми ценными ударами
			foo->delPosStrokeBy2();//удаление слоя 3 чтоб в if
			vector<int> price = foo->getPrice();
			foo->delPrice();
			if (price.empty()==false) //если есть что бить
			{
				int temp_i=0, temp_j = 0, temp_ix=0, temp_jx=0;
				foo->FindCoordinates(temp_i, temp_j, temp_ix, temp_jx, *(price.begin()));
				foo->dislocate(temp_i, temp_j, temp_ix, temp_jx);
				
			}
			else//если нечего бить
			{
				bool ex = false;
				while (true)
				{
					int x1 = 0, x2 = 7;
					int y1 = 0, y2 = 7;
					int randomi = rand() % (x2 - x1 + 1) + x1;
					int randomj = rand() % (y2 - y1 + 1) + y1;
					if (foo->isThereFigure(randomi, randomj, !foo->getPlayerColor()))//есть ли там фигура противника
					{
						if (foo->isPossibleSrike(randomi, randomj, !foo->getPlayerColor()))//может ли она стрелять? если да то
						{
							foo->allPossibleStrikes(randomi, randomj, !foo->getPlayerColor());//на слое 3 все возможные удары
							while (true)
							{
								int randomi1 = rand() % (x2 - x1 + 1) + x1;
								int randomj1 = rand() % (y2 - y1 + 1) + y1;
								if (foo->matchedStrike(randomi1, randomj1))//если можно туда походить
								{
									foo->dislocate(randomi, randomj, randomi1, randomj1);
									foo->delPosStrokeBy2();
									if (foo->isTherePeshka(randomi1, randomj1) == true)
									{
										foo->setForPeshka(randomi1, randomj1);//указание пешке что первый ход был
									}
									ex = true;
								}
								if (ex) break;
							}
						}
					}
					if (ex) break;
				}
				
			}
		}
	} while (true);
	
}

char StartGame::yourStroke()
{

	do
	{
		char g;

		g = _getch();
		
		if (g == 119)//w
		{
			foo->cursorUp();
		}
		else if (g == 115)//s
		{
			foo->cursorDown();
		}
		else if (g == 97)//a
		{
			foo->cursorLeft();
		}
		else if (g == 100)//d
		{
			foo->cursorRight();
		}
		else if (g == 13)//символ Enter
		{
			return g;
		}
		if (g == 27) //символ Esc
		{
			return g;
		}
		foo->coutPole();
	} while (true);
}

void StartGame::save() const
{
	foo->saveGame();
}

void StartGame::load()
{
	foo->loadGame();
}
