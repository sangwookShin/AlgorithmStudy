#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int I;
int dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int s1, s2, e1, e2;
int visit[301][301] = { 0, };

void BFS(int x, int y) {

	queue<pair<pair<int, int>, int>> q;
	visit[x][y] = 1;
	q.push({ {x, y}, 0 });

	while (!q.empty()) {

		int a = q.front().first.first;
		int b = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (a == e1 && b == e2) {
			cout << cnt << endl;
			return;
		}

		for (int i = 0; i < 8; i++) {

			int na = a + dx[i];
			int nb = b + dy[i];

			if (na < 0 || nb < 0 || na >= I || nb >= I) {
				continue;
			}

			if (visit[na][nb] == 0) {
				visit[na][nb] = 1;
				q.push({ {na, nb}, cnt + 1 });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> I >> s1 >> s2 >> e1 >> e2;
		BFS(s1, s2);
		memset(visit, 0, sizeof(visit));
	}

	return 0;
}