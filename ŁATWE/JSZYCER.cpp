#include <iostream>

using namespace std;

int main()
{
    string text;
    string alphabet ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    while(getline(cin, text))
    {
        for (int i=0; i<text.length(); i++)
        {
            for(int j=0; j<alphabet.length(); j++)
            {
                if(text[i]==' ')
                {
                    cout<<" ";
                    break;
                }
                else if(text[i] == alphabet[j])
                {
                    if(j>=23)
                    {
                        cout<<alphabet[0+(j-23)];
                        break;
                    }
                    else
                    {
                        cout<<alphabet[j+3];
                        break;
                    }
                }
            }
        }
    }
    
    return 0;
}
