#include <iostream>

using namespace std;

int main()
{
	int szukana = 0, dlugosc = 0;
	while (cin >> szukana >> dlugosc)
	{
		int ile_razy = 0;
		for (int i = 0; i < dlugosc; i++)
		{
			int a;
			cin >> a;
			if (a == szukana) ile_razy++;
		}
		cout << ile_razy << endl;
		ile_razy = 0;
	}
    return 0;
}
