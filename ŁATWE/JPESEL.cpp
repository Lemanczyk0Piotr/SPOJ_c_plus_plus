#include <iostream>
#include <string>

using namespace std;

int main()
{
    int pesel[11];
    string stringPesel;
    int t;
    cin >> t;
    while(t--) //dodanie testow
    {
        cin >> stringPesel;
        
        for (int i=0; i<stringPesel.length(); i++) //dodowanie cyfr do tablicy w zaleznosci od dlugosci peselu
        {
            pesel[i]=stringPesel[i]; //dodanie cyfr do tablicy
        }
        
        int suma_peselu = pesel[0]*1 + pesel[1]*3 + pesel[2]*7 + pesel[3]*9 + pesel[4]*1 + pesel[5]*3 + pesel[6]*7 + pesel[7]*9 + pesel[8]*1 + pesel[9]*3 + pesel[10]*1; //rownanie do sprawdzenia poprawnosci peselu

        if(suma_peselu > 0)
        {
            if (suma_peselu % 10 == 0) //sprawdzenie czy na koncu peselu jest cyfra 0
            {
                cout << "D" << endl; //jezeli tak, pesel jest poprawny
            }
            else
            {
               cout << "N" << endl; //jesli jest cos innego nie jest poprawny (inne niz 0)
            }
        }
        else
        {
            cout << "N" << endl; //w kazdym innym przypadku pesel nie jest poprawny
        }
    }
    return 0;
}
