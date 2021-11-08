#include <iostream>
#include <algorithm>

using namespace std;

int dp[12];

void solve() {

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 7;

    for (int i = 5; i <= 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;

    cin >> T;

    solve();

    for (int i = 0; i < T; i++) {
        int a;
        cin >> a;
        cout << dp[a] << "\n";
    }

    return 0;
}