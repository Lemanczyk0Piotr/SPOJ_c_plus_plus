#include <iostream>
#include<string>

using namespace std;

int main()
{

    string wyraz;
    
    int dlugosc=wyraz.length();

    while (cin>>wyraz)
    {

        for (int i = 0; i < wyraz.length(); i++)
        {
            cout << wyraz[wyraz.length() - (i + 1)];
        }

        cout << endl;
    }

    return 0;
}
