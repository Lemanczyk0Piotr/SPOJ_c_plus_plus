#include <iostream>

using namespace std;

int main()
{
	long long num, koncowy= 0, posredni = 0;
	while (cin >> num)
	{
		
		if (num == 0)
		{
			cout << posredni << endl;
			koncowy += posredni;
			posredni = 0;
		}
		else
		{
			posredni += num;
		}
	}
	cout << koncowy << endl;
	return 0;
}
