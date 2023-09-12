#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Funkcja do odszyfrowania szyfrogramu przy użyciu klucza
string odszyfrujSzyfrogram(const string& szyfrogram, int klucz) {
    string odszyfrowaneSlowo = szyfrogram;

    for (char &c : odszyfrowaneSlowo) {
        if (isalpha(c)) {
            c -= klucz % 26;
            if (c < 'A') {
                c += 26;
            }
        }
    }

    return odszyfrowaneSlowo;
}

int main() {
    ifstream plikDane("dane_6_2.txt");
    ofstream plikWyniki("wyniki_6_2.txt");

    string szyfrogram;
    int klucz;

    while (plikDane >> szyfrogram >> klucz) {
        string odszyfrowaneSłowo = odszyfrujSzyfrogram(szyfrogram, klucz);
        plikWyniki << odszyfrowaneSłowo << endl;
    }

    plikDane.close();
    plikWyniki.close();

    cout << "Odszyfrowane słowa zapisano do pliku wyniki_6_2.txt." << endl;

    return 0;
}
