#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int INF = 987654321;

int n, m;
int D[101][101];

void floydWarshall() {

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s, e, w;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				D[i][j] = 0;
			}
			else {
				D[i][j] = INF;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> s >> e >> w;
		D[s][e] = min(D[s][e], w);
	}

	floydWarshall();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || D[i][j] == INF) {
				cout << 0 << " ";
			}
			else {
				cout << D[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}