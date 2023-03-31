#include <iostream> 

 using namespace std; 

 float a,b,c; 

 int main() 
 { 
    while(cin>>a>>b>>c) 
     { 
         if(a+b>c&&b+c>a&&c+a>b) cout << "1"<< endl; 
         else cout << "0" << endl; 

     } 
     return 0; 
 }
