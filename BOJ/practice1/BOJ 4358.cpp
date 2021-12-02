#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> m;
    string wood;
    double cnt = 0;

    while (getline(cin, wood)) {

        cnt++;

        if (m.find(wood) != m.end()) {
            m[wood]++;
        }
        else {
            m[wood] = 1;
        }
    } //while

    cout << fixed;
    cout.precision(4);

    for (auto it = m.begin(); it != m.end(); it++) {
        double result = (it->second / cnt) * 100;
        cout << it->first << " ";
        cout << result << "\n";
    }


    return 0;

}