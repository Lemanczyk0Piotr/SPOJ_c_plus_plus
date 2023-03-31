#include <iostream>
#include <string>

using namespace std;

string tekst;
int dlugoscTekstu;

int main()
{
    while(getline(cin,tekst)) //wprowadznie naszego wyrażenia
    {
    dlugoscTekstu=tekst.length(); //sprawdzenie ilości wszystkich znaków w wyrażeniu

    for(int i=0;i<dlugoscTekstu;i++) //wykonywanie pętli tak dlugo az sprawdzimy wszystkie znaki (robione linijkje wyzej)
    {
        if(i==0)
        {
            tekst[0]=toupper(tekst[0]); //Zamiana pierwszej litery na duża (jezeli nie jest juz duza) ROBIMY TO TYLKO RAZ!!!!
        }
        else if(tekst[i]== ' ') //usuwanie spacji jako następy krok
            {
                if(i<dlugoscTekstu-1)
                {
                 tekst[i+1]=toupper(tekst[i+1]); //dodawanie duzych liter w srodku wyrazenia po spacji
                }
            }
        if(tekst[i]!= ' ') // jezeli w naszym wyrazeiu nie ma juz spacji mozemy je coutować
            cout << tekst[i]; 

    }
    cout << endl; //odstęp
    }


    return 0;
}
