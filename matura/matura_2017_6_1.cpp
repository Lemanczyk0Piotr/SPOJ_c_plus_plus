#include <iostream>
#include <fstream>


using namespace std;

int main() {

	ifstream dane("dane.txt");
	ofstream wynik6("wynik_6.txt");

	int max=dane.peek(), min=dane.peek();

	while(!dane.eof()){

		int tmp;

		for(int i=0; i < 320; i++)
			{
				dane >> tmp;

				if (tmp < min)
				{
					min = tmp;
				}
				if (tmp > max)
				{
					max = tmp;
				}
			}
			
		
		}
	wynik6 << min << " " << max << endl;
}
