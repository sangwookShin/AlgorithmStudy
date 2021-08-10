#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<int> v;

void solve() {

	int cnt = 0;

	for (int i = v.size() - 1; i >= 0; i--) {

		int s;

		if (K < v[i]) {
			continue;
		}

		s = K / v[i];
		cnt = cnt + s;
		K = K - s * v[i];

		if (K == 0) {
			cout << cnt;
			return;
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	solve();

	return 0;
}