#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		const int wielkosc = 110;
		int tablica[4][wielkosc];

		int ilosc_kolun;
		int ilosc_wierszy;

		cin >> ilosc_wierszy >> ilosc_kolun;
		
		int w = 0;
		while (w<ilosc_wierszy)
		{
			for (int k = 0; k < ilosc_kolun; k++)
			{
				if (w == 0)
				{
					if (k == 0)
						cin >> tablica[w + 1][k];

					if (k>0)
						cin >> tablica[w][k - 1];
				}

				if (w == 1)
				{
					if (k == 0)
						cin >> tablica[w + 1][k];

					if (k>0 && k<ilosc_kolun - 1)
						cin >> tablica[w][k];

					if (k == ilosc_kolun - 1)
						cin >> tablica[w - 1][ilosc_kolun - 1];
				}

				if (w == 2)
				{
					if (k >= 0 && k<ilosc_kolun - 1)
						cin >> tablica[w][k + 1];

					if (k == ilosc_kolun - 1)
						cin >> tablica[w - 1][k];
				}
			}
			w++;
		}

		w = 0;
		cout << endl;
		while (w<ilosc_wierszy)
		{
			for (int k = 0; k < ilosc_kolun; k++)
			{
				cout << tablica[w][k];
				if (k<ilosc_kolun)
					cout << " ";
			}
			w++;
			cout << endl;
		}
	}
	return 0;
}
