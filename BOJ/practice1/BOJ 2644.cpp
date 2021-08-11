#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> family[101];
int visit[101] = { 0, };
int a, b;
queue<int> q;

void BFS() {

	q.push(a);

	while (!q.empty()) {

		int x = q.front();
		q.pop();

		if (x == b) {
			cout << visit[b];
			return;
		}

		for (int i = 0; i < family[x].size(); i++) {

			if (visit[family[x][i]] == 0) {
				q.push(family[x][i]);
				visit[family[x][i]] = visit[x] + 1;
			}
		}
	}

	cout << "-1";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> a >> b >> m;

	for (int i = 0; i < m; i++) {
		int p, q;
		cin >> p >> q;
		family[p].push_back(q);
		family[q].push_back(p);
	}

	BFS();
	return 0;
}