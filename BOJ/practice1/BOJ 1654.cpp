#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long long K, N;
long long lan[10001];

void solve() {

	long long H;
	long long L = 1;
	long long mid;
	long long result = 0;
	long long cnt;

	sort(lan, lan + K);

	H = lan[K - 1];

	while (L <= H) {

		mid = (L + H) / 2;
		cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt = cnt + lan[i] / mid;
		}
		if (cnt < N) {
			H = mid - 1;
		}
		else {
			L = mid + 1;
			result = max(result, mid);
		}
	}
	cout << result;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> lan[i];
	}

	solve();

	return 0;
}