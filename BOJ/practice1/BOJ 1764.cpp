#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, M, cnt = 0;
set<string> a;
set<string> result;

void solve() {

    for (int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;
        if (a.find(tmp) != a.end()) {
            result.insert(tmp);
            cnt++;
        }
    }

    cout << cnt << "\n";

    for (string s : result) {
        cout << s << "\n";
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        a.insert(tmp);
    }

    solve();

    return 0;
}