#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[100001];

void solve() {

	int sum = 0;
	int result = -987654321;

	for (int i = 0; i < K; i++) {
		sum = sum + arr[i];
	}
	result = sum;
	for (int i = K; i < N; i++) {
		sum = sum + arr[i] - arr[i - K];
		result = max(sum, result);
	}

	cout << result;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	solve();

	return 0;
}