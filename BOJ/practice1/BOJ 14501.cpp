//삼성 SW 역량 테스트 기출 문제
#include <iostream>

using namespace std;

int N;
int T[100];
int P[100];

int solve() {

	int sum[100] = { 0, };
	int result = 0;

	for (int i = N; i > 0; i--) {
		int day = i + T[i];
		if (day > N + 1) {
			sum[i] = sum[i + 1];
		}
		else {
			sum[i] = max(sum[i + 1], sum[day] + P[i]);
		}


	}

	return sum[1];
}
int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	cout << solve();

	return 0;
}