#include <iostream>

using namespace std;

int n;
int dp[1000];

void solve() {

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] = dp[i] % 10007;
	}

	cout << dp[n];

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	solve();

	return 0;
}