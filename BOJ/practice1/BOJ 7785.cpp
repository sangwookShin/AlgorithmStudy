#include <iostream>
#include <map>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    map<string, string, greater<>> m;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string name, status;
        cin >> name >> status;

        m[name] = status;
    }

    map<string, string>::iterator iter;

    for (iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == "enter") {
            cout << iter->first << "\n";
        }
    }

    return 0;
}