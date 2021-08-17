#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, K;
int m[101][101];
int visit[101][101] = { 0, };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int cnt;

void DFS(int x, int y) {

	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
			continue;
		}
		if (visit[nx][ny] == 0 && m[nx][ny] == 1) {
			cnt++;
			DFS(nx, ny);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int result = 0;

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		m[r - 1][c - 1] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] == 0 && m[i][j] == 1) {
				cnt = 1;
				DFS(i, j);
				if (cnt > result) {
					result = cnt;
				}
			}
		}
	}

	cout << result;

	return 0;
}