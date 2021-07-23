#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M, V;
vector<int> a[1001];
int dfsvisit[1001] = { 0, };
int bfsvisit[1001] = { 0, };

void bfs(int start) {

	queue<int> q;

	q.push(start);
	bfsvisit[start] = 1;

	while (!q.empty()) {

		int x = q.front();
		cout << x << " ";
		q.pop();

		for (int i = 0; i < a[x].size(); i++) {

			int y = a[x][i];
			if (bfsvisit[y] == 0) {
				q.push(y);
				bfsvisit[y] = 1;
			}
		}
	}
}

void dfs(int start) {

	if (dfsvisit[start] == 1) {
		return;
	}

	dfsvisit[start] = 1; //¹æ¹®
	cout << start << " ";

	for (int i = 0; i < a[start].size(); i++) {
		int x = a[start][i];
		dfs(x);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;

		a[s].push_back(e);
		a[e].push_back(s);
	}

	for (int i = 1; i <= N; i++) {
		sort(a[i].begin(), a[i].end());
	}

	dfs(V);
	cout << endl;
	bfs(V);

	return 0;
}