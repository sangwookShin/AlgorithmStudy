#include <iostream>
#include <algorithm>

using namespace std;

long long N, M;
long long trees[1000001];

void solve() {

	sort(trees, trees + N);

	long long left = 0;
	long long right = trees[N - 1];
	long long mid = (left + right) / 2;
	long long result = 0;

	while (left <= right) {

		mid = (left + right) / 2;
		long long sum = 0;

		for (int i = 0; i < N; i++) {
			if (mid < trees[i]) {
				sum = sum + trees[i] - mid;
			}
		}

		if (sum >= M) {
			if (result < mid) {
				result = mid;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << result;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> trees[i];
	}

	solve();

	return 0;
}