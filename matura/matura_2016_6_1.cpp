// MATURA2016_6.1_6.2_6.3.cpp : Ten plik zawiera funkcję „main”. W nim
// rozpoczyna się i kończy wykonywanie programu.
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string tekst;
  string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ifstream odczyt("dane_6_1.txt");
  ofstream zapis("wynik_6_1.txt");

  int key = 107;

  while (!odczyt.eof()) {
    odczyt >> tekst;
    int pos = 0;
    int base = 0;

    for (int i = 0; i < tekst.length(); i++) {
      for (int a = 0; a < alpha.length(); a++) {
        if (tekst[i] == alpha[a]) {
          pos = a;
          break;
        }
      }

      base = key % 26;

      if (pos + base > alpha.length()) {
        tekst[i] = alpha[pos + base - alpha.length()];
      } else {
        tekst[i] = alpha[pos + base];
      }
    }

    zapis << tekst << endl;
  }
}
