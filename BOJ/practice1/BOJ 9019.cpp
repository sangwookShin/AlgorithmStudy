#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int T, a, b;
int visit[100001] = { 0, };

void BFS() {

	queue<pair<int, string>> q;
	q.push({ a, "" });
	visit[a] = 1;

	while (!q.empty()) {

		int cur_num = q.front().first;
		string cur_str = q.front().second;
		q.pop();

		if (cur_num == b) {
			cout << cur_str << "\n";
			return;
		}

		//D
		int next_num = (cur_num * 2) % 10000;
		if (visit[next_num] == 0) {
			visit[next_num] = 1;
			q.push({ next_num , cur_str + "D" });
		}

		//S
		next_num = cur_num - 1;
		if (next_num < 0) {
			next_num = 9999;
		}
		if (visit[next_num] == 0) {
			visit[next_num] = 1;
			q.push({ next_num , cur_str + "S" });
		}

		//L
		next_num = (cur_num % 1000) * 10 + (cur_num / 1000);
		if (visit[next_num] == 0) {
			visit[next_num] = 1;
			q.push({ next_num , cur_str + "L" });
		}

		//R
		next_num = (cur_num % 10) * 1000 + (cur_num / 10);
		if (visit[next_num] == 0) {
			visit[next_num] = 1;
			q.push({ next_num , cur_str + "R" });
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		memset(visit, 0, sizeof(visit));
		BFS();
	}

	return 0;
}