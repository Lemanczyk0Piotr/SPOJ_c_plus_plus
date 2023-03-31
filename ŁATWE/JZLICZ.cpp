#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int znaki[256];

void liczenie(string napis) //liczenie ilosci liter w danym slowie
{
    for(int i=0; i<napis.length(); i++) //tyle razy wykonana ile ma liter dane slowo
    {
        if(napis[i] != ' ') //do tablicy dodajemy tylko litery, bez spacji
        {
            znaki[int(napis[i])]++; //dodanie do tablicy
        }
    }
}

int main()
{
    int T;
    cin>>T;
    for (int i; i <= T; i++)
    {
        string napis;
        getline(cin,napis);
        liczenie(napis);
    }
    
    cout << endl; // kod odnajduje litery i przypisuje je do numeracji ASCII, potem patrzy ile razy mu sie to powtorzyle (ile razy musiala przejsc petla)
    
     for(int i=97; i<=122; i++) //assci duze litry
    {
        if(znaki[i] != 0)
        {
            cout<<char(i)<<" "<<znaki[i]<<'\n'; // rzutowanie na char liter
        }
    }
    for(int i=65; i<=90; i++) //asscii male  litery
    {
        if(znaki[i] != 0)
        {
            cout<<char(i)<<" "<<znaki[i]<<'\n'; // rzutowanie na char liter
        }
    }
    return 0;
}
