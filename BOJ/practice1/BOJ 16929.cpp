#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
char arr[50][50];
bool visit[50][50] = { false, };

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

bool check = false;

void DFS(int x, int y, int direction, int cnt, int start_x, int start_y) { //DFS탐색위치 x,y / 방향 / 몇번꺾이는지 / 맨처음탐색위치

    if (check == true) {
        return;
    }

    for (int i = 0; i < 4; i++) {

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
            continue;
        }

        if (!visit[nx][ny]) { //방문안한 곳
            if (arr[x][y] == arr[nx][ny]) { //전과 같으면
                visit[nx][ny] = true;
                if (i == direction) { //계속 같은 방향이면
                    DFS(nx, ny, direction, cnt, start_x, start_y);
                }
                else { //꺾일경우
                    DFS(nx, ny, i, cnt + 1, start_x, start_y);
                }
            } //if

        } //if
        else { //방문한 곳
            if (nx == start_x && ny == start_y && cnt >= 4) { //4번꺾여서 사각형이되고, 좌표가 맨처음 위치랑 같으면 Yes
                check = true;
                return;
            }
        }
    } //for

}

void solve() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            memset(visit, false, sizeof(visit));
            int start_x = i;
            int start_y = j;

            for (int k = 0; k < 4; k++) {

                memset(visit, false, sizeof(visit));
                visit[i][j] = true;
                DFS(i, j, k, 1, start_x, start_y);
                if (check == true) {
                    cout << "Yes";
                    return;
                }
            }

        } //for
    } //for

    cout << "No";
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

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