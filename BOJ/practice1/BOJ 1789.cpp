#include <iostream>
#include <algorithm>

using namespace std;

long long S;

void solve() {

    long long sum = 0;
    int i = 1;
    int cnt = 0;
    while (1) {

        sum = sum + i;
        i++;
        cnt++;
        if (sum > S) {
            cout << cnt - 1;
            break;
        }
    }
}

int main() {

    cin >> S;

    solve();

    return 0;
}