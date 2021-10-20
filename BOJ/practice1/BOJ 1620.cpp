#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int N, M;
map<string, int> m;
vector<string> v;
string s[100001];

void solve() {

    for (int i = 0; i < v.size(); i++) {
        if ('0' <= v[i][0] && v[i][0] <= '9') { //숫자로 주어짐
            int n = stoi(v[i]);
            cout << s[n] << "\n";
        }
        else { //이름으로 주어짐
            cout << m[v[i]] << "\n";
        }
    }

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string tmp;
        cin >> tmp;
        m.insert({ tmp, i });
        s[i] = tmp;
    }

    for (int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    solve();

    return 0;
}