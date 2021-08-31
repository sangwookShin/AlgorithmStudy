#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];
int dp[1001];

void solve() {

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[i] < dp[j] + arr[i]) {
					dp[i] = dp[j] + arr[i];
				}
			}
		}
		result = max(result, dp[i]);
	}
	cout << result;
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}

	solve();

	return 0;
}