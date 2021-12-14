#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool visit[1001][1001][11];
char arr[1001][1001];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int N, M, K;

void solve() {

    queue<pair<pair<int, int>, pair<int, int>>> q; //x,y, cnt, 부순벽
    q.push({ {0,0},{1,0} });
    visit[0][0][0] = true;

    while (!q.empty()) {

        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int br_wall = q.front().second.second;
        q.pop();

        if (x == N - 1 && y == M - 1) {
            cout << cnt << "\n";
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                continue;
            }

            if (visit[nx][ny][br_wall] == false) {
                if (arr[nx][ny] == '0') {
                    visit[nx][ny][br_wall] = true;
                    q.push({ {nx,ny}, {cnt + 1, br_wall} });
                }
                else if (arr[nx][ny] == '1') {
                    if (br_wall < K) { //부실수 있으면
                        visit[nx][ny][br_wall + 1] = true;
                        q.push({ {nx,ny}, {cnt + 1, br_wall + 1} });
                    }
                }

            } //if
        } //for
    }//while

    cout << -1;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            arr[i][j] = tmp[j];
        }
    }

    solve();

    return 0;
}