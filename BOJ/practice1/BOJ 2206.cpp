#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int m[1001][1001];
int visit[1001][1001][2] = { 0, }; //x /y / 1(벽부수기가능), 0(벽부수기불가)

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
queue<pair<pair<int, int>, int>> q;

void BFS(int x, int y) {

	q.push({ {0,0}, 1 });
	visit[0][0][1] = 1;

	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;
		int s = q.front().second;

		q.pop();

		if (x == N - 1 && y == M - 1) {
			cout << visit[x][y][s];
			return;
		}

		for (int i = 0; i < 4; i++) {

			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}

			if (m[nx][ny] == 1 && s == 1) {
				q.push({ {nx, ny}, 0 });
				visit[nx][ny][s - 1] = visit[x][y][s] + 1;
			}
			else if (m[nx][ny] == 0 && visit[nx][ny][s] == 0) {
				q.push({ {nx, ny}, s });
				visit[nx][ny][s] = visit[x][y][s] + 1;
			}


		}
	}

	cout << "-1";
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			int t;

			if (tmp[j] == '1') {
				t = 1;
			}
			else {
				t = 0;
			}
			m[i][j] = t;
		}
	}

	BFS(0, 0);

	return 0;
}