//삼성 SW 역량 테스트 기출 문제
#include <iostream>
#include <vector>

using namespace std;

int N;
int S[20][20];
int result = 987654321;
bool check[20];

void dfs(int start, int cnt) {

	if (cnt == N / 2) {

		vector<int> team_S;
		vector<int> team_L;

		for (int i = 0; i < N; i++) {
			if (check[i] == true)
				team_S.push_back(i);
			else
				team_L.push_back(i);
		}

		int sum_S = 0;
		int sum_L = 0;

		for (int i = 0; i < N / 2; i++) {
			for (int j = i + 1; j < N / 2; j++) {
				sum_S = sum_S + S[team_S[i]][team_S[j]] + S[team_S[j]][team_S[i]];
				sum_L = sum_L + S[team_L[i]][team_L[j]] + S[team_L[j]][team_L[i]];
			}
		}

		result = min(result, abs(sum_S - sum_L));

		return;
	}

	for (int i = start + 1; i < N; i++) {
		if (check[i] == false) {
			check[i] = true;
			dfs(i, cnt + 1);
			check[i] = false;
		}
	}

}
int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}

	dfs(0, 0);

	cout << result;

	return 0;
}