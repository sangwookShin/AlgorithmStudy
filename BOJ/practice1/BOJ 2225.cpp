#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
long long dp[201][201];

void solve() {

	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] = dp[i][j] + dp[i - 1][k];
			}
			dp[i][j] = dp[i][j] % 1000000000;
		}

	}

	cout << dp[K][N];
}

int main() {

	cin >> N >> K;

	solve();

	return 0;
}