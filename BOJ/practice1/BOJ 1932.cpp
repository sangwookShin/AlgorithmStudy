#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[501][501];
int result;

void solve() {

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i][j] + dp[i - 1][0];
			}
			else if (j == i) {
				dp[i][j] = dp[i][j] + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = dp[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}

			result = max(result, dp[i][j]);

		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int t;
			cin >> t;
			dp[i][j] = t;
		}
	}

	solve();

	cout << result;

	return 0;
}