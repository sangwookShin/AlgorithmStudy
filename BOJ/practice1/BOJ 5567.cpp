#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[502];
int visit[502];
int n, m;

void solve() {

	int result = 0;
	queue<int> q;
	q.push(1);
	visit[1] = 1;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visit[next] > visit[cur] + 1) {
				visit[next] = visit[cur] + 1;
				q.push(next);
			}
		}
	}

	for (int i = 2; i <= n; i++) {

		if (visit[i] <= 3) {
			result++;
		}
	}

	cout << result;
	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		visit[i] = 9;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	solve();

	return 0;
}