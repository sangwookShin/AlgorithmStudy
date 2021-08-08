#include <iostream>
#include <algorithm>

using namespace std;

int N;
int P[1001];

void solve() {

	int result = 0;

	sort(P, P + N);

	for (int i = 0; i < N; i++) {

		result = result + P[i] * (N - i);
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
		P[i] = t;
	}

	solve();

	return 0;
}