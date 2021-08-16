#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int K, V, E;
vector<int> g[20001];
int visit[20001] = { 0, };

bool isBGraph() {

	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			int x = g[i][j];
			if (visit[i] == visit[x]) {
				return false;
			}
		}
	}
	return true;
}

void BFS(int x) {

	queue<int> q;
	visit[x] = 1;
	q.push(x);
	int status = 1;

	while (!q.empty()) {

		int t = q.front();
		q.pop();

		if (visit[t] == 1) {
			status = 2;
		}
		else if (visit[t] == 2) {
			status = 1;
		}

		for (int i = 0; i < g[t].size(); i++) {
			int y = g[t][i];
			if (visit[y] == 0) {
				visit[y] = status;
				q.push(y);
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> K;

	for (int i = 0; i < K; i++) {

		cin >> V >> E;

		for (int j = 0; j < E; j++) {
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		for (int p = 0; p < V; p++) {
			if (visit[p] == 0) {
				BFS(p);
			}
		}

		//검사
		if (isBGraph() == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

		//초기화
		for (int z = 0; z <= V; z++) {
			g[z].clear();
		}
		memset(visit, 0, sizeof(visit));
	}

	return 0;
}