#include <iostream>

using namespace std;

//!!!! NIE DZIAŁA OSTATNI TEST 4 0 0 0 0

int main()
{
    int t;
    cin>>t;
    while(t--) //testy
    {
        int i, dni=-1, tab[i], x;
        cin>>i; //liczba segmentow
			
        for(int j=0;j<i;j++){
            cin>>x; //liczba nozek wystających z segmentow
            tab[j]=x;
        }
      
        dni+=i;

        for(int j=0;j<i;j++){
					dni+=tab[j];
				}
        cout<<dni<<endl;
    }
    return 0;
}
