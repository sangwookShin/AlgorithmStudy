#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int K, W, H;
int land[201][201];
int visit[201][201][31] = { 0, };
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int hdx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int hdy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

void solve() { //BFS

	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0}, {0,0} });
	visit[0][0][0] = 1;

	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;
		int horse = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (x == H - 1 && y == W - 1) { //목표 지점 도착
			cout << cnt;
			return;
		}

		if (horse < K) {
			for (int i = 0; i < 8; i++) {
				int nx = x + hdx[i];
				int ny = y + hdy[i];

				if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
					continue;
				}
				if (land[nx][ny] == 0 && visit[nx][ny][horse + 1] == 0) {
					visit[nx][ny][horse + 1] = 1;
					q.push({ {nx, ny},{horse + 1, cnt + 1} });
				}
			}

		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= H || ny >= W) {
				continue;
			}
			if (land[nx][ny] == 0 && visit[nx][ny][horse] == 0) {
				visit[nx][ny][horse] = 1;
				q.push({ {nx, ny},{horse, cnt + 1} });
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

	cin >> K >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> land[i][j];
		}
	}

	solve();

	return 0;
}