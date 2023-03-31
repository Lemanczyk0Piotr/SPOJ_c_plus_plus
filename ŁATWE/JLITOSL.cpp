#include <iostream>
#include <string>

using namespace std;

int main()
{
	string jednosci[10] =	{	"",
					"jeden",
					"dwa",
					"trzy",
					"cztery",
					"piec",
					"szesc",
					"siedem",
					"osiem",
					"dziewiec"
				};
	string dziesiatki[10] =	{	"",
					"",
					"dwadziescia",
					"trzydziesci",
					"czterdziesci",
					"piecdziesiat",
					"szescdziesiat",
					"siedemdziesiat",
					"osiemdziesiat",
					"dziewiecdziesiat"
				};
	string nastki[10] =	{	"dziesiec",
					"jedenascie",
					"dwanascie",
					"trzynascie",
					"czternascie",
					"pietnascie",
					"szesnascie",
					"siedemnascie",
					"osiemnascie",
					"dziewietnascie"
				};
	string setki[10] =	{	"",
					"sto",
					"dwiescie",
					"trzysta",
					"czterysta",
					"piecset",
					"szescset",
					"siedemset",
					"osiemset",
					"dziewiecset"
				};
	string skroty[5] =	{	"",
					"tys.",
					"mln.",
					"mld.",
					"bln.",
				};
	string liczba;
	int t, i, len, cyfra;

	cin >> t;

	while (t--)
	{
		cin >> liczba;
		len = liczba.length();

		for (i = 0; i < len; ++i)
		{
			if ((len - i) % 3 == 0 && i != 0)
				if (	((i>0)?liczba[i-1]:'0') != '0' ||
					((i>1)?liczba[i-2]:'0') != '0' ||
					((i>2)?liczba[i-3]:'0') != '0')
				{
					cout << ((i!=0 && (len-i)/3!=0)?" ":"");
					cout << skroty[(len - i) / 3];
				}

			switch ((len - i) % 3)
			{
			case 0:
				cout << ((i!=0 && liczba[i]-'0'!=0)?" ":"");
				cout << setki[liczba[i]-'0'];
				break;
			case 2:
				if (liczba[i] - '0' != 1)
				{
					cout << ((i!=0 && liczba[i]-'0'!=0 && liczba[i]-'0'!=1)?" ":"");
					cout << dziesiatki[liczba[i]-'0'];
				}
				else
					cout << ((i!=0)?" ":"") << nastki[liczba[i+1]-'0'];
				break;
			case 1:
				cout << ((i!=0 && liczba[i]-'0'!=0)?" ":"");
				cout << jednosci[liczba[i]-'0'];
				break;
			}

			if ((len - i) % 3 == 2 && liczba[i] == '1')
				++i;
		}

		cout << endl;
	}
	
	return 0;
}
