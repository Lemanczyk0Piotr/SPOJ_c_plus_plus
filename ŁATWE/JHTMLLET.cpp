#include <iostream>
using namespace std;

int main()
{
    string tekst; //zmienna tesktowa
    bool big=false; //zmienna bez wartosci, moze byc tylko prawdziwa lub falszywa
    while(getline(cin,tekst))
    {
        for(int i=0;i<tekst.length();i++) //przejscie tyle razy pętli ile znaków miało nasze wprowadzone wyrażenie
        {
            if(tekst[i]=='<') //chcemy zmieniac litery tylko miedzy znakami < i >
            big=true;
            else
            if(tekst[i]=='>')  //chcemy zmieniac litery tylko miedzy znakami < i >
            big=false;
            else
            if(big)
            {
                if(tekst[i]>=97) //zmiena liter na podstawie numeracji ascii
                {
                    tekst[i]=tekst[i]-32; //zmiena o odpowiednio 32 miesjca, taka jest roznica w tabeli ascci miedzy duzymi a malymi literami
                }
            }
        }
        cout<<tekst<<endl; //wyjscie danych
    }
    return 0;
}
