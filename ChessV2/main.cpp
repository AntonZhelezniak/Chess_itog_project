#include"StartGame.h"

int main()
{
	
	int h = 0;
	do {
		cout << "1. New Game" << endl << "2. Load Game" << endl;
		cin >> h;
	} while (h != 1 && h != 2);
	
	if (h == 1)
	{
		StartGame New(1);
		try
		{
			New.Logic();
		}
		catch (string x)
		{
			cout << x << endl;
		}
	}
	else
	{
		/*StartGame New("x");
		try
		{
			New.load();
			New.Logic();
		}
		catch (string x)
		{
			cout << x << endl;
		}*/
	}
	
}