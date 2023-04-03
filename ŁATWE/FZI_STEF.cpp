#include <iostream>

using namespace std;
  
int main() {
    int miasta, kaska;
    long long suma=0, maks=0; 
    cin >> miasta; 
	
    while (miasta--)
    {
            cin >> kaska;
  
            suma+=kaska; 
  
            if (suma>maks)
	    {
                maks=suma; 
            }
            if (suma<0) 
	    {
                suma=0; 
            }
    }
  
        cout << maks << endl; 
  
    return 0;
  
}
