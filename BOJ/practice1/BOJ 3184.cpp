#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int r, c;
int sheep = 0;
int wolf = 0;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
char arr[250][250];
bool visit[250][250];

void BFS(int a, int b) {

    int sheep_cnt = 0;
    int wolf_cnt = 0;
    queue<pair<int, int>> q;
    q.push({ a,b });
    visit[a][b] = true;

    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (arr[x][y] == 'v') {
            wolf_cnt++;
        }
        if (arr[x][y] == 'o') {
            sheep_cnt++;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
                continue;
            }

            if (!visit[nx][ny] && arr[nx][ny] != '#') {
                visit[nx][ny] = true;
                q.push({ nx,ny });
            }
        }

    } //while

    if (sheep_cnt > wolf_cnt) {
        sheep += sheep_cnt;
    }
    else {
        wolf += wolf_cnt;
    }
}

void solve() {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (visit[i][j] == false) {
                BFS(i, j);
            }
        }
    }

    cout << sheep << " " << wolf;
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
        } //for
    } //for

    solve();

    return 0;

}