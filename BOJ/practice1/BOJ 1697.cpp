#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N, K;
int cnt = 0;
int visit[100001] = { 0, };
queue<pair<int, int>> q;

void bfs(int x) {

	while (!q.empty()) {

		int location = q.front().first;
		int h = q.front().second;
		q.pop();

		if (location == K) {
			cnt = h;
			break;
		}

		if (location - 1 >= 0 && location - 1 <= 100000 && visit[location - 1] == 0) {
			visit[location - 1] = 1;
			q.push({ location - 1, h + 1 });
		}

		if (location + 1 >= 0 && location + 1 <= 100000 && visit[location + 1] == 0) {
			visit[location + 1] = 1;
			q.push({ location + 1, h + 1 });
		}

		if (location * 2 >= 0 && location * 2 <= 100000 && visit[location * 2] == 0) {
			visit[location * 2] = 1;
			q.push({ location * 2, h + 1 });
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	visit[N] = 1;
	q.push({ N, 0 });
	bfs(N);

	cout << cnt;

	return 0;
}