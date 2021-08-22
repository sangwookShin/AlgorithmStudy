#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f

int v, e;
vector<pair<int, int>> g[20001];

vector<int> dijkstra(int start, int vertex) {

	vector<int> dis(vertex, INF); //start ~ 각 vertex 까지의 거리 저장, 초기값 INF
	dis[start] = 0; // start ~ start = 0

	//최소 힙 생성
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {

		int cost = pq.top().first;
		int currentVertex = pq.top().second;
		pq.pop();

		if (dis[currentVertex] < cost) {
			continue;
		}

		for (int i = 0; i < g[currentVertex].size(); i++) {
			int neighbor = g[currentVertex][i].first; //to
			int distanceToN = cost + g[currentVertex][i].second; //cost

			if (dis[neighbor] > distanceToN) {
				dis[neighbor] = distanceToN;
				pq.push({ distanceToN, neighbor });
			}
		}
	}

	return dis;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int s;
	int from, to, cost;
	cin >> v >> e >> s;

	for (int i = 0; i < e; i++) {
		cin >> from >> to >> cost;
		g[from].push_back({ to, cost });
	}

	vector<int> result = dijkstra(s, v + 1);

	for (int i = 1; i < v + 1; i++) {
		if (result[i] == INF) {
			cout << "INF" << "\n";
		}
		else {
			cout << result[i] << "\n";
		}
	}

	return 0;
}