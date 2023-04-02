#include <iostream>

using namespace std;

int main()
{

    unsigned long ilosc_linii = 0;
    string z;

    while (getline(cin,z))
        ++ilosc_linii;

    cout << ilosc_linii;

    return 0;
}
