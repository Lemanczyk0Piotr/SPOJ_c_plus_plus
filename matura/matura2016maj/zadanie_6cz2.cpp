#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Funkcja do szyfrowania tekstu
string szyfrujTekst(const string& tekst, int klucz) {
    string zaszyfrowanyTekst = tekst;

    for (char &c : zaszyfrowanyTekst) {
        if (isalpha(c)) {
            int pos = alpha.find(c);
            int base = klucz % 26;

            if (pos != string::npos) {
                pos = (pos + base) % alpha.length();
                c = alpha[pos];
            }
        }
    }

    return zaszyfrowanyTekst;
}

// Funkcja do odszyfrowania szyfrogramu
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
    // Pierwszy kod
    ifstream odczyt1("dane_6_1.txt");
    ofstream zapis1("wynik_6_1.txt");
    int key1 = 107;

    while (!odczyt1.eof()) {
        string tekst;
        odczyt1 >> tekst;
        string zaszyfrowanyTekst = szyfrujTekst(tekst, key1);
        zapis1 << zaszyfrowanyTekst << endl;
    }
    odczyt1.close();
    zapis1.close();

    // Drugi kod
    ifstream plikDane2("dane_6_2.txt");
    ofstream plikWyniki2("wyniki_6_2.txt");

    while (plikDane2 >> szyfrogram >> klucz) {
        string odszyfrowaneSłowo = odszyfrujSzyfrogram(szyfrogram, klucz);
        plikWyniki2 << odszyfrowaneSłowo << endl;
    }
    plikDane2.close();
    plikWyniki2.close();

    // Trzeci kod
    ifstream plik3("dane_6_3.txt");
    ofstream plik3wynik("wynik_6_3.txt");
    
    for (int i = 0; i < 3000; i++) {
        string slowo1, slowo2;
        plik3 >> slowo1;
        plik3 >> slowo2;
        int dlugosc = slowo1.size();
        int roznica, roznicatmp, identyczne, numer, numer2;
    
        for (int j = 0; j < dlugosc; j++) {
            char litera = slowo1[j];
            char litera2 = slowo2[j];
            numer = (int)litera;
            numer2 = (int)litera2;
            roznicatmp = numer2 - numer;
            
            if (roznicatmp < 0) roznicatmp += 26;
            
            if (j == 0) {
                identyczne = 1;
                roznica = roznicatmp;
            } else {
                if (roznicatmp != roznica) identyczne = 0;
            }
        }
        
        if (identyczne == 0) plik3wynik << slowo1 << endl;
    }
    plik3.close();
    plik3wynik.close();

    cout << "Operacje zakończone." << endl;

    return 0;
}
