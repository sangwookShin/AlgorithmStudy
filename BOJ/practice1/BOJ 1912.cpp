#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];
int N;

void solve() {

	int result;
	int b[100001];

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		a[i] = t;
	}

	result = a[0];
	b[0] = a[0];

	for (int i = 1; i < N; i++) {
		b[i] = max(b[i - 1] + a[i], a[i]);
		result = max(result, b[i]);
	}

	cout << result;
}

int main() {

	cin >> N;
	solve();

	return 0;
}