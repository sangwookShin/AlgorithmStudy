#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int w, h;
int land[51][51];
int visit[51][51] = { 0, };
int dx[] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[] = { 1, 0, -1, 0, -1, 1, -1, 1 };

void dfs(int x, int y) {

	visit[x][y] = 1;

	for (int i = 0; i < 8; i++) {

		int next_x = dx[i] + x;
		int next_y = dy[i] + y;

		if (next_x < 0 || next_y < 0 || next_x >= h || next_y >= w) {
			continue;
		}

		if (land[next_x][next_y] == 1 && visit[next_x][next_y] == 0) {
			dfs(next_x, next_y);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 0;

	while (1) {

		cin >> w >> h;

		if (w == 0 && h == 0) {
			return 0;
		}

		cnt = 0;

		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int t;
				cin >> t;
				land[i][j] = t;
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {

				if (visit[i][j] == 0 && land[i][j] == 1) {
					dfs(i, j);
					cnt++;
				}
			}
		}

		cout << cnt << endl;

	}

	return 0;
}