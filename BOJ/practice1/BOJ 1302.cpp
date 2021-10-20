#include <iostream>
#include <map>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int max = 0;
    map<string, int> m;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        m[tmp]++;
    }

    map<string, int>::iterator iter;

    for (iter = m.begin(); iter != m.end(); iter++) {
        if (max <= iter->second) {
            max = iter->second;
        }
    }

    for (iter = m.begin(); iter != m.end(); iter++) {
        if (max == iter->second) {
            cout << iter->first;
            return 0;
        }
    }

    return 0;
}