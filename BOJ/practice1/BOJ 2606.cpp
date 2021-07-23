#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> a[101];
int bfsvisit[101] = { 0, };

void bfs(int start) {

	queue<int> q;

	q.push(start);
	bfsvisit[start] = 1;
	int cnt = -1;

	while (!q.empty()) {

		int x = q.front();

		cnt++;
		q.pop();

		for (int i = 0; i < a[x].size(); i++) {

			int y = a[x][i];
			if (bfsvisit[y] == 0) {
				q.push(y);
				bfsvisit[y] = 1;
			}
		}
	}

	cout << cnt;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;

		a[s].push_back(e);
		a[e].push_back(s);
	}

	for (int i = 1; i <= N; i++) {
		sort(a[i].begin(), a[i].end());
	}

	bfs(1);

	return 0;
}