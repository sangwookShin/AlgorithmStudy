#include <string>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> v[101];
int arr[101][101];
bool visit[101];

int BFS(int n, vector<vector<int>> wires) {

    int result = 0;
    queue<int> q;
    q.push(n);

    visit[n] = true;

    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        result++;

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            if (visit[next] == false && arr[cur][next] == 1) {
                q.push(next);
                visit[next] = true;
            } //if
        } //for 
    } //while

    return result;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;

    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            arr[i][j] = 0;
        }
    }

    for (int i = 0; i < wires.size(); i++) {
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
        arr[wires[i][0]][wires[i][1]] = 1;
        arr[wires[i][1]][wires[i][0]] = 1;
    }

    for (auto wire : wires) {

        memset(visit, false, sizeof(visit));

        arr[wire[0]][wire[1]] = 0;
        arr[wire[1]][wire[0]] = 0;

        answer = min(answer, abs(BFS(wire[0], wires) - BFS(wire[1], wires)));

        arr[wire[0]][wire[1]] = 1;
        arr[wire[1]][wire[0]] = 1;
    }

    return answer;
}