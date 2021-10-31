#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int M, N;
int arr[501][501];
int dp[501][501];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int DFS(int a, int b) {

    if (a == M - 1 && b == N - 1) {
        return 1;
    }
    if (dp[a][b] != -1) {
        return dp[a][b];
    }
    dp[a][b] = 0;

    for (int i = 0; i < 4; i++) {
        int nx = a + dx[i];
        int ny = b + dy[i];

        if (nx < 0 || ny < 0 || nx >= M || ny >= N) {
            continue;
        }

        if (arr[nx][ny] < arr[a][b]) {
            dp[a][b] = dp[a][b] + DFS(nx, ny);
        }
    }

    return dp[a][b];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    cout << DFS(0, 0);

    return 0;
}