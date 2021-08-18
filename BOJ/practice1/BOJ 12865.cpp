#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int w[104]; //����
int v[104];	//��ġ
int dp[104][100004] = { 0, };

void solve() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= w[i]) { //���� �� �ִ� ���
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else { //���� �� ���� ���
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
	}

	solve();
	return 0;
}