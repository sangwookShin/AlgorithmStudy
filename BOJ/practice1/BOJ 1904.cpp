#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int dp[1000000];

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] = dp[i] % 15746;
    }

    cout << dp[N];

    return 0;

}