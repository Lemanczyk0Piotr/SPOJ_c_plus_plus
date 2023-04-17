#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int w, z, t, x, y, r = 0;
    cin >> w >> z;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        double t = sqrt(pow(x - w, 2) + pow(y - 0, 2));
        if (t > z)
        {
            r++;
        }
    }
    cout << r << endl;
    return 0;
}
