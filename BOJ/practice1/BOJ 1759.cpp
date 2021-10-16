#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;
vector<char> v;

void DFS(int pos, string s, int ja, int mo) {

    if (s.size() == L) {
        if (ja >= 2 && mo >= 1) {
            cout << s << "\n";
        }
        return;
    }

    for (int i = pos; i < C; i++) {

        if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
            DFS(i + 1, s + v[i], ja, mo + 1);
        }
        else {
            DFS(i + 1, s + v[i], ja + 1, mo);
        }
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        char c;
        cin >> c;
        v.push_back(c);
    }

    sort(v.begin(), v.end());

    DFS(0, "", 0, 0);

    return 0;
}