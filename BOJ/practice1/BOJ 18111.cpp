#include <iostream>
#include <algorithm>

using namespace std;

int land[500][500];
int N, M, B;
int mintime = 987654321;

void solve() {

	int resulth;

	for (int h = 0; h < 257; h++) {

		int curtime = 0;
		int save = B;
		int build = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				if (land[i][j] > h) { //지우기
					B = B + land[i][j] - h;
					curtime = curtime + (land[i][j] - h) * 2;
				}

				if (land[i][j] < h) { //쌓기
					build = build + h - land[i][j];
				}

			}
		}

		if (build > B) { //불가능
			B = save;
			continue;
		}
		else {
			curtime = curtime + build;
			if (mintime >= curtime) {
				resulth = h;
			}
			mintime = min(mintime, curtime);
			B = save;
		}

	}

	cout << mintime << " " << resulth;
}

int main() {

	cin >> N >> M >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int t;
			cin >> t;
			land[i][j] = t;
		}
	}

	solve();

	return 0;
}