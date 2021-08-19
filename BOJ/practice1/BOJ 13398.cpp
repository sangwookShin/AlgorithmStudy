#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100001];
int dp[100001][2]; //0 삭제 / 1 삭제x

void solve() {

	int result = a[0];
	dp[0][0] = a[0];
	dp[0][1] = a[0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0] + a[i], a[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + a[i]);
		result = max(result, max(dp[i][0], dp[i][1]));
	}

	cout << result;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	solve();

	return 0;
}