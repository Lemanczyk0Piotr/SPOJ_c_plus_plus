#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_nondecreasing_subsequence(vector<int> seq) {
    vector<int> ends;
    for (int i = 0; i < seq.size(); i++) {
        int j = upper_bound(ends.begin(), ends.end(), seq[i]) - ends.begin();
        if (j < ends.size()) {
            ends[j] = seq[i];
        }
        else {
            ends.push_back(seq[i]);
        }
    }
    return ends.size();
}

int main() {
    int n;
    cin >> n;

    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    int result = longest_nondecreasing_subsequence(seq);
    cout << result << endl;

    return 0;
}
