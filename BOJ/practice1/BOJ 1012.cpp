#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int T, K, N, M;
int a[52][52];
int visit[52][52] = { 0, };
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int result;

void bfs() {

	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (a[i][j] == 1 && visit[i][j] == 0) {
				result++;
				visit[i][j] = 1;
				q.push({ i,j });

				while (!q.empty()) {

					pair<int, int> x = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						int nx = x.first + dx[i];
						int ny = x.second + dy[i];

						if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
							continue;
						}
						if (a[nx][ny] == 0 || visit[nx][ny] == 1) {
							continue;
						}
						visit[nx][ny] = 1;
						q.push({ nx,ny });

					}
				}
			}
		}
	}

	cout << result << endl;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;


	for (int i = 0; i < T; i++) {
		cin >> N >> M >> K;
		result = 0;
		for (int j = 0; j < K; j++) {
			int s, e;
			cin >> s >> e;
			a[s][e] = 1;
		}

		bfs();

		for (int i = 0; i < 52; i++) {
			for (int j = 0; j < 52; j++) {
				visit[i][j] = 0;
				a[i][j] = 0;
			}
		}
	}

	return 0;
}