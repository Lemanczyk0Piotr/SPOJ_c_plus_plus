#include <iostream>
#include <fstream>

using namespace std;

int main() {
  
    string zmienna, zmiana;
    char litera, litera2;
    int dlugosc, numer;

    ifstream plik3("dane_6_3.txt");
		ofstream plik3wynik("wynik_6_3.txt");
    string slowo1, slowo2;
    int roznica, roznicatmp, identyczne, numer2;
    
  for(int i=0; i<3000;i++){
    plik3 >> slowo1;
    plik3 >> slowo2;
    dlugosc = slowo1.size();
    
    for(int j=0; j<dlugosc; j++){
        
    litera = slowo1[j];
    litera2 = slowo2[j];
    numer = (int)litera;
    numer2 = (int)litera2;
    roznicatmp = numer2 - numer;
    if(roznicatmp < 0) roznicatmp += 26;
    if(j==0){
            identyczne = 1;
            roznica = roznicatmp;
    }else{
      if(roznicatmp != roznica) identyczne = 0;
    }
  }
  if(identyczne == 0) plik3wynik<<slowo1<<endl;
  }
  return 0;
}
