#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1010];

void solve() {

    int dp[1010];

    if (N == 1) {
        cout << 0;
        return;
    }

    for (int i = 0; i < N; i++) {
        dp[i] = 987654321;
    }

    dp[0] = 0;
    int tmp = 987654321;

    for (int i = 0; i < N; i++) {
        int num = arr[i];
        for (int j = i + 1; j <= i + num; j++) {
            if (j >= N - 1) {
                tmp = min(tmp, dp[i] + 1);
            }
            else {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
    }

    if (tmp == 987654321) {
        cout << -1;
    }
    else {
        cout << tmp;
    }

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    solve();

    return 0;
}