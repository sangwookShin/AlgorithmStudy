#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;

void solve() {

    string s;
    string result;

    cin >> s;

    int cnt = 0;

    do {
        cnt++;
        result = s;
        if (cnt == 2) {
            break;
        }


    } while (next_permutation(s.begin(), s.end()));

    cout << result << "\n";
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        solve();
    }

    return 0;
}