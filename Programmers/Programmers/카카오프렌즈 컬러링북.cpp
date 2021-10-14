#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dx[4];
int dy[4];
bool visit[101][101];

int BFS(int a, int b, int m, int n, vector<vector<int>> picture) {

    int color = picture[a][b];
    int size = 1;
    queue<pair<int, int>> q;
    q.push({ a,b });
    visit[a][b] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                continue;
            }
            if (picture[nx][ny] == color && visit[nx][ny] == false) {
                visit[nx][ny] = true;
                q.push({ nx,ny });
                size++;
            }
        } //for
    } //while

    return size;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    dx[0] = 0; dx[1] = 0; dx[2] = -1; dx[3] = 1;
    dy[0] = -1; dy[1] = 1; dy[2] = 0; dy[3] = 0;
    memset(visit, false, sizeof(visit));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && visit[i][j] == false) {
                int result = BFS(i, j, m, n, picture);
                if (result > max_size_of_one_area) {
                    max_size_of_one_area = result;
                }
                number_of_area++;
            } //if
        } //for
    } //for

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}