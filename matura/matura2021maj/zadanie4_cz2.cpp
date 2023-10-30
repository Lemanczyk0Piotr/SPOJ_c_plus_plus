#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	 ifstream dane("instrukcje.txt");
	 ofstream wyniki("wynik4.txt");
	 //4.1
	 string slowo;
	 int licznik=0;
	 char a;
	 for (int i=0; i<2000; i++)
	 {
				dane>>slowo>>a;
			 if (slowo=="DOPISZ")
						licznik++;
			 if (slowo=="USUN")
				licznik-=1;
	 }
	 wyniki<<"1. "<<licznik<<endl;
	 dane.close();

		//4.2
	 dane.open("instrukcje.txt");
	 licznik=0;
	 slowo="";
	 int maksLicznik=0;
	 string slowo1="";
	 string instrukcja;
	 for (int i=0; i<2000; i++)
	 {
			 dane>>slowo>>a;
			 if (slowo==slowo1)
				licznik++;
			 else if (licznik>maksLicznik)
			 {
						maksLicznik=licznik;
						instrukcja=slowo1;
						licznik=1;
			 }
				else licznik=1;
				slowo1=slowo;
	 }
	 wyniki<<"2. "<<instrukcja<<" "<<maksLicznik<<endl;
	 dane.close();

		//4.3
		dane.open("instrukcje.txt");
		int tab[30];
		for (int i=0; i<30; i++) tab[i]=0;
		for (int i=0; i<2000; i++)
		{
				dane>>slowo>>a;
				if (slowo=="DOPISZ") tab[a-65]++;
		}
		licznik=0;
		maksLicznik=0;
		for (int i=0; i<30; i++)
		{
				if (tab[i]>maksLicznik)
				{
						maksLicznik=tab[i];
						licznik=i;
				}
		}
		char b=licznik+65;
		wyniki<<"3. "<<b<<" "<<maksLicznik<< endl;
		dane.close();

		//4.4
		dane.open("instrukcje.txt");
		string odpowiedz = "";

		string instrukcjaa; char argument;
		while(dane >> instrukcjaa >> argument){
				if(instrukcjaa == "DOPISZ"){
						odpowiedz += argument;
				}else if(instrukcjaa == "USUN"){
						odpowiedz.pop_back();
				}else if(instrukcjaa == "ZMIEN"){
						odpowiedz.pop_back();
						odpowiedz += argument;
				}else if(instrukcjaa == "PRZESUN"){
						int idx = odpowiedz.find(argument);
						if(!idx && idx != 0)continue;
						int i = (int)argument;
						char a = (i==90 ? 65 : i+1);
						odpowiedz[idx] = a;
				}
		}

		wyniki << "4. " << odpowiedz;

		return 0;
}
