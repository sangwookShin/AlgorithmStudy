#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int L, W;
int visit[51][51] = { 0, };
char g[51][51];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int BFS(int x, int y) {

	queue<pair<int, int>> q;
	q.push({ x, y });
	visit[x][y] = 1;
	int result = 0;

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			result = max(result, visit[x][y]);

			if (nx < 0 || ny < 0 || nx >= L || ny >= W) {
				continue;
			}
			if (g[nx][ny] == 'L' && visit[nx][ny] == 0) {
				q.push({ nx,ny });
				visit[nx][ny] = visit[x][y] + 1;
			}
		}
	}

	return result - 1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int result = 0;
	cin >> L >> W;

	for (int i = 0; i < L; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < W; j++) {
			g[i][j] = tmp[j];
		}
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < W; j++) {
			if (g[i][j] == 'L') {
				result = max(result, BFS(i, j));
				memset(visit, 0, sizeof(visit));
			}
		}
	}

	cout << result;
	return 0;
}