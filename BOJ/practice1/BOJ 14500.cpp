#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int arr[501][501];
bool visit[501][501];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int result;

void DFS(int x, int y, int sum, int cnt) {

    visit[x][y] = true;

    if (cnt == 3) {
        result = max(result, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny] == true) {
            continue;
        }

        DFS(nx, ny, sum + arr[nx][ny], cnt + 1);
        visit[nx][ny] = false;
    }

}

void oh1(int x, int y) { //で
    int sum = 0;
    sum = arr[x - 1][y] + arr[x][y - 1] + arr[x][y] + arr[x][y + 1];
    if (sum > result) {
        result = sum;
    }
}

void oh2(int x, int y) { //ぬ
    int sum = 0;
    sum = arr[x][y - 1] + arr[x][y] + arr[x][y + 1] + arr[x + 1][y];
    if (sum > result) {
        result = sum;
    }
}

void oh3(int x, int y) { //た
    int sum = 0;
    sum = arr[x - 1][y] + arr[x][y] + arr[x][y + 1] + arr[x + 1][y];
    if (sum > result) {
        result = sum;
    }
}

void oh4(int x, int y) { //っ
    int sum = 0;
    sum = arr[x - 1][y] + arr[x][y - 1] + arr[x][y] + arr[x + 1][y];
    if (sum > result) {
        result = sum;
    }
}

void solve() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            memset(visit, false, sizeof(visit));
            DFS(i, j, arr[i][j], 0);
            if (i - 1 >= 0 && j - 1 >= 0 && j + 1 < M) { //で
                oh1(i, j);
            }
            if (i + 1 < N && j - 1 >= 0 && j + 1 < M) { //ぬ
                oh2(i, j);
            }
            if (i - 1 >= 0 && i + 1 < N && j + 1 < M) { //た
                oh3(i, j);
            }
            if (i - 1 >= 0 && i + 1 < N && j - 1 >= 0) { //っ
                oh4(i, j);
            }
        }
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

    cout << result;
    return 0;
}