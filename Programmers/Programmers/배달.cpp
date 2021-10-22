#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> g[51];
vector<int> dis;

void dijkstra() {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 1, 0 }); //end , cost

    while (!pq.empty()) {

        int cur = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if (dis[cur] < cost) {
            continue;
        }

        for (int i = 0; i < g[cur].size(); i++) {
            int next = g[cur][i].first;
            int next_cost = cost + g[cur][i].second;

            if (dis[next] > next_cost) {
                dis[next] = next_cost;
                pq.push({ next, next_cost });
            }
        }
    }

    return;
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    dis.resize(N + 1, 2e9);

    for (int i = 0; i < road.size(); i++) {
        g[road[i][0]].push_back({ road[i][1], road[i][2] });
        g[road[i][1]].push_back({ road[i][0], road[i][2] });
    }

    dis[1] = 0;
    dijkstra();

    for (int i = 1; i < dis.size(); i++) {
        if (dis[i] <= K) {
            answer++;
        }
    }

    return answer;
}