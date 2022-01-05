#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    map<string, int> m;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        string t;
        int idx;
        for (int j = 0; j < tmp.size(); j++) {
            if (tmp[j] == '.') {
                idx = j + 1;
                break;
            }
        }
        t = tmp.substr(idx);
        m[t]++;
    }

    for (auto it : m) {
        cout << it.first << " " << it.second << "\n";
    }

    return 0;
}