//삼성 SW 역량 테스트 기출 문제
#include <iostream>

using namespace std;

int N, K;
int A[201];
int robot[201];
int stage = 1;

int check_naegudo_cnt() { //내구도가 0인 개수

	int cnt = 0;

	for (int i = 1; i <= 2 * N; i++) {
		if (A[i] == 0)
			cnt++;
	}

	return cnt;
}
void rotation() { //회전

	//벨트 회전
	int tmp = A[2 * N];
	for (int i = 2 * N; i > 1; i--) {
		A[i] = A[i - 1];
	}
	A[1] = tmp;

	//로봇 회전
	for (int i = N - 1; i >= 1; i--) {
		if (robot[i] == 1) {
			robot[i + 1] = 1;
			robot[i] = 0;
		}
	}
	robot[N] = 0;
}
void move_robot() { //로봇이동

	for (int i = N - 1; i >= 1; i--) {

		if (robot[i] == 1 && robot[i + 1] == 0 && A[i + 1] >= 1) {
			robot[i + 1] = 1;
			robot[i] = 0;
			A[i + 1]--;
		}

	}
	robot[N] = 0;
}
int solve() {

	while (1) {

		//1
		rotation();

		//2
		move_robot();

		//3
		if (robot[1] == 0 && A[1] > 0) {
			robot[1] = 1;
			A[1]--;
		}
		//4
		if (check_naegudo_cnt() >= K) {
			break;
		}
		stage++;
	}

	return stage;
}
int main() {

	cin >> N >> K;

	for (int i = 1; i <= 2 * N; i++) {
		cin >> A[i];
	}

	cout << solve();

	return 0;
}