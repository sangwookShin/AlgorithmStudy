#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long M;
long long money[10001];

void solve() {

	long long low = 0;
	long long high;

	sort(money, money + N);

	high = money[N - 1];

	while (low <= high) {

		long long mid = (low + high) / 2;
		long long sum = 0;

		for (int i = 0; i < N; i++) {
			sum = sum + min(mid, money[i]);
		}

		if (sum <= M) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}

	}
	cout << low - 1;
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> money[i];
	}

	cin >> M;

	solve();

	return 0;
}