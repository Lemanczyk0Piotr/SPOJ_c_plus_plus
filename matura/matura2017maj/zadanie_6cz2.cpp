#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream plik("dane.txt");
		ofstream plikWyniki("wyniki_6.txt");
		

    // 6.1
    int min_val = 256;
    int max_val = 0;
    int zmienna;

    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 320; j++) {
            plik >> zmienna;
            if (zmienna > max_val) max_val = zmienna;
            if (zmienna < min_val) min_val = zmienna;
        }
    }

    cout << "6.1 Min: " << min_val << " ,Max: " << max_val << endl;
		plikWyniki << min_val << " " << max_val << endl;

    // 6.2
    ifstream plik2("dane.txt");
    int tablica[200][320];

    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 320; j++) {
            plik2 >> tablica[i][j];
        }
    }

    int ilesymetria = 0;

    for (int i = 0; i < 200; i++) {
        bool symetria = true;
        for (int j = 0; j < 160; j++) {
            int k = 320 - 1 - j;
            if (tablica[i][j] != tablica[i][k]) {
                symetria = false;
                break;
            }
        }
        if (!symetria) ilesymetria++;
    }

    cout << "6.2 Należy usunąć " << ilesymetria << " wierszy." << endl;
		plikWyniki << ilesymetria << endl;

    // 6.3
    int ilekontrastujacych = 0;

    for (int i = 0; i < 200; i++) {
        for (int j = 0; j < 320; j++) {
            int kontrastujacy = 0;
            int roznica;

            // Czy lewy
            if (j > 0) {
                roznica = abs(tablica[i][j] - tablica[i][j - 1]);
                if (roznica > 128) kontrastujacy = 1;
            }
            // Czy prawy
            if (j < 319) {
                roznica = abs(tablica[i][j] - tablica[i][j + 1]);
                if (roznica > 128) kontrastujacy = 1;
            }
            // Czy góra
            if (i > 0) {
                roznica = abs(tablica[i][j] - tablica[i - 1][j]);
                if (roznica > 128) kontrastujacy = 1;
            }
            // Czy dół
            if (i < 199) {
                roznica = abs(tablica[i][j] - tablica[i + 1][j]);
                if (roznica > 128) kontrastujacy = 1;
            }

            if (kontrastujacy == 1) ilekontrastujacych++;
        }
    }

    cout << "6.3 Ilość pikseli kontrastujących: " << ilekontrastujacych << endl;
		plikWyniki << ilekontrastujacych << endl;

    // 6.4
    int najdluzszy = 1;
    int najdluzszytmp = 1;

    for (int j = 0; j < 320; j++) {
        int poprzedni = tablica[0][j];
        najdluzszytmp = 1;

        for (int i = 1; i < 200; i++) {
            if (tablica[i][j] == poprzedni) {
                najdluzszytmp++;
            } else {
                if (najdluzszytmp > najdluzszy) najdluzszy = najdluzszytmp;
                najdluzszytmp = 1;
            }
            poprzedni = tablica[i][j];
        }

        if (najdluzszytmp > najdluzszy) najdluzszy = najdluzszytmp;
    }

    cout << "6.4 Najdłuższy ciąg: " << najdluzszy << endl;
		plikWyniki << najdluzszy << endl;

		plikWyniki.close();
	  plik.close();

    return 0;
}
