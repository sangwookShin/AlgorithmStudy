#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int M, N;
int arr[301][301];
int arr2[301][301];
bool visit[301][301];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void BFS(int x, int y) {

    queue<pair<int, int>> q;
    q.push({ x,y });
    visit[x][y] = true;

    while (!q.empty()) {

        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                continue;
            }
            if (visit[nx][ny] == false && arr[nx][ny] != 0) {
                visit[nx][ny] = true;
                q.push({ nx,ny });
            }
        }
    } //while
}

int melt(int x, int y) {

    int result = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (arr[nx][ny] == 0) {
            result++;
        }
    }

    return result;
}

void solve() {

    int result = 0;

    while (1) {

        int cnt = 0; //µ¢¾î¸® °³¼ö
        memset(visit, false, sizeof(visit));
        memset(arr2, 0, sizeof(arr2));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] != 0 && visit[i][j] == false) {
                    BFS(i, j);
                    cnt++;
                }
            }
        } //for

        if (cnt >= 2) {
            cout << result;
            return;
        }
        if (cnt == 0) {
            cout << 0;
            return;
        } //if

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] != 0) {
                    arr2[i][j] = arr[i][j] - melt(i, j);
                    if (arr2[i][j] <= 0) {
                        arr2[i][j] = 0;
                    }
                }
            }
        } //for

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                arr[i][j] = arr2[i][j];
            }
        }

        result++;
    } //while
}

int main()
{
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