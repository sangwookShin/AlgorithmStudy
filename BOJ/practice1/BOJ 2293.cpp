#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;

    cin >> n >> k;

    int dp[10001] = { 0, };
    int arr[101];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - arr[i]];
        }
    }

    cout << dp[k];

    return 0;

}