#include <iostream>

using namespace std;


int main() 
{
	int ileliczb, przesuniecie;
        cout << "Podaj liczbe cyfr" << endl;
	cin >> ileliczb;
	cout << "Podaj przesunięcie" << endl;
	cin >> przesuniecie;
	cout << endl;
	cout << "Podaj liczby" << endl; //zaaplikowanie danych do programu 

	int tab[ileliczb];

	for (int i=0; i < ileliczb; i++)
		{
			cin >> tab[i]; //dodanie liczb do przesunięcia do tablicy
		}
	for (int i=przesuniecie; i < ileliczb; i++)
		{
			cout << tab[i]<<" "; //przesuniecie liczb z konca tablicy na jej poczatek
		}
	for (int i=0; i < przesuniecie ; i++)
		{
			cout << tab[i]<<" "; //przesuniecie liczb z poczatku tablicy na koniec
		}

	return 0;
	
}
