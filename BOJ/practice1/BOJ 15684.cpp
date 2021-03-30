//삼성 SW 역량 테스트 기출 문제
#include <iostream>

using namespace std;
int N, M, H;
int m[31][11] = { 0, };
int ans = 4;

bool checkResult() {

	for (int i = 1; i <= N; i++) {
		int k = i;
		for (int j = 1; j <= H; j++) { //오른쪽 이동
			if (m[j][k] == 1) {
				k = k + 1;
			}
			else if (m[j][k - 1] == 1 && k - 1 > 0) { //왼쪽 이동
				k = k - 1;
			}
		}
		if (i != k)
			return false;
	}
	return true;
}

void solve(int cnt, int a, int b) {

	if (cnt >= ans)
		return;

	if (checkResult()) {
		ans = cnt;
		return;
	}
	if (cnt == 3)
		return;

	for (int i = a; i <= H; i++, b = 1) {
		for (int j = b; j < N; j++) {
			if (m[i][j] == 1) { //사다리가 있으면
				j = j + 1;
			}
			else {
				m[i][j] = 1;
				solve(cnt + 1, i, j + 2);
				m[i][j] = 0;
			}
		}
	}
}
int main() {

	cin >> N >> M >> H;

	for (int i = 1; i <= M; i++) { //선이 있으면 1
		int a, b;
		cin >> a >> b;
		m[a][b] = 1;
	}

	solve(0, 1, 1);

	if (ans > 3) {
		cout << "-1";
	}
	else
		cout << ans;


	return 0;
}