#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int F, S, G, U, D;
int tower[1000001] = { 0, };

int solve() { //BFS

	queue<int> q;
	q.push(S);
	tower[S] = 1;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		if (cur == G) {	//¸ñÇ¥Ãþ µµÂø
			cout << tower[cur] - 1;
			return 0;
		}

		int next[2];
		next[0] = cur + U;
		next[1] = cur - D;

		for (int i = 0; i < 2; i++) {
			if (1 <= next[i] && next[i] <= F && tower[next[i]] == 0) {
				tower[next[i]] = tower[cur] + 1;
				q.push(next[i]);
			}
		}

	}

	cout << "use the stairs";
	return 0;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;

	solve();

	return 0;
}