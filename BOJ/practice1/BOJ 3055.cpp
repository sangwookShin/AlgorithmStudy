#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int R, C;
char arr[51][51];
bool visit[51][51];
int D_x, D_y;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

queue<pair<int, int>> water;
queue<pair<int, int>> start;

void solve() {

    int result = 0;

    while (!start.empty()) {

        result++;
        int water_size = water.size();

        while (water_size--) {

            int x = water.front().first;
            int y = water.front().second;
            water.pop();

            for (int j = 0; j < 4; j++) {

                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
                    continue;
                }

                if (arr[nx][ny] == 'X' || arr[nx][ny] == 'D' || arr[nx][ny] == '*') {
                    continue;
                }

                water.push({ nx, ny });
                arr[nx][ny] = '*';
            } //for


        } //while

        int start_size = start.size();
        while (start_size--) {

            int x = start.front().first;
            int y = start.front().second;
            visit[x][y] = true;
            start.pop();

            if (x == D_x && y == D_y) {
                cout << result - 1;
                return;
            } //if

            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
                    continue;
                }
                if (arr[nx][ny] == 'X' || arr[nx][ny] == '*' || visit[nx][ny] == true) {
                    continue;
                }

                start.push({ nx,ny });
                visit[nx][ny] = true;
            }
        } //while
    } //while

    cout << "KAKTUS";
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < C; j++) {
            arr[i][j] = tmp[j];
            if (arr[i][j] == 'S') {
                start.push({ i,j });
            }
            else if (arr[i][j] == 'D') {
                D_x = i;
                D_y = j;
            }
            else if (arr[i][j] == '*') {
                water.push({ i,j });
            }
        }
    } //for

    solve();

    return 0;
}