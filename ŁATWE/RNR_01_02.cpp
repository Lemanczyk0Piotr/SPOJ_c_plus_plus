#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(string s) {
    return equal(s.begin(), s.end(), s.rbegin());
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool found = false;
        for (int i = 0; i <= s.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                string s2 = s;
                s2.insert(i, 1, c);
                if (is_palindrome(s2)) {
                    cout << s2 << endl;
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (!found) {
            cout << "NIE" << endl;
        }
    }
    return 0;
}
