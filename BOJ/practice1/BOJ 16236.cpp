#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int N;
int arr[21][21];
int visit[21][21];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int start_x, start_y; //처음 아기상어의 위치 행,열
int babyshark_size = 2; //아기상어의 크기
vector<pair<pair<int, int>, int>> shark; //상어 거리/x좌표/y좌표

void BFS(int bx, int by) {

    int dis = 987654321;
    queue<pair<int, int>> q;
    q.push({ bx, by });

    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) {
                continue;
            }
            if (visit[nx][ny] == 0 && babyshark_size >= arr[nx][ny]) { //자기보다 작거나 같은 상어
                visit[nx][ny] = visit[x][y] + 1;
                if (babyshark_size > arr[nx][ny] && arr[nx][ny] != 0) { //자기보다 작은 상어를 먹는다
                    if (dis >= visit[nx][ny]) {
                        dis = visit[nx][ny];
                        shark.push_back({ {dis, nx},ny });
                    }
                }
                q.push({ nx,ny });
            } //if
        } //for
    } //while
}

void solve() {

    int result = 0;
    int cnt = 0;

    while (1) {

        memset(visit, 0, sizeof(visit));
        shark.clear();
        BFS(start_x, start_y);

        if (shark.empty()) {
            break;
        }
        else {
            sort(shark.begin(), shark.end());
            cnt++; //먹은 수
            result = result + shark.front().first.first; //초 계산
            arr[shark.front().first.second][shark.front().second] = 0; //먹었으니 0으로 만듬

            //먹은곳에서 시작 위치 재설정
            start_x = shark.front().first.second;
            start_y = shark.front().second;

            //아기상어 크기의 수만큼 상어를 먹었을 때 아기상어 크기 증가
            if (babyshark_size == cnt) {
                babyshark_size++;
                cnt = 0;
            }
        }
    } //while

    cout << result;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                arr[i][j] = 0;
                start_x = i;
                start_y = j;
            }
        }
    }

    solve();

    return 0;
}