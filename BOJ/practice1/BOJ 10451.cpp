#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T, N;
int visit[1001] = { 0, };
int graph[1001];
int cnt = 0;

void dfs(int x) {

	visit[x] = 1;

	if (visit[graph[x]] == 0) {
		dfs(graph[x]);
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {

		cin >> N;

		//√ ±‚»≠
		cnt = 0;
		memset(visit, 0, sizeof(visit));

		for (int i = 1; i <= N; i++) {
			int t;
			cin >> t;
			graph[i] = t;
		}

		for (int i = 1; i <= N; i++) {

			if (visit[i] == 0) {
				dfs(i);
				cnt++;
			}
		}

		cout << cnt << endl;

	}


	return 0;
}