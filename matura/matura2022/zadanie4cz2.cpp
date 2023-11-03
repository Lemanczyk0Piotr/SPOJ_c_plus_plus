#include <iostream>
#include <fstream>
using namespace std;

bool czyPierwsza(int num) {
		if (num <= 1) return false;
		for (int i = 2; i * i <= num; i++) {
				if (num % i == 0) return false;
		}
		return true;
}

int main() {
		ifstream wejscie("liczby.txt");
		ofstream wyjscie("wyniki4.txt");

		int maksIloscCzynnikowPierwszych = 0, maksIloscRoznychCzynnikowPierwszych = 0, liczbaZMaksCzynnikamiPierwszymi = 0, liczbaZRoznymiCzynnikamiPierwszymi = 0, liczba1, pierwsza, ostatnia, licznik = 0, pierwszaWystapila = -1;

		// Zadanie 4.1
		while (wejscie >> liczba1) {
				pierwsza = liczba1;

				while (pierwsza >= 10) {
						pierwsza /= 10;
				}

				ostatnia = liczba1 % 10;

				if (pierwsza == ostatnia) {
						if (pierwszaWystapila == -1) {
								pierwszaWystapila = liczba1;
						}
						licznik++;
				}
				// Zadanie 4.2
				int num = liczba1;
				int iloscCzynnikowPierwszych = 0;
				int iloscRoznychCzynnikowPierwszych = 0;
				int poprzedniCzynnik = 0;

				for (int i = 2; i <= num; ++i) {
						while (num % i == 0 && czyPierwsza(i)) {
								iloscCzynnikowPierwszych++;
								num /= i;
								if (i != poprzedniCzynnik) {
										iloscRoznychCzynnikowPierwszych++;
										poprzedniCzynnik = i;
								}
						}
				}
				if (iloscCzynnikowPierwszych > maksIloscCzynnikowPierwszych) {
						maksIloscCzynnikowPierwszych = iloscCzynnikowPierwszych;
						liczbaZMaksCzynnikamiPierwszymi = liczba1;
				}

				if (iloscRoznychCzynnikowPierwszych > maksIloscRoznychCzynnikowPierwszych) {
						maksIloscRoznychCzynnikowPierwszych = iloscRoznychCzynnikowPierwszych;
						liczbaZRoznymiCzynnikamiPierwszymi = liczba1;
				}
		}
		wyjscie << "4.1. " << licznik << endl;
		wyjscie << "4.1. " << pierwszaWystapila << " (pierwsza spełniająca warunek)" << endl;
		wyjscie << "4.2. Najwięcej czynników pierwszych: " << liczbaZMaksCzynnikamiPierwszymi << " ("
						<< maksIloscCzynnikowPierwszych << " czynników pierwszych)" << endl;
		wyjscie << "4.2. Najwięcej różnych czynników pierwszych: " << liczbaZRoznymiCzynnikamiPierwszymi << " ("
						<< maksIloscRoznychCzynnikowPierwszych << " różnych czynników pierwszych)" << endl;
		wejscie.close();
		wyjscie.close();

		return 0;
}
