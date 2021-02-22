//삼성 SW 역량 테스트 기출 문제
#include <iostream>

using namespace std;

int N, B, C;
int A[1000001];

long long solve() {

	long long min = N;

	for (int i = 0; i < N; i++) {

		A[i] -= B;

		if (A[i] > 0) {
			min += A[i] / C;
			if (A[i] % C > 0)
				min++;
		}
	}

	return min;
}
int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cin >> B >> C;

	cout << solve();

	return 0;
}