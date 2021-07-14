#include <iostream>
#include <algorithm>

using namespace std;

int m[100][100];
long long dp[100][100] = { 0, };
int N;

void solve() {

	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (dp[i][j] == 0 || (i == N - 1 && j == N - 1)) {
				continue;
			}

			int d = m[i][j];
			int right = d + j;
			int down = d + i;

			if (down < N) {
				dp[down][j] = dp[down][j] + dp[i][j];
			}
			if (right < N) {
				dp[i][right] = dp[i][right] + dp[i][j];
			}
		}
	}

	cout << dp[N - 1][N - 1];
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			m[i][j] = a;
		}
	}

	solve();

	return 0;
}