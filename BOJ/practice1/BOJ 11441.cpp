#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int arr[100001];
    int dp[100001];
    int sum = 0;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sum = sum + arr[i];
        dp[i] = sum;
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        if (a == b) {
            cout << arr[a] << "\n";
        }
        else {
            cout << dp[b] - dp[a - 1] << "\n";
        }
    }

    return 0;
}