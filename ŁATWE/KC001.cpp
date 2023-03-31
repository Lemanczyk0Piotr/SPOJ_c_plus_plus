#include <iostream>

using namespace std;

int main ()
{
	int a, b, c;
	cin>>a;
	cout<<endl;
	cin>>b;
	cout<<endl;
	cin>>c;
	cout<<endl;

	if (a > 100 || b > 100 || c > 100){
		cout << "Podales za duza liczbe" << endl;
	}
	else
	cout << (a+b+c) << endl;
	
  return 0;
}
