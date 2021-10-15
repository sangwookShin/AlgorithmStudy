#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
void solve() {

    int tmp = 1;
    int cnt = 1;
    int sum = 1;

    while (1) {

        if (sum >= N) {
            break;
        }
        tmp = 6 * cnt;
        cnt++;
        sum += tmp;
    }

    cout << cnt;
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    solve();

    return 0;
}