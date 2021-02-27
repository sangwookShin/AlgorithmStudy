//삼성 SW 역량테스트 기출 문제
#include <iostream>

using namespace std;

int N, L, R;
int A[50][50];
int visited[50][50];
int cnt;

int find(int r, int c, int value) {

	if (r<0 || r>N - 1 || c<0 || c>N - 1) {
		return 0;
	}

	if (visited[r][c]) return 0;

	if (value != -1) {
		int diff = abs(value - A[r][c]);
		if (diff < L || diff > R) { return 0; }
	}

	visited[r][c] = 1;
	cnt++;

	int sum = A[r][c];
	sum += find(r - 1, c, A[r][c]);
	sum += find(r + 1, c, A[r][c]);
	sum += find(r, c - 1, A[r][c]);
	sum += find(r, c + 1, A[r][c]);

	return sum;
}
void move(int r, int c, int value) {

	if (r<0 || r>N - 1 || c<0 || c>N - 1) {
		return;
	}

	if (visited[r][c] != 1) {
		return;
	}

	visited[r][c] = 2;

	A[r][c] = value;
	move(r - 1, c, value);
	move(r + 1, c, value);
	move(r, c - 1, value);
	move(r, c + 1, value);

}
int solve() {

	int movecount = 0;
	bool isMoved;

	do {
		isMoved = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == 0) {
					cnt = 0;
					int sum = find(i, j, -1);
					if (cnt > 1) {
						isMoved = true;
						move(i, j, sum / cnt);
					}
					else {
						visited[i][j] = 2;
					}
				}
			}
		}

		if (isMoved) movecount++;
	} while (isMoved);

	return movecount;
}

int main() {

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	cout << solve();

	return 0;
}