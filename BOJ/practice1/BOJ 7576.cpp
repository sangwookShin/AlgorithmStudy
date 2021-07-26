#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int tomato[1001][1001];
queue<pair<int, int>> q;

void bfs() {

	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };

	while (!q.empty()) {

		int x = q.front().second;
		int y = q.front().first;

		q.pop();

		for (int i = 0; i < 4; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < M && ny < N && tomato[ny][nx] == 0) {

				tomato[ny][nx] = tomato[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int t;
			cin >> t;
			tomato[i][j] = t;
			if (t == 1) {
				q.push({ i,j });
			}
		}
	}

	bfs();

	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 0) {
				cout << "-1";
				return 0;
			}

			if (result < tomato[i][j]) {
				result = tomato[i][j];
			}

		}
	}

	cout << result - 1;

	return 0;
}