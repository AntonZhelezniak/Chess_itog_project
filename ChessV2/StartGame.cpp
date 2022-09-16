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
		if (foo->findKing(King_i, King_j, foo->getPlayerColor()))//���� ������ ���
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
				if (foo->isThereFigure(i, j, foo->getPlayerColor()) == true) //���� �� ��� ������ ������?
				{
					if (foo->isPossibleSrike(i, j, foo->getPlayerColor()) == true) //����� �� ��� ������ ������?
					{
						foo->allPossibleStrikes(i, j, foo->getPlayerColor());//��������� ���� ���������� ������
						FigureIsActive = true;//��� ������ ������ ����
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
			if (FigureIsActive == false) continue;//�������� ����� ����
			else
			{
				do //���� �� ������� �� �������� ���
				{
					int i1 = 0, j1 = 0;
					foo->coutPole();
					Enter = yourStroke();
					if (Enter == 13 || Enter == 27) //enter or esc
					{
						foo->coordinatesOfCursor(i1, j1);
						if ((i1 == i && j1 == j) || Enter == 27)//���� ��������� enter ��������� � ���������� ��� ������ esc
						{
							foo->delPosStrokeBy2();//������ ������
							break;
						}
						else
						{
							if (foo->matchedStrike(i1, j1) == true) //���� ��� ��������
							{
								foo->dislocate(i, j, i1, j1);
								foo->delPosStrokeBy2();
								if (foo->isTherePeshka(i1, j1) == true)
								{
									foo->setForPeshka(i1, j1);//�������� ����� ��� ������ ��� ���
								}
								FigureStrikes = true;
								break;
							}
							else //���� ��� ����������. ��������������
							{
								continue;
							}
						}
					}
				} while (true);
			}
		} while (!FigureStrikes);
		//=======================������ ����������=======
		//Stage 1 ����� ������ � �������� ��� ������������
		
		//foo->findKing(King_i, King_j, !color);
		//if (foo->allCanStrikes(King_i, King_j, foo->getPlayerColor()) == true)//������ � ���������,���
		if(false)
		{
			//�������� ������
		}
		else //������ � ������������
		{
			if (foo->findKing(King_i, King_j, !foo->getPlayerColor()))//���� ������ ���
			{
				throw (string)"Game over. Enemy king is empty!";
			}
			foo->allEnemyStrikes(); //���������� ���� 3 ����� ���������� ������
			foo->theMostPriceStrike(); //���������� ������� ������ ������� �������
			foo->delPosStrokeBy2();//�������� ���� 3 ���� � if
			vector<int> price = foo->getPrice();
			foo->delPrice();
			if (price.empty()==false) //���� ���� ��� ����
			{
				int temp_i=0, temp_j = 0, temp_ix=0, temp_jx=0;
				foo->FindCoordinates(temp_i, temp_j, temp_ix, temp_jx, *(price.begin()));
				foo->dislocate(temp_i, temp_j, temp_ix, temp_jx);
				
			}
			else//���� ������ ����
			{
				bool ex = false;
				while (true)
				{
					int x1 = 0, x2 = 7;
					int y1 = 0, y2 = 7;
					int randomi = rand() % (x2 - x1 + 1) + x1;
					int randomj = rand() % (y2 - y1 + 1) + y1;
					if (foo->isThereFigure(randomi, randomj, !foo->getPlayerColor()))//���� �� ��� ������ ����������
					{
						if (foo->isPossibleSrike(randomi, randomj, !foo->getPlayerColor()))//����� �� ��� ��������? ���� �� ��
						{
							foo->allPossibleStrikes(randomi, randomj, !foo->getPlayerColor());//�� ���� 3 ��� ��������� �����
							while (true)
							{
								int randomi1 = rand() % (x2 - x1 + 1) + x1;
								int randomj1 = rand() % (y2 - y1 + 1) + y1;
								if (foo->matchedStrike(randomi1, randomj1))//���� ����� ���� ��������
								{
									foo->dislocate(randomi, randomj, randomi1, randomj1);
									foo->delPosStrokeBy2();
									if (foo->isTherePeshka(randomi1, randomj1) == true)
									{
										foo->setForPeshka(randomi1, randomj1);//�������� ����� ��� ������ ��� ���
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
		else if (g == 13)//������ Enter
		{
			return g;
		}
		if (g == 27) //������ Esc
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
