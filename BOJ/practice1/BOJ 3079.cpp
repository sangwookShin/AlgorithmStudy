#include <iostream>
#include <algorithm>

using namespace std;

long long N, M;
long long T[100001];

void solve() {

	long long low = 0;
	long long high = M * T[N - 1];
	long long result = high;

	while (low <= high) {

		long long mid = (low + high) / 2;
		long long sum = 0;

		for (int i = 0; i < N; i++) {
			sum = sum + mid / T[i];
		}

		if (sum >= M) {
			result = min(result, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}

	}
	cout << result;
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> T[i];
	}

	sort(T, T + N);

	solve();

	return 0;
}