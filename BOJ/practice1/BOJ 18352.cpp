#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> g[300001];

int n, m, k, x;
int dis[300001];

void dijkstra(int start) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[start] = 0;
    pq.push({ 0,start });

    while (!pq.empty()) {

        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dis[cur] < cost) {
            continue;
        }

        for (int i = 0; i < g[cur].size(); i++) {
            int next = g[cur][i].second;
            int nextCost = g[cur][i].first;
            if (cost + nextCost < dis[next]) {
                dis[next] = cost + nextCost;
                pq.push({ dis[next], next });
            }
        }
    } //while
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k >> x;

    for (int i = 1; i <= n; i++) {
        dis[i] = 987654321;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back({ 1,b });
    }

    dijkstra(x);

    bool check = true;

    for (int i = 1; i <= n; i++) {
        if (dis[i] == k) {
            cout << i << "\n";
            check = false;
        }
    }

    if (check) {
        cout << -1;
    }

    return 0;
}