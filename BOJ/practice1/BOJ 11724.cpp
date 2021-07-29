#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

vector<int> v[1001];
int num = 0;
int visit[1001] = { 0, };

void dfs(int x) {

	if (visit[x] == 1) {
		return;
	}

	visit[x] = 1;

	for (int i = 0; i < v[x].size(); i++) {
		int a = v[x][i];
		dfs(a);
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {

		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0) {
			num++;
			dfs(i);
		}
	}

	cout << num;

	return 0;
}