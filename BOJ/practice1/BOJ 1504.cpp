#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> g[801];
int dis[801];
int N, E, v1, v2;

void dijkstra(int start) {

    dis[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {

        int cost = pq.top().first;
        int cur_vertex = pq.top().second;
        pq.pop();

        if (dis[cur_vertex] < cost) {
            continue;
        }

        for (int i = 0; i < g[cur_vertex].size(); i++) {
            int next = g[cur_vertex][i].first;
            int dis_to_next = cost + g[cur_vertex][i].second;

            if (dis[next] > dis_to_next) {
                dis[next] = dis_to_next;
                pq.push({ dis_to_next, next });
            } //if
        } //for
    } //while
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({ b,c });
        g[b].push_back({ a,c });
    }

    cin >> v1 >> v2;

    for (int i = 0; i <= N; i++) {
        dis[i] = 987654321;
    }
    dijkstra(1);

    int result;
    int r1 = dis[v1];
    int r2 = dis[v2];
    bool check_v1 = true;
    bool check_v2 = true;
    if (r1 == 987654321) {
        check_v1 = false;
    }
    if (r2 == 987654321) {
        check_v2 = false;
    }

    for (int i = 1; i <= N; i++) {
        dis[i] = 987654321;
    }
    dijkstra(v1);
    if (check_v1 == true) {
        r1 = r1 + dis[v2];
    }
    if (check_v2 == true) {
        r2 = r2 + dis[v2];
    }

    for (int i = 1; i <= N; i++) {
        dis[i] = 987654321;
    }
    dijkstra(v2);
    if (check_v1 == true) {
        r1 = r1 + dis[N];
    }

    for (int i = 1; i <= N; i++) {
        dis[i] = 987654321;
    }
    dijkstra(v1);
    if (check_v2 == true) {
        r2 = r2 + dis[N];
    }

    if (check_v1 == false && check_v2 == false) {
        result = -1;
    }
    else {
        result = min(r1, r2);
    }

    if (result == 987654321) {
        result = -1;
    }

    cout << result;

    return 0;
}