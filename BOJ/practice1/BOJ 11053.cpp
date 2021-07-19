#include <iostream>

using namespace std;

int N;
int A[1000];
int dp[1000] = { 1, };

void solve() {

	for (int i = 1; i < N; i++) {
		int min = 0;

		for (int j = 0; j < i; j++) {
			if (A[i] > A[j] && min <= dp[j]) {
				min = dp[j];
			}
		}
		dp[i] = min + 1;

	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		if (result < dp[i]) {
			result = dp[i];
		}
	}

	cout << result;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		A[i] = t;
	}

	solve();

	return 0;
}