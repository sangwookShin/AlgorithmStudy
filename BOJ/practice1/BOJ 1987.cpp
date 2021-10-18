#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c;
char arr[21][21];
int visit[26] = { 0, };
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int result = 0;

void DFS(int x, int y, int cnt) {

    result = max(result, cnt);

    for (int i = 0; i < 4; i++) {

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
            continue;
        }
        if (visit[arr[nx][ny] - 'A'] == 0) {
            visit[arr[nx][ny] - 'A'] = 1;
            DFS(nx, ny, cnt + 1);
            visit[arr[nx][ny] - 'A'] = 0;
        }
    }

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

    visit[arr[0][0] - 'A'] = 1;
    DFS(0, 0, 1);

    cout << result;
    return 0;
}