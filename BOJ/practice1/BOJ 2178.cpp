#include <iostream>
#include <queue>

using namespace std;

int N, M;
char m[101][101];
int dis[101][101] = { 0, };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;
int visit[101][101] = { 0, };

void bfs(int x, int y) {

	visit[x][y] = 1;
	q.push({ x,y });

	while (!q.empty()) {

		int a = q.front().first;
		int b = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {

			int nx = a + dx[i];
			int ny = b + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
				continue;
			}

			if (visit[nx][ny] == 0 && m[nx][ny] == '1') {
				dis[nx][ny] = dis[a][b] + 1;
				visit[nx][ny] = 1;
				q.push({ nx, ny });
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
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			m[i][j] = tmp[j];
		}
	}

	bfs(0, 0);

	cout << dis[N - 1][M - 1] + 1;

	return 0;
}