#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, H;
int tomato[101][101][101];
int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
queue<pair<pair<int, int>, int>> q;

bool checkTomato() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < H; k++) {
				if (tomato[i][j][k] == 0) {
					return false;
				}
			}
		}
	}
	return true;
}

void BFS() {

	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) {
				continue;
			}
			if (tomato[nx][ny][nz] == 0) {
				tomato[nx][ny][nz] = tomato[x][y][z] + 1;
				q.push({ {nx, ny},nz });
			}
		}
	} //while
} //BFS

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int day = 0;

	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int t;
				cin >> t;
				tomato[j][k][i] = t;
				if (t == 1) {
					q.push({ {j,k},i });
				}
			}
		}
	}

	if (checkTomato() == true) {
		cout << 0;
		return 0;
	}

	if (q.empty()) {
		cout << -1;
		return 0;
	}

	BFS();

	if (checkTomato() == true) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < H; k++) {
					if (day < tomato[i][j][k]) {
						day = tomato[i][j][k];
					}
				}
			}
		}
		cout << day - 1;
		return 0;
	}
	else if (checkTomato() == false) {
		cout << -1;
		return 0;
	}

	return 0;
}