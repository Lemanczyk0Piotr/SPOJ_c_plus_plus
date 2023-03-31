#include <iostream>

using namespace std;
  
int main() {
    int miasta, kaska;
    long long suma=0, maks=0; //long long - nie wiemy ile mozna zarobic nawet po kilkadziesiąt miliardów, int by miał za malo znków
	
    cin >> miasta; // wprowadzamy ilość miast
	
    while (miasta--) //odejmujemy jeden po kazdym przejsciu calej pętli az dojdzie do 0
    {
            cin >> kaska; //ile zarobi na jednym
  
            suma+=kaska; // to samo co suma = suma + kaska
  
            if (suma>maks) // wszystko jasne po dodaniu 
	    {
                maks=suma; // jezeli jest suma wieksza to przypisujemy bo pewnie bedzie to maks nasza wartość
            }
            if (suma<0) // wszystko jasne xd bo zarobek chyba nie moze byc ujemny
	    {
                suma=0; // wszystko jasne, w sensie moze byc ujemny ale nie ma takije mozliwosci w zadaniu, w jedmyn przykladiz jest ze jak masz mniej niz 0 to ma zawsze wyswitlic 0
            }
    }
  
        cout << maks << endl; //wyjscie danych
  
    return 0;
  
}
