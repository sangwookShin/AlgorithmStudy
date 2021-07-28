#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int number;
int home[26][26];
int visit[25][25] = { 0, };
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
vector<int> v;

void dfs(int a, int b) {

	visit[a][b] = 1;

	for (int i = 0; i < 4; i++) {

		int x = a + dx[i];
		int y = b + dy[i];

		if (x < 0 || y < 0 || x >= N || y >= N) {
			continue;
		}

		if (home[x][y] == 1 && visit[x][y] == 0) {
			number++;
			dfs(x, y);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string t;
		cin >> t;

		for (int j = 0; j < N; j++) {
			home[i][j] = t[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (home[i][j] == 1 && visit[i][j] == 0) {
				number = 1;
				dfs(i, j);
				v.push_back(number);
			}
		}
	}

	cout << v.size() << endl;
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	return 0;
}