#include <iostream>

using namespace std;

int main()
{
	int liczba = 0, wyraz = 0;
	char wyrazenie;
	bool jezeliwyraz = false;

	while(cin.get(wyrazenie))
	{
		if (wyrazenie == ' ' || wyrazenie == '\n')
		{
			if (jezeliwyraz)
				++wyraz;
			else
			    	++liczba;

			if (wyrazenie == '\n')
			{
				cout << liczba << " " << wyraz << endl;
				liczba = wyraz = 0;
			}
			jezeliwyraz = false;
		}
		else if (wyrazenie < '0' || wyrazenie > '9')
			jezeliwyraz = true;
	}

	return 0;
}
