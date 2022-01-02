#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool check[101];
string s;

void solve(int l, int r) {

    int m = 987;
    int idx = -1;

    for (int i = l; i < r + 1; i++) {
        if (!check[i] && m > s[i]) {
            m = s[i];
            idx = i;
        }
    }

    if (m == 987) {
        return;
    }

    check[idx] = true;

    for (int i = 0; s[i]; i++) {
        if (check[i]) {
            cout << s[i];
        }
    }

    cout << "\n";

    solve(idx + 1, r);
    solve(l, idx - 1);

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    solve(0, s.size() - 1);

    return 0;
}