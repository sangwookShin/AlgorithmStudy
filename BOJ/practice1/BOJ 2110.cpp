#include <iostream>
#include <algorithm>

using namespace std;

int N, C;
long long x[200001];

bool possible(int dis) {

	int cnt = 1;
	int cur = x[0];

	for (int i = 1; i < N; i++) {

		if (x[i] - cur >= dis) {
			cnt++;
			cur = x[i];
		}

	}

	if (cnt >= C) {
		return true;
	}

	return false;

}

void solve() {

	long long low = 1;
	long long high = x[N - 1] - x[0];
	long long result = 0;

	while (low <= high) {

		long long mid = (low + high) / 2;

		if (possible(mid)) {
			result = max(result, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << result;
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}

	sort(x, x + N);

	solve();

	return 0;
}