#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, h;
int land[101][101];
int visit[101][101] = { 0, };
int cnt = 1;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int result = 1;

void dfs(int x, int y) {

	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {

		int next_x = dx[i] + x;
		int next_y = dy[i] + y;

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) {
			continue;
		}

		if (visit[next_x][next_y] == 0 && land[next_x][next_y] > h) {

			dfs(next_x, next_y);
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int t;
			cin >> t;
			land[i][j] = t;
		}
	}

	for (h = 1; h <= 100; h++) {

		memset(visit, 0, sizeof(visit));
		cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (visit[i][j] == 0 && land[i][j] > h) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		result = max(result, cnt);
	}

	cout << result;

	return 0;
}