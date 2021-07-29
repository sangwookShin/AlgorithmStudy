#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
int paper[102][102] = { 0, };
int visit[102][102] = { 0, };
vector<int> v;
int cnt = 0;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

void dfs(int x, int y) {

	visit[x][y] = 1;
	cnt++;

	for (int i = 0; i < 4; i++) {

		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (new_x < 0 || new_y < 0 || new_x >= m || new_y >= n) {
			continue;
		}

		if (visit[new_x][new_y] == 0 && paper[new_x][new_y] == 0) {

			dfs(new_x, new_y);
		}
	}


}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {

		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++) {
			for (int p = x1; p < x2; p++) {
				paper[j][p] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (paper[i][j] == 0 && visit[i][j] == 0) {
				cnt = 0;
				dfs(i, j);
				v.push_back(cnt);
			}

		}
	}

	cout << v.size() << endl;

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}