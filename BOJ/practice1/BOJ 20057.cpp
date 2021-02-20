//삼성 SW 역량 테스트 기출 문제
#include <iostream>

using namespace std;

int N;
int A[503][503];
int dir;
int r, c;
int cnt = 1;

void solve() {

	if (dir == 0 && c>2) { //좌
		for (int i = 0; i < cnt; i++) {
			if (r == 2 && c == 2) return; //마지막

			int y = A[r][c - 1];
			double d = y / 100.0;
			int a = y - (int)(d * 7) - (int)(d * 7) - (int)(d * 1) - (int)(d * 1)
				- (int)(d * 10) - (int)(d * 10) - (int)(d * 2) - (int)(d * 2)
				- (int)(d * 5);

			A[r][c - 2] += a;
			A[r][c - 1] = 0;

			A[r][c - 3] += (int)(d * 5);
			A[r - 1][c] += (int)(d);
			A[r + 1][c] += (int)(d);
			A[r - 1][c - 1] += (int)(d * 7);
			A[r + 1][c - 1] += (int)(d * 7);
			A[r - 1][c - 2] += (int)(d * 10);
			A[r + 1][c - 2] += (int)(d * 10);
			A[r - 2][c - 1] += (int)(d * 2);
			A[r + 2][c - 1] += (int)(d * 2);
			c--;
		}
		dir = 1;
		solve();
	}
	else if (dir == 1 && r<N+2) { //하
		for (int i = 0; i < cnt; i++) {
			int y = A[r - 1][c];
			double d = y / 100.0;
			int a = y - (int)(d * 7) - (int)(d * 7) - (int)(d * 1) - (int)(d * 1)
				- (int)(d * 10) - (int)(d * 10) - (int)(d * 2) - (int)(d * 2)
				- (int)(d * 5);

			A[r - 2][c] += a;
			A[r - 1][c] = 0;

			A[r - 3][c] += (int)(d * 5);
			A[r][c - 1] += (int)(d);
			A[r][c + 1] += (int)(d);
			A[r + 1][c - 1] += (int)(d * 7);
			A[r + 1][c + 1] += (int)(d * 7);
			A[r + 2][c - 1] += (int)(d * 10);
			A[r + 2][c + 1] += (int)(d * 10);
			A[r + 1][c - 2] += (int)(d * 2);
			A[r + 1][c + 2] += (int)(d * 2);
			r++;
		}
		dir = 2;
		cnt++;
		solve();
	}
	else if (dir == 2 && c<N+2) { //우
		for (int i = 0; i < cnt; i++) {
			int y = A[r][c + 1];
			double d = y / 100.0;
			int a = y - (int)(d * 7) - (int)(d * 7) - (int)(d * 1) - (int)(d * 1)
				- (int)(d * 10) - (int)(d * 10) - (int)(d * 2) - (int)(d * 2)
				- (int)(d * 5);

			A[r][c + 2] += a;
			A[r][c + 1] = 0;

			A[r][c + 3] += (int)(d * 5);
			A[r - 1][c] += (int)(d);
			A[r + 1][c] += (int)(d);
			A[r - 1][c + 1] += (int)(d * 7);
			A[r + 1][c + 1] += (int)(d * 7);
			A[r - 1][c + 2] += (int)(d * 10);
			A[r + 1][c + 2] += (int)(d * 10);
			A[r - 2][c + 1] += (int)(d * 2);
			A[r + 2][c + 1] += (int)(d * 2);
			c++;
		}
		dir = 3;
		solve();
	}
	else if (dir == 3 && r>2) { //상
		for (int i = 0; i < cnt; i++) {
			int y = A[r - 1][c];
			double d = y / 100.0;
			int a = y - (int)(d * 7) - (int)(d * 7) - (int)(d * 1) - (int)(d * 1)
				- (int)(d * 10) - (int)(d * 10) - (int)(d * 2) - (int)(d * 2)
				- (int)(d * 5);

			A[r - 2][c] += a;
			A[r - 1][c] = 0;

			A[r - 3][c] += (int)(d * 5);
			A[r][c - 1] += (int)(d);
			A[r][c + 1] += (int)(d);
			A[r - 1][c - 1] += (int)(d * 7);
			A[r - 1][c + 1] += (int)(d * 7);
			A[r - 2][c - 1] += (int)(d * 10);
			A[r - 2][c + 1] += (int)(d * 10);
			A[r - 1][c - 2] += (int)(d * 2);
			A[r - 1][c + 2] += (int)(d * 2);
			r--;
		}
		dir = 0;
		cnt++;
		solve();
	}
}
int result() {
	int sum =0;
	int total = 0;

	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < N + 2; j++) {
			total = total + A[i][j];
		}
	}
	
	for (int i = 2; i < N; i++) {
		for (int j = 2; j < N; j++) {
			sum = sum + A[i][j];
		}
	}

	return total - sum;
}
int main() {

	cin >> N;

	for (int i = 2; i < N + 2; i++) {
		for (int j = 2; j < N + 2; j++) {
			cin >> A[i][j];
		}
	}

	dir = 0;
	r = ((N + 2) / 2) + 1;
	c = ((N + 2) / 2) + 1;

	solve();

	cout << result();

	return 0;
}