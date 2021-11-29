#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

int N, M;
vector<pair<int, int>> graph[1001];

int dijkstra(int start, int v, int finish) {

    vector<int> distance(v, INF);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (distance[cur] < cost) {
            continue;
        }

        int num = graph[cur].size();
        for (int i = 0; i < num; i++) {
            int neighbor = graph[cur][i].first;
            int distanceToN = cost + graph[cur][i].second;

            if (distance[neighbor] > distanceToN) {
                distance[neighbor] = distanceToN;
                pq.push({ distanceToN, neighbor });
            }
        }
    }

    return distance[finish];
}

int main() {

    int start, finish;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({ to, cost });
    }

    cin >> start >> finish;

    cout << dijkstra(start, N + 1, finish);
    return 0;

}