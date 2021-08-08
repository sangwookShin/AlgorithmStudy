#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int pic[101][101];
int visit[101][101] = { 0, };
int N;
int cnt1 = 0, cnt2 = 0;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

void dfs(int x, int y) {

	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {

		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
			continue;
		}
		if (visit[nx][ny] == 0 && pic[x][y] == pic[nx][ny]) {
			dfs(nx, ny);
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {

		string tmp;
		cin >> tmp;

		for (int j = 0; j < N; j++) {
			pic[i][j] = tmp[j];
		}
	}

	//색약x
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0) {
				dfs(i, j);
				cnt1++;
			}
		}
	}

	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (pic[i][j] == 'R') {
				pic[i][j] = 'G';
			}
		}
	}

	//색약o
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] == 0) {
				dfs(i, j);
				cnt2++;
			}
		}
	}



	cout << cnt1 << " " << cnt2;

	return 0;
}