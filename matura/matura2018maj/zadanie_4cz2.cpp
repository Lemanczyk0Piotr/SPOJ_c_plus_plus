#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Funkcja znajdująca słowo z największą liczbą różnych liter
pair<string, int> znajdzNajwiekszaLiczbeRoznychLiter(string slowa[], int iloscSlow) {
    int maksLiczbaLiter = 0;
    string slowoZNajwiekszaLiczbaLiter = "";

    for (int i = 0; i < iloscSlow; ++i) {
        string slowo = slowa[i];

        int liczbaRoznychLiter = 0;
        bool wystapila[26] = {false};

        for (char litera : slowo) {
            if (isupper(litera) && !wystapila[litera - 'A']) {
                wystapila[litera - 'A'] = true;
                liczbaRoznychLiter++;
            }
        }

        if (liczbaRoznychLiter > maksLiczbaLiter) {
            maksLiczbaLiter = liczbaRoznychLiter;
            slowoZNajwiekszaLiczbaLiter = slowo;
        }
    }

    return make_pair(slowoZNajwiekszaLiczbaLiter, maksLiczbaLiter);
}

// Funkcja sprawdzająca, czy każde dwie litery w słowie są oddalone o co najwyżej 10 miejsc w alfabecie
bool czySpelniaWarunek(const string& slowo) {
    int dlugosc = slowo.length();
    for (int i = 0; i < dlugosc; ++i) {
        for (int j = i + 1; j < dlugosc; ++j) {
            if (abs(slowo[i] - slowo[j]) > 10) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ifstream plik("sygnaly.txt");
    ofstream wynikiFile("wyniki4.txt");

    string slowa[1000];
		int iloscSlow = 0;

    while (iloscSlow < 1000 && plik >> slowa[iloscSlow]) {
        iloscSlow++;
    }

    // Znajdź słowo z największą liczbą różnych liter
    pair<string, int> wynik = znajdzNajwiekszaLiczbeRoznychLiter(slowa, iloscSlow);

    wynikiFile << "1. " << wynik.first << " " << wynik.second << endl;

    wynikiFile << "Słowa spełniające warunek (oddalone o co najwyżej 10 miejsc w alfabecie):" << endl;

    // Sprawdź i wypisz słowa spełniające warunek
    for (int i = 0; i < iloscSlow; ++i) {
        if (czySpelniaWarunek(slowa[i])) {
            wynikiFile << slowa[i] << endl;
        }
    }

    plik.close();
    wynikiFile.close();

    return 0;
}
