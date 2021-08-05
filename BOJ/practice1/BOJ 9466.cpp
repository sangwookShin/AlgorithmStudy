#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, T;
int graph[100001] = { 0, };
int visit[100001] = { 0, };
int done[100001] = { 0, };
int cnt = 0;

void dfs(int x) {

	visit[x] = 1;

	int next = graph[x];

	if (visit[next] == 0) {
		dfs(next);
	}
	else if (done[next] == 0) {

		for (int i = next; i != x; i = graph[i]) {
			cnt++;
		}
		cnt++;
	}

	done[x] = 1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {

		cin >> n;

		for (int j = 1; j <= n; j++) {

			int t;
			cin >> t;
			graph[j] = t;

		}

		for (int k = 1; k <= n; k++) {
			if (visit[k] == 0) {
				dfs(k);
			}
		}

		cout << n - cnt << endl;

		cnt = 0;
		memset(visit, 0, sizeof(visit));
		memset(done, 0, sizeof(done));
	}

	return 0;
}