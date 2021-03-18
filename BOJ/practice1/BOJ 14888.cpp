//삼성 SW 역량 테스트 기출 문제
#include <iostream>
#include <algorithm>

int N;
int A[12];
int op[4];
int cnt;
int MAX = -1000000001;
int MIN = 1000000001;

using namespace std;

void dfs(int p, int m, int mul, int de, int sum, int cnt) {

	if (cnt == N) {
		MAX = max(MAX, sum);
		MIN = min(MIN, sum);
	}

	if (p > 0) {
		dfs(p - 1, m, mul, de, sum + A[cnt], cnt + 1);
	}
	if (m > 0) {
		dfs(p, m - 1, mul, de, sum - A[cnt], cnt + 1);
	}
	if (mul > 0) {
		dfs(p, m, mul - 1, de, sum * A[cnt], cnt + 1);
	}
	if (de > 0) {
		dfs(p, m, mul, de - 1, sum / A[cnt], cnt + 1);
	}
}
int main() {

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	for (int i = 0; i < 4; i++)
		cin >> op[i];

	dfs(op[0], op[1], op[2], op[3], A[0], 1);

	cout << MAX << endl;
	cout << MIN;

	return 0;
}