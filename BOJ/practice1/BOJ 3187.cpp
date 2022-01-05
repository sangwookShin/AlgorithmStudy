#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int r, c;
char arr[250][250];
bool visit[250][250];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int s, w;

void BFS(int a, int b) {

    int s_cnt = 0;
    int w_cnt = 0;
    queue<pair<int, int>> q;
    q.push({ a,b });
    visit[a][b] = true;

    if (arr[a][b] == 'k') {
        s_cnt++;
    }
    if (arr[a][b] == 'v') {
        w_cnt++;
    }

    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
                continue;
            }

            if (!visit[nx][ny]) {

                if (arr[nx][ny] == '.') {
                    visit[nx][ny] = true;
                    q.push({ nx, ny });
                }
                else if (arr[nx][ny] == 'v') {
                    visit[nx][ny] = true;
                    q.push({ nx,ny });
                    w_cnt++;
                }
                else if (arr[nx][ny] == 'k') {
                    visit[nx][ny] = true;
                    q.push({ nx,ny });
                    s_cnt++;
                }
            } //if
        } //for
    } //while

    if (w_cnt >= s_cnt) {
        w = w + w_cnt;
    }
    else {
        s = s + s_cnt;
    }
}

void solve() {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == '#') {
                continue;
            }
            if (!visit[i][j]) {
                BFS(i, j);
            }
        }
    }

    cout << s << " " << w;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < c; j++) {
            arr[i][j] = tmp[j];
        }
    }

    solve();

    return 0;
}