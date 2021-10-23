#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    for (int i = 0; i < test_case; i++) {

        int n;
        cin >> n;

        map<string, int> m;

        for (int j = 0; j < n; j++) {

            string a, b;
            cin >> a >> b;

            if (m.find(b) == m.end()) {
                m[b] = 1;
            }
            else {
                m[b]++;
            }
        } //for

        int result = 1;

        for (auto it : m) {
            result = result * (it.second + 1);
        }
        cout << result - 1 << "\n";
    }

    return 0;
}