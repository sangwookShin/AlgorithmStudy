#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int m[9][9];
int tmp[9][9];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int result = 0;

void BFS() {

	int afterspread[9][9];
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			afterspread[i][j] = tmp[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (afterspread[i][j] == 2) {
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}

			if (afterspread[nx][ny] == 0) {

				afterspread[nx][ny] = 2;
				q.push({ nx,ny });
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (afterspread[i][j] == 0) {
				cnt++;
			}
		}
	}

	result = max(result, cnt);
}

void solve(int cnt) {

	if (cnt == 3) {
		BFS();
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0) {
				tmp[i][j] = 1;
				solve(cnt + 1);
				tmp[i][j] = 0;
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] == 0) {
				for (int p = 0; p < N; p++) {
					for (int q = 0; q < M; q++) {
						tmp[p][q] = m[p][q];
					}
				}

				tmp[i][j] = 1;
				solve(1);
				tmp[i][j] = 0;
			}
		}
	}

	cout << result;

	return 0;
}