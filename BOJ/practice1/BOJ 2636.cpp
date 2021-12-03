#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int arr[100][100];
bool visit[100][100];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int result;
int t = 0;

bool BFS() {

    int cnt = 0;
    visit[0][0] = false;
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    t++;

    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny]) {
                continue;
            }

            if (arr[nx][ny] == 0) {
                q.push({ nx, ny });
            }
            else {
                arr[nx][ny] = 0;
                cnt++;
            }
            visit[nx][ny] = true;
        }

    } //while

    if (cnt == 0) { //치즈가 없을 경우
        cout << t - 1 << "\n" << result;
        return true;
    }
    else {
        result = cnt;
        return false;
    }

}

void solve() {

    while (1) {
        if (BFS()) {
            break;
        }
        memset(visit, false, sizeof(visit));
    }

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    solve();

    return 0;
}