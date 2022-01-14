#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[250][250];
bool visit[250][250];
int n, m;

int dx[] = { 0,0,-1,1,-1,-1,1,1 };
int dy[] = { -1,1,0,0,-1,1,-1,1 };

void BFS(int a, int b) {

    queue<pair<int, int>> q;
    q.push({ a,b });
    visit[a][b] = true;

    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }
            if (arr[nx][ny] == 1 && !visit[nx][ny]) {
                q.push({ nx,ny });
                visit[nx][ny] = true;
            }
        }
    }
}
void solve() {

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1 && !visit[i][j]) {
                BFS(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    solve();

    return 0;
}