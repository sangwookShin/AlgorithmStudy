#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int a[100001];
int result[100001];
int b[100001];

void solve() {

	int i, j;
	result[1] = a[1];

	for (int p = 2; p <= N; p++) {

		result[p] = result[p - 1] + a[p];
	}

	for (int q = 0; q < M; q++) {

		scanf("%d %d", &i, &j);
		b[q] = result[j] - result[i - 1];
	}

	for (int r = 0; r < M; r++) {

		printf("%d\n", b[r]);
	}
}

int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		a[i] = t;
	}

	solve();

	return 0;
}