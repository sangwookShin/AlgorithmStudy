#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int T;

void solve(string tmp) {

    stack<char> s;
    bool check = true;

    for (int i = 0; i < tmp.size(); i++) {

        if (tmp[i] == '(') {
            s.push('(');
        }
        else {
            if (!s.empty()) {
                s.pop();
            }
            else {
                cout << "NO" << "\n";
                return;
            }
        }
    }

    if (s.empty()) {
        cout << "YES" << "\n";
        return;
    }

    cout << "NO" << "\n";
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        string tmp = "";
        cin >> tmp;
        solve(tmp);
    }

    return 0;
}