#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long dp[1001];
void solve() {

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i < 1001; i++) {
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}

	cout << dp[n];

}

int main() {

	cin >> n;

	solve();

	return 0;
}