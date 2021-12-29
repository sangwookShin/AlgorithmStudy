#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> g[20001];
int visit[20001];

int bfs() {

    memset(visit, -1, sizeof(visit));
    queue<pair<int, int>> q;
    q.push({ 1, 0 });
    visit[1] = 0;
    int m = 0;

    while (!q.empty()) {

        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();

        for (int i = 0; i < g[cur].size(); i++) {

            int next = g[cur][i];
            if (visit[next] == -1) {
                visit[next] = dist + 1;
                q.push({ next, dist + 1 });
                if (m < dist + 1) {
                    m = dist + 1;
                }
            }
        } //for
    } //while

    return m;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    for (int i = 0; i < edge.size(); i++) {
        g[edge[i][0]].push_back(edge[i][1]);
        g[edge[i][1]].push_back(edge[i][0]);
    }

    int dis = bfs();

    for (int i = 2; i <= n; i++) {
        if (visit[i] == dis) {
            answer++;
        }
    }
    return answer;
}