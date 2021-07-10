#include <iostream>
#include <algorithm>

using namespace std;

long long dp[101];
int a[100];
void solve() {

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;

	for (int i = 5; i < 101; i++) {
		dp[i] = dp[i - 2] + dp[i - 3];
	}

}

int main() {

	int T;

	cin >> T;

	solve();

	for (int i = 0; i < T; i++) {
		int b;
		cin >> b;
		a[i] = b;
	}

	for (int i = 0; i < T; i++) {
		cout << dp[a[i]] << endl;
	}

	return 0;
}