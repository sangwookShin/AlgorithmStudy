#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;

char arr[100][100];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int w_cnt = 0;
int b_cnt = 0;

bool visit[100][100];

int BFS(int a, int b) {

    queue<pair<int, int>> q;
    q.push({ a,b });
    visit[a][b] = true;
    char c = arr[a][b];
    int cnt = 1;

    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
                continue;
            }

            if (!visit[nx][ny] && c == arr[nx][ny]) {
                cnt++;
                visit[nx][ny] = true;
                q.push({ nx,ny });
            }
        }
    } //while

    return cnt * cnt;
}

void solve() {

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j]) {
                if (arr[i][j] == 'W') {
                    w_cnt += BFS(i, j);
                }
                else {
                    b_cnt += BFS(i, j);
                }
            }
        }
    }

    cout << w_cnt << " " << b_cnt;

    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < N; j++) {
            arr[i][j] = tmp[j];
        }
    }

    solve();

    return 0;
}