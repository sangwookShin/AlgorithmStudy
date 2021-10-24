#include<vector>
#include <cstring>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 1;
    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { -1, 1, 0, 0 };
    queue<pair<int, int>> q;

    int n = maps.size();
    int m = maps[0].size();

    int arr[101][101];

    memset(arr, -1, sizeof(arr));

    q.push({ 0,0 });
    arr[0][0] = 1;

    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }

            if (arr[nx][ny] == -1 && maps[nx][ny] == 1) {
                q.push({ nx, ny });
                arr[nx][ny] = arr[x][y] + 1;
            }

        } //for

    } //while

    answer = arr[n - 1][m - 1];

    return answer;
}